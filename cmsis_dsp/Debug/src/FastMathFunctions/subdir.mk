################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/FastMathFunctions/FastMathFunctions.c \
../src/FastMathFunctions/FastMathFunctionsF16.c \
../src/FastMathFunctions/arm_atan2_f16.c \
../src/FastMathFunctions/arm_atan2_f32.c \
../src/FastMathFunctions/arm_atan2_q15.c \
../src/FastMathFunctions/arm_atan2_q31.c \
../src/FastMathFunctions/arm_cos_f32.c \
../src/FastMathFunctions/arm_cos_q15.c \
../src/FastMathFunctions/arm_cos_q31.c \
../src/FastMathFunctions/arm_divide_q15.c \
../src/FastMathFunctions/arm_divide_q31.c \
../src/FastMathFunctions/arm_sin_f32.c \
../src/FastMathFunctions/arm_sin_q15.c \
../src/FastMathFunctions/arm_sin_q31.c \
../src/FastMathFunctions/arm_sqrt_q15.c \
../src/FastMathFunctions/arm_sqrt_q31.c \
../src/FastMathFunctions/arm_vexp_f16.c \
../src/FastMathFunctions/arm_vexp_f32.c \
../src/FastMathFunctions/arm_vexp_f64.c \
../src/FastMathFunctions/arm_vinverse_f16.c \
../src/FastMathFunctions/arm_vlog_f16.c \
../src/FastMathFunctions/arm_vlog_f32.c \
../src/FastMathFunctions/arm_vlog_f64.c \
../src/FastMathFunctions/arm_vlog_q15.c \
../src/FastMathFunctions/arm_vlog_q31.c 

C_DEPS += \
./src/FastMathFunctions/FastMathFunctions.d \
./src/FastMathFunctions/FastMathFunctionsF16.d \
./src/FastMathFunctions/arm_atan2_f16.d \
./src/FastMathFunctions/arm_atan2_f32.d \
./src/FastMathFunctions/arm_atan2_q15.d \
./src/FastMathFunctions/arm_atan2_q31.d \
./src/FastMathFunctions/arm_cos_f32.d \
./src/FastMathFunctions/arm_cos_q15.d \
./src/FastMathFunctions/arm_cos_q31.d \
./src/FastMathFunctions/arm_divide_q15.d \
./src/FastMathFunctions/arm_divide_q31.d \
./src/FastMathFunctions/arm_sin_f32.d \
./src/FastMathFunctions/arm_sin_q15.d \
./src/FastMathFunctions/arm_sin_q31.d \
./src/FastMathFunctions/arm_sqrt_q15.d \
./src/FastMathFunctions/arm_sqrt_q31.d \
./src/FastMathFunctions/arm_vexp_f16.d \
./src/FastMathFunctions/arm_vexp_f32.d \
./src/FastMathFunctions/arm_vexp_f64.d \
./src/FastMathFunctions/arm_vinverse_f16.d \
./src/FastMathFunctions/arm_vlog_f16.d \
./src/FastMathFunctions/arm_vlog_f32.d \
./src/FastMathFunctions/arm_vlog_f64.d \
./src/FastMathFunctions/arm_vlog_q15.d \
./src/FastMathFunctions/arm_vlog_q31.d 

OBJS += \
./src/FastMathFunctions/FastMathFunctions.o \
./src/FastMathFunctions/FastMathFunctionsF16.o \
./src/FastMathFunctions/arm_atan2_f16.o \
./src/FastMathFunctions/arm_atan2_f32.o \
./src/FastMathFunctions/arm_atan2_q15.o \
./src/FastMathFunctions/arm_atan2_q31.o \
./src/FastMathFunctions/arm_cos_f32.o \
./src/FastMathFunctions/arm_cos_q15.o \
./src/FastMathFunctions/arm_cos_q31.o \
./src/FastMathFunctions/arm_divide_q15.o \
./src/FastMathFunctions/arm_divide_q31.o \
./src/FastMathFunctions/arm_sin_f32.o \
./src/FastMathFunctions/arm_sin_q15.o \
./src/FastMathFunctions/arm_sin_q31.o \
./src/FastMathFunctions/arm_sqrt_q15.o \
./src/FastMathFunctions/arm_sqrt_q31.o \
./src/FastMathFunctions/arm_vexp_f16.o \
./src/FastMathFunctions/arm_vexp_f32.o \
./src/FastMathFunctions/arm_vexp_f64.o \
./src/FastMathFunctions/arm_vinverse_f16.o \
./src/FastMathFunctions/arm_vlog_f16.o \
./src/FastMathFunctions/arm_vlog_f32.o \
./src/FastMathFunctions/arm_vlog_f64.o \
./src/FastMathFunctions/arm_vlog_q15.o \
./src/FastMathFunctions/arm_vlog_q31.o 


