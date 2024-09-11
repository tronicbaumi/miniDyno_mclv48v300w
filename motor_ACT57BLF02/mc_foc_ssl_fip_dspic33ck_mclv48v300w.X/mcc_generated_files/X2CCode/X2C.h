/**
 * @file
 * @brief Generated model file.
 * 
 * Date:  2024-09-11 11:05
 * 
 * X2C-Version: 6.4.3073
 * X2C-Edition: Free
 */
/* This file is part of X2C. http://x2c.lcm.at/                                                                       */

/* Model: mc_foc_ssl_fip_dspic33ck_mclv48v300w                                                                        */
/* Date:  2024-09-11 11:05                                                                                            */

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
#include "I_FiP16.h"
#include "RateLimiter_FiP16.h"
#include "LoopBreaker_Bool.h"
#include "LoopBreaker_FiP16.h"
#include "ManualSwitch_FiP16.h"
#include "Not_Bool.h"
#include "Constant_FiP16.h"
#include "uSub_FiP16.h"
#include "Sin3Gen_FiP16.h"
#include "PI_FiP16.h"
#include "Saturation_FiP16.h"
#include "AutoSwitch_FiP16.h"
#include "BEMF_PLL_MCHP_FiP16.h"
#include "Sequencer_FiP16.h"
#include "SinGen_FiP16.h"
#include "Sub_FiP16.h"
#include "Clarke_Park_MCHP_FiP16.h"
#include "uI_FiP16.h"
#include "TypeConv_FiP16_Bool.h"
#include "Park_Clarke_inv_SVM_MCHP_FiP16.h"
#include "Add_FiP16.h"
#include "Sign_FiP16.h"
#include "Mult_FiP16.h"
#include "Scope_Main.h"
#include "CommonFcts.h"

/**********************************************************************************************************************/
/**     Defines                                                                                                      **/
/**********************************************************************************************************************/
#define FUNCTIONS \
    CONSTANT_BOOL_FUNCTIONS , \
    GAIN_FIP16_FUNCTIONS , \
    I_FIP16_FUNCTIONS , \
    RATELIMITER_FIP16_FUNCTIONS , \
    LOOPBREAKER_BOOL_FUNCTIONS , \
    LOOPBREAKER_FIP16_FUNCTIONS , \
    MANUALSWITCH_FIP16_FUNCTIONS , \
    NOT_BOOL_FUNCTIONS , \
    CONSTANT_FIP16_FUNCTIONS , \
    USUB_FIP16_FUNCTIONS , \
    SIN3GEN_FIP16_FUNCTIONS , \
    PI_FIP16_FUNCTIONS , \
    SATURATION_FIP16_FUNCTIONS , \
    AUTOSWITCH_FIP16_FUNCTIONS , \
    BEMF_PLL_MCHP_FIP16_FUNCTIONS , \
    SEQUENCER_FIP16_FUNCTIONS , \
    SINGEN_FIP16_FUNCTIONS , \
    SUB_FIP16_FUNCTIONS , \
    CLARKE_PARK_MCHP_FIP16_FUNCTIONS , \
    UI_FIP16_FUNCTIONS , \
    TYPECONV_FIP16_BOOL_FUNCTIONS , \
    PARK_CLARKE_INV_SVM_MCHP_FIP16_FUNCTIONS , \
    ADD_FIP16_FUNCTIONS , \
    SIGN_FIP16_FUNCTIONS , \
    MULT_FIP16_FUNCTIONS , \
    SCOPE_MAIN_FUNCTIONS

