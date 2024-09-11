/**
 * @file
 * @brief Generated model file.
 * 
 * Date:  2024-09-11 10:58
 * 
 * X2C-Version: 6.4.3073
 * X2C-Edition: Free
 */
/* This file is part of X2C. http://x2c.lcm.at/                                                                       */

/* Model: MC_FOC_DYNO_SAME54_MCLV_48V_300W                                                                            */
/* Date:  2024-09-11 10:58                                                                                            */

/* X2C-Version: 6.4.3073                                                                                              */
/* X2C-Edition: Free                                                                                                  */

#ifndef X2C_H
#define X2C_H

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************************************************************************/
/**     Includes                                                                                                     **/
/**********************************************************************************************************************/
/* Common includes                                                                                                    */
#include "Constant_Bool.h"
#include "Gain_FiP16.h"
#include "TypeConv_Bool_FiP16.h"
#include "Gain_Float32.h"
#include "RateLimiter_FiP16.h"
#include "Int2Real_FiP16_Float32.h"
#include "Real2Int_Float32_FiP8.h"
#include "Negation_FiP16.h"
#include "ManualSwitch_FiP16.h"
#include "Sum_Float32.h"
#include "Constant_FiP16.h"
#include "Not_Bool.h"
#include "PI_FiP16.h"
#include "ManualSwitch_Bool.h"
#include "Saturation_FiP16.h"
#include "LookupTable_FiP16.h"
#include "PILimit_FiP16.h"
#include "AutoSwitch_FiP16.h"
#include "Sequencer_FiP16.h"
#include "SinGen_FiP16.h"
#include "Mult_Float32.h"
#include "Sub_FiP16.h"
#include "Clarke_Park_MCHP_FiP16.h"
#include "Constant_Float32.h"
#include "Average_FiP16.h"
#include "Abs_FiP16.h"
#include "TypeConv_FiP16_Bool.h"
#include "Selector_FiP16.h"
#include "Park_Clarke_inv_SVM_MCHP_FiP16.h"
#include "Add_FiP16.h"
#include "Sign_FiP16.h"
#include "SaveSignal_Float32.h"
#include "uAdd_FiP16.h"
#include "Mult_FiP16.h"
#include "Scope_Main.h"
#include "CommonFcts.h"

/**********************************************************************************************************************/
/**     Defines                                                                                                      **/
/**********************************************************************************************************************/
#define FUNCTIONS \
    CONSTANT_BOOL_FUNCTIONS , \
    GAIN_FIP16_FUNCTIONS , \
    TYPECONV_BOOL_FIP16_FUNCTIONS , \
    GAIN_FLOAT32_FUNCTIONS , \
    RATELIMITER_FIP16_FUNCTIONS , \
    INT2REAL_FIP16_FLOAT32_FUNCTIONS , \
    REAL2INT_FLOAT32_FIP8_FUNCTIONS , \
    NEGATION_FIP16_FUNCTIONS , \
    MANUALSWITCH_FIP16_FUNCTIONS , \
    SUM_FLOAT32_FUNCTIONS , \
    CONSTANT_FIP16_FUNCTIONS , \
    NOT_BOOL_FUNCTIONS , \
    PI_FIP16_FUNCTIONS , \
    MANUALSWITCH_BOOL_FUNCTIONS , \
    SATURATION_FIP16_FUNCTIONS , \
    LOOKUPTABLE_FIP16_FUNCTIONS , \
    PILIMIT_FIP16_FUNCTIONS , \
    AUTOSWITCH_FIP16_FUNCTIONS , \
    SEQUENCER_FIP16_FUNCTIONS , \
    SINGEN_FIP16_FUNCTIONS , \
    MULT_FLOAT32_FUNCTIONS , \
    SUB_FIP16_FUNCTIONS , \
    CLARKE_PARK_MCHP_FIP16_FUNCTIONS , \
    CONSTANT_FLOAT32_FUNCTIONS , \
    AVERAGE_FIP16_FUNCTIONS , \
    ABS_FIP16_FUNCTIONS , \
    TYPECONV_FIP16_BOOL_FUNCTIONS , \
    SELECTOR_FIP16_FUNCTIONS , \
    PARK_CLARKE_INV_SVM_MCHP_FIP16_FUNCTIONS , \
    ADD_FIP16_FUNCTIONS , \
    SIGN_FIP16_FUNCTIONS , \
    SAVESIGNAL_FLOAT32_FUNCTIONS , \
    UADD_FIP16_FUNCTIONS , \
    MULT_FIP16_FUNCTIONS , \
    SCOPE_MAIN_FUNCTIONS

