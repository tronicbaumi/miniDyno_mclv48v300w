/*******************************************************************************
 Motor Control Library Filee - PLL Estimator

  Company:
    Microchip Technology Inc.

  File Name:
    can1_Lib.c

  Summary:
    This file contains the can bus routine for CAN1 Peripheral

  Description:
    This file contains the can bus routine for CAN1 Peripheral
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

#include "definitions.h"

#include "can1_Lib.h"

#include "config/default/X2CCode/X2CModel/Controller/Protocol/LNet/LNet.h" //El01
#include "config/default/X2CCode/X2CModel/ConfigX2C.h"
//#include "config/default/peripheral/can/plib_can_common.h"
//#include "config/default/peripheral/can/plib_can_common.h"

CAN1_PARAM Can1_Param;
COMM_PARAM TX_Param;
COMM_PARAM RX_Param;
CAN1_DATA Can1_M, Can1_S;

uint8_t Can1MessageRAM[CAN1_MESSAGE_RAM_CONFIG_SIZE] __attribute__((aligned (32)));

// *****************************************************************************
// *****************************************************************************
// Section: Init Can Bus
// *****************************************************************************
// *****************************************************************************
void CAN1Lib_Init(uint8_t TypeDevice, CAN1_PARAM *Param)
{
uint8_t j;

            /* Set Message RAM Configuration */
    CAN1_MessageRAMConfigSet(Can1MessageRAM);
    
    Param->DeviceType = TypeDevice;
    Param->TimeBase = 0;
    Param->PollingState = 1;// 0 skip MASTER_REQ1;
    Param->Flag = 0;
    Param->TOTAL_RX_AFTER_FILTER = 0;
    Param->TOTAL_TX_FROM_MASTER = 0;
    Param->TOTAL_TX_TO_MASTER = 0;

    Param->count_dw = Param->count_up = 0;
    
    // Init MASTER Data
    Can1_M.rx_ID = 0;
    Can1_M.tx_ID = 0x111;
    Can1_M.rx_Length = Can1_M.tx_Length = 0;
    for(j=0;j<CAN1_DLC;j++)Can1_M.rx_buffer[j] = Can1_M.tx_buffer[j] = 0;
    
    // Init SLAVE Data    
    Can1_S.rx_ID = Can1_S.tx_ID = Can1_S.rx_Length = Can1_S.tx_Length = 0;
    for(j=0;j<CAN1_DLC;j++)Can1_S.rx_buffer[j] = Can1_S.tx_buffer[j] = 0;
}


// *****************************************************************************
// *****************************************************************************
// Section: Check whether the board is MASTER or SLAVE
// *****************************************************************************
// *****************************************************************************
bool IsMaster(void)
{
    if(Can1_Param.DeviceType == MASTER)return true;
    else return false;
}

// *****************************************************************************
// *****************************************************************************
// Section: TestTimerCan1 
// *****************************************************************************
// *****************************************************************************
void TestTimerCan1(void)
{
    if(Can1_Param.TimeBase)Can1_Param.TimeBase--;  // called every 50us
}