#define PARAMETER_TABLE \
    { 1U, &x2cModel.blocks.bGain } , \
    { 2U, &x2cModel.blocks.bLoopBreaker } , \
    { 3U, &x2cModel.blocks.bLoopBreaker1 } , \
    { 4U, &x2cModel.blocks.bNot } , \
    { 5U, &x2cModel.blocks.bPosSignalPath } , \
    { 6U, &x2cModel.blocks.sSpeed_PI.bConstant } , \
    { 7U, &x2cModel.blocks.sSpeed_PI.bConstant1 } , \
    { 8U, &x2cModel.blocks.sSpeed_PI.bManualSwitch } , \
    { 9U, &x2cModel.blocks.sSpeed_PI.bPI_speed } , \
    { 10U, &x2cModel.blocks.sSpeed_PI.bRateLimiter } , \
    { 11U, &x2cModel.blocks.sSpeed_PI.bSpeed_error } , \
    { 12U, &x2cModel.blocks.sSpeed_PI.sSuperBlock.bAdd } , \
    { 13U, &x2cModel.blocks.sSpeed_PI.sSuperBlock.bAutoSwitch } , \
    { 14U, &x2cModel.blocks.sSpeed_PI.sSuperBlock.bConstant } , \
    { 15U, &x2cModel.blocks.sSpeed_PI.sSuperBlock.bConstant1 } , \
    { 16U, &x2cModel.blocks.sSpeed_PI.sSuperBlock.bConstant2 } , \
    { 17U, &x2cModel.blocks.sSpeed_PI.sSuperBlock.bConstant3 } , \
    { 18U, &x2cModel.blocks.sSpeed_PI.sSuperBlock.bGain } , \
    { 19U, &x2cModel.blocks.sSpeed_PI.sSuperBlock.bRateLimiter } , \
    { 20U, &x2cModel.blocks.sSpeed_PI.sSuperBlock.bSinGen } , \
    { 21U, &x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP } , \
    { 22U, &x2cModel.blocks.sSuperBlock.bClarke_Park_MCHP } , \
    { 23U, &x2cModel.blocks.sSuperBlock.bConstant } , \
    { 24U, &x2cModel.blocks.sSuperBlock.bConstant1 } , \
    { 25U, &x2cModel.blocks.sSuperBlock.bGain } , \
    { 26U, &x2cModel.blocks.sSuperBlock.bGain2 } , \
    { 27U, &x2cModel.blocks.sSuperBlock.bGain3 } , \
    { 28U, &x2cModel.blocks.sSuperBlock.bManualSwitch } , \
    { 29U, &x2cModel.blocks.sSuperBlock.bManualSwitch1 } , \
    { 30U, &x2cModel.blocks.sSuperBlock.bManualSwitch2 } , \
    { 31U, &x2cModel.blocks.sSuperBlock.bManualSwitch3 } , \
    { 32U, &x2cModel.blocks.sSuperBlock.bManualSwitch5 } , \
    { 33U, &x2cModel.blocks.sSuperBlock.bNot } , \
    { 34U, &x2cModel.blocks.sSuperBlock.bOpenLoop_Vd } , \
    { 35U, &x2cModel.blocks.sSuperBlock.bOpenLoop_Vq } , \
    { 36U, &x2cModel.blocks.sSuperBlock.bPI_flux } , \
    { 37U, &x2cModel.blocks.sSuperBlock.bPI_torque } , \
    { 38U, &x2cModel.blocks.sSuperBlock.bPark_Clarke_inv_SVM_MCHP } , \
    { 39U, &x2cModel.blocks.sSuperBlock.bSaturation } , \
    { 40U, &x2cModel.blocks.sSuperBlock.bSaturation1 } , \
    { 41U, &x2cModel.blocks.sSuperBlock.bSin3Gen } , \
    { 42U, &x2cModel.blocks.sSuperBlock.bSub_flux } , \
    { 43U, &x2cModel.blocks.sSuperBlock.bSub_torque } , \
    { 44U, &x2cModel.blocks.bVelSignalPatth } , \
    { 45U, &x2cModel.blocks.sstartup.bConstant } , \
    { 46U, &x2cModel.blocks.sstartup.bConstant1 } , \
    { 47U, &x2cModel.blocks.sstartup.bConstant2 } , \
    { 48U, &x2cModel.blocks.sstartup.bConstant3 } , \
    { 49U, &x2cModel.blocks.sstartup.bConstant5 } , \
    { 50U, &x2cModel.blocks.sstartup.bFlux_select } , \
    { 51U, &x2cModel.blocks.sstartup.bFlux_select1 } , \
    { 52U, &x2cModel.blocks.sstartup.bIdRateLimiter } , \
    { 53U, &x2cModel.blocks.sstartup.bIq_select } , \
    { 54U, &x2cModel.blocks.sstartup.bLoopBreaker } , \
    { 55U, &x2cModel.blocks.sstartup.bLoopBreaker1 } , \
    { 56U, &x2cModel.blocks.sstartup.bManualSwitch } , \
    { 57U, &x2cModel.blocks.sstartup.bManualSwitch1 } , \
    { 58U, &x2cModel.blocks.sstartup.bPI } , \
    { 59U, &x2cModel.blocks.sstartup.bPosError } , \
    { 60U, &x2cModel.blocks.sstartup.bPosSwitch } , \
    { 61U, &x2cModel.blocks.sstartup.bRamp_Up_Current } , \
    { 62U, &x2cModel.blocks.sstartup.bSequencer } , \
    { 63U, &x2cModel.blocks.sstartup.sSuperBlock.bConstant4 } , \
    { 64U, &x2cModel.blocks.sstartup.sSuperBlock.bI } , \
    { 65U, &x2cModel.blocks.sstartup.sSuperBlock.bI_Init_Zero } , \
    { 66U, &x2cModel.blocks.sstartup.sSuperBlock.bI_Init_Zero1 } , \
    { 67U, &x2cModel.blocks.sstartup.sSuperBlock.bMult } , \
    { 68U, &x2cModel.blocks.sstartup.sSuperBlock.bRamp_Up_PositionGenerator } , \
    { 69U, &x2cModel.blocks.sstartup.sSuperBlock.bSaturation } , \
    { 70U, &x2cModel.blocks.sstartup.sSuperBlock.bSign } , \
    { 71U, &x2cModel.blocks.sstartup.sSuperBlock.bTypeConv } , \
    { 72U, &x2cModel.blocks.sstartup.bTypeConv } , \
    { 73U, &x2cModel.blocks.sstartup.bTypeConv1 } , \
    { 74U, &x2cModel.blocks.sstartup.bTypeConv2 } , \
    { 92U, &x2cScope }

