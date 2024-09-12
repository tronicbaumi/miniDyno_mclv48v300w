/*******************************************************************************
  Source File for High-Resolution PWM with Fine Edge Placement Configuration

  File Name:
    pwm.c

  Summary:
    This file includes subroutine for initializing  High-Resolution PWM with 
    Fine Edge Placement 

  Description:
    Definitions in the file are for dsPIC33CK256MP508 MC DIM plugged onto
    Motor Control Development board from Microchip

*******************************************************************************/
/*******************************************************************************
* Copyright (c) 2017 released Microchip Technology Inc.  All rights reserved.
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
#include "pwm.h"

// *****************************************************************************
// *****************************************************************************
// Section: Functions
// *****************************************************************************
// *****************************************************************************
void InitPWMGenerator1 (void);
void InitPWMGenerator2 (void);
void InitPWMGenerator3 (void);
void InitDutyPWM123Generators(void);
void InitPWMGenerators(void);   
void ChargeBootstarpCapacitors(void);
// *****************************************************************************
/* Function:
    InitPWMGenerators()

  Summary:
    Routine to initialize PWM Module for Inverters

  Description:
    Function initializes  and enable the PWM Module after configuration

  Precondition:
    None.

  Parameters:
    None

  Returns:
    None.

  Remarks:
    None.
 */
void InitPWMGenerators(void)
{

    PCLKCON      = 0x0000;
    /* PWM Clock Divider Selection bits
       0b11 = 1:16 ; 0b10 = 1:8 ;0b01 = 1:4 ; 0b00 = 1:2*/
    PCLKCONbits.DIVSEL = 0;
    /* PWM Master Clock Selection bits
       0b11 = AFPLLO ; 0b10 = FPLLO ; 0b01 = AFVCO/2 ; 0b00 = FOSC */
    PCLKCONbits.MCLKSEL = 1;
    /* Lock bit: 0 = Write-protected registers and bits are unlocked   */
    PCLKCONbits.LOCK = 0;

    /* Initialize Master Phase Register */
    MPHASE       = 0x0000;
    /* Initialize Master Duty Cycle */
    MDC          = 0x0000;
    /* Initialize Master Period Register */
    MPER         = LOOPTIME_TCY;
    
    /* Initialize FREQUENCY SCALE REGISTER*/
    FSCL          = 0x0000;
    /* Initialize FREQUENCY SCALING MINIMUM PERIOD REGISTER */
    FSMINPER     = 0x0000;
    /* Initialize Linear Feedback Shift Register */
    LFSR         = 0x0000;
    /* Initialize Combinational Trigger Register Low */
    CMBTRIG     = 0x0000;
//    /* Initialize Combinational Trigger Register High */
//    CMBTRIGH     = 0x0000;
    /* Initialize LOGIC CONTROL REGISTER 1 LOW */
    LOGCONA     = 0x0000;
    /* Initialize LOGIC CONTROL REGISTER 1 HIGH */
    LOGCONB     = 0x0000;
    /* Initialize LOGIC CONTROL REGISTER 2 LOW */
    LOGCONC     = 0x0000;
    /* Initialize LOGIC CONTROL REGISTER 2 HIGH */
    LOGCOND     = 0x0000;
    /* Initialize LOGIC CONTROL REGISTER 3 LOW */
    LOGCONE     = 0x0000;
    /* Initialize LOGIC CONTROL REGISTER 3 High */
    LOGCONF     = 0x0000;
    /* PWM EVENT OUTPUT CONTROL REGISTER A */
    PWMEVTA     = 0x0000;     
    /* PWM EVENT OUTPUT CONTROL REGISTER B */
    PWMEVTB     = 0x0000;
    /* PWM EVENT OUTPUT CONTROL REGISTER C */
    PWMEVTC     = 0x0000;
    /* PWM EVENT OUTPUT CONTROL REGISTER D */
    PWMEVTD     = 0x0000;
    /* PWM EVENT OUTPUT CONTROL REGISTER E */
    PWMEVTE     = 0x0000;
    /* PWM EVENT OUTPUT CONTROL REGISTER F */
    PWMEVTF     = 0x0000;
    
    InitPWMGenerator1 ();
    InitPWMGenerator2 ();
    InitPWMGenerator3 (); 
    
    InitDutyPWM123Generators();

    _PWM1IF = 0;
    _PWM1IE = 0;
    _PWM1IP = 7;
	PG2CONbits.ON = 1;      // Enable PWM module after initializing generators
    PG3CONbits.ON = 1;      // Enable PWM module after initializing generators
    PG1CONbits.ON = 1;      // Enable PWM module after initializing generators

//    /* Function call to charge Bootstrap capacitors*/
//    ChargeBootstarpCapacitors();
}
// *****************************************************************************
/* Function:
    InitDutyPWM123Generators()

  Summary:
    Routine to initialize Duty cycle of PWM generators 1,2,3 

  Description:
    Function initializes Duty cycle of PWM module for 3-phase inverter control 
    in Complimentary mode 

  Precondition:
    None.

  Parameters:
    None

  Returns:
    None.

  Remarks:
    None.
 */
void InitDutyPWM123Generators(void)
{

// Enable PWMs only on PWMxL ,to charge bootstrap capacitors initially.
    // Hence PWMxH is over-ridden to "LOW"
   
    PG3IOCONbits.OVRDAT = 0;  // 0b00 = State for PWM3H,L, if Override is Enabled
    PG2IOCONbits.OVRDAT = 0;  // 0b00 = State for PWM2H,L, if Override is Enabled
    PG1IOCONbits.OVRDAT = 0;  // 0b00 = State for PWM1H,L, if Override is Enabled

    PG3IOCONbits.OVRENH = 1;  // 1 = OVRDAT<1> provides data for output on PWM3H
    PG2IOCONbits.OVRENH = 1;  // 1 = OVRDAT<1> provides data for output on PWM2H
    PG1IOCONbits.OVRENH = 1;  // 1 = OVRDAT<1> provides data for output on PWM1H

    PG3IOCONbits.OVRENL = 1;  // 0 = PWM generator provides data for PWM3L pin
    PG2IOCONbits.OVRENL = 1;  // 0 = PWM generator provides data for PWM2L pin
    PG1IOCONbits.OVRENL = 1;  // 0 = PWM generator provides data for PWM1L pin

    /* Set PWM Duty Cycles */
    PG3DC = 0;
    PG2DC = 0;      
    PG1DC = 0;

}

// *****************************************************************************
/* Function:
    Charge_Bootstrap_Capacitors()

  Summary:
    Routine to initialize PWM generators 1-3 to charge bootstrap capacitors

  Description:
    Function to charge bootstrap capacitors at the beginning

  Precondition:
    None.

  Parameters:
    None

  Returns:
    None.

  Remarks:
    None.
 */
