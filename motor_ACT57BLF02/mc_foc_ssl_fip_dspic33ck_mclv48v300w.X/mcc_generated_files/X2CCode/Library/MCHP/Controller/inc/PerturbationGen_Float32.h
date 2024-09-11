/*
 * Copyright (c) {YEAR}, {ORGANIZATION_NAME}, {ORGANIZATION_WEB}
 * All rights reserved.
 */
/*
 * This file is licensed according to the BSD 3-clause license as follows:
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of the "{ORGANIZATION_NAME}" nor
 *     the names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL "{ORGANIZATION_NAME}" BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 * This file is part of X2C. http://x2c.lcm.at/
 * $LastChangedRevision: 2457 $
 * $LastChangedDate:: 2022-02-11 12:58:55 +0100#$
 */
/* USERCODE-BEGIN:Description                                                                                         */
/* Description: */
/* USERCODE-END:Description                                                                                           */
#ifndef PERTURBATIONGEN_FLOAT32_H
#define PERTURBATIONGEN_FLOAT32_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CommonFcts.h"

#if !defined(PERTURBATIONGEN_FLOAT32_ISLINKED)
#define PERTURBATIONGEN_FLOAT32_ID ((uint16)21026)

typedef struct {
    uint16          ID;
    float32         *f;
    float32         *dc;
    float32         *S_in;
    float32         u;
    float32         S_out;
    float32         delta_phi;
    float32         phi;
    float32         level_low;
    float32         level_high;
    float32         RateUp;
    float32         RateDown;
    float32         out_old;
    float32         out_ramp;
} PERTURBATIONGEN_FLOAT32;

#define PERTURBATIONGEN_FLOAT32_FUNCTIONS { \
    PERTURBATIONGEN_FLOAT32_ID, \
    (void (*)(void*))PerturbationGen_Float32_Update, \
    (void (*)(void*))PerturbationGen_Float32_Init, \
    (tLoadImplementationParameter)PerturbationGen_Float32_Load, \
    (tSaveImplementationParameter)PerturbationGen_Float32_Save, \
    (void* (*)(const void*, uint16))PerturbationGen_Float32_GetAddress }

/**********************************************************************************************************************/
/** Public prototypes                                                                                                **/
/**********************************************************************************************************************/
void PerturbationGen_Float32_Update(PERTURBATIONGEN_FLOAT32 *pTPerturbationGen_Float32);
void PerturbationGen_Float32_Init(PERTURBATIONGEN_FLOAT32 *pTPerturbationGen_Float32);
uint8 PerturbationGen_Float32_Load(const PERTURBATIONGEN_FLOAT32 *pTPerturbationGen_Float32, uint8 data[], uint16 *dataLength, uint16 maxSize);
uint8 PerturbationGen_Float32_Save(PERTURBATIONGEN_FLOAT32 *pTPerturbationGen_Float32, const uint8 data[], uint16 dataLength);
void* PerturbationGen_Float32_GetAddress(const PERTURBATIONGEN_FLOAT32 *block, uint16 elementId);

#endif

#ifdef __cplusplus
}
#endif

#endif