// *****************************************************************************
// *****************************************************************************
// Section: HandleCan1State 
// *****************************************************************************
// *****************************************************************************
void HandleCan1State(void){
    uint8_t index = 0;    
    /* Check the application's current state. */    
    switch (can1Obj.state){ 
        case CAN_STATE_TRANSFER_RECEIVE:
            CAN1_CallbackRegister( APP_CAN_Callback, (uintptr_t)CAN_STATE_TRANSFER_RECEIVE );
            can1Obj.state = CAN_STATE_IDLE;
            /* Receive FIFO 0 New Message */
            ////////////////////////////////////////
            // Reply received from Slaves
            ///////////////////////////////////////
            if(IsMaster())
            {
                CAN1_MessageReceive(&Can1_M.rx_ID, &Can1_M.rx_Length, Can1_M.rx_buffer, CAN_MSG_ATTR_RX_FIFO0);
            }
            ////////////////////////////////////////
            // Request received from Master
            ///////////////////////////////////////
            else
            {
                CAN1_MessageReceive(&Can1_S.rx_ID, &Can1_S.rx_Length, Can1_S.rx_buffer, CAN_MSG_ATTR_RX_FIFO0);
            }
        break; 
        case CAN_STATE_TRANSFER_TRANSMIT:
            CAN1_CallbackRegister( APP_CAN_Callback, (uintptr_t)CAN_STATE_TRANSFER_TRANSMIT ); 
            can1Obj.state = CAN_STATE_IDLE;
            ////////////////////////////////////////
            // Transmit info from master to slaves
            ///////////////////////////////////////
            if(IsMaster())
            {
                CAN1_MessageTransmit(Can1_M.tx_ID, Can1_M.tx_Length, Can1_M.tx_buffer, CAN_MODE_NORMAL, CAN_MSG_ATTR_TX_FIFO_DATA_FRAME); 
            }
            ////////////////////////////////////////
            // Transmit reply to master request
            ///////////////////////////////////////
            else
            {
                CAN1_MessageTransmit(Can1_S.tx_ID, Can1_S.tx_Length, Can1_S.tx_buffer, CAN_MODE_NORMAL, CAN_MSG_ATTR_TX_FIFO_DATA_FRAME); 
            }
        break; 
        case CAN_STATE_IDLE: // Application can do other task here          
            //*************************************
            // MASTER Configuration
            //*************************************
            if(IsMaster())
            {   
                if(!Can1_Param.TimeBase){
                    // PREPARE MASTER TRANSMISSION
                    switch(Can1_Param.PollingState++){
                        case 0:                         
                            Can1_M.tx_ID = MASTER_REQ1;
                            Can1_M.tx_Length = 8;
                            Can1_M.tx_buffer[0]=(uint8_t)(Can1_Param.TOTAL_TX_MASTER>>24);
                            Can1_M.tx_buffer[1]=(uint8_t)(Can1_Param.TOTAL_TX_MASTER>>16);
                            Can1_M.tx_buffer[2]=(uint8_t)(Can1_Param.TOTAL_TX_MASTER>>8);
                            Can1_M.tx_buffer[3]=(uint8_t)Can1_Param.TOTAL_TX_MASTER;
                            Can1_M.tx_buffer[4]=0;
                            Can1_M.tx_buffer[5]=0;
                            Can1_M.tx_buffer[6]=0;
                            Can1_M.tx_buffer[7]=0;                            
                        break;
                        case 1:
                            Can1_M.tx_ID = MASTER_REQ2;
                            Can1_M.tx_Length = 8;
                            Can1_M.tx_buffer[0] = TX_Param.SetControlType;
                            Can1_M.tx_buffer[1] = TX_Param.SetFunction;
                            Can1_M.tx_buffer[2] = TX_Param.Spare1;
                            Can1_M.tx_buffer[3] = TX_Param.Spare2;
                            Can1_M.tx_buffer[4] = (uint8_t)(TX_Param.SetSpeedValue>>8);
                            Can1_M.tx_buffer[5] = (uint8_t)TX_Param.SetSpeedValue;
                            Can1_M.tx_buffer[6] = (uint8_t)(TX_Param.SetTorqueValue>>8);
                            Can1_M.tx_buffer[7] = (uint8_t)TX_Param.SetTorqueValue;
                        break;
                        case 2:
                            Can1_M.tx_ID = MASTER_REQ3;
                            Can1_M.tx_Length = 8;
                            Can1_M.tx_buffer[0] = 0;
                            Can1_M.tx_buffer[1] = 0;
                            Can1_M.tx_buffer[2] = 0;
                            Can1_M.tx_buffer[3] = 0;
                            Can1_M.tx_buffer[4] = 0;
                            Can1_M.tx_buffer[5] = 0;
                            Can1_M.tx_buffer[6] = 0;
                            Can1_M.tx_buffer[7] = 0;
/*                      break;
                        case 3: // outside Acceptance filters
                            Can1_M.tx_ID = MASTER_REQ_OUTSIDE_FILTER;
                            Can1_M.tx_Length = 0;                            
                        break;
                        case 4:
                            Can1_M.tx_ID = MASTER_REQ_UNKNOWN;
                            Can1_M.tx_Length = 0;*/
                        default:
                            Can1_Param.PollingState = 1;// 0 skip MASTER_REQ1;
                        break;                     
                    }
                    // restart TX-RX cycle
                    can1Obj.state = CAN_STATE_TRANSFER_TRANSMIT;    
                    Can1_Param.TimeBase = 20; // *50us
                }
                else if(Can1_Param.Flag & END_RECEIVE)
                {   
                    // VERIFY AND LOAD RECEIVED DATA
                    switch(Can1_M.rx_ID)
                    {
                        case SLAVE_ANSWER1:
                            if((Can1_M.tx_ID == MASTER_REQ1) && (Can1_M.rx_Length == CAN1_DLC))
                            {
                                Can1_Param.TOTAL_RX_SLAVE = ((uint32_t)Can1_M.rx_buffer[0]<<24) + ((uint32_t)Can1_M.rx_buffer[1]<<16) + ((uint32_t)Can1_M.rx_buffer[2]<<8) + (uint32_t)Can1_M.rx_buffer[3];               
                                Can1_Param.TOTAL_TX_SLAVE = ((uint32_t)Can1_M.rx_buffer[4]<<24) + ((uint32_t)Can1_M.rx_buffer[5]<<16) + ((uint32_t)Can1_M.rx_buffer[6]<<8) + (uint32_t)Can1_M.rx_buffer[7];               
                            }
                        break;
                        case SLAVE_ANSWER2:
                            if((Can1_M.tx_ID == MASTER_REQ2) && (Can1_M.rx_Length == CAN1_DLC))
                            {                                
                                RX_Param.ReadSpeedValue = ((uint16_t)Can1_M.rx_buffer[0]<<8) + (uint16_t)Can1_M.rx_buffer[1];
                                RX_Param.ReadPosition = ((uint16_t)Can1_M.rx_buffer[2]<<8) + (uint16_t)Can1_M.rx_buffer[3];
                                RX_Param.ReadCurrentPHA =((uint16_t)Can1_M.rx_buffer[4]<<8) + (uint16_t)Can1_M.rx_buffer[5];
                                RX_Param.ReadCurrentPHB = ((uint16_t)Can1_M.rx_buffer[6]<<8) + (uint16_t)Can1_M.rx_buffer[7];
                            }
                        break;                       
                        case SLAVE_ANSWER3:
                            if((Can1_M.tx_ID == MASTER_REQ3) && (Can1_M.rx_Length == CAN1_DLC))
                            {                                
                                Can1_Param.count_up = Can1_M.rx_buffer[0];
                                Can1_Param.count_dw = Can1_M.rx_buffer[7];
                            }
                        break;
                    }
                    Can1_Param.Flag &=~ END_RECEIVE;
                }
            }
            //*************************************
            // SLAVE Configuration
            //*************************************
            else
            {
                if(!Can1_Param.TimeBase)
                {
                    Can1_Param.count_dw--;
                    Can1_Param.count_up++;
                    Can1_Param.TimeBase = 200; // *50us
                }                
                if(Can1_Param.Flag & END_RECEIVE)
                {   
                    // prepare for transmission
                    can1Obj.state = CAN_STATE_TRANSFER_TRANSMIT;
                    // VERIFY AND LOAD RECEIVED DATA
                    // PREPARE SLAVE TRANSMISSION
                    switch(Can1_S.rx_ID)
                    {
                        case MASTER_REQ1:
                            // RX FRAME
                            // TX FRAME
                            Can1_Param.TOTAL_TX_FROM_MASTER = ((uint32_t)Can1_S.rx_buffer[0]<<24) + ((uint32_t)Can1_S.rx_buffer[1]<<16) + ((uint32_t)Can1_S.rx_buffer[2]<<8) + (uint32_t)Can1_S.rx_buffer[3];               
                            Can1_S.tx_ID = SLAVE_ANSWER1;
                            Can1_S.tx_Length = 8;
                            Can1_S.tx_buffer[0]=(uint8_t)(Can1_Param.TOTAL_RX_AFTER_FILTER>>24);
                            Can1_S.tx_buffer[1]=(uint8_t)(Can1_Param.TOTAL_RX_AFTER_FILTER>>16);
                            Can1_S.tx_buffer[2]=(uint8_t)(Can1_Param.TOTAL_RX_AFTER_FILTER>>8);
                            Can1_S.tx_buffer[3]=(uint8_t)Can1_Param.TOTAL_RX_AFTER_FILTER;
                            Can1_S.tx_buffer[4]=(uint8_t)(Can1_Param.TOTAL_TX_TO_MASTER>>24);
                            Can1_S.tx_buffer[5]=(uint8_t)(Can1_Param.TOTAL_TX_TO_MASTER>>16);
                            Can1_S.tx_buffer[6]=(uint8_t)(Can1_Param.TOTAL_TX_TO_MASTER>>8);
                            Can1_S.tx_buffer[7]=(uint8_t)Can1_Param.TOTAL_TX_TO_MASTER;
                        break;
                        case MASTER_REQ2:
                            // RX FRAME
                            RX_Param.SetControlType = Can1_S.rx_buffer[0];
                            RX_Param.SetFunction = Can1_S.rx_buffer[1];
                            RX_Param.Spare1 = Can1_S.rx_buffer[2];
                            RX_Param.Spare2 = Can1_S.rx_buffer[3];       
                            RX_Param.SetSpeedValue =((uint16_t)Can1_S.rx_buffer[4]<<8) + (uint16_t)Can1_S.rx_buffer[5];
                            RX_Param.SetTorqueValue = ((uint16_t)Can1_S.rx_buffer[6]<<8) + (uint16_t)Can1_S.rx_buffer[7];
                                
                            // TX FRAME
                            Can1_S.tx_ID = SLAVE_ANSWER2;
                            Can1_S.tx_Length = 8;
                            Can1_S.tx_buffer[0]=(uint8_t)(TX_Param.ReadSpeedValue>>8);
                            Can1_S.tx_buffer[1]=(uint8_t)TX_Param.ReadSpeedValue;
                            Can1_S.tx_buffer[2]=(uint8_t)(TX_Param.ReadPosition>>8);
                            Can1_S.tx_buffer[3]=(uint8_t)TX_Param.ReadPosition;
                            Can1_S.tx_buffer[4]=(uint8_t)(TX_Param.ReadCurrentPHA>>8);
                            Can1_S.tx_buffer[5]=(uint8_t)TX_Param.ReadCurrentPHA;
                            Can1_S.tx_buffer[6]=(uint8_t)(TX_Param.ReadCurrentPHB>>8);
                            Can1_S.tx_buffer[7]=(uint8_t)TX_Param.ReadCurrentPHB;                                                             
                        break;
                        case MASTER_REQ3:
                            // RX FRAME
                            // TX FRAME
                            Can1_S.tx_ID = SLAVE_ANSWER3;
                            Can1_S.tx_Length = 8;
                            for(index=1;index<8;index++)Can1_S.tx_buffer[index] = 0;
                            Can1_S.tx_buffer[0]=Can1_Param.count_up;
                            Can1_S.tx_buffer[7]=Can1_Param.count_dw;
                        break;                        
                        default:// go back to receive mode and discard current packet 
                            can1Obj.state = CAN_STATE_TRANSFER_RECEIVE;
                        break;
                    }
                    Can1_Param.Flag &=~ END_RECEIVE;
                }
            }
        default:
        break;
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: APP_CAN_Callback 
// *****************************************************************************
// *****************************************************************************
void APP_CAN_Callback(uintptr_t context){
    uint32_t status = 0;
    
    /* Check CAN Status */
    status = CAN1_ErrorGet(); 
    if (((status & CAN_PSR_LEC_Msk) == CAN_ERROR_NONE) || ((status & CAN_PSR_LEC_Msk) == CAN_ERROR_LEC_NC)) 
    {
        switch ((CAN_STATE)context){                 
            case CAN_STATE_TRANSFER_RECEIVE:
                // can1Obj.state = CAN_STATE_TRANSFER_TRANSMIT; commented in order move from interrupt to main
                Can1_Param.Flag |= END_RECEIVE;
                can1Obj.state = CAN_STATE_IDLE;
            break;
            case CAN_STATE_TRANSFER_TRANSMIT:
                can1Obj.state = CAN_STATE_TRANSFER_RECEIVE;
            break;
            default:
            break; 
        } 
    }
} 
