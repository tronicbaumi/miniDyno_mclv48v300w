/*******************************************************************************
  Device Configuration Routine Source File

  File Name:
    device_config.c

  Summary:
    This file includes subroutine for configuring the device
	to select oscillators, communication channels and resets.

  Description:
    Definitions in the file are for dsPIC33AK128MC106.
*******************************************************************************/
/*******************************************************************************
* Copyright (c) 2019 released Microchip Technology Inc.  All rights reserved.
*
* SOFTWARE LICENSE AGREEMENT:
* 
* Microchip Technology  ("Microchip") retains all ownership and
* intellectual property rights in the code aIncorporatedccompanying this message and in all
* derivatives hereto.  You may use this code, and any derivatives created by
* any person or entity by or on your behalf, exclusively with Microchip's
* proprietary products.  Your acceptance and/or use of this code constitutes
* agreement to the terms and conditions of this notice.
*
* CODE ACCOMPANYING THIS MESSAGE IS SUPPLIED BY MICROCHIP "AS IS".  NO
* WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
* TO, IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A
* PARTICULAR PURPOSE APPLY TO THIS CODE, ITS INTERACTION WITH MICROCHIP'S
* PRODUCTS, COMBINATION WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.
*
* YOU ACKNOWLEDGE AND AGREE THAT, IN NO EVENT, SHALL MICROCHIP BE LIABLE,
* WHETHER IN CONTRACT, WARRANTY, TORT (INCLUDING NEGLIGENCE OR BREACH OF
* STATUTORY DUTY),STRICT LIABILITY, INDEMNITY, CONTRIBUTION, OR OTHERWISE,
* FOR ANY INDIRECT, SPECIAL,PUNITIVE, EXEMPLARY, INCIDENTAL OR CONSEQUENTIAL
* LOSS, DAMAGE, FOR COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE CODE,
* HOWSOEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR
* THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT ALLOWABLE BY LAW,
* MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS CODE,
* SHALL NOT EXCEED THE PRICE YOU PAID DIRECTLY TO MICROCHIP SPECIFICALLY TO
* HAVE THIS CODE DEVELOPED.
*
* You agree that you are solely responsible for testing the code and
* determining its suitability.  Microchip has no obligation to modify, test,
* certify, or support the code.
*
*******************************************************************************/
// DSPIC33AK128MC106 Configuration Bit Settings

// 'C' source line config statements

// FCP
#pragma config FCP_CP = OFF             // Memory protection enable bit (Memory protection is disabled)
#pragma config FCP_CRC = OFF            // CRC enable bit (CRC is disabled)
#pragma config FCP_WPUCA = OFF          // User configuration areas write protection enable bits (Protection is disabled)

// FICD
// ChB #pragma config FICD_ICS = PGx1          // Debugger pins selection bits (PGx1 pins are used)
#pragma config FICD_JTAGEN = OFF         // JTAG enable bit (JTAG is enabled)

// FDEVOPT1
#pragma config FDEVOPT1_PWMLOCK = OFF    // PWM registers protection enable bit (Unlock sequence must be executed to write PWM registers)
#pragma config FDEVOPT1_ALTI2C1 = OFF   // Alternate I2C1 pins selection bit (Primary I2C1 pins are used)
#pragma config FDEVOPT1_ALTI2C2 = OFF   // Alternate I2C2 pins selection bit (Primary I2C2 pins are used)
#pragma config FDEVOPT1_BISTDIS = OFF   // Hardware RAM test disable bit (RAM test after reset is enabled)
#pragma config FDEVOPT1_SPI2MAPDIS = OFF// SPI2 peripheral pin selection disable bit (SPI2 pins are selected by peripheral pin selection feature)

