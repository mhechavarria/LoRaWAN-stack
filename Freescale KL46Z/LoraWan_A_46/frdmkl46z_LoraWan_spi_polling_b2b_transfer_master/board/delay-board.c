/*!
 * \file      delay-board.c
 *
 * \brief     Target board delay implementation
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
 * \endcode
 *
 * \author    Miguel Luis ( Semtech )
 *
 * \author    Gregory Cristian ( Semtech )
 *
 * \author    Johannes Bruder ( STACKFORCE )
 *
 * \author    Marten Lootsma(TWTG) on behalf of Microchip/Atmel (c)2017
 */


// #include <hal_delay.h>

// ver que libreria hace falta
#include "board_46.h" //esta es del
#include "fsl_gpio.h"

//#include "pin_mux.h"


#include "delay-board.h"

volatile uint32_t g_systickCounter;

void SysTick_Handler(void)
{
    if (g_systickCounter != 0U)
    {
        g_systickCounter--;

    }
}

void SysTick_DelayTicks(uint32_t n)
{
    g_systickCounter = n;
    while(g_systickCounter!= 0U)
    {
    }
}

void DelayMsMcu( uint32_t ms )
{
	SysTick_DelayTicks(ms);
  //  delay_ms( ms );

}
