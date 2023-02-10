################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/BayesFunctions/BayesFunctions.c \
../src/BayesFunctions/BayesFunctionsF16.c \
../src/BayesFunctions/arm_gaussian_naive_bayes_predict_f16.c \
../src/BayesFunctions/arm_gaussian_naive_bayes_predict_f32.c 

C_DEPS += \
./src/BayesFunctions/BayesFunctions.d \
./src/BayesFunctions/BayesFunctionsF16.d \
./src/BayesFunctions/arm_gaussian_naive_bayes_predict_f16.d \
./src/BayesFunctions/arm_gaussian_naive_bayes_predict_f32.d 

OBJS += \
./src/BayesFunctions/BayesFunctions.o \
./src/BayesFunctions/BayesFunctionsF16.o \
./src/BayesFunctions/arm_gaussian_naive_bayes_predict_f16.o \
./src/BayesFunctions/arm_gaussian_naive_bayes_predict_f32.o 


# Each subdirectory must supply rules for building sources it contributes
src/BayesFunctions/%.o: ../src/BayesFunctions/%.c src/BayesFunctions/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -D__REDLIB__ -DCORE_M4 -D__USE_LPCOPEN -D__LPC43XX__ -I"/media/carlassaraf/DATA/facultad/TD III/2022_td3_512_carlassara/3.workspace/cmsis_dsp/inc" -I"/media/carlassaraf/DATA/facultad/TD III/2022_td3_512_carlassara/3.workspace/chip/lpc_chip_43xx/inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fsingle-precision-constant -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-BayesFunctions

clean-src-2f-BayesFunctions:
	-$(RM) ./src/BayesFunctions/BayesFunctions.d ./src/BayesFunctions/BayesFunctions.o ./src/BayesFunctions/BayesFunctionsF16.d ./src/BayesFunctions/BayesFunctionsF16.o ./src/BayesFunctions/arm_gaussian_naive_bayes_predict_f16.d ./src/BayesFunctions/arm_gaussian_naive_bayes_predict_f16.o ./src/BayesFunctions/arm_gaussian_naive_bayes_predict_f32.d ./src/BayesFunctions/arm_gaussian_naive_bayes_predict_f32.o

.PHONY: clean-src-2f-BayesFunctions

