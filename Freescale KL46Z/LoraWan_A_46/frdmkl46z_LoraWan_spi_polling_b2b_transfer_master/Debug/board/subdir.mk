################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../board/board.c \
../board/delay-board.c \
../board/eeprom-board.c \
../board/rtc-board.c \
../board/spi-board.c \
../board/sx1276-board.c \
../board/uart-board.c \
../board/utilities.c 

OBJS += \
./board/board.o \
./board/delay-board.o \
./board/eeprom-board.o \
./board/rtc-board.o \
./board/spi-board.o \
./board/sx1276-board.o \
./board/uart-board.o \
./board/utilities.o 

C_DEPS += \
./board/board.d \
./board/delay-board.d \
./board/eeprom-board.d \
./board/rtc-board.d \
./board/spi-board.d \
./board/sx1276-board.d \
./board/uart-board.d \
./board/utilities.d 


# Each subdirectory must supply rules for building sources it contributes
board/%.o: ../board/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MKL46Z256VLL4 -DCPU_MKL46Z256VLL4_cm0plus -DFRDM_KL46Z -DFREEDOM -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I../CMSIS -I../drivers -I../utilities -I../board -I../source -I../ -I../startup -I../board/src -O0 -fno-common -g -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


