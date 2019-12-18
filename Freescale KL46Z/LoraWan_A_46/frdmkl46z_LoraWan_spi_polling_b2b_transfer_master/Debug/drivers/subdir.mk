################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/LoRaMac.c \
../drivers/LoRaMacAdr.c \
../drivers/LoRaMacClassB.c \
../drivers/LoRaMacCommands.c \
../drivers/LoRaMacConfirmQueue.c \
../drivers/LoRaMacCrypto.c \
../drivers/LoRaMacFCntHandler.c \
../drivers/LoRaMacParser.c \
../drivers/LoRaMacSerializer.c \
../drivers/adc.c \
../drivers/delay.c \
../drivers/eeprom.c \
../drivers/fifo.c \
../drivers/fsl_clock.c \
../drivers/fsl_common.c \
../drivers/fsl_cop.c \
../drivers/fsl_debug_console.c \
../drivers/fsl_ftfx_cache.c \
../drivers/fsl_ftfx_controller.c \
../drivers/fsl_ftfx_flash.c \
../drivers/fsl_ftfx_flexnvm.c \
../drivers/fsl_gpio.c \
../drivers/fsl_lpsci.c \
../drivers/fsl_pit.c \
../drivers/fsl_rtc.c \
../drivers/fsl_smc.c \
../drivers/fsl_spi.c \
../drivers/fsl_tpm.c \
../drivers/fsl_uart.c \
../drivers/gpio-board.c \
../drivers/gpio.c \
../drivers/nvmm.c \
../drivers/systime.c \
../drivers/timer.c \
../drivers/uart.c 

OBJS += \
./drivers/LoRaMac.o \
./drivers/LoRaMacAdr.o \
./drivers/LoRaMacClassB.o \
./drivers/LoRaMacCommands.o \
./drivers/LoRaMacConfirmQueue.o \
./drivers/LoRaMacCrypto.o \
./drivers/LoRaMacFCntHandler.o \
./drivers/LoRaMacParser.o \
./drivers/LoRaMacSerializer.o \
./drivers/adc.o \
./drivers/delay.o \
./drivers/eeprom.o \
./drivers/fifo.o \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_cop.o \
./drivers/fsl_debug_console.o \
./drivers/fsl_ftfx_cache.o \
./drivers/fsl_ftfx_controller.o \
./drivers/fsl_ftfx_flash.o \
./drivers/fsl_ftfx_flexnvm.o \
./drivers/fsl_gpio.o \
./drivers/fsl_lpsci.o \
./drivers/fsl_pit.o \
./drivers/fsl_rtc.o \
./drivers/fsl_smc.o \
./drivers/fsl_spi.o \
./drivers/fsl_tpm.o \
./drivers/fsl_uart.o \
./drivers/gpio-board.o \
./drivers/gpio.o \
./drivers/nvmm.o \
./drivers/systime.o \
./drivers/timer.o \
./drivers/uart.o 

C_DEPS += \
./drivers/LoRaMac.d \
./drivers/LoRaMacAdr.d \
./drivers/LoRaMacClassB.d \
./drivers/LoRaMacCommands.d \
./drivers/LoRaMacConfirmQueue.d \
./drivers/LoRaMacCrypto.d \
./drivers/LoRaMacFCntHandler.d \
./drivers/LoRaMacParser.d \
./drivers/LoRaMacSerializer.d \
./drivers/adc.d \
./drivers/delay.d \
./drivers/eeprom.d \
./drivers/fifo.d \
./drivers/fsl_clock.d \
./drivers/fsl_common.d \
./drivers/fsl_cop.d \
./drivers/fsl_debug_console.d \
./drivers/fsl_ftfx_cache.d \
./drivers/fsl_ftfx_controller.d \
./drivers/fsl_ftfx_flash.d \
./drivers/fsl_ftfx_flexnvm.d \
./drivers/fsl_gpio.d \
./drivers/fsl_lpsci.d \
./drivers/fsl_pit.d \
./drivers/fsl_rtc.d \
./drivers/fsl_smc.d \
./drivers/fsl_spi.d \
./drivers/fsl_tpm.d \
./drivers/fsl_uart.d \
./drivers/gpio-board.d \
./drivers/gpio.d \
./drivers/nvmm.d \
./drivers/systime.d \
./drivers/timer.d \
./drivers/uart.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MKL46Z256VLL4 -DCPU_MKL46Z256VLL4_cm0plus -DFRDM_KL46Z -DFREEDOM -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I../CMSIS -I../drivers -I../utilities -I../board -I../source -I../ -I../startup -I../board/src -O0 -fno-common -g -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