// FWDT
#pragma config FWDT_WINEN = OFF          // Watchdog Timer Window Enable bit (Watchdog Timer operates in Window mode)
#pragma config FWDT_SWDTMPS = PS2147483648// Sleep Mode Watchdog Timer Post Scaler select bits (1:2147483648)
#pragma config FWDT_RCLKSEL = BPRC256   // Watchdog Timer Clock select bits (WDT Run Mode uses BFRC:256)
#pragma config FWDT_RWDTPS = PS2147483648// Run Mode Watchdog Timer Post Scaler select bits (1:2147483648)
#pragma config FWDT_WDTWIN = WIN25      // Watchdog Timer Window Size Select bits (WDT Window is 25% of WDT period)
#pragma config FWDT_WDTEN = HW          // Watchdog Timer Enable bit (WDT is enabled in hardware)
#pragma config FWDT_WDTRSTEN = OFF       // Watchdog Timer Reset Enable bit (WDT event generates a reset)

// FCPBKUP
#pragma config FCPBKUP_CP = OFF         // Memory protection enable bit backup (Memory protection is disabled)
#pragma config FCPBKUP_CRC = OFF        // CRC enable bit backup (CRC is disabled)
#pragma config FCPBKUP_WPUCA = OFF      // User configuration areas write protection enable bits backup (Protection is disabled)

// FICDBKUP
// ChB #pragma config FICDBKUP_ICS = PGx1      // Debugger pins selection bits backup (PGx1 pins are used)
#pragma config FICDBKUP_JTAGEN = OFF     // JTAG enable bit backup (JTAG is enabled)

// FDEVOPT1BKUP
#pragma config FDEVOPT1BKUP_PWMLOCK = OFF// PWM registers protection enable bit backup (Unlock sequence must be executed to write PWM registers)
#pragma config FDEVOPT1BKUP_ALTI2C1 = OFF// Alternate I2C1 pins selection bit backup (Primary I2C1 pins are used)
#pragma config FDEVOPT1BKUP_ALTI2C2 = OFF// Alternate I2C2 pins selection bit backup (Primary I2C2 pins are used)
#pragma config FDEVOPT1BKUP_BISTDIS = OFF// Hardware RAM test disable bit backup (RAM test after reset is enabled)
#pragma config FDEVOPT1BKUP_SPI2MAPDIS = OFF// SPI2 peripheral pin selection disable bit backup (SPI2 pins are selected by peripheral pin selection feature)

// FWDTBKUP
#pragma config FWDTBKUP_WINEN = OFF      // Watchdog Timer Window Enable bit backup (Watchdog Timer operates in Window mode)
#pragma config FWDTBKUP_SWDTMPS = PS2147483648// Sleep Mode Watchdog Timer Post Scaler select bits backup (1:2147483648)
#pragma config FWDTBKUP_RCLKSEL = BPRC256// Watchdog Timer Clock select bits backup (WDT Run Mode uses BFRC:256)
#pragma config FWDTBKUP_RWDTPS = PS2147483648// Run Mode Watchdog Timer Post Scaler select bits backup (1:2147483648)
#pragma config FWDTBKUP_WDTWIN = WIN25  // Watchdog Timer Window Size Select bits backup (WDT Window is 25% of WDT period)
#pragma config FWDTBKUP_WDTEN = HW      // Watchdog Timer Enable bit backup (WDT is enabled in hardware)
#pragma config FWDTBKUP_WDTRSTEN = OFF   // Watchdog Timer Reset Enable bit backup (WDT event generates a reset)

// FPR0CTRL
#pragma config FPR0CTRL_RDIS = ON       // Region protection disable bit (Protection is disabled)
#pragma config FPR0CTRL_EX = ON         // Execute permission bit (Code execution is enabled)
#pragma config FPR0CTRL_RD = ON         // Read permission bit (Read operation is enabled)
#pragma config FPR0CTRL_WR = ON         // Write permission bit (Write and erase operation is enabled)
#pragma config FPR0CTRL_CRC = ON        // CRC enable bit (NVM controller CRC calculation is enabled)
#pragma config FPR0CTRL_RTYPE = FIRMWARE// Region type selection bits (Firmware configurable region)

// FPR0ST
#pragma config FPR0ST_START = 0x7FF  // Region start address bits (Enter Hexadecimal value)

// FPR0END
#pragma config FPR0END_END = 0x7FF   // Region end address bits (Enter Hexadecimal value)