void ChargeBootstarpCapacitors(void)
{
    uint16_t i = BOOTSTRAP_CHARGING_COUNTS;
    uint16_t prevStatusCAHALF = 0,currStatusCAHALF = 0;
    uint16_t k = 0;
    
    // Enable PWMs only on PWMxL ,to charge bootstrap capacitors at the beginning
    // Hence PWMxH is over-ridden to "LOW"
    PG3IOCONbits.OVRDAT = 0;  // 0b00 = State for PWM3H,L, if Override is Enabled
    PG2IOCONbits.OVRDAT = 0;  // 0b00 = State for PWM2H,L, if Override is Enabled
    PG1IOCONbits.OVRDAT = 0;  // 0b00 = State for PWM1H,L, if Override is Enabled

    PG3IOCONbits.OVRENH = 1;  // 1 = OVRDAT<1> provides data for output on PWM3H
    PG2IOCONbits.OVRENH = 1;  // 1 = OVRDAT<1> provides data for output on PWM2H
    PG1IOCONbits.OVRENH = 1;  // 1 = OVRDAT<1> provides data for output on PWM1H

    PG3IOCONbits.OVRENL = 1;  // 1 = OVRDAT<0> provides data for output on PWM3L
    PG2IOCONbits.OVRENL = 1;  // 1 = OVRDAT<0> provides data for output on PWM2L
    PG1IOCONbits.OVRENL = 1;  // 1 = OVRDAT<0> provides data for output on PWM1L

    // PDCx: PWMx GENERATOR DUTY CYCLE REGISTER
    // Initialize the PWM duty cycle for charging
    INVERTERA_PWM_PDC3 = LOOPTIME_TCY - (DDEADTIME/2 + 5);
    INVERTERA_PWM_PDC2 = LOOPTIME_TCY - (DDEADTIME/2 + 5);
    INVERTERA_PWM_PDC1 = LOOPTIME_TCY - (DDEADTIME/2 + 5);
    
    while(i)
    {
        prevStatusCAHALF = currStatusCAHALF;
        currStatusCAHALF = PG1STATbits.CAHALF;
        if (prevStatusCAHALF != currStatusCAHALF)
        {
            if (currStatusCAHALF == 0)
            {
                i--; 
                k++;
                if (i == (BOOTSTRAP_CHARGING_COUNTS - 50))
                {
                    // 0 = PWM generator provides data for PWM1L pin
                    PG1IOCONbits.OVRENL = 0;
                }
                else if (i == (BOOTSTRAP_CHARGING_COUNTS - 150))
                {
                    // 0 = PWM generator provides data for PWM2L pin
                    PG2IOCONbits.OVRENL = 0;  
                }
                else if (i == (BOOTSTRAP_CHARGING_COUNTS - 250))
                {
                    // 0 = PWM generator provides data for PWM3L pin
                    PG3IOCONbits.OVRENL = 0;  
                }
                if (k > 25)
                {
                    if (PG3IOCONbits.OVRENL == 0)
                    {
                        if (INVERTERA_PWM_PDC3 > 2)
                        {
                            INVERTERA_PWM_PDC3 -= 2;
                        }
                        else
                        {
                           INVERTERA_PWM_PDC3 = 0; 
                        }
                    }
                    if (PG2IOCONbits.OVRENL == 0)
                    {
                        if (INVERTERA_PWM_PDC2 > 2)
                        {
                            INVERTERA_PWM_PDC2 -= 2;
                        }
                        else
                        {
                            INVERTERA_PWM_PDC2 = 0; 
                        }
                    }
                    if (PG1IOCONbits.OVRENL == 0)
                    {
                        if (INVERTERA_PWM_PDC1 > 2)
                        {
                            INVERTERA_PWM_PDC1 -= 2;
                        }
                        else
                        {
                            INVERTERA_PWM_PDC1 = 0; 
                        }
                    }
                    k = 0;
                } 
            }
        }
    }
    // PDCx: PWMx GENERATOR DUTY CYCLE REGISTER
    // Initialize the PWM duty cycle for charging
    INVERTERA_PWM_PDC3 = 0;
    INVERTERA_PWM_PDC2 = 0;
    INVERTERA_PWM_PDC1 = 0;

    PG3IOCONbits.OVRENH = 0;  // 0 = PWM generator provides data for PWM3H pin
    PG2IOCONbits.OVRENH = 0;  // 0 = PWM generator provides data for PWM2H pin
    PG1IOCONbits.OVRENH = 0;  // 0 = PWM generator provides data for PWM1H pin
}
// *****************************************************************************
/* Function:
    InitPWM1Generator()

  Summary:
    Routine to initialize PWM generators 1 

  Description:
    Function initializes PWM module for 3-phase inverter control in Complimentary
    mode ;initializes period,dead time;Configures PWM fault control logic

  Precondition:
    None.

  Parameters:
    None

  Returns:
    None.

  Remarks:
    None.
 */
