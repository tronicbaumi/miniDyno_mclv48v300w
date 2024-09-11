/* This is an autogenerated file from a template. Do not edit this file as it will be overwritten.*/
/**
 *
 * zsmt_params.h
 *
 * Component: commutation
 */ /*
 *
 * Motor Control Application Framework
 * R7/RC37 (commit 116330, build on 2023 Feb 09)
 *
 * (c) 2017 - 2023 Microchip Technology Inc. and its subsidiaries. You may use
 * this software and any derivatives exclusively with Microchip products.
 *
 * This software and any accompanying information is for suggestion only.
 * It does not modify Microchip's standard warranty for its products.
 * You agree that you are solely responsible for testing the software and
 * determining its suitability.  Microchip has no obligation to modify,
 * test, certify, or support the software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE, OR ITS INTERACTION WITH
 * MICROCHIP PRODUCTS, COMBINATION WITH ANY OTHER PRODUCTS, OR USE IN ANY
 * APPLICATION.
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL,
 * PUNITIVE, INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF
 * ANY KIND WHATSOEVER RELATED TO THE USE OF THIS SOFTWARE, THE
 * motorBench(R) DEVELOPMENT SUITE TOOL, PARAMETERS AND GENERATED CODE,
 * HOWEVER CAUSED, BY END USERS, WHETHER MICROCHIP'S CUSTOMERS OR
 * CUSTOMER'S CUSTOMERS, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGES OR THE DAMAGES ARE FORESEEABLE. TO THE
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL
 * CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT
 * OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS
 * SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF
 * THESE TERMS.
 *
 *
 ******************************************************************************/
#ifndef __ZSMT_PARAMS_H
#define __ZSMT_PARAMS_H

#ifdef  __cplusplus
extern "C" {
#endif

/* 
 * Vexc:                           1.440  V
 * tau:                           10.000 ms
 * zeta:                           1.500  
 * executionDivider:               2.000  
 * elim:                         999.970 m
 * A:                            0.333330  
 * A1:                            19.819 mA
 * A2norm:                       511.984375  
 * A2:                            11.613  /A
 * A1A2:                         0.230158  
 * Ki:                            43.448 krad/s^2
 *                               414.901 kRPM/s
 * Kp:                             1.303 krad/s
 *                                12.447 kRPM
 * dt:                            50.000 us
 * timestep:                     100.000 us
 * omega_lpf:                     20.000 krad/s
 *                               190.986 kRPM
 * alignTime:                      1.000 ms
 * angleLockDelay:                50.000 ms
 * angleProbeCurrent:              5.250  A
 * angleProbeTime:                10.000 ms
 * angleProbeAccumGain:                1  
 * angleProbeSlewTime:           116.222 us
 * angleProbeSlewRate:            45.172 kA/s
 * angleProbeBlankingTime:       309.926 us
 * correctionGainDc:               0.000  rad/A
 * pllLockTime:                   10.000 ms
 * pllLockSpeedLimit:              3.142  rad/s
 *                                30.000  RPM
 * pllLockCurrentLimit:            2.100  A
 * pllLockCurrentSquaredLimit:     4.410  A^2
 */

/* Excitation voltage amplitude */
#define ZSMT_EXCITATION_VOLTAGE_AMPLITUDE        622      // Q15(  0.01898) =   +1.44073 V           =   +1.44000 V           + 0.0506%
/* Proportional gain of PLL = 2*zeta/B/tau */
#define ZSMT_PLL_KP                         13347      // Q12(  3.25854) =   +1.30342 krad/s      =   +1.30345 krad/s      - 0.0025%
#define ZSMT_PLL_KP_Q                          12
/* Integral gain of PLL = 1/B/tau^2 */
#define ZSMT_PLL_KI                           712      // Q16(  0.01086) =  +43.45703 krad/s^2    =  +43.44835 krad/s^2    + 0.0200%
/* PLL integrator time scaling factor */
#define ZSMT_PLL_DT                          1311      // Q16(  0.02000) =  +50.01068 us          =  +50.00000 us          + 0.0214%
/* Scaling gain for HFI error */
#define ZSMT_ERROR_GAIN                     32767      // Q6(511.98438)  = +511.98438             = +511.98438             + 0.0000%
/* Error limit for PLL */
#define ZSMT_ERROR_LIMIT                    32767      // Q15(  0.99997) = +999.96948 m           = +999.97000 m           - 0.0001%
#define ZSMT_PLL_EXECUTION_DIVIDER                   2 // ()         defines PLL execution rate based on main control update rate
/* Pole of input low-pass filter */
#define ZSMT_FILTER_GAIN                    65535      // Q16(  0.99998) =   +9.99985 krad/s      =  +20.00000 krad/s      -50.0008%
/* Align delay */
#define ZSMT_ALIGN_TIME                        20      // Q0( 20.00000)  =   +1.00000 ms          =   +1.00000 ms          + 0.0000%
/* Angle lock delay */
#define ZSMT_ANGLE_LOCK_DELAY                1000      // Q0(1000.00000) =  +50.00000 ms          =  +50.00000 ms          + 0.0000%
/* Angle probe duration */
#define ZSMT_ANGLE_PROBE_TIME                 200      // Q0(200.00000)  =  +10.00000 ms          =  +10.00000 ms          + 0.0000%
/* Angle probe accumulator gain */
#define ZSMT_ANGLE_PROBE_ACCUM_GAIN           328      // Q16(  0.00500) =   +1.00098             =   +1.00000             + 0.0977%
/* Angle probe blanking time */
#define ZSMT_ANGLE_PROBE_BLANKING_TIME          6      // Q0(  6.00000)  = +300.00000 us          = +309.92591 us          - 3.2027%
/* Angle probe slew rate */
#define ZSMT_ANGLE_PROBE_SLEW_RATE           1679      // Q15(  0.05124) =  +45.18051 kA/s        =  +45.17209 kA/s        + 0.0187%
/* DC correction gain */
#define ZSMT_CORRECTION_GAIN_DC                 0      // Q14(  0.00000) =   +0.00000 rad/A       =   +0.00000 rad/A       + 0.0000%
/* Required PLL lock time */
#define ZSMT_PLL_LOCK_TIME                    200      // Q0(200.00000)  =  +10.00000 ms          =  +10.00000 ms          + 0.0000%
/* Maximum allowed speed for ZSMT startup */
#define ZSMT_PLL_LOCK_SPEED_LIMIT             328      // Q15(  0.01001) =   +3.14466 rad/s       =   +3.14159 rad/s       + 0.0977%
/* Maximum allowed squared current for ZSMT startup */
#define ZSMT_PLL_LOCK_CURRENT_SQUARED_LIMIT         74      // Q15(  0.00226) =   +4.38958 A^2         =   +4.41000 A^2         - 0.4631%

/**
 * Returns whether ZS/MT estimator operates in a standalone manner.
 * (whether it uses its own sine/cosine calculations and Park transforms)
 *
 * @return whether ZS/MT estimator operates in a standalone manner
 */
inline static bool ZSMT_IsStandaloneEstimator(void)
{
    return true;
}

#ifdef  __cplusplus
}
#endif

#endif // __ZSMT_PARAMS_H
