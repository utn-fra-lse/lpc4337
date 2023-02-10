################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/QuaternionMathFunctions/QuaternionMathFunctions.c \
../src/QuaternionMathFunctions/arm_quaternion2rotation_f32.c \
../src/QuaternionMathFunctions/arm_quaternion_conjugate_f32.c \
../src/QuaternionMathFunctions/arm_quaternion_inverse_f32.c \
../src/QuaternionMathFunctions/arm_quaternion_norm_f32.c \
../src/QuaternionMathFunctions/arm_quaternion_normalize_f32.c \
../src/QuaternionMathFunctions/arm_quaternion_product_f32.c \
../src/QuaternionMathFunctions/arm_quaternion_product_single_f32.c \
../src/QuaternionMathFunctions/arm_rotation2quaternion_f32.c 

C_DEPS += \
./src/QuaternionMathFunctions/QuaternionMathFunctions.d \
./src/QuaternionMathFunctions/arm_quaternion2rotation_f32.d \
./src/QuaternionMathFunctions/arm_quaternion_conjugate_f32.d \
./src/QuaternionMathFunctions/arm_quaternion_inverse_f32.d \
./src/QuaternionMathFunctions/arm_quaternion_norm_f32.d \
./src/QuaternionMathFunctions/arm_quaternion_normalize_f32.d \
./src/QuaternionMathFunctions/arm_quaternion_product_f32.d \
./src/QuaternionMathFunctions/arm_quaternion_product_single_f32.d \
./src/QuaternionMathFunctions/arm_rotation2quaternion_f32.d 

OBJS += \
./src/QuaternionMathFunctions/QuaternionMathFunctions.o \
./src/QuaternionMathFunctions/arm_quaternion2rotation_f32.o \
./src/QuaternionMathFunctions/arm_quaternion_conjugate_f32.o \
./src/QuaternionMathFunctions/arm_quaternion_inverse_f32.o \
./src/QuaternionMathFunctions/arm_quaternion_norm_f32.o \
./src/QuaternionMathFunctions/arm_quaternion_normalize_f32.o \
./src/QuaternionMathFunctions/arm_quaternion_product_f32.o \
./src/QuaternionMathFunctions/arm_quaternion_product_single_f32.o \
./src/QuaternionMathFunctions/arm_rotation2quaternion_f32.o 


# Each subdirectory must supply rules for building sources it contributes
src/QuaternionMathFunctions/%.o: ../src/QuaternionMathFunctions/%.c src/QuaternionMathFunctions/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -D__REDLIB__ -DCORE_M4 -D__USE_LPCOPEN -D__LPC43XX__ -I"/media/carlassaraf/DATA/facultad/TD III/2022_td3_512_carlassara/3.workspace/cmsis_dsp/inc" -I"/media/carlassaraf/DATA/facultad/TD III/2022_td3_512_carlassara/3.workspace/chip/lpc_chip_43xx/inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fsingle-precision-constant -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-QuaternionMathFunctions

clean-src-2f-QuaternionMathFunctions:
	-$(RM) ./src/QuaternionMathFunctions/QuaternionMathFunctions.d ./src/QuaternionMathFunctions/QuaternionMathFunctions.o ./src/QuaternionMathFunctions/arm_quaternion2rotation_f32.d ./src/QuaternionMathFunctions/arm_quaternion2rotation_f32.o ./src/QuaternionMathFunctions/arm_quaternion_conjugate_f32.d ./src/QuaternionMathFunctions/arm_quaternion_conjugate_f32.o ./src/QuaternionMathFunctions/arm_quaternion_inverse_f32.d ./src/QuaternionMathFunctions/arm_quaternion_inverse_f32.o ./src/QuaternionMathFunctions/arm_quaternion_norm_f32.d ./src/QuaternionMathFunctions/arm_quaternion_norm_f32.o ./src/QuaternionMathFunctions/arm_quaternion_normalize_f32.d ./src/QuaternionMathFunctions/arm_quaternion_normalize_f32.o ./src/QuaternionMathFunctions/arm_quaternion_product_f32.d ./src/QuaternionMathFunctions/arm_quaternion_product_f32.o ./src/QuaternionMathFunctions/arm_quaternion_product_single_f32.d ./src/QuaternionMathFunctions/arm_quaternion_product_single_f32.o ./src/QuaternionMathFunctions/arm_rotation2quaternion_f32.d ./src/QuaternionMathFunctions/arm_rotation2quaternion_f32.o

.PHONY: clean-src-2f-QuaternionMathFunctions

