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

#include "variant.h"

/*
 * Pins descriptions
 */

// TCC0 IOSET6
// TCC1 IOSET1
// TCC2 IOSET1
const PinDescription g_APinDescription[]=
{
  // 0..5 - External Pins
  // ----------------------------------
  // 0..1 I2C pins (SDA/SCL)
  { PORTA, 12, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, TC2_CH0, EXTERNAL_INT_12 }, 				// 00:SERCOM 2.0 (D0)
  { PORTA, 13, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, TC2_CH1, EXTERNAL_INT_13 }, 				// 01:SERCOM 2.1 (D1)
  // 2..5 - SPI pins (SS/SCK/MISO/MOSI)
  { PORTA, 16, PIO_SERCOM, PIN_ATTR_PWM_F, No_ADC_Channel, TCC1_CH0, TC2_CH0, EXTERNAL_INT_0 }, 					// 02:SERCOM 1.0 (D2)
  { PORTA, 17, PIO_SERCOM, PIN_ATTR_PWM_F, No_ADC_Channel, TCC1_CH1, TC2_CH1, EXTERNAL_INT_1 }, 					// 03:SERCOM 1.1 (D3)
  { PORTA, 18, PIO_SERCOM, PIN_ATTR_PWM_F, No_ADC_Channel, TCC1_CH2, TC3_CH0, EXTERNAL_INT_2 }, 					// 04:SERCOM 1.2 (D4)
  { PORTA, 19, PIO_SERCOM, PIN_ATTR_PWM_F, No_ADC_Channel, TCC1_CH3, TC3_CH1, EXTERNAL_INT_3 }, 					// 05:SERCOM 1.3 (D5)
  
  // 6..7 UART pins (TX/RX)
  // ----------------------------------
  { PORTA, 4, PIO_SERCOM_ALT, (PIN_ATTR_ANALOG|PIN_ATTR_PWM_E), ADC_Channel4, TC0_CH0, TC0_CH0, EXTERNAL_INT_4 },	// 06:SERCOM 0.0(A0)
  { PORTA, 5, PIO_SERCOM_ALT, (PIN_ATTR_ANALOG|PIN_ATTR_PWM_E), ADC_Channel5, TC0_CH1, TC0_CH1, EXTERNAL_INT_5 },	// 07:SERCOM 0.1(A1)
  // 8..9 - Analog pins
  // ----------------------------------
  { PORTA, 6, PIO_ANALOG, (PIN_ATTR_ANALOG|PIN_ATTR_PWM_E), ADC_Channel6, TC1_CH0, TC1_CH0, EXTERNAL_INT_6 },		// 08:A2
  { PORTA, 7, PIO_ANALOG, (PIN_ATTR_ANALOG|PIN_ATTR_PWM_E), ADC_Channel7, TC1_CH1, TC1_CH1, EXTERNAL_INT_7 },		// 09:A3
  
  // 10..13 - DIP Switch
  // ----------------------------------
  { PORTA, 2, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2 },			// 10:DIP SW0
  { PORTA, 3, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3 }, 			// 11:DIP SW1
  { PORTB, 2, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2 }, 			// 12:DIP SW2
  { PORTB, 3, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3 }, 			// 13:DIP SW3
  
  // 14..16 - Other
  // ----------------------------------
  { PORTA, 14, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC2_CH0, TC3_CH0, EXTERNAL_INT_14 }, 					// 14:I2CPULLEN
  { PORTA, 15, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC2_CH1, TC3_CH1, EXTERNAL_INT_15 }, 					// 15:LED RED
  { PORTA, 20, PIO_DIGITAL, PIN_ATTR_PWM_G, No_ADC_Channel, TCC0_CH0, NOT_ON_TIMER, EXTERNAL_INT_4 }, 				// 16:LED GREEN
  
  // 17..20 IM920sL
  // ----------------------------------
  { PORTB, 22, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_6 },			// 17:920 BUSY
  { PORTB, 23, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },    	// 18:920 RESET
  { PORTB,  8, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_8 },		// 19:SERCOM 4.0 (920 TX (out))
  { PORTB,  9, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_9 },		// 20:SERCOM 4.1 (920 RX (in))
  
  // 21..24 IMBLE2
  // ----------------------------------
  { PORTA,  21, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_5 }, 			// 21:BLE BUSY
  { PORTA,  27, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, 		// 22:BLE RESET
  { PORTA,  23, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_7 }, 		// 23:SERCOM 5.0 (BLE TX (out))
  { PORTA,  22, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_6 }, 		// 24:SERCOM 5.1 (BLE RX (in))

  // 25..26- USB
  // --------------------
  { PORTA, 24, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_8 }, 					// 25:USB/DM
  { PORTA, 25, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_9 }, 					// 26:USB/DP


  // ----------------------
  // 27 - 32 QSPI (SCK, CS, IO0, IO1, IO2, IO3)
  { PORTB, 10, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_10 },					// 27:
  { PORTB, 11, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_11 },					// 28:
  { PORTA, 8, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NMI },					// 29:
  { PORTA, 9, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_9 },					// 30:
  { PORTA, 10, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_10 },					// 31:
  { PORTA, 11, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_11 },					// 32:
  
} ;

const void* g_apTCInstances[TCC_INST_NUM+TC_INST_NUM]={ TCC0, TCC1, TCC2, TC0, TC1, TC2, TC3 } ;
const uint32_t GCLK_CLKCTRL_IDs[TCC_INST_NUM+TC_INST_NUM] = { TCC0_GCLK_ID, TCC1_GCLK_ID, TCC2_GCLK_ID, TC0_GCLK_ID, TC1_GCLK_ID, TC2_GCLK_ID, TC3_GCLK_ID } ;

// Multi-serial objects instantiation
SERCOM sercom0( SERCOM0 ) ;
SERCOM sercom1( SERCOM1 ) ;
SERCOM sercom2( SERCOM2 ) ;
SERCOM sercom3( SERCOM3 ) ;
SERCOM sercom4( SERCOM4 ) ;
SERCOM sercom5( SERCOM5 ) ;

Uart Serial1( &sercom0, PIN_SERIAL1_RX, PIN_SERIAL1_TX, PAD_SERIAL1_RX, PAD_SERIAL1_TX ) ;

void SERCOM0_0_Handler()
{
  Serial1.IrqHandler();
}
void SERCOM0_1_Handler()
{
  Serial1.IrqHandler();
}
void SERCOM0_2_Handler()
{
  Serial1.IrqHandler();
}
void SERCOM0_3_Handler()
{
  Serial1.IrqHandler();
}