#define PARAMETER_TABLE \
    { 1U, &x2cModel.blocks.bAverage } , \
    { 2U, &x2cModel.blocks.sDyno.bAdd } , \
    { 3U, &x2cModel.blocks.sDyno.bAdd1 } , \
    { 4U, &x2cModel.blocks.sDyno.bAdd2 } , \
    { 5U, &x2cModel.blocks.sDyno.bAutoSwitch } , \
    { 6U, &x2cModel.blocks.sDyno.bConstT5 } , \
    { 7U, &x2cModel.blocks.sDyno.bConstT6 } , \
    { 8U, &x2cModel.blocks.sDyno.bConstT7 } , \
    { 9U, &x2cModel.blocks.sDyno.bConstant } , \
    { 10U, &x2cModel.blocks.sDyno.bConstant4 } , \
    { 11U, &x2cModel.blocks.sDyno.bConstant6 } , \
    { 12U, &x2cModel.blocks.sDyno.bGainT5 } , \
    { 13U, &x2cModel.blocks.sDyno.bGainT6 } , \
    { 14U, &x2cModel.blocks.sDyno.bGainT7 } , \
    { 15U, &x2cModel.blocks.sDyno.bLookupTable } , \
    { 16U, &x2cModel.blocks.sDyno.bLookupTable1 } , \
    { 17U, &x2cModel.blocks.sDyno.bLookupTable2 } , \
    { 18U, &x2cModel.blocks.sDyno.bMult } , \
    { 19U, &x2cModel.blocks.sDyno.bReal2Int } , \
    { 20U, &x2cModel.blocks.sDyno.bSelector } , \
    { 21U, &x2cModel.blocks.sDyno.bSinGen1 } , \
    { 22U, &x2cModel.blocks.sDyno.bSin_load } , \
    { 23U, &x2cModel.blocks.sDyno.bconst_torque } , \
    { 24U, &x2cModel.blocks.sDyno.bfan_gain } , \
    { 25U, &x2cModel.blocks.sDyno.bsine_A } , \
    { 26U, &x2cModel.blocks.sDyno.bsine_F } , \
    { 27U, &x2cModel.blocks.sDyno.bswitch_mech_el } , \
    { 28U, &x2cModel.blocks.sDyno.bt_load_f } , \
    { 29U, &x2cModel.blocks.sDyno.bt_load_high } , \
    { 30U, &x2cModel.blocks.sDyno.bt_load_low } , \
    { 31U, &x2cModel.blocks.sDyno.bt_load_rate } , \
    { 32U, &x2cModel.blocks.sDyno.btorque_mode } , \
    { 33U, &x2cModel.blocks.bDynoMotor } , \
    { 34U, &x2cModel.blocks.sFOCmain.bAdd } , \
    { 35U, &x2cModel.blocks.sFOCmain.bClarke_Park_MCHP } , \
    { 36U, &x2cModel.blocks.sFOCmain.bGain } , \
    { 37U, &x2cModel.blocks.sFOCmain.bGain1 } , \
    { 38U, &x2cModel.blocks.sFOCmain.bGain2 } , \
    { 39U, &x2cModel.blocks.sFOCmain.bGain3 } , \
    { 40U, &x2cModel.blocks.sFOCmain.bGain4 } , \
    { 41U, &x2cModel.blocks.sFOCmain.bGain5 } , \
    { 42U, &x2cModel.blocks.sFOCmain.bGain6 } , \
    { 43U, &x2cModel.blocks.sFOCmain.bInt2Real } , \
    { 44U, &x2cModel.blocks.sFOCmain.bInt2Real1 } , \
    { 45U, &x2cModel.blocks.sFOCmain.bInt2Real2 } , \
    { 46U, &x2cModel.blocks.sFOCmain.bInt2Real3 } , \
    { 47U, &x2cModel.blocks.sFOCmain.bInt2Real4 } , \
    { 48U, &x2cModel.blocks.sFOCmain.bInt2Real5 } , \
    { 49U, &x2cModel.blocks.sFOCmain.bManualSwitch } , \
    { 50U, &x2cModel.blocks.sFOCmain.bManualSwitch1 } , \
    { 51U, &x2cModel.blocks.sFOCmain.bMult } , \
    { 52U, &x2cModel.blocks.sFOCmain.bMult1 } , \
    { 53U, &x2cModel.blocks.sFOCmain.bMult2 } , \
    { 54U, &x2cModel.blocks.sFOCmain.bNot } , \
    { 55U, &x2cModel.blocks.sFOCmain.bOpenLoop_Vd } , \
    { 56U, &x2cModel.blocks.sFOCmain.bOpenLoop_Vq } , \
    { 57U, &x2cModel.blocks.sFOCmain.bPI_flux } , \
    { 58U, &x2cModel.blocks.sFOCmain.bPI_torque } , \
    { 59U, &x2cModel.blocks.sFOCmain.bPark_Clarke_inv_SVM_MCHP } , \
    { 60U, &x2cModel.blocks.sFOCmain.bSaturation } , \
    { 61U, &x2cModel.blocks.sFOCmain.bSaturation1 } , \
    { 62U, &x2cModel.blocks.sFOCmain.bSub_flux } , \
    { 63U, &x2cModel.blocks.sFOCmain.bSub_torque } , \
    { 64U, &x2cModel.blocks.sFOCmain.bSum } , \
    { 65U, &x2cModel.blocks.sFOCmain.bTypeConv2 } , \
    { 66U, &x2cModel.blocks.sFOCmain.bbreakPowerW } , \
    { 67U, &x2cModel.blocks.sFOCmain.bforced_current } , \
    { 68U, &x2cModel.blocks.sFOCmain.bforced_current1 } , \
    { 69U, &x2cModel.blocks.sFOCmain.btheta_offset } , \
    { 70U, &x2cModel.blocks.sFOCmain.buAdd } , \
    { 71U, &x2cModel.blocks.bFlux_SP1 } , \
    { 72U, &x2cModel.blocks.sMotor.bAutoSwitch } , \
    { 73U, &x2cModel.blocks.sMotor.bConstant } , \
    { 74U, &x2cModel.blocks.sMotor.bConstant1 } , \
    { 75U, &x2cModel.blocks.sMotor.bConstant3 } , \
    { 76U, &x2cModel.blocks.sMotor.bConstant4 } , \
    { 77U, &x2cModel.blocks.sMotor.bConstant6 } , \
    { 78U, &x2cModel.blocks.sMotor.bGain } , \
    { 79U, &x2cModel.blocks.sMotor.bGain1 } , \
    { 80U, &x2cModel.blocks.sMotor.bGain3 } , \
    { 81U, &x2cModel.blocks.sMotor.bInt2Real } , \
    { 82U, &x2cModel.blocks.sMotor.bMAX_SPEED } , \
    { 83U, &x2cModel.blocks.sMotor.bManualSwitch } , \
    { 84U, &x2cModel.blocks.sMotor.bPILimit } , \
    { 85U, &x2cModel.blocks.sMotor.bReal2Int } , \
    { 86U, &x2cModel.blocks.sMotor.bSelector } , \
    { 87U, &x2cModel.blocks.sMotor.bSinGen1 } , \
    { 88U, &x2cModel.blocks.sMotor.bSubSpeed } , \
    { 89U, &x2cModel.blocks.sMotor.sSuperBlock.bConstant2 } , \
    { 90U, &x2cModel.blocks.sMotor.sSuperBlock.bGain2 } , \
    { 91U, &x2cModel.blocks.sMotor.sSuperBlock.bSub } , \
    { 92U, &x2cModel.blocks.sMotor.bTypeConv } , \
    { 93U, &x2cModel.blocks.sMotor.bconst_speed } , \
    { 94U, &x2cModel.blocks.sMotor.bconst_speed1 } , \
    { 95U, &x2cModel.blocks.sMotor.bconst_torque_motor } , \
    { 96U, &x2cModel.blocks.sMotor.bmotor_torquemode } , \
    { 97U, &x2cModel.blocks.sMotor.bomega_rpm } , \
    { 98U, &x2cModel.blocks.sMotor.bspeedPI_limit } , \
    { 99U, &x2cModel.blocks.sMotor.bspeed_mode } , \
    { 100U, &x2cModel.blocks.sMotor.bt_load_rate } , \
    { 101U, &x2cModel.blocks.sMotor.bt_speed_f } , \
    { 102U, &x2cModel.blocks.sMotor.bt_speed_high } , \
    { 103U, &x2cModel.blocks.sMotor.bt_speed_low } , \
    { 104U, &x2cModel.blocks.sQEI_init.bGain1 } , \
    { 105U, &x2cModel.blocks.sQEI_init.bNot } , \
    { 106U, &x2cModel.blocks.sQEI_init.bTypeConv } , \
    { 107U, &x2cModel.blocks.sQEI_init.bTypeConv1 } , \
    { 108U, &x2cModel.blocks.bSequencer } , \
    { 109U, &x2cModel.blocks.sdyno_quadrant.bAbs } , \
    { 110U, &x2cModel.blocks.sdyno_quadrant.bAutoSwitch } , \
    { 111U, &x2cModel.blocks.sdyno_quadrant.bConstant1 } , \
    { 112U, &x2cModel.blocks.sdyno_quadrant.bConstant2 } , \
    { 113U, &x2cModel.blocks.sdyno_quadrant.bManualSwitch3 } , \
    { 114U, &x2cModel.blocks.sdyno_quadrant.bMult1 } , \
    { 115U, &x2cModel.blocks.sdyno_quadrant.bMult2 } , \
    { 116U, &x2cModel.blocks.sdyno_quadrant.bNegation } , \
    { 117U, &x2cModel.blocks.sdyno_quadrant.bRateLimiter } , \
    { 118U, &x2cModel.blocks.sdyno_quadrant.bSaturation } , \
    { 119U, &x2cModel.blocks.sdyno_quadrant.bSign1 } , \
    { 120U, &x2cModel.blocks.sdyno_quadrant.bSpeedAverage } , \
    { 121U, &x2cModel.blocks.sdyno_quadrant.bTorque_SP } , \
    { 141U, &x2cScope }

