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
all: multicore_blinky_m4.axf

dependents:
	-cd D:/Facultad/Quinto/TD\ III/ciaa-api/api/ciaa_api_common/Debug && $(MAKE) all
	-cd D:/Facultad/Quinto/TD\ III/ciaa-api/api/ciaa_api_m4/Debug && $(MAKE) all

# Tool invocations
multicore_blinky_m4.axf: $(OBJS) $(USER_OBJS) D:/Facultad/Quinto/TD\ III/ciaa-api/api/ciaa_api_common/Debug/libciaa_api_common.a D:/Facultad/Quinto/TD\ III/ciaa-api/api/ciaa_api_m4/Debug/libciaa_api_m4.a
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"D:\Facultad\Quinto\TD III\ciaa-api\api\ciaa_api_common\Debug" -L"D:\Facultad\Quinto\TD III\ciaa-api\chip\lpc_chip_43xx\Debug" -L"D:\Facultad\Quinto\TD III\ciaa-api\api\ciaa_api_m4\Debug" -Xlinker -Map="multicore_blinky_m4.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -T "multicore_blinky_m4_Debug.ld" -o "multicore_blinky_m4.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) multicore_blinky_m4.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "multicore_blinky_m4.axf"; # arm-none-eabi-objcopy -v -O binary "multicore_blinky_m4.axf" "multicore_blinky_m4.bin" ; # checksum -p LPC4337 -d "multicore_blinky_m4.bin";
	-@echo ' '

.PHONY: all clean dependents post-build
D:/Facultad/Quinto/TD\ III/ciaa-api/api/ciaa_api_common/Debug/libciaa_api_common.a:
D:/Facultad/Quinto/TD\ III/ciaa-api/api/ciaa_api_m4/Debug/libciaa_api_m4.a:

-include ../makefile.targets