// FPR1CTRL
#pragma config FPR1CTRL_RDIS = ON       // Region protection disable bit (Protection is disabled)
#pragma config FPR1CTRL_EX = ON         // Execute permission bit (Code execution is enabled)
#pragma config FPR1CTRL_RD = ON         // Read permission bit (Read operation is enabled)
#pragma config FPR1CTRL_WR = ON         // Write permission bit (Write and erase operation is enabled)
#pragma config FPR1CTRL_CRC = ON        // CRC enable bit (NVM controller CRC calculation is enabled)
#pragma config FPR1CTRL_RTYPE = FIRMWARE// Region type selection bits (Firmware configurable region)

// FPR1ST
#pragma config FPR1ST_START = 0x7FF  // Region start address bits (Enter Hexadecimal value)

// FPR1END
#pragma config FPR1END_END = 0x7FF   // Region end address bits (Enter Hexadecimal value)

// FPR2CTRL
#pragma config FPR2CTRL_RDIS = ON       // Region protection disable bit (Protection is disabled)
#pragma config FPR2CTRL_EX = ON         // Execute permission bit (Code execution is enabled)
#pragma config FPR2CTRL_RD = ON         // Read permission bit (Read operation is enabled)
#pragma config FPR2CTRL_WR = ON         // Write permission bit (Write and erase operation is enabled)
#pragma config FPR2CTRL_CRC = ON        // CRC enable bit (NVM controller CRC calculation is enabled)
#pragma config FPR2CTRL_RTYPE = FIRMWARE// Region type selection bits (Firmware configurable region)

// FPR2ST
#pragma config FPR2ST_START = 0x7FF  // Region start address bits (Enter Hexadecimal value)

// FPR2END
#pragma config FPR2END_END = 0x7FF   // Region end address bits (Enter Hexadecimal value)

// FPR3CTRL
#pragma config FPR3CTRL_RDIS = ON       // Region protection disable bit (Protection is disabled)
#pragma config FPR3CTRL_EX = ON         // Execute permission bit (Code execution is enabled)
#pragma config FPR3CTRL_RD = ON         // Read permission bit (Read operation is enabled)
#pragma config FPR3CTRL_WR = ON         // Write permission bit (Write and erase operation is enabled)
#pragma config FPR3CTRL_CRC = ON        // CRC enable bit (NVM controller CRC calculation is enabled)
#pragma config FPR3CTRL_RTYPE = FIRMWARE// Region type selection bits (Firmware configurable region)

// FPR3ST
#pragma config FPR3ST_START = 0x7FF  // Region start address bits (Enter Hexadecimal value)

// FPR3END
#pragma config FPR3END_END = 0x7FF   // Region end address bits (Enter Hexadecimal value)

// FPR4CTRL
#pragma config FPR4CTRL_RDIS = ON       // Region protection disable bit (Protection is disabled)
#pragma config FPR4CTRL_EX = ON         // Execute permission bit (Code execution is enabled)
#pragma config FPR4CTRL_RD = ON         // Read permission bit (Read operation is enabled)
#pragma config FPR4CTRL_WR = ON         // Write permission bit (Write and erase operation is enabled)
#pragma config FPR4CTRL_CRC = ON        // CRC enable bit (NVM controller CRC calculation is enabled)
#pragma config FPR4CTRL_RTYPE = FIRMWARE// Region type selection bits (Firmware configurable region)

// FPR4ST
#pragma config FPR4ST_START = 0x7FF  // Region start address bits (Enter Hexadecimal value)

// FPR4END
#pragma config FPR4END_END = 0x7FF   // Region end address bits (Enter Hexadecimal value)

// FPR5CTRL
#pragma config FPR5CTRL_RDIS = ON       // Region protection disable bit (Protection is disabled)
#pragma config FPR5CTRL_EX = ON         // Execute permission bit (Code execution is enabled)
#pragma config FPR5CTRL_RD = ON         // Read permission bit (Read operation is enabled)
#pragma config FPR5CTRL_WR = ON         // Write permission bit (Write and erase operation is enabled)
#pragma config FPR5CTRL_CRC = ON        // CRC enable bit (NVM controller CRC calculation is enabled)
#pragma config FPR5CTRL_RTYPE = FIRMWARE// Region type selection bits (Firmware configurable region)