#define INPORT_PARAMID_TABLE \
    { 122U, 2U, &x2cModel.inports.bCPU_LOAD } , \
    { 123U, 2U, &x2cModel.inports.bI_a } , \
    { 124U, 2U, &x2cModel.inports.bI_b } , \
    { 125U, 2U, &x2cModel.inports.bI_sum } , \
    { 126U, 2U, &x2cModel.inports.bQEI_POS } , \
    { 127U, 2U, &x2cModel.inports.bQEI_POS_MECH } , \
    { 128U, 2U, &x2cModel.inports.bQEI_VEL } , \
    { 129U, 2U, &x2cModel.inports.bS2 } , \
    { 130U, 2U, &x2cModel.inports.bS3 } , \
    { 131U, 2U, &x2cModel.inports.bV_DCLINK } , \
    { 132U, 2U, &x2cModel.inports.bV_POT } 

#define OUTPORT_PARAMID_TABLE \
    { 133U, 2U, &x2cModel.outports.bHOME_INIT } , \
    { 134U, 2U, &x2cModel.outports.bIq } , \
    { 135U, 2U, &x2cModel.outports.bLED_D17 } , \
    { 136U, 2U, &x2cModel.outports.bLED_D2 } , \
    { 137U, 2U, &x2cModel.outports.bPWM1 } , \
    { 138U, 2U, &x2cModel.outports.bPWM2 } , \
    { 139U, 2U, &x2cModel.outports.bPWM3 } , \
    { 140U, 2U, &x2cModel.outports.sdyno_quadrant.bSPEED_ABS } 


