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
all: multicore_blinky_m0app.axf

dependents:
	-cd D:/Facultad/Quinto/TD\ III/ciaa-api/api/ciaa_api_common/Debug && $(MAKE) clean all
	-cd D:/Facultad/Quinto/TD\ III/ciaa-api/api/ciaa_api_m0/Debug && $(MAKE) clean all
	-cd D:/Facultad/Quinto/TD\ III/ciaa-api/chip/lpc_chip_43xx_m0/Debug && $(MAKE) clean all

# Tool invocations
multicore_blinky_m0app.axf: $(OBJS) $(USER_OBJS) D:/Facultad/Quinto/TD\ III/ciaa-api/api/ciaa_api_common/Debug/libciaa_api_common.a D:/Facultad/Quinto/TD\ III/ciaa-api/api/ciaa_api_m0/Debug/libciaa_api_m0.a D:/Facultad/Quinto/TD\ III/ciaa-api/chip/lpc_chip_43xx_m0/Debug/liblpc_chip_43xx_m0.a
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"D:\Facultad\Quinto\TD III\ciaa-api\api\ciaa_api_m0\Debug" -L"D:\Facultad\Quinto\TD III\ciaa-api\api\ciaa_api_common\Debug" -L"D:\Facultad\Quinto\TD III\ciaa-api\chip\lpc_chip_43xx_m0\Debug" -Xlinker -Map="multicore_blinky_m0app.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m0 -mthumb -T "multicore_blinky_m0app_Debug.ld" -o "multicore_blinky_m0app.axf" $(OBJS) $(USER_OBJS) $(LIBS) && arm-none-eabi-objcopy --target elf32-littlearm --verbose --strip-all --remove-section=.ARM.attributes --redefine-sym __vectors_start__=__vectors_start___core_m0app --keep-symbol __vectors_start___core_m0app --redefine-sym _data=__start_data_core_m0app --keep-symbol __start_data_core_m0app --redefine-sym _edata=__end_data_core_m0app --keep-symbol __end_data_core_m0app --remove-section=".bss*" --remove-section=".noinit*" --rename-section .ARM.exidx=".core_m0app.ARM.exidx" --rename-section .ARM.extab=".core_m0app.ARM.extab" --rename-section .text=".core_m0app" --rename-section .data=".core_m0app.data" --rename-section .data_RAM2=".core_m0app.data_RAM2" --rename-section .data_RAM3=".core_m0app.data_RAM3" --rename-section .data_RAM4=".core_m0app.data_RAM4" "multicore_blinky_m0app.axf" "multicore_blinky_m0app.axf.o"
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) multicore_blinky_m0app.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "multicore_blinky_m0app.axf"; # arm-none-eabi-objcopy -v -O binary "multicore_blinky_m0app.axf" "multicore_blinky_m0app.bin" ; # checksum -p LPC4337_M0 -d "multicore_blinky_m0app.bin";
	-@echo ' '

.PHONY: all clean dependents post-build
D:/Facultad/Quinto/TD\ III/ciaa-api/api/ciaa_api_common/Debug/libciaa_api_common.a:
D:/Facultad/Quinto/TD\ III/ciaa-api/api/ciaa_api_m0/Debug/libciaa_api_m0.a:
D:/Facultad/Quinto/TD\ III/ciaa-api/chip/lpc_chip_43xx_m0/Debug/liblpc_chip_43xx_m0.a:

-include ../makefile.targets
