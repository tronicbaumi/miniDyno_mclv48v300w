/*******************************************************************************
  ADC Configuration Routine source File

  File Name:
    adc.c

  Summary:
    This file includes subroutine for initializing ADC Cores of Controller.

  Description:
    Definitions in the file are for dsPIC33AK128MC106 on Motor Control 
    Development board from Microchip

*******************************************************************************/
/*******************************************************************************
* Copyright (c) 2019 released Microchip Technology Inc.  All rights reserved.
*
* SOFTWARE LICENSE AGREEMENT:
* 
* Microchip Technology Incorporated ("Microchip") retains all ownership and
* intellectual property rights in the code accompanying this message and in all
* derivatives hereto.  You may use this code, and any derivatives created by
* any person or entity by or on your behalf, exclusively with Microchip's
* proprietary products.  Your acceptance and/or use of this code constitutes
* agreement to the terms and conditions of this notice.
*
* CODE ACCOMPANYING THIS MESSAGE IS SUPPLIED BY MICROCHIP "AS IS".  NO
* WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
* TO, IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A
* PARTICULAR PURPOSE APPLY TO THIS CODE, ITS INTERACTION WITH MICROCHIP'S
* PRODUCTS, COMBINATION WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.
*
* YOU ACKNOWLEDGE AND AGREE THAT, IN NO EVENT, SHALL MICROCHIP BE LIABLE,
* WHETHER IN CONTRACT, WARRANTY, TORT (INCLUDING NEGLIGENCE OR BREACH OF
* STATUTORY DUTY),STRICT LIABILITY, INDEMNITY, CONTRIBUTION, OR OTHERWISE,
* FOR ANY INDIRECT, SPECIAL,PUNITIVE, EXEMPLARY, INCIDENTAL OR CONSEQUENTIAL
* LOSS, DAMAGE, FOR COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE CODE,
* HOWSOEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR
* THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT ALLOWABLE BY LAW,
* MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS CODE,
* SHALL NOT EXCEED THE PRICE YOU PAID DIRECTLY TO MICROCHIP SPECIFICALLY TO
* HAVE THIS CODE DEVELOPED.
*
* You agree that you are solely responsible for testing the code and
* determining its suitability.  Microchip has no obligation to modify, test,
* certify, or support the code.
*
*******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <xc.h>
#include <stdint.h>
#include "adc.h"

// *****************************************************************************
// *****************************************************************************
// Section: Functions
// *****************************************************************************
// *****************************************************************************
void Init_ADC(void);
// *****************************************************************************
/* Function:
    void Init_ADC(void)

  Summary:
    Routine to configure ADC Module

  Description:
    Function to configure ADC Cores
  
  Precondition:
    None.

  Parameters:
    None

  Returns:
    None.

  Remarks:
    None.
 */
void Init_ADC(void)
{
    AD1CHCON0bits.PINSEL = 0;       // ADC1 Channel 0 for IA (AD1AN0)
    AD1CHCON0bits.SAMC = 7;         // maximum sampling time (180nS)
    AD1CHCON0bits.TRG1SRC = 4;      // software trigger
    AD1CHCON0bits.LEFT = 0;
    AD1CHCON0bits.DIFF = 0;
    
    AD1CHCON1bits.PINSEL = 10;      // ADC1 Channel 1 for POT (AD1AN10)
    AD1CHCON1bits.SAMC = 7;         // maximum sampling time (180nS)
    AD1CHCON1bits.TRG1SRC = 4;      // software trigger
    AD1CHCON1bits.LEFT = 0;
    AD1CHCON1bits.DIFF = 0;
    
    AD2CHCON0bits.PINSEL = 1;       // ADC2 Channel 0 for IB (AD2AN1)
    AD2CHCON0bits.SAMC = 7;         // maximum sampling time (180nS)
    AD2CHCON0bits.TRG1SRC = 4;      // software trigger
    AD2CHCON0bits.LEFT = 0;
    AD2CHCON0bits.DIFF = 0;

    _AD1CH1IP = 7;
    _AD1CH1IF = 0;
    _AD1CH1IE = 1;
    
    AD1CONbits.ON = 1;              // enable ADC`
    while(AD1CONbits.ADRDY == 0);   // wait when it is ready 
    AD2CONbits.ON = 1;              // enable ADC2
    while(AD2CONbits.ADRDY == 0);   // wait when it is ready   

}
