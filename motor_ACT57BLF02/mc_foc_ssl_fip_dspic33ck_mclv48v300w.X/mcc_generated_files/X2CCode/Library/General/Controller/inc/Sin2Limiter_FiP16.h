/*
 * Copyright (c) 2018, Linz Center of Mechatronics GmbH (LCM) http://www.lcm.at/
 * All rights reserved.
 */
/*
 * This file is licensed according to the BSD 3-clause license as follows:
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the "Linz Center of Mechatronics GmbH" and "LCM" nor
 *       the names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL "Linz Center of Mechatronics GmbH" BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 * This file is part of X2C. http://x2c.lcm.at/
 * $LastChangedRevision: 2584 $
 * $LastChangedDate:: 2022-05-03 15:06:23 +0200#$
 */
/* USERCODE-BEGIN:Description                                                                                         */
/**     Description:	Continuously differentiable output change rate limitation with	sin^2 shape                  **/
/**						Calculation:                               													 **/
/**							du/dt = 0:																				 **/
/**								y = u																				 **/
/**							du/dt <> 0:																				 **/
/**								y = u * sin^2(t)		(simplified)												 **/
/**																													 **/
/**		Caution:	A step in the input signal during a	running limitation process will not abort the running        **/
/**					limitation process!																				 **/
/**																													 **/
/* USERCODE-END:Description                                                                                           */
#ifndef SIN2LIMITER_FIP16_H
#define SIN2LIMITER_FIP16_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CommonFcts.h"

#if !defined(SIN2LIMITER_FIP16_ISLINKED)
#define SIN2LIMITER_FIP16_ID ((uint16)113)

#if !defined(X2C_USE_UNION_FOR_POINTER)
typedef struct {
    uint16          ID;
    int16           *In;
    int16           *Init;
    bool            *Enable;
    int16           Out;
    int32           RateUp;
    int32           RateDown;
    int32           Scaled_RateUp;
    int32           Scaled_RateDown;
    int16           Out_end;
    uint32          Level;
    int32           Step_Height;
    int8            State;
    bool            Enable_old;
} SIN2LIMITER_FIP16;
#else
typedef struct {
    uint16          ID;
    INT16_PTR       In;
    INT16_PTR       Init;
    BOOL_PTR        Enable;
    int16           Out;
    int32           RateUp;
    int32           RateDown;
    int32           Scaled_RateUp;
    int32           Scaled_RateDown;
    int16           Out_end;
    uint32          Level;
    int32           Step_Height;
    int8            State;
    bool            Enable_old;
} SIN2LIMITER_FIP16;
#endif

#define SIN2LIMITER_FIP16_FUNCTIONS { \
    SIN2LIMITER_FIP16_ID, \
    (void (*)(void*))Sin2Limiter_FiP16_Update, \
    (void (*)(void*))Sin2Limiter_FiP16_Init, \
    (tLoadImplementationParameter)Sin2Limiter_FiP16_Load, \
    (tSaveImplementationParameter)Sin2Limiter_FiP16_Save, \
    (void* (*)(const void*, uint16))Sin2Limiter_FiP16_GetAddress }

/**********************************************************************************************************************/
/** Public prototypes                                                                                                **/
/**********************************************************************************************************************/
void Sin2Limiter_FiP16_Update(SIN2LIMITER_FIP16 *pTSin2Limiter_FiP16);
void Sin2Limiter_FiP16_Init(SIN2LIMITER_FIP16 *pTSin2Limiter_FiP16);
uint8 Sin2Limiter_FiP16_Load(const SIN2LIMITER_FIP16 *pTSin2Limiter_FiP16, uint8 data[], uint16 *dataLength, uint16 maxSize);
uint8 Sin2Limiter_FiP16_Save(SIN2LIMITER_FIP16 *pTSin2Limiter_FiP16, const uint8 data[], uint16 dataLength);
void* Sin2Limiter_FiP16_GetAddress(const SIN2LIMITER_FIP16 *block, uint16 elementId);

#endif

#ifdef __cplusplus
}
#endif

#endif