void InitPWMGenerator1 (void)
{

    /* Initialize PWM GENERATOR 1 CONTROL REGISTER LOW */
    PG1CON      = 0x0000;
    /* PWM Generator 1 Enable bit : 1 = Is enabled, 0 = Is not enabled */
    /* Ensuring PWM Generator is disabled prior to configuring module */
    PG1CONbits.ON = 0;
    /* Clock Selection bits
       0b01 = Macro uses Master clock selected by the PCLKCON.MCLKSEL bits*/
    PG1CONbits.CLKSEL = 1;
    /* PWM Mode Selection bits
     * 110 = Dual Edge Center-Aligned PWM mode (interrupt/register update once per cycle)
       100 = Center-Aligned PWM mode(interrupt/register update once per cycle)*/
#ifdef SINGLE_SHUNT
    PG1CONLbits.MODSEL = 6;
#else
    PG1CONbits.MODSEL = 4;
#endif 
    /* Trigger Count Select bits
       000 = PWM Generator produces 1 PWM cycle after triggered */
    PG1CONbits.TRGCNT = 0;
    
//    /* Initialize PWM GENERATOR 1 CONTROL REGISTER HIGH */
//    PG1CONH      = 0x0000;
    /* Master Duty Cycle Register Select bit
       1 = Macro uses the MDC register instead of PG1DC
       0 = Macro uses the PG1DC register*/
    PG1CONbits.MDCSEL = 0;
    /* Master Period Register Select bit
       1 = Macro uses the MPER register instead of PG1PER
       0 = Macro uses the PG1PER register */
    PG1CONbits.MPERSEL = 1;
    /* MPHSEL: Master Phase Register Select bit
       1 = Macro uses the MPHASE register instead of PG1PHASE
       0 = Macro uses the PG1PHASE register */
    PG1CONbits.MPHSEL = 0;
    /* Master Update Enable bit
       1 = PWM Generator broadcasts software set/clear of UPDATE status bit and 
           EOC signal to other PWM Generators
       0 = PWM Generator does not broadcast UPDATE status bit or EOC signal */
    PG1CONbits.MSTEN = 1;
    /* PWM Buffer Update Mode Selection bits 
       Update Data registers at start of next PWM cycle if UPDATE = 1. */
    PG1CONbits.UPDMOD = 0;
    /* PWM Generator Trigger Mode Selection bits
       0b00 = PWM Generator operates in Single Trigger mode */
    PG1CONbits.TRGMOD = 0;
    /* Start of Cycle Selection bits
       0000 = Local EOC*/
    PG1CONbits.SOCS = 0;
    
    /* Clear PWM GENERATOR 1 STATUS REGISTER*/
    PG1STAT      = 0x0000;
    /* Initialize PWM GENERATOR 1 I/O CONTROL REGISTER LOW */
    PG1IOCON    = 0x0000;

    /* Current Limit Mode Select bit
       0 = If PCI current limit is active, then the CLDAT<1:0> bits define 
       the PWM output levels */
    PG1IOCONbits.CLMOD = 0;
    /* Swap PWM Signals to PWM1H and PWM1L Device Pins bit 
       0 = PWM1H/L signals are mapped to their respective pins */
    PG1IOCONbits.SWAP = 0;
    /* User Override Enable for PWM1H Pin bit
       0 = PWM Generator provides data for the PWM1H pin*/
    PG1IOCONbits.OVRENH = 0;
    /* User Override Enable for PWM1L Pin bit
       0 = PWM Generator provides data for the PWM1L pin*/
    PG1IOCONbits.OVRENL = 0;
    /* Data for PWM1H/PWM1L Pins if Override is Enabled bits
       If OVERENH = 1, then OVRDAT<1> provides data for PWM1H.
       If OVERENL = 1, then OVRDAT<0> provides data for PWM1L */
    PG1IOCONbits.OVRDAT = 0;
    /* User Output Override Synchronization Control bits
       00 = User output overrides via the OVRENL/H and OVRDAT<1:0> bits are 
       synchronized to the local PWM time base (next start of cycle)*/
    PG1IOCONbits.OSYNC = 0;
    /* Data for PWM1H/PWM1L Pins if FLT Event is Active bits
       If Fault is active, then FLTDAT<1> provides data for PWM1H.
       If Fault is active, then FLTDAT<0> provides data for PWM1L.*/
    PG1IOCONbits.FLTDAT = 0;
    /* Data for PWM1H/PWM1L Pins if CLMT Event is Active bits
       If current limit is active, then CLDAT<1> provides data for PWM1H.
       If current limit is active, then CLDAT<0> provides data for PWM1L.*/
    PG1IOCONbits.CLDAT = 0;
    /* Data for PWM1H/PWM1L Pins if Feed-Forward Event is Active bits
       If feed-forward is active, then FFDAT<1> provides data for PWM1H.
       If feed-forward is active, then FFDAT<0> provides data for PWM1L.*/
    PG1IOCONbits.FFDAT = 0;
    /* Data for PWM1H/PWM1L Pins if Debug Mode is Active and PTFRZ = 1 bits
       If Debug mode is active and PTFRZ=1,then DBDAT<1> provides PWM1H data.
       If Debug mode is active and PTFRZ=1,then DBDAT<0> provides PWM1L data. */
    PG1IOCONbits.DBDAT = 0;
    
//    /* Initialize PWM GENERATOR 1 I/O CONTROL REGISTER HIGH */    
//    PG1IOCONH    = 0x0000;
    /* Time Base Capture Source Selection bits
       000 = No hardware source selected for time base capture ? software only*/
    PG1IOCONbits.CAPSRC = 0;
    /* Dead-Time Compensation Select bit 
       0 = Dead-time compensation is controlled by PCI Sync logic */
    PG1IOCONbits.DTCMPSEL = 0;
    /* PWM Generator Output Mode Selection bits
       00 = PWM Generator outputs operate in Complementary mode*/
    PG1IOCONbits.PMOD = 0;
    /* PWM1H Output Port Enable bit
       1 = PWM Generator controls the PWM1H output pin
       0 = PWM Generator does not control the PWM1H output pin */
    PG1IOCONbits.PENH = 1;
    /* PWM1L Output Port Enable bit
       1 = PWM Generator controls the PWM1L output pin
       0 = PWM Generator does not control the PWM1L output pin */
    PG1IOCONbits.PENL = 1;
    /* PWM1H Output Polarity bit
       1 = Output pin is active-low
       0 = Output pin is active-high*/
    PG1IOCONbits.POLH = 0;
    /* PWM1L Output Polarity bit
       1 = Output pin is active-low
       0 = Output pin is active-high*/
    PG1IOCONbits.POLL = 0;
    
    /* Initialize PWM GENERATOR 1 EVENT REGISTER LOW*/
    PG1EVT      = 0x0000;
    /* ADC Trigger 1 Post-scaler Selection bits
       00000 = 1:1 */
    PG1EVTbits.ADTR1PS = 0;
    /* ADC Trigger 1 Source is PG1TRIGC Compare Event Enable bit
       0 = PG1TRIGC register compare event is disabled as trigger source for 
           ADC Trigger 1 */
    PG1EVTbits.ADTR1EN3  = 0;
    /* ADC Trigger 1 Source is PG1TRIGB Compare Event Enable bit
       0 = PG1TRIGB register compare event is disabled as trigger source for 
           ADC Trigger 1 */
    PG1EVTbits.ADTR1EN2 = 0;    
    /* ADC Trigger 1 Source is PG1TRIGA Compare Event Enable bit
       1 = PG1TRIGA register compare event is enabled as trigger source for 
           ADC Trigger 1 */
    PG1EVTbits.ADTR1EN1 = 1;
    /* Update Trigger Select bits
       01 = A write of the PG1DC register automatically sets the UPDATE bit*/
    PG1EVTbits.UPDTRG = 1;
    /* PWM Generator Trigger Output Selection bits
       000 = EOC event is the PWM Generator trigger*/
    PG1EVTbits.PGTRGSEL = 0;
    
//    /* Initialize PWM GENERATOR 1 EVENT REGISTER HIGH */
//    PG1EVTH      = 0x0000;
    /* FLTIEN: PCI Fault Interrupt Enable bit
       1 = Fault interrupt is enabled */
    PG1EVTbits.FLTIEN = 1;
    /* PCI Current Limit Interrupt Enable bit
       0 = Current limit interrupt is disabled */
    PG1EVTbits.CLIEN = 0;
    /* PCI Feed-Forward Interrupt Enable bit
       0 = Feed-forward interrupt is disabled */
    PG1EVTbits.FFIEN = 0;
    /* PCI Sync Interrupt Enable bit
       0 = Sync interrupt is disabled */
    PG1EVTbits.SIEN = 0;
    /* Interrupt Event Selection bits
       00 = Interrupts CPU at EOC
       01 = Interrupts CPU at TRIGA compare event
       10 = Interrupts CPU at ADC Trigger 1 event
       11 = Time base interrupts are disabled */
    PG1EVTbits.IEVTSEL = 3;
#ifdef SINGLE_SHUNT
    /* ADC Trigger 2 Source is PG1TRIGC Compare Event Enable bit
       0 = PG1TRIGC register compare event is enabled as 
           trigger source for ADC Trigger 2 */
    PG1EVTHbits.ADTR2EN3 = 1;
    /* ADC Trigger 2 Source is PG1TRIGB Compare Event Enable bit
       0 = PG1TRIGB register compare event is enabled as 
           trigger source for ADC Trigger 2 */
    PG1EVTHbits.ADTR2EN2 = 1;
#else
        /* ADC Trigger 2 Source is PG1TRIGC Compare Event Enable bit
       0 = PG1TRIGC register compare event is disabled as 
           trigger source for ADC Trigger 2 */
    PG1EVTbits.ADTR2EN3 = 0;
    /* ADC Trigger 2 Source is PG1TRIGB Compare Event Enable bit
       0 = PG1TRIGB register compare event is disabled as 
           trigger source for ADC Trigger 2 */
    PG1EVTbits.ADTR2EN2 = 0;
#endif
    /* ADC Trigger 2 Source is PG1TRIGA Compare Event Enable bit
       0 = PG1TRIGA register compare event is disabled as 
           trigger source for ADC Trigger 2 */
    PG1EVTbits.ADTR2EN1 = 0;
    /* ADC Trigger 1 Offset Selection bits
       00000 = No offset */
    PG1EVTbits.ADTR1OFS = 0;
    
#ifndef ENABLE_PWM_FAULT
    /* PWM GENERATOR 1 Fault PCI REGISTER LOW */
    PG1FPCI     = 0x0000;
//    /* PWM GENERATOR 1 Fault PCI REGISTER HIGH */
//    PG1FPCIH     = 0x0000;
#else
       /* PWM GENERATOR 1 Fault PCI REGISTER LOW */
    PG1FPCI     = 0x0000;
    /* Termination Synchronization Disable bit
       1 = Termination of latched PCI occurs immediately
       0 = Termination of latched PCI occurs at PWM EOC */
    PG1FPCIbits.TSYNCDIS = 0;
    /* Termination Event Selection bits
       001 = Auto-Terminate: Terminate when PCI source transitions from 
             active to inactive */
    PG1FPCIbits.TERM = 1;
    /* Acceptance Qualifier Polarity Select bit: 0 = Not inverted 1 = Inverted*/
    PG1FPCIbits.AQPS = 0;
    /* Acceptance Qualifier Source Selection bits
       111 = SWPCI control bit only (qualifier forced to 0)
       110 = Selects PCI Source #9
       101 = Selects PCI Source #8
       100 = Selects PCI Source #1 (PWM Generator output selected by the PWMPCI<2:0> bits)
       011 = PWM Generator is triggered
       010 = LEB is active
       001 = Duty cycle is active (base PWM Generator signal)        
       000 = No acceptance qualifier is used (qualifier forced to 1) */
    PG1FPCIbits.AQSS = 0;
    /* PCI Synchronization Control bit
       1 = PCI source is synchronized to PWM EOC
       0 = PCI source is not synchronized to PWM EOC*/
    PG1FPCIbits.PSYNC = 0;
    /* PCI Polarity Select bit 0 = Not inverted 1 = Inverted */
    PG1FPCIbits.PPS = 1;
    /* PCI Source Selection bits
       11111 = PCI Source #31
       ? ?
       00001 = PCI Source #1
       00000 = Software PCI control bit (SWPCI) only*/
    PG1FPCIbits.PSS = 9;
    
//    /* PWM GENERATOR 1 Fault PCI REGISTER HIGH */
//    PG1FPCIH     = 0x0000;
    /* PCI Bypass Enable bit
       0 = PCI function is not bypassed */
    PG1FPCIbits.BPEN   = 0;
    /* PCI Bypass Source Selection bits(1)
       000 = PCI control is sourced from PG1 PCI logic when BPEN = 1 */
    PG1FPCIbits.BPSEL   = 0;
    /* PCI Acceptance Criteria Selection bits
       101 = Latched any edge(2)
       100 = Latched rising edge
       011 = Latched
       010 = Any edge
       001 = Rising edge
       000 = Level-sensitive*/
    PG1FPCIbits.ACP   = 3;
//    /* PCI SR Latch Mode bit
//       1 = SR latch is Reset-dominant in Latched Acceptance modes
//       0 = SR latch is Set-dominant in Latched Acceptance modes*/
//    PG1FPCIbits  = 0;
    /* Termination Qualifier Polarity Select bit 1 = Inverted 0 = Not inverted*/
    PG1FPCIbits.TQPS   = 0;
    /* Termination Qualifier Source Selection bits
       111 = SWPCI control bit only (qualifier forced to ?1?b0?)(3)
       110 = Selects PCI Source #9 (pwm_pci[9] input port)
       101 = Selects PCI Source #8 (pwm_pci[8] input port)
       100 = Selects PCI Source #1 (PWM Generator output selected by the PWMPCI<2:0> bits)
       011 = PWM Generator is triggered
       010 = LEB is active
       001 = Duty cycle is active (base PWM Generator signal)
       000 = No termination qualifier used (qualifier forced to ?1?b1?)(3)*/
    PG1FPCIbits.TQSS  = 3;
#endif    

    /* PWM GENERATOR 1 Current Limit PCI REGISTER LOW */
    PG1CLPCI    = 0x0000;
//    /* PWM GENERATOR 1 Current Limit PCI REGISTER HIGH */
//    PG1CLPCIH    = 0x0000;
    /* PWM GENERATOR 1 Feed Forward PCI REGISTER LOW */
    PG1FFPCI    = 0x0000;
//    /* PWM GENERATOR 1 Feed Forward  PCI REGISTER HIGH */
//    PG1FFPCIH    = 0x0000;
    /* PWM GENERATOR 1 Sync PCI REGISTER LOW */
    PG1SPCI     = 0x0000;
//    /* PWM GENERATOR 1 Sync PCI REGISTER LOW */
//    PG1SPCIH     = 0x0000;
    
    /* Initialize PWM GENERATOR 1 LEADING-EDGE BLANKING REGISTER LOW */
    PG1LEB      = 0x0000;
//    /* Initialize PWM GENERATOR 1 LEADING-EDGE BLANKING REGISTER HIGH*/
//    PG1LEBH      = 0x0000;
    
    /* Initialize PWM GENERATOR 1 PHASE REGISTER */
    PG1PHASE     = 0x0000;
    /* Initialize PWM GENERATOR 1 DUTY CYCLE REGISTER */
    PG1DC        = MIN_DUTY;
    /* Initialize PWM GENERATOR 1 DUTY CYCLE ADJUSTMENT REGISTER */
    PG1DCA       = 0x0000;
    /* Initialize PWM GENERATOR 1 PERIOD REGISTER */
    PG1PER       = 0x0000;
    /* Initialize PWM GENERATOR 1 DEAD-TIME REGISTER LOW */
    PG1DTbits.DTH       = DDEADTIME;
    /* Initialize PWM GENERATOR 1 DEAD-TIME REGISTER HIGH */
    PG1DTbits.DTL      = DDEADTIME;

    /* Initialize PWM GENERATOR 1 TRIGGER A REGISTER */
    PG1TRIGA     = ADC_SAMPLING_POINT;
    /* Initialize PWM GENERATOR 1 TRIGGER B REGISTER */
    PG1TRIGB     = 0x0000;
    /* Initialize PWM GENERATOR 1 TRIGGER C REGISTER */
    PG1TRIGC     = 0x0000;
    
}
    
