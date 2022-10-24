/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _VARIANT_IBDUAL_
#define _VARIANT_IBDUAL_

// The definitions here needs a SAMD core >=1.6.10
#define ARDUINO_SAMD_VARIANT_COMPLIANCE 10610

/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/

/** Frequency of the board main oscillator */
#define VARIANT_MAINOSC		(32768ul)

/** Master clock frequency */
#define VARIANT_MCK        (F_CPU)

#define VARIANT_GCLK0_FREQ (F_CPU)
#define VARIANT_GCLK1_FREQ (48000000UL)
#define VARIANT_GCLK2_FREQ (100000000UL)

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"

#ifdef __cplusplus
#include "SERCOM.h"
#include "Uart.h"
#endif // __cplusplus

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/

// Number of pins defined in PinDescription array
#define PINS_COUNT           (38u)
#define NUM_DIGITAL_PINS     (25u)
#define NUM_ANALOG_INPUTS    (4u)
#define NUM_ANALOG_OUTPUTS   (2u)
#define analogInputToDigitalPin(p)  ((p < NUM_ANALOG_INPUTS) ? (p) + PIN_A0 : -1)

#define digitalPinToPort(P)        ( &(PORT->Group[g_APinDescription[P].ulPort]) )
#define digitalPinToBitMask(P)     ( 1 << g_APinDescription[P].ulPin )
//#define analogInPinToBit(P)        ( )
#define portOutputRegister(port)   ( &(port->OUT.reg) )
#define portInputRegister(port)    ( &(port->IN.reg) )
#define portModeRegister(port)     ( &(port->DIR.reg) )
#define digitalPinHasPWM(P)        ( g_APinDescription[P].ulPWMChannel != NOT_ON_PWM || g_APinDescription[P].ulTCChannel != NOT_ON_TIMER )

/*
 * digitalPinToTimer(..) is AVR-specific and is not defined for SAMD
 * architecture. If you need to check if a pin supports PWM you must
 * use digitalPinHasPWM(..).
 *
 * https://github.com/arduino/Arduino/issues/1833
 */
// #define digitalPinToTimer(P)

#define LEDR			 (15u)	//LED Red
#define LEDG		 	 (16u)	//	  Green
#define I2C_PUEN		 (14u)	//I2C Pull En/Dis
#define DSW0			 (10u)	//DIP 0
#define DSW1			 (11u)	//    1
#define DSW2			 (12u)	//	  2
#define DSW3			 (13u)	//    3
#define IM_BUSY		 	 (17u)	//IM920sL BUSY
#define IM_RST		 	 (18u)	//		  RESET
#define IM_TXD			 (19u)	//        UART TxD
#define IM_RXD			 (20u)	//        UART RxD
#define BLE_BUSY		 (21u)	//IMBLE2  BUSY
#define BLE_IRQ			 (21u)	//        IRQ
#define BLE_RST		 	 (22u)	//	      RESET
#define BLE_TXD			 (23u)	//		  UART TxD SERCOM5.0 
#define BLE_RXD			 (24u)	//		  UART RxD SERCOM5.1
#define BLE_SCL			 (23u)	//		  I2C  SCL SERCOM3.1
#define BLE_SDA			 (24u)	//		  I2C  SDA SERCOM3.0
#define D0				 (0u)
#define D1				 (1u)
#define D2				 (2u)
#define D3				 (3u)
#define D4				 (4u)
#define D5				 (5u)
#define PIN_DAC			 (7ul)	//A1
#define TX				 (0u)
#define RX				 (1u)

#define LED_BUILTIN		 LEDG

/*
 * Analog pins
 */
#define PIN_A0               (6ul)
#define PIN_A1               (PIN_A0 + 1)
#define PIN_A2               (PIN_A0 + 2)
#define PIN_A3               (PIN_A0 + 3)
#define PIN_DAC0             DSW0
#define PIN_DAC1             PIN_A1

//static const uint8_t D0  = PIN_D0;
//static const uint8_t D1  = PIN_D1;
//static const uint8_t D2  = PIN_D2;
//static const uint8_t D3  = PIN_D3;
//static const uint8_t D4  = PIN_D4;
//static const uint8_t D5  = PIN_D5;
static const uint8_t A0  = PIN_A0;
static const uint8_t A1  = PIN_A1;
static const uint8_t A2  = PIN_A2;
static const uint8_t A3  = PIN_A3;

