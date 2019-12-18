################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/mac/region/Region.c \
../drivers/mac/region/RegionAU915.c \
../drivers/mac/region/RegionCommon.c 

OBJS += \
./drivers/mac/region/Region.o \
./drivers/mac/region/RegionAU915.o \
./drivers/mac/region/RegionCommon.o 

C_DEPS += \
./drivers/mac/region/Region.d \
./drivers/mac/region/RegionAU915.d \
./drivers/mac/region/RegionCommon.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/mac/region/%.o: ../drivers/mac/region/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MKL46Z256VLL4 -DCPU_MKL46Z256VLL4_cm0plus -DFRDM_KL46Z -DFREEDOM -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I../board -I../source -I../ -I../drivers -I../CMSIS -I../startup -I../utilities -I../board/src -O0 -fno-common -g -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


