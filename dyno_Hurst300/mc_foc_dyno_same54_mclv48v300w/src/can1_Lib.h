
/*******************************************************************************
  Motor Control Library Interface Header

  Company:
    Microchip Technology Inc. 

  File Name:  
    can1_Lib.h

  Summary:
    Motor Control Library Header File.

  Description:
    This file describes the macros, structures and APIs used by Motor Control Library for SAMD5x 
*******************************************************************************/


// DOM-IGNORE-BEGIN   
/*******************************************************************************
Copyright (c) <2018> released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/
#include <stdint.h>
#include <stdbool.h>

#ifndef _CAN1LIB_H
#define _CAN1LIB_H
// DOM-IGNORE-END

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Constants
// **n***************************************************************************
// *****************************************************************************

#define 	SLAVE    0xFF      // Device defined as Slave
#define 	MASTER   0         // Device defined as Master

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************
/*  Defines structures which contain input and output parameters for the motor control APIs
*/

//Structure containing variables used in CAN BUS communication
typedef struct 
{
    uint8_t DeviceType;
    uint8_t TimeBase;
    uint8_t PollingState; 
    uint8_t Flag;
    
    // MASTER parameters
    uint32_t TOTAL_RX_MASTER;
    uint32_t TOTAL_TX_MASTER;

    uint32_t TOTAL_RX_SLAVE;    
    uint32_t TOTAL_TX_SLAVE;
    
    // SLAVE parameters
    uint32_t TOTAL_RX_AFTER_FILTER;
    uint32_t TOTAL_TX_FROM_MASTER;
    uint32_t TOTAL_TX_TO_MASTER;
    
    uint8_t count_up;
    uint8_t count_dw;
}CAN1_PARAM, *PCAN1_PARAM;

//Structure containing variables used in CAN BUS communication
typedef struct 
{
     // ENABLE FUNCTION
    uint8_t SetControlType;
    uint8_t SetFunction;
    uint8_t Spare1;
    uint8_t Spare2;
    
    
    // SET POINT
    uint16_t SetSpeedValue;
    uint16_t SetTorqueValue;
    
    // MEASURES
    uint16_t ReadSpeedValue;
    uint16_t ReadPosition;
    uint16_t ReadCurrentPHA;
    uint16_t ReadCurrentPHB;

}COMM_PARAM, *PCOMM_PARAM;

typedef struct 
{
    uint32_t tx_ID;
    uint8_t tx_buffer[8];
    uint8_t tx_Length;

    uint32_t rx_ID;
    uint8_t rx_buffer[8];    
    uint8_t rx_Length;
}CAN1_DATA;

extern CAN1_PARAM Can1_Param;
extern CAN1_DATA Can1_M, Can1_S;
extern COMM_PARAM TX_Param;
extern COMM_PARAM RX_Param;

#define CAN1_DLC    8

#define END_RECEIVE     0x01
#define END_TRANSMIT    0x02

#define MASTER_REQ1                 0x7F0
#define MASTER_REQ2                 0x7F2
#define MASTER_REQ3                 0x7F4
#define MASTER_REQ_OUTSIDE_FILTER   0x200
#define MASTER_REQ_UNKNOWN          0x7FE

// Replies sent from SLAVE
#define SLAVE_ANSWER1               0x7F1
#define SLAVE_ANSWER2               0x7F3
#define SLAVE_ANSWER3               0x7F5


#define SPEED_MODE              1
#define TORQUE_MODE             2
#define OPEN_LOOP_MODE          3

#define NORMAL_MODE             1
#define FLUX_WEAKENING_MODE     2
#define WINDMILLING_MODE        3
#define TRAPEZOID_MODE          4

// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************
void CAN1Lib_Init(uint8_t, CAN1_PARAM *Param);
bool IsMaster(void);
void APP_CAN_Callback(uintptr_t context);
void HandleCan1State(void); 
void TestTimerCan1(void);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // #ifndef _CAN1LIB_H
/*******************************************************************************
 End of File
*/
