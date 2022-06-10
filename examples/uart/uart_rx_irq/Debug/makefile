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
all: uart_rx_irq.axf

dependents:
	-cd D:/Facultad/Quinto/TD\ III/ciaa-api/api/Debug && $(MAKE) all
	-cd D:/Facultad/Quinto/TD\ III/ciaa-api/examples/uart/uart_rx_irq/Release && $(MAKE) all

# Tool invocations
uart_rx_irq.axf: $(OBJS) $(USER_OBJS) D:/Facultad/Quinto/TD\ III/ciaa-api/api/Debug/libciaa_api.a D:/Facultad/Quinto/TD\ III/ciaa-api/examples/uart/uart_rx_irq/Release/uart_rx_irq.axf
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"D:\Facultad\Quinto\TD III\ciaa-api\api\Debug" -L"D:\Facultad\Quinto\TD III\ciaa-api\chip\lpc_chip_43xx\Debug" -Xlinker -Map="uart_rx_irq.map" -Xlinker --cref -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -T "uart_rx_irq_Debug.ld" -o "uart_rx_irq.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) uart_rx_irq.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "uart_rx_irq.axf"; # arm-none-eabi-objcopy -v -O binary "uart_rx_irq.axf" "uart_rx_irq.bin" ; # checksum -p LPC4337 -d "uart_rx_irq.bin";
	-@echo ' '

.PHONY: all clean dependents post-build
D:/Facultad/Quinto/TD\ III/ciaa-api/api/Debug/libciaa_api.a:
D:/Facultad/Quinto/TD\ III/ciaa-api/examples/uart/uart_rx_irq/Release/uart_rx_irq.axf:

-include ../makefile.targets
