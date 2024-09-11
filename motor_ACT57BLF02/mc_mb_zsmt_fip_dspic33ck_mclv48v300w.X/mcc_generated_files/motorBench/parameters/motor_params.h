/* This is an autogenerated file from a template. Do not edit this file as it will be overwritten.*/
/**
 *
 * motor_params.h
 *
 * Motor parameters
 *
 * Component: miscellaneous
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
#ifndef __MOTOR_PARAMS_H
#define __MOTOR_PARAMS_H

#ifdef  __cplusplus
extern "C" {
#endif

/* Stator resistance (line-to-neutral) */
#define MCAF_MOTOR_RS                        4574      // Q15(  0.13959) = +240.30765 mohm        = +240.31434 mohm        - 0.0028%
#define MCAF_MOTOR_RS_Q                        15

/* Maximum of Ld, Lq */
#define MCAF_MOTOR_LMAX_BASE_DT             14730      // Q13(  1.79810) = +154.77620 uH          = +154.77270 uH          + 0.0023%
#define MCAF_MOTOR_LMAX_BASE_DT_Q              13

/* Stator inductance (line-to-neutral) */
#define MCAF_MOTOR_LS_BASE_DT               13657      // Q13(  1.66711) = +143.50160 uH          = +143.50498 uH          - 0.0024%
#define MCAF_MOTOR_LS_BASE_DT_Q                13

/* Stator d-axis inductance (line-to-neutral) */
#define MCAF_MOTOR_LD_BASE_DT               12585      // Q13(  1.53625) = +132.23751 uH          = +132.23725 uH          + 0.0002%
#define MCAF_MOTOR_LD_BASE_DT_Q                13

/* Stator q-axis inductance (line-to-neutral) */
#define MCAF_MOTOR_LQ_BASE_DT               14730      // Q13(  1.79810) = +154.77620 uH          = +154.77270 uH          + 0.0023%
#define MCAF_MOTOR_LQ_BASE_DT_Q                13

/* Common-mode stator inductance (line-to-neutral) */
#define MCAF_MOTOR_L0_BASE_DT               13657      // Q13(  1.66711) = +143.50160 uH          = +143.50498 uH          - 0.0024%
#define MCAF_MOTOR_L0_BASE_DT_Q                13

/* Differential-mode stator inductance (line-to-neutral) */
#define MCAF_MOTOR_L1_BASE_DT               -1072      // Q13( -0.13086) =  -11.26409 uH          =  -11.26772 uH          - 0.0322%
#define MCAF_MOTOR_L1_BASE_DT_Q                13

/* Saliency ratio Lq/Ld */
#define MCAF_MOTOR_SALIENCY_RATIO            4794      // Q12(  1.17041) =   +1.17041             =   +1.17042             - 0.0006%

/* Relative saliency = (Lq-Ld)/(Lq+Ld) */
#define MCAF_MOTOR_RELATIVE_SALIENCY         2573      // Q15(  0.07852) =  +78.52173 m           =  +78.51799 m           + 0.0048%

/* Back-EMF constant of the motor */
#define MCAF_MOTOR_KE                         632      // Q12(  0.15430) =  +37.27769 mV/(rad/s)  =  +37.27435 mV/(rad/s)  + 0.0090%
#define MCAF_MOTOR_KE_Q                        12

/* Inverse of BEMF constant of the motor */
#define MCAF_MOTOR_KE_INVERSE               13274      // Q11(  6.48145) =  +26.82748 (rad/s)/V   =  +26.82810 (rad/s)/V   - 0.0023%
#define MCAF_MOTOR_KE_INVERSE_Q                11

/* Magnetic Flux of the motor */
#define MCAF_MOTOR_PSI_BASE_OMEGA_E          2528      // Q14(  0.15430) =   +9.31942 mV*s        =   +9.31859 mV*s        + 0.0090%
#define MCAF_MOTOR_PSI_BASE_OMEGA_E_Q          14

/* Magnetic Flux of the motor */
#define MCAF_MOTOR_PSI_BASE_DT              20115      // Q13(  2.45544) =   +9.31841 mV*s        =   +9.31859 mV*s        - 0.0019%
#define MCAF_MOTOR_PSI_BASE_DT_Q               13

/* Maximum of Ld, Lq */
#define MCAF_MOTOR_LMAX_BASE_OMEGA_E         3702      // Q15(  0.11298) = +154.77400 uH          = +154.77270 uH          + 0.0008%
#define MCAF_MOTOR_LMAX_BASE_OMEGA_E_Q         15

