/*!
 * \file      gpio-board.c
 *
 * \brief     Target board GPIO driver implementation
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

#include "gpio-board.h"
///
#include "fsl_port.h"
#include "fsl_gpio.h"
#include <MKL46Z4.h>
#include <stdint.h>
#include "fsl_port.h"
#include "radio/sx1276/sx1276.h"

uint8_t PUERTO_BASE;

/*
 * Esta función fue modificada para que carge los datos en el *obj y ponga
 * en LOW o HIGH si es una salida.
 * La inicialización del pin se hace directamente en el pin_mux.c
 */
void GpioMcuInit( Gpio_t *obj, PinNames pin, PinModes mode, PinConfigs config, PinTypes type, uint32_t value )
{

	obj->pin = GPIO_PIN(pin); //pin contiene el puero y el pin, entonces con la funcion saco solo el pin.
	PUERTO_BASE=GPIO_PORT(pin); //pin contiene el puero y el pin, entonces con la funcion saco solo el puerto.

    if( pin == NC )
    {
        return;
    }


    switch (PUERTO_BASE)
    {
    case 0x9U:
    	obj->port = GPIOA;
    	break;
    case 0xAU:
        obj->port = GPIOB;
        break;
    case 0xBU:
        obj->port = GPIOC;
        break;
    case 0xCU:
        obj->port = GPIOD;
        break;
    case 0xDU:
        obj->port = GPIOE;
        break;
    }

    if( mode == PIN_OUTPUT )
    {
        GpioMcuWrite( obj, value );
    }

}
void GpioMcuSetInterrupt( Gpio_t *obj, IrqModes irqMode, IrqPriorities irqPriority, GpioIrqHandler *irqHandler )
{
    //ext_irq_register( obj->pin, irqHandler );
}

void GpioMcuRemoveInterrupt( Gpio_t *obj )
{
    //ext_irq_register( obj->pin, NULL );
}

void GpioMcuWrite( Gpio_t *obj, uint32_t value )
{

    if( obj == NULL )
    {
        //assert_param( FAIL );
        while( 1 );
    }
    // Check if pin is not connected
    if( obj->pin == NC )
    {
        return;
    }
    GPIO_WritePinOutput(obj->port, obj->pin, value);
}

void GpioMcuToggle( Gpio_t *obj )
{
    if( obj == NULL )
    {
        //assert_param( FAIL );
        while( 1 );
    }

    // Check if pin is not connected
    if( obj->pin == NC )
    {
        return;
    }
    GPIO_TogglePinsOutput(obj->port,obj->pin);
}

uint32_t GpioMcuRead( Gpio_t *obj )
{
    if( obj == NULL )
    {
        //assert_param( FAIL );
        while( 1 );
    }
    // Check if pin is not connected
    if( obj->pin == NC )
    {
        return 0;
    }
    return ( uint32_t )GPIO_ReadPinInput(obj->port, obj->pin);
}


///////////////////////////////////////
//Manejador de interrupciones (PORTA)//
///////////////////////////////////////
void PORTA_IRQHandler(void)
{
	switch(PORT_GetPinsInterruptFlags(PORTA)){

	case ((uint32_t)1U<<6U): //Irq DIO0
    /* Clear external interrupt flag. */
    GPIO_PortClearInterruptFlags(GPIOA, 1U << 6);
	//printf("Dio0IRQ() \n");
	SX1276OnDio0Irq();
	//printf("***** Timestamp = %d \n",RtcGetTimerValue());
	break;

	case ((uint32_t)1U<<7U): //Irq DIO1
    /* Clear external interrupt flag. */
    GPIO_PortClearInterruptFlags(GPIOA, 1U << 7);
	//printf("Dio1IRQ() \n");
	SX1276OnDio1Irq();
	//printf("***** Timestamp = %d \n",RtcGetTimerValue());
	break;

	case ((uint32_t)1U<<13U): //Irq DIO2
    /* Clear external interrupt flag. */
    GPIO_PortClearInterruptFlags(GPIOA, 1U << 13);
	//printf("Dio2IRQ() \n");
	SX1276OnDio2Irq();
	break;

	case ((uint32_t)1U<<5U): //Irq DIO3
    /* Clear external interrupt flag. */
    GPIO_PortClearInterruptFlags(GPIOA, 1U << 5);
	//printf("Dio3IRQ() \n");
	SX1276OnDio3Irq();
	break;

	default:
	GPIO_PortClearInterruptFlags(GPIOA, 0xFFFFFFFF); //Limpio todos los flags
	break;

	}
}
