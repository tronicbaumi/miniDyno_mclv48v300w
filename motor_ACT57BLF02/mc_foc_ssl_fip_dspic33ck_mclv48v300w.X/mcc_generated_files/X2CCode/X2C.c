/* This file is part of X2C. http://x2c.lcm.at/                                                                       */

/* Model: mc_foc_ssl_fip_dspic33ck_mclv48v300w                                                                        */
/* Date:  2024-09-11 11:05                                                                                            */

/* X2C-Version: 6.4.3073                                                                                              */
/* X2C-Edition: Free                                                                                                  */

/* Common includes                                                                                                    */
#include <stddef.h>
#include "TableStruct.h"
/* Generated file includes                                                                                            */
#include "FlashTable.h"
#include "RamTable.h"
#include "X2C.h"

/**********************************************************************************************************************/
/**                                                       Model                                                      **/
/**********************************************************************************************************************/
struct x2cModel x2cModel;

/**********************************************************************************************************************/
/**                                                       Scope                                                      **/
/**********************************************************************************************************************/
SCOPE_MAIN x2cScope;

/* Block function table                                                                                               */
const tBlockFunctions blockFunctionTable[] = {
    FUNCTIONS,
    { 0U, NULL, NULL, NULL, NULL, NULL } /* End of table entry */
};

/* Parameter identifier table                                                                                         */
const tParameterTable parameterIdTable[] = {
    PARAMETER_TABLE,
    { 0U, NULL } /* End of table entry */
};

/* Inport Parameter identifier table                                                                                  */
const tIoParamIdEntry inportParamIdTable[] = {
    INPORT_PARAMID_TABLE, 
    { 0U, 0U, NULL } /* End of table entry */
};

/* Outport Parameter identifier table                                                                                 */
const tIoParamIdEntry outportParamIdTable[] = {
    OUTPORT_PARAMID_TABLE, 
    { 0U, 0U, NULL } /* End of table entry */
};

/* Mask Parameter identifier table                                                                                    */
const tMaskParameterEntry maskParamIdTable[] = {
    { 0U, NULL, NULL, NULL, NULL } /* End of table entry */
};

/* Extended Mask Parameter identifier table (used by Model API)                                                       */
const tMaskParamExtRecord maskParamExtTable[] = {
    { 0U, 0U, NULL, NULL, NULL, NULL, NULL } /* End of table entry */
};

/* Mask Parameter data table (used by Model API)                                                                      */
const tMaskParamDataRecord maskParamDataTable[] = {
    { 0U, 0U, NULL, 0U, 0U } /* End of table entry */
};

/**********************************************************************************************************************/
/** Model Sample Time                                                                                                **/
/**********************************************************************************************************************/
float_CoT getModelSampleTime()
{
    return ((float_CoT)1.0E-4);
}

