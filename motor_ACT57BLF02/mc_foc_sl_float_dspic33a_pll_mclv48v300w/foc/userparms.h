#ifndef _USER_HEADER
#define _USER_HEADER

#include <math.h>

#define MAX_CURRENT                 (float)(22.0)
#define ADC_CURRENT_SCALE           (float)(MAX_CURRENT/(float)32768)
#define ADC_CURRENT_SCALE_INVERSE   (float)((float)32768/ MAX_CURRENT)
#define DC_BUS_VOLTAGE              (float)24
#define MOTOR_PER_PHASE_RESISTANCE                          ((float)2.833)
#define MOTOR_PER_PHASE_INDUCTANCE                          ((float)((0.00243)))
#define MOTOR_BACK_EMF_CONSTANT_Vpeak_Line_Line_KRPM_MECH   (float)7.5678
#define NOPOLESPAIRS                    5

#undef OPEN_LOOP_FUNCTIONING
#undef TORQUE_MODE
#undef INTERNAL_OPAMP_CONFIG
#undef SINGLE_SHUNT

#define SINGLE_ELEC_ROT_RADS_PER_SEC    (float)(2.0*M_PI)
#define MAX_DUTY                        19999 // For 5KHz PWM frequency on dsPIC33CK device
#define SQRT_3                          (float)1.732
#define LOOPTIME_SEC                    (float)0.00005           // PWM Period - 200 uSec, 5Khz PWM
#define DEADTIME                        (float)0.0000005
#define EFFECTIVE_MAX_DUTY              (float)((LOOPTIME_SEC - DEADTIME)/LOOPTIME_SEC)
#define LOCK_TIME_IN_SEC                1
#define LOCK_COUNT_FOR_LOCK_TIME        (unsigned int)((float)LOCK_TIME_IN_SEC/(float)LOOPTIME_SEC)
#define LOCK_TIME_IN_SEC                1
#define LOCK_COUNT_FOR_LOCK_TIME        (unsigned int)((float)LOCK_TIME_IN_SEC/(float)LOOPTIME_SEC)
#define END_SPEED_RPM                   500 // Value in RPM


#define END_SPEED_RPS               ((float)END_SPEED_RPM/60)
// In 1 second, the motor maked "END_SPEED_RPS" mechanical rotations
#define RAMP_TIME_IN_SEC                3
#define END_SPEED_RADS_SEC_SEC_MECH (float)(END_SPEED_RPS * SINGLE_ELEC_ROT_RADS_PER_SEC)
#define END_SPEED_RADS_SEC_SEC_ELEC (float)(END_SPEED_RADS_SEC_SEC_MECH * NOPOLESPAIRS)
#define END_SPEED_RADS_SEC_SEC_ELEC_IN_LOOPTIME (float)(END_SPEED_RADS_SEC_SEC_ELEC * LOOPTIME_SEC)
//#define OPENLOOP_RAMPSPEED_INCREASERATE     (float)(END_SPEED_RADS_SEC_SEC_ELEC_IN_LOOPTIME/(RAMP_TIME_IN_SEC/LOOPTIME_SEC))
#define OPENLOOP_RAMPSPEED_INCREASERATE     (float)(END_SPEED_RADS_SEC_SEC_ELEC/(RAMP_TIME_IN_SEC/LOOPTIME_SEC))
/* end speed conveted to fit the startup ramp */
#define Q_CURRENT_REF_OPENLOOP           0.1
/* Nominal speed of the motor in RPM */
#define NOMINAL_SPEED_RPM                                (float)2000 // Value in RPM
#define NOMINAL_SPEED_RAD_PER_SEC_ELEC                   (float)(((NOMINAL_SPEED_RPM/60)*2*M_PI)*5) // Value in RPM

   
#define DC_BUS_VOLTAGE_DUE_TO_SVM     (float)((DC_BUS_VOLTAGE * EFFECTIVE_MAX_DUTY)/SQRT_3)

#define MOTOR_BACK_EMF_CONSTANT_Vpeak_PHASE_RPM_MECH                    (float)((MOTOR_BACK_EMF_CONSTANT_Vpeak_Line_Line_KRPM_MECH/1.732)/1000)
#define MOTOR_BACK_EMF_CONSTANT_Vpeak_PHASE_RPS_MECH                    (float)(MOTOR_BACK_EMF_CONSTANT_Vpeak_PHASE_RPM_MECH * 60)
#define MOTOR_BACK_EMF_CONSTANT_Vpeak_PHASE_RAD_PER_SEC_MECH        (float)(MOTOR_BACK_EMF_CONSTANT_Vpeak_PHASE_RPS_MECH/(2*M_PI))
#define MOTOR_BACK_EMF_CONSTANT_Vpeak_PHASE_RAD_PER_SEC_ELEC        (float)(MOTOR_BACK_EMF_CONSTANT_Vpeak_PHASE_RAD_PER_SEC_MECH/NOPOLESPAIRS)

/* PI controllers tuning values - */
//******** D Control Loop Coefficients *******
#define     D_CURRCNTR_PTERM           5.61/2//(0.05/MAX_CURRENT)
#define     D_CURRCNTR_ITERM           0.35/2//(0.003 /MAX_CURRENT)
#define     D_CURRCNTR_CTERM           1;//(0.999/MAX_CURRENT)
#define     D_CURRCNTR_OUTMAX          DC_BUS_VOLTAGE_DUE_TO_SVM

//******** Q Control Loop Coefficients *******
#define     Q_CURRCNTR_PTERM           5.61/2//(0.05/MAX_CURRENT)
#define     Q_CURRCNTR_ITERM           0.35/2//(0.003 /MAX_CURRENT)
#define     Q_CURRCNTR_CTERM           1;//(0.999/MAX_CURRENT)
#define     Q_CURRCNTR_OUTMAX          DC_BUS_VOLTAGE_DUE_TO_SVM

//*** Velocity Control Loop Coefficients *****
#define     SPEEDCNTR_PTERM        0.003367/2//(0.07 * 4 * (M_PI/30))
#define     SPEEDCNTR_ITERM        0.00000084/2//(0.001 * (M_PI/30))//0.005
#define     SPEEDCNTR_CTERM        1;//0.005//(0.005 * (30/M_PI))//0.005
#define     SPEEDCNTR_OUTMAX       2.0  // Max current allowed is 2.0 Amps
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/
#define KFILTER_ESDQ                        (float)((float)(4327*2)/(float)32767)
#define KFILTER_VELESTIM                    (float)((float)(2801*2)/(float)32767)
#define INITOFFSET_TRANS_OPEN_CLSD          (float)((float)0/(float)32767)


#define FW_SPEED_RPM                        (float)3500
#define FW_SPEED_RAD_PER_SEC_ELEC           (float)(((FW_SPEED_RPM/60)*2*M_PI)*5)
#define SPEED_COMMAND_RAMP_UP_TIME          (float)25.0 // seconds
#define MAX_FW_NEGATIVE_ID_REF              (float)(-2)

#endif