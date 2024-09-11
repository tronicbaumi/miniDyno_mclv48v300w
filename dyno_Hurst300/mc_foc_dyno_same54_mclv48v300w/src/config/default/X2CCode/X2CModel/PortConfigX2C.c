/* This file is part of X2C. http://www.mechatronic-simulation.org/                                                   */

#include "X2C.h"
#include "PortConfigX2C.h"
#include "definitions.h"

#include "../../../../userparams.h"
#include "can1_Lib.h"

uint16_t rotor_elec_count;
uint16_t rotor_mech_count;
uint16_t rotor_speed_count;

int16_t pos_count_diff = 0;
float speed_elec = 0.0;

static unsigned char S3_Value;
static unsigned char S3_Value_old = 1;
static unsigned char DebounceCnt;
static unsigned char edge=0;

extern int16_t  adc_0_offset;
extern int16_t  adc_1_offset;
extern uint16_t phaseA_current_raw;
extern uint16_t phaseB_current_raw;
extern uint16_t dcbus_raw;
extern uint16_t pot_raw;
extern int16_t CpuLoad;

uint32_t  duty_A;
uint32_t  duty_B;
uint32_t  duty_C;
bool adcCalibrated = false;

//Structure containing variables used in position and speed calculation
typedef struct
{
  int16_t prev_position_count;
  int16_t present_position_count;
  uint16_t QDECcnt;
  uint16_t QDECcntZ;
  uint16_t posCntElec;
  uint16_t posCntMech;
  uint16_t posCompensation;
  uint32_t posCntTmp;
  
}MCAPP_POSITION_CALC;

MCAPP_POSITION_CALC  gPositionCalc;


extern uint16_t TimerEncoderFilter;
extern uint16_t slow_loop_count;
void Reset_Position(void);


