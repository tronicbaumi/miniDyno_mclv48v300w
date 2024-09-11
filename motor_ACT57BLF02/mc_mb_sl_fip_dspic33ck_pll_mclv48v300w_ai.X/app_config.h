/* Microchip Technology Inc. and its subsidiaries.  You may use this software
 * and any derivatives exclusively with Microchip products.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
 * TERMS.
 */

/*
 * File:
 * Author:
 * Comments:
 * Revision history:
 */

// This is a guard condition so that contents of this file are not included
// more than once.
#ifndef APP_CONFIG_H
#define	APP_CONFIG_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

// *****************************************************************************
// *****************************************************************************
// Section: Platform specific includes
// *****************************************************************************
// ***************************************************************************** 


#include "mcc_generated_files/motorBench/mcaf_main.h"
#include "mcc_generated_files/system/system.h"
#include "motorbench/system_state.h"
#include "motorbench/sat_PI.h"
#include "motorbench/filter.h"
#include "mcaf_sample_application.h"

#include "ringbuffer.h"

// *****************************************************************************
// *****************************************************************************
// Section: Enumeration of available data streaming formats
// *****************************************************************************
// *****************************************************************************
// Disable all data streaming
#define DATA_STREAMER_FORMAT_APP       0

// Dump data to uart in form suitable for MPLAB DV plugin
#define DATA_STREAMER_FORMAT_MDV        1


// *****************************************************************************
// *****************************************************************************
// Section: User configurable application level parameters
// *****************************************************************************
// *****************************************************************************

// Data streaming formatting selection
#ifndef DATA_STREAMER_FORMAT
#define DATA_STREAMER_FORMAT    DATA_STREAMER_FORMAT_MDV
#endif




// Size of  buffer in samples (must be power of 2)
#define BUF_LEN            128

// Type used to store and stream samples
#define SAMPLE_DATA_TYPE          int16_t

// Frame header byte for MPLAB DV
#define MDV_START_OF_FRAME      0xA5U


#define SAMPLES_PER_PACKET 1



// *****************************************************************************
// *****************************************************************************
// Section: Defines derived from user config parameters
// *****************************************************************************
// *****************************************************************************
#define NUM_AXES   (2)

#define RPM_CONVERSION_FACTOR 6.99f 

// The way the buffering works the following condition must be enforced
#if (BUF_LEN % SAMPLES_PER_PACKET) > 0
#error "SAMPLES_PER_PACKET must be a factor of BUF_LEN"
#endif

#define STREAM_FORMAT_IS(X) (defined(DATA_STREAMER_FORMAT_ ## X) && (DATA_STREAMER_FORMAT_ ## X == DATA_STREAMER_FORMAT))
 

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

typedef SAMPLE_DATA_TYPE sample_data_t;
typedef SAMPLE_DATA_TYPE sample_dataframe_t[NUM_AXES];
typedef SAMPLE_DATA_TYPE sample_datapacket_t[NUM_AXES*SAMPLES_PER_PACKET];


extern volatile ringbuffer_t data_sample_buffer;
extern volatile bool data_sample_buffer_overrun;

size_t __attribute__(( unused )) UART_Write(uint8_t *ptr, const size_t nbytes);



bool USART_Write( void *buffer, const size_t size );

/**
 * Measures Motor speed
 * @param appData application data
 */

uint16_t speed_measurement_local(APPLICATION_DATA *appData);
  
/**
 * Handles IQ and RPM values and writes to ring buffer
 */
    
void handle_iqrpm_value(void); 

/**
 * Reads Motor IQ and RPM values
 * @param apiData MCAPI data
 * @param appData application data
 */
    
void iqrpm_read(sample_data_t *ptr, MCAF_MOTOR_DATA *pmotor, APPLICATION_DATA *appdata);




#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* APP_CONFIG_H */
