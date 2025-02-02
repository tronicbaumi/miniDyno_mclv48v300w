/* This file is part of X2C. http://x2c.lcm.at/                                                                       */

/* Model: MC_FOC_DYNO_SAME54_MCLV_48V_300W                                                                            */
/* Date:  2024-09-11 10:58                                                                                            */

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

    /* Block: Average                                                                                                 */
    /* n = 8                                                                                                          */
    /* ts_fact = 1.0                                                                                                  */
    x2cModel.blocks.bAverage.n = 8;
    x2cModel.blocks.bAverage.sfrn = 3;
    x2cModel.blocks.bAverage.sum = 0;
    x2cModel.blocks.bAverage.count = 0;
    x2cModel.blocks.bAverage.avg = &RamTable_int16[0];

    /* Block: Dyno/Add                                                                                                */

    /* Block: Dyno/Add1                                                                                               */

    /* Block: Dyno/Add2                                                                                               */

    /* Block: Dyno/AutoSwitch                                                                                         */
    /* Thresh_up = 0.0                                                                                                */
    /* Thresh_down = 0.0                                                                                              */
    x2cModel.blocks.sDyno.bAutoSwitch.Thresh_up = 0;
    x2cModel.blocks.sDyno.bAutoSwitch.Thresh_down = 0;
    x2cModel.blocks.sDyno.bAutoSwitch.Status = &RamTable_int16[256];

    /* Block: Dyno/ConstT5                                                                                            */
    /* Value = 0.1                                                                                                    */
    x2cModel.blocks.sDyno.bConstT5.K = 3277;

    /* Block: Dyno/ConstT6                                                                                            */
    /* Value = 0.1                                                                                                    */
    x2cModel.blocks.sDyno.bConstT6.K = 3277;

    /* Block: Dyno/ConstT7                                                                                            */
    /* Value = 0.1                                                                                                    */
    x2cModel.blocks.sDyno.bConstT7.K = 3277;

    /* Block: Dyno/Constant                                                                                           */
    /* Value = 1.0                                                                                                    */
    x2cModel.blocks.sDyno.bConstant.K = 32767;

    /* Block: Dyno/Constant4                                                                                          */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.sDyno.bConstant4.K = 0;

    /* Block: Dyno/Constant6                                                                                          */
    /* Value = 1.0                                                                                                    */
    x2cModel.blocks.sDyno.bConstant6.K = 1;

    /* Block: Dyno/GainT5                                                                                             */
    /* Gain = 0.1                                                                                                     */
    x2cModel.blocks.sDyno.bGainT5.V = 3277;
    x2cModel.blocks.sDyno.bGainT5.sfr = 15;

    /* Block: Dyno/GainT6                                                                                             */
    /* Gain = 0.1                                                                                                     */
    x2cModel.blocks.sDyno.bGainT6.V = 3277;
    x2cModel.blocks.sDyno.bGainT6.sfr = 15;

    /* Block: Dyno/GainT7                                                                                             */
    /* Gain = 0.1                                                                                                     */
    x2cModel.blocks.sDyno.bGainT7.V = 3277;
    x2cModel.blocks.sDyno.bGainT7.sfr = 15;

    /* Block: Dyno/LookupTable                                                                                        */
    /* Lookup = [real 1x257 row vector]                                                                               */
    x2cModel.blocks.sDyno.bLookupTable.Table = &FlashTable_int16[0];

    /* Block: Dyno/LookupTable1                                                                                       */
    /* Lookup = [real 1x257 row vector]                                                                               */
    x2cModel.blocks.sDyno.bLookupTable1.Table = &FlashTable_int16[257];

    /* Block: Dyno/LookupTable2                                                                                       */
    /* Lookup = [real 1x257 row vector]                                                                               */
    x2cModel.blocks.sDyno.bLookupTable2.Table = &FlashTable_int16[514];

    /* Block: Dyno/Mult                                                                                               */

    /* Block: Dyno/Real2Int                                                                                           */
    /* Scale = 128.0                                                                                                  */
    x2cModel.blocks.sDyno.bReal2Int.scale = 1;

    /* Block: Dyno/Selector                                                                                           */

    /* Block: Dyno/SinGen1                                                                                            */
    /* fmax = 10.0                                                                                                    */
    /* Offset = 0.0                                                                                                   */
    /* Phase = 0.0                                                                                                    */
    /* ts_fact = 10.0                                                                                                 */
    x2cModel.blocks.sDyno.bSinGen1.delta_phi = 655;
    x2cModel.blocks.sDyno.bSinGen1.phase = 0;
    x2cModel.blocks.sDyno.bSinGen1.offset = 0;
    x2cModel.blocks.sDyno.bSinGen1.phi = 0;

    /* Block: Dyno/Sin_load                                                                                           */
    /* fmax = 10.0                                                                                                    */
    /* Offset = 0.25                                                                                                  */
    /* Phase = 0.0                                                                                                    */
    /* ts_fact = 10.0                                                                                                 */
    x2cModel.blocks.sDyno.bSin_load.delta_phi = 655;
    x2cModel.blocks.sDyno.bSin_load.phase = 0;
    x2cModel.blocks.sDyno.bSin_load.offset = 8192;
    x2cModel.blocks.sDyno.bSin_load.phi = 0;

    /* Block: Dyno/const_torque                                                                                       */
    /* Value = 0.1                                                                                                    */
    x2cModel.blocks.sDyno.bconst_torque.K = 3277;

    /* Block: Dyno/fan_gain                                                                                           */
    /* Gain = 2.0                                                                                                     */
    x2cModel.blocks.sDyno.bfan_gain.V = 16384;
    x2cModel.blocks.sDyno.bfan_gain.sfr = 13;

    /* Block: Dyno/sine_A                                                                                             */
    /* Value = 0.05                                                                                                   */
    x2cModel.blocks.sDyno.bsine_A.K = 1638;

    /* Block: Dyno/sine_F                                                                                             */
    /* Value = 0.06                                                                                                   */
    x2cModel.blocks.sDyno.bsine_F.K = 1966;

    /* Block: Dyno/switch_mech_el                                                                                     */
    /* Toggle = 1.0                                                                                                   */
    x2cModel.blocks.sDyno.bswitch_mech_el.Toggle = 1;

    /* Block: Dyno/t_load_f                                                                                           */
    /* Value = 0.3                                                                                                    */
    x2cModel.blocks.sDyno.bt_load_f.K = 9830;

    /* Block: Dyno/t_load_high                                                                                        */
    /* Value = 0.1                                                                                                    */
    x2cModel.blocks.sDyno.bt_load_high.K = 3277;

    /* Block: Dyno/t_load_low                                                                                         */
    /* Value = 0.05                                                                                                   */
    x2cModel.blocks.sDyno.bt_load_low.K = 1638;

    /* Block: Dyno/t_load_rate                                                                                        */
    /* Tr = 1.0                                                                                                       */
    /* Tf = 1.0                                                                                                       */
    /* ts_fact = 10.0                                                                                                 */
    x2cModel.blocks.sDyno.bt_load_rate.RateUp = 2147484;
    x2cModel.blocks.sDyno.bt_load_rate.RateDown = 2147484;
    x2cModel.blocks.sDyno.bt_load_rate.out_old = 0;
    x2cModel.blocks.sDyno.bt_load_rate.enable_old = 0;

    /* Block: Dyno/torque_mode                                                                                        */
    /* Value = 1.0                                                                                                    */
    x2cModel.blocks.sDyno.btorque_mode.K = 1;

    /* Block: DynoMotor                                                                                               */
    /* Toggle = 1.0                                                                                                   */
    x2cModel.blocks.bDynoMotor.Toggle = 1;

    /* Block: FOCmain/Add                                                                                             */

    /* Block: FOCmain/Clarke_Park_MCHP                                                                                */

    /* Block: FOCmain/Gain                                                                                            */
    /* Gain = 4.4                                                                                                     */
    x2cModel.blocks.sFOCmain.bGain.V = 4.4;

    /* Block: FOCmain/Gain1                                                                                           */
    /* Gain = -1.0                                                                                                    */
    x2cModel.blocks.sFOCmain.bGain1.V = -16384;
    x2cModel.blocks.sFOCmain.bGain1.sfr = 14;

    /* Block: FOCmain/Gain2                                                                                           */
    /* Gain = 4.4                                                                                                     */
    x2cModel.blocks.sFOCmain.bGain2.V = 4.4;

    /* Block: FOCmain/Gain3                                                                                           */
    /* Gain = 4.4                                                                                                     */
    x2cModel.blocks.sFOCmain.bGain3.V = 4.4;

    /* Block: FOCmain/Gain4                                                                                           */
    /* Gain = 12.0                                                                                                    */
    x2cModel.blocks.sFOCmain.bGain4.V = 12;

    /* Block: FOCmain/Gain5                                                                                           */
    /* Gain = 12.0                                                                                                    */
    x2cModel.blocks.sFOCmain.bGain5.V = 12;

    /* Block: FOCmain/Gain6                                                                                           */
    /* Gain = 12.0                                                                                                    */
    x2cModel.blocks.sFOCmain.bGain6.V = 12;

    /* Block: FOCmain/Int2Real                                                                                        */
    /* Scale = 1.0                                                                                                    */
    x2cModel.blocks.sFOCmain.bInt2Real.scale = 0.000030517578125;

    /* Block: FOCmain/Int2Real1                                                                                       */
    /* Scale = 1.0                                                                                                    */
    x2cModel.blocks.sFOCmain.bInt2Real1.scale = 0.000030517578125;

    /* Block: FOCmain/Int2Real2                                                                                       */
    /* Scale = 1.0                                                                                                    */
    x2cModel.blocks.sFOCmain.bInt2Real2.scale = 0.000030517578125;

    /* Block: FOCmain/Int2Real3                                                                                       */
    /* Scale = 1.0                                                                                                    */
    x2cModel.blocks.sFOCmain.bInt2Real3.scale = 0.000030517578125;

    /* Block: FOCmain/Int2Real4                                                                                       */
    /* Scale = 1.0                                                                                                    */
    x2cModel.blocks.sFOCmain.bInt2Real4.scale = 0.000030517578125;

    /* Block: FOCmain/Int2Real5                                                                                       */
    /* Scale = 1.0                                                                                                    */
    x2cModel.blocks.sFOCmain.bInt2Real5.scale = 0.000030517578125;

    /* Block: FOCmain/ManualSwitch                                                                                    */
    /* Toggle = 1.0                                                                                                   */
    x2cModel.blocks.sFOCmain.bManualSwitch.Toggle = 1;

    /* Block: FOCmain/ManualSwitch1                                                                                   */
    /* Toggle = 1.0                                                                                                   */
    x2cModel.blocks.sFOCmain.bManualSwitch1.Toggle = 1;

    /* Block: FOCmain/Mult                                                                                            */

    /* Block: FOCmain/Mult1                                                                                           */

    /* Block: FOCmain/Mult2                                                                                           */

    /* Block: FOCmain/Not                                                                                             */

    /* Block: FOCmain/OpenLoop_Vd                                                                                     */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.sFOCmain.bOpenLoop_Vd.K = 0;

    /* Block: FOCmain/OpenLoop_Vq                                                                                     */
    /* Value = 0.3                                                                                                    */
    x2cModel.blocks.sFOCmain.bOpenLoop_Vq.K = 9830;

    /* Block: FOCmain/PI_flux                                                                                         */
    /* Kp = 6.5                                                                                                       */
    /* Ki = 60.0                                                                                                      */
    /* ts_fact = 1.0                                                                                                  */
    x2cModel.blocks.sFOCmain.bPI_flux.b0 = 197;
    x2cModel.blocks.sFOCmain.bPI_flux.b1 = 26624;
    x2cModel.blocks.sFOCmain.bPI_flux.sfrb0 = 15;
    x2cModel.blocks.sFOCmain.bPI_flux.sfrb1 = 12;
    x2cModel.blocks.sFOCmain.bPI_flux.i_old = 0;
    x2cModel.blocks.sFOCmain.bPI_flux.enable_old = 0;

    /* Block: FOCmain/PI_torque                                                                                       */
    /* Kp = 6.5                                                                                                       */
    /* Ki = 60.0                                                                                                      */
    /* ts_fact = 1.0                                                                                                  */
    x2cModel.blocks.sFOCmain.bPI_torque.b0 = 197;
    x2cModel.blocks.sFOCmain.bPI_torque.b1 = 26624;
    x2cModel.blocks.sFOCmain.bPI_torque.sfrb0 = 15;
    x2cModel.blocks.sFOCmain.bPI_torque.sfrb1 = 12;
    x2cModel.blocks.sFOCmain.bPI_torque.i_old = 0;
    x2cModel.blocks.sFOCmain.bPI_torque.enable_old = 0;

    /* Block: FOCmain/Park_Clarke_inv_SVM_MCHP                                                                        */

    /* Block: FOCmain/Saturation                                                                                      */
    /* max = 0.98                                                                                                     */
    /* min = -0.98                                                                                                    */
    x2cModel.blocks.sFOCmain.bSaturation.max = 32113;
    x2cModel.blocks.sFOCmain.bSaturation.min = -32113;

    /* Block: FOCmain/Saturation1                                                                                     */
    /* max = 0.98                                                                                                     */
    /* min = -0.98                                                                                                    */
    x2cModel.blocks.sFOCmain.bSaturation1.max = 32113;
    x2cModel.blocks.sFOCmain.bSaturation1.min = -32113;

    /* Block: FOCmain/Sub_flux                                                                                        */

    /* Block: FOCmain/Sub_torque                                                                                      */

    /* Block: FOCmain/Sum                                                                                             */
    /* In1 = +                                                                                                        */
    /* In2 = +                                                                                                        */
    /* In3 = +                                                                                                        */
    /* In4 = 0                                                                                                        */
    /* In5 = 0                                                                                                        */
    /* In6 = 0                                                                                                        */
    /* In7 = 0                                                                                                        */
    /* In8 = 0                                                                                                        */
    x2cModel.blocks.sFOCmain.bSum.sign = 21;

    /* Block: FOCmain/TypeConv2                                                                                       */

    /* Block: FOCmain/breakPowerW                                                                                     */

    /* Block: FOCmain/forced_current                                                                                  */
    /* Value = 0.2                                                                                                    */
    x2cModel.blocks.sFOCmain.bforced_current.K = 6554;

    /* Block: FOCmain/forced_current1                                                                                 */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.sFOCmain.bforced_current1.K = 0;

    /* Block: FOCmain/theta_offset                                                                                    */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.sFOCmain.btheta_offset.K = 0;

    /* Block: FOCmain/uAdd                                                                                            */

    /* Block: Flux_SP1                                                                                                */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.bFlux_SP1.K = 0;

    /* Block: Motor/AutoSwitch                                                                                        */
    /* Thresh_up = 0.0                                                                                                */
    /* Thresh_down = 0.0                                                                                              */
    x2cModel.blocks.sMotor.bAutoSwitch.Thresh_up = 0;
    x2cModel.blocks.sMotor.bAutoSwitch.Thresh_down = 0;
    x2cModel.blocks.sMotor.bAutoSwitch.Status = &RamTable_int16[257];

    /* Block: Motor/Constant                                                                                          */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.sMotor.bConstant.K = 0;

    /* Block: Motor/Constant1                                                                                         */
    /* Value = 1.0                                                                                                    */
    x2cModel.blocks.sMotor.bConstant1.K = 32767;

    /* Block: Motor/Constant3                                                                                         */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.sMotor.bConstant3.K = 0;

    /* Block: Motor/Constant4                                                                                         */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.sMotor.bConstant4.K = 0;

    /* Block: Motor/Constant6                                                                                         */
    /* Value = 1.0                                                                                                    */
    x2cModel.blocks.sMotor.bConstant6.K = 1;

    /* Block: Motor/Gain                                                                                              */
    /* Gain = 1.0                                                                                                     */
    x2cModel.blocks.sMotor.bGain.V = 16384;
    x2cModel.blocks.sMotor.bGain.sfr = 14;

    /* Block: Motor/Gain1                                                                                             */
    /* Gain = -1.0                                                                                                    */
    x2cModel.blocks.sMotor.bGain1.V = -16384;
    x2cModel.blocks.sMotor.bGain1.sfr = 14;

    /* Block: Motor/Gain3                                                                                             */
    /* Gain = 0.4                                                                                                     */
    x2cModel.blocks.sMotor.bGain3.V = 13107;
    x2cModel.blocks.sMotor.bGain3.sfr = 15;

    /* Block: Motor/Int2Real                                                                                          */
    /* Scale = 1.0                                                                                                    */
    x2cModel.blocks.sMotor.bInt2Real.scale = 0.000030517578125;

    /* Block: Motor/MAX_SPEED                                                                                         */
    /* Gain = 3000.0                                                                                                  */
    x2cModel.blocks.sMotor.bMAX_SPEED.V = 3000;

    /* Block: Motor/ManualSwitch                                                                                      */
    /* Toggle = 1.0                                                                                                   */
    x2cModel.blocks.sMotor.bManualSwitch.Toggle = 1;

    /* Block: Motor/PILimit                                                                                           */
    /* Kp = 1.2                                                                                                       */
    /* Ki = 3.0                                                                                                       */
    /* ts_fact = 10.0                                                                                                 */
    x2cModel.blocks.sMotor.bPILimit.b0 = 98;
    x2cModel.blocks.sMotor.bPILimit.b1 = 19661;
    x2cModel.blocks.sMotor.bPILimit.sfrb0 = 15;
    x2cModel.blocks.sMotor.bPILimit.sfrb1 = 14;
    x2cModel.blocks.sMotor.bPILimit.i_old = 0;
    x2cModel.blocks.sMotor.bPILimit.enable_old = 0;

    /* Block: Motor/Real2Int                                                                                          */
    /* Scale = 128.0                                                                                                  */
    x2cModel.blocks.sMotor.bReal2Int.scale = 1;

    /* Block: Motor/Selector                                                                                          */

    /* Block: Motor/SinGen1                                                                                           */
    /* fmax = 100.0                                                                                                   */
    /* Offset = 0.0                                                                                                   */
    /* Phase = 0.0                                                                                                    */
    /* ts_fact = 10.0                                                                                                 */
    x2cModel.blocks.sMotor.bSinGen1.delta_phi = 6554;
    x2cModel.blocks.sMotor.bSinGen1.phase = 0;
    x2cModel.blocks.sMotor.bSinGen1.offset = 0;
    x2cModel.blocks.sMotor.bSinGen1.phi = 0;

    /* Block: Motor/SubSpeed                                                                                          */

    /* Block: Motor/SuperBlock/Constant2                                                                              */
    /* Value = 0.5                                                                                                    */
    x2cModel.blocks.sMotor.sSuperBlock.bConstant2.K = 16384;

    /* Block: Motor/SuperBlock/Gain2                                                                                  */
    /* Gain = 2.0                                                                                                     */
    x2cModel.blocks.sMotor.sSuperBlock.bGain2.V = 16384;
    x2cModel.blocks.sMotor.sSuperBlock.bGain2.sfr = 13;

    /* Block: Motor/SuperBlock/Sub                                                                                    */

    /* Block: Motor/TypeConv                                                                                          */

    /* Block: Motor/const_speed                                                                                       */
    /* Value = 0.38                                                                                                   */
    x2cModel.blocks.sMotor.bconst_speed.K = 12452;

    /* Block: Motor/const_speed1                                                                                      */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.sMotor.bconst_speed1.K = 0;

    /* Block: Motor/const_torque_motor                                                                                */
    /* Value = 0.05                                                                                                   */
    x2cModel.blocks.sMotor.bconst_torque_motor.K = 1638;

    /* Block: Motor/motor_torquemode                                                                                  */
    /* Toggle = 1.0                                                                                                   */
    x2cModel.blocks.sMotor.bmotor_torquemode.Toggle = 1;

    /* Block: Motor/omega_rpm                                                                                         */

    /* Block: Motor/speedPI_limit                                                                                     */
    /* Value = 0.99                                                                                                   */
    x2cModel.blocks.sMotor.bspeedPI_limit.K = 32440;

    /* Block: Motor/speed_mode                                                                                        */
    /* Value = 2.0                                                                                                    */
    x2cModel.blocks.sMotor.bspeed_mode.K = 2;

    /* Block: Motor/t_load_rate                                                                                       */
    /* Tr = 1.0                                                                                                       */
    /* Tf = 1.0                                                                                                       */
    /* ts_fact = 10.0                                                                                                 */
    x2cModel.blocks.sMotor.bt_load_rate.RateUp = 2147484;
    x2cModel.blocks.sMotor.bt_load_rate.RateDown = 2147484;
    x2cModel.blocks.sMotor.bt_load_rate.out_old = 0;
    x2cModel.blocks.sMotor.bt_load_rate.enable_old = 0;

    /* Block: Motor/t_speed_f                                                                                         */
    /* Value = 0.003                                                                                                  */
    x2cModel.blocks.sMotor.bt_speed_f.K = 98;

    /* Block: Motor/t_speed_high                                                                                      */
    /* Value = 0.6                                                                                                    */
    x2cModel.blocks.sMotor.bt_speed_high.K = 19661;

    /* Block: Motor/t_speed_low                                                                                       */
    /* Value = 0.1                                                                                                    */
    x2cModel.blocks.sMotor.bt_speed_low.K = 3277;

    /* Block: QEI_init/Gain1                                                                                          */
    /* Gain = -1.0e-4                                                                                                 */
    x2cModel.blocks.sQEI_init.bGain1.V = -3;
    x2cModel.blocks.sQEI_init.bGain1.sfr = 15;

    /* Block: QEI_init/Not                                                                                            */

    /* Block: QEI_init/TypeConv                                                                                       */

    /* Block: QEI_init/TypeConv1                                                                                      */

    /* Block: Sequencer                                                                                               */
    /* Delay1 = 0.3                                                                                                   */
    /* Delay2 = 0.6                                                                                                   */
    /* Delay3 = 0.0                                                                                                   */
    /* Delay4 = 0.0                                                                                                   */
    /* ts_fact = 1.0                                                                                                  */
    x2cModel.blocks.bSequencer.delay1 = 3000;
    x2cModel.blocks.bSequencer.delay2 = 6000;
    x2cModel.blocks.bSequencer.delay3 = 0;
    x2cModel.blocks.bSequencer.delay4 = 0;
    x2cModel.blocks.bSequencer.cnt = 0;
    x2cModel.blocks.bSequencer.start_old = 0;

    /* Block: dyno_quadrant/Abs                                                                                       */

    /* Block: dyno_quadrant/AutoSwitch                                                                                */
    /* Thresh_up = 0.06                                                                                               */
    /* Thresh_down = 0.02                                                                                             */
    x2cModel.blocks.sdyno_quadrant.bAutoSwitch.Thresh_up = 1966;
    x2cModel.blocks.sdyno_quadrant.bAutoSwitch.Thresh_down = 655;
    x2cModel.blocks.sdyno_quadrant.bAutoSwitch.Status = &RamTable_int16[258];

    /* Block: dyno_quadrant/Constant1                                                                                 */
    /* Value = 1.0                                                                                                    */
    x2cModel.blocks.sdyno_quadrant.bConstant1.K = 1;

    /* Block: dyno_quadrant/Constant2                                                                                 */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.sdyno_quadrant.bConstant2.K = 0;

    /* Block: dyno_quadrant/ManualSwitch3                                                                             */
    /* Toggle = 1.0                                                                                                   */
    x2cModel.blocks.sdyno_quadrant.bManualSwitch3.Toggle = 1;

    /* Block: dyno_quadrant/Mult1                                                                                     */

    /* Block: dyno_quadrant/Mult2                                                                                     */

    /* Block: dyno_quadrant/Negation                                                                                  */

    /* Block: dyno_quadrant/RateLimiter                                                                               */
    /* Tr = 0.0                                                                                                       */
    /* Tf = 0.0                                                                                                       */
    /* ts_fact = 1.0                                                                                                  */
    x2cModel.blocks.sdyno_quadrant.bRateLimiter.RateUp = 2147483647;
    x2cModel.blocks.sdyno_quadrant.bRateLimiter.RateDown = 2147483647;
    x2cModel.blocks.sdyno_quadrant.bRateLimiter.out_old = 0;
    x2cModel.blocks.sdyno_quadrant.bRateLimiter.enable_old = 0;

    /* Block: dyno_quadrant/Saturation                                                                                */
    /* max = 1.0                                                                                                      */
    /* min = -1.0                                                                                                     */
    x2cModel.blocks.sdyno_quadrant.bSaturation.max = 32767;
    x2cModel.blocks.sdyno_quadrant.bSaturation.min = -32767;

    /* Block: dyno_quadrant/Sign1                                                                                     */

    /* Block: dyno_quadrant/SpeedAverage                                                                              */
    /* n = 64                                                                                                         */
    /* ts_fact = 1.0                                                                                                  */
    x2cModel.blocks.sdyno_quadrant.bSpeedAverage.n = 64;
    x2cModel.blocks.sdyno_quadrant.bSpeedAverage.sfrn = 6;
    x2cModel.blocks.sdyno_quadrant.bSpeedAverage.sum = 0;
    x2cModel.blocks.sdyno_quadrant.bSpeedAverage.count = 0;
    x2cModel.blocks.sdyno_quadrant.bSpeedAverage.avg = &RamTable_int16[259];

    /* Block: dyno_quadrant/Torque_SP                                                                                 */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.sdyno_quadrant.bTorque_SP.K = 0;


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
    x2cModel.inports.bQEI_POS_MECH = (int16)0;
    x2cModel.inports.bQEI_VEL = (int16)0;
    x2cModel.inports.bS2 = (int16)0;
    x2cModel.inports.bS3 = (int16)0;
    x2cModel.inports.bV_DCLINK = (int16)0;
    x2cModel.inports.bV_POT = (int16)0;

    /******************************************************************************************************************/
    /**                                               Link Block Inputs                                              **/
    /******************************************************************************************************************/

    /* Block Average                                                                                                  */
    x2cModel.blocks.bAverage.In =
        &x2cModel.inports.bV_POT;

    /* Block Add                                                                                                      */
    x2cModel.blocks.sDyno.bAdd.In1 =
        &x2cModel.blocks.sDyno.bGainT5.Out;
    x2cModel.blocks.sDyno.bAdd.In2 =
        &x2cModel.blocks.sDyno.bConstT5.Out;

    /* Block Add1                                                                                                     */
    x2cModel.blocks.sDyno.bAdd1.In1 =
        &x2cModel.blocks.sDyno.bGainT6.Out;
    x2cModel.blocks.sDyno.bAdd1.In2 =
        &x2cModel.blocks.sDyno.bConstT6.Out;

    /* Block Add2                                                                                                     */
    x2cModel.blocks.sDyno.bAdd2.In1 =
        &x2cModel.blocks.sDyno.bGainT7.Out;
    x2cModel.blocks.sDyno.bAdd2.In2 =
        &x2cModel.blocks.sDyno.bConstT7.Out;

    /* Block AutoSwitch                                                                                               */
    x2cModel.blocks.sDyno.bAutoSwitch.In1 =
        &x2cModel.blocks.sDyno.bt_load_high.Out;
    x2cModel.blocks.sDyno.bAutoSwitch.Switch =
        &x2cModel.blocks.sDyno.bSinGen1.u;
    x2cModel.blocks.sDyno.bAutoSwitch.In3 =
        &x2cModel.blocks.sDyno.bt_load_low.Out;

    /* Block ConstT5                                                                                                  */

    /* Block ConstT6                                                                                                  */

    /* Block ConstT7                                                                                                  */

    /* Block Constant                                                                                                 */

    /* Block Constant4                                                                                                */

    /* Block Constant6                                                                                                */

    /* Block GainT5                                                                                                   */
    x2cModel.blocks.sDyno.bGainT5.In =
        &x2cModel.blocks.sDyno.bLookupTable.Out;

    /* Block GainT6                                                                                                   */
    x2cModel.blocks.sDyno.bGainT6.In =
        &x2cModel.blocks.sDyno.bLookupTable1.Out;

    /* Block GainT7                                                                                                   */
    x2cModel.blocks.sDyno.bGainT7.In =
        &x2cModel.blocks.sDyno.bLookupTable2.Out;

    /* Block LookupTable                                                                                              */
    x2cModel.blocks.sDyno.bLookupTable.In =
        &x2cModel.blocks.sDyno.bswitch_mech_el.Out;

    /* Block LookupTable1                                                                                             */
    x2cModel.blocks.sDyno.bLookupTable1.In =
        &x2cModel.blocks.sDyno.bswitch_mech_el.Out;

    /* Block LookupTable2                                                                                             */
    x2cModel.blocks.sDyno.bLookupTable2.In =
        &x2cModel.blocks.sDyno.bswitch_mech_el.Out;

    /* Block Mult                                                                                                     */
    x2cModel.blocks.sDyno.bMult.In1 =
        &x2cModel.inports.bQEI_VEL;
    x2cModel.blocks.sDyno.bMult.In2 =
        &x2cModel.inports.bQEI_VEL;

    /* Block Real2Int                                                                                                 */
    x2cModel.blocks.sDyno.bReal2Int.In =
        &x2cModel.blocks.sDyno.btorque_mode.Out;

    /* Block Selector                                                                                                 */
    x2cModel.blocks.sDyno.bSelector.In0 =
        &x2cModel.blocks.bAverage.Out;
    x2cModel.blocks.sDyno.bSelector.In1 =
        &x2cModel.blocks.sDyno.bconst_torque.Out;
    x2cModel.blocks.sDyno.bSelector.In2 =
        &x2cModel.blocks.sDyno.bt_load_rate.Out;
    x2cModel.blocks.sDyno.bSelector.In3 =
        &x2cModel.blocks.sDyno.bfan_gain.Out;
    x2cModel.blocks.sDyno.bSelector.In4 =
        &x2cModel.blocks.sDyno.bSin_load.u;
    x2cModel.blocks.sDyno.bSelector.In5 =
        &x2cModel.blocks.sDyno.bAdd.Out;
    x2cModel.blocks.sDyno.bSelector.In6 =
        &x2cModel.blocks.sDyno.bAdd1.Out;
    x2cModel.blocks.sDyno.bSelector.In7 =
        &x2cModel.blocks.sDyno.bAdd2.Out;
    x2cModel.blocks.sDyno.bSelector.Select =
        &x2cModel.blocks.sDyno.bReal2Int.Out;

    /* Block SinGen1                                                                                                  */
    x2cModel.blocks.sDyno.bSinGen1.A =
        &x2cModel.blocks.sDyno.bConstant.Out;
    x2cModel.blocks.sDyno.bSinGen1.f =
        &x2cModel.blocks.sDyno.bt_load_f.Out;

    /* Block Sin_load                                                                                                 */
    x2cModel.blocks.sDyno.bSin_load.A =
        &x2cModel.blocks.sDyno.bsine_A.Out;
    x2cModel.blocks.sDyno.bSin_load.f =
        &x2cModel.blocks.sDyno.bsine_F.Out;

    /* Block const_torque                                                                                             */

    /* Block fan_gain                                                                                                 */
    x2cModel.blocks.sDyno.bfan_gain.In =
        &x2cModel.blocks.sDyno.bMult.Out;

    /* Block sine_A                                                                                                   */

    /* Block sine_F                                                                                                   */

    /* Block switch_mech_el                                                                                           */
    x2cModel.blocks.sDyno.bswitch_mech_el.In1 =
        &x2cModel.inports.bQEI_POS;
    x2cModel.blocks.sDyno.bswitch_mech_el.In2 =
        &x2cModel.inports.bQEI_POS_MECH;

    /* Block t_load_f                                                                                                 */

    /* Block t_load_high                                                                                              */

    /* Block t_load_low                                                                                               */

    /* Block t_load_rate                                                                                              */
    x2cModel.blocks.sDyno.bt_load_rate.In =
        &x2cModel.blocks.sDyno.bAutoSwitch.Out;
    x2cModel.blocks.sDyno.bt_load_rate.Init =
        &x2cModel.blocks.sDyno.bConstant4.Out;
    x2cModel.blocks.sDyno.bt_load_rate.Enable =
        &x2cModel.blocks.sDyno.bConstant6.Out;

    /* Block torque_mode                                                                                              */

    /* Block DynoMotor                                                                                                */
    x2cModel.blocks.bDynoMotor.In1 =
        &x2cModel.blocks.sMotor.bGain.Out;
    x2cModel.blocks.bDynoMotor.In2 =
        &x2cModel.blocks.sdyno_quadrant.bRateLimiter.Out;

    /* Block Add                                                                                                      */
    x2cModel.blocks.sFOCmain.bAdd.In1 =
        &x2cModel.inports.bI_b;
    x2cModel.blocks.sFOCmain.bAdd.In2 =
        &x2cModel.inports.bI_a;

    /* Block Clarke_Park_MCHP                                                                                         */
    x2cModel.blocks.sFOCmain.bClarke_Park_MCHP.a =
        &x2cModel.inports.bI_a;
    x2cModel.blocks.sFOCmain.bClarke_Park_MCHP.b =
        &x2cModel.inports.bI_b;
    x2cModel.blocks.sFOCmain.bClarke_Park_MCHP.theta =
        &x2cModel.blocks.sFOCmain.buAdd.Out;

    /* Block Gain                                                                                                     */
    x2cModel.blocks.sFOCmain.bGain.In =
        &x2cModel.blocks.sFOCmain.bInt2Real.Out;

    /* Block Gain1                                                                                                    */
    x2cModel.blocks.sFOCmain.bGain1.In =
        &x2cModel.blocks.sFOCmain.bAdd.Out;

    /* Block Gain2                                                                                                    */
    x2cModel.blocks.sFOCmain.bGain2.In =
        &x2cModel.blocks.sFOCmain.bInt2Real1.Out;

    /* Block Gain3                                                                                                    */
    x2cModel.blocks.sFOCmain.bGain3.In =
        &x2cModel.blocks.sFOCmain.bInt2Real3.Out;

    /* Block Gain4                                                                                                    */
    x2cModel.blocks.sFOCmain.bGain4.In =
        &x2cModel.blocks.sFOCmain.bInt2Real2.Out;

    /* Block Gain5                                                                                                    */
    x2cModel.blocks.sFOCmain.bGain5.In =
        &x2cModel.blocks.sFOCmain.bInt2Real5.Out;

    /* Block Gain6                                                                                                    */
    x2cModel.blocks.sFOCmain.bGain6.In =
        &x2cModel.blocks.sFOCmain.bInt2Real4.Out;

    /* Block Int2Real                                                                                                 */
    x2cModel.blocks.sFOCmain.bInt2Real.In =
        &x2cModel.inports.bI_a;

    /* Block Int2Real1                                                                                                */
    x2cModel.blocks.sFOCmain.bInt2Real1.In =
        &x2cModel.inports.bI_b;

    /* Block Int2Real2                                                                                                */
    x2cModel.blocks.sFOCmain.bInt2Real2.In =
        &x2cModel.blocks.sFOCmain.bPark_Clarke_inv_SVM_MCHP.A;

    /* Block Int2Real3                                                                                                */
    x2cModel.blocks.sFOCmain.bInt2Real3.In =
        &x2cModel.blocks.sFOCmain.bGain1.Out;

    /* Block Int2Real4                                                                                                */
    x2cModel.blocks.sFOCmain.bInt2Real4.In =
        &x2cModel.blocks.sFOCmain.bPark_Clarke_inv_SVM_MCHP.B;

    /* Block Int2Real5                                                                                                */
    x2cModel.blocks.sFOCmain.bInt2Real5.In =
        &x2cModel.blocks.sFOCmain.bPark_Clarke_inv_SVM_MCHP.C;

    /* Block ManualSwitch                                                                                             */
    x2cModel.blocks.sFOCmain.bManualSwitch.In1 =
        &x2cModel.blocks.sFOCmain.bOpenLoop_Vd.Out;
    x2cModel.blocks.sFOCmain.bManualSwitch.In2 =
        &x2cModel.blocks.sFOCmain.bPI_flux.Out;

    /* Block ManualSwitch1                                                                                            */
    x2cModel.blocks.sFOCmain.bManualSwitch1.In1 =
        &x2cModel.blocks.sFOCmain.bOpenLoop_Vq.Out;
    x2cModel.blocks.sFOCmain.bManualSwitch1.In2 =
        &x2cModel.blocks.sFOCmain.bPI_torque.Out;

    /* Block Mult                                                                                                     */
    x2cModel.blocks.sFOCmain.bMult.In1 =
        &x2cModel.blocks.sFOCmain.bGain4.Out;
    x2cModel.blocks.sFOCmain.bMult.In2 =
        &x2cModel.blocks.sFOCmain.bGain.Out;

    /* Block Mult1                                                                                                    */
    x2cModel.blocks.sFOCmain.bMult1.In1 =
        &x2cModel.blocks.sFOCmain.bGain5.Out;
    x2cModel.blocks.sFOCmain.bMult1.In2 =
        &x2cModel.blocks.sFOCmain.bGain3.Out;

    /* Block Mult2                                                                                                    */
    x2cModel.blocks.sFOCmain.bMult2.In1 =
        &x2cModel.blocks.sFOCmain.bGain6.Out;
    x2cModel.blocks.sFOCmain.bMult2.In2 =
        &x2cModel.blocks.sFOCmain.bGain2.Out;

    /* Block Not                                                                                                      */
    x2cModel.blocks.sFOCmain.bNot.In =
        &x2cModel.blocks.sFOCmain.bTypeConv2.Out;

    /* Block OpenLoop_Vd                                                                                              */

    /* Block OpenLoop_Vq                                                                                              */

    /* Block PI_flux                                                                                                  */
    x2cModel.blocks.sFOCmain.bPI_flux.In =
        &x2cModel.blocks.sFOCmain.bSub_flux.Out;
    x2cModel.blocks.sFOCmain.bPI_flux.Init =
        &x2cModel.blocks.sFOCmain.bSub_flux.Out;
    x2cModel.blocks.sFOCmain.bPI_flux.Enable =
        &x2cModel.blocks.sFOCmain.bTypeConv2.Out;

    /* Block PI_torque                                                                                                */
    x2cModel.blocks.sFOCmain.bPI_torque.In =
        &x2cModel.blocks.sFOCmain.bSub_torque.Out;
    x2cModel.blocks.sFOCmain.bPI_torque.Init =
        &x2cModel.blocks.sFOCmain.bSub_torque.Out;
    x2cModel.blocks.sFOCmain.bPI_torque.Enable =
        &x2cModel.blocks.sFOCmain.bTypeConv2.Out;

    /* Block Park_Clarke_inv_SVM_MCHP                                                                                 */
    x2cModel.blocks.sFOCmain.bPark_Clarke_inv_SVM_MCHP.d =
        &x2cModel.blocks.sFOCmain.bSaturation1.Out;
    x2cModel.blocks.sFOCmain.bPark_Clarke_inv_SVM_MCHP.q =
        &x2cModel.blocks.sFOCmain.bSaturation.Out;
    x2cModel.blocks.sFOCmain.bPark_Clarke_inv_SVM_MCHP.theta =
        &x2cModel.blocks.sFOCmain.buAdd.Out;
    x2cModel.blocks.sFOCmain.bPark_Clarke_inv_SVM_MCHP.forcedMode =
        &x2cModel.blocks.sFOCmain.bNot.Out;
    x2cModel.blocks.sFOCmain.bPark_Clarke_inv_SVM_MCHP.forcedValue =
        &x2cModel.blocks.sFOCmain.bforced_current.Out;

    /* Block Saturation                                                                                               */
    x2cModel.blocks.sFOCmain.bSaturation.In =
        &x2cModel.blocks.sFOCmain.bManualSwitch1.Out;

    /* Block Saturation1                                                                                              */
    x2cModel.blocks.sFOCmain.bSaturation1.In =
        &x2cModel.blocks.sFOCmain.bManualSwitch.Out;

    /* Block Sub_flux                                                                                                 */
    x2cModel.blocks.sFOCmain.bSub_flux.Plus =
        &x2cModel.blocks.bFlux_SP1.Out;
    x2cModel.blocks.sFOCmain.bSub_flux.Minus =
        &x2cModel.blocks.sFOCmain.bClarke_Park_MCHP.d;

    /* Block Sub_torque                                                                                               */
    x2cModel.blocks.sFOCmain.bSub_torque.Plus =
        &x2cModel.blocks.bDynoMotor.Out;
    x2cModel.blocks.sFOCmain.bSub_torque.Minus =
        &x2cModel.blocks.sFOCmain.bClarke_Park_MCHP.q;

    /* Block Sum                                                                                                      */
    x2cModel.blocks.sFOCmain.bSum.In1 =
        &x2cModel.blocks.sFOCmain.bMult.Out;
    x2cModel.blocks.sFOCmain.bSum.In2 =
        &x2cModel.blocks.sFOCmain.bMult2.Out;
    x2cModel.blocks.sFOCmain.bSum.In3 =
        &x2cModel.blocks.sFOCmain.bMult1.Out;
    x2cModel.blocks.sFOCmain.bSum.In4 =
        &x2cModel.blocks.sFOCmain.bforced_current1.Out;
    x2cModel.blocks.sFOCmain.bSum.In5 =
        &x2cModel.blocks.sFOCmain.bforced_current1.Out;
    x2cModel.blocks.sFOCmain.bSum.In6 =
        &x2cModel.blocks.sFOCmain.bforced_current1.Out;
    x2cModel.blocks.sFOCmain.bSum.In7 =
        &x2cModel.blocks.sFOCmain.bforced_current1.Out;
    x2cModel.blocks.sFOCmain.bSum.In8 =
        &x2cModel.blocks.sFOCmain.bforced_current1.Out;

    /* Block TypeConv2                                                                                                */
    x2cModel.blocks.sFOCmain.bTypeConv2.In =
        &x2cModel.blocks.bSequencer.Out1;

    /* Block breakPowerW                                                                                              */
    x2cModel.blocks.sFOCmain.bbreakPowerW.In =
        &x2cModel.blocks.sFOCmain.bSum.Out;

    /* Block forced_current                                                                                           */

    /* Block forced_current1                                                                                          */

    /* Block theta_offset                                                                                             */

    /* Block uAdd                                                                                                     */
    x2cModel.blocks.sFOCmain.buAdd.In1 =
        &x2cModel.inports.bQEI_POS;
    x2cModel.blocks.sFOCmain.buAdd.In2 =
        &x2cModel.blocks.sFOCmain.btheta_offset.Out;

    /* Block Flux_SP1                                                                                                 */

    /* Block AutoSwitch                                                                                               */
    x2cModel.blocks.sMotor.bAutoSwitch.In1 =
        &x2cModel.blocks.sMotor.bt_speed_high.Out;
    x2cModel.blocks.sMotor.bAutoSwitch.Switch =
        &x2cModel.blocks.sMotor.bSinGen1.u;
    x2cModel.blocks.sMotor.bAutoSwitch.In3 =
        &x2cModel.blocks.sMotor.bt_speed_low.Out;

    /* Block Constant                                                                                                 */

    /* Block Constant1                                                                                                */

    /* Block Constant3                                                                                                */

    /* Block Constant4                                                                                                */

    /* Block Constant6                                                                                                */

    /* Block Gain                                                                                                     */
    x2cModel.blocks.sMotor.bGain.In =
        &x2cModel.blocks.sMotor.bmotor_torquemode.Out;

    /* Block Gain1                                                                                                    */
    x2cModel.blocks.sMotor.bGain1.In =
        &x2cModel.blocks.sMotor.bspeedPI_limit.Out;

    /* Block Gain3                                                                                                    */
    x2cModel.blocks.sMotor.bGain3.In =
        &x2cModel.blocks.sMotor.sSuperBlock.bGain2.Out;

    /* Block Int2Real                                                                                                 */
    x2cModel.blocks.sMotor.bInt2Real.In =
        &x2cModel.inports.bQEI_VEL;

    /* Block MAX_SPEED                                                                                                */
    x2cModel.blocks.sMotor.bMAX_SPEED.In =
        &x2cModel.blocks.sMotor.bInt2Real.Out;

    /* Block ManualSwitch                                                                                             */
    x2cModel.blocks.sMotor.bManualSwitch.In1 =
        &x2cModel.blocks.sMotor.bConstant.Out;
    x2cModel.blocks.sMotor.bManualSwitch.In2 =
        &x2cModel.blocks.sMotor.bTypeConv.Out;

    /* Block PILimit                                                                                                  */
    x2cModel.blocks.sMotor.bPILimit.In =
        &x2cModel.blocks.sMotor.bSubSpeed.Out;
    x2cModel.blocks.sMotor.bPILimit.Init =
        &x2cModel.blocks.sMotor.bConstant3.Out;
    x2cModel.blocks.sMotor.bPILimit.max =
        &x2cModel.blocks.sMotor.bspeedPI_limit.Out;
    x2cModel.blocks.sMotor.bPILimit.min =
        &x2cModel.blocks.sMotor.bGain1.Out;
    x2cModel.blocks.sMotor.bPILimit.Enable =
        &x2cModel.blocks.sMotor.bManualSwitch.Out;

    /* Block Real2Int                                                                                                 */
    x2cModel.blocks.sMotor.bReal2Int.In =
        &x2cModel.blocks.sMotor.bspeed_mode.Out;

    /* Block Selector                                                                                                 */
    x2cModel.blocks.sMotor.bSelector.In0 =
        &x2cModel.blocks.sMotor.bGain3.Out;
    x2cModel.blocks.sMotor.bSelector.In1 =
        &x2cModel.blocks.sMotor.bconst_speed.Out;
    x2cModel.blocks.sMotor.bSelector.In2 =
        &x2cModel.blocks.sMotor.bt_load_rate.Out;
    x2cModel.blocks.sMotor.bSelector.In3 =
        &x2cModel.blocks.sMotor.bconst_speed1.Out;
    x2cModel.blocks.sMotor.bSelector.In4 =
        &x2cModel.blocks.sMotor.bconst_speed1.Out;
    x2cModel.blocks.sMotor.bSelector.In5 =
        &x2cModel.blocks.sMotor.bconst_speed1.Out;
    x2cModel.blocks.sMotor.bSelector.In6 =
        &x2cModel.blocks.sMotor.bconst_speed1.Out;
    x2cModel.blocks.sMotor.bSelector.In7 =
        &x2cModel.blocks.sMotor.bconst_speed1.Out;
    x2cModel.blocks.sMotor.bSelector.Select =
        &x2cModel.blocks.sMotor.bReal2Int.Out;

    /* Block SinGen1                                                                                                  */
    x2cModel.blocks.sMotor.bSinGen1.A =
        &x2cModel.blocks.sMotor.bConstant1.Out;
    x2cModel.blocks.sMotor.bSinGen1.f =
        &x2cModel.blocks.sMotor.bt_speed_f.Out;

    /* Block SubSpeed                                                                                                 */
    x2cModel.blocks.sMotor.bSubSpeed.Plus =
        &x2cModel.blocks.sMotor.bSelector.Out;
    x2cModel.blocks.sMotor.bSubSpeed.Minus =
        &x2cModel.inports.bQEI_VEL;

    /* Block Constant2                                                                                                */

    /* Block Gain2                                                                                                    */
    x2cModel.blocks.sMotor.sSuperBlock.bGain2.In =
        &x2cModel.blocks.sMotor.sSuperBlock.bSub.Out;

    /* Block Sub                                                                                                      */
    x2cModel.blocks.sMotor.sSuperBlock.bSub.Plus =
        &x2cModel.blocks.bAverage.Out;
    x2cModel.blocks.sMotor.sSuperBlock.bSub.Minus =
        &x2cModel.blocks.sMotor.sSuperBlock.bConstant2.Out;

    /* Block TypeConv                                                                                                 */
    x2cModel.blocks.sMotor.bTypeConv.In =
        &x2cModel.blocks.bSequencer.Out2;

    /* Block const_speed                                                                                              */

    /* Block const_speed1                                                                                             */

    /* Block const_torque_motor                                                                                       */

    /* Block motor_torquemode                                                                                         */
    x2cModel.blocks.sMotor.bmotor_torquemode.In1 =
        &x2cModel.blocks.sMotor.bconst_torque_motor.Out;
    x2cModel.blocks.sMotor.bmotor_torquemode.In2 =
        &x2cModel.blocks.sMotor.bPILimit.Out;

    /* Block omega_rpm                                                                                                */
    x2cModel.blocks.sMotor.bomega_rpm.In =
        &x2cModel.blocks.sMotor.bMAX_SPEED.Out;

    /* Block speedPI_limit                                                                                            */

    /* Block speed_mode                                                                                               */

    /* Block t_load_rate                                                                                              */
    x2cModel.blocks.sMotor.bt_load_rate.In =
        &x2cModel.blocks.sMotor.bAutoSwitch.Out;
    x2cModel.blocks.sMotor.bt_load_rate.Init =
        &x2cModel.blocks.sMotor.bConstant4.Out;
    x2cModel.blocks.sMotor.bt_load_rate.Enable =
        &x2cModel.blocks.sMotor.bConstant6.Out;

    /* Block t_speed_f                                                                                                */

    /* Block t_speed_high                                                                                             */

    /* Block t_speed_low                                                                                              */

    /* Block Gain1                                                                                                    */
    x2cModel.blocks.sQEI_init.bGain1.In =
        &x2cModel.blocks.sQEI_init.bTypeConv1.Out;

    /* Block Not                                                                                                      */
    x2cModel.blocks.sQEI_init.bNot.In =
        &x2cModel.blocks.sQEI_init.bTypeConv.Out;

    /* Block TypeConv                                                                                                 */
    x2cModel.blocks.sQEI_init.bTypeConv.In =
        &x2cModel.blocks.bSequencer.Out1;

    /* Block TypeConv1                                                                                                */
    x2cModel.blocks.sQEI_init.bTypeConv1.In =
        &x2cModel.blocks.sQEI_init.bNot.Out;

    /* Block Sequencer                                                                                                */
    x2cModel.blocks.bSequencer.Start =
        &x2cModel.inports.bS2;

    /* Block Abs                                                                                                      */
    x2cModel.blocks.sdyno_quadrant.bAbs.In =
        &x2cModel.inports.bQEI_VEL;

    /* Block AutoSwitch                                                                                               */
    x2cModel.blocks.sdyno_quadrant.bAutoSwitch.In1 =
        &x2cModel.blocks.sdyno_quadrant.bSaturation.Out;
    x2cModel.blocks.sdyno_quadrant.bAutoSwitch.Switch =
        &x2cModel.blocks.sdyno_quadrant.bSpeedAverage.Out;
    x2cModel.blocks.sdyno_quadrant.bAutoSwitch.In3 =
        &x2cModel.blocks.sdyno_quadrant.bTorque_SP.Out;

    /* Block Constant1                                                                                                */

    /* Block Constant2                                                                                                */

    /* Block ManualSwitch3                                                                                            */
    x2cModel.blocks.sdyno_quadrant.bManualSwitch3.In1 =
        &x2cModel.blocks.sdyno_quadrant.bConstant2.Out;
    x2cModel.blocks.sdyno_quadrant.bManualSwitch3.In2 =
        &x2cModel.inports.bQEI_VEL;

    /* Block Mult1                                                                                                    */
    x2cModel.blocks.sdyno_quadrant.bMult1.In1 =
        &x2cModel.blocks.sDyno.bSelector.Out;
    x2cModel.blocks.sdyno_quadrant.bMult1.In2 =
        &x2cModel.blocks.sdyno_quadrant.bNegation.Out;

    /* Block Mult2                                                                                                    */
    x2cModel.blocks.sdyno_quadrant.bMult2.In1 =
        &x2cModel.blocks.sdyno_quadrant.bManualSwitch3.Out;
    x2cModel.blocks.sdyno_quadrant.bMult2.In2 =
        &x2cModel.blocks.sdyno_quadrant.bSign1.Out;

    /* Block Negation                                                                                                 */
    x2cModel.blocks.sdyno_quadrant.bNegation.In =
        &x2cModel.blocks.sdyno_quadrant.bSign1.Out;

    /* Block RateLimiter                                                                                              */
    x2cModel.blocks.sdyno_quadrant.bRateLimiter.In =
        &x2cModel.blocks.sdyno_quadrant.bAutoSwitch.Out;
    x2cModel.blocks.sdyno_quadrant.bRateLimiter.Init =
        &x2cModel.blocks.sdyno_quadrant.bTorque_SP.Out;
    x2cModel.blocks.sdyno_quadrant.bRateLimiter.Enable =
        &x2cModel.blocks.sdyno_quadrant.bConstant1.Out;

    /* Block Saturation                                                                                               */
    x2cModel.blocks.sdyno_quadrant.bSaturation.In =
        &x2cModel.blocks.sdyno_quadrant.bMult1.Out;

    /* Block Sign1                                                                                                    */
    x2cModel.blocks.sdyno_quadrant.bSign1.In =
        &x2cModel.blocks.sdyno_quadrant.bManualSwitch3.Out;

    /* Block SpeedAverage                                                                                             */
    x2cModel.blocks.sdyno_quadrant.bSpeedAverage.In =
        &x2cModel.blocks.sdyno_quadrant.bMult2.Out;

    /* Block Torque_SP                                                                                                */

    /******************************************************************************************************************/
    /**                                                 Link Outports                                                **/
    /******************************************************************************************************************/
    x2cModel.outports.bHOME_INIT =
        &x2cModel.blocks.sQEI_init.bGain1.Out;
    x2cModel.outports.bIq =
        &x2cModel.blocks.bDynoMotor.Out;
    x2cModel.outports.bLED_D17 =
        &x2cModel.blocks.bSequencer.Out1;
    x2cModel.outports.bLED_D2 =
        &x2cModel.inports.bS2;
    x2cModel.outports.bPWM1 =
        &x2cModel.blocks.sFOCmain.bPark_Clarke_inv_SVM_MCHP.A;
    x2cModel.outports.bPWM2 =
        &x2cModel.blocks.sFOCmain.bPark_Clarke_inv_SVM_MCHP.B;
    x2cModel.outports.bPWM3 =
        &x2cModel.blocks.sFOCmain.bPark_Clarke_inv_SVM_MCHP.C;
    x2cModel.outports.sdyno_quadrant.bSPEED_ABS =
        &x2cModel.blocks.sdyno_quadrant.bAbs.Out;

    /******************************************************************************************************************/
    /**                                           Run Block Init Functions                                           **/
    /******************************************************************************************************************/
    Average_FiP16_Init(&x2cModel.blocks.bAverage);
    Add_FiP16_Init(&x2cModel.blocks.sDyno.bAdd);
    Add_FiP16_Init(&x2cModel.blocks.sDyno.bAdd1);
    Add_FiP16_Init(&x2cModel.blocks.sDyno.bAdd2);
    AutoSwitch_FiP16_Init(&x2cModel.blocks.sDyno.bAutoSwitch);
    Constant_FiP16_Init(&x2cModel.blocks.sDyno.bConstT5);
    Constant_FiP16_Init(&x2cModel.blocks.sDyno.bConstT6);
    Constant_FiP16_Init(&x2cModel.blocks.sDyno.bConstT7);
    Constant_FiP16_Init(&x2cModel.blocks.sDyno.bConstant);
    Constant_FiP16_Init(&x2cModel.blocks.sDyno.bConstant4);
    Constant_Bool_Init(&x2cModel.blocks.sDyno.bConstant6);
    Gain_FiP16_Init(&x2cModel.blocks.sDyno.bGainT5);
    Gain_FiP16_Init(&x2cModel.blocks.sDyno.bGainT6);
    Gain_FiP16_Init(&x2cModel.blocks.sDyno.bGainT7);
    LookupTable_FiP16_Init(&x2cModel.blocks.sDyno.bLookupTable);
    LookupTable_FiP16_Init(&x2cModel.blocks.sDyno.bLookupTable1);
    LookupTable_FiP16_Init(&x2cModel.blocks.sDyno.bLookupTable2);
    Mult_FiP16_Init(&x2cModel.blocks.sDyno.bMult);
    Real2Int_Float32_FiP8_Init(&x2cModel.blocks.sDyno.bReal2Int);
    Selector_FiP16_Init(&x2cModel.blocks.sDyno.bSelector);
    SinGen_FiP16_Init(&x2cModel.blocks.sDyno.bSinGen1);
    SinGen_FiP16_Init(&x2cModel.blocks.sDyno.bSin_load);
    Constant_FiP16_Init(&x2cModel.blocks.sDyno.bconst_torque);
    Gain_FiP16_Init(&x2cModel.blocks.sDyno.bfan_gain);
    Constant_FiP16_Init(&x2cModel.blocks.sDyno.bsine_A);
    Constant_FiP16_Init(&x2cModel.blocks.sDyno.bsine_F);
    ManualSwitch_FiP16_Init(&x2cModel.blocks.sDyno.bswitch_mech_el);
    Constant_FiP16_Init(&x2cModel.blocks.sDyno.bt_load_f);
    Constant_FiP16_Init(&x2cModel.blocks.sDyno.bt_load_high);
    Constant_FiP16_Init(&x2cModel.blocks.sDyno.bt_load_low);
    RateLimiter_FiP16_Init(&x2cModel.blocks.sDyno.bt_load_rate);
    Constant_Float32_Init(&x2cModel.blocks.sDyno.btorque_mode);
    ManualSwitch_FiP16_Init(&x2cModel.blocks.bDynoMotor);
    Add_FiP16_Init(&x2cModel.blocks.sFOCmain.bAdd);
    Clarke_Park_MCHP_FiP16_Init(&x2cModel.blocks.sFOCmain.bClarke_Park_MCHP);
    Gain_Float32_Init(&x2cModel.blocks.sFOCmain.bGain);
    Gain_FiP16_Init(&x2cModel.blocks.sFOCmain.bGain1);
    Gain_Float32_Init(&x2cModel.blocks.sFOCmain.bGain2);
    Gain_Float32_Init(&x2cModel.blocks.sFOCmain.bGain3);
    Gain_Float32_Init(&x2cModel.blocks.sFOCmain.bGain4);
    Gain_Float32_Init(&x2cModel.blocks.sFOCmain.bGain5);
    Gain_Float32_Init(&x2cModel.blocks.sFOCmain.bGain6);
    Int2Real_FiP16_Float32_Init(&x2cModel.blocks.sFOCmain.bInt2Real);
    Int2Real_FiP16_Float32_Init(&x2cModel.blocks.sFOCmain.bInt2Real1);
    Int2Real_FiP16_Float32_Init(&x2cModel.blocks.sFOCmain.bInt2Real2);
    Int2Real_FiP16_Float32_Init(&x2cModel.blocks.sFOCmain.bInt2Real3);
    Int2Real_FiP16_Float32_Init(&x2cModel.blocks.sFOCmain.bInt2Real4);
    Int2Real_FiP16_Float32_Init(&x2cModel.blocks.sFOCmain.bInt2Real5);
    ManualSwitch_FiP16_Init(&x2cModel.blocks.sFOCmain.bManualSwitch);
    ManualSwitch_FiP16_Init(&x2cModel.blocks.sFOCmain.bManualSwitch1);
    Mult_Float32_Init(&x2cModel.blocks.sFOCmain.bMult);
    Mult_Float32_Init(&x2cModel.blocks.sFOCmain.bMult1);
    Mult_Float32_Init(&x2cModel.blocks.sFOCmain.bMult2);
    Not_Bool_Init(&x2cModel.blocks.sFOCmain.bNot);
    Constant_FiP16_Init(&x2cModel.blocks.sFOCmain.bOpenLoop_Vd);
    Constant_FiP16_Init(&x2cModel.blocks.sFOCmain.bOpenLoop_Vq);
    PI_FiP16_Init(&x2cModel.blocks.sFOCmain.bPI_flux);
    PI_FiP16_Init(&x2cModel.blocks.sFOCmain.bPI_torque);
    Park_Clarke_inv_SVM_MCHP_FiP16_Init(&x2cModel.blocks.sFOCmain.bPark_Clarke_inv_SVM_MCHP);
    Saturation_FiP16_Init(&x2cModel.blocks.sFOCmain.bSaturation);
    Saturation_FiP16_Init(&x2cModel.blocks.sFOCmain.bSaturation1);
    Sub_FiP16_Init(&x2cModel.blocks.sFOCmain.bSub_flux);
    Sub_FiP16_Init(&x2cModel.blocks.sFOCmain.bSub_torque);
    Sum_Float32_Init(&x2cModel.blocks.sFOCmain.bSum);
    TypeConv_FiP16_Bool_Init(&x2cModel.blocks.sFOCmain.bTypeConv2);
    SaveSignal_Float32_Init(&x2cModel.blocks.sFOCmain.bbreakPowerW);
    Constant_FiP16_Init(&x2cModel.blocks.sFOCmain.bforced_current);
    Constant_Float32_Init(&x2cModel.blocks.sFOCmain.bforced_current1);
    Constant_FiP16_Init(&x2cModel.blocks.sFOCmain.btheta_offset);
    uAdd_FiP16_Init(&x2cModel.blocks.sFOCmain.buAdd);
    Constant_FiP16_Init(&x2cModel.blocks.bFlux_SP1);
    AutoSwitch_FiP16_Init(&x2cModel.blocks.sMotor.bAutoSwitch);
    Constant_Bool_Init(&x2cModel.blocks.sMotor.bConstant);
    Constant_FiP16_Init(&x2cModel.blocks.sMotor.bConstant1);
    Constant_FiP16_Init(&x2cModel.blocks.sMotor.bConstant3);
    Constant_FiP16_Init(&x2cModel.blocks.sMotor.bConstant4);
    Constant_Bool_Init(&x2cModel.blocks.sMotor.bConstant6);
    Gain_FiP16_Init(&x2cModel.blocks.sMotor.bGain);
    Gain_FiP16_Init(&x2cModel.blocks.sMotor.bGain1);
    Gain_FiP16_Init(&x2cModel.blocks.sMotor.bGain3);
    Int2Real_FiP16_Float32_Init(&x2cModel.blocks.sMotor.bInt2Real);
    Gain_Float32_Init(&x2cModel.blocks.sMotor.bMAX_SPEED);
    ManualSwitch_Bool_Init(&x2cModel.blocks.sMotor.bManualSwitch);
    PILimit_FiP16_Init(&x2cModel.blocks.sMotor.bPILimit);
    Real2Int_Float32_FiP8_Init(&x2cModel.blocks.sMotor.bReal2Int);
    Selector_FiP16_Init(&x2cModel.blocks.sMotor.bSelector);
    SinGen_FiP16_Init(&x2cModel.blocks.sMotor.bSinGen1);
    Sub_FiP16_Init(&x2cModel.blocks.sMotor.bSubSpeed);
    Constant_FiP16_Init(&x2cModel.blocks.sMotor.sSuperBlock.bConstant2);
    Gain_FiP16_Init(&x2cModel.blocks.sMotor.sSuperBlock.bGain2);
    Sub_FiP16_Init(&x2cModel.blocks.sMotor.sSuperBlock.bSub);
    TypeConv_FiP16_Bool_Init(&x2cModel.blocks.sMotor.bTypeConv);
    Constant_FiP16_Init(&x2cModel.blocks.sMotor.bconst_speed);
    Constant_FiP16_Init(&x2cModel.blocks.sMotor.bconst_speed1);
    Constant_FiP16_Init(&x2cModel.blocks.sMotor.bconst_torque_motor);
    ManualSwitch_FiP16_Init(&x2cModel.blocks.sMotor.bmotor_torquemode);
    SaveSignal_Float32_Init(&x2cModel.blocks.sMotor.bomega_rpm);
    Constant_FiP16_Init(&x2cModel.blocks.sMotor.bspeedPI_limit);
    Constant_Float32_Init(&x2cModel.blocks.sMotor.bspeed_mode);
    RateLimiter_FiP16_Init(&x2cModel.blocks.sMotor.bt_load_rate);
    Constant_FiP16_Init(&x2cModel.blocks.sMotor.bt_speed_f);
    Constant_FiP16_Init(&x2cModel.blocks.sMotor.bt_speed_high);
    Constant_FiP16_Init(&x2cModel.blocks.sMotor.bt_speed_low);
    Gain_FiP16_Init(&x2cModel.blocks.sQEI_init.bGain1);
    Not_Bool_Init(&x2cModel.blocks.sQEI_init.bNot);
    TypeConv_FiP16_Bool_Init(&x2cModel.blocks.sQEI_init.bTypeConv);
    TypeConv_Bool_FiP16_Init(&x2cModel.blocks.sQEI_init.bTypeConv1);
    Sequencer_FiP16_Init(&x2cModel.blocks.bSequencer);
    Abs_FiP16_Init(&x2cModel.blocks.sdyno_quadrant.bAbs);
    AutoSwitch_FiP16_Init(&x2cModel.blocks.sdyno_quadrant.bAutoSwitch);
    Constant_Bool_Init(&x2cModel.blocks.sdyno_quadrant.bConstant1);
    Constant_FiP16_Init(&x2cModel.blocks.sdyno_quadrant.bConstant2);
    ManualSwitch_FiP16_Init(&x2cModel.blocks.sdyno_quadrant.bManualSwitch3);
    Mult_FiP16_Init(&x2cModel.blocks.sdyno_quadrant.bMult1);
    Mult_FiP16_Init(&x2cModel.blocks.sdyno_quadrant.bMult2);
    Negation_FiP16_Init(&x2cModel.blocks.sdyno_quadrant.bNegation);
    RateLimiter_FiP16_Init(&x2cModel.blocks.sdyno_quadrant.bRateLimiter);
    Saturation_FiP16_Init(&x2cModel.blocks.sdyno_quadrant.bSaturation);
    Sign_FiP16_Init(&x2cModel.blocks.sdyno_quadrant.bSign1);
    Average_FiP16_Init(&x2cModel.blocks.sdyno_quadrant.bSpeedAverage);
    Constant_FiP16_Init(&x2cModel.blocks.sdyno_quadrant.bTorque_SP);
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
    Average_FiP16_Update(&x2cModel.blocks.bAverage);
    ManualSwitch_FiP16_Update(&x2cModel.blocks.sDyno.bswitch_mech_el);
    LookupTable_FiP16_Update(&x2cModel.blocks.sDyno.bLookupTable);
    LookupTable_FiP16_Update(&x2cModel.blocks.sDyno.bLookupTable1);
    LookupTable_FiP16_Update(&x2cModel.blocks.sDyno.bLookupTable2);
    Gain_FiP16_Update(&x2cModel.blocks.sDyno.bGainT5);
    Gain_FiP16_Update(&x2cModel.blocks.sDyno.bGainT6);
    Gain_FiP16_Update(&x2cModel.blocks.sDyno.bGainT7);
    Add_FiP16_Update(&x2cModel.blocks.sDyno.bAdd);
    Add_FiP16_Update(&x2cModel.blocks.sDyno.bAdd1);
    Add_FiP16_Update(&x2cModel.blocks.sDyno.bAdd2);
    Real2Int_Float32_FiP8_Update(&x2cModel.blocks.sDyno.bReal2Int);
    uAdd_FiP16_Update(&x2cModel.blocks.sFOCmain.buAdd);
    Clarke_Park_MCHP_FiP16_Update(&x2cModel.blocks.sFOCmain.bClarke_Park_MCHP);
    Mult_FiP16_Update(&x2cModel.blocks.sDyno.bMult);
    Sub_FiP16_Update(&x2cModel.blocks.sFOCmain.bSub_flux);
    Sequencer_FiP16_Update(&x2cModel.blocks.bSequencer);
    ManualSwitch_FiP16_Update(&x2cModel.blocks.sdyno_quadrant.bManualSwitch3);
    Gain_FiP16_Update(&x2cModel.blocks.sDyno.bfan_gain);
    TypeConv_FiP16_Bool_Update(&x2cModel.blocks.sFOCmain.bTypeConv2);
    TypeConv_FiP16_Bool_Update(&x2cModel.blocks.sQEI_init.bTypeConv);
    Sign_FiP16_Update(&x2cModel.blocks.sdyno_quadrant.bSign1);
    Selector_FiP16_Update(&x2cModel.blocks.sDyno.bSelector);
    PI_FiP16_Update(&x2cModel.blocks.sFOCmain.bPI_flux);
    Not_Bool_Update(&x2cModel.blocks.sQEI_init.bNot);
    Mult_FiP16_Update(&x2cModel.blocks.sdyno_quadrant.bMult2);
    Negation_FiP16_Update(&x2cModel.blocks.sdyno_quadrant.bNegation);
    ManualSwitch_FiP16_Update(&x2cModel.blocks.sFOCmain.bManualSwitch);
    Not_Bool_Update(&x2cModel.blocks.sFOCmain.bNot);
    TypeConv_Bool_FiP16_Update(&x2cModel.blocks.sQEI_init.bTypeConv1);
    Mult_FiP16_Update(&x2cModel.blocks.sdyno_quadrant.bMult1);
    Average_FiP16_Update(&x2cModel.blocks.sdyno_quadrant.bSpeedAverage);
    Saturation_FiP16_Update(&x2cModel.blocks.sFOCmain.bSaturation1);
    ManualSwitch_FiP16_Update(&x2cModel.blocks.sMotor.bmotor_torquemode);
    Gain_FiP16_Update(&x2cModel.blocks.sQEI_init.bGain1);
    Abs_FiP16_Update(&x2cModel.blocks.sdyno_quadrant.bAbs);
    Saturation_FiP16_Update(&x2cModel.blocks.sdyno_quadrant.bSaturation);
    Gain_FiP16_Update(&x2cModel.blocks.sMotor.bGain);
    AutoSwitch_FiP16_Update(&x2cModel.blocks.sdyno_quadrant.bAutoSwitch);
    RateLimiter_FiP16_Update(&x2cModel.blocks.sdyno_quadrant.bRateLimiter);
    ManualSwitch_FiP16_Update(&x2cModel.blocks.bDynoMotor);
    Sub_FiP16_Update(&x2cModel.blocks.sFOCmain.bSub_torque);
    PI_FiP16_Update(&x2cModel.blocks.sFOCmain.bPI_torque);
    ManualSwitch_FiP16_Update(&x2cModel.blocks.sFOCmain.bManualSwitch1);
    Saturation_FiP16_Update(&x2cModel.blocks.sFOCmain.bSaturation);
    Park_Clarke_inv_SVM_MCHP_FiP16_Update(&x2cModel.blocks.sFOCmain.bPark_Clarke_inv_SVM_MCHP);
    Scope_Main_Update(&x2cScope);
}

