################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/SVMFunctions/SVMFunctions.c \
../src/SVMFunctions/SVMFunctionsF16.c \
../src/SVMFunctions/arm_svm_linear_init_f16.c \
../src/SVMFunctions/arm_svm_linear_init_f32.c \
../src/SVMFunctions/arm_svm_linear_predict_f16.c \
../src/SVMFunctions/arm_svm_linear_predict_f32.c \
../src/SVMFunctions/arm_svm_polynomial_init_f16.c \
../src/SVMFunctions/arm_svm_polynomial_init_f32.c \
../src/SVMFunctions/arm_svm_polynomial_predict_f16.c \
../src/SVMFunctions/arm_svm_polynomial_predict_f32.c \
../src/SVMFunctions/arm_svm_rbf_init_f16.c \
../src/SVMFunctions/arm_svm_rbf_init_f32.c \
../src/SVMFunctions/arm_svm_rbf_predict_f16.c \
../src/SVMFunctions/arm_svm_rbf_predict_f32.c \
../src/SVMFunctions/arm_svm_sigmoid_init_f16.c \
../src/SVMFunctions/arm_svm_sigmoid_init_f32.c \
../src/SVMFunctions/arm_svm_sigmoid_predict_f16.c \
../src/SVMFunctions/arm_svm_sigmoid_predict_f32.c 

C_DEPS += \
./src/SVMFunctions/SVMFunctions.d \
./src/SVMFunctions/SVMFunctionsF16.d \
./src/SVMFunctions/arm_svm_linear_init_f16.d \
./src/SVMFunctions/arm_svm_linear_init_f32.d \
./src/SVMFunctions/arm_svm_linear_predict_f16.d \
./src/SVMFunctions/arm_svm_linear_predict_f32.d \
./src/SVMFunctions/arm_svm_polynomial_init_f16.d \
./src/SVMFunctions/arm_svm_polynomial_init_f32.d \
./src/SVMFunctions/arm_svm_polynomial_predict_f16.d \
./src/SVMFunctions/arm_svm_polynomial_predict_f32.d \
./src/SVMFunctions/arm_svm_rbf_init_f16.d \
./src/SVMFunctions/arm_svm_rbf_init_f32.d \
./src/SVMFunctions/arm_svm_rbf_predict_f16.d \
./src/SVMFunctions/arm_svm_rbf_predict_f32.d \
./src/SVMFunctions/arm_svm_sigmoid_init_f16.d \
./src/SVMFunctions/arm_svm_sigmoid_init_f32.d \
./src/SVMFunctions/arm_svm_sigmoid_predict_f16.d \
./src/SVMFunctions/arm_svm_sigmoid_predict_f32.d 

OBJS += \
./src/SVMFunctions/SVMFunctions.o \
./src/SVMFunctions/SVMFunctionsF16.o \
./src/SVMFunctions/arm_svm_linear_init_f16.o \
./src/SVMFunctions/arm_svm_linear_init_f32.o \
./src/SVMFunctions/arm_svm_linear_predict_f16.o \
./src/SVMFunctions/arm_svm_linear_predict_f32.o \
./src/SVMFunctions/arm_svm_polynomial_init_f16.o \
./src/SVMFunctions/arm_svm_polynomial_init_f32.o \
./src/SVMFunctions/arm_svm_polynomial_predict_f16.o \
./src/SVMFunctions/arm_svm_polynomial_predict_f32.o \
./src/SVMFunctions/arm_svm_rbf_init_f16.o \
./src/SVMFunctions/arm_svm_rbf_init_f32.o \
./src/SVMFunctions/arm_svm_rbf_predict_f16.o \
./src/SVMFunctions/arm_svm_rbf_predict_f32.o \
./src/SVMFunctions/arm_svm_sigmoid_init_f16.o \
./src/SVMFunctions/arm_svm_sigmoid_init_f32.o \
./src/SVMFunctions/arm_svm_sigmoid_predict_f16.o \
./src/SVMFunctions/arm_svm_sigmoid_predict_f32.o 


# Each subdirectory must supply rules for building sources it contributes
src/SVMFunctions/%.o: ../src/SVMFunctions/%.c src/SVMFunctions/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -D__REDLIB__ -DCORE_M4 -D__USE_LPCOPEN -D__LPC43XX__ -I"/media/carlassaraf/DATA/facultad/TD III/2022_td3_512_carlassara/3.workspace/cmsis_dsp/inc" -I"/media/carlassaraf/DATA/facultad/TD III/2022_td3_512_carlassara/3.workspace/chip/lpc_chip_43xx/inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fsingle-precision-constant -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-SVMFunctions

clean-src-2f-SVMFunctions:
	-$(RM) ./src/SVMFunctions/SVMFunctions.d ./src/SVMFunctions/SVMFunctions.o ./src/SVMFunctions/SVMFunctionsF16.d ./src/SVMFunctions/SVMFunctionsF16.o ./src/SVMFunctions/arm_svm_linear_init_f16.d ./src/SVMFunctions/arm_svm_linear_init_f16.o ./src/SVMFunctions/arm_svm_linear_init_f32.d ./src/SVMFunctions/arm_svm_linear_init_f32.o ./src/SVMFunctions/arm_svm_linear_predict_f16.d ./src/SVMFunctions/arm_svm_linear_predict_f16.o ./src/SVMFunctions/arm_svm_linear_predict_f32.d ./src/SVMFunctions/arm_svm_linear_predict_f32.o ./src/SVMFunctions/arm_svm_polynomial_init_f16.d ./src/SVMFunctions/arm_svm_polynomial_init_f16.o ./src/SVMFunctions/arm_svm_polynomial_init_f32.d ./src/SVMFunctions/arm_svm_polynomial_init_f32.o ./src/SVMFunctions/arm_svm_polynomial_predict_f16.d ./src/SVMFunctions/arm_svm_polynomial_predict_f16.o ./src/SVMFunctions/arm_svm_polynomial_predict_f32.d ./src/SVMFunctions/arm_svm_polynomial_predict_f32.o ./src/SVMFunctions/arm_svm_rbf_init_f16.d ./src/SVMFunctions/arm_svm_rbf_init_f16.o ./src/SVMFunctions/arm_svm_rbf_init_f32.d ./src/SVMFunctions/arm_svm_rbf_init_f32.o ./src/SVMFunctions/arm_svm_rbf_predict_f16.d ./src/SVMFunctions/arm_svm_rbf_predict_f16.o ./src/SVMFunctions/arm_svm_rbf_predict_f32.d ./src/SVMFunctions/arm_svm_rbf_predict_f32.o ./src/SVMFunctions/arm_svm_sigmoid_init_f16.d ./src/SVMFunctions/arm_svm_sigmoid_init_f16.o ./src/SVMFunctions/arm_svm_sigmoid_init_f32.d ./src/SVMFunctions/arm_svm_sigmoid_init_f32.o ./src/SVMFunctions/arm_svm_sigmoid_predict_f16.d ./src/SVMFunctions/arm_svm_sigmoid_predict_f16.o ./src/SVMFunctions/arm_svm_sigmoid_predict_f32.d ./src/SVMFunctions/arm_svm_sigmoid_predict_f32.o

.PHONY: clean-src-2f-SVMFunctions

