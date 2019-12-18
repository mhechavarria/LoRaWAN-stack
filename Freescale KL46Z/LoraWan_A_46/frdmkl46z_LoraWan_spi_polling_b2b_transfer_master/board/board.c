/*!
 * \file      board.c
 *
 * \brief     Target board general functions implementation
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

#include "board-config.h"
#include "utilities.h"
#include "delay.h"
#include "gpio.h"
#include "adc.h"
#include "spi.h"
#include "uart.h"
#include "timer.h"
#include "rtc-board.h"
#include "board-config.h"
#include "sx1276-board.h"
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "pin_mux.h"
#include "peripherals.h"
#include "clock_config.h"
#include "fsl_cop.h"


/*
 * MCU objects
 */
Gpio_t Led1;
Gpio_t Led2;
Gpio_t Led3;
Uart_t Uart1;


cop_config_t configCop; //Variable para inicializar el WatchDog


/*!
 * Flag to indicate if the MCU is Initialized
 */
static bool McuInitialized = false;

void BoardCriticalSectionBegin( uint32_t *mask )
{
    *mask = __get_PRIMASK( );
    __disable_irq( );
    NVIC_DisableIRQ;
 //    DisableIRQ(PORTA_IRQn);


}

void BoardCriticalSectionEnd( uint32_t *mask )
{
    __set_PRIMASK( *mask );
   __enable_irq();
   NVIC_EnableIRQ;
  //  EnableIRQ(PORTA_IRQn);

}

void BoardInitPeriph( void )
{
	/*
	 * En esta  funcion se debe inicializar todos los pines del LED.
	 */

	BOARD_InitPins(); //Activo LEDs y DIOs

    GpioInit( &Led1, LED_1, PIN_OUTPUT, PIN_PUSH_PULL, PIN_NO_PULL, 1); //Verde TX (Ini LED Off, logica invertida)
    GpioInit( &Led2, LED_2, PIN_OUTPUT, PIN_PUSH_PULL, PIN_NO_PULL, 1); //Rojo RX (Ini LED Off, logica invertida)
    GpioInit( &Led3, LED_3, PIN_OUTPUT, PIN_PUSH_PULL, PIN_NO_PULL, 1); //Rojo RX (Ini LED Off, logica invertida)
}

void BoardInitMcu( void )
{
	/*
	 * En esta funcion se debe inicializar los perifericos: UART, SPI, RTC
	 */
	//ini watchdog
	 COP_GetDefaultConfig(&configCop); //Configura el timeout del WatchDog en 1 seg. aprox.
	 COP_Init(SIM, &configCop);
    //init_mcu( );
   //delay_init( SysTick );
   /* Set systick reload value to generate 1ms interrupt */
   	SysTick_Config(SystemCoreClock/1000U); //Este es del delay-board (inicializacion)

	SpiInit( &SX1276.Spi, SPI_1, RADIO_MOSI, RADIO_MISO, RADIO_SCLK, RADIO_NSS );
	RtcInit(); //Inicializacion RTC
	SX1276IoInit( ); //Declaraba los DIO, ahora se hace en la otra función
    //BOARD_InitBootPeripherals(); //Creo que no se necesita nada de aquí
/*
    hri_gclk_write_PCHCTRL_reg( GCLK, EIC_GCLK_ID, CONF_GCLK_EIC_SRC | ( 1 << GCLK_PCHCTRL_CHEN_Pos ) );
    hri_mclk_set_APBAMASK_EIC_bit( MCLK );

    UartInit( &Uart1, UART_1, UART_TX, UART_RX );
    UartConfig( &Uart1, RX_TX, 921600, UART_8_BIT, UART_1_STOP_BIT, NO_PARITY, NO_FLOW_CTRL );




*/

    McuInitialized = true;
}

void BoardResetMcu( void )
{
    CRITICAL_SECTION_BEGIN( );

    //Restart system
    NVIC_SystemReset( );

}

void BoardDeInitMcu( void )
{
	/*
	 * inicializar de nuevo el SPI, como que este es más directo
	 */

   SpiDeInit( &SX1276.Spi );
}

uint32_t BoardGetRandomSeed( void )
{
    return 0;
}

void BoardGetUniqueId( uint8_t *id )
{
    // We don't have an ID, so use the one from Commissioning.h
}



#if !defined ( __CC_ARM )

/*
 * Function to be used by stdout for printf etc
 */
int _write( int fd, const void *buf, size_t count )
{
    while( UartPutBuffer( &Uart1, ( uint8_t* )buf, ( uint16_t )count ) != 0 ){ };
    return count;
}

/*
 * Function to be used by stdin for scanf etc
 */
int _read( int fd, const void *buf, size_t count )
{
    size_t bytesRead = 0;
    while( UartGetBuffer( &Uart1, ( uint8_t* )buf, count, ( uint16_t* )&bytesRead ) != 0 ){ };
    // Echo back the character
    while( UartPutBuffer( &Uart1, ( uint8_t* )buf, ( uint16_t )bytesRead ) != 0 ){ };
    return bytesRead;
}

#else

// Keil compiler
int fputc( int c, FILE *stream )
{
    while( UartPutChar( &Uart1, ( uint8_t )c ) != 0 );
    return c;
}

int fgetc( FILE *stream )
{
    uint8_t c = 0;
    while( UartGetChar( &Uart1, &c ) != 0 );
    // Echo back the character
    while( UartPutChar( &Uart1, c ) != 0 );
    return ( int )c;
}

#endif

#ifdef USE_FULL_ASSERT
/*
 * Function Name  : assert_failed
 * Description    : Reports the name of the source file and the source line number
 *                  where the assert_param error has occurred.
 * Input          : - file: pointer to the source file name
 *                  - line: assert_param error line source number
 * Output         : None
 * Return         : None
 */
void assert_failed( uint8_t* file, uint32_t line )
{
    /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %u\r\n", file, line) */

    printf( "Wrong parameters value: file %s on line %u\r\n", ( const char* )file, line );
    /* Infinite loop */
    while( 1 )
    {
    }
}
#endif