// *****************************************************************************
/* Function:
    InitPWMGenerator2()

  Summary:
    Routine to initialize PWM generators 2 

  Description:
    Function initializes PWM module for 3-phase inverter control in Complimentary
    mode ;initializes period,dead time;Configures PWM fault control logic

  Precondition:
    None.

  Parameters:
    None

  Returns:
    None.

  Remarks:
    None.
 */
void InitPWMGenerator2 (void)
{

    /* Initialize PWM GENERATOR 2 CONTROL REGISTER LOW */
    PG2CON      = 0x0000;
    /* PWM Generator 2 Enable bit : 1 = Is enabled, 0 = Is not enabled */
    /* PWM Generator is disabled prior to configuring module */
    PG2CONbits.ON = 0;
    /* Clock Selection bits
       0b01 = Macro uses Master clock selected by the PCLKCON.MCLKSEL bits*/
    PG2CONbits.CLKSEL = 1;
    /* PWM Mode Selection bits
     * 110 = Dual Edge Center-Aligned PWM mode (interrupt/register update once per cycle)
       100 = Center-Aligned PWM mode(interrupt/register update once per cycle)*/
#ifdef SINGLE_SHUNT
    PG2CONLbits.MODSEL = 6;
#else
    PG2CONbits.MODSEL = 4;
#endif 
    /* Trigger Count Select bits
       000 = PWM Generator produces 1 PWM cycle after triggered */
    PG2CONbits.TRGCNT = 0;
    
//    /* Initialize PWM GENERATOR 2 CONTROL REGISTER HIGH */
//    PG2CONH      = 0x0000;
    /* Master Duty Cycle Register Select bit
       1 = Macro uses the MDC register instead of PG2DC
       0 = Macro uses the PG2DC register*/
    PG2CONbits.MDCSEL = 0;
    /* Master Period Register Select bit
       1 = Macro uses the MPER register instead of PG2PER
       0 = Macro uses the PG2PER register */
    PG2CONbits.MPERSEL = 1;
    /* MPHSEL: Master Phase Register Select bit
       1 = Macro uses the MPHASE register instead of PG2PHASE
       0 = Macro uses the PG2PHASE register */
    PG2CONbits.MPHSEL = 0;
    /* Master Update Enable bit
       1 = PWM Generator broadcasts software set/clear of UPDATE status bit and 
           EOC signal to other PWM Generators
       0 = PWM Generator does not broadcast UPDATE status bit or EOC signal */
    PG2CONbits.MSTEN = 0;
     /* PWM Buffer Update Mode Selection bits 
       0b010 = Slaved SOC Update Data registers at start of next cycle if a 
       master update request is received. A master update request will be 
       transmitted if MSTEN = 1 and UPDATE = 1 for the requesting PWM
       Generator.. */
	PG2CONbits.UPDMOD = 0b010;
    /* PWM Generator Trigger Mode Selection bits
       0b00 = PWM Generator operates in Single Trigger mode */
    PG2CONbits.TRGMOD = 0;
    /* Start of Cycle Selection bits
       0001 = PWM1 trigger o/p selected by PG1 PGTRGSEL<2:0> bits(PGxEVT<2:0>)*/
    PG2CONbits.SOCS = 1;
    
    /* Clear PWM GENERATOR 2 STATUS REGISTER*/
    PG2STAT      = 0x0000;
    /* Initialize PWM GENERATOR 2 I/O CONTROL REGISTER LOW */
    PG2IOCON    = 0x0000;

    /* Current Limit Mode Select bit
       0 = If PCI current limit is active, then the CLDAT<1:0> bits define 
       the PWM output levels */
    PG2IOCONbits.CLMOD = 0;
    /* Swap PWM Signals to PWM2H and PWM2L Device Pins bit 
       0 = PWM2H/L signals are mapped to their respective pins */
    PG2IOCONbits.SWAP = 0;
    /* User Override Enable for PWM2H Pin bit
       0 = PWM Generator provides data for the PWM2H pin*/
    PG2IOCONbits.OVRENH = 0;
    /* User Override Enable for PWM2L Pin bit
       0 = PWM Generator provides data for the PWM2L pin*/
    PG2IOCONbits.OVRENL = 0;
    /* Data for PWM2H/PWM2L Pins if Override is Enabled bits
       If OVERENH = 1, then OVRDAT<1> provides data for PWM2H.
       If OVERENL = 1, then OVRDAT<0> provides data for PWM2L */
    PG2IOCONbits.OVRDAT = 0;
    /* User Output Override Synchronization Control bits
       00 = User output overrides via the OVRENL/H and OVRDAT<1:0> bits are 
       synchronized to the local PWM time base (next start of cycle)*/
    PG2IOCONbits.OSYNC = 0;
    /* Data for PWM2H/PWM2L Pins if FLT Event is Active bits
       If Fault is active, then FLTDAT<1> provides data for PWM2H.
       If Fault is active, then FLTDAT<0> provides data for PWM2L.*/
    PG2IOCONbits.FLTDAT = 0;
    /* Data for PWM2H/PWM2L Pins if CLMT Event is Active bits
       If current limit is active, then CLDAT<1> provides data for PWM2H.
       If current limit is active, then CLDAT<0> provides data for PWM2L.*/
    PG2IOCONbits.CLDAT = 0;
    /* Data for PWM2H/PWM2L Pins if Feed-Forward Event is Active bits
       If feed-forward is active, then FFDAT<1> provides data for PWM2H.
       If feed-forward is active, then FFDAT<0> provides data for PWM2L.*/
    PG2IOCONbits.FFDAT = 0;
    /* Data for PWM2H/PWM2L Pins if Debug Mode is Active and PTFRZ = 1 bits
       If Debug mode is active and PTFRZ=1,then DBDAT<1> provides PWM2H data.
       If Debug mode is active and PTFRZ=1,then DBDAT<0> provides PWM2L data. */
    PG2IOCONbits.DBDAT = 0;
    
//    /* Initialize PWM GENERATOR 2 I/O CONTROL REGISTER HIGH */    
//    PG2IOCONH    = 0x0000;
    /* Time Base Capture Source Selection bits
       000 = No hardware source selected for time base capture ? software only*/
    PG2IOCONbits.CAPSRC = 0;
    /* Dead-Time Compensation Select bit 
       0 = Dead-time compensation is controlled by PCI Sync logic */
    PG2IOCONbits.DTCMPSEL = 0;
    /* PWM Generator Output Mode Selection bits
       00 = PWM Generator outputs operate in Complementary mode*/
    PG2IOCONbits.PMOD = 0;
    /* PWM2H Output Port Enable bit
       1 = PWM Generator controls the PWM2H output pin
       0 = PWM Generator does not control the PWM2H output pin */
    PG2IOCONbits.PENH = 1;
    /* PWM2L Output Port Enable bit
       1 = PWM Generator controls the PWM2L output pin
       0 = PWM Generator does not control the PWM2L output pin */
    PG2IOCONbits.PENL = 1;
    /* PWM2H Output Polarity bit
       1 = Output pin is active-low
       0 = Output pin is active-high*/
    PG2IOCONbits.POLH = 0;
    /* PWM2L Output Polarity bit
       1 = Output pin is active-low
       0 = Output pin is active-high*/
    PG2IOCONbits.POLL = 0;
    
    /* Initialize PWM GENERATOR 2 EVENT REGISTER LOW*/
    PG2EVT      = 0x0000;
    /* ADC Trigger 1 Post-scaler Selection bits
       00000 = 1:1 */
    PG2EVTbits.ADTR1PS = 0;
    /* ADC Trigger 1 Source is PG2TRIGC Compare Event Enable bit
       0 = PG2TRIGC register compare event is disabled as trigger source for 
           ADC Trigger 1 */
    PG2EVTbits.ADTR1EN3  = 0;
    /* ADC Trigger 1 Source is PG2TRIGB Compare Event Enable bit
       0 = PG2TRIGB register compare event is disabled as trigger source for 
           ADC Trigger 1 */
    PG2EVTbits.ADTR1EN2 = 0;
    /* ADC Trigger 1 Source is PG2TRIGA Compare Event Enable bit
       0 = PG2TRIGA register compare event is disabled as trigger source for 
           ADC Trigger 1 */
    PG2EVTbits.ADTR1EN1 = 0;
    /* Update Trigger Select bits
       01 = A write of the PG2DC register automatically sets the UPDATE bit
       00 = User must set the UPDATE bit manually*/
    PG2EVTbits.UPDTRG = 0;
    /* PWM Generator Trigger Output Selection bits
       000 = EOC event is the PWM Generator trigger*/
    PG2EVTbits.PGTRGSEL = 0;
    
//    /* Initialize PWM GENERATOR 2 EVENT REGISTER HIGH */
//    PG2EVTH      = 0x0000;
    /* FLTIEN: PCI Fault Interrupt Enable bit
       0 = Fault interrupt is disabled */
    PG2EVTbits.FLTIEN = 0;
    /* PCI Current Limit Interrupt Enable bit
       0 = Current limit interrupt is disabled */
    PG2EVTbits.CLIEN = 0;
    /* PCI Feed-Forward Interrupt Enable bit
       0 = Feed-forward interrupt is disabled */
    PG2EVTbits.FFIEN = 0;
    /* PCI Sync Interrupt Enable bit
       0 = Sync interrupt is disabled */
    PG2EVTbits.SIEN = 0;
    /* Interrupt Event Selection bits
       00 = Interrupts CPU at EOC
       01 = Interrupts CPU at TRIGA compare event
       10 = Interrupts CPU at ADC Trigger 1 event
       11 = Time base interrupts are disabled */
    PG2EVTbits.IEVTSEL = 3;
    /* ADC Trigger 2 Source is PG2TRIGC Compare Event Enable bit
       0 = PG2TRIGC register compare event is disabled as 
           trigger source for ADC Trigger 2 */
    PG2EVTbits.ADTR2EN3 = 0;
    /* ADC Trigger 2 Source is PG2TRIGB Compare Event Enable bit
       0 = PG2TRIGB register compare event is disabled as 
           trigger source for ADC Trigger 2 */
    PG2EVTbits.ADTR2EN2 = 0;
    /* ADC Trigger 2 Source is PG2TRIGA Compare Event Enable bit
       0 = PG2TRIGA register compare event is disabled as 
           trigger source for ADC Trigger 2 */
    PG2EVTbits.ADTR2EN1 = 0;
    /* ADC Trigger 1 Offset Selection bits
       00000 = No offset */
    PG2EVTbits.ADTR1OFS = 0;
    
#ifndef ENABLE_PWM_FAULT
    /* PWM GENERATOR 1 Fault PCI REGISTER LOW */
    PG2FPCI     = 0x0000;
//    /* PWM GENERATOR 1 Fault PCI REGISTER HIGH */
//    PG2FPCIH     = 0x0000;
#else
       /* PWM GENERATOR 1 Fault PCI REGISTER LOW */
    PG2FPCI     = 0x0000;
    /* Termination Synchronization Disable bit
       1 = Termination of latched PCI occurs immediately
       0 = Termination of latched PCI occurs at PWM EOC */
    PG2FPCIbits.TSYNCDIS = 0;
    /* Termination Event Selection bits
       001 = Auto-Terminate: Terminate when PCI source transitions from 
             active to inactive */
    PG2FPCIbits.TERM = 1;
    /* Acceptance Qualifier Polarity Select bit: 0 = Not inverted 1 = Inverted*/
    PG2FPCIbits.AQPS = 0;
    /* Acceptance Qualifier Source Selection bits
       111 = SWPCI control bit only (qualifier forced to 0)
       110 = Selects PCI Source #9
       101 = Selects PCI Source #8
       100 = Selects PCI Source #1 (PWM Generator output selected by the PWMPCI<2:0> bits)
       011 = PWM Generator is triggered
       010 = LEB is active
       001 = Duty cycle is active (base PWM Generator signal)        
       000 = No acceptance qualifier is used (qualifier forced to 1) */
    PG2FPCIbits.AQSS = 0;
    /* PCI Synchronization Control bit
       1 = PCI source is synchronized to PWM EOC
       0 = PCI source is not synchronized to PWM EOC*/
    PG2FPCIbits.PSYNC = 0;
    /* PCI Polarity Select bit 0 = Not inverted 1 = Inverted*/
    PG2FPCIbits.PPS = 1;
    /* PCI Source Selection bits
       11111 = PCI Source #31
       ? ?
       00001 = PCI Source #1
       00000 = Software PCI control bit (SWPCI) only*/
    PG2FPCIbits.PSS = 9;
    
//    /* PWM GENERATOR 1 Fault PCI REGISTER HIGH */
//    PG2FPCIH     = 0x0000;
    /* PCI Bypass Enable bit
       0 = PCI function is not bypassed */
    PG2FPCIbits.BPEN   = 0;
    /* PCI Bypass Source Selection bits(1)
       000 = PCI control is sourced from PG1 PCI logic when BPEN = 1 */
    PG2FPCIbits.BPSEL   = 0;
    /* PCI Acceptance Criteria Selection bits
       101 = Latched any edge(2)
       100 = Latched rising edge
       011 = Latched
       010 = Any edge
       001 = Rising edge
       000 = Level-sensitive*/
    PG2FPCIbits.ACP   = 3;
//    /* PCI SR Latch Mode bit
//       1 = SR latch is Reset-dominant in Latched Acceptance modes
//       0 = SR latch is Set-dominant in Latched Acceptance modes*/
//    PG2FPCIbits.PCIGT  = 0;
    /* Termination Qualifier Polarity Select bit 1 = Inverted 0 = Not inverted*/
    PG2FPCIbits.TQPS   = 0;
    /* Termination Qualifier Source Selection bits
       111 = SWPCI control bit only (qualifier forced to ?1?b0?)(3)
       110 = Selects PCI Source #9 (pwm_pci[9] input port)
       101 = Selects PCI Source #8 (pwm_pci[8] input port)
       100 = Selects PCI Source #1 (PWM Generator output selected by the PWMPCI<2:0> bits)
       011 = PWM Generator is triggered
       010 = LEB is active
       001 = Duty cycle is active (base PWM Generator signal)
       000 = No termination qualifier used (qualifier forced to ?1?b1?)(3)*/
    PG2FPCIbits.TQSS  = 3;
#endif
    
    /* PWM GENERATOR 2 Current Limit PCI REGISTER LOW */
    PG2CLPCI    = 0x0000;
//    /* PWM GENERATOR 2 Current Limit PCI REGISTER HIGH */
//    PG2CLPCIH    = 0x0000;
    /* PWM GENERATOR 2 Feed Forward PCI REGISTER LOW */
    PG2FFPCI    = 0x0000;
//    /* PWM GENERATOR 2 Feed Forward  PCI REGISTER HIGH */
//    PG2FFPCIH    = 0x0000;
    /* PWM GENERATOR 2 Sync PCI REGISTER LOW */
    PG2SPCI     = 0x0000;
//    /* PWM GENERATOR 2 Sync PCI REGISTER LOW */
//    PG2SPCIH     = 0x0000;
    
    /* Initialize PWM GENERATOR 2 LEADING-EDGE BLANKING REGISTER LOW */
    PG2LEB      = 0x0000;
//    /* Initialize PWM GENERATOR 2 LEADING-EDGE BLANKING REGISTER HIGH*/
//    PG2LEBH      = 0x0000;
    
    /* Initialize PWM GENERATOR 2 PHASE REGISTER */
    PG2PHASE     = 0x0000;
    /* Initialize PWM GENERATOR 2 DUTY CYCLE REGISTER */
    PG2DC        = MIN_DUTY;
    /* Initialize PWM GENERATOR 2 DUTY CYCLE ADJUSTMENT REGISTER */
    PG2DCA       = 0x0000;
    /* Initialize PWM GENERATOR 2 PERIOD REGISTER */
    PG2PER       = 0x0000;
    /* Initialize PWM GENERATOR 2 DEAD-TIME REGISTER LOW */
    PG2DTbits.DTH       = DDEADTIME;
    /* Initialize PWM GENERATOR 2 DEAD-TIME REGISTER HIGH */
    PG2DTbits.DTL       = DDEADTIME;

    /* Initialize PWM GENERATOR 2 TRIGGER A REGISTER */
    PG2TRIGA     = 0x0000;
    /* Initialize PWM GENERATOR 2 TRIGGER B REGISTER */
    PG2TRIGB     = 0x0000;
    /* Initialize PWM GENERATOR 2 TRIGGER C REGISTER */
    PG2TRIGC     = 0x0000;
    
}
    
