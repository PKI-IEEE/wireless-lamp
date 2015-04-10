################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
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
all: Lamp.axf

# Tool invocations
Lamp.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"C:\Users\Josh\Dropbox\Code\Lamp\CMSISv2p00_LPC13xx\Debug" -L"C:\Users\Josh\Dropbox\Code\Lamp\LPC13xx_cmsis2_Lib\Debug" -Xlinker -Map=Lamp.map -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "BalanceBot_Debug.ld" -o "Lamp.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) Lamp.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size Lamp.axf;  arm-none-eabi-objcopy -O binary Lamp.axf Lamp.bin ; checksum -p LPC1343 -d Lamp.bin;
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
