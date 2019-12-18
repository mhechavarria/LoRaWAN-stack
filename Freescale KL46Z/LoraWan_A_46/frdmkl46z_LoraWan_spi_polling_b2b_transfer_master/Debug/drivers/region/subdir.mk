################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/region/Region.c \
../drivers/region/RegionAU915.c \
../drivers/region/RegionCommon.c 

OBJS += \
./drivers/region/Region.o \
./drivers/region/RegionAU915.o \
./drivers/region/RegionCommon.o 

C_DEPS += \
./drivers/region/Region.d \
./drivers/region/RegionAU915.d \
./drivers/region/RegionCommon.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/region/%.o: ../drivers/region/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MKL46Z256VLL4 -DCPU_MKL46Z256VLL4_cm0plus -DFRDM_KL46Z -DFREEDOM -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I../CMSIS -I../drivers -I../utilities -I../board -I../source -I../ -I../startup -I../board/src -O0 -fno-common -g -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