void readInports(void)
{
	/* TODO add linkage hardware-inputs -> X2C inports here 
     * Pass the peripheral values to model Inports
     * if (PORTA & 1) { 
     *    x2cModel.inports.bInport = INT16_MAX;
     * }else {
     *    x2cModel.inports.bInport = 0;
     * }
	 */
    
    x2cModel.inports.bI_a = (phaseA_current_raw-adc_0_offset)<<4; 
    x2cModel.inports.bI_b = (phaseB_current_raw-adc_1_offset)<<4; 
    x2cModel.inports.bV_POT = (pot_raw)<<3;  // pot value between 0 and 1 (=INT16_MAX) 
    x2cModel.inports.bV_DCLINK = dcbus_raw;// EL01 to be fixed (dcbus_raw * 48) / 4095;  YA
   
    /* Button latch and debounce */
    
    if(BUTTON_01_Get()==0) x2cModel.inports.bS2 = 0;
    else  x2cModel.inports.bS2 = INT16_MAX;
    
    S3_Value = BUTTON_02_Get();
    // x2cModel.inports.bS2 =  S3_Value;    
    if(edge==0)
    {
        if (S3_Value != S3_Value_old) 
        {
            S3_Value_old = S3_Value;
            if(S3_Value)
            {
                DebounceCnt = 0;
                edge = 1;
            }
        }
    }
    else
    {
        DebounceCnt++;
        if(DebounceCnt >= 10)
        {           
            if(x2cModel.inports.bS3==0)
            {
                x2cModel.inports.bS3 = INT16_MAX;
            }
            else
            {
                x2cModel.inports.bS3 = 0;
            }
            
            DebounceCnt = 0;
            edge=0;
        }    
    }
    if (*x2cModel.outports.bHOME_INIT == 0) { // read the encode after the HOME_INIT sequence 
        // Get Rotor Position from QDEC     
        gPositionCalc.QDECcnt = PDEC_QDECPositionGet();
        if((gPositionCalc.QDECcnt>QDEC_UPPER_THRESHOLD) && (gPositionCalc.QDECcntZ<QDEC_LOWER_THRESHOLD))
        {
            gPositionCalc.posCompensation += QDEC_UNDERFLOW;
        } 
        else if((gPositionCalc.QDECcntZ>QDEC_UPPER_THRESHOLD) && (gPositionCalc.QDECcnt<QDEC_LOWER_THRESHOLD))
        {
            gPositionCalc.posCompensation += QDEC_OVERFLOW;           
        } 
        gPositionCalc.posCompensation = gPositionCalc.posCompensation % ENCODER_PULSES_PER_ELEC_REV;
        gPositionCalc.posCntTmp = gPositionCalc.QDECcnt + gPositionCalc.posCompensation;
        gPositionCalc.posCntElec = (gPositionCalc.posCntTmp % ENCODER_PULSES_PER_ELEC_REV) * QEI_FACT_ELEC;
        rotor_elec_count = gPositionCalc.posCntElec;
        gPositionCalc.posCntMech = (gPositionCalc.posCntTmp % ENCODER_PULSES_PER_MECH_REV) * QEI_FACT_MECH;
        rotor_mech_count = gPositionCalc.posCntMech; 
        gPositionCalc.QDECcntZ = gPositionCalc.QDECcnt;    
        // Speed Calculation from Encoder
        if (slow_loop_count >= SPEED_SAMPLE_FREQ)
        {
            slow_loop_count = 0;            
            gPositionCalc.present_position_count = (int16_t)(PDEC_QDECPositionGet());
            pos_count_diff = gPositionCalc.present_position_count - gPositionCalc.prev_position_count;
            speed_elec = (float)pos_count_diff * ((60.0 * (float)(PWM_FREQ / SPEED_SAMPLE_FREQ)*(float)INT16_MAX) / ((float)MAX_SPEED*(float)ENCODER_PULSES_PER_MECH_REV)); 
            rotor_speed_count = ((int16_t)speed_elec);
            gPositionCalc.prev_position_count = gPositionCalc.present_position_count;
        }
    }

    // transfer encoder values to the model 
    // used negative sign in order to use same model as dsPIC33EP
    /*EL01 x2cModel.inports.bQEI_POS = -rotor_elec_count;
    x2cModel.inports.bQEI_POS_MECH = -rotor_mech_count;
    x2cModel.inports.bQEI_VEL = -rotor_speed_count;
    */
    
    x2cModel.inports.bQEI_POS = rotor_elec_count;
    x2cModel.inports.bQEI_POS_MECH = rotor_mech_count;
    x2cModel.inports.bQEI_VEL = rotor_speed_count;
    
    x2cModel.inports.bCPU_LOAD = CpuLoad;
    x2cModel.inports.bI_sum = -(x2cModel.inports.bI_a + x2cModel.inports.bI_b);
    
    // Show data receive from slave
//    x2cModel.inports.bDRV_MOTOR_SPEED = RX_Param.ReadSpeedValue;
//    x2cModel.inports.bDEBUG2 = RX_Param.ReadPosition;
//    x2cModel.inports.bDEBUG3 = RX_Param.ReadCurrentPHA;
//    x2cModel.inports.bDEBUG4 = RX_Param.ReadCurrentPHB;
}