#define INPORT_PARAMID_TABLE \
    { 75U, 2U, &x2cModel.inports.bCPU_LOAD } , \
    { 76U, 2U, &x2cModel.inports.bI_a } , \
    { 77U, 2U, &x2cModel.inports.bI_b } , \
    { 78U, 2U, &x2cModel.inports.bI_sum } , \
    { 79U, 2U, &x2cModel.inports.bQEI_POS } , \
    { 80U, 2U, &x2cModel.inports.bQEI_VEL } , \
    { 81U, 1U, &x2cModel.inports.bSW1 } , \
    { 82U, 2U, &x2cModel.inports.bSW2 } , \
    { 83U, 2U, &x2cModel.inports.bV_POT } 

#define OUTPORT_PARAMID_TABLE \
    { 84U, 1U, &x2cModel.outports.bHOME_INIT } , \
    { 85U, 1U, &x2cModel.outports.bLED1 } , \
    { 86U, 2U, &x2cModel.outports.bLED2 } , \
    { 87U, 2U, &x2cModel.outports.bPWM1 } , \
    { 88U, 2U, &x2cModel.outports.bPWM2 } , \
    { 89U, 2U, &x2cModel.outports.bPWM3 } , \
    { 90U, 2U, &x2cModel.outports.sSuperBlock.bEstimated_angle } , \
    { 91U, 2U, &x2cModel.outports.sSuperBlock.bEstimated_speed } 


