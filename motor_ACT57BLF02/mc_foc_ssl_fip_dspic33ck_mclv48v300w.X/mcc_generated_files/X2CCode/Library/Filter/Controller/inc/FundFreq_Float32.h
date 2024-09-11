/*
 * ===== CONFIDENTIAL =====
 * The content of this file is confidential according to the X2C Licence Terms and Conditions.
 *  
 * Copyright (c) 2014, Linz Center of Mechatronics GmbH (LCM) http://www.lcm.at/
 * All rights reserved.
 */
/*
 * This file is part of X2C. http://x2c.lcm.at/
 * $LastChangedRevision: 2584 $
 * $LastChangedDate:: 2022-05-03 15:06:23 +0200#$
 */
/* USERCODE-BEGIN:Description                                                                                         */
/* Description: Calculation of fundamental wave.                              */
/* USERCODE-END:Description                                                                                           */
#ifndef FUNDFREQ_FLOAT32_H
#define FUNDFREQ_FLOAT32_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CommonFcts.h"

#if !defined(FUNDFREQ_FLOAT32_ISLINKED)
#define FUNDFREQ_FLOAT32_ID ((uint16)8019)

#if !defined(X2C_USE_UNION_FOR_POINTER)
typedef struct {
    uint16          ID;
    float32         *In;
    float32         *phi;
    float32         Out;
    uint32          cnt;
    float32         phi_old;
    float32         sum_a;
    float32         sum_b;
    float32         a;
    float32         b;
} FUNDFREQ_FLOAT32;
#else
typedef struct {
    uint16          ID;
    FLOAT32_PTR     In;
    FLOAT32_PTR     phi;
    float32         Out;
    uint32          cnt;
    float32         phi_old;
    float32         sum_a;
    float32         sum_b;
    float32         a;
    float32         b;
} FUNDFREQ_FLOAT32;
#endif

#define FUNDFREQ_FLOAT32_FUNCTIONS { \
    FUNDFREQ_FLOAT32_ID, \
    (void (*)(void*))FundFreq_Float32_Update, \
    (void (*)(void*))FundFreq_Float32_Init, \
    (tLoadImplementationParameter)Common_Load, \
    (tSaveImplementationParameter)Common_Save, \
    (void* (*)(const void*, uint16))FundFreq_Float32_GetAddress }

/**********************************************************************************************************************/
/** Public prototypes                                                                                                **/
/**********************************************************************************************************************/
void FundFreq_Float32_Update(FUNDFREQ_FLOAT32 *pTFundFreq_Float32);
void FundFreq_Float32_Init(FUNDFREQ_FLOAT32 *pTFundFreq_Float32);
void* FundFreq_Float32_GetAddress(const FUNDFREQ_FLOAT32 *block, uint16 elementId);

#endif

#ifdef __cplusplus
}
#endif

#endif