static const uint8_t DAC0 = PIN_DAC0;
static const uint8_t DAC1 = PIN_DAC1;

#define ADC_RESOLUTION		12

// Other pins
//#define PIN_ATN              (25ul)
//static const uint8_t ATN = PIN_ATN;

/*
 * Serial interfaces
 */

// Serial1
#define PIN_SERIAL1_TX       (6ul)	//PA4 / A0
#define PIN_SERIAL1_RX       (7ul)	//PA5 / A1
#define PAD_SERIAL1_RX       (SERCOM_RX_PAD_1)
#define PAD_SERIAL1_TX       (UART_TX_PAD_0)

/*
 * SPI Interfaces
 */
#define SPI_INTERFACES_COUNT     1

#define PIN_SPI_MISO         (4u)		// PA18
#define PIN_SPI_SCK          (3u)		// PA17
#define PIN_SPI_MOSI         (5u)		// PA19
#define PERIPH_SPI           sercom1
#define PAD_SPI_TX           SPI_PAD_3_SCK_1
#define PAD_SPI_RX           SERCOM_RX_PAD_2

static const uint8_t CS	  = D2 ;
static const uint8_t SS	  = D2 ;
static const uint8_t MOSI = PIN_SPI_MOSI ;
static const uint8_t MISO = PIN_SPI_MISO ;
static const uint8_t SCK  = PIN_SPI_SCK ;

/*
 * Wire Interfaces
 */
#define WIRE_INTERFACES_COUNT 1

#define PIN_WIRE_SDA         (0u)
#define PIN_WIRE_SCL         (1u)
#define PERIPH_WIRE          sercom2
#define WIRE_IT_HANDLER      SERCOM2_Handler
#define WIRE_IT_HANDLER_0    SERCOM2_0_Handler
#define WIRE_IT_HANDLER_1    SERCOM2_1_Handler
#define WIRE_IT_HANDLER_2    SERCOM2_2_Handler
#define WIRE_IT_HANDLER_3    SERCOM2_3_Handler

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

/*
 * USB
 */
#define USB_HOSTEN_UNUSED	// ipc
//#define PIN_USB_HOST_ENABLE (22ul)
#define PIN_USB_DM          (25ul)
#define PIN_USB_DP          (26ul)

/*
 * I2S Interfaces
 */
#define I2S_INTERFACES_COUNT 0

#define I2S_DEVICE          0
// no I2S on G19!

// On-board QSPI Flash
#define EXTERNAL_FLASH_DEVICES   GD25Q64C
#define EXTERNAL_FLASH_USE_QSPI

//QSPI Pins
#define PIN_QSPI_SCK	(27u)
#define PIN_QSPI_CS		(28u)
#define PIN_QSPI_IO0	(29u)
#define PIN_QSPI_IO1	(30u)
#define PIN_QSPI_IO2	(31u)
#define PIN_QSPI_IO3	(32u)

//PCC Pins
#if 0
#define PIN_PCC_DEN1    (PIN_SPI_MOSI)
#define PIN_PCC_DEN2    (PIN_SPI_SCK)
#define PIN_PCC_CLK     (PIN_SPI_MISO)
#define PIN_PCC_D0      (13u)
#define PIN_PCC_D1      (12u)
#define PIN_PCC_D2      (10u)
#define PIN_PCC_D3      (11u)
#define PIN_PCC_D4      (9u)
#define PIN_PCC_D5      (8u)
#define PIN_PCC_D6      (1u)
#define PIN_PCC_D7      (0u)
#define PIN_PCC_D8      (5u)
#define PIN_PCC_D9      (6u)
#endif

#if !defined(VARIANT_QSPI_BAUD_DEFAULT)
  // TODO: meaningful value for this
  #define VARIANT_QSPI_BAUD_DEFAULT 5000000
#endif

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus

/*	=========================
 *	===== SERCOM DEFINITION
 *	=========================
*/
extern SERCOM sercom0;
extern SERCOM sercom1;
extern SERCOM sercom2;
extern SERCOM sercom3;
extern SERCOM sercom4;
extern SERCOM sercom5;

extern Uart Serial1;

#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_USBVIRTUAL      Serial
#define SERIAL_PORT_MONITOR         Serial
// Serial has no physical pins broken out, so it's not listed as HARDWARE port
#define SERIAL_PORT_HARDWARE        Serial1
#define SERIAL_PORT_HARDWARE_OPEN   Serial1

#endif /* _VARIANT_IBDUAL_EXPRESS_ */