/**********************************************************************************************************************/
/**                                            Model structure definition                                            **/
/**********************************************************************************************************************/
struct x2cModel {
/*  Control Blocks                                                                                                    */
    struct {
/*      Sub-system Speed_PI                                                                                           */
        struct {
/*          Sub-system SuperBlock                                                                                     */
            struct {
                ADD_FIP16 bAdd;
                AUTOSWITCH_FIP16 bAutoSwitch;
                CONSTANT_FIP16 bConstant;
                CONSTANT_FIP16 bConstant1;
                CONSTANT_BOOL bConstant2;
                CONSTANT_FIP16 bConstant3;
                GAIN_FIP16 bGain;
                RATELIMITER_FIP16 bRateLimiter;
                SINGEN_FIP16 bSinGen;
            } sSuperBlock;
            CONSTANT_FIP16 bConstant;
            CONSTANT_FIP16 bConstant1;
            MANUALSWITCH_FIP16 bManualSwitch;
            PI_FIP16 bPI_speed;
            RATELIMITER_FIP16 bRateLimiter;
            SUB_FIP16 bSpeed_error;
        } sSpeed_PI;
/*      Sub-system SuperBlock                                                                                         */
        struct {
            BEMF_PLL_MCHP_FIP16 bBEMF_PLL_MCHP;
            CLARKE_PARK_MCHP_FIP16 bClarke_Park_MCHP;
            CONSTANT_FIP16 bConstant;
            CONSTANT_FIP16 bConstant1;
            GAIN_FIP16 bGain;
            GAIN_FIP16 bGain2;
            GAIN_FIP16 bGain3;
            MANUALSWITCH_FIP16 bManualSwitch;
            MANUALSWITCH_FIP16 bManualSwitch1;
            MANUALSWITCH_FIP16 bManualSwitch2;
            MANUALSWITCH_FIP16 bManualSwitch3;
            MANUALSWITCH_FIP16 bManualSwitch5;
            NOT_BOOL bNot;
            CONSTANT_FIP16 bOpenLoop_Vd;
            CONSTANT_FIP16 bOpenLoop_Vq;
            PI_FIP16 bPI_flux;
            PI_FIP16 bPI_torque;
            PARK_CLARKE_INV_SVM_MCHP_FIP16 bPark_Clarke_inv_SVM_MCHP;
            SATURATION_FIP16 bSaturation;
            SATURATION_FIP16 bSaturation1;
            SIN3GEN_FIP16 bSin3Gen;
            SUB_FIP16 bSub_flux;
            SUB_FIP16 bSub_torque;
        } sSuperBlock;
/*      Sub-system startup                                                                                            */
        struct {
/*          Sub-system SuperBlock                                                                                     */
            struct {
                CONSTANT_FIP16 bConstant4;
                I_FIP16 bI;
                CONSTANT_FIP16 bI_Init_Zero;
                CONSTANT_FIP16 bI_Init_Zero1;
                MULT_FIP16 bMult;
                UI_FIP16 bRamp_Up_PositionGenerator;
                SATURATION_FIP16 bSaturation;
                SIGN_FIP16 bSign;
                TYPECONV_FIP16_BOOL bTypeConv;
            } sSuperBlock;
            CONSTANT_FIP16 bConstant;
            CONSTANT_FIP16 bConstant1;
            CONSTANT_FIP16 bConstant2;
            CONSTANT_FIP16 bConstant3;
            CONSTANT_BOOL bConstant5;
            AUTOSWITCH_FIP16 bFlux_select;
            AUTOSWITCH_FIP16 bFlux_select1;
            RATELIMITER_FIP16 bIdRateLimiter;
            AUTOSWITCH_FIP16 bIq_select;
            LOOPBREAKER_FIP16 bLoopBreaker;
            LOOPBREAKER_BOOL bLoopBreaker1;
            MANUALSWITCH_FIP16 bManualSwitch;
            MANUALSWITCH_FIP16 bManualSwitch1;
            PI_FIP16 bPI;
            USUB_FIP16 bPosError;
            AUTOSWITCH_FIP16 bPosSwitch;
            CONSTANT_FIP16 bRamp_Up_Current;
            SEQUENCER_FIP16 bSequencer;
            TYPECONV_FIP16_BOOL bTypeConv;
            TYPECONV_FIP16_BOOL bTypeConv1;
            TYPECONV_FIP16_BOOL bTypeConv2;
        } sstartup;
        GAIN_FIP16 bGain;
        LOOPBREAKER_FIP16 bLoopBreaker;
        LOOPBREAKER_FIP16 bLoopBreaker1;
        NOT_BOOL bNot;
        MANUALSWITCH_FIP16 bPosSignalPath;
        MANUALSWITCH_FIP16 bVelSignalPatth;
    } blocks;
/*  Inports                                                                                                           */
    struct {
        int16 bCPU_LOAD;
        int16 bI_a;
        int16 bI_b;
        int16 bI_sum;
        int16 bQEI_POS;
        int16 bQEI_VEL;
        bool bSW1;
        int16 bSW2;
        int16 bV_POT;
    } inports;
/*  Outports                                                                                                          */
    struct {
/*      Sub-system SuperBlock                                                                                         */
        struct {
            int16* bEstimated_angle;
            int16* bEstimated_speed;
        } sSuperBlock;
        bool* bHOME_INIT;
        bool* bLED1;
        int16* bLED2;
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
