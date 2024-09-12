/*******************************************************************************
  Input / Output Port Configuration Routine source File

  File Name:
    port_config.c

  Summary:
    This file includes subroutine for initializing GPIO pins as analog/digital,
    input or output etc. Also to PPS functionality to Remap-able input or output 
    pins.

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
#include "port_config.h"

#undef MCBOARD_UART
// *****************************************************************************
// *****************************************************************************
// Section: Functions
// *****************************************************************************
// *****************************************************************************
void CN_Configure (void);
void MapGPIOHWFunction (void);
// *****************************************************************************
/* Function:
    SetupGPIOPorts()

  Summary:
    Routine to set-up GPIO ports

  Description:
    Function initializes GPIO pins for input or output ports,analog/digital pins,
    remap the peripheral functions to desires RPx pins.

  Precondition:
    None.

  Parameters:
    None

  Returns:
    None.

  Remarks:
    None.
 */

void SetupGPIOPorts(void)
{
    // Reset all PORTx register (all inputs)
    #ifdef TRISA
        TRISA = 0xFFFF;
        LATA  = 0x0000;
    #endif
    #ifdef ANSELA
        ANSELA = 0x0000;
    #endif

    #ifdef TRISB
        TRISB = 0xFFFF;
        LATB  = 0x0000;
    #endif
    #ifdef ANSELB
        ANSELB = 0x0000;
    #endif

    #ifdef TRISC
        TRISC = 0xFFFF;
        LATC  = 0x0000;
    #endif
    #ifdef ANSELC
        ANSELC = 0x0000;
    #endif

    #ifdef TRISD
        TRISD = 0xFFFF;
        LATD  = 0x0000;
    #endif
    #ifdef ANSELD
        ANSELD = 0x0000;
    #endif

    MapGPIOHWFunction();

    return;
}
// *****************************************************************************
/* Function:
    Map_GPIO_HW_Function()

  Summary:
    Routine to setup GPIO pin used as input/output analog/digital etc

  Description:
    Function initializes GPIO pins as input or output port pins,analog/digital 
    pins,remap the peripheral functions to desires RPx pins.

  Precondition:
    None.

  Parameters:
    None

  Returns:
    None.

  Remarks:
    None.
 */