/**********************************************************************************************************************/
/**                                                  Initialization                                                  **/
/**********************************************************************************************************************/
void X2C_Init(void)
{
    /******************************************************************************************************************/
    /**                                          Initialize Block Parameters                                         **/
    /******************************************************************************************************************/

    /* Block: Gain                                                                                                    */
    /* Gain = 0.6                                                                                                     */
    x2cModel.blocks.bGain.V = 19661;
    x2cModel.blocks.bGain.sfr = 15;

    /* Block: LoopBreaker                                                                                             */

    /* Block: LoopBreaker1                                                                                            */

    /* Block: Not                                                                                                     */

    /* Block: PosSignalPath                                                                                           */
    /* Toggle = 1.0                                                                                                   */
    x2cModel.blocks.bPosSignalPath.Toggle = 1;

    /* Block: Speed_PI/Constant                                                                                       */
    /* Value = 0.01                                                                                                   */
    x2cModel.blocks.sSpeed_PI.bConstant.K = 328;

    /* Block: Speed_PI/Constant1                                                                                      */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.sSpeed_PI.bConstant1.K = 0;

    /* Block: Speed_PI/ManualSwitch                                                                                   */
    /* Toggle = 0.0                                                                                                   */
    x2cModel.blocks.sSpeed_PI.bManualSwitch.Toggle = 0;

    /* Block: Speed_PI/PI_speed                                                                                       */
    /* Kp = 0.5                                                                                                       */
    /* Ki = 0.4                                                                                                       */
    /* ts_fact = 10.0                                                                                                 */
    x2cModel.blocks.sSpeed_PI.bPI_speed.b0 = 13;
    x2cModel.blocks.sSpeed_PI.bPI_speed.b1 = 16384;
    x2cModel.blocks.sSpeed_PI.bPI_speed.sfrb0 = 15;
    x2cModel.blocks.sSpeed_PI.bPI_speed.sfrb1 = 15;
    x2cModel.blocks.sSpeed_PI.bPI_speed.i_old = 0;
    x2cModel.blocks.sSpeed_PI.bPI_speed.enable_old = 0;

    /* Block: Speed_PI/RateLimiter                                                                                    */
    /* Tr = 0.2                                                                                                       */
    /* Tf = 0.2                                                                                                       */
    /* ts_fact = 10.0                                                                                                 */
    x2cModel.blocks.sSpeed_PI.bRateLimiter.RateUp = 10737418;
    x2cModel.blocks.sSpeed_PI.bRateLimiter.RateDown = 10737418;
    x2cModel.blocks.sSpeed_PI.bRateLimiter.out_old = 0;
    x2cModel.blocks.sSpeed_PI.bRateLimiter.enable_old = 0;

    /* Block: Speed_PI/Speed_error                                                                                    */

    /* Block: Speed_PI/SuperBlock/Add                                                                                 */

    /* Block: Speed_PI/SuperBlock/AutoSwitch                                                                          */
    /* Thresh_up = 0.0                                                                                                */
    /* Thresh_down = 0.0                                                                                              */
    x2cModel.blocks.sSpeed_PI.sSuperBlock.bAutoSwitch.Thresh_up = 0;
    x2cModel.blocks.sSpeed_PI.sSuperBlock.bAutoSwitch.Thresh_down = 0;
    x2cModel.blocks.sSpeed_PI.sSuperBlock.bAutoSwitch.Status = &RamTable_int16[0];

    /* Block: Speed_PI/SuperBlock/Constant                                                                            */
    /* Value = 1.0                                                                                                    */
    x2cModel.blocks.sSpeed_PI.sSuperBlock.bConstant.K = 32767;

    /* Block: Speed_PI/SuperBlock/Constant1                                                                           */
    /* Value = 0.01                                                                                                   */
    x2cModel.blocks.sSpeed_PI.sSuperBlock.bConstant1.K = 328;

    /* Block: Speed_PI/SuperBlock/Constant2                                                                           */
    /* Value = 1.0                                                                                                    */
    x2cModel.blocks.sSpeed_PI.sSuperBlock.bConstant2.K = 1;

    /* Block: Speed_PI/SuperBlock/Constant3                                                                           */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.sSpeed_PI.sSuperBlock.bConstant3.K = 0;

    /* Block: Speed_PI/SuperBlock/Gain                                                                                */
    /* Gain = -1.0                                                                                                    */
    x2cModel.blocks.sSpeed_PI.sSuperBlock.bGain.V = -16384;
    x2cModel.blocks.sSpeed_PI.sSuperBlock.bGain.sfr = 14;

    /* Block: Speed_PI/SuperBlock/RateLimiter                                                                         */
    /* Tr = 0.0                                                                                                       */
    /* Tf = 0.0                                                                                                       */
    /* ts_fact = 10.0                                                                                                 */
    x2cModel.blocks.sSpeed_PI.sSuperBlock.bRateLimiter.RateUp = 2147483647;
    x2cModel.blocks.sSpeed_PI.sSuperBlock.bRateLimiter.RateDown = 2147483647;
    x2cModel.blocks.sSpeed_PI.sSuperBlock.bRateLimiter.out_old = 0;
    x2cModel.blocks.sSpeed_PI.sSuperBlock.bRateLimiter.enable_old = 0;

    /* Block: Speed_PI/SuperBlock/SinGen                                                                              */
    /* fmax = 100.0                                                                                                   */
    /* Offset = 0.0                                                                                                   */
    /* Phase = 0.0                                                                                                    */
    /* ts_fact = 10.0                                                                                                 */
    x2cModel.blocks.sSpeed_PI.sSuperBlock.bSinGen.delta_phi = 6554;
    x2cModel.blocks.sSpeed_PI.sSuperBlock.bSinGen.phase = 0;
    x2cModel.blocks.sSpeed_PI.sSuperBlock.bSinGen.offset = 0;
    x2cModel.blocks.sSpeed_PI.sSuperBlock.bSinGen.phi = 0;

    /* Block: SuperBlock/BEMF_PLL_MCHP                                                                                */
    /* Ls = 0.34                                                                                                      */
    /* Rs = 0.4                                                                                                       */
    /* U0 = 24.0                                                                                                      */
    /* I0 = 22.0                                                                                                      */
    /* CurrentSampleFactor = 4.0                                                                                      */
    /* n = 4                                                                                                          */
    /* Gain = 0.65625                                                                                                 */
    /* p = 4.0                                                                                                        */
    /* n_max = 5000.0                                                                                                 */
    /* ts_fact = 1.0                                                                                                  */
    x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP.Ls = 25532;
    x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP.Rs = 12015;
    x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP.sfrLs = 15;
    x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP.sfrRs = 15;
    x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP.Ib_old = 0;
    x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP.Ia_old = 0;
    x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP.CurrentSampleFactor = 4;
    x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP.V_Ls_alpha = 0;
    x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP.V_Ls_beta = 0;
    x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP.FactCounter = 0;
    x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP.old_theta = 0;
    x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP.avg_d = &RamTable_int16[1];
    x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP.avg_q = &RamTable_int16[257];
    x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP.sum_d = 0;
    x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP.sum_q = 0;
    x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP.n = 4;
    x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP.sfrn = 2;
    x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP.count = 0;
    x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP.V_gain = 21504;
    x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP.sfr_gain = 15;
    x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP.b0 = 2185;
    x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP.sfr_b0 = 15;
    x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP.i_old = 0;
    x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP.enable_old = 0;

    /* Block: SuperBlock/Clarke_Park_MCHP                                                                             */

    /* Block: SuperBlock/Constant                                                                                     */
    /* Value = 0.25                                                                                                   */
    x2cModel.blocks.sSuperBlock.bConstant.K = 8192;

    /* Block: SuperBlock/Constant1                                                                                    */
    /* Value = 0.3                                                                                                    */
    x2cModel.blocks.sSuperBlock.bConstant1.K = 9830;

    /* Block: SuperBlock/Gain                                                                                         */
    /* Gain = 0.5                                                                                                     */
    x2cModel.blocks.sSuperBlock.bGain.V = 16384;
    x2cModel.blocks.sSuperBlock.bGain.sfr = 15;

    /* Block: SuperBlock/Gain2                                                                                        */
    /* Gain = 0.98                                                                                                    */
    x2cModel.blocks.sSuperBlock.bGain2.V = 32113;
    x2cModel.blocks.sSuperBlock.bGain2.sfr = 15;

    /* Block: SuperBlock/Gain3                                                                                        */
    /* Gain = 0.98                                                                                                    */
    x2cModel.blocks.sSuperBlock.bGain3.V = 32113;
    x2cModel.blocks.sSuperBlock.bGain3.sfr = 15;

    /* Block: SuperBlock/ManualSwitch                                                                                 */
    /* Toggle = 1.0                                                                                                   */
    x2cModel.blocks.sSuperBlock.bManualSwitch.Toggle = 1;

    /* Block: SuperBlock/ManualSwitch1                                                                                */
    /* Toggle = 1.0                                                                                                   */
    x2cModel.blocks.sSuperBlock.bManualSwitch1.Toggle = 1;

    /* Block: SuperBlock/ManualSwitch2                                                                                */
    /* Toggle = 1.0                                                                                                   */
    x2cModel.blocks.sSuperBlock.bManualSwitch2.Toggle = 1;

    /* Block: SuperBlock/ManualSwitch3                                                                                */
    /* Toggle = 1.0                                                                                                   */
    x2cModel.blocks.sSuperBlock.bManualSwitch3.Toggle = 1;

    /* Block: SuperBlock/ManualSwitch5                                                                                */
    /* Toggle = 1.0                                                                                                   */
    x2cModel.blocks.sSuperBlock.bManualSwitch5.Toggle = 1;

    /* Block: SuperBlock/Not                                                                                          */

    /* Block: SuperBlock/OpenLoop_Vd                                                                                  */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.sSuperBlock.bOpenLoop_Vd.K = 0;

    /* Block: SuperBlock/OpenLoop_Vq                                                                                  */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.sSuperBlock.bOpenLoop_Vq.K = 0;

    /* Block: SuperBlock/PI_flux                                                                                      */
    /* Kp = 1.0                                                                                                       */
    /* Ki = 100.0                                                                                                     */
    /* ts_fact = 1.0                                                                                                  */
    x2cModel.blocks.sSuperBlock.bPI_flux.b0 = 328;
    x2cModel.blocks.sSuperBlock.bPI_flux.b1 = 16384;
    x2cModel.blocks.sSuperBlock.bPI_flux.sfrb0 = 15;
    x2cModel.blocks.sSuperBlock.bPI_flux.sfrb1 = 14;
    x2cModel.blocks.sSuperBlock.bPI_flux.i_old = 0;
    x2cModel.blocks.sSuperBlock.bPI_flux.enable_old = 0;

    /* Block: SuperBlock/PI_torque                                                                                    */
    /* Kp = 1.0                                                                                                       */
    /* Ki = 100.0                                                                                                     */
    /* ts_fact = 1.0                                                                                                  */
    x2cModel.blocks.sSuperBlock.bPI_torque.b0 = 328;
    x2cModel.blocks.sSuperBlock.bPI_torque.b1 = 16384;
    x2cModel.blocks.sSuperBlock.bPI_torque.sfrb0 = 15;
    x2cModel.blocks.sSuperBlock.bPI_torque.sfrb1 = 14;
    x2cModel.blocks.sSuperBlock.bPI_torque.i_old = 0;
    x2cModel.blocks.sSuperBlock.bPI_torque.enable_old = 0;

    /* Block: SuperBlock/Park_Clarke_inv_SVM_MCHP                                                                     */

    /* Block: SuperBlock/Saturation                                                                                   */
    /* max = 0.86                                                                                                     */
    /* min = -0.86                                                                                                    */
    x2cModel.blocks.sSuperBlock.bSaturation.max = 28180;
    x2cModel.blocks.sSuperBlock.bSaturation.min = -28180;

    /* Block: SuperBlock/Saturation1                                                                                  */
    /* max = 0.88                                                                                                     */
    /* min = -0.88                                                                                                    */
    x2cModel.blocks.sSuperBlock.bSaturation1.max = 28836;
    x2cModel.blocks.sSuperBlock.bSaturation1.min = -28836;

    /* Block: SuperBlock/Sin3Gen                                                                                      */
    /* fmax = 100.0                                                                                                   */
    /* Offset = 0.0                                                                                                   */
    /* ts_fact = 1.0                                                                                                  */
    x2cModel.blocks.sSuperBlock.bSin3Gen.delta_phi = 655;
    x2cModel.blocks.sSuperBlock.bSin3Gen.offset = 0;
    x2cModel.blocks.sSuperBlock.bSin3Gen.phi = 0;

    /* Block: SuperBlock/Sub_flux                                                                                     */

    /* Block: SuperBlock/Sub_torque                                                                                   */

    /* Block: VelSignalPatth                                                                                          */
    /* Toggle = 1.0                                                                                                   */
    x2cModel.blocks.bVelSignalPatth.Toggle = 1;

    /* Block: startup/Constant                                                                                        */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.sstartup.bConstant.K = 0;

    /* Block: startup/Constant1                                                                                       */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.sstartup.bConstant1.K = 0;

    /* Block: startup/Constant2                                                                                       */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.sstartup.bConstant2.K = 0;

    /* Block: startup/Constant3                                                                                       */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.sstartup.bConstant3.K = 0;

    /* Block: startup/Constant5                                                                                       */
    /* Value = 1.0                                                                                                    */
    x2cModel.blocks.sstartup.bConstant5.K = 1;

    /* Block: startup/Flux_select                                                                                     */
    /* Thresh_up = 0.5                                                                                                */
    /* Thresh_down = 0.5                                                                                              */
    x2cModel.blocks.sstartup.bFlux_select.Thresh_up = 16384;
    x2cModel.blocks.sstartup.bFlux_select.Thresh_down = 16384;
    x2cModel.blocks.sstartup.bFlux_select.Status = &RamTable_int16[513];

    /* Block: startup/Flux_select1                                                                                    */
    /* Thresh_up = 0.5                                                                                                */
    /* Thresh_down = 0.5                                                                                              */
    x2cModel.blocks.sstartup.bFlux_select1.Thresh_up = 16384;
    x2cModel.blocks.sstartup.bFlux_select1.Thresh_down = 16384;
    x2cModel.blocks.sstartup.bFlux_select1.Status = &RamTable_int16[514];

    /* Block: startup/IdRateLimiter                                                                                   */
    /* Tr = 0.5                                                                                                       */
    /* Tf = 1.0                                                                                                       */
    /* ts_fact = 1.0                                                                                                  */
    x2cModel.blocks.sstartup.bIdRateLimiter.RateUp = 429497;
    x2cModel.blocks.sstartup.bIdRateLimiter.RateDown = 214748;
    x2cModel.blocks.sstartup.bIdRateLimiter.out_old = 0;
    x2cModel.blocks.sstartup.bIdRateLimiter.enable_old = 0;

    /* Block: startup/Iq_select                                                                                       */
    /* Thresh_up = 0.5                                                                                                */
    /* Thresh_down = 0.5                                                                                              */
    x2cModel.blocks.sstartup.bIq_select.Thresh_up = 16384;
    x2cModel.blocks.sstartup.bIq_select.Thresh_down = 16384;
    x2cModel.blocks.sstartup.bIq_select.Status = &RamTable_int16[515];

    /* Block: startup/LoopBreaker                                                                                     */

    /* Block: startup/LoopBreaker1                                                                                    */

    /* Block: startup/ManualSwitch                                                                                    */
    /* Toggle = 0.0                                                                                                   */
    x2cModel.blocks.sstartup.bManualSwitch.Toggle = 0;

    /* Block: startup/ManualSwitch1                                                                                   */
    /* Toggle = 0.0                                                                                                   */
    x2cModel.blocks.sstartup.bManualSwitch1.Toggle = 0;

    /* Block: startup/PI                                                                                              */
    /* Kp = 0.0                                                                                                       */
    /* Ki = 0.0                                                                                                       */
    /* ts_fact = 1.0                                                                                                  */
    x2cModel.blocks.sstartup.bPI.b0 = 0;
    x2cModel.blocks.sstartup.bPI.b1 = 0;
    x2cModel.blocks.sstartup.bPI.sfrb0 = 15;
    x2cModel.blocks.sstartup.bPI.sfrb1 = 15;
    x2cModel.blocks.sstartup.bPI.i_old = 0;
    x2cModel.blocks.sstartup.bPI.enable_old = 0;

    /* Block: startup/PosError                                                                                        */

    /* Block: startup/PosSwitch                                                                                       */
    /* Thresh_up = 0.5                                                                                                */
    /* Thresh_down = 0.5                                                                                              */
    x2cModel.blocks.sstartup.bPosSwitch.Thresh_up = 16384;
    x2cModel.blocks.sstartup.bPosSwitch.Thresh_down = 16384;
    x2cModel.blocks.sstartup.bPosSwitch.Status = &RamTable_int16[516];

    /* Block: startup/Ramp_Up_Current                                                                                 */
    /* Value = 0.2                                                                                                    */
    x2cModel.blocks.sstartup.bRamp_Up_Current.K = 6554;

    /* Block: startup/Sequencer                                                                                       */
    /* Delay1 = 0.1                                                                                                   */
    /* Delay2 = 0.5                                                                                                   */
    /* Delay3 = 1.3                                                                                                   */
    /* Delay4 = 1.6                                                                                                   */
    /* ts_fact = 1.0                                                                                                  */
    x2cModel.blocks.sstartup.bSequencer.delay1 = 1000;
    x2cModel.blocks.sstartup.bSequencer.delay2 = 5000;
    x2cModel.blocks.sstartup.bSequencer.delay3 = 13000;
    x2cModel.blocks.sstartup.bSequencer.delay4 = 16000;
    x2cModel.blocks.sstartup.bSequencer.cnt = 0;
    x2cModel.blocks.sstartup.bSequencer.start_old = 0;

    /* Block: startup/SuperBlock/Constant4                                                                            */
    /* Value = 1.0                                                                                                    */
    x2cModel.blocks.sstartup.sSuperBlock.bConstant4.K = 32767;

    /* Block: startup/SuperBlock/I                                                                                    */
    /* Ki = 0.5                                                                                                       */
    /* ts_fact = 1.0                                                                                                  */
    x2cModel.blocks.sstartup.sSuperBlock.bI.b0 = 2;
    x2cModel.blocks.sstartup.sSuperBlock.bI.sfr = 15;
    x2cModel.blocks.sstartup.sSuperBlock.bI.i_old = 0;
    x2cModel.blocks.sstartup.sSuperBlock.bI.enable_old = 0;

    /* Block: startup/SuperBlock/I_Init_Zero                                                                          */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.sstartup.sSuperBlock.bI_Init_Zero.K = 0;

    /* Block: startup/SuperBlock/I_Init_Zero1                                                                         */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.sstartup.sSuperBlock.bI_Init_Zero1.K = 0;

    /* Block: startup/SuperBlock/Mult                                                                                 */

    /* Block: startup/SuperBlock/Ramp_Up_PositionGenerator                                                            */
    /* Ki = 200.0                                                                                                     */
    /* ts_fact = 1.0                                                                                                  */
    x2cModel.blocks.sstartup.sSuperBlock.bRamp_Up_PositionGenerator.b0 = 655;
    x2cModel.blocks.sstartup.sSuperBlock.bRamp_Up_PositionGenerator.sfr = 15;
    x2cModel.blocks.sstartup.sSuperBlock.bRamp_Up_PositionGenerator.i_old = 0;
    x2cModel.blocks.sstartup.sSuperBlock.bRamp_Up_PositionGenerator.enable_old = 0;

    /* Block: startup/SuperBlock/Saturation                                                                           */
    /* max = 0.5                                                                                                      */
    /* min = -0.5                                                                                                     */
    x2cModel.blocks.sstartup.sSuperBlock.bSaturation.max = 16384;
    x2cModel.blocks.sstartup.sSuperBlock.bSaturation.min = -16384;

    /* Block: startup/SuperBlock/Sign                                                                                 */

    /* Block: startup/SuperBlock/TypeConv                                                                             */

    /* Block: startup/TypeConv                                                                                        */

    /* Block: startup/TypeConv1                                                                                       */

    /* Block: startup/TypeConv2                                                                                       */


    /* Initialize RAM table content */
    initRamTables();

    /******************************************************************************************************************/
    /**                                              Initialize Inports                                              **/
    /******************************************************************************************************************/
    x2cModel.inports.bCPU_LOAD = (int16)0;
    x2cModel.inports.bI_a = (int16)0;
    x2cModel.inports.bI_b = (int16)0;
    x2cModel.inports.bI_sum = (int16)0;
    x2cModel.inports.bQEI_POS = (int16)0;
    x2cModel.inports.bQEI_VEL = (int16)0;
    x2cModel.inports.bSW1 = false;
    x2cModel.inports.bSW2 = (int16)0;
    x2cModel.inports.bV_POT = (int16)0;

    /******************************************************************************************************************/
    /**                                               Link Block Inputs                                              **/
    /******************************************************************************************************************/

    /* Block Gain                                                                                                     */
    x2cModel.blocks.bGain.In =
        &x2cModel.inports.bV_POT;

    /* Block LoopBreaker                                                                                              */
    x2cModel.blocks.bLoopBreaker.In =
        &x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP.speed;

    /* Block LoopBreaker1                                                                                             */
    x2cModel.blocks.bLoopBreaker1.In =
        &x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP.theta;

    /* Block Not                                                                                                      */
    x2cModel.blocks.bNot.In =
        &x2cModel.blocks.sstartup.bTypeConv.Out;

    /* Block PosSignalPath                                                                                            */
    x2cModel.blocks.bPosSignalPath.In1 =
        &x2cModel.inports.bQEI_POS;
    x2cModel.blocks.bPosSignalPath.In2 =
        &x2cModel.blocks.bLoopBreaker1.Out;

    /* Block Constant                                                                                                 */

    /* Block Constant1                                                                                                */

    /* Block ManualSwitch                                                                                             */
    x2cModel.blocks.sSpeed_PI.bManualSwitch.In1 =
        &x2cModel.blocks.sSpeed_PI.bPI_speed.Out;
    x2cModel.blocks.sSpeed_PI.bManualSwitch.In2 =
        &x2cModel.blocks.sSpeed_PI.bConstant.Out;

    /* Block PI_speed                                                                                                 */
    x2cModel.blocks.sSpeed_PI.bPI_speed.In =
        &x2cModel.blocks.sSpeed_PI.bSpeed_error.Out;
    x2cModel.blocks.sSpeed_PI.bPI_speed.Init =
        &x2cModel.blocks.sstartup.bLoopBreaker.Out;
    x2cModel.blocks.sSpeed_PI.bPI_speed.Enable =
        &x2cModel.blocks.sstartup.bLoopBreaker1.Out;

    /* Block RateLimiter                                                                                              */
    x2cModel.blocks.sSpeed_PI.bRateLimiter.In =
        &x2cModel.blocks.bGain.Out;
    x2cModel.blocks.sSpeed_PI.bRateLimiter.Init =
        &x2cModel.blocks.bVelSignalPatth.Out;
    x2cModel.blocks.sSpeed_PI.bRateLimiter.Enable =
        &x2cModel.blocks.sstartup.bLoopBreaker1.Out;

    /* Block Speed_error                                                                                              */
    x2cModel.blocks.sSpeed_PI.bSpeed_error.Plus =
        &x2cModel.blocks.sSpeed_PI.bRateLimiter.Out;
    x2cModel.blocks.sSpeed_PI.bSpeed_error.Minus =
        &x2cModel.blocks.bVelSignalPatth.Out;

    /* Block Add                                                                                                      */
    x2cModel.blocks.sSpeed_PI.sSuperBlock.bAdd.In1 =
        &x2cModel.blocks.sSpeed_PI.bManualSwitch.Out;
    x2cModel.blocks.sSpeed_PI.sSuperBlock.bAdd.In2 =
        &x2cModel.blocks.sSpeed_PI.sSuperBlock.bAutoSwitch.Out;

    /* Block AutoSwitch                                                                                               */
    x2cModel.blocks.sSpeed_PI.sSuperBlock.bAutoSwitch.In1 =
        &x2cModel.blocks.sSpeed_PI.bConstant1.Out;
    x2cModel.blocks.sSpeed_PI.sSuperBlock.bAutoSwitch.Switch =
        &x2cModel.blocks.sSpeed_PI.sSuperBlock.bSinGen.u;
    x2cModel.blocks.sSpeed_PI.sSuperBlock.bAutoSwitch.In3 =
        &x2cModel.blocks.sSpeed_PI.sSuperBlock.bGain.Out;

    /* Block Constant                                                                                                 */

    /* Block Constant1                                                                                                */

    /* Block Constant2                                                                                                */

    /* Block Constant3                                                                                                */

    /* Block Gain                                                                                                     */
    x2cModel.blocks.sSpeed_PI.sSuperBlock.bGain.In =
        &x2cModel.blocks.sSpeed_PI.bConstant1.Out;

    /* Block RateLimiter                                                                                              */
    x2cModel.blocks.sSpeed_PI.sSuperBlock.bRateLimiter.In =
        &x2cModel.blocks.sSpeed_PI.sSuperBlock.bAdd.Out;
    x2cModel.blocks.sSpeed_PI.sSuperBlock.bRateLimiter.Init =
        &x2cModel.blocks.sSpeed_PI.sSuperBlock.bConstant3.Out;
    x2cModel.blocks.sSpeed_PI.sSuperBlock.bRateLimiter.Enable =
        &x2cModel.blocks.sSpeed_PI.sSuperBlock.bConstant2.Out;

    /* Block SinGen                                                                                                   */
    x2cModel.blocks.sSpeed_PI.sSuperBlock.bSinGen.A =
        &x2cModel.blocks.sSpeed_PI.sSuperBlock.bConstant.Out;
    x2cModel.blocks.sSpeed_PI.sSuperBlock.bSinGen.f =
        &x2cModel.blocks.sSpeed_PI.sSuperBlock.bConstant1.Out;

    /* Block BEMF_PLL_MCHP                                                                                            */
    x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP.Ialpha =
        &x2cModel.blocks.sSuperBlock.bClarke_Park_MCHP.alpha;
    x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP.Ibeta =
        &x2cModel.blocks.sSuperBlock.bClarke_Park_MCHP.beta;
    x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP.Valpha =
        &x2cModel.blocks.sSuperBlock.bGain2.Out;
    x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP.Vbeta =
        &x2cModel.blocks.sSuperBlock.bGain3.Out;
    x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP.theta0 =
        &x2cModel.blocks.sstartup.bPosSwitch.Out;
    x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP.Enable =
        &x2cModel.blocks.sstartup.bTypeConv2.Out;

    /* Block Clarke_Park_MCHP                                                                                         */
    x2cModel.blocks.sSuperBlock.bClarke_Park_MCHP.a =
        &x2cModel.inports.bI_a;
    x2cModel.blocks.sSuperBlock.bClarke_Park_MCHP.b =
        &x2cModel.inports.bI_b;
    x2cModel.blocks.sSuperBlock.bClarke_Park_MCHP.theta =
        &x2cModel.blocks.sstartup.bPosSwitch.Out;

    /* Block Constant                                                                                                 */

    /* Block Constant1                                                                                                */

    /* Block Gain                                                                                                     */
    x2cModel.blocks.sSuperBlock.bGain.In =
        &x2cModel.blocks.sstartup.bIdRateLimiter.Out;

    /* Block Gain2                                                                                                    */
    x2cModel.blocks.sSuperBlock.bGain2.In =
        &x2cModel.blocks.sSuperBlock.bPark_Clarke_inv_SVM_MCHP.Valpha;

    /* Block Gain3                                                                                                    */
    x2cModel.blocks.sSuperBlock.bGain3.In =
        &x2cModel.blocks.sSuperBlock.bPark_Clarke_inv_SVM_MCHP.Vbeta;

    /* Block ManualSwitch                                                                                             */
    x2cModel.blocks.sSuperBlock.bManualSwitch.In1 =
        &x2cModel.blocks.sSuperBlock.bOpenLoop_Vd.Out;
    x2cModel.blocks.sSuperBlock.bManualSwitch.In2 =
        &x2cModel.blocks.sSuperBlock.bPI_flux.Out;

    /* Block ManualSwitch1                                                                                            */
    x2cModel.blocks.sSuperBlock.bManualSwitch1.In1 =
        &x2cModel.blocks.sSuperBlock.bOpenLoop_Vq.Out;
    x2cModel.blocks.sSuperBlock.bManualSwitch1.In2 =
        &x2cModel.blocks.sSuperBlock.bPI_torque.Out;

    /* Block ManualSwitch2                                                                                            */
    x2cModel.blocks.sSuperBlock.bManualSwitch2.In1 =
        &x2cModel.blocks.sSuperBlock.bSin3Gen.u;
    x2cModel.blocks.sSuperBlock.bManualSwitch2.In2 =
        &x2cModel.blocks.sSuperBlock.bPark_Clarke_inv_SVM_MCHP.A;

    /* Block ManualSwitch3                                                                                            */
    x2cModel.blocks.sSuperBlock.bManualSwitch3.In1 =
        &x2cModel.blocks.sSuperBlock.bSin3Gen.v;
    x2cModel.blocks.sSuperBlock.bManualSwitch3.In2 =
        &x2cModel.blocks.sSuperBlock.bPark_Clarke_inv_SVM_MCHP.B;

    /* Block ManualSwitch5                                                                                            */
    x2cModel.blocks.sSuperBlock.bManualSwitch5.In1 =
        &x2cModel.blocks.sSuperBlock.bSin3Gen.w;
    x2cModel.blocks.sSuperBlock.bManualSwitch5.In2 =
        &x2cModel.blocks.sSuperBlock.bPark_Clarke_inv_SVM_MCHP.C;

    /* Block Not                                                                                                      */
    x2cModel.blocks.sSuperBlock.bNot.In =
        &x2cModel.blocks.sstartup.bTypeConv.Out;

    /* Block OpenLoop_Vd                                                                                              */

    /* Block OpenLoop_Vq                                                                                              */

    /* Block PI_flux                                                                                                  */
    x2cModel.blocks.sSuperBlock.bPI_flux.In =
        &x2cModel.blocks.sSuperBlock.bSub_flux.Out;
    x2cModel.blocks.sSuperBlock.bPI_flux.Init =
        &x2cModel.blocks.sstartup.bIdRateLimiter.Out;
    x2cModel.blocks.sSuperBlock.bPI_flux.Enable =
        &x2cModel.blocks.sstartup.bTypeConv.Out;

    /* Block PI_torque                                                                                                */
    x2cModel.blocks.sSuperBlock.bPI_torque.In =
        &x2cModel.blocks.sSuperBlock.bSub_torque.Out;
    x2cModel.blocks.sSuperBlock.bPI_torque.Init =
        &x2cModel.blocks.sstartup.bLoopBreaker.Out;
    x2cModel.blocks.sSuperBlock.bPI_torque.Enable =
        &x2cModel.blocks.sstartup.bTypeConv.Out;

    /* Block Park_Clarke_inv_SVM_MCHP                                                                                 */
    x2cModel.blocks.sSuperBlock.bPark_Clarke_inv_SVM_MCHP.d =
        &x2cModel.blocks.sSuperBlock.bSaturation1.Out;
    x2cModel.blocks.sSuperBlock.bPark_Clarke_inv_SVM_MCHP.q =
        &x2cModel.blocks.sSuperBlock.bSaturation.Out;
    x2cModel.blocks.sSuperBlock.bPark_Clarke_inv_SVM_MCHP.theta =
        &x2cModel.blocks.sstartup.bPosSwitch.Out;
    x2cModel.blocks.sSuperBlock.bPark_Clarke_inv_SVM_MCHP.forcedMode =
        &x2cModel.blocks.sSuperBlock.bNot.Out;
    x2cModel.blocks.sSuperBlock.bPark_Clarke_inv_SVM_MCHP.forcedValue =
        &x2cModel.blocks.sSuperBlock.bGain.Out;

    /* Block Saturation                                                                                               */
    x2cModel.blocks.sSuperBlock.bSaturation.In =
        &x2cModel.blocks.sSuperBlock.bManualSwitch1.Out;

    /* Block Saturation1                                                                                              */
    x2cModel.blocks.sSuperBlock.bSaturation1.In =
        &x2cModel.blocks.sSuperBlock.bManualSwitch.Out;

    /* Block Sin3Gen                                                                                                  */
    x2cModel.blocks.sSuperBlock.bSin3Gen.A =
        &x2cModel.blocks.sSuperBlock.bConstant.Out;
    x2cModel.blocks.sSuperBlock.bSin3Gen.f =
        &x2cModel.blocks.sSuperBlock.bConstant1.Out;

    /* Block Sub_flux                                                                                                 */
    x2cModel.blocks.sSuperBlock.bSub_flux.Plus =
        &x2cModel.blocks.sstartup.bIdRateLimiter.Out;
    x2cModel.blocks.sSuperBlock.bSub_flux.Minus =
        &x2cModel.blocks.sSuperBlock.bClarke_Park_MCHP.d;

    /* Block Sub_torque                                                                                               */
    x2cModel.blocks.sSuperBlock.bSub_torque.Plus =
        &x2cModel.blocks.sstartup.bLoopBreaker.Out;
    x2cModel.blocks.sSuperBlock.bSub_torque.Minus =
        &x2cModel.blocks.sSuperBlock.bClarke_Park_MCHP.q;

    /* Block VelSignalPatth                                                                                           */
    x2cModel.blocks.bVelSignalPatth.In1 =
        &x2cModel.inports.bQEI_VEL;
    x2cModel.blocks.bVelSignalPatth.In2 =
        &x2cModel.blocks.bLoopBreaker.Out;

    /* Block Constant                                                                                                 */

    /* Block Constant1                                                                                                */

    /* Block Constant2                                                                                                */

    /* Block Constant3                                                                                                */

    /* Block Constant5                                                                                                */

    /* Block Flux_select                                                                                              */
    x2cModel.blocks.sstartup.bFlux_select.In1 =
        &x2cModel.blocks.sstartup.bRamp_Up_Current.Out;
    x2cModel.blocks.sstartup.bFlux_select.Switch =
        &x2cModel.blocks.sstartup.bSequencer.Out1;
    x2cModel.blocks.sstartup.bFlux_select.In3 =
        &x2cModel.blocks.sstartup.bConstant3.Out;

    /* Block Flux_select1                                                                                             */
    x2cModel.blocks.sstartup.bFlux_select1.In1 =
        &x2cModel.blocks.sstartup.bConstant3.Out;
    x2cModel.blocks.sstartup.bFlux_select1.Switch =
        &x2cModel.blocks.sstartup.bManualSwitch.Out;
    x2cModel.blocks.sstartup.bFlux_select1.In3 =
        &x2cModel.blocks.sstartup.bFlux_select.Out;

    /* Block IdRateLimiter                                                                                            */
    x2cModel.blocks.sstartup.bIdRateLimiter.In =
        &x2cModel.blocks.sstartup.bFlux_select1.Out;
    x2cModel.blocks.sstartup.bIdRateLimiter.Init =
        &x2cModel.blocks.sstartup.bConstant3.Out;
    x2cModel.blocks.sstartup.bIdRateLimiter.Enable =
        &x2cModel.blocks.sstartup.bConstant5.Out;

    /* Block Iq_select                                                                                                */
    x2cModel.blocks.sstartup.bIq_select.In1 =
        &x2cModel.blocks.sSpeed_PI.sSuperBlock.bRateLimiter.Out;
    x2cModel.blocks.sstartup.bIq_select.Switch =
        &x2cModel.blocks.sstartup.bManualSwitch.Out;
    x2cModel.blocks.sstartup.bIq_select.In3 =
        &x2cModel.blocks.sstartup.bPI.Out;

    /* Block LoopBreaker                                                                                              */
    x2cModel.blocks.sstartup.bLoopBreaker.In =
        &x2cModel.blocks.sstartup.bIq_select.Out;

    /* Block LoopBreaker1                                                                                             */
    x2cModel.blocks.sstartup.bLoopBreaker1.In =
        &x2cModel.blocks.sstartup.bTypeConv1.Out;

    /* Block ManualSwitch                                                                                             */
    x2cModel.blocks.sstartup.bManualSwitch.In1 =
        &x2cModel.blocks.sstartup.bSequencer.Out4;
    x2cModel.blocks.sstartup.bManualSwitch.In2 =
        &x2cModel.blocks.sstartup.bConstant.Out;

    /* Block ManualSwitch1                                                                                            */
    x2cModel.blocks.sstartup.bManualSwitch1.In1 =
        &x2cModel.blocks.sstartup.bSequencer.Out3;
    x2cModel.blocks.sstartup.bManualSwitch1.In2 =
        &x2cModel.blocks.sstartup.bConstant2.Out;

    /* Block PI                                                                                                       */
    x2cModel.blocks.sstartup.bPI.In =
        &x2cModel.blocks.sstartup.bPosError.Out;
    x2cModel.blocks.sstartup.bPI.Init =
        &x2cModel.blocks.sstartup.bConstant1.Out;
    x2cModel.blocks.sstartup.bPI.Enable =
        &x2cModel.blocks.sstartup.bTypeConv2.Out;

    /* Block PosError                                                                                                 */
    x2cModel.blocks.sstartup.bPosError.Plus =
        &x2cModel.blocks.sstartup.sSuperBlock.bRamp_Up_PositionGenerator.Out;
    x2cModel.blocks.sstartup.bPosError.Minus =
        &x2cModel.blocks.bPosSignalPath.Out;

    /* Block PosSwitch                                                                                                */
    x2cModel.blocks.sstartup.bPosSwitch.In1 =
        &x2cModel.blocks.bPosSignalPath.Out;
    x2cModel.blocks.sstartup.bPosSwitch.Switch =
        &x2cModel.blocks.sstartup.bManualSwitch.Out;
    x2cModel.blocks.sstartup.bPosSwitch.In3 =
        &x2cModel.blocks.sstartup.sSuperBlock.bRamp_Up_PositionGenerator.Out;

    /* Block Ramp_Up_Current                                                                                          */

    /* Block Sequencer                                                                                                */
    x2cModel.blocks.sstartup.bSequencer.Start =
        &x2cModel.inports.bSW2;

    /* Block Constant4                                                                                                */

    /* Block I                                                                                                        */
    x2cModel.blocks.sstartup.sSuperBlock.bI.In =
        &x2cModel.blocks.sstartup.sSuperBlock.bMult.Out;
    x2cModel.blocks.sstartup.sSuperBlock.bI.I0 =
        &x2cModel.blocks.sstartup.sSuperBlock.bI_Init_Zero.Out;
    x2cModel.blocks.sstartup.sSuperBlock.bI.Enable =
        &x2cModel.blocks.sstartup.sSuperBlock.bTypeConv.Out;

    /* Block I_Init_Zero                                                                                              */

    /* Block I_Init_Zero1                                                                                             */

    /* Block Mult                                                                                                     */
    x2cModel.blocks.sstartup.sSuperBlock.bMult.In1 =
        &x2cModel.blocks.sstartup.sSuperBlock.bConstant4.Out;
    x2cModel.blocks.sstartup.sSuperBlock.bMult.In2 =
        &x2cModel.blocks.sstartup.sSuperBlock.bSign.Out;

    /* Block Ramp_Up_PositionGenerator                                                                                */
    x2cModel.blocks.sstartup.sSuperBlock.bRamp_Up_PositionGenerator.In =
        &x2cModel.blocks.sstartup.sSuperBlock.bSaturation.Out;
    x2cModel.blocks.sstartup.sSuperBlock.bRamp_Up_PositionGenerator.Init =
        &x2cModel.blocks.sstartup.sSuperBlock.bI_Init_Zero1.Out;
    x2cModel.blocks.sstartup.sSuperBlock.bRamp_Up_PositionGenerator.Enable =
        &x2cModel.blocks.sstartup.sSuperBlock.bTypeConv.Out;

    /* Block Saturation                                                                                               */
    x2cModel.blocks.sstartup.sSuperBlock.bSaturation.In =
        &x2cModel.blocks.sstartup.sSuperBlock.bI.Out;

    /* Block Sign                                                                                                     */
    x2cModel.blocks.sstartup.sSuperBlock.bSign.In =
        &x2cModel.blocks.bGain.Out;

    /* Block TypeConv                                                                                                 */
    x2cModel.blocks.sstartup.sSuperBlock.bTypeConv.In =
        &x2cModel.blocks.sstartup.bSequencer.Out2;

    /* Block TypeConv                                                                                                 */
    x2cModel.blocks.sstartup.bTypeConv.In =
        &x2cModel.blocks.sstartup.bSequencer.Out2;

    /* Block TypeConv1                                                                                                */
    x2cModel.blocks.sstartup.bTypeConv1.In =
        &x2cModel.blocks.sstartup.bManualSwitch.Out;

    /* Block TypeConv2                                                                                                */
    x2cModel.blocks.sstartup.bTypeConv2.In =
        &x2cModel.blocks.sstartup.bManualSwitch1.Out;

    /******************************************************************************************************************/
    /**                                                 Link Outports                                                **/
    /******************************************************************************************************************/
    x2cModel.outports.bHOME_INIT =
        &x2cModel.blocks.bNot.Out;
    x2cModel.outports.bLED1 =
        &x2cModel.inports.bSW1;
    x2cModel.outports.bLED2 =
        &x2cModel.inports.bSW2;
    x2cModel.outports.bPWM1 =
        &x2cModel.blocks.sSuperBlock.bManualSwitch2.Out;
    x2cModel.outports.bPWM2 =
        &x2cModel.blocks.sSuperBlock.bManualSwitch3.Out;
    x2cModel.outports.bPWM3 =
        &x2cModel.blocks.sSuperBlock.bManualSwitch5.Out;
    x2cModel.outports.sSuperBlock.bEstimated_angle =
        &x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP.theta;
    x2cModel.outports.sSuperBlock.bEstimated_speed =
        &x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP.speed;

    /******************************************************************************************************************/
    /**                                           Run Block Init Functions                                           **/
    /******************************************************************************************************************/
    Gain_FiP16_Init(&x2cModel.blocks.bGain);
    LoopBreaker_FiP16_Init(&x2cModel.blocks.bLoopBreaker);
    LoopBreaker_FiP16_Init(&x2cModel.blocks.bLoopBreaker1);
    Not_Bool_Init(&x2cModel.blocks.bNot);
    ManualSwitch_FiP16_Init(&x2cModel.blocks.bPosSignalPath);
    Constant_FiP16_Init(&x2cModel.blocks.sSpeed_PI.bConstant);
    Constant_FiP16_Init(&x2cModel.blocks.sSpeed_PI.bConstant1);
    ManualSwitch_FiP16_Init(&x2cModel.blocks.sSpeed_PI.bManualSwitch);
    PI_FiP16_Init(&x2cModel.blocks.sSpeed_PI.bPI_speed);
    RateLimiter_FiP16_Init(&x2cModel.blocks.sSpeed_PI.bRateLimiter);
    Sub_FiP16_Init(&x2cModel.blocks.sSpeed_PI.bSpeed_error);
    Add_FiP16_Init(&x2cModel.blocks.sSpeed_PI.sSuperBlock.bAdd);
    AutoSwitch_FiP16_Init(&x2cModel.blocks.sSpeed_PI.sSuperBlock.bAutoSwitch);
    Constant_FiP16_Init(&x2cModel.blocks.sSpeed_PI.sSuperBlock.bConstant);
    Constant_FiP16_Init(&x2cModel.blocks.sSpeed_PI.sSuperBlock.bConstant1);
    Constant_Bool_Init(&x2cModel.blocks.sSpeed_PI.sSuperBlock.bConstant2);
    Constant_FiP16_Init(&x2cModel.blocks.sSpeed_PI.sSuperBlock.bConstant3);
    Gain_FiP16_Init(&x2cModel.blocks.sSpeed_PI.sSuperBlock.bGain);
    RateLimiter_FiP16_Init(&x2cModel.blocks.sSpeed_PI.sSuperBlock.bRateLimiter);
    SinGen_FiP16_Init(&x2cModel.blocks.sSpeed_PI.sSuperBlock.bSinGen);
    BEMF_PLL_MCHP_FiP16_Init(&x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP);
    Clarke_Park_MCHP_FiP16_Init(&x2cModel.blocks.sSuperBlock.bClarke_Park_MCHP);
    Constant_FiP16_Init(&x2cModel.blocks.sSuperBlock.bConstant);
    Constant_FiP16_Init(&x2cModel.blocks.sSuperBlock.bConstant1);
    Gain_FiP16_Init(&x2cModel.blocks.sSuperBlock.bGain);
    Gain_FiP16_Init(&x2cModel.blocks.sSuperBlock.bGain2);
    Gain_FiP16_Init(&x2cModel.blocks.sSuperBlock.bGain3);
    ManualSwitch_FiP16_Init(&x2cModel.blocks.sSuperBlock.bManualSwitch);
    ManualSwitch_FiP16_Init(&x2cModel.blocks.sSuperBlock.bManualSwitch1);
    ManualSwitch_FiP16_Init(&x2cModel.blocks.sSuperBlock.bManualSwitch2);
    ManualSwitch_FiP16_Init(&x2cModel.blocks.sSuperBlock.bManualSwitch3);
    ManualSwitch_FiP16_Init(&x2cModel.blocks.sSuperBlock.bManualSwitch5);
    Not_Bool_Init(&x2cModel.blocks.sSuperBlock.bNot);
    Constant_FiP16_Init(&x2cModel.blocks.sSuperBlock.bOpenLoop_Vd);
    Constant_FiP16_Init(&x2cModel.blocks.sSuperBlock.bOpenLoop_Vq);
    PI_FiP16_Init(&x2cModel.blocks.sSuperBlock.bPI_flux);
    PI_FiP16_Init(&x2cModel.blocks.sSuperBlock.bPI_torque);
    Park_Clarke_inv_SVM_MCHP_FiP16_Init(&x2cModel.blocks.sSuperBlock.bPark_Clarke_inv_SVM_MCHP);
    Saturation_FiP16_Init(&x2cModel.blocks.sSuperBlock.bSaturation);
    Saturation_FiP16_Init(&x2cModel.blocks.sSuperBlock.bSaturation1);
    Sin3Gen_FiP16_Init(&x2cModel.blocks.sSuperBlock.bSin3Gen);
    Sub_FiP16_Init(&x2cModel.blocks.sSuperBlock.bSub_flux);
    Sub_FiP16_Init(&x2cModel.blocks.sSuperBlock.bSub_torque);
    ManualSwitch_FiP16_Init(&x2cModel.blocks.bVelSignalPatth);
    Constant_FiP16_Init(&x2cModel.blocks.sstartup.bConstant);
    Constant_FiP16_Init(&x2cModel.blocks.sstartup.bConstant1);
    Constant_FiP16_Init(&x2cModel.blocks.sstartup.bConstant2);
    Constant_FiP16_Init(&x2cModel.blocks.sstartup.bConstant3);
    Constant_Bool_Init(&x2cModel.blocks.sstartup.bConstant5);
    AutoSwitch_FiP16_Init(&x2cModel.blocks.sstartup.bFlux_select);
    AutoSwitch_FiP16_Init(&x2cModel.blocks.sstartup.bFlux_select1);
    RateLimiter_FiP16_Init(&x2cModel.blocks.sstartup.bIdRateLimiter);
    AutoSwitch_FiP16_Init(&x2cModel.blocks.sstartup.bIq_select);
    LoopBreaker_FiP16_Init(&x2cModel.blocks.sstartup.bLoopBreaker);
    LoopBreaker_Bool_Init(&x2cModel.blocks.sstartup.bLoopBreaker1);
    ManualSwitch_FiP16_Init(&x2cModel.blocks.sstartup.bManualSwitch);
    ManualSwitch_FiP16_Init(&x2cModel.blocks.sstartup.bManualSwitch1);
    PI_FiP16_Init(&x2cModel.blocks.sstartup.bPI);
    uSub_FiP16_Init(&x2cModel.blocks.sstartup.bPosError);
    AutoSwitch_FiP16_Init(&x2cModel.blocks.sstartup.bPosSwitch);
    Constant_FiP16_Init(&x2cModel.blocks.sstartup.bRamp_Up_Current);
    Sequencer_FiP16_Init(&x2cModel.blocks.sstartup.bSequencer);
    Constant_FiP16_Init(&x2cModel.blocks.sstartup.sSuperBlock.bConstant4);
    I_FiP16_Init(&x2cModel.blocks.sstartup.sSuperBlock.bI);
    Constant_FiP16_Init(&x2cModel.blocks.sstartup.sSuperBlock.bI_Init_Zero);
    Constant_FiP16_Init(&x2cModel.blocks.sstartup.sSuperBlock.bI_Init_Zero1);
    Mult_FiP16_Init(&x2cModel.blocks.sstartup.sSuperBlock.bMult);
    uI_FiP16_Init(&x2cModel.blocks.sstartup.sSuperBlock.bRamp_Up_PositionGenerator);
    Saturation_FiP16_Init(&x2cModel.blocks.sstartup.sSuperBlock.bSaturation);
    Sign_FiP16_Init(&x2cModel.blocks.sstartup.sSuperBlock.bSign);
    TypeConv_FiP16_Bool_Init(&x2cModel.blocks.sstartup.sSuperBlock.bTypeConv);
    TypeConv_FiP16_Bool_Init(&x2cModel.blocks.sstartup.bTypeConv);
    TypeConv_FiP16_Bool_Init(&x2cModel.blocks.sstartup.bTypeConv1);
    TypeConv_FiP16_Bool_Init(&x2cModel.blocks.sstartup.bTypeConv2);
    Scope_Main_Init(&x2cScope);

    /* Initialize TableStruct tables                                                                                  */
    TableStruct->TFncTable = blockFunctionTable;
    TableStruct->TParamTable = parameterIdTable;
    TableStruct->inportParamTable = inportParamIdTable;
    TableStruct->outportParamTable = outportParamIdTable;
    TableStruct->maskParameterTable = maskParamIdTable;
}

