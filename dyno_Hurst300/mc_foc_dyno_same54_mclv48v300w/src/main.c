/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes


#include "can1_Lib.h" // EL01
//#include "config/default/peripheral/can/plib_can_common.h"
#include "userparams.h"

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

int16_t current_ia, current_ib, pot_value, dc_bus;
uint32_t calibration_sample_count = 0;
uint32_t adc_0_sum = 0;
uint32_t adc_1_sum = 0;
int16_t  adc_0_offset = 0;
int16_t  adc_1_offset = 0;
int16_t  updateCnt = 0;
uint16_t  phaseA_current_raw = 0;
uint16_t  phaseB_current_raw = 0;
uint16_t  dcbus_raw = 0;
uint16_t  pot_raw = 0;
uint16_t slow_loop_count = 0;
uint16_t TimerEncoderFilter = 0;
int16_t CpuLoad;

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************
void ADC0_Tasks()
{
   // TC0_TimerStart();
    LED_01_Set();
    
    phaseA_current_raw = ADC0_ConversionResultGet();
    phaseB_current_raw = ADC1_ConversionResultGet();
       /* Clear all interrupt flags */
       ADC0_REGS->ADC_INTFLAG = ADC_INTFLAG_Msk;

       ADC0_REGS->ADC_INTENCLR = ADC_INTFLAG_RESRDY_Msk;// Disable ADC interrupt
    /* select the next channel */
	/* select the next ADC channel for conversion */
    ADC0_ChannelSelect(ADC_POSINPUT_AIN12,ADC_NEGINPUT_GND); // Potentiometer to ADC0
    ADC1_ChannelSelect(ADC_POSINPUT_AIN2,ADC_NEGINPUT_GND); // DC Bus Voltage to ADC1
    ADC0_REGS->ADC_SWTRIG |= ADC_SWTRIG_START_Msk;
       
    X2C_UpdateModel(); //EL01
    
    while(ADC0_REGS->ADC_INTFLAG != ADC_INTFLAG_RESRDY_Msk);
                       
    /* Read the ADC result value */
    dcbus_raw = ADC1_ConversionResultGet(); // Reads and translates to actual bus voltage
    pot_raw = ADC0_ConversionResultGet();

    
    /* select the next ADC channel for conversion */
    ADC0_ChannelSelect(ADC_POSINPUT_AIN0,ADC_NEGINPUT_GND); // Phase U to ADC0
    ADC1_ChannelSelect(ADC_POSINPUT_AIN0,ADC_NEGINPUT_GND); // Phase V to ADC1
    ADC0_REGS->ADC_INTENSET = ADC_INTFLAG_RESRDY_Msk;// Enable ADC interrupt
    /* Clear all interrupt flags */
    ADC0_REGS->ADC_INTFLAG = ADC_INTFLAG_Msk;
    
    slow_loop_count++;
        
//    TestTimerCan1();                               // called every 50us
    if(TimerEncoderFilter)TimerEncoderFilter--;    // called every 50us
    
    //CpuLoad = TC0_Timer16bitCounterGet() *((uint16)INT16_MAX/PWM_PERIODE);

    LED_01_Clear();
  //  TC0_TimerStop();
}

// *****************************************************************************
// *****************************************************************************
void ADC_Calibration()
{
    calibration_sample_count++;
    if(calibration_sample_count <= 32768)
    {
        adc_0_sum += ADC0_ConversionResultGet();    
        adc_1_sum += ADC1_ConversionResultGet();
    }
    else
    {
        adc_0_offset = adc_0_sum>>15;
        adc_1_offset = adc_1_sum>>15;
        ADC0_CallbackRegister( (ADC_CALLBACK)ADC0_Tasks,(uintptr_t)NULL );
    }
 
}

///* This function is called after period expires */
//void TC0_Callback_InterruptHandler(TC_TIMER_STATUS status, uintptr_t context)
//{
//    // LED2_Toggle();
//}



////////////////////////////////////////////////////////////////////////////////
int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    
   // CAN1Lib_Init(MASTER, &Can1_Param);
    
    ADC0_CallbackRegister( (ADC_CALLBACK)ADC_Calibration,(uintptr_t)NULL );

    TCC0_PWMStart();//EL01 to be added
    ADC0_Enable();
    
    PDEC_QDECStart();
    
    /* Register callback function for TC0 period interrupt */
    //TC0_TimerCallbackRegister(TC0_Callback_InterruptHandler, (uintptr_t)NULL);
    
    /* Start the timer channel 0*/
   // TC0_TimerStart();
    
    while ( true )
    {
        X2C_Communicate();//EL01
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
                
    //    HandleCan1State();
        
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