void writeOutports(void)
{
	/* TODO add linkage X2C outports -> hardware-outputs here 
     * if (*x2cModel.outports.bOutport) {  // if model Outport differ than zero 
     *    LATB |= 1; // set LATB0 
     * } else {
     *    LATB &= ~1; // clear LATB0
     * } 
	*/
    
	if((*x2cModel.outports.bIq !=0) || (*x2cModel.outports.bHOME_INIT != 0))  //  position alignment
    {
        // Duty cycle is subtracted from INT16_MAX instead of adding (as done in dsPIC and PIC32MK). 
        // This is because in center aligned PWM, the On time is inversely proportional to duty cycle
        duty_A = (uint16_t)(((INT16_MAX - *x2cModel.outports.bPWM1)*PWM_PERIODE)>>16); 
        duty_B = (uint16_t)(((INT16_MAX - *x2cModel.outports.bPWM2)*PWM_PERIODE)>>16);
        duty_C = (uint16_t)(((INT16_MAX - *x2cModel.outports.bPWM3)*PWM_PERIODE)>>16);

        TCC0_PWMPatternSet(0x00,0x00); /* Disable PWM override*/        
    }
    else 
    {
        // Set Duty cycle to 50%
        duty_A = (uint16_t)(((INT16_MAX)*PWM_PERIODE)>>16); 
        duty_B = (uint16_t)(((INT16_MAX)*PWM_PERIODE)>>16);
        duty_C = (uint16_t)(((INT16_MAX)*PWM_PERIODE)>>16);
        
        /*Override all PWM outputs to low*/
        TCC0_PWMPatternSet((TCC_PATT_PGE0_Msk|TCC_PATT_PGE1_Msk|TCC_PATT_PGE2_Msk
            |TCC_PATT_PGE4_Msk|TCC_PATT_PGE5_Msk|TCC_PATT_PGE6_Msk),
            (TCC_PATT_PGE0(0)|TCC_PATT_PGE1(0)|TCC_PATT_PGE2(0)|TCC_PATT_PGE4(0)
            |TCC_PATT_PGE5(0)|TCC_PATT_PGE6(0)));
    }
    
    TCC0_PWM24bitDutySet(TCC0_CHANNEL0, (uint32_t) duty_A ); 
    TCC0_PWM24bitDutySet(TCC0_CHANNEL1, (uint32_t) duty_B );
    TCC0_PWM24bitDutySet(TCC0_CHANNEL2, (uint32_t) duty_C );


    
    /* Clear position counter on Home init as long as HOME_INIT is active*/
    if (*x2cModel.outports.bHOME_INIT != 0) { 
        PDEC_QDECStop();        
        TimerEncoderFilter = 10000; // *50us 
    }
    else
    {
        if(TimerEncoderFilter) // delay to compensate for rotor to move back
        {
            PDEC_REGS->PDEC_CTRLBSET = PDEC_CTRLBSET_CMD_RETRIGGER;
            while((PDEC_REGS->PDEC_SYNCBUSY))
            {
                /* Wait for Write Synchronization */
            }
            Reset_Position(); 
            PDEC_QDECStart();
        }
    }

    
//    if (*x2cModel.outports.bLED_D17 != 0) {
//        LED1_Set();
//    }
//    else {
//        LED1_Clear();
//    }
//    
//    if (*x2cModel.outports.bLED_D2 != 0) {
//        LED2_Set();
//    }
//    else {
//        LED2_Clear();
//    }
       
    // set parameter for SLAVE    
//    TX_Param.SetControlType = *x2cModel.outports.bControl_Type;
//    TX_Param.SetFunction = *x2cModel.outports.bFunction_Type;
//    TX_Param.SetSpeedValue = (uint16_t)*x2cModel.outports.bSetPointSpeed;
//    TX_Param.SetTorqueValue = (uint16_t)*x2cModel.outports.bSetPointTorque;
}

// *****************************************************************************
void Reset_Position(void)
{
    
    gPositionCalc.QDECcnt = 0;
    gPositionCalc.posCompensation = 0;
    gPositionCalc.posCntTmp = 0;
    gPositionCalc.posCntElec = 0;
    gPositionCalc.posCntMech = 0;
    gPositionCalc.QDECcntZ = gPositionCalc.QDECcnt;
    
    gPositionCalc.present_position_count = 0;
    gPositionCalc.prev_position_count = gPositionCalc.present_position_count;
    
    rotor_elec_count = 0;
    rotor_mech_count = 0;
    pos_count_diff = 0;
    speed_elec = 0.0;
    rotor_speed_count = 0;
}