/**********************************************************************************************************************/
/**                                            Run Block Update Functions                                            **/
/**********************************************************************************************************************/
static uint16 cnt_10 = X2C_UPDATE_10_DIVIDER - 1;
void X2C_Update(void)
{
    X2C_Update_1();
    if (cnt_10 == 0)
    {
        cnt_10 = X2C_UPDATE_10_DIVIDER;
        X2C_Update_10();
    }

    cnt_10--;
}

/* X2C_Update for blocks with 1*Ts                                                                                    */
void X2C_Update_1(void)
{
    LoopBreaker_FiP16_Update(&x2cModel.blocks.bLoopBreaker1);
    LoopBreaker_FiP16_Update(&x2cModel.blocks.sstartup.bLoopBreaker);
    Gain_FiP16_Update(&x2cModel.blocks.bGain);
    Sign_FiP16_Update(&x2cModel.blocks.sstartup.sSuperBlock.bSign);
    Mult_FiP16_Update(&x2cModel.blocks.sstartup.sSuperBlock.bMult);
    Sequencer_FiP16_Update(&x2cModel.blocks.sstartup.bSequencer);
    ManualSwitch_FiP16_Update(&x2cModel.blocks.bPosSignalPath);
    AutoSwitch_FiP16_Update(&x2cModel.blocks.sstartup.bFlux_select);
    ManualSwitch_FiP16_Update(&x2cModel.blocks.sstartup.bManualSwitch);
    TypeConv_FiP16_Bool_Update(&x2cModel.blocks.sstartup.sSuperBlock.bTypeConv);
    TypeConv_FiP16_Bool_Update(&x2cModel.blocks.sstartup.bTypeConv);
    Not_Bool_Update(&x2cModel.blocks.sSuperBlock.bNot);
    AutoSwitch_FiP16_Update(&x2cModel.blocks.sstartup.bFlux_select1);
    ManualSwitch_FiP16_Update(&x2cModel.blocks.sstartup.bManualSwitch1);
    I_FiP16_Update(&x2cModel.blocks.sstartup.sSuperBlock.bI);
    Sin3Gen_FiP16_Update(&x2cModel.blocks.sSuperBlock.bSin3Gen);
    RateLimiter_FiP16_Update(&x2cModel.blocks.sstartup.bIdRateLimiter);
    Saturation_FiP16_Update(&x2cModel.blocks.sstartup.sSuperBlock.bSaturation);
    TypeConv_FiP16_Bool_Update(&x2cModel.blocks.sstartup.bTypeConv2);
    Not_Bool_Update(&x2cModel.blocks.bNot);
    Gain_FiP16_Update(&x2cModel.blocks.sSuperBlock.bGain);
    uI_FiP16_Update(&x2cModel.blocks.sstartup.sSuperBlock.bRamp_Up_PositionGenerator);
    uSub_FiP16_Update(&x2cModel.blocks.sstartup.bPosError);
    AutoSwitch_FiP16_Update(&x2cModel.blocks.sstartup.bPosSwitch);
    Clarke_Park_MCHP_FiP16_Update(&x2cModel.blocks.sSuperBlock.bClarke_Park_MCHP);
    PI_FiP16_Update(&x2cModel.blocks.sstartup.bPI);
    Sub_FiP16_Update(&x2cModel.blocks.sSuperBlock.bSub_flux);
    Sub_FiP16_Update(&x2cModel.blocks.sSuperBlock.bSub_torque);
    PI_FiP16_Update(&x2cModel.blocks.sSuperBlock.bPI_flux);
    PI_FiP16_Update(&x2cModel.blocks.sSuperBlock.bPI_torque);
    ManualSwitch_FiP16_Update(&x2cModel.blocks.sSuperBlock.bManualSwitch);
    ManualSwitch_FiP16_Update(&x2cModel.blocks.sSuperBlock.bManualSwitch1);
    Saturation_FiP16_Update(&x2cModel.blocks.sSuperBlock.bSaturation);
    Saturation_FiP16_Update(&x2cModel.blocks.sSuperBlock.bSaturation1);
    Park_Clarke_inv_SVM_MCHP_FiP16_Update(&x2cModel.blocks.sSuperBlock.bPark_Clarke_inv_SVM_MCHP);
    Gain_FiP16_Update(&x2cModel.blocks.sSuperBlock.bGain2);
    Gain_FiP16_Update(&x2cModel.blocks.sSuperBlock.bGain3);
    ManualSwitch_FiP16_Update(&x2cModel.blocks.sSuperBlock.bManualSwitch2);
    ManualSwitch_FiP16_Update(&x2cModel.blocks.sSuperBlock.bManualSwitch3);
    ManualSwitch_FiP16_Update(&x2cModel.blocks.sSuperBlock.bManualSwitch5);
    BEMF_PLL_MCHP_FiP16_Update(&x2cModel.blocks.sSuperBlock.bBEMF_PLL_MCHP);
    AutoSwitch_FiP16_Update(&x2cModel.blocks.sstartup.bIq_select);
    Scope_Main_Update(&x2cScope);
}

