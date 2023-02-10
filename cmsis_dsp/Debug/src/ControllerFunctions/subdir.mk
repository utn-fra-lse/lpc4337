################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ControllerFunctions/ControllerFunctions.c \
../src/ControllerFunctions/arm_pid_init_f32.c \
../src/ControllerFunctions/arm_pid_init_q15.c \
../src/ControllerFunctions/arm_pid_init_q31.c \
../src/ControllerFunctions/arm_pid_reset_f32.c \
../src/ControllerFunctions/arm_pid_reset_q15.c \
../src/ControllerFunctions/arm_pid_reset_q31.c \
../src/ControllerFunctions/arm_sin_cos_f32.c \
../src/ControllerFunctions/arm_sin_cos_q31.c 

C_DEPS += \
./src/ControllerFunctions/ControllerFunctions.d \
./src/ControllerFunctions/arm_pid_init_f32.d \
./src/ControllerFunctions/arm_pid_init_q15.d \
./src/ControllerFunctions/arm_pid_init_q31.d \
./src/ControllerFunctions/arm_pid_reset_f32.d \
./src/ControllerFunctions/arm_pid_reset_q15.d \
./src/ControllerFunctions/arm_pid_reset_q31.d \
./src/ControllerFunctions/arm_sin_cos_f32.d \
./src/ControllerFunctions/arm_sin_cos_q31.d 

OBJS += \
./src/ControllerFunctions/ControllerFunctions.o \
./src/ControllerFunctions/arm_pid_init_f32.o \
./src/ControllerFunctions/arm_pid_init_q15.o \
./src/ControllerFunctions/arm_pid_init_q31.o \
./src/ControllerFunctions/arm_pid_reset_f32.o \
./src/ControllerFunctions/arm_pid_reset_q15.o \
./src/ControllerFunctions/arm_pid_reset_q31.o \
./src/ControllerFunctions/arm_sin_cos_f32.o \
./src/ControllerFunctions/arm_sin_cos_q31.o 


# Each subdirectory must supply rules for building sources it contributes
src/ControllerFunctions/%.o: ../src/ControllerFunctions/%.c src/ControllerFunctions/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -D__REDLIB__ -DCORE_M4 -D__USE_LPCOPEN -D__LPC43XX__ -I"/media/carlassaraf/DATA/facultad/TD III/2022_td3_512_carlassara/3.workspace/cmsis_dsp/inc" -I"/media/carlassaraf/DATA/facultad/TD III/2022_td3_512_carlassara/3.workspace/chip/lpc_chip_43xx/inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fsingle-precision-constant -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-ControllerFunctions

clean-src-2f-ControllerFunctions:
	-$(RM) ./src/ControllerFunctions/ControllerFunctions.d ./src/ControllerFunctions/ControllerFunctions.o ./src/ControllerFunctions/arm_pid_init_f32.d ./src/ControllerFunctions/arm_pid_init_f32.o ./src/ControllerFunctions/arm_pid_init_q15.d ./src/ControllerFunctions/arm_pid_init_q15.o ./src/ControllerFunctions/arm_pid_init_q31.d ./src/ControllerFunctions/arm_pid_init_q31.o ./src/ControllerFunctions/arm_pid_reset_f32.d ./src/ControllerFunctions/arm_pid_reset_f32.o ./src/ControllerFunctions/arm_pid_reset_q15.d ./src/ControllerFunctions/arm_pid_reset_q15.o ./src/ControllerFunctions/arm_pid_reset_q31.d ./src/ControllerFunctions/arm_pid_reset_q31.o ./src/ControllerFunctions/arm_sin_cos_f32.d ./src/ControllerFunctions/arm_sin_cos_f32.o ./src/ControllerFunctions/arm_sin_cos_q31.d ./src/ControllerFunctions/arm_sin_cos_q31.o

.PHONY: clean-src-2f-ControllerFunctions

