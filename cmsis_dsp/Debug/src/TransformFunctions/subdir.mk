################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/TransformFunctions/TransformFunctions.c \
../src/TransformFunctions/TransformFunctionsF16.c \
../src/TransformFunctions/arm_bitreversal.c \
../src/TransformFunctions/arm_bitreversal2.c \
../src/TransformFunctions/arm_bitreversal_f16.c \
../src/TransformFunctions/arm_cfft_f16.c \
../src/TransformFunctions/arm_cfft_f32.c \
../src/TransformFunctions/arm_cfft_f64.c \
../src/TransformFunctions/arm_cfft_init_f16.c \
../src/TransformFunctions/arm_cfft_init_f32.c \
../src/TransformFunctions/arm_cfft_init_f64.c \
../src/TransformFunctions/arm_cfft_init_q15.c \
../src/TransformFunctions/arm_cfft_init_q31.c \
../src/TransformFunctions/arm_cfft_q15.c \
../src/TransformFunctions/arm_cfft_q31.c \
../src/TransformFunctions/arm_cfft_radix2_f16.c \
../src/TransformFunctions/arm_cfft_radix2_f32.c \
../src/TransformFunctions/arm_cfft_radix2_init_f16.c \
../src/TransformFunctions/arm_cfft_radix2_init_f32.c \
../src/TransformFunctions/arm_cfft_radix2_init_q15.c \
../src/TransformFunctions/arm_cfft_radix2_init_q31.c \
../src/TransformFunctions/arm_cfft_radix2_q15.c \
../src/TransformFunctions/arm_cfft_radix2_q31.c \
../src/TransformFunctions/arm_cfft_radix4_f16.c \
../src/TransformFunctions/arm_cfft_radix4_f32.c \
../src/TransformFunctions/arm_cfft_radix4_init_f16.c \
../src/TransformFunctions/arm_cfft_radix4_init_f32.c \
../src/TransformFunctions/arm_cfft_radix4_init_q15.c \
../src/TransformFunctions/arm_cfft_radix4_init_q31.c \
../src/TransformFunctions/arm_cfft_radix4_q15.c \
../src/TransformFunctions/arm_cfft_radix4_q31.c \
../src/TransformFunctions/arm_cfft_radix8_f16.c \
../src/TransformFunctions/arm_cfft_radix8_f32.c \
../src/TransformFunctions/arm_dct4_f32.c \
../src/TransformFunctions/arm_dct4_init_f32.c \
../src/TransformFunctions/arm_dct4_init_q15.c \
../src/TransformFunctions/arm_dct4_init_q31.c \
../src/TransformFunctions/arm_dct4_q15.c \
../src/TransformFunctions/arm_dct4_q31.c \
../src/TransformFunctions/arm_mfcc_f16.c \
../src/TransformFunctions/arm_mfcc_f32.c \
../src/TransformFunctions/arm_mfcc_init_f16.c \
../src/TransformFunctions/arm_mfcc_init_f32.c \
../src/TransformFunctions/arm_mfcc_init_q15.c \
../src/TransformFunctions/arm_mfcc_init_q31.c \
../src/TransformFunctions/arm_mfcc_q15.c \
../src/TransformFunctions/arm_mfcc_q31.c \
../src/TransformFunctions/arm_rfft_f32.c \
../src/TransformFunctions/arm_rfft_fast_f16.c \
../src/TransformFunctions/arm_rfft_fast_f32.c \
../src/TransformFunctions/arm_rfft_fast_f64.c \
../src/TransformFunctions/arm_rfft_fast_init_f16.c \
../src/TransformFunctions/arm_rfft_fast_init_f32.c \
../src/TransformFunctions/arm_rfft_fast_init_f64.c \
../src/TransformFunctions/arm_rfft_init_f32.c \
../src/TransformFunctions/arm_rfft_init_q15.c \
../src/TransformFunctions/arm_rfft_init_q31.c \
../src/TransformFunctions/arm_rfft_q15.c \
../src/TransformFunctions/arm_rfft_q31.c 