// *****************************************************************************
/* Function:
    InitPWMGenerator3()

  Summary:
    Routine to initialize PWM generators 3 

  Description:
    Function initializes PWM module for 3-phase inverter control in Complimentary
    mode ;initializes period,dead time;Configures PWM fault control logic

  Precondition:
    None.

  Parameters:
    None

  Returns:
    None.

  Remarks:
    None.
 */
void InitPWMGenerator3 (void)
{

    /* Initialize PWM GENERATOR 3 CONTROL REGISTER LOW */
    PG3CON      = 0x0000;
    /* PWM Generator 3 Enable bit : 1 = Is enabled, 0 = Is not enabled */
    /* PWM Generator is disabled prior to configuring module */
    PG3CONbits.ON = 0;
    /* Clock Selection bits
       0b01 = Macro uses Master clock selected by the PCLKCON.MCLKSEL bits*/
    PG3CONbits.CLKSEL = 1;
    /* PWM Mode Selection bits
     * 110 = Dual Edge Center-Aligned PWM mode (interrupt/register update once per cycle)
       100 = Center-Aligned PWM mode(interrupt/register update once per cycle)*/
#ifdef SINGLE_SHUNT
    PG3CONLbits.MODSEL = 6;
#else
    PG3CONbits.MODSEL = 4;
#endif    
    /* Trigger Count Select bits
       000 = PWM Generator produces 1 PWM cycle after triggered */
    PG3CONbits.TRGCNT = 0;
    
//    /* Initialize PWM GENERATOR 3 CONTROL REGISTER HIGH */
//    PG3CONH      = 0x0000;
    /* Master Duty Cycle Register Select bit
       1 = Macro uses the MDC register instead of PG3DC
       0 = Macro uses the PG3DC register*/
    PG3CONbits.MDCSEL = 0;
    /* Master Period Register Select bit
       1 = Macro uses the MPER register instead of PG3PER
       0 = Macro uses the PG3PER register */
    PG3CONbits.MPERSEL = 1;
    /* MPHSEL: Master Phase Register Select bit
       1 = Macro uses the MPHASE register instead of PG3PHASE
       0 = Macro uses the PG3PHASE register */
    PG3CONbits.MPHSEL = 0;
    /* Master Update Enable bit
       1 = PWM Generator broadcasts software set/clear of UPDATE status bit and 
           EOC signal to other PWM Generators
       0 = PWM Generator does not broadcast UPDATE status bit or EOC signal */
    PG3CONbits.MSTEN = 0;
    /* PWM Buffer Update Mode Selection bits 
       0b010 = Slaved SOC Update Data registers at start of next cycle if a 
       master update request is received. A master update request will be 
       transmitted if MSTEN = 1 and UPDATE = 1 for the requesting PWM
       Generator.. */
	PG3CONbits.UPDMOD = 0b010;
    /* PWM Generator Trigger Mode Selection bits
       0b00 = PWM Generator operates in Single Trigger mode */
    PG3CONbits.TRGMOD = 0;
    /* Start of Cycle Selection bits
       0001 = PWM1 trigger o/p selected by PG1 PGTRGSEL<2:0> bits(PGxEVT<2:0>)*/
    PG3CONbits.SOCS = 1;
    
    /* Clear PWM GENERATOR 3 STATUS REGISTER*/
    PG3STAT      = 0x0000;
    /* Initialize PWM GENERATOR 3 I/O CONTROL REGISTER LOW */
    PG3IOCON    = 0x0000;

    /* Current Limit Mode Select bit
       0 = If PCI current limit is active, then the CLDAT<1:0> bits define 
       the PWM output levels */
    PG3IOCONbits.CLMOD = 0;
    /* Swap PWM Signals to PWM3H and PWM3L Device Pins bit 
       0 = PWM3H/L signals are mapped to their respective pins */
    PG3IOCONbits.SWAP = 0;
    /* User Override Enable for PWM3H Pin bit
       0 = PWM Generator provides data for the PWM3H pin*/
    PG3IOCONbits.OVRENH = 0;
    /* User Override Enable for PWM3L Pin bit
       0 = PWM Generator provides data for the PWM3L pin*/
    PG3IOCONbits.OVRENL = 0;
    /* Data for PWM3H/PWM3L Pins if Override is Enabled bits
       If OVERENH = 1, then OVRDAT<1> provides data for PWM3H.
       If OVERENL = 1, then OVRDAT<0> provides data for PWM3L */
    PG3IOCONbits.OVRDAT = 0;
    /* User Output Override Synchronization Control bits
       00 = User output overrides via the OVRENL/H and OVRDAT<1:0> bits are 
       synchronized to the local PWM time base (next start of cycle)*/
    PG3IOCONbits.OSYNC = 0;
    /* Data for PWM3H/PWM3L Pins if FLT Event is Active bits
       If Fault is active, then FLTDAT<1> provides data for PWM3H.
       If Fault is active, then FLTDAT<0> provides data for PWM3L.*/
    PG3IOCONbits.FLTDAT = 0;
    /* Data for PWM3H/PWM3L Pins if CLMT Event is Active bits
       If current limit is active, then CLDAT<1> provides data for PWM3H.
       If current limit is active, then CLDAT<0> provides data for PWM3L.*/
    PG3IOCONbits.CLDAT = 0;
    /* Data for PWM3H/PWM3L Pins if Feed-Forward Event is Active bits
       If feed-forward is active, then FFDAT<1> provides data for PWM3H.
       If feed-forward is active, then FFDAT<0> provides data for PWM3L.*/
    PG3IOCONbits.FFDAT = 0;
    /* Data for PWM3H/PWM3L Pins if Debug Mode is Active and PTFRZ = 1 bits
       If Debug mode is active and PTFRZ=1,then DBDAT<1> provides PWM3H data.
       If Debug mode is active and PTFRZ=1,then DBDAT<0> provides PWM3L data. */
    PG3IOCONbits.DBDAT = 0;
    
//    /* Initialize PWM GENERATOR 3 I/O CONTROL REGISTER HIGH */    
//    PG3IOCONH    = 0x0000;
    /* Time Base Capture Source Selection bits
       000 = No hardware source selected for time base capture ? software only*/
    PG3IOCONbits.CAPSRC = 0;
    /* Dead-Time Compensation Select bit 
       0 = Dead-time compensation is controlled by PCI Sync logic */
    PG3IOCONbits.DTCMPSEL = 0;
    /* PWM Generator Output Mode Selection bits
       00 = PWM Generator outputs operate in Complementary mode*/
    PG3IOCONbits.PMOD = 0;
    /* PWM3H Output Port Enable bit
       1 = PWM Generator controls the PWM3H output pin
       0 = PWM Generator does not control the PWM3H output pin */
    PG3IOCONbits.PENH = 1;
    /* PWM3L Output Port Enable bit
       1 = PWM Generator controls the PWM3L output pin
       0 = PWM Generator does not control the PWM3L output pin */
    PG3IOCONbits.PENL = 1;
    /* PWM3H Output Polarity bit
       1 = Output pin is active-low
       0 = Output pin is active-high*/
    PG3IOCONbits.POLH = 0;
    /* PWM3L Output Polarity bit
       1 = Output pin is active-low
       0 = Output pin is active-high*/
    PG3IOCONbits.POLL = 0;
    
    /* Initialize PWM GENERATOR 3 EVENT REGISTER LOW*/
    PG3EVT      = 0x0000;
    /* ADC Trigger 1 Post-scaler Selection bits
       00000 = 1:1 */
    PG3EVTbits.ADTR1PS = 0;
    /* ADC Trigger 1 Source is PG3TRIGC Compare Event Enable bit
       0 = PG3TRIGC register compare event is disabled as trigger source for 
           ADC Trigger 1 */
    PG3EVTbits.ADTR1EN3  = 0;
    /* ADC Trigger 1 Source is PG3TRIGB Compare Event Enable bit
       0 = PG3TRIGB register compare event is disabled as trigger source for 
           ADC Trigger 1 */
    PG3EVTbits.ADTR1EN2 = 0;
    /* ADC Trigger 1 Source is PG3TRIGA Compare Event Enable bit
       0 = PG3TRIGA register compare event is disabled as trigger source for 
           ADC Trigger 1 */
    PG3EVTbits.ADTR1EN1 = 0;
    /* Update Trigger Select bits
       01 = A write of the PG3DC register automatically sets the UPDATE bit
       00 = User must set the UPDATE bit manually*/
    PG3EVTbits.UPDTRG = 0;
    /* PWM Generator Trigger Output Selection bits
       000 = EOC event is the PWM Generator trigger*/
    PG3EVTbits.PGTRGSEL = 0;
    
//    /* Initialize PWM GENERATOR 3 EVENT REGISTER HIGH */
//    PG3EVTH      = 0x0000;
    /* FLTIEN: PCI Fault Interrupt Enable bit
       0 = Fault interrupt is disabled */
    PG3EVTbits.FLTIEN = 0;
    /* PCI Current Limit Interrupt Enable bit
       0 = Current limit interrupt is disabled */
    PG3EVTbits.CLIEN = 0;
    /* PCI Feed-Forward Interrupt Enable bit
       0 = Feed-forward interrupt is disabled */
    PG3EVTbits.FFIEN = 0;
    /* PCI Sync Interrupt Enable bit
       0 = Sync interrupt is disabled */
    PG3EVTbits.SIEN = 0;
    /* Interrupt Event Selection bits
       00 = Interrupts CPU at EOC
       01 = Interrupts CPU at TRIGA compare event
       10 = Interrupts CPU at ADC Trigger 1 event
       11 = Time base interrupts are disabled */
    PG3EVTbits.IEVTSEL = 3;
    /* ADC Trigger 3 Source is PG3TRIGC Compare Event Enable bit
       0 = PG3TRIGC register compare event is disabled as 
           trigger source for ADC Trigger 2 */
    PG3EVTbits.ADTR2EN3 = 0;
    /* ADC Trigger 2 Source is PG3TRIGB Compare Event Enable bit
       0 = PG3TRIGB register compare event is disabled as 
           trigger source for ADC Trigger 2 */
    PG3EVTbits.ADTR2EN2 = 0;
    /* ADC Trigger 2 Source is PG3TRIGA Compare Event Enable bit
       0 = PG3TRIGA register compare event is disabled as 
           trigger source for ADC Trigger 2 */
    PG3EVTbits.ADTR2EN1 = 0;
    /* ADC Trigger 1 Offset Selection bits
       00000 = No offset */
    PG3EVTbits.ADTR1OFS = 0;
    
    /* PWM GENERATOR 3 Fault PCI REGISTER LOW */
#ifndef ENABLE_PWM_FAULT
    /* PWM GENERATOR 1 Fault PCI REGISTER LOW */
    PG3FPCI     = 0x0000;
//    /* PWM GENERATOR 1 Fault PCI REGISTER HIGH */
//    PG3FPCIH     = 0x0000;
#else
       /* PWM GENERATOR 1 Fault PCI REGISTER LOW */
    PG3FPCI     = 0x0000;
    /* Termination Synchronization Disable bit
       1 = Termination of latched PCI occurs immediately
       0 = Termination of latched PCI occurs at PWM EOC */
    PG3FPCIbits.TSYNCDIS = 0;
    /* Termination Event Selection bits
       001 = Auto-Terminate: Terminate when PCI source transitions from 
             active to inactive */
    PG3FPCIbits.TERM = 1;
    /* Acceptance Qualifier Polarity Select bit: 0 = Not inverted 1 = Inverted*/
    PG3FPCIbits.AQPS = 0;
    /* Acceptance Qualifier Source Selection bits
       111 = SWPCI control bit only (qualifier forced to 0)
       110 = Selects PCI Source #9
       101 = Selects PCI Source #8
       100 = Selects PCI Source #1 (PWM Generator output selected by the PWMPCI<2:0> bits)
       011 = PWM Generator is triggered
       010 = LEB is active
       001 = Duty cycle is active (base PWM Generator signal)        
       000 = No acceptance qualifier is used (qualifier forced to 1) */
    PG3FPCIbits.AQSS = 0;
    /* PCI Synchronization Control bit
       1 = PCI source is synchronized to PWM EOC
       0 = PCI source is not synchronized to PWM EOC*/
    PG3FPCIbits.PSYNC = 0;
    /* PCI Polarity Select bit 0 = Not inverted 1 = Inverted*/
    PG3FPCIbits.PPS = 1;
    /* PCI Source Selection bits
       11111 = PCI Source #31
       ? ?
       00001 = PCI Source #1
       00000 = Software PCI control bit (SWPCI) only*/
    PG3FPCIbits.PSS = 9;
    
//    /* PWM GENERATOR 1 Fault PCI REGISTER HIGH */
//    PG3FPCIH     = 0x0000;
    /* PCI Bypass Enable bit
       0 = PCI function is not bypassed */
    PG3FPCIbits.BPEN   = 0;
    /* PCI Bypass Source Selection bits(1)
       000 = PCI control is sourced from PG1 PCI logic when BPEN = 1 */
    PG3FPCIbits.BPSEL   = 0;
    /* PCI Acceptance Criteria Selection bits
       101 = Latched any edge(2)
       100 = Latched rising edge
       011 = Latched
       010 = Any edge
       001 = Rising edge
       000 = Level-sensitive*/
    PG3FPCIbits.ACP   = 3;
//    /* PCI SR Latch Mode bit
//       1 = SR latch is Reset-dominant in Latched Acceptance modes
//       0 = SR latch is Set-dominant in Latched Acceptance modes*/
//    PG3FPCIbits.PCIGT  = 0;
    /* Termination Qualifier Polarity Select bit 1 = Inverted 0 = Not inverted*/
    PG3FPCIbits.TQPS   = 0;
    /* Termination Qualifier Source Selection bits
       111 = SWPCI control bit only (qualifier forced to ?1?b0?)(3)
       110 = Selects PCI Source #9 (pwm_pci[9] input port)
       101 = Selects PCI Source #8 (pwm_pci[8] input port)
       100 = Selects PCI Source #1 (PWM Generator output selected by the PWMPCI<2:0> bits)
       011 = PWM Generator is triggered
       010 = LEB is active
       001 = Duty cycle is active (base PWM Generator signal)
       000 = No termination qualifier used (qualifier forced '1')*/
    PG3FPCIbits.TQSS  = 3;
#endif
    
    /* PWM GENERATOR 3 Current Limit PCI REGISTER LOW */
    PG3CLPCI    = 0x0000;
//    /* PWM GENERATOR 3 Current Limit PCI REGISTER HIGH */
//    PG3CLPCIH    = 0x0000;
    /* PWM GENERATOR 3 Feed Forward PCI REGISTER LOW */
    PG3FFPCI    = 0x0000;
//    /* PWM GENERATOR 3 Feed Forward  PCI REGISTER HIGH */
//    PG3FFPCIH    = 0x0000;
    /* PWM GENERATOR 3 Sync PCI REGISTER LOW */
    PG3SPCI     = 0x0000;
//    /* PWM GENERATOR 3 Sync PCI REGISTER LOW */
//    PG3SPCIH     = 0x0000;
    
    /* Initialize PWM GENERATOR 3 LEADING-EDGE BLANKING REGISTER LOW */
    PG3LEB      = 0x0000;
//    /* Initialize PWM GENERATOR 3 LEADING-EDGE BLANKING REGISTER HIGH*/
//    PG3LEBH      = 0x0000;
    
    /* Initialize PWM GENERATOR 3 PHASE REGISTER */
    PG3PHASE     = 0x0000;
    /* Initialize PWM GENERATOR 3 DUTY CYCLE REGISTER */
    PG3DC        = MIN_DUTY;
    /* Initialize PWM GENERATOR 3 DUTY CYCLE ADJUSTMENT REGISTER */
    PG3DCA       = 0x0000;
    /* Initialize PWM GENERATOR 3 PERIOD REGISTER */
    PG3PER       = 0x0000;
    /* Initialize PWM GENERATOR 3 DEAD-TIME REGISTER LOW */
    PG3DTbits.DTH       = DDEADTIME;
    /* Initialize PWM GENERATOR 3 DEAD-TIME REGISTER HIGH */
    PG3DTbits.DTL      = DDEADTIME;

    /* Initialize PWM GENERATOR 3 TRIGGER A REGISTER */
    PG3TRIGA     = 0x0000;
    /* Initialize PWM GENERATOR 3 TRIGGER B REGISTER */
    PG3TRIGB     = 0x0000;
    /* Initialize PWM GENERATOR 3 TRIGGER C REGISTER */
    PG3TRIGC     = 0x0000;
    
}
/**
 * Disable the PWM channels assigned for Inverter #A by overriding them to low state.
 * @example
 * <code>
 * DisablePWMOutputsInverterA();
 * </code>
 */
