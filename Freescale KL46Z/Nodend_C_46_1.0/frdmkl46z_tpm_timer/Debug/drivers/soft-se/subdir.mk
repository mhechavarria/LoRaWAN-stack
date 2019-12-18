################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/soft-se/aes.c \
../drivers/soft-se/cmac.c \
../drivers/soft-se/soft-se.c 

OBJS += \
./drivers/soft-se/aes.o \
./drivers/soft-se/cmac.o \
./drivers/soft-se/soft-se.o 

C_DEPS += \
./drivers/soft-se/aes.d \
./drivers/soft-se/cmac.d \
./drivers/soft-se/soft-se.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/soft-se/%.o: ../drivers/soft-se/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MKL46Z256VLL4 -DCPU_MKL46Z256VLL4_cm0plus -DFRDM_KL46Z -DFREEDOM -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I../board -I../source -I../ -I../drivers -I../CMSIS -I../startup -I../utilities -I../board/src -O0 -fno-common -g -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