/* X2C_Update for blocks with 10*Ts                                                                                   */
void X2C_Update_10(void)
{
    LoopBreaker_FiP16_Update(&x2cModel.blocks.bLoopBreaker);
    LoopBreaker_Bool_Update(&x2cModel.blocks.sstartup.bLoopBreaker1);
    SinGen_FiP16_Update(&x2cModel.blocks.sSpeed_PI.sSuperBlock.bSinGen);
    Gain_FiP16_Update(&x2cModel.blocks.sSpeed_PI.sSuperBlock.bGain);
    AutoSwitch_FiP16_Update(&x2cModel.blocks.sSpeed_PI.sSuperBlock.bAutoSwitch);
    TypeConv_FiP16_Bool_Update(&x2cModel.blocks.sstartup.bTypeConv1);
    ManualSwitch_FiP16_Update(&x2cModel.blocks.bVelSignalPatth);
    RateLimiter_FiP16_Update(&x2cModel.blocks.sSpeed_PI.bRateLimiter);
    Sub_FiP16_Update(&x2cModel.blocks.sSpeed_PI.bSpeed_error);
    PI_FiP16_Update(&x2cModel.blocks.sSpeed_PI.bPI_speed);
    ManualSwitch_FiP16_Update(&x2cModel.blocks.sSpeed_PI.bManualSwitch);
    Add_FiP16_Update(&x2cModel.blocks.sSpeed_PI.sSuperBlock.bAdd);
    RateLimiter_FiP16_Update(&x2cModel.blocks.sSpeed_PI.sSuperBlock.bRateLimiter);
}

