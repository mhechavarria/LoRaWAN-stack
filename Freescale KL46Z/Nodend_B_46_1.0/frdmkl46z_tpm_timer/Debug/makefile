################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include utilities/subdir.mk
-include startup/subdir.mk
-include source/subdir.mk
-include drivers/system/subdir.mk
-include drivers/soft-se/subdir.mk
-include drivers/radio/sx1276/subdir.mk
-include drivers/mac/region/subdir.mk
-include drivers/mac/subdir.mk
-include drivers/subdir.mk
-include board/src/subdir.mk
-include board/subdir.mk
-include CMSIS/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: frdmkl46z_tpm_timer.axf

# Tool invocations
frdmkl46z_tpm_timer.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -Xlinker -Map="frdmkl46z_tpm_timer.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -Xlinker --sort-section=alignment -mcpu=cortex-m0plus -mthumb -T frdmkl46z_tpm_timer_Debug.ld -o "frdmkl46z_tpm_timer.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) frdmkl46z_tpm_timer.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "frdmkl46z_tpm_timer.axf"; # arm-none-eabi-objcopy -v -O binary "frdmkl46z_tpm_timer.axf" "frdmkl46z_tpm_timer.bin" ; # checksum -p MKL46Z256xxx4 -d "frdmkl46z_tpm_timer.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
