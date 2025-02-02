/*******************************************************************************
   Motor data

  Company:
    Microchip Technology Inc.

  File Name:
    mc_motor.h

  Summary:
  Motor data

  Description:
  Motor data

 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
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
// DOM-IGNORE-END

#ifndef MCMOTOR_H
#define MCMOTOR_H

/*******************************************************************************
 Header File inclusions
 *******************************************************************************/
#include "mc_types.h"

/*******************************************************************************
 Parameters
 *******************************************************************************/

/*******************************************************************************
 Default module parameters
 *******************************************************************************/

/*******************************************************************************
 Module data type
 *******************************************************************************/
typedef struct
{
    float32_t PolePairs;
    float32_t RsInOhms;
    float32_t LdInHenry;
    float32_t LqInHenry;
    float32_t KeInVpeakPerKrpm;
    float32_t IrmsMaxInAmps;
    float32_t JmInKgPerCmSquare;
    float32_t NmaxInRpm;
    float32_t NratedInRpm;
}tmcMot_PMSM_s;

/*******************************************************************************
 Interface variables
 *******************************************************************************/
extern tmcMot_PMSM_s mcMotI_PMSM_gds;

/*******************************************************************************
 Characteristic curves
 *******************************************************************************/
#define  LDMINUSLQ_VS_IS  { \
    { 0.0f,  0.00032f }, \
    { 1.0f,  0.00032f }, \
    { 2.0f,  0.00032f }, \
    { 3.0f,  0.00032f }, \
}

/*******************************************************************************
 Static Functions
 *******************************************************************************/
/*! \brief Set PMSM motor parameters
 *
 * Details.
 * Set PMSM motor parameters
 *
 * @param[in]: Configuration parameters
 * @param[in/out]: None
 * @param[out]: PMSM motor parameters structure
 *                           - RsInOhms:    Per phase resistance in Ohms
 *                           - LdInHenry: Direct axis inductance in Henry
 *                           - LqInHenry: Quadrature axis inductance in Henry
 *                           - PolePairs: Number of pole pairs
 *                           - KeInRmsVoltSecPerRad: Back EMF constant in RMS volts-sec / rad
 *                           - NratedInRadPerSec: Rated speed in rad/sec
 *                           - NmaxInRadPerSec: Maximum speed in rad/sec
 *                           - JmInKgPerCmSquare: Motor inertia in Kg/cm^2
 * @return: None
 */
static inline void mcMotI_ParametersSet(tmcMot_PMSM_s * const pParameters )
{
    pParameters->RsInOhms = (float32_t)(0.481);
    pParameters->LdInHenry = (float32_t)(0.000264);
    pParameters->LqInHenry = (float32_t)(0.00031);
    pParameters->PolePairs = (float32_t)(4);
    pParameters->KeInVpeakPerKrpm = (float32_t)(6.3);
    pParameters->IrmsMaxInAmps = (float32_t)(20);
    pParameters->NratedInRpm = (float32_t)(2000);
    pParameters->NmaxInRpm = (float32_t)(2000);
    pParameters->JmInKgPerCmSquare = 0.2f;
}

/*******************************************************************************
 Interface Functions
 *******************************************************************************/

/*! \brief Motor parameters initialization
 *
 * Details.
 * Motor parameters initialization
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcMotI_MotorParametersInit( tmcMot_PMSM_s * const pParameters );

#endif    /* MCMOTOR_H */
