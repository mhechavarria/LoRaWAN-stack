################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/mac/LoRaMac.c \
../drivers/mac/LoRaMacAdr.c \
../drivers/mac/LoRaMacClassB.c \
../drivers/mac/LoRaMacCommands.c \
../drivers/mac/LoRaMacConfirmQueue.c \
../drivers/mac/LoRaMacCrypto.c \
../drivers/mac/LoRaMacFCntHandler.c \
../drivers/mac/LoRaMacParser.c \
../drivers/mac/LoRaMacSerializer.c 

OBJS += \
./drivers/mac/LoRaMac.o \
./drivers/mac/LoRaMacAdr.o \
./drivers/mac/LoRaMacClassB.o \
./drivers/mac/LoRaMacCommands.o \
./drivers/mac/LoRaMacConfirmQueue.o \
./drivers/mac/LoRaMacCrypto.o \
./drivers/mac/LoRaMacFCntHandler.o \
./drivers/mac/LoRaMacParser.o \
./drivers/mac/LoRaMacSerializer.o 

C_DEPS += \
./drivers/mac/LoRaMac.d \
./drivers/mac/LoRaMacAdr.d \
./drivers/mac/LoRaMacClassB.d \
./drivers/mac/LoRaMacCommands.d \
./drivers/mac/LoRaMacConfirmQueue.d \
./drivers/mac/LoRaMacCrypto.d \
./drivers/mac/LoRaMacFCntHandler.d \
./drivers/mac/LoRaMacParser.d \
./drivers/mac/LoRaMacSerializer.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/mac/%.o: ../drivers/mac/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MKL46Z256VLL4 -DCPU_MKL46Z256VLL4_cm0plus -DFRDM_KL46Z -DFREEDOM -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I../board -I../source -I../ -I../drivers -I../CMSIS -I../startup -I../utilities -I../board/src -O0 -fno-common -g -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


