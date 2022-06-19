################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ciaa_adc_api_m0.c \
../src/ciaa_dac_api_m0.c \
../src/ciaa_gpio_api_m0.c \
../src/ciaa_lcd_api_m0.c \
../src/ciaa_multicore_api_m0.c \
../src/ciaa_pwm_api_m0.c \
../src/ciaa_scu_api_m4.c \
../src/ciaa_stdlib_m0.c \
../src/ciaa_timer_api_m0.c \
../src/ciaa_uart_api_m0.c 

OBJS += \
./src/ciaa_adc_api_m0.o \
./src/ciaa_dac_api_m0.o \
./src/ciaa_gpio_api_m0.o \
./src/ciaa_lcd_api_m0.o \
./src/ciaa_multicore_api_m0.o \
./src/ciaa_pwm_api_m0.o \
./src/ciaa_scu_api_m4.o \
./src/ciaa_stdlib_m0.o \
./src/ciaa_timer_api_m0.o \
./src/ciaa_uart_api_m0.o 

C_DEPS += \
./src/ciaa_adc_api_m0.d \
./src/ciaa_dac_api_m0.d \
./src/ciaa_gpio_api_m0.d \
./src/ciaa_lcd_api_m0.d \
./src/ciaa_multicore_api_m0.d \
./src/ciaa_pwm_api_m0.d \
./src/ciaa_scu_api_m4.d \
./src/ciaa_stdlib_m0.d \
./src/ciaa_timer_api_m0.d \
./src/ciaa_uart_api_m0.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -D__REDLIB__ -DCORE_M0 -D__USE_LPCOPEN -D__LPC43XX__ -I"D:\Facultad\Quinto\TD III\ciaa-api\api\ciaa_api_common" -I"D:\Facultad\Quinto\TD III\ciaa-api\api\ciaa_api_m0\inc" -I"D:\Facultad\Quinto\TD III\ciaa-api\chip\lpc_chip_43xx_m0\inc" -I"D:\Facultad\Quinto\TD III\ciaa-api\chip\lpc_chip_43xx_m0\inc\config_43xx_m0app" -I"D:\Facultad\Quinto\TD III\ciaa-api\chip\lpc_chip_43xx_m0\inc\usbd_rom" -I/ciaa_api_common/inc -I"D:\Facultad\Quinto\TD III\ciaa-api\api\ciaa_api_common\inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