// FPR5ST
#pragma config FPR5ST_START = 0x7FF  // Region start address bits (Enter Hexadecimal value)

// FPR5END
#pragma config FPR5END_END = 0x7FF   // Region end address bits (Enter Hexadecimal value)

// FPR6CTRL
#pragma config FPR6CTRL_RDIS = ON       // Region protection disable bit (Protection is disabled)
#pragma config FPR6CTRL_EX = ON         // Execute permission bit (Code execution is enabled)
#pragma config FPR6CTRL_RD = ON         // Read permission bit (Read operation is enabled)
#pragma config FPR6CTRL_WR = ON         // Write permission bit (Write and erase operation is enabled)
#pragma config FPR6CTRL_CRC = ON        // CRC enable bit (NVM controller CRC calculation is enabled)
#pragma config FPR6CTRL_RTYPE = FIRMWARE// Region type selection bits (Firmware configurable region)

// FPR6ST
#pragma config FPR6ST_START = 0x7FF  // Region start address bits (Enter Hexadecimal value)

// FPR6END
#pragma config FPR6END_END = 0x7FF   // Region end address bits (Enter Hexadecimal value)

// FPR7CTRL
#pragma config FPR7CTRL_RDIS = ON       // Region protection disable bit (Protection is disabled)
#pragma config FPR7CTRL_EX = ON         // Execute permission bit (Code execution is enabled)
#pragma config FPR7CTRL_RD = ON         // Read permission bit (Read operation is enabled)
#pragma config FPR7CTRL_WR = ON         // Write permission bit (Write and erase operation is enabled)
#pragma config FPR7CTRL_CRC = ON        // CRC enable bit (NVM controller CRC calculation is enabled)
#pragma config FPR7CTRL_RTYPE = FIRMWARE// Region type selection bits (Firmware configurable region)

// FPR7ST
#pragma config FPR7ST_START = 0x7FF  // Region start address bits (Enter Hexadecimal value)

// FPR7END
#pragma config FPR7END_END = 0x7FF   // Region end address bits (Enter Hexadecimal value)

// FIRT
#pragma config FIRT_IRT = OFF           // Immutable Root of Trust enable bit (Immutable root of trust (IRT) regions are disabled)

// FSECDBG
#pragma config FSECDBG_SECDBG = OFF     // Secure debug enable bit (Secure debug is disabled)

// FPED
#pragma config FPED_ICSPPED = OFF       // ICSP Program and Erase disable bit (ICSP can program and erase)

// FEPUCB
//#pragma config FEPUCB_EPUCB = 0xF// UCB erase protection bits (Enter Hexadecimal value)

// FWPUCB
//#pragma config FWPUCB_WPUCB = 0xF// UCB write protection bits (Enter Hexadecimal value)

// FPR0CTRLBKUP
#pragma config FPR0CTRLBKUP_RDIS = ON   // Region protection disable bit backup (Protection is disabled)
#pragma config FPR0CTRLBKUP_EX = ON     // Execute permission bit backup (Code execution is enabled)
#pragma config FPR0CTRLBKUP_RD = ON     // Read permission bit backup (Read operation is enabled)
#pragma config FPR0CTRLBKUP_WR = ON     // Write permission bit backup (Write and erase operation is enabled)
#pragma config FPR0CTRLBKUP_CRC = ON    // CRC enable bit backup (NVM controller CRC calculation is enabled)
#pragma config FPR0CTRLBKUP_RTYPE = FIRMWARE// Region type selection bits backup (Firmware configurable region)

// FPR0STBKUP
#pragma config FPR0STBKUP_START = 0x7FF// Region start address bits backup (Enter Hexadecimal value)

// FPR0ENDBKUP
#pragma config FPR0ENDBKUP_END = 0x7FF// Region end address bits backup (Enter Hexadecimal value)