void MapGPIOHWFunction(void)
{  
    // Amplifier input and output pins
    // IA : OA1
    ANSELAbits.ANSELA4 = 1;
    TRISAbits.TRISA4 = 1;   // PIN14: OA1IN+/AD1AN1/CMP1B/RP4/RA4
    ANSELAbits.ANSELA3 = 1;
    TRISAbits.TRISA3 = 1;   // PIN13: OA1IN-/AD1ANN1/AD2AN0/RP3/RA3
    ANSELAbits.ANSELA2 = 1;
    
    
    // IB : OA2
    ANSELBbits.ANSELB2 = 1;
    TRISBbits.TRISB2 = 1;   // PIN22: OA2IN+/AD2AN4/CMP2B/RP18/RB2
    ANSELBbits.ANSELB1 = 1;
    TRISBbits.TRISB1 = 1;   // PIN21: TMS/OA2IN-/AD1AN4/AD2ANN1/RP17/RB1  
    ANSELBbits.ANSELB0 = 1;
  
    
    // IBUS : OA3
    ANSELBbits.ANSELB5 = 1;
    TRISBbits.TRISB5 = 1;   // PIN17: OA3IN+/AD2AN2/CMP3B/RP21/RB5
    ANSELAbits.ANSELA6 = 1;
    TRISAbits.TRISA6 = 1;   // PIN16: OA3IN-/AD1AN2/RP6/RA6
    ANSELAbits.ANSELA5 = 1;
    
#ifndef INTERNAL_OPAMP_CONFIG
    TRISAbits.TRISA2 = 1;   // PIN12: OA1OUT/AD1AN0/CMP1A/RP2/RA2   
    TRISBbits.TRISB0 = 1;   // PIN20: OA2OUT/AD2AN1/CMP2A/RP16/RB0 
    TRISAbits.TRISA5 = 1;   // PIN15: OA3OUT/AD1AN3/CMP3A/RP5/INT0/RA5
#endif
    
    // Potentiometer  input - used as Speed Reference
    // POT1 
    ANSELAbits.ANSELA11 = 1;
    TRISAbits.TRISA11 = 1;   // PIN06: AD1AN10/RP11/RA11
    
    // DC Bus Voltage  
    // VBUS 
    ANSELAbits.ANSELA7 = 1;
    TRISAbits.TRISA7 = 1;   // PIN07: AD1AN6/RP7/IOMONF1/RA7
     
    // Phase Voltages
    // VA,VB,VC 
    ANSELBbits.ANSELB9 = 1;
    TRISBbits.TRISB9 = 1;   // PIN24: AD2AN10/RP25/RB9
    ANSELBbits.ANSELB8 = 1;
    TRISBbits.TRISB8 = 1;   // PIN23: AD1AN11/RP24/RB8
    ANSELAbits.ANSELA10 = 1;
    TRISAbits.TRISA10 = 1;  // PIN09: AD2ANN3/AD2AN7/RP10/RA10
    
    // TEMERATURE INVERTER   
    ANSELAbits.ANSELA9 = 1;
    TRISAbits.TRISA9 = 1;  // PIN08: AD1ANN3/AD1AN9/RP9/RA9    
    
    // VABSREF
    ANSELAbits.ANSELA0 = 1;
    TRISAbits.TRISA0 = 1;   // PIN01: PGED2/AD2AN6/CMP3C/ISRC2/RP0/SDA2/IOMONF2/RA0
    
    /* Digital SIGNALS */   
    // DIGITAL INPUT/OUTPUT PINS

    // Inverter Control - PWM Outputs
    // PWM1L : PIN #54  TDI/RP51/PWM1L/IOMOND5/RD3
    // PWM1H : PIN #53  TDO/RP50/PWM1H/IOMOND4/RD2
    // PWM2L : PIN #52  TCK/RP49/PWM2L/IOMOND3/RD1
    // PWM2H : PIN #51  RP48/PWM2H/IOMOND2/RD0
    // PWM3L : PIN #44  RP36/PWM3L/IOMOND1/RC4
    // PWM3H : PIN #43  PGED3/RP35/PWM3H/IOMOND0/RC3
    TRISDbits.TRISD3 = 0 ;          
    TRISDbits.TRISD2 = 0 ;         
    TRISDbits.TRISD1 = 0 ;          
    TRISDbits.TRISD0 = 0 ;           
    TRISCbits.TRISC4 = 0 ;          
    TRISCbits.TRISC3 = 0 ;         
     
    // Debug LEDs
    // LED1 : DIM:030
    TRISDbits.TRISD5 = 0;
    // LED2 : DIM:032
    TRISCbits.TRISC9 = 0;

    // Push button Switches
    // SW1 : 
    TRISDbits.TRISD9 = 1;            // PIN:49 - RP57/IOMONF7/RD9
    // SW2 : 
    TRISDbits.TRISD10 = 1;           // PIN:50 - RP58/RD10
    
    //HALL/QEI Input Signals
    TRISCbits.TRISC6 = 1 ;          // PIN:35 : RP38/RC6
    TRISCbits.TRISC7 = 1 ;          // PIN:36 : RP39/RC7
    TRISCbits.TRISC8 = 1 ;          // PIN:33 : RP40/IOMOND11/IOMONF11/PCI20/RC8
    
//    TRISDbits.TRISD11 = 0 ;          
//    TRISDbits.TRISD8 = 0 ;         
//    TRISDbits.TRISD7 = 0 ;          
//    TRISDbits.TRISD6 = 0 ;           
//    TRISDbits.TRISD4 = 0 ;          
//    TRISDbits.TRISD12 = 0 ; 
    
	
	/** Diagnostic Interface
        Re-map UART Channels to the device pins connected to the following 
        device pins on the Motor Control Development Boards .
        UART_RX : PIN #46 - RP43/IOMOND8/IOMONF8/RC11 (Input)
        UART_TX : PIN #45 - RP42/IOMOND9/IOMONF9/RC10(Output)   */
//    _U1RXR = 61; // click board
//    _RP60R = 9;
    
    _U1RXR = 44;
    _RP43R = 9;
    
    _RP55R = 22; 
//        _RP55R = 9;
}
void OpampConfig (void)
{
    /** AMPxCON1 :AMPx Control Register 1*/
    AMP1CON1 = 0x0000;
    /** Bit 15 ? AMPEN Op Amp Enable/On bit 
        1 Enables op amp module ; 
        0 Disables op amp module */
    AMP1CON1bits.AMPEN = 0;
    /** Bit 14 ? HPEN High-Power Enable bit  
        1 Enables Op Amp High-Power (high bandwidth) mode ; 
        0 Disables Op Amp High-Power mode */    
    AMP1CON1bits.HPEN = 0;
    /** Bit 13 ? UGE Unity Gain Buffer Enable bit 
        1 Enables Unity Gain mode ; 
        0 Disables Unity Gain mode */
    AMP1CON1bits.UGE = 0;
    /** Bits 12:11 ? DIFFCON[1:0] Differential Input Mode Control bits
        11 Reserved, do not use; 
        10 Turn NMOS differential input pair off
        01 Turn PMOS differential input pair off 
        00 Use both NMOS and PMOS differential input pair */
    AMP1CON1bits.DIFFCON = 0;
    /** Bit 10 ? REFEN Input Reference Enable bit
        1 Noninverting input connected to internal device voltage source
        0 Noninverting input of op amp connected to user pin */
    AMP1CON1bits.REFEN = 0;
    /** Bit 9 ? IMONEN Enable Input Monitor bit
        1 Enables positive input to ADC ; 
        0 Disables positive input to ADC */    
    AMP1CON1bits.IMONEN = 0;
    /** Bit 8 ? OMONEN Enable Output Monitor bit
        1 Enables output to ADC; 
        0 Disables output to ADC */     
    AMP1CON1bits.OMONEN = 1;
    
    /** AMPxCON1 :AMPx Control Register 1*/
    AMP2CON1 = 0x0000;
    /** Bit 15 ? AMPEN Op Amp Enable/On bit 
        1 Enables op amp module ; 
        0 Disables op amp module */
    AMP2CON1bits.AMPEN = 0;
    /** Bit 14 ? HPEN High-Power Enable bit  
        1 Enables Op Amp High-Power (high bandwidth) mode ; 
        0 Disables Op Amp High-Power mode */    
    AMP2CON1bits.HPEN = 0;
    /** Bit 13 ? UGE Unity Gain Buffer Enable bit 
        1 Enables Unity Gain mode ; 
        0 Disables Unity Gain mode */
    AMP2CON1bits.UGE = 0;
    /** Bits 12:11 ? DIFFCON[1:0] Differential Input Mode Control bits
        11 Reserved, do not use; 
        10 Turn NMOS differential input pair off
        01 Turn PMOS differential input pair off 
        00 Use both NMOS and PMOS differential input pair */
    AMP2CON1bits.DIFFCON = 0;
    /** Bit 10 ? REFEN Input Reference Enable bit
        1 Noninverting input connected to internal device voltage source
        0 Noninverting input of op amp connected to user pin */
    AMP2CON1bits.REFEN = 0;
    /** Bit 9 ? IMONEN Enable Input Monitor bit
        1 Enables positive input to ADC ; 
        0 Disables positive input to ADC */    
    AMP2CON1bits.IMONEN = 0;
    /** Bit 8 ? OMONEN Enable Output Monitor bit
        1 Enables output to ADC; 
        0 Disables output to ADC */     
    AMP2CON1bits.OMONEN = 1;
    
    /** AMPxCON1 :AMPx Control Register 1*/
    AMP2CON1 = 0x0000;
    /** Bit 15 ? AMPEN Op Amp Enable/On bit 
        1 Enables op amp module ; 
        0 Disables op amp module */
    AMP2CON1bits.AMPEN = 0;
    /** Bit 14 ? HPEN High-Power Enable bit  
        1 Enables Op Amp High-Power (high bandwidth) mode ; 
        0 Disables Op Amp High-Power mode */    
    AMP2CON1bits.HPEN = 0;
    /** Bit 13 ? UGE Unity Gain Buffer Enable bit 
        1 Enables Unity Gain mode ; 
        0 Disables Unity Gain mode */
    AMP2CON1bits.UGE = 0;
    /** Bits 12:11 ? DIFFCON[1:0] Differential Input Mode Control bits
        11 Reserved, do not use; 
        10 Turn NMOS differential input pair off
        01 Turn PMOS differential input pair off 
        00 Use both NMOS and PMOS differential input pair */
    AMP2CON1bits.DIFFCON = 0;
    /** Bit 10 ? REFEN Input Reference Enable bit
        1 Noninverting input connected to internal device voltage source
        0 Noninverting input of op amp connected to user pin */
    AMP2CON1bits.REFEN = 0;
    /** Bit 9 ? IMONEN Enable Input Monitor bit
        1 Enables positive input to ADC ; 
        0 Disables positive input to ADC */    
    AMP2CON1bits.IMONEN = 0;
    /** Bit 8 ? OMONEN Enable Output Monitor bit
        1 Enables output to ADC; 
        0 Disables output to ADC */     
    AMP2CON1bits.OMONEN = 1;
    
    /** AMPxCON1 :AMPx Control Register 1*/
    AMP3CON1 = 0x0000;
    /** Bit 15 ? AMPEN Op Amp Enable/On bit 
        1 Enables op amp module ; 
        0 Disables op amp module */
    AMP3CON1bits.AMPEN = 0;
    /** Bit 14 ? HPEN High-Power Enable bit  
        1 Enables Op Amp High-Power (high bandwidth) mode ; 
        0 Disables Op Amp High-Power mode */    
    AMP3CON1bits.HPEN = 0;
    /** Bit 13 ? UGE Unity Gain Buffer Enable bit 
        1 Enables Unity Gain mode ; 
        0 Disables Unity Gain mode */
    AMP3CON1bits.UGE = 0;
    /** Bits 12:11 ? DIFFCON[1:0] Differential Input Mode Control bits
        11 Reserved, do not use; 
        10 Turn NMOS differential input pair off
        01 Turn PMOS differential input pair off 
        00 Use both NMOS and PMOS differential input pair */
    AMP3CON1bits.DIFFCON = 0;
    /** Bit 10 ? REFEN Input Reference Enable bit
        1 Noninverting input connected to internal device voltage source
        0 Noninverting input of op amp connected to user pin */
    AMP3CON1bits.REFEN = 0;
    /** Bit 9 ? IMONEN Enable Input Monitor bit
        1 Enables positive input to ADC ; 
        0 Disables positive input to ADC */    
    AMP3CON1bits.IMONEN = 0;
    /** Bit 8 ? OMONEN Enable Output Monitor bit
        1 Enables output to ADC; 
        0 Disables output to ADC */     
    AMP3CON1bits.OMONEN = 1;
    
    /** Bit 15 ? AMPEN Op Amp Enable/On bit 
        1 Enables op amp module ; 
        0 Disables op amp module */
    AMP1CON1bits.AMPEN = 1;
    /** Bit 15 ? AMPEN Op Amp Enable/On bit 
        1 Enables op amp module ; 
        0 Disables op amp module */
    AMP2CON1bits.AMPEN = 1;
    /** Bit 15 ? AMPEN Op Amp Enable/On bit 
        1 Enables op amp module ; 
        0 Disables op amp module */
    AMP3CON1bits.AMPEN = 1;
}

