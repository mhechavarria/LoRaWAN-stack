/*!
 * \file      board-config.h
 *
 * \brief     Board configuration
 *
 * \copyright Revised BSD License, see section \ref LICENSE.
 *
 * \code
 *                ______                              _
 *               / _____)             _              | |
 *              ( (____  _____ ____ _| |_ _____  ____| |__
 *               \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 *               _____) ) ____| | | || |_| ____( (___| | | |
 *              (______/|_____)_|_|_| \__)_____)\____)_| |_|
 *              (C)2013-2017 Semtech
 *
 *               ___ _____ _   ___ _  _____ ___  ___  ___ ___
 *              / __|_   _/_\ / __| |/ / __/ _ \| _ \/ __| __|
 *              \__ \ | |/ _ \ (__| ' <| _| (_) |   / (__| _|
 *              |___/ |_/_/ \_\___|_|\_\_| \___/|_|_\\___|___|
 *              embedded.connectivity.solutions===============
 *
 * \endcode
 *
 * \author    Miguel Luis ( Semtech )
 *
 * \author    Gregory Cristian ( Semtech )
 *
 * \author    Daniel Jaeckle ( STACKFORCE )
 *
 * \author    Johannes Bruder ( STACKFORCE )
 *
 * \author    Marten Lootsma(TWTG) on behalf of Microchip/Atmel (c)2017
 */
#ifndef __BOARD_CONFIG_H__
#define __BOARD_CONFIG_H__
#include "MKL46Z4.h"
#include "gpio-board.h"
/*!
 * Defines the time required for the TCXO to wakeup [ms].
 */
#define BOARD_TCXO_WAKEUP_TIME                      0

/*!
 * Board MCU pins definitions
 */

#define RADIO_RESET                                 GPIO( PORTC_BASE, 13 )

#define RADIO_MOSI                                  GPIO( PORTA_BASE, 16 )
#define RADIO_MISO                                  GPIO( PORTA_BASE, 17 )
#define RADIO_SCLK                                  GPIO( PORTA_BASE, 15 )
#define RADIO_NSS                                   GPIO( PORTA_BASE, 14 )

#define RADIO_DIO_0                                 GPIO( PORTA_BASE, 6 )
#define RADIO_DIO_1                                 GPIO( PORTA_BASE, 7 )
#define RADIO_DIO_2                                 GPIO( PORTA_BASE, 13 )
#define RADIO_DIO_3                                 GPIO( PORTA_BASE, 5 )
//#define RADIO_DIO_4                                 GPIO( PORTA_BASE, 4 )
//#define RADIO_DIO_5                                 GPIO( PORTA_BASE, 12 )

// Debug pins definition.
#define LED_1										GPIO( PORTD_BASE,  5 )   //LED Verde
#define LED_2 										GPIO( PORTE_BASE,  29 )  //LED Rojo
#define LED_3 										GPIO( PORTC_BASE,  1 )   //LED Amarillo
/*
#define UART_TX                                     GPIO( GPIO_PORTA, 22 )
#define UART_RX                                     GPIO( GPIO_PORTA, 23 )

#define RADIO_DBG_PIN_TX
#define RADIO_DBG_PIN_RX

#define RTC_DBG_PIN_0
#define RTC_DBG_PIN_1

#define HWTMR_DBG_PIN_0                             GPIO( GPIO_PORTB, 30 )
*/

#endif // __BOARD_CONFIG_H__