// FPR1CTRLBKUP
#pragma config FPR1CTRLBKUP_RDIS = ON   // Region protection disable bit backup (Protection is disabled)
#pragma config FPR1CTRLBKUP_EX = ON     // Execute permission bit backup (Code execution is enabled)
#pragma config FPR1CTRLBKUP_RD = ON     // Read permission bit backup (Read operation is enabled)
#pragma config FPR1CTRLBKUP_WR = ON     // Write permission bit backup (Write and erase operation is enabled)
#pragma config FPR1CTRLBKUP_CRC = ON    // CRC enable bit backup (NVM controller CRC calculation is enabled)
#pragma config FPR1CTRLBKUP_RTYPE = FIRMWARE// Region type selection bits backup (Firmware configurable region)

// FPR1STBKUP
#pragma config FPR1STBKUP_START = 0x7FF// Region start address bits backup (Enter Hexadecimal value)

// FPR1ENDBKUP
#pragma config FPR1ENDBKUP_END = 0x7FF// Region end address bits backup (Enter Hexadecimal value)

// FPR2CTRLBKUP
#pragma config FPR2CTRLBKUP_RDIS = ON   // Region protection disable bit backup (Protection is disabled)
#pragma config FPR2CTRLBKUP_EX = ON     // Execute permission bit backup (Code execution is enabled)
#pragma config FPR2CTRLBKUP_RD = ON     // Read permission bit backup (Read operation is enabled)
#pragma config FPR2CTRLBKUP_WR = ON     // Write permission bit backup (Write and erase operation is enabled)
#pragma config FPR2CTRLBKUP_CRC = ON    // CRC enable bit backup (NVM controller CRC calculation is enabled)
#pragma config FPR2CTRLBKUP_RTYPE = FIRMWARE// Region type selection bits backup (Firmware configurable region)

// FPR2STBKUP
#pragma config FPR2STBKUP_START = 0x7FF// Region start address bits backup (Enter Hexadecimal value)

// FPR2ENDBKUP
#pragma config FPR2ENDBKUP_END = 0x7FF// Region end address bits backup (Enter Hexadecimal value)

// FPR3CTRLBKUP
#pragma config FPR3CTRLBKUP_RDIS = ON   // Region protection disable bit backup (Protection is disabled)
#pragma config FPR3CTRLBKUP_EX = ON     // Execute permission bit backup (Code execution is enabled)
#pragma config FPR3CTRLBKUP_RD = ON     // Read permission bit backup (Read operation is enabled)
#pragma config FPR3CTRLBKUP_WR = ON     // Write permission bit backup (Write and erase operation is enabled)
#pragma config FPR3CTRLBKUP_CRC = ON    // CRC enable bit backup (NVM controller CRC calculation is enabled)
#pragma config FPR3CTRLBKUP_RTYPE = FIRMWARE// Region type selection bits backup (Firmware configurable region)

// FPR3STBKUP
#pragma config FPR3STBKUP_START = 0x7FF// Region start address bits backup (Enter Hexadecimal value)

// FPR3ENDBKUP
#pragma config FPR3ENDBKUP_END = 0x7FF// Region end address bits backup (Enter Hexadecimal value)

// FPR4CTRLBKUP
#pragma config FPR4CTRLBKUP_RDIS = ON   // Region protection disable bit backup (Protection is disabled)
#pragma config FPR4CTRLBKUP_EX = ON     // Execute permission bit backup (Code execution is enabled)
#pragma config FPR4CTRLBKUP_RD = ON     // Read permission bit backup (Read operation is enabled)
#pragma config FPR4CTRLBKUP_WR = ON     // Write permission bit backup (Write and erase operation is enabled)
#pragma config FPR4CTRLBKUP_CRC = ON    // CRC enable bit backup (NVM controller CRC calculation is enabled)
#pragma config FPR4CTRLBKUP_RTYPE = FIRMWARE// Region type selection bits backup (Firmware configurable region)

// FPR4STBKUP
#pragma config FPR4STBKUP_START = 0x7FF// Region start address bits backup (Enter Hexadecimal value)

// FPR4ENDBKUP
#pragma config FPR4ENDBKUP_END = 0x7FF// Region end address bits backup (Enter Hexadecimal value)

