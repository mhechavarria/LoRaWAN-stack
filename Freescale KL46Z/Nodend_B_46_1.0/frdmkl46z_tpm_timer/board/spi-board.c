/*!
 * \file      spi-board.c
 *
 * \brief     Target board SPI driver implementation
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
 * \author    Marten Lootsma(TWTG) on behalf of Microchip/Atmel (c)2017
 */

#include "spi-board.h"
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "fsl_spi.h"
#include "fsl_port.h"
#include "board_46.h"
#include "pin_mux.h"
#include "clock_config.h"




/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define EXAMPLE_SPI_MASTER SPI0
#define EXAMPLE_SPI_MASTER_SOURCE_CLOCK kCLOCK_BusClk
#define EXAMPLE_SPI_MASTER_CLK_FREQ CLOCK_GetFreq(kCLOCK_BusClk)
/*******************************************************************************
 * Variables
 ******************************************************************************/
#define BUFFER_SIZE (1)
static uint8_t srcBuff[BUFFER_SIZE];
static uint8_t destBuff[BUFFER_SIZE];

spi_master_config_t userConfig = {0};
spi_transfer_t xfer = {0};
uint32_t srcFreq = 0;

void SpiInit( Spi_t *obj, SpiId_t spiId, PinNames mosi, PinNames miso, PinNames sclk, PinNames nss )
{
	SPI_MasterGetDefaultConfig(&userConfig);
	srcFreq = EXAMPLE_SPI_MASTER_CLK_FREQ;
	SPI_MasterInit(EXAMPLE_SPI_MASTER, &userConfig, srcFreq);

    GpioInit( &obj->Miso, miso, PIN_INPUT, PIN_PUSH_PULL, PIN_PULL_DOWN, 0 );
    GpioInit( &obj->Mosi, mosi, PIN_OUTPUT, PIN_PUSH_PULL, PIN_NO_PULL, 0 );
    GpioInit( &obj->Sclk, sclk, PIN_OUTPUT, PIN_PUSH_PULL, PIN_NO_PULL, 0 );
    GpioInit( &obj->Nss, nss, PIN_OUTPUT, PIN_PUSH_PULL, PIN_PULL_UP, 1 );
}


void SpiDeInit( Spi_t *obj )
{
    GpioInit( &obj->Mosi, obj->Mosi.pin, PIN_OUTPUT, PIN_PUSH_PULL, PIN_NO_PULL, 0 );
    GpioInit( &obj->Miso, obj->Miso.pin, PIN_INPUT, PIN_PUSH_PULL, PIN_PULL_DOWN, 0 );
    GpioInit( &obj->Sclk, obj->Sclk.pin, PIN_OUTPUT, PIN_PUSH_PULL, PIN_NO_PULL, 0 );
    GpioInit( &obj->Nss, obj->Nss.pin, PIN_OUTPUT, PIN_PUSH_PULL, PIN_PULL_UP, 1 );
}

uint16_t SpiInOut( Spi_t *obj, uint16_t outData )
{
	srcBuff[0]=(uint8_t)outData;
	xfer.txData = srcBuff;
	xfer.rxData = destBuff;
	xfer.dataSize = BUFFER_SIZE;
	SPI_MasterTransferBlocking(EXAMPLE_SPI_MASTER, &xfer);

	return (uint16_t)destBuff[0];
}
