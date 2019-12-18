/*
 * The Clear BSD License
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted (subject to the limitations in the disclaimer below) provided
 * that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED BY THIS LICENSE.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v3.0
processor: MKL46Z256xxx4
package_id: MKL46Z256VLL4
mcu_data: ksdk2_0
processor_version: 0.0.9
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "MKL46Z4.h"
#include "pin_mux.h"


/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void)
{

    /* Port A Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortA);

    /* Port B Clock Gate Control: Clock enabled */
    //CLOCK_EnableClock(kCLOCK_PortB);

    /* Port C Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortC);

    /* Port D Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortD);

    /* Port EClock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortE);

    //Clock
    PORT_SetPinMux(PORTA, 18,  kPORT_PinDisabledOrAnalog);
    PORT_SetPinMux(PORTA, 19,  kPORT_PinDisabledOrAnalog);

    // RTC_CLKIN
    //PORT_SetPinMux(PORTC, 1U, kPORT_MuxAsGpio);

    //LED Verde
    gpio_pin_config_t led_green_config = {
            kGPIO_DigitalOutput, 1,
        };
    GPIO_PinInit(GPIOD,5U, &led_green_config);
    PORT_SetPinMux(PORTD, 5U, kPORT_MuxAsGpio);

    //LED Rojo
    gpio_pin_config_t led_red_config = {
            kGPIO_DigitalOutput, 1,
        };
    GPIO_PinInit(GPIOE,29U, &led_red_config);
    PORT_SetPinMux(PORTE, 29U, kPORT_MuxAsGpio);

    //LED Amarillo
    gpio_pin_config_t led_yellow_config = {
            kGPIO_DigitalOutput, 1,
        };
    GPIO_PinInit(GPIOC,1U, &led_yellow_config);
    PORT_SetPinMux(PORTC, 1U, kPORT_MuxAsGpio);

    //Reset
	gpio_pin_config_t gpioc_pin13_config = {
		        kGPIO_DigitalOutput,0,
	};
	GPIO_PinInit(GPIOC, 13U, &gpioc_pin13_config);
	PORT_SetPinMux(PORTC, 13U, kPORT_MuxAsGpio);

    //DIO 0
    const port_pin_config_t porta6_pin_config = {/* Internal pull-up resistor is enabled */
                                                    kPORT_PullUp,
                                                    /* Slow slew rate is configured */
                                                    kPORT_SlowSlewRate,
                                                    /* Passive filter is disabled */
                                                    kPORT_PassiveFilterDisable,
                                                    /* Low drive strength is configured */
                                                    kPORT_LowDriveStrength,
                                                    /* Pin is configured as PTC12 */
                                                    kPORT_MuxAsGpio};
    PORT_SetPinConfig(PORTA, 6U, &porta6_pin_config);

    gpio_pin_config_t gpioa_pin6_config = {
    			 kGPIO_DigitalInput,0,
    		};
    PORT_SetPinInterruptConfig(PORTA, 6U, kPORT_InterruptRisingEdge);
    GPIO_PinInit(GPIOA, 6U, &gpioa_pin6_config);
    PORT_SetPinMux(PORTA, 6U, kPORT_MuxAsGpio);

    //DIO 1
    const port_pin_config_t porta7_pin_config = {/* Internal pull-up resistor is enabled */
                                                    kPORT_PullUp,
                                                    /* Slow slew rate is configured */
                                                    kPORT_SlowSlewRate,
                                                    /* Passive filter is disabled */
                                                    kPORT_PassiveFilterDisable,
                                                    /* Low drive strength is configured */
                                                    kPORT_LowDriveStrength,
                                                    /* Pin is configured as PTC12 */
                                                    kPORT_MuxAsGpio};
    PORT_SetPinConfig(PORTA, 7U, &porta7_pin_config);

	gpio_pin_config_t gpioa_pin7_config = {
			 kGPIO_DigitalInput,0,
			};
	PORT_SetPinInterruptConfig(PORTA, 7U, kPORT_InterruptRisingEdge);
	GPIO_PinInit(GPIOA, 7U, &gpioa_pin7_config);
	PORT_SetPinMux(PORTA, 7U, kPORT_MuxAsGpio);

    //DIO 2
    const port_pin_config_t porta13_pin_config = {/* Internal pull-up resistor is enabled */
                                                    kPORT_PullUp,
                                                    /* Slow slew rate is configured */
                                                    kPORT_SlowSlewRate,
                                                    /* Passive filter is disabled */
                                                    kPORT_PassiveFilterDisable,
                                                    /* Low drive strength is configured */
                                                    kPORT_LowDriveStrength,
                                                    /* Pin is configured as PTC12 */
                                                    kPORT_MuxAsGpio};
    PORT_SetPinConfig(PORTA, 13U, &porta13_pin_config);
	gpio_pin_config_t gpioa_pin13_config = {
			 kGPIO_DigitalInput,0,
				};
	PORT_SetPinInterruptConfig(PORTA, 13U, kPORT_InterruptRisingEdge);
	GPIO_PinInit(GPIOA, 13U, &gpioa_pin13_config);
	PORT_SetPinMux(PORTA, 13U, kPORT_MuxAsGpio);


    //DIO 3
    const port_pin_config_t porta5_pin_config = {/* Internal pull-up resistor is enabled */
                                                    kPORT_PullUp,
                                                    /* Slow slew rate is configured */
                                                    kPORT_SlowSlewRate,
                                                    /* Passive filter is disabled */
                                                    kPORT_PassiveFilterDisable,
                                                    /* Low drive strength is configured */
                                                    kPORT_LowDriveStrength,
                                                    /* Pin is configured as PTC12 */
                                                    kPORT_MuxAsGpio};
    PORT_SetPinConfig(PORTA, 5U, &porta5_pin_config);
	gpio_pin_config_t gpioa_pin5_config = {
			 kGPIO_DigitalInput,0,
			};
	PORT_SetPinInterruptConfig(PORTA, 5U, kPORT_InterruptRisingEdge);
	GPIO_PinInit(GPIOA, 5U, &gpioa_pin5_config);
	PORT_SetPinMux(PORTA, 5U, kPORT_MuxAsGpio);

	EnableIRQ(PORTA_IRQn);

   // NSS - A la vieja escuela PTA-14
    /* PORTA14 (pin 44) is configured as SPI0_PCS0 */
	gpio_pin_config_t gpioa_pin14_config = {
			        kGPIO_DigitalOutput,0,
		};
	GPIO_PinInit(GPIOA, 14U, &gpioa_pin14_config);
	PORT_SetPinMux(PORTA, 14U, kPORT_MuxAsGpio);

    /* PORTA15 (pin 45) is configured as SPI0_SCK */
    PORT_SetPinMux(PORTA, 15U, kPORT_MuxAlt2);

    /* PORTA16 (pin 46) is configured as SPI0_MOSI */
    PORT_SetPinMux(PORTA, 16U, kPORT_MuxAlt2);

    /* PORTA17 (pin 47) is configured as SPI0_MISO */
    PORT_SetPinMux(PORTA, 17U, kPORT_MuxAlt2);


    /* PORTA1 (pin 35) is configured as UART0_RX */
    PORT_SetPinMux(PORTA, 1U, kPORT_MuxAlt2);

    /* PORTA2 (pin 36) is configured as UART0_TX */
    PORT_SetPinMux(PORTA, 2U, kPORT_MuxAlt2);

   // SIM->SCGC6 |= (0x20000000);

    SIM->SOPT5 = ((SIM->SOPT5 &
                   /* Mask bits to zero which are setting */
                   (~(SIM_SOPT5_UART0TXSRC_MASK | SIM_SOPT5_UART0RXSRC_MASK)))

                  /* UART0 Transmit Data Source Select: UART0_TX pin. */
                  | SIM_SOPT5_UART0TXSRC(SOPT5_UART0TXSRC_UART_TX)

                  /* UART0 Receive Data Source Select: UART_RX pin. */
                  | SIM_SOPT5_UART0RXSRC(SOPT5_UART0RXSRC_UART_RX));
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