// FPR5CTRLBKUP
#pragma config FPR5CTRLBKUP_RDIS = ON   // Region protection disable bit backup (Protection is disabled)
#pragma config FPR5CTRLBKUP_EX = ON     // Execute permission bit backup (Code execution is enabled)
#pragma config FPR5CTRLBKUP_RD = ON     // Read permission bit backup (Read operation is enabled)
#pragma config FPR5CTRLBKUP_WR = ON     // Write permission bit backup (Write and erase operation is enabled)
#pragma config FPR5CTRLBKUP_CRC = ON    // CRC enable bit backup (NVM controller CRC calculation is enabled)
#pragma config FPR5CTRLBKUP_RTYPE = FIRMWARE// Region type selection bits backup (Firmware configurable region)

// FPR5STBKUP
#pragma config FPR5STBKUP_START = 0x7FF// Region start address bits backup (Enter Hexadecimal value)

// FPR5ENDBKUP
#pragma config FPR5ENDBKUP_END = 0x7FF//  end address bits backup (Enter Hexadecimal value)

// FPR6CTRLBKUP
#pragma config FPR6CTRLBKUP_RDIS = ON   // Region protection disable bit backup (Protection is disabled)
#pragma config FPR6CTRLBKUP_EX = ON     // Execute permission bit backup (Code execution is enabled)
#pragma config FPR6CTRLBKUP_RD = ON     // Read permission bit backup (Read operation is enabled)
#pragma config FPR6CTRLBKUP_WR = ON     // Write permission bit backup (Write and erase operation is enabled)
#pragma config FPR6CTRLBKUP_CRC = ON    // CRC enable bit backup (NVM controller CRC calculation is enabled)
#pragma config FPR6CTRLBKUP_RTYPE = FIRMWARE// Region type selection bits backup (Firmware configurable region)

// FPR6STBKUP
#pragma config FPR6STBKUP_START = 0x7FF// Region start address bits backup (Enter Hexadecimal value)

// FPR6ENDBKUP
#pragma config FPR6ENDBKUP_END = 0x7FF// Region end address bits backup (Enter Hexadecimal value)

// FPR7CTRLBKUP
#pragma config FPR7CTRLBKUP_RDIS = ON   // Region protection disable bit backup (Protection is disabled)
#pragma config FPR7CTRLBKUP_EX = ON     // Execute permission bit backup (Code execution is enabled)
#pragma config FPR7CTRLBKUP_RD = ON     // Read permission bit backup (Read operation is enabled)
#pragma config FPR7CTRLBKUP_WR = ON     // Write permission bit backup (Write and erase operation is enabled)
#pragma config FPR7CTRLBKUP_CRC = ON    // CRC enable bit backup (NVM controller CRC calculation is enabled)
#pragma config FPR7CTRLBKUP_RTYPE = FIRMWARE// Region type selection bits backup (Firmware configurable region)

// FPR7STBKUP
#pragma config FPR7STBKUP_START = 0x7FF// Region start address bits backup (Enter Hexadecimal value)

// FPR7ENDBKUP
#pragma config FPR7ENDBKUP_END = 0x7FF// Region end address bits backup (Enter Hexadecimal value)

// FIRTBKUP
#pragma config FIRTBKUP_IRT = OFF       // Immutable Root of Trust enable bit backup (Immutable root of trust (IRT) regions are disabled)

// FSECDBGBKUP
#pragma config FSECDBGBKUP_SECDBG = OFF // Secure debug enable bit backup (Secure debug is disabled)

// FPEDBKUP
#pragma config FPEDBKUP_ICSPPED = OFF   // ICSP Program and Erase disable bit backup (ICSP can program and erase)

// FEPUCBBKUP
//#pragma config FEPUCBBKUP_EPUCB = 0xFFF// UCB erase protection bits backup (Enter Hexadecimal value)

// FWPUCBBKUP
//#pragma config FWPUCBBKUP_WPUCB = 0xFFF// UCB write protection bits backup (Enter Hexadecimal value)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// *****************************************************************************
// *****************************************************************************