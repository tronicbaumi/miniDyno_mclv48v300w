/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 
    
    typedef signed int SFRAC16;

    #define Q15(Float_Value)	\
        ((Float_Value < 0.0) ? (SFRAC16)(32768 * (Float_Value) - 0.5) \
        : (SFRAC16)(32767 * (Float_Value) + 0.5))

#define FOSC                120000000
#define PWM_FREQ            20000    // PWM Frequency in Hz

    /* encoder */    
#define DFCY                FOSC        // Instruction cycle frequency (Hz)

#define DTCY                (1.0/DFCY)          // Instruction cycle period (sec)
#define LOOPINTCY           (DFCY/PWM_FREQ)     // Basic loop period in units of Tcy
#define PWM_PERIODE         (LOOPINTCY/2)
    
#define NOPOLESPAIRS                        (5)      // Number of Pole Pairs of the PMSM Motor        
#define ENCODER_PULSES_PER_MECH_REV         (1000)   
#define ENCODER_PULSES_PER_ELEC_REV         (uint16_t)(ENCODER_PULSES_PER_MECH_REV/NOPOLESPAIRS)

#define QDEC_RC                             65536u
#define QDEC_UPPER_THRESHOLD                49151u   
#define QDEC_LOWER_THRESHOLD                16384u  
#define QDEC_OVERFLOW                       (uint16_t)(QDEC_RC % ENCODER_PULSES_PER_ELEC_REV) 
#define QDEC_UNDERFLOW                      (uint16_t)(ENCODER_PULSES_PER_ELEC_REV - QDEC_OVERFLOW)
#define FAST_LOOP_TIME_SEC                  (float)(1/(float)PWM_FREQ)          /* Always runs in sync with PWM */
#define SPEED_SAMPLE_FREQ                   100             /*In 1/seconds*/
#define SLOW_LOOP_TIME_SEC                  (float)(FAST_LOOP_TIME_SEC * SPEED_SAMPLE_FREQ)   /* SPEED_SAMPLE_FREQ times slower than Fast Loop */

 #define QEI_FACT_ELEC   65535u/(ENCODER_PULSES_PER_ELEC_REV)
 #define QEI_FACT_MECH   65535u/(ENCODER_PULSES_PER_MECH_REV)

#define MAX_SPEED       6000                    /*rpm*/
    

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

