                                                                                         /*
© [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/


#include <util.h>
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdint.h>
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include <stdio.h>
#include "ringbuffer.h"
#include <string.h>
#include <hal.h>
#include <libpic30.h>                    // Defines DELAY

#include "app_config.h"


#if STREAM_FORMAT_IS(APP)

#include "knowledgepack/mplabml/inc/kb.h"
#include "knowledgepack/application/sml_recognition_run.h"

#endif 


// *****************************************************************************
// *****************************************************************************
// Section: Global variables
// *****************************************************************************
// *****************************************************************************

static sample_data_t motor_buffer_data[BUF_LEN][NUM_AXES];
volatile ringbuffer_t data_sample_buffer;
volatile bool data_sample_buffer_overrun = false;
volatile int8_t flag_read =0;
volatile int8_t sample_time =0;


extern MCAF_MOTOR_DATA motor;

#define NUM_CLASSES 4u
/*
 By ML model
 
*  "0": "unknown"
 * "1": "normal",
 * "2": "unbalanced load"
 
 By FOC logic
 
 *  "3": "motor is off"
 
 */
static uint8_t class_map[NUM_CLASSES] = {0u};


#if STREAM_FORMAT_IS(APP)
    int class_id = -1;  
    int8_t flag_print=1;
#endif

    
 /*
    Main application
*/ 
        
int main ( void )
{
    int8_t app_failed = 1;

   /* Initialize all modules */
    SYSTEM_Initialize ();
    MCAF_MainInit();
 
    
#if STREAM_FORMAT_IS(APP)        
      
        /* Initialize MPLABML Knowledge Pack */
        
        
        
              
#endif
    
    while (1)
    {
   
        /* Initialize the sensor data buffer */
        if (ringbuffer_init(&data_sample_buffer, motor_buffer_data, sizeof(motor_buffer_data) / sizeof(motor_buffer_data[0]), sizeof(motor_buffer_data[0])))
            break;
    
        //Checks for motor operational faults
         if(motor.state == MCSM_FAULT)
        {
            printf("\r\033[K  ERROR: Got a bad motor status");
            break;
        }
        
        app_failed = 0;
        break;
        
    }
     
    
    while (!app_failed)
    {
        
        MCAF_MainLoop();
              
        handle_iqrpm_value();

        
        if (data_sample_buffer_overrun == true) {
            printf("\n\n\nOverrun!\n\n\n");
            ringbuffer_reset(&data_sample_buffer);
            data_sample_buffer_overrun = false;
     
            continue;
        }
#if STREAM_FORMAT_IS(MDV)
        else if(ringbuffer_get_read_items(&data_sample_buffer) >= SAMPLES_PER_PACKET) 
        {
            ringbuffer_size_t rdcnt;
            sample_dataframe_t const *ptr = ringbuffer_get_read_buffer(&data_sample_buffer, &rdcnt);
            while (rdcnt >= SAMPLES_PER_PACKET) 
            {       
                uint8_t headerbyte = MDV_START_OF_FRAME;
                UART_Write(&headerbyte, 1);
                UART_Write((uint8_t *) ptr, sizeof(sample_datapacket_t));
                headerbyte = ~headerbyte;
                UART_Write(&headerbyte, 1); 
                ptr += SAMPLES_PER_PACKET;
                rdcnt -= SAMPLES_PER_PACKET;
                ringbuffer_advance_read_index(&data_sample_buffer, SAMPLES_PER_PACKET);
            }
        }
#else   
        else {
            
            
                if ((motor.state == MCSM_RUNNING) && (sample_time == 1) )
                {
                ringbuffer_size_t rdcnt;
                sample_time =0;
                sample_dataframe_t const *ptr = ringbuffer_get_read_buffer(&data_sample_buffer, &rdcnt);
                 while (rdcnt--) 
                {
                   int ret = sml_recognition_run((sample_data_t *) ptr++,  NUM_AXES);
                    ringbuffer_advance_read_index(&data_sample_buffer, 1);
               
                        

                    /*Class ID
                      1 - Normal_operation
                      2 - Unbalanced_load
                      0 - unknown*/

                     if (ret >=0 && ret != class_id)
                    {
                        class_id = ret;
                        
                        UART1_Write(0xA5);
                        class_map[0u] = 0u;//unknown//
                        class_map[1u] = 0u;//normal//
                        class_map[2u] = 0u;//unbalance_load//
                        class_map[3u] = 0u;//off
                        switch(ret)
                        {
                            case 0u:
                                class_map[0u]=1u;
                                break;
                            case 1u:
                                class_map[1u]=1u;
                                break;
                            case 2u:
                                class_map[2u]=1u;
                                break;
                        }
                        UART_Write(class_map,4u);
                        UART1_Write(~0xA5);

                     
                    }

                }
                flag_print =1;
            }
        
            else
            {
                if(motor.state == MCSM_STOPPED && flag_print == 1)
                {
                        UART1_Write(0xA5);
                        class_map[0u] = 0u;//unknown//
                        class_map[1u] = 0u;//normal//
                        class_map[2u] = 0u;//unbalance_load//
                        class_map[3u] = 1u;//off
                        UART_Write(class_map,4u);
                        UART1_Write(~0xA5);
                                               
                flag_print=0;
                class_id = -1;
                }
                
                ringbuffer_reset(&data_sample_buffer);
                
            }
        }
#endif //STREAM_FORMAT_IS(MDV)



    
    }

    
    /* Loop forever on error */
    while (1) {};

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/