################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/InterpolationFunctions/InterpolationFunctions.c \
../src/InterpolationFunctions/InterpolationFunctionsF16.c \
../src/InterpolationFunctions/arm_bilinear_interp_f16.c \
../src/InterpolationFunctions/arm_bilinear_interp_f32.c \
../src/InterpolationFunctions/arm_bilinear_interp_q15.c \
../src/InterpolationFunctions/arm_bilinear_interp_q31.c \
../src/InterpolationFunctions/arm_bilinear_interp_q7.c \
../src/InterpolationFunctions/arm_linear_interp_f16.c \
../src/InterpolationFunctions/arm_linear_interp_f32.c \
../src/InterpolationFunctions/arm_linear_interp_q15.c \
../src/InterpolationFunctions/arm_linear_interp_q31.c \
../src/InterpolationFunctions/arm_linear_interp_q7.c \
../src/InterpolationFunctions/arm_spline_interp_f32.c \
../src/InterpolationFunctions/arm_spline_interp_init_f32.c 

C_DEPS += \
./src/InterpolationFunctions/InterpolationFunctions.d \
./src/InterpolationFunctions/InterpolationFunctionsF16.d \
./src/InterpolationFunctions/arm_bilinear_interp_f16.d \
./src/InterpolationFunctions/arm_bilinear_interp_f32.d \
./src/InterpolationFunctions/arm_bilinear_interp_q15.d \
./src/InterpolationFunctions/arm_bilinear_interp_q31.d \
./src/InterpolationFunctions/arm_bilinear_interp_q7.d \
./src/InterpolationFunctions/arm_linear_interp_f16.d \
./src/InterpolationFunctions/arm_linear_interp_f32.d \
./src/InterpolationFunctions/arm_linear_interp_q15.d \
./src/InterpolationFunctions/arm_linear_interp_q31.d \
./src/InterpolationFunctions/arm_linear_interp_q7.d \
./src/InterpolationFunctions/arm_spline_interp_f32.d \
./src/InterpolationFunctions/arm_spline_interp_init_f32.d 

OBJS += \
./src/InterpolationFunctions/InterpolationFunctions.o \
./src/InterpolationFunctions/InterpolationFunctionsF16.o \
./src/InterpolationFunctions/arm_bilinear_interp_f16.o \
./src/InterpolationFunctions/arm_bilinear_interp_f32.o \
./src/InterpolationFunctions/arm_bilinear_interp_q15.o \
./src/InterpolationFunctions/arm_bilinear_interp_q31.o \
./src/InterpolationFunctions/arm_bilinear_interp_q7.o \
./src/InterpolationFunctions/arm_linear_interp_f16.o \
./src/InterpolationFunctions/arm_linear_interp_f32.o \
./src/InterpolationFunctions/arm_linear_interp_q15.o \
./src/InterpolationFunctions/arm_linear_interp_q31.o \
./src/InterpolationFunctions/arm_linear_interp_q7.o \
./src/InterpolationFunctions/arm_spline_interp_f32.o \
./src/InterpolationFunctions/arm_spline_interp_init_f32.o 


# Each subdirectory must supply rules for building sources it contributes
src/InterpolationFunctions/%.o: ../src/InterpolationFunctions/%.c src/InterpolationFunctions/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -D__REDLIB__ -DCORE_M4 -D__USE_LPCOPEN -D__LPC43XX__ -I"/media/carlassaraf/DATA/facultad/TD III/2022_td3_512_carlassara/3.workspace/cmsis_dsp/inc" -I"/media/carlassaraf/DATA/facultad/TD III/2022_td3_512_carlassara/3.workspace/chip/lpc_chip_43xx/inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fsingle-precision-constant -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-InterpolationFunctions

clean-src-2f-InterpolationFunctions:
	-$(RM) ./src/InterpolationFunctions/InterpolationFunctions.d ./src/InterpolationFunctions/InterpolationFunctions.o ./src/InterpolationFunctions/InterpolationFunctionsF16.d ./src/InterpolationFunctions/InterpolationFunctionsF16.o ./src/InterpolationFunctions/arm_bilinear_interp_f16.d ./src/InterpolationFunctions/arm_bilinear_interp_f16.o ./src/InterpolationFunctions/arm_bilinear_interp_f32.d ./src/InterpolationFunctions/arm_bilinear_interp_f32.o ./src/InterpolationFunctions/arm_bilinear_interp_q15.d ./src/InterpolationFunctions/arm_bilinear_interp_q15.o ./src/InterpolationFunctions/arm_bilinear_interp_q31.d ./src/InterpolationFunctions/arm_bilinear_interp_q31.o ./src/InterpolationFunctions/arm_bilinear_interp_q7.d ./src/InterpolationFunctions/arm_bilinear_interp_q7.o ./src/InterpolationFunctions/arm_linear_interp_f16.d ./src/InterpolationFunctions/arm_linear_interp_f16.o ./src/InterpolationFunctions/arm_linear_interp_f32.d ./src/InterpolationFunctions/arm_linear_interp_f32.o ./src/InterpolationFunctions/arm_linear_interp_q15.d ./src/InterpolationFunctions/arm_linear_interp_q15.o ./src/InterpolationFunctions/arm_linear_interp_q31.d ./src/InterpolationFunctions/arm_linear_interp_q31.o ./src/InterpolationFunctions/arm_linear_interp_q7.d ./src/InterpolationFunctions/arm_linear_interp_q7.o ./src/InterpolationFunctions/arm_spline_interp_f32.d ./src/InterpolationFunctions/arm_spline_interp_f32.o ./src/InterpolationFunctions/arm_spline_interp_init_f32.d ./src/InterpolationFunctions/arm_spline_interp_init_f32.o

.PHONY: clean-src-2f-InterpolationFunctions