void DisablePWMOutputsInverterA(void)
{
    /** Set Override Data on all PWM outputs */
    // 0b00 = State for PWM3H,L, if Override is Enabled
    PG3IOCONbits.OVRDAT = 0;
    // 0b00 = State for PWM2H,L, if Override is Enabled
    PG2IOCONbits.OVRDAT = 0; 
    // 0b00 = State for PWM1H,L, if Override is Enabled
    PG1IOCONbits.OVRDAT = 0;  
    
    // 1 = OVRDAT<1> provides data for output on PWM3H
    PG3IOCONbits.OVRENH = 1; 
    // 1 = OVRDAT<0> provides data for output on PWM3L
    PG3IOCONbits.OVRENL = 1; 
    
    // 1 = OVRDAT<1> provides data for output on PWM2H
    PG2IOCONbits.OVRENH = 1;
    // 1 = OVRDAT<0> provides data for output on PWM2L
    PG2IOCONbits.OVRENL = 1; 
    
    // 1 = OVRDAT<1> provides data for output on PWM1H
    PG1IOCONbits.OVRENH = 1;  
    // 1 = OVRDAT<0> provides data for output on PWM1L
    PG1IOCONbits.OVRENL = 1;     
}

/**
 * Enable the PWM channels assigned for Inverter #A by removing Override.
 * @example
 * <code>
 * EnablePWMOutputsInverterA();
 * </code>
 */
void EnablePWMOutputsInverterA(void)
{    
    // 0 = PWM Generator provides data for the PWM3H pin
    PG3IOCONbits.OVRENH = 0; 
    // 0 = PWM Generator provides data for the PWM3L pin
    PG3IOCONbits.OVRENL = 0; 
    
    // 0 = PWM Generator provides data for the PWM2H pin
    PG2IOCONbits.OVRENH = 0;
    // 0 = PWM Generator provides data for the PWM2L pin
    PG2IOCONbits.OVRENL = 0; 
    
    // 0 = PWM Generator provides data for the PWM1H pin
    PG1IOCONbits.OVRENH = 0;  
    // 0 = PWM Generator provides data for the PWM1L pin
    PG1IOCONbits.OVRENL = 0;     
}

void PWMDutyCycleSet(uint32_t duty)
{ 
    INVERTERA_PWM_PDC3 = duty;
    INVERTERA_PWM_PDC2 = duty;
    INVERTERA_PWM_PDC1 = duty;
}
