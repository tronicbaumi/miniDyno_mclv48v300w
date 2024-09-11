/*******************************************************************************
  Buffering Interface Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_functions.c

  Summary:
    This file contains functions required for this application. 

 
 *******************************************************************************/
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
//* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include "app_config.h"

#if STREAM_FORMAT_IS(APP)
#include "knowledgepack/mplabml/inc/kb.h"
#endif 

extern MCAF_MOTOR_DATA motor;
extern APPLICATION_DATA app;

int16_t rpm=0;


// *****************************************************************************
// Section: Platform specific stub definitions
// *****************************************************************************
// *****************************************************************************


bool USART_Write( void *buffer, const size_t size )
{
    bool writeStatus      = false;
    uint8_t *pu8Data      = (uint8_t*)buffer;
    uint32_t u32Index     = 0U;

    if(buffer != NULL)
    {
        /* Blocks while buffer is being transferred */
        while(u32Index < size)
        {
            /* Check if USART is ready for new data */
            while(U1STAHbits.UTXBF == 1)
             {
        
             }
            /* Write data to USART module */
              U1TXREG = pu8Data[u32Index];;    // Write the data byte to the USART.
            /* Increment index */
            u32Index++;
        }
        writeStatus = true;
    }

    return writeStatus;
}




size_t __attribute__(( unused )) UART_Write(uint8_t *ptr, const size_t nbytes) {
    return USART_Write(ptr, nbytes) ? nbytes : 0;
}

// *****************************************************************************
// *****************************************************************************
// Section: Generic stub definitions
// *****************************************************************************
// *****************************************************************************
void Null_Handler() {
    // Do nothing
}



// RPM measurement 
uint16_t speed_measurement_local(APPLICATION_DATA *appData)
{
    rpm = (float)(motor.apiData.velocityMeasured) / RPM_CONVERSION_FACTOR;      
    return rpm;
}

// For handling the motor IQ and RPM data 
 void handle_iqrpm_value() 
{
 
  ringbuffer_size_t wrcnt;
   
  if (data_sample_buffer_overrun)
     return;
  
    
    sample_data_t *ptr = ringbuffer_get_write_buffer(&data_sample_buffer, &wrcnt);
    
    if (wrcnt == 0)
        data_sample_buffer_overrun = true;
    else 
    {
       iqrpm_read( ptr, &motor, &app );
       ringbuffer_advance_write_index(&data_sample_buffer, 1);
    }
}    

 
 //Reads Motor IQ and RPM value
 
void iqrpm_read( sample_data_t *ptr, MCAF_MOTOR_DATA *pmotor, APPLICATION_DATA *appData)
{
    sample_data_t * l_data_sample_buffer = ptr;
  
  *l_data_sample_buffer++ = (sample_data_t)abs(pmotor->idq.q);
  *l_data_sample_buffer++ = (sample_data_t)abs(speed_measurement_local(&app));
   

}

