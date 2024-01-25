################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/UART/subdir.mk
-include MCAL/TIMER/subdir.mk
-include MCAL/GI/subdir.mk
-include MCAL/DIO/subdir.mk
-include HAL/ULTRASONIC/subdir.mk
-include HAL/SevenSegment/subdir.mk
-include HAL/SERVO/subdir.mk
-include HAL/BUZZER/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
AVRProject.lss \

FLASH_IMAGE += \
AVRProject.hex \

EEPROM_IMAGE += \
AVRProject.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: AVRProject.elf secondary-outputs

# Tool invocations
AVRProject.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,AVRProject.map -mmcu=atmega32 -o "AVRProject.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

AVRProject.lss: AVRProject.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S AVRProject.elf  >"AVRProject.lss"
	@echo 'Finished building: $@'
	@echo ' '

AVRProject.hex: AVRProject.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex AVRProject.elf  "AVRProject.hex"
	@echo 'Finished building: $@'
	@echo ' '

AVRProject.eep: AVRProject.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex AVRProject.elf  "AVRProject.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: AVRProject.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 AVRProject.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) AVRProject.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