/* Stator inductance (line-to-neutral) */
#define MCAF_MOTOR_LS_BASE_OMEGA_E           3432      // Q15(  0.10474) = +143.48578 uH          = +143.50498 uH          - 0.0134%
#define MCAF_MOTOR_LS_BASE_OMEGA_E_Q           15

/* Stator d-axis inductance (line-to-neutral) */
#define MCAF_MOTOR_LD_BASE_OMEGA_E           3163      // Q15(  0.09653) = +132.23937 uH          = +132.23725 uH          + 0.0016%
#define MCAF_MOTOR_LD_BASE_OMEGA_E_Q           15

/* Stator q-axis inductance (line-to-neutral) */
#define MCAF_MOTOR_LQ_BASE_OMEGA_E           3702      // Q15(  0.11298) = +154.77400 uH          = +154.77270 uH          + 0.0008%
#define MCAF_MOTOR_LQ_BASE_OMEGA_E_Q           15

/* Common-mode stator inductance (line-to-neutral) */
#define MCAF_MOTOR_L0_BASE_OMEGA_E           3432      // Q15(  0.10474) = +143.48578 uH          = +143.50498 uH          - 0.0134%
#define MCAF_MOTOR_L0_BASE_OMEGA_E_Q           15

/* Differential-mode stator inductance (line-to-neutral) */
#define MCAF_MOTOR_L1_BASE_OMEGA_E           -270      // Q15( -0.00824) =  -11.28822 uH          =  -11.26772 uH          + 0.1819%
#define MCAF_MOTOR_L1_BASE_OMEGA_E_Q           15


/* 
 * motor under test:
 * id:                           act Motor  
 * poleCount:                          8  
 * polePairs:                          4  
 * R:                            240.314 mohms line-neutral
 *                               480.629 mohms line-line
 * L:                            143.505 uH line-neutral
 *                               287.010 uH line-line
 * Ld:                           132.237 uH line-neutral
 *                               264.475 uH line-line
 * Lq:                           154.773 uH line-neutral
 *                               309.545 uH line-line
 * Ke:                            37.274 mV/(rad/s) line-neutral 0-pk
 *                                64.561 mV/(rad/s) line-line 0-pk
 *                                 4.781  Vrms/KRPM line-line
 * B:                             39.961 uNm/(rad/s)
 * Tf:                            14.324 mNm
 * J:                             28.429 uNm/(rad/s^2)
 * Maximum velocity:             209.440  rad/s
 *                                 2.000 kRPM
 * Nominal (base) velocity:      209.440  rad/s
 *                                 2.000 kRPM
 * Nominal electrical frequency: 837.758  rad/s
 *                                 8.000 kRPM
 * Rated current:                  7.000  A
 * V1:                             7.807  V line-neutral
 * V1ll:                          13.522  V line-line
 * T1:                           391.381 mNm
 * P1:                            81.971  W
 *
 * Motor constant:                93.125 mNm/sqrt(W)
 * Electrical time constant:     597.155 us
 * Mechanical time constant:     711.399 ms
 * tau_m1:                         3.278 ms
 * Mechanical time constant including effect of stator resistance:  3.263 ms
 * Rotor flux:                     9.319 mVs
 * Saliency ratio:                 1.170  
 * tau_e_bar:                    0.500272  
 * tau_m_bar:                    0.686565  
 * alpha_J:                      5.489536  
 * alpha_B:                      0.004608  
 * alpha_psi:                    0.107799  
 * alpha_Tf:                     0.036598  
 * alpha_R:                      0.215481  
 */

#define MOTOR_PARAM_R                  2.403143394E-01   // stator resistance (ohms line-neutral)
#define MOTOR_PARAM_L                  1.435049762E-04   // stator inductance (H line-neutral)
#define MOTOR_PARAM_KE                 3.727435243E-02   // back-EMF constant (V/(rad/s) line-neutral 0-pk)
#define MOTOR_PARAM_J                  2.842855142E-05   // inertia (Nm/(rad/s^2))
#define MOTOR_PARAM_B                  3.996146207E-05   // viscous damping (Nm/(rad/s))
#define MOTOR_PARAM_TFR                1.432383501E-02   // Coulomb friction (Nm)
#define MOTOR_PARAM_POLE_COUNT                       8   // number of poles 
#define MOTOR_PARAM_POLE_PAIRS                       4   // number of pole pairs 

#ifdef  __cplusplus
}
#endif

#endif // __MOTOR_PARAMS_H