C_DEPS += \
./src/TransformFunctions/TransformFunctions.d \
./src/TransformFunctions/TransformFunctionsF16.d \
./src/TransformFunctions/arm_bitreversal.d \
./src/TransformFunctions/arm_bitreversal2.d \
./src/TransformFunctions/arm_bitreversal_f16.d \
./src/TransformFunctions/arm_cfft_f16.d \
./src/TransformFunctions/arm_cfft_f32.d \
./src/TransformFunctions/arm_cfft_f64.d \
./src/TransformFunctions/arm_cfft_init_f16.d \
./src/TransformFunctions/arm_cfft_init_f32.d \
./src/TransformFunctions/arm_cfft_init_f64.d \
./src/TransformFunctions/arm_cfft_init_q15.d \
./src/TransformFunctions/arm_cfft_init_q31.d \
./src/TransformFunctions/arm_cfft_q15.d \
./src/TransformFunctions/arm_cfft_q31.d \
./src/TransformFunctions/arm_cfft_radix2_f16.d \
./src/TransformFunctions/arm_cfft_radix2_f32.d \
./src/TransformFunctions/arm_cfft_radix2_init_f16.d \
./src/TransformFunctions/arm_cfft_radix2_init_f32.d \
./src/TransformFunctions/arm_cfft_radix2_init_q15.d \
./src/TransformFunctions/arm_cfft_radix2_init_q31.d \
./src/TransformFunctions/arm_cfft_radix2_q15.d \
./src/TransformFunctions/arm_cfft_radix2_q31.d \
./src/TransformFunctions/arm_cfft_radix4_f16.d \
./src/TransformFunctions/arm_cfft_radix4_f32.d \
./src/TransformFunctions/arm_cfft_radix4_init_f16.d \
./src/TransformFunctions/arm_cfft_radix4_init_f32.d \
./src/TransformFunctions/arm_cfft_radix4_init_q15.d \
./src/TransformFunctions/arm_cfft_radix4_init_q31.d \
./src/TransformFunctions/arm_cfft_radix4_q15.d \
./src/TransformFunctions/arm_cfft_radix4_q31.d \
./src/TransformFunctions/arm_cfft_radix8_f16.d \
./src/TransformFunctions/arm_cfft_radix8_f32.d \
./src/TransformFunctions/arm_dct4_f32.d \
./src/TransformFunctions/arm_dct4_init_f32.d \
./src/TransformFunctions/arm_dct4_init_q15.d \
./src/TransformFunctions/arm_dct4_init_q31.d \
./src/TransformFunctions/arm_dct4_q15.d \
./src/TransformFunctions/arm_dct4_q31.d \
./src/TransformFunctions/arm_mfcc_f16.d \
./src/TransformFunctions/arm_mfcc_f32.d \
./src/TransformFunctions/arm_mfcc_init_f16.d \
./src/TransformFunctions/arm_mfcc_init_f32.d \
./src/TransformFunctions/arm_mfcc_init_q15.d \
./src/TransformFunctions/arm_mfcc_init_q31.d \
./src/TransformFunctions/arm_mfcc_q15.d \
./src/TransformFunctions/arm_mfcc_q31.d \
./src/TransformFunctions/arm_rfft_f32.d \
./src/TransformFunctions/arm_rfft_fast_f16.d \
./src/TransformFunctions/arm_rfft_fast_f32.d \
./src/TransformFunctions/arm_rfft_fast_f64.d \
./src/TransformFunctions/arm_rfft_fast_init_f16.d \
./src/TransformFunctions/arm_rfft_fast_init_f32.d \
./src/TransformFunctions/arm_rfft_fast_init_f64.d \
./src/TransformFunctions/arm_rfft_init_f32.d \
./src/TransformFunctions/arm_rfft_init_q15.d \
./src/TransformFunctions/arm_rfft_init_q31.d \
./src/TransformFunctions/arm_rfft_q15.d \
./src/TransformFunctions/arm_rfft_q31.d 

