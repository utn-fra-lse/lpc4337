################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../multicore_common/ipc_example.c \
../multicore_common/ipc_msg.c \
../multicore_common/m0_img_ldr.c 

OBJS += \
./multicore_common/ipc_example.o \
./multicore_common/ipc_msg.o \
./multicore_common/m0_img_ldr.o 

C_DEPS += \
./multicore_common/ipc_example.d \
./multicore_common/ipc_msg.d \
./multicore_common/m0_img_ldr.d 


# Each subdirectory must supply rules for building sources it contributes
multicore_common/%.o: ../multicore_common/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0 -D__USE_LPCOPEN -D__LPC43XX__ -D__REDLIB__ -D__MULTICORE_M0APP -DCORE_M0APP -I"D:\Facultad\Quinto\TD III\ciaa-api\examples\multicore\multicore_blinky\multicore_blinky_m0app\inc" -I"D:\Facultad\Quinto\TD III\ciaa-api\chip\lpc_chip_43xx_m0" -I"D:\Facultad\Quinto\TD III\ciaa-api\api\ciaa_api_m0" -I"D:\Facultad\Quinto\TD III\ciaa-api\api\ciaa_api_common" -I"D:\Facultad\Quinto\TD III\ciaa-api\chip\lpc_chip_43xx_m0\inc" -I"D:\Facultad\Quinto\TD III\ciaa-api\chip\lpc_chip_43xx_m0\inc\config_43xx_m0app" -I"D:\Facultad\Quinto\TD III\ciaa-api\chip\lpc_chip_43xx_m0\inc\usbd_rom" -I"D:\Facultad\Quinto\TD III\ciaa-api\api\ciaa_api_m0\inc" -I"D:\Facultad\Quinto\TD III\ciaa-api\api\ciaa_api_common\inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


