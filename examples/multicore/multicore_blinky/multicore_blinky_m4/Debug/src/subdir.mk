################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/cr_startup_lpc43xx.c \
../src/multicore_blinky.c \
../src/sysinit.c 

OBJS += \
./src/cr_startup_lpc43xx.o \
./src/multicore_blinky.o \
./src/sysinit.o 

C_DEPS += \
./src/cr_startup_lpc43xx.d \
./src/multicore_blinky.d \
./src/sysinit.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M4 -D__USE_LPCOPEN -D__LPC43XX__ -D__REDLIB__ -DLPC43_MULTICORE_M0APP -D__MULTICORE_MASTER -D__MULTICORE_MASTER_SLAVE_M0APP -DNO_BOARD_LIB -I"D:\Facultad\Quinto\TD III\ciaa-api\api\ciaa_api_m4" -I"D:\Facultad\Quinto\TD III\ciaa-api\api\ciaa_api_common" -I"D:\Facultad\Quinto\TD III\ciaa-api\chip\lpc_chip_43xx\inc" -I"D:\Facultad\Quinto\TD III\ciaa-api\chip\lpc_chip_43xx\inc\config_43xx" -I"D:\Facultad\Quinto\TD III\ciaa-api\chip\lpc_chip_43xx\inc\usbd_rom" -I"D:\Facultad\Quinto\TD III\ciaa-api\examples\multicore\multicore_blinky\multicore_blinky_m4\inc" -I"D:\Facultad\Quinto\TD III\ciaa-api\api\ciaa_api_m4\inc" -I"D:\Facultad\Quinto\TD III\ciaa-api\api\ciaa_api_common\inc" -I"D:\Facultad\Quinto\TD III\ciaa-api\examples\multicore\multicore_blinky\multicore_blinky_m4\inc" -I"D:\Facultad\Quinto\TD III\ciaa-api\chip\lpc_chip_43xx" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fsingle-precision-constant -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


