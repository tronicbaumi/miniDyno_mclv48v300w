/*
 * Copyright (c) 2013, Linz Center of Mechatronics GmbH (LCM) http://www.lcm.at/
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
 */
/* USERCODE-BEGIN:Description                                                                                         */
/* Description: One dimensional look-up table with selectable number of entries */
/* USERCODE-END:Description                                                                                           */
#ifndef LOOKUPTABLE1D_FLOAT32_H
#define LOOKUPTABLE1D_FLOAT32_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CommonFcts.h"

#if !defined(LOOKUPTABLE1D_FLOAT32_ISLINKED)
#define LOOKUPTABLE1D_FLOAT32_ID ((uint16)499)

#if !defined(X2C_USE_UNION_FOR_POINTER)
typedef struct {
    uint16          ID;
    float32         *x;
    float32         Out;
const  float32      *Table;
    uint16          dimX;
    float32         gainX;
    float32         offsetX;
} LOOKUPTABLE1D_FLOAT32;
#else
typedef struct {
    uint16          ID;
    FLOAT32_PTR     x;
    float32         Out;
const  FLOAT32_PTR  Table;
    uint16          dimX;
    float32         gainX;
    float32         offsetX;
} LOOKUPTABLE1D_FLOAT32;
#endif

#define LOOKUPTABLE1D_FLOAT32_FUNCTIONS { \
    LOOKUPTABLE1D_FLOAT32_ID, \
    (void (*)(void*))LookupTable1D_Float32_Update, \
    (void (*)(void*))LookupTable1D_Float32_Init, \
    (tLoadImplementationParameter)LookupTable1D_Float32_Load, \
    (tSaveImplementationParameter)LookupTable1D_Float32_Save, \
    (void* (*)(const void*, uint16))LookupTable1D_Float32_GetAddress }

/**********************************************************************************************************************/
/** Public prototypes                                                                                                **/
/**********************************************************************************************************************/
void LookupTable1D_Float32_Update(LOOKUPTABLE1D_FLOAT32 *pTLookupTable1D_Float32);
void LookupTable1D_Float32_Init(LOOKUPTABLE1D_FLOAT32 *pTLookupTable1D_Float32);
uint8 LookupTable1D_Float32_Load(const LOOKUPTABLE1D_FLOAT32 *pTLookupTable1D_Float32, uint8 data[], uint16 *dataLength, uint16 maxSize);
uint8 LookupTable1D_Float32_Save(LOOKUPTABLE1D_FLOAT32 *pTLookupTable1D_Float32, const uint8 data[], uint16 dataLength);
void* LookupTable1D_Float32_GetAddress(const LOOKUPTABLE1D_FLOAT32 *block, uint16 elementId);

#endif

#ifdef __cplusplus
}
#endif

#endif