# Each subdirectory must supply rules for building sources it contributes
src/FastMathFunctions/%.o: ../src/FastMathFunctions/%.c src/FastMathFunctions/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -D__REDLIB__ -DCORE_M4 -D__USE_LPCOPEN -D__LPC43XX__ -I"/media/carlassaraf/DATA/facultad/TD III/2022_td3_512_carlassara/3.workspace/cmsis_dsp/inc" -I"/media/carlassaraf/DATA/facultad/TD III/2022_td3_512_carlassara/3.workspace/chip/lpc_chip_43xx/inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fsingle-precision-constant -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-FastMathFunctions

clean-src-2f-FastMathFunctions:
	-$(RM) ./src/FastMathFunctions/FastMathFunctions.d ./src/FastMathFunctions/FastMathFunctions.o ./src/FastMathFunctions/FastMathFunctionsF16.d ./src/FastMathFunctions/FastMathFunctionsF16.o ./src/FastMathFunctions/arm_atan2_f16.d ./src/FastMathFunctions/arm_atan2_f16.o ./src/FastMathFunctions/arm_atan2_f32.d ./src/FastMathFunctions/arm_atan2_f32.o ./src/FastMathFunctions/arm_atan2_q15.d ./src/FastMathFunctions/arm_atan2_q15.o ./src/FastMathFunctions/arm_atan2_q31.d ./src/FastMathFunctions/arm_atan2_q31.o ./src/FastMathFunctions/arm_cos_f32.d ./src/FastMathFunctions/arm_cos_f32.o ./src/FastMathFunctions/arm_cos_q15.d ./src/FastMathFunctions/arm_cos_q15.o ./src/FastMathFunctions/arm_cos_q31.d ./src/FastMathFunctions/arm_cos_q31.o ./src/FastMathFunctions/arm_divide_q15.d ./src/FastMathFunctions/arm_divide_q15.o ./src/FastMathFunctions/arm_divide_q31.d ./src/FastMathFunctions/arm_divide_q31.o ./src/FastMathFunctions/arm_sin_f32.d ./src/FastMathFunctions/arm_sin_f32.o ./src/FastMathFunctions/arm_sin_q15.d ./src/FastMathFunctions/arm_sin_q15.o ./src/FastMathFunctions/arm_sin_q31.d ./src/FastMathFunctions/arm_sin_q31.o ./src/FastMathFunctions/arm_sqrt_q15.d ./src/FastMathFunctions/arm_sqrt_q15.o ./src/FastMathFunctions/arm_sqrt_q31.d ./src/FastMathFunctions/arm_sqrt_q31.o ./src/FastMathFunctions/arm_vexp_f16.d ./src/FastMathFunctions/arm_vexp_f16.o ./src/FastMathFunctions/arm_vexp_f32.d ./src/FastMathFunctions/arm_vexp_f32.o ./src/FastMathFunctions/arm_vexp_f64.d ./src/FastMathFunctions/arm_vexp_f64.o ./src/FastMathFunctions/arm_vinverse_f16.d ./src/FastMathFunctions/arm_vinverse_f16.o ./src/FastMathFunctions/arm_vlog_f16.d ./src/FastMathFunctions/arm_vlog_f16.o ./src/FastMathFunctions/arm_vlog_f32.d ./src/FastMathFunctions/arm_vlog_f32.o ./src/FastMathFunctions/arm_vlog_f64.d ./src/FastMathFunctions/arm_vlog_f64.o ./src/FastMathFunctions/arm_vlog_q15.d ./src/FastMathFunctions/arm_vlog_q15.o ./src/FastMathFunctions/arm_vlog_q31.d ./src/FastMathFunctions/arm_vlog_q31.o

.PHONY: clean-src-2f-FastMathFunctions