/**********************************************************************************************************************/
/**                                            Model structure definition                                            **/
/**********************************************************************************************************************/
struct x2cModel {
/*  Control Blocks                                                                                                    */
    struct {
/*      Sub-system Dyno                                                                                               */
        struct {
            ADD_FIP16 bAdd;
            ADD_FIP16 bAdd1;
            ADD_FIP16 bAdd2;
            AUTOSWITCH_FIP16 bAutoSwitch;
            CONSTANT_FIP16 bConstT5;
            CONSTANT_FIP16 bConstT6;
            CONSTANT_FIP16 bConstT7;
            CONSTANT_FIP16 bConstant;
            CONSTANT_FIP16 bConstant4;
            CONSTANT_BOOL bConstant6;
            GAIN_FIP16 bGainT5;
            GAIN_FIP16 bGainT6;
            GAIN_FIP16 bGainT7;
            LOOKUPTABLE_FIP16 bLookupTable;
            LOOKUPTABLE_FIP16 bLookupTable1;
            LOOKUPTABLE_FIP16 bLookupTable2;
            MULT_FIP16 bMult;
            REAL2INT_FLOAT32_FIP8 bReal2Int;
            SELECTOR_FIP16 bSelector;
            SINGEN_FIP16 bSinGen1;
            SINGEN_FIP16 bSin_load;
            CONSTANT_FIP16 bconst_torque;
            GAIN_FIP16 bfan_gain;
            CONSTANT_FIP16 bsine_A;
            CONSTANT_FIP16 bsine_F;
            MANUALSWITCH_FIP16 bswitch_mech_el;
            CONSTANT_FIP16 bt_load_f;
            CONSTANT_FIP16 bt_load_high;
            CONSTANT_FIP16 bt_load_low;
            RATELIMITER_FIP16 bt_load_rate;
            CONSTANT_FLOAT32 btorque_mode;
        } sDyno;
/*      Sub-system FOCmain                                                                                            */
        struct {
            ADD_FIP16 bAdd;
            CLARKE_PARK_MCHP_FIP16 bClarke_Park_MCHP;
            GAIN_FLOAT32 bGain;
            GAIN_FIP16 bGain1;
            GAIN_FLOAT32 bGain2;
            GAIN_FLOAT32 bGain3;
            GAIN_FLOAT32 bGain4;
            GAIN_FLOAT32 bGain5;
            GAIN_FLOAT32 bGain6;
            INT2REAL_FIP16_FLOAT32 bInt2Real;
            INT2REAL_FIP16_FLOAT32 bInt2Real1;
            INT2REAL_FIP16_FLOAT32 bInt2Real2;
            INT2REAL_FIP16_FLOAT32 bInt2Real3;
            INT2REAL_FIP16_FLOAT32 bInt2Real4;
            INT2REAL_FIP16_FLOAT32 bInt2Real5;
            MANUALSWITCH_FIP16 bManualSwitch;
            MANUALSWITCH_FIP16 bManualSwitch1;
            MULT_FLOAT32 bMult;
            MULT_FLOAT32 bMult1;
            MULT_FLOAT32 bMult2;
            NOT_BOOL bNot;
            CONSTANT_FIP16 bOpenLoop_Vd;
            CONSTANT_FIP16 bOpenLoop_Vq;
            PI_FIP16 bPI_flux;
            PI_FIP16 bPI_torque;
            PARK_CLARKE_INV_SVM_MCHP_FIP16 bPark_Clarke_inv_SVM_MCHP;
            SATURATION_FIP16 bSaturation;
            SATURATION_FIP16 bSaturation1;
            SUB_FIP16 bSub_flux;
            SUB_FIP16 bSub_torque;
            SUM_FLOAT32 bSum;
            TYPECONV_FIP16_BOOL bTypeConv2;
            SAVESIGNAL_FLOAT32 bbreakPowerW;
            CONSTANT_FIP16 bforced_current;
            CONSTANT_FLOAT32 bforced_current1;
            CONSTANT_FIP16 btheta_offset;
            UADD_FIP16 buAdd;
        } sFOCmain;
/*      Sub-system Motor                                                                                              */
        struct {
/*          Sub-system SuperBlock                                                                                     */
            struct {
                CONSTANT_FIP16 bConstant2;
                GAIN_FIP16 bGain2;
                SUB_FIP16 bSub;
            } sSuperBlock;
            AUTOSWITCH_FIP16 bAutoSwitch;
            CONSTANT_BOOL bConstant;
            CONSTANT_FIP16 bConstant1;
            CONSTANT_FIP16 bConstant3;
            CONSTANT_FIP16 bConstant4;
            CONSTANT_BOOL bConstant6;
            GAIN_FIP16 bGain;
            GAIN_FIP16 bGain1;
            GAIN_FIP16 bGain3;
            INT2REAL_FIP16_FLOAT32 bInt2Real;
            GAIN_FLOAT32 bMAX_SPEED;
            MANUALSWITCH_BOOL bManualSwitch;
            PILIMIT_FIP16 bPILimit;
            REAL2INT_FLOAT32_FIP8 bReal2Int;
            SELECTOR_FIP16 bSelector;
            SINGEN_FIP16 bSinGen1;
            SUB_FIP16 bSubSpeed;
            TYPECONV_FIP16_BOOL bTypeConv;
            CONSTANT_FIP16 bconst_speed;
            CONSTANT_FIP16 bconst_speed1;
            CONSTANT_FIP16 bconst_torque_motor;
            MANUALSWITCH_FIP16 bmotor_torquemode;
            SAVESIGNAL_FLOAT32 bomega_rpm;
            CONSTANT_FIP16 bspeedPI_limit;
            CONSTANT_FLOAT32 bspeed_mode;
            RATELIMITER_FIP16 bt_load_rate;
            CONSTANT_FIP16 bt_speed_f;
            CONSTANT_FIP16 bt_speed_high;
            CONSTANT_FIP16 bt_speed_low;
        } sMotor;
/*      Sub-system QEI_init                                                                                           */
        struct {
            GAIN_FIP16 bGain1;
            NOT_BOOL bNot;
            TYPECONV_FIP16_BOOL bTypeConv;
            TYPECONV_BOOL_FIP16 bTypeConv1;
        } sQEI_init;
/*      Sub-system dyno_quadrant                                                                                      */
        struct {
            ABS_FIP16 bAbs;
            AUTOSWITCH_FIP16 bAutoSwitch;
            CONSTANT_BOOL bConstant1;
            CONSTANT_FIP16 bConstant2;
            MANUALSWITCH_FIP16 bManualSwitch3;
            MULT_FIP16 bMult1;
            MULT_FIP16 bMult2;
            NEGATION_FIP16 bNegation;
            RATELIMITER_FIP16 bRateLimiter;
            SATURATION_FIP16 bSaturation;
            SIGN_FIP16 bSign1;
            AVERAGE_FIP16 bSpeedAverage;
            CONSTANT_FIP16 bTorque_SP;
        } sdyno_quadrant;
        AVERAGE_FIP16 bAverage;
        MANUALSWITCH_FIP16 bDynoMotor;
        CONSTANT_FIP16 bFlux_SP1;
        SEQUENCER_FIP16 bSequencer;
    } blocks;
/*  Inports                                                                                                           */
    struct {
        int16 bCPU_LOAD;
        int16 bI_a;
        int16 bI_b;
        int16 bI_sum;
        int16 bQEI_POS;
        int16 bQEI_POS_MECH;
        int16 bQEI_VEL;
        int16 bS2;
        int16 bS3;
        int16 bV_DCLINK;
        int16 bV_POT;
    } inports;
/*  Outports                                                                                                          */
    struct {
/*      Sub-system dyno_quadrant                                                                                      */
        struct {
            int16* bSPEED_ABS;
        } sdyno_quadrant;
        int16* bHOME_INIT;
        int16* bIq;
        int16* bLED_D17;
        int16* bLED_D2;
        int16* bPWM1;
        int16* bPWM2;
        int16* bPWM3;
    } outports;
};

/**********************************************************************************************************************/
/**     Externals                                                                                                    **/
/**********************************************************************************************************************/
extern struct x2cModel x2cModel;

extern const tBlockFunctions blockFunctionTable[];
extern const tParameterTable parameterIdTable[];
extern const tIoParamIdEntry inportParamIdTable[];
extern const tIoParamIdEntry outportParamIdTable[];
extern const tMaskParameterEntry maskParamIdTable[];
extern const tMaskParamExtRecord maskParamExtTable[];
extern const tMaskParamDataRecord maskParamDataTable[];

#define X2C_UPDATE_10_DIVIDER 10

/**********************************************************************************************************************/
/**     Prototypes                                                                                                   **/
/**********************************************************************************************************************/
void X2C_Init(void);
void X2C_Update(void);
void X2C_Update_1(void);
void X2C_Update_10(void);

#ifdef __cplusplus
}
#endif

#endif