/* X2C_Update for blocks with 10*Ts                                                                                   */
void X2C_Update_10(void)
{
    SinGen_FiP16_Update(&x2cModel.blocks.sDyno.bSinGen1);
    SinGen_FiP16_Update(&x2cModel.blocks.sMotor.bSinGen1);
    Sub_FiP16_Update(&x2cModel.blocks.sMotor.sSuperBlock.bSub);
    AutoSwitch_FiP16_Update(&x2cModel.blocks.sDyno.bAutoSwitch);
    AutoSwitch_FiP16_Update(&x2cModel.blocks.sMotor.bAutoSwitch);
    Gain_FiP16_Update(&x2cModel.blocks.sMotor.sSuperBlock.bGain2);
    SinGen_FiP16_Update(&x2cModel.blocks.sDyno.bSin_load);
    RateLimiter_FiP16_Update(&x2cModel.blocks.sDyno.bt_load_rate);
    Gain_FiP16_Update(&x2cModel.blocks.sMotor.bGain3);
    Real2Int_Float32_FiP8_Update(&x2cModel.blocks.sMotor.bReal2Int);
    RateLimiter_FiP16_Update(&x2cModel.blocks.sMotor.bt_load_rate);
    Add_FiP16_Update(&x2cModel.blocks.sFOCmain.bAdd);
    Selector_FiP16_Update(&x2cModel.blocks.sMotor.bSelector);
    Gain_FiP16_Update(&x2cModel.blocks.sFOCmain.bGain1);
    Sub_FiP16_Update(&x2cModel.blocks.sMotor.bSubSpeed);
    Int2Real_FiP16_Float32_Update(&x2cModel.blocks.sFOCmain.bInt2Real);
    Int2Real_FiP16_Float32_Update(&x2cModel.blocks.sFOCmain.bInt2Real1);
    Int2Real_FiP16_Float32_Update(&x2cModel.blocks.sFOCmain.bInt2Real3);
    Gain_FiP16_Update(&x2cModel.blocks.sMotor.bGain1);
    TypeConv_FiP16_Bool_Update(&x2cModel.blocks.sMotor.bTypeConv);
    Gain_Float32_Update(&x2cModel.blocks.sFOCmain.bGain);
    Gain_Float32_Update(&x2cModel.blocks.sFOCmain.bGain2);
    Gain_Float32_Update(&x2cModel.blocks.sFOCmain.bGain3);
    ManualSwitch_Bool_Update(&x2cModel.blocks.sMotor.bManualSwitch);
    Int2Real_FiP16_Float32_Update(&x2cModel.blocks.sMotor.bInt2Real);
    PILimit_FiP16_Update(&x2cModel.blocks.sMotor.bPILimit);
    Gain_Float32_Update(&x2cModel.blocks.sMotor.bMAX_SPEED);
    Int2Real_FiP16_Float32_Update(&x2cModel.blocks.sFOCmain.bInt2Real2);
    Int2Real_FiP16_Float32_Update(&x2cModel.blocks.sFOCmain.bInt2Real4);
    Int2Real_FiP16_Float32_Update(&x2cModel.blocks.sFOCmain.bInt2Real5);
    Gain_Float32_Update(&x2cModel.blocks.sFOCmain.bGain4);
    Gain_Float32_Update(&x2cModel.blocks.sFOCmain.bGain5);
    Gain_Float32_Update(&x2cModel.blocks.sFOCmain.bGain6);
    Mult_Float32_Update(&x2cModel.blocks.sFOCmain.bMult);
    Mult_Float32_Update(&x2cModel.blocks.sFOCmain.bMult1);
    Mult_Float32_Update(&x2cModel.blocks.sFOCmain.bMult2);
    Sum_Float32_Update(&x2cModel.blocks.sFOCmain.bSum);
}

