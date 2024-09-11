/*
 * Copyright (c) 2018, Linz Center of Mechatronics GmbH (LCM) http://www.lcm.at/
 * All rights reserved.
 */
/*
 * This file is part of X2C. http://x2c.lcm.at/
 * $LastChangedRevision: 2584 $
 * $LastChangedDate:: 2022-05-03 15:06:23 +0200#$
 */
/* USERCODE-BEGIN:Description                                                                                         */
/* Description: */
/* USERCODE-END:Description                                                                                           */
#ifndef LOWPASSBIQ_FIP32_H
#define LOWPASSBIQ_FIP32_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CommonFcts.h"

#if !defined(LOWPASSBIQ_FIP32_ISLINKED)
#define LOWPASSBIQ_FIP32_ID ((uint16)8130)

#if !defined(X2C_USE_UNION_FOR_POINTER)
typedef struct {
    uint16          ID;
    int32           *In;
    int32           Out;
    int32           b0;
    int32           b1;
    int32           b2;
    int32           a1;
    int32           a2;
    int8            sfrb0;
    int8            sfrb1;
    int8            sfrb2;
    int8            sfra1;
    int8            sfra2;
    int32           in_old;
    int32           in_veryold;
    int32           out_old;
    int32           out_veryold;
} LOWPASSBIQ_FIP32;
#else
typedef struct {
    uint16          ID;
    INT32_PTR       In;
    int32           Out;
    int32           b0;
    int32           b1;
    int32           b2;
    int32           a1;
    int32           a2;
    int8            sfrb0;
    int8            sfrb1;
    int8            sfrb2;
    int8            sfra1;
    int8            sfra2;
    int32           in_old;
    int32           in_veryold;
    int32           out_old;
    int32           out_veryold;
} LOWPASSBIQ_FIP32;
#endif

#define LOWPASSBIQ_FIP32_FUNCTIONS { \
    LOWPASSBIQ_FIP32_ID, \
    (void (*)(void*))LowpassBiQ_FiP32_Update, \
    (void (*)(void*))LowpassBiQ_FiP32_Init, \
    (tLoadImplementationParameter)LowpassBiQ_FiP32_Load, \
    (tSaveImplementationParameter)LowpassBiQ_FiP32_Save, \
    (void* (*)(const void*, uint16))LowpassBiQ_FiP32_GetAddress }

/**********************************************************************************************************************/
/** Public prototypes                                                                                                **/
/**********************************************************************************************************************/
void LowpassBiQ_FiP32_Update(LOWPASSBIQ_FIP32 *pTLowpassBiQ_FiP32);
void LowpassBiQ_FiP32_Init(LOWPASSBIQ_FIP32 *pTLowpassBiQ_FiP32);
uint8 LowpassBiQ_FiP32_Load(const LOWPASSBIQ_FIP32 *pTLowpassBiQ_FiP32, uint8 data[], uint16 *dataLength, uint16 maxSize);
uint8 LowpassBiQ_FiP32_Save(LOWPASSBIQ_FIP32 *pTLowpassBiQ_FiP32, const uint8 data[], uint16 dataLength);
void* LowpassBiQ_FiP32_GetAddress(const LOWPASSBIQ_FIP32 *block, uint16 elementId);

#endif

#ifdef __cplusplus
}
#endif

#endif