OBJS += \
./src/TransformFunctions/TransformFunctions.o \
./src/TransformFunctions/TransformFunctionsF16.o \
./src/TransformFunctions/arm_bitreversal.o \
./src/TransformFunctions/arm_bitreversal2.o \
./src/TransformFunctions/arm_bitreversal_f16.o \
./src/TransformFunctions/arm_cfft_f16.o \
./src/TransformFunctions/arm_cfft_f32.o \
./src/TransformFunctions/arm_cfft_f64.o \
./src/TransformFunctions/arm_cfft_init_f16.o \
./src/TransformFunctions/arm_cfft_init_f32.o \
./src/TransformFunctions/arm_cfft_init_f64.o \
./src/TransformFunctions/arm_cfft_init_q15.o \
./src/TransformFunctions/arm_cfft_init_q31.o \
./src/TransformFunctions/arm_cfft_q15.o \
./src/TransformFunctions/arm_cfft_q31.o \
./src/TransformFunctions/arm_cfft_radix2_f16.o \
./src/TransformFunctions/arm_cfft_radix2_f32.o \
./src/TransformFunctions/arm_cfft_radix2_init_f16.o \
./src/TransformFunctions/arm_cfft_radix2_init_f32.o \
./src/TransformFunctions/arm_cfft_radix2_init_q15.o \
./src/TransformFunctions/arm_cfft_radix2_init_q31.o \
./src/TransformFunctions/arm_cfft_radix2_q15.o \
./src/TransformFunctions/arm_cfft_radix2_q31.o \
./src/TransformFunctions/arm_cfft_radix4_f16.o \
./src/TransformFunctions/arm_cfft_radix4_f32.o \
./src/TransformFunctions/arm_cfft_radix4_init_f16.o \
./src/TransformFunctions/arm_cfft_radix4_init_f32.o \
./src/TransformFunctions/arm_cfft_radix4_init_q15.o \
./src/TransformFunctions/arm_cfft_radix4_init_q31.o \
./src/TransformFunctions/arm_cfft_radix4_q15.o \
./src/TransformFunctions/arm_cfft_radix4_q31.o \
./src/TransformFunctions/arm_cfft_radix8_f16.o \
./src/TransformFunctions/arm_cfft_radix8_f32.o \
./src/TransformFunctions/arm_dct4_f32.o \
./src/TransformFunctions/arm_dct4_init_f32.o \
./src/TransformFunctions/arm_dct4_init_q15.o \
./src/TransformFunctions/arm_dct4_init_q31.o \
./src/TransformFunctions/arm_dct4_q15.o \
./src/TransformFunctions/arm_dct4_q31.o \
./src/TransformFunctions/arm_mfcc_f16.o \
./src/TransformFunctions/arm_mfcc_f32.o \
./src/TransformFunctions/arm_mfcc_init_f16.o \
./src/TransformFunctions/arm_mfcc_init_f32.o \
./src/TransformFunctions/arm_mfcc_init_q15.o \
./src/TransformFunctions/arm_mfcc_init_q31.o \
./src/TransformFunctions/arm_mfcc_q15.o \
./src/TransformFunctions/arm_mfcc_q31.o \
./src/TransformFunctions/arm_rfft_f32.o \
./src/TransformFunctions/arm_rfft_fast_f16.o \
./src/TransformFunctions/arm_rfft_fast_f32.o \
./src/TransformFunctions/arm_rfft_fast_f64.o \
./src/TransformFunctions/arm_rfft_fast_init_f16.o \
./src/TransformFunctions/arm_rfft_fast_init_f32.o \
./src/TransformFunctions/arm_rfft_fast_init_f64.o \
./src/TransformFunctions/arm_rfft_init_f32.o \
./src/TransformFunctions/arm_rfft_init_q15.o \
./src/TransformFunctions/arm_rfft_init_q31.o \
./src/TransformFunctions/arm_rfft_q15.o \
./src/TransformFunctions/arm_rfft_q31.o 


