/* ************************************************************************** */
/** X2CComm.c

  @Company
    Microchip Technology

  @Summary
    Implements the X2C Lin protocol connection with MCC Peripheral drivers.

 */
/* ************************************************************************** */
#include <xc.h>
#include "X2CscopeComm.h"

#include "../uart/uart1.h"

/** 
  @brief
    Puts the data to the hardware layer. (UART)
   @param[in] serial Serial interface object. (Not used)
   @param[in] data Data to send 
 */
void sendSerial(uint8_t data)
{
    MCC_UART_Write(data);
}

/** 
  @brief
   Get serial data from hardware. Reset the hardware in case of error. (UART2)
  @param[in] serial Serial interface object. (Not used)
  @return
    Return with the received data
 */
uint8_t receiveSerial()
{
    return MCC_UART_Read();
}

/** 
  @brief  Check data availability (UART).
  @param[in] serial Serial interface object. (Not used)
  @return
    True -> Serial data ready to read.
    False -> No data.
 */
uint8_t isReceiveDataAvailable()
{
    return MCC_UART_IsRxReady();
}

/** 
  @brief
   Check output buffer. (UART)
  @param[in] serial Serial interface object. (Not used)
  @return    
    True -> Transmit buffer is not full, at least one more character can be written.
    False -> Transmit buffer is full.
 */
uint8_t isSendReady()
{
    return MCC_UART_IsTxReady();
}
/* *****************************************************************************
 End of File
 */