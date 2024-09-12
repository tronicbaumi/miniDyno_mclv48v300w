/*******************************************************************************
  Clock Configuration Routine source File

  File Name:
    clock.c

  Summary:
    This file includes subroutine for initializing Oscillator and Reference 
    Clock Output

  Description:
    Definitions in the file are for dsPIC33CK256MP508 on Motor Control 
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
#include "clock.h"

// *****************************************************************************
// *****************************************************************************
// Section: Functions
// *****************************************************************************
// *****************************************************************************
void InitClock (void)
{
    /** System Clock Control Register */
    OSCCTRL = 0x0000;
    /* Bit 0 ? FRC_EN 8 MHz FRC Clock Enable bit
     * 1 Enable FRC Oscillator
       0 Disable FRC Oscillator */
    OSCCTRLbits.FRCEN = 1;
    /* Bit 2 ? POSC_EN Primary Crystal Clock Enable bit 
       1 Enable Primary Crystal/Resonator Oscillator
       0 Disable Primary Crystal/Resonator Oscillator  */
    OSCCTRLbits.POSCEN = 0;

    
    /** OSCCFG : Oscillator Configuration Register */
    OSCCFG = 0;
    /** Bit 0 ? POSCMD0 Primary Oscillator Configuration bit(1)
        1 Oscillator mode selected (3.5 MHz-32 MHz)
        0 External clock mode selected */
    OSCCFGbits.POSCMD = 0;
    /** Bit 5 ? POSCIOFNC Primary CLKO Enable Configuration bit
        1 CLKO output signal active on the OSC2 pin; 
        0 CLKO output disabled */
    OSCCFGbits.POSCIOFNC = 0;
       
      /* In this device Internal RC Oscillator is 8MHz
     * Also,In all Motor Control Development boards primary oscillator or 
     * Crystal oscillator output frequency is  8MHz
     * Hence, FPLLI (PLL Input frequency)is 8MHz in the application
     * 
     * FOSC (Oscillator output frequency),FCY (Device Operating Frequency),
     * FVCO (VCO Output Frequency )is:
     *         ( FPLLI * M)     (8 * 75)           
     * FVCO = -------------- = -----------  = 600 MHz
     *               N1             1    
     *
     *         (FPLLI * M)         (8 * 75)          
     * FPLL = --------------  = -----------    = 200 MHz
     *        (N1 * N2 * N3)     (1 * 3 * 1)     
     *
     * Fsys  = 200 MHz 
     *
     * where,
     * N1 = PLL1DIVbits.REFDIV = 1 
     * N2 = PLL1DIVbits.POSTDIV1 = 3
     * N3 = PLL1DIVbits.POSTDIV2 = 1 
     * M = PLL1DIVbits.FBDIV = 75
     */
    
    /* PLL Feedback Divider bits (also denoted as ?M?, PLL multiplier)
     * M = (PLLFBDbits.PLLFBDIV)= 150                                         */
    PLL1DIVbits.FBDIV = 75;

    /* PLL Phase Detector I/P Divider Select bits(denoted as ?N1?,PLL pre-scaler)
     * N1 = PLL1DIVbits.REFDIV = 1                                             */
    PLL1DIVbits.REFDIV = 1;

    /* PLL Output Divider #1 Ratio bits((denoted as 'N2' or POSTDIV#1)
     * N2 = PLL1DIVbits.POSTDIV1 = 3                                           */
    PLL1DIVbits.POSTDIV1 = 3;
    
    /* PLL Output Divider #2 Ratio bits((denoted as 'N3' or POSTDIV#2)
     * N3 = PLL1DIVbits.POSTDIV2 = 1                                           */
    PLL1DIVbits.POSTDIV2 = 1;
        /* Bit 6 ? PLL1_EN PLL1 Enable bit
        1 Enable PLL1
        0 Disable PLL1 */
    OSCCTRLbits.PLL1EN = 1;
    PLL1CONbits.NOSC = 1;
    PLL1CONbits.ON = 1;
    PLL1CONbits.OE = 0;
    PLL1CONbits.OSWEN = 1;
    VCO1DIV = 1;
    while (PLL1CONbits.OSWEN);
    
    PLL1CONbits.PLLSWEN = 1;
    while (PLL1CONbits.PLLSWEN == 1);
    PLL1CONbits.FOUTSWEN = 1;
    while (PLL1CONbits.PLLSWEN == 1);
    while(PLL1CONbits.CLKRDY == 0);
    
    /** Reference Clock Generator REFO1 output through PPS (PPS to be 22)*/
    CLK12DIVbits.INTDIV = 4000;
    CLK12CONbits.OE = 1;
    CLK12CONbits.ON = 1;
    CLK12CONbits.NOSC = 5; //new PLL input oscillator Fin
    CLK12CONbits.OSWEN = 1; // enable PLL switch
    while (CLK12CONbits.OSWEN);
    CLK12CONbits.DIVSWEN =1;
    while (CLK12CONbits.DIVSWEN);
    
    CLK1CONbits.OE = 1;
    CLK1CONbits.ON = 1;
    CLK1CONbits.NOSC = 5; //new PLL input oscillator Fin
    CLK1CONbits.OSWEN = 1; // enable PLL switch
    while (CLK1CONbits.OSWEN);
    CLK1CONbits.DIVSWEN =1;
    while (CLK1CONbits.DIVSWEN);
    
    /** Clock used for UART - 100 MHz*/
    CLK8DIVbits.INTDIV = 1;
    CLK8CONbits.OE = 1;
    CLK8CONbits.ON = 1;
    CLK8CONbits.NOSC = 5; //new PLL input oscillator Fin
    CLK8CONbits.OSWEN = 1; // enable PLL switch
    while (CLK8CONbits.OSWEN);
    CLK8CONbits.DIVSWEN =1;
    while (CLK8CONbits.DIVSWEN);
    
    /** PWM Clock */
    CLK5DIVbits.INTDIV = 2;
    CLK5CONbits.OE = 1;
    CLK5CONbits.ON = 1;
    CLK5CONbits.NOSC = 5; //new PLL input oscillator Fin
    CLK5CONbits.OSWEN = 1; // enable PLL switch
    while (CLK5CONbits.OSWEN);
    CLK5CONbits.DIVSWEN =1;
    while (CLK5CONbits.DIVSWEN);
    
    /** ADC Clock */
    CLK6DIVbits.INTDIV = 4;
    CLK6CONbits.OE = 1;
    CLK6CONbits.ON = 1;
    CLK6CONbits.NOSC = 5; //new PLL input oscillator Fin
    CLK6CONbits.OSWEN = 1; // enable PLL switch
    while (CLK6CONbits.OSWEN);
    CLK6CONbits.DIVSWEN =1;
    while (CLK6CONbits.DIVSWEN);
}