# Each subdirectory must supply rules for building sources it contributes
src/TransformFunctions/%.o: ../src/TransformFunctions/%.c src/TransformFunctions/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -D__REDLIB__ -DCORE_M4 -D__USE_LPCOPEN -D__LPC43XX__ -I"/media/carlassaraf/DATA/facultad/TD III/2022_td3_512_carlassara/3.workspace/cmsis_dsp/inc" -I"/media/carlassaraf/DATA/facultad/TD III/2022_td3_512_carlassara/3.workspace/chip/lpc_chip_43xx/inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fsingle-precision-constant -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-TransformFunctions

clean-src-2f-TransformFunctions:
	-$(RM) ./src/TransformFunctions/TransformFunctions.d ./src/TransformFunctions/TransformFunctions.o ./src/TransformFunctions/TransformFunctionsF16.d ./src/TransformFunctions/TransformFunctionsF16.o ./src/TransformFunctions/arm_bitreversal.d ./src/TransformFunctions/arm_bitreversal.o ./src/TransformFunctions/arm_bitreversal2.d ./src/TransformFunctions/arm_bitreversal2.o ./src/TransformFunctions/arm_bitreversal_f16.d ./src/TransformFunctions/arm_bitreversal_f16.o ./src/TransformFunctions/arm_cfft_f16.d ./src/TransformFunctions/arm_cfft_f16.o ./src/TransformFunctions/arm_cfft_f32.d ./src/TransformFunctions/arm_cfft_f32.o ./src/TransformFunctions/arm_cfft_f64.d ./src/TransformFunctions/arm_cfft_f64.o ./src/TransformFunctions/arm_cfft_init_f16.d ./src/TransformFunctions/arm_cfft_init_f16.o ./src/TransformFunctions/arm_cfft_init_f32.d ./src/TransformFunctions/arm_cfft_init_f32.o ./src/TransformFunctions/arm_cfft_init_f64.d ./src/TransformFunctions/arm_cfft_init_f64.o ./src/TransformFunctions/arm_cfft_init_q15.d ./src/TransformFunctions/arm_cfft_init_q15.o ./src/TransformFunctions/arm_cfft_init_q31.d ./src/TransformFunctions/arm_cfft_init_q31.o ./src/TransformFunctions/arm_cfft_q15.d ./src/TransformFunctions/arm_cfft_q15.o ./src/TransformFunctions/arm_cfft_q31.d ./src/TransformFunctions/arm_cfft_q31.o ./src/TransformFunctions/arm_cfft_radix2_f16.d ./src/TransformFunctions/arm_cfft_radix2_f16.o ./src/TransformFunctions/arm_cfft_radix2_f32.d ./src/TransformFunctions/arm_cfft_radix2_f32.o ./src/TransformFunctions/arm_cfft_radix2_init_f16.d ./src/TransformFunctions/arm_cfft_radix2_init_f16.o ./src/TransformFunctions/arm_cfft_radix2_init_f32.d ./src/TransformFunctions/arm_cfft_radix2_init_f32.o ./src/TransformFunctions/arm_cfft_radix2_init_q15.d ./src/TransformFunctions/arm_cfft_radix2_init_q15.o ./src/TransformFunctions/arm_cfft_radix2_init_q31.d ./src/TransformFunctions/arm_cfft_radix2_init_q31.o ./src/TransformFunctions/arm_cfft_radix2_q15.d ./src/TransformFunctions/arm_cfft_radix2_q15.o ./src/TransformFunctions/arm_cfft_radix2_q31.d ./src/TransformFunctions/arm_cfft_radix2_q31.o ./src/TransformFunctions/arm_cfft_radix4_f16.d ./src/TransformFunctions/arm_cfft_radix4_f16.o ./src/TransformFunctions/arm_cfft_radix4_f32.d ./src/TransformFunctions/arm_cfft_radix4_f32.o ./src/TransformFunctions/arm_cfft_radix4_init_f16.d ./src/TransformFunctions/arm_cfft_radix4_init_f16.o ./src/TransformFunctions/arm_cfft_radix4_init_f32.d ./src/TransformFunctions/arm_cfft_radix4_init_f32.o ./src/TransformFunctions/arm_cfft_radix4_init_q15.d ./src/TransformFunctions/arm_cfft_radix4_init_q15.o ./src/TransformFunctions/arm_cfft_radix4_init_q31.d ./src/TransformFunctions/arm_cfft_radix4_init_q31.o ./src/TransformFunctions/arm_cfft_radix4_q15.d ./src/TransformFunctions/arm_cfft_radix4_q15.o ./src/TransformFunctions/arm_cfft_radix4_q31.d ./src/TransformFunctions/arm_cfft_radix4_q31.o ./src/TransformFunctions/arm_cfft_radix8_f16.d ./src/TransformFunctions/arm_cfft_radix8_f16.o ./src/TransformFunctions/arm_cfft_radix8_f32.d ./src/TransformFunctions/arm_cfft_radix8_f32.o ./src/TransformFunctions/arm_dct4_f32.d ./src/TransformFunctions/arm_dct4_f32.o ./src/TransformFunctions/arm_dct4_init_f32.d ./src/TransformFunctions/arm_dct4_init_f32.o ./src/TransformFunctions/arm_dct4_init_q15.d ./src/TransformFunctions/arm_dct4_init_q15.o ./src/TransformFunctions/arm_dct4_init_q31.d ./src/TransformFunctions/arm_dct4_init_q31.o ./src/TransformFunctions/arm_dct4_q15.d ./src/TransformFunctions/arm_dct4_q15.o ./src/TransformFunctions/arm_dct4_q31.d ./src/TransformFunctions/arm_dct4_q31.o ./src/TransformFunctions/arm_mfcc_f16.d ./src/TransformFunctions/arm_mfcc_f16.o ./src/TransformFunctions/arm_mfcc_f32.d ./src/TransformFunctions/arm_mfcc_f32.o ./src/TransformFunctions/arm_mfcc_init_f16.d ./src/TransformFunctions/arm_mfcc_init_f16.o ./src/TransformFunctions/arm_mfcc_init_f32.d ./src/TransformFunctions/arm_mfcc_init_f32.o ./src/TransformFunctions/arm_mfcc_init_q15.d ./src/TransformFunctions/arm_mfcc_init_q15.o ./src/TransformFunctions/arm_mfcc_init_q31.d ./src/TransformFunctions/arm_mfcc_init_q31.o ./src/TransformFunctions/arm_mfcc_q15.d ./src/TransformFunctions/arm_mfcc_q15.o ./src/TransformFunctions/arm_mfcc_q31.d ./src/TransformFunctions/arm_mfcc_q31.o ./src/TransformFunctions/arm_rfft_f32.d ./src/TransformFunctions/arm_rfft_f32.o ./src/TransformFunctions/arm_rfft_fast_f16.d ./src/TransformFunctions/arm_rfft_fast_f16.o ./src/TransformFunctions/arm_rfft_fast_f32.d ./src/TransformFunctions/arm_rfft_fast_f32.o ./src/TransformFunctions/arm_rfft_fast_f64.d ./src/TransformFunctions/arm_rfft_fast_f64.o ./src/TransformFunctions/arm_rfft_fast_init_f16.d ./src/TransformFunctions/arm_rfft_fast_init_f16.o ./src/TransformFunctions/arm_rfft_fast_init_f32.d ./src/TransformFunctions/arm_rfft_fast_init_f32.o ./src/TransformFunctions/arm_rfft_fast_init_f64.d ./src/TransformFunctions/arm_rfft_fast_init_f64.o ./src/TransformFunctions/arm_rfft_init_f32.d ./src/TransformFunctions/arm_rfft_init_f32.o ./src/TransformFunctions/arm_rfft_init_q15.d ./src/TransformFunctions/arm_rfft_init_q15.o ./src/TransformFunctions/arm_rfft_init_q31.d ./src/TransformFunctions/arm_rfft_init_q31.o ./src/TransformFunctions/arm_rfft_q15.d ./src/TransformFunctions/arm_rfft_q15.o ./src/TransformFunctions/arm_rfft_q31.d ./src/TransformFunctions/arm_rfft_q31.o

.PHONY: clean-src-2f-TransformFunctions

