################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/system/adc.c \
../drivers/system/delay.c \
../drivers/system/eeprom.c \
../drivers/system/fifo.c \
../drivers/system/gpio.c \
../drivers/system/gps.c \
../drivers/system/i2c.c \
../drivers/system/nvmm.c \
../drivers/system/systime.c \
../drivers/system/timer.c \
../drivers/system/uart.c 

OBJS += \
./drivers/system/adc.o \
./drivers/system/delay.o \
./drivers/system/eeprom.o \
./drivers/system/fifo.o \
./drivers/system/gpio.o \
./drivers/system/gps.o \
./drivers/system/i2c.o \
./drivers/system/nvmm.o \
./drivers/system/systime.o \
./drivers/system/timer.o \
./drivers/system/uart.o 

C_DEPS += \
./drivers/system/adc.d \
./drivers/system/delay.d \
./drivers/system/eeprom.d \
./drivers/system/fifo.d \
./drivers/system/gpio.d \
./drivers/system/gps.d \
./drivers/system/i2c.d \
./drivers/system/nvmm.d \
./drivers/system/systime.d \
./drivers/system/timer.d \
./drivers/system/uart.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/system/%.o: ../drivers/system/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MKL46Z256VLL4 -DCPU_MKL46Z256VLL4_cm0plus -DFRDM_KL46Z -DFREEDOM -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I../board -I../source -I../ -I../drivers -I../CMSIS -I../startup -I../utilities -I../board/src -O0 -fno-common -g -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


