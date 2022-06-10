################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/cr_startup_lpc43xx.c \
../src/crp.c \
../src/sysinit.c \
../src/uart_rx_irq.c 

OBJS += \
./src/cr_startup_lpc43xx.o \
./src/crp.o \
./src/sysinit.o \
./src/uart_rx_irq.o 

C_DEPS += \
./src/cr_startup_lpc43xx.d \
./src/crp.d \
./src/sysinit.d \
./src/uart_rx_irq.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M4 -D__USE_LPCOPEN -DNO_BOARD_LIB -D__LPC43XX__ -D__REDLIB__ -I"D:\Facultad\Quinto\TD III\ciaa-api\chip\lpc_chip_43xx\inc" -I/ciaa_api -I"D:\Facultad\Quinto\TD III\ciaa-api\api\inc" -I"D:\Facultad\Quinto\TD III\ciaa-api\chip\lpc_chip_43xx\inc\config_43xx" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fsingle-precision-constant -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


