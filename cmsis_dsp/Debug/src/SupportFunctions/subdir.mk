################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/SupportFunctions/SupportFunctions.c \
../src/SupportFunctions/SupportFunctionsF16.c \
../src/SupportFunctions/arm_barycenter_f16.c \
../src/SupportFunctions/arm_barycenter_f32.c \
../src/SupportFunctions/arm_bitonic_sort_f32.c \
../src/SupportFunctions/arm_bubble_sort_f32.c \
../src/SupportFunctions/arm_copy_f16.c \
../src/SupportFunctions/arm_copy_f32.c \
../src/SupportFunctions/arm_copy_f64.c \
../src/SupportFunctions/arm_copy_q15.c \
../src/SupportFunctions/arm_copy_q31.c \
../src/SupportFunctions/arm_copy_q7.c \
../src/SupportFunctions/arm_f16_to_f64.c \
../src/SupportFunctions/arm_f16_to_float.c \
../src/SupportFunctions/arm_f16_to_q15.c \
../src/SupportFunctions/arm_f64_to_f16.c \
../src/SupportFunctions/arm_f64_to_float.c \
../src/SupportFunctions/arm_f64_to_q15.c \
../src/SupportFunctions/arm_f64_to_q31.c \
../src/SupportFunctions/arm_f64_to_q7.c \
../src/SupportFunctions/arm_fill_f16.c \
../src/SupportFunctions/arm_fill_f32.c \
../src/SupportFunctions/arm_fill_f64.c \
../src/SupportFunctions/arm_fill_q15.c \
../src/SupportFunctions/arm_fill_q31.c \
../src/SupportFunctions/arm_fill_q7.c \
../src/SupportFunctions/arm_float_to_f16.c \
../src/SupportFunctions/arm_float_to_f64.c \
../src/SupportFunctions/arm_float_to_q15.c \
../src/SupportFunctions/arm_float_to_q31.c \
../src/SupportFunctions/arm_float_to_q7.c \
../src/SupportFunctions/arm_heap_sort_f32.c \
../src/SupportFunctions/arm_insertion_sort_f32.c \
../src/SupportFunctions/arm_merge_sort_f32.c \
../src/SupportFunctions/arm_merge_sort_init_f32.c \
../src/SupportFunctions/arm_q15_to_f16.c \
../src/SupportFunctions/arm_q15_to_f64.c \
../src/SupportFunctions/arm_q15_to_float.c \
../src/SupportFunctions/arm_q15_to_q31.c \
../src/SupportFunctions/arm_q15_to_q7.c \
../src/SupportFunctions/arm_q31_to_f64.c \
../src/SupportFunctions/arm_q31_to_float.c \
../src/SupportFunctions/arm_q31_to_q15.c \
../src/SupportFunctions/arm_q31_to_q7.c \
../src/SupportFunctions/arm_q7_to_f64.c \
../src/SupportFunctions/arm_q7_to_float.c \
../src/SupportFunctions/arm_q7_to_q15.c \
../src/SupportFunctions/arm_q7_to_q31.c \
../src/SupportFunctions/arm_quick_sort_f32.c \
../src/SupportFunctions/arm_selection_sort_f32.c \
../src/SupportFunctions/arm_sort_f32.c \
../src/SupportFunctions/arm_sort_init_f32.c \
../src/SupportFunctions/arm_weighted_sum_f16.c \
../src/SupportFunctions/arm_weighted_sum_f32.c 

C_DEPS += \
./src/SupportFunctions/SupportFunctions.d \
./src/SupportFunctions/SupportFunctionsF16.d \
./src/SupportFunctions/arm_barycenter_f16.d \
./src/SupportFunctions/arm_barycenter_f32.d \
./src/SupportFunctions/arm_bitonic_sort_f32.d \
./src/SupportFunctions/arm_bubble_sort_f32.d \
./src/SupportFunctions/arm_copy_f16.d \
./src/SupportFunctions/arm_copy_f32.d \
./src/SupportFunctions/arm_copy_f64.d \
./src/SupportFunctions/arm_copy_q15.d \
./src/SupportFunctions/arm_copy_q31.d \
./src/SupportFunctions/arm_copy_q7.d \
./src/SupportFunctions/arm_f16_to_f64.d \
./src/SupportFunctions/arm_f16_to_float.d \
./src/SupportFunctions/arm_f16_to_q15.d \
./src/SupportFunctions/arm_f64_to_f16.d \
./src/SupportFunctions/arm_f64_to_float.d \
./src/SupportFunctions/arm_f64_to_q15.d \
./src/SupportFunctions/arm_f64_to_q31.d \
./src/SupportFunctions/arm_f64_to_q7.d \
./src/SupportFunctions/arm_fill_f16.d \
./src/SupportFunctions/arm_fill_f32.d \
./src/SupportFunctions/arm_fill_f64.d \
./src/SupportFunctions/arm_fill_q15.d \
./src/SupportFunctions/arm_fill_q31.d \
./src/SupportFunctions/arm_fill_q7.d \
./src/SupportFunctions/arm_float_to_f16.d \
./src/SupportFunctions/arm_float_to_f64.d \
./src/SupportFunctions/arm_float_to_q15.d \
./src/SupportFunctions/arm_float_to_q31.d \
./src/SupportFunctions/arm_float_to_q7.d \
./src/SupportFunctions/arm_heap_sort_f32.d \
./src/SupportFunctions/arm_insertion_sort_f32.d \
./src/SupportFunctions/arm_merge_sort_f32.d \
./src/SupportFunctions/arm_merge_sort_init_f32.d \
./src/SupportFunctions/arm_q15_to_f16.d \
./src/SupportFunctions/arm_q15_to_f64.d \
./src/SupportFunctions/arm_q15_to_float.d \
./src/SupportFunctions/arm_q15_to_q31.d \
./src/SupportFunctions/arm_q15_to_q7.d \
./src/SupportFunctions/arm_q31_to_f64.d \
./src/SupportFunctions/arm_q31_to_float.d \
./src/SupportFunctions/arm_q31_to_q15.d \
./src/SupportFunctions/arm_q31_to_q7.d \
./src/SupportFunctions/arm_q7_to_f64.d \
./src/SupportFunctions/arm_q7_to_float.d \
./src/SupportFunctions/arm_q7_to_q15.d \
./src/SupportFunctions/arm_q7_to_q31.d \
./src/SupportFunctions/arm_quick_sort_f32.d \
./src/SupportFunctions/arm_selection_sort_f32.d \
./src/SupportFunctions/arm_sort_f32.d \
./src/SupportFunctions/arm_sort_init_f32.d \
./src/SupportFunctions/arm_weighted_sum_f16.d \
./src/SupportFunctions/arm_weighted_sum_f32.d 

OBJS += \
./src/SupportFunctions/SupportFunctions.o \
./src/SupportFunctions/SupportFunctionsF16.o \
./src/SupportFunctions/arm_barycenter_f16.o \
./src/SupportFunctions/arm_barycenter_f32.o \
./src/SupportFunctions/arm_bitonic_sort_f32.o \
./src/SupportFunctions/arm_bubble_sort_f32.o \
./src/SupportFunctions/arm_copy_f16.o \
./src/SupportFunctions/arm_copy_f32.o \
./src/SupportFunctions/arm_copy_f64.o \
./src/SupportFunctions/arm_copy_q15.o \
./src/SupportFunctions/arm_copy_q31.o \
./src/SupportFunctions/arm_copy_q7.o \
./src/SupportFunctions/arm_f16_to_f64.o \
./src/SupportFunctions/arm_f16_to_float.o \
./src/SupportFunctions/arm_f16_to_q15.o \
./src/SupportFunctions/arm_f64_to_f16.o \
./src/SupportFunctions/arm_f64_to_float.o \
./src/SupportFunctions/arm_f64_to_q15.o \
./src/SupportFunctions/arm_f64_to_q31.o \
./src/SupportFunctions/arm_f64_to_q7.o \
./src/SupportFunctions/arm_fill_f16.o \
./src/SupportFunctions/arm_fill_f32.o \
./src/SupportFunctions/arm_fill_f64.o \
./src/SupportFunctions/arm_fill_q15.o \
./src/SupportFunctions/arm_fill_q31.o \
./src/SupportFunctions/arm_fill_q7.o \
./src/SupportFunctions/arm_float_to_f16.o \
./src/SupportFunctions/arm_float_to_f64.o \
./src/SupportFunctions/arm_float_to_q15.o \
./src/SupportFunctions/arm_float_to_q31.o \
./src/SupportFunctions/arm_float_to_q7.o \
./src/SupportFunctions/arm_heap_sort_f32.o \
./src/SupportFunctions/arm_insertion_sort_f32.o \
./src/SupportFunctions/arm_merge_sort_f32.o \
./src/SupportFunctions/arm_merge_sort_init_f32.o \
./src/SupportFunctions/arm_q15_to_f16.o \
./src/SupportFunctions/arm_q15_to_f64.o \
./src/SupportFunctions/arm_q15_to_float.o \
./src/SupportFunctions/arm_q15_to_q31.o \
./src/SupportFunctions/arm_q15_to_q7.o \
./src/SupportFunctions/arm_q31_to_f64.o \
./src/SupportFunctions/arm_q31_to_float.o \
./src/SupportFunctions/arm_q31_to_q15.o \
./src/SupportFunctions/arm_q31_to_q7.o \
./src/SupportFunctions/arm_q7_to_f64.o \
./src/SupportFunctions/arm_q7_to_float.o \
./src/SupportFunctions/arm_q7_to_q15.o \
./src/SupportFunctions/arm_q7_to_q31.o \
./src/SupportFunctions/arm_quick_sort_f32.o \
./src/SupportFunctions/arm_selection_sort_f32.o \
./src/SupportFunctions/arm_sort_f32.o \
./src/SupportFunctions/arm_sort_init_f32.o \
./src/SupportFunctions/arm_weighted_sum_f16.o \
./src/SupportFunctions/arm_weighted_sum_f32.o 


# Each subdirectory must supply rules for building sources it contributes
src/SupportFunctions/%.o: ../src/SupportFunctions/%.c src/SupportFunctions/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -D__REDLIB__ -DCORE_M4 -D__USE_LPCOPEN -D__LPC43XX__ -I"/media/carlassaraf/DATA/facultad/TD III/2022_td3_512_carlassara/3.workspace/cmsis_dsp/inc" -I"/media/carlassaraf/DATA/facultad/TD III/2022_td3_512_carlassara/3.workspace/chip/lpc_chip_43xx/inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fsingle-precision-constant -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-SupportFunctions

clean-src-2f-SupportFunctions:
	-$(RM) ./src/SupportFunctions/SupportFunctions.d ./src/SupportFunctions/SupportFunctions.o ./src/SupportFunctions/SupportFunctionsF16.d ./src/SupportFunctions/SupportFunctionsF16.o ./src/SupportFunctions/arm_barycenter_f16.d ./src/SupportFunctions/arm_barycenter_f16.o ./src/SupportFunctions/arm_barycenter_f32.d ./src/SupportFunctions/arm_barycenter_f32.o ./src/SupportFunctions/arm_bitonic_sort_f32.d ./src/SupportFunctions/arm_bitonic_sort_f32.o ./src/SupportFunctions/arm_bubble_sort_f32.d ./src/SupportFunctions/arm_bubble_sort_f32.o ./src/SupportFunctions/arm_copy_f16.d ./src/SupportFunctions/arm_copy_f16.o ./src/SupportFunctions/arm_copy_f32.d ./src/SupportFunctions/arm_copy_f32.o ./src/SupportFunctions/arm_copy_f64.d ./src/SupportFunctions/arm_copy_f64.o ./src/SupportFunctions/arm_copy_q15.d ./src/SupportFunctions/arm_copy_q15.o ./src/SupportFunctions/arm_copy_q31.d ./src/SupportFunctions/arm_copy_q31.o ./src/SupportFunctions/arm_copy_q7.d ./src/SupportFunctions/arm_copy_q7.o ./src/SupportFunctions/arm_f16_to_f64.d ./src/SupportFunctions/arm_f16_to_f64.o ./src/SupportFunctions/arm_f16_to_float.d ./src/SupportFunctions/arm_f16_to_float.o ./src/SupportFunctions/arm_f16_to_q15.d ./src/SupportFunctions/arm_f16_to_q15.o ./src/SupportFunctions/arm_f64_to_f16.d ./src/SupportFunctions/arm_f64_to_f16.o ./src/SupportFunctions/arm_f64_to_float.d ./src/SupportFunctions/arm_f64_to_float.o ./src/SupportFunctions/arm_f64_to_q15.d ./src/SupportFunctions/arm_f64_to_q15.o ./src/SupportFunctions/arm_f64_to_q31.d ./src/SupportFunctions/arm_f64_to_q31.o ./src/SupportFunctions/arm_f64_to_q7.d ./src/SupportFunctions/arm_f64_to_q7.o ./src/SupportFunctions/arm_fill_f16.d ./src/SupportFunctions/arm_fill_f16.o ./src/SupportFunctions/arm_fill_f32.d ./src/SupportFunctions/arm_fill_f32.o ./src/SupportFunctions/arm_fill_f64.d ./src/SupportFunctions/arm_fill_f64.o ./src/SupportFunctions/arm_fill_q15.d ./src/SupportFunctions/arm_fill_q15.o ./src/SupportFunctions/arm_fill_q31.d ./src/SupportFunctions/arm_fill_q31.o ./src/SupportFunctions/arm_fill_q7.d ./src/SupportFunctions/arm_fill_q7.o ./src/SupportFunctions/arm_float_to_f16.d ./src/SupportFunctions/arm_float_to_f16.o ./src/SupportFunctions/arm_float_to_f64.d ./src/SupportFunctions/arm_float_to_f64.o ./src/SupportFunctions/arm_float_to_q15.d ./src/SupportFunctions/arm_float_to_q15.o ./src/SupportFunctions/arm_float_to_q31.d ./src/SupportFunctions/arm_float_to_q31.o ./src/SupportFunctions/arm_float_to_q7.d ./src/SupportFunctions/arm_float_to_q7.o ./src/SupportFunctions/arm_heap_sort_f32.d ./src/SupportFunctions/arm_heap_sort_f32.o ./src/SupportFunctions/arm_insertion_sort_f32.d ./src/SupportFunctions/arm_insertion_sort_f32.o ./src/SupportFunctions/arm_merge_sort_f32.d ./src/SupportFunctions/arm_merge_sort_f32.o ./src/SupportFunctions/arm_merge_sort_init_f32.d ./src/SupportFunctions/arm_merge_sort_init_f32.o ./src/SupportFunctions/arm_q15_to_f16.d ./src/SupportFunctions/arm_q15_to_f16.o ./src/SupportFunctions/arm_q15_to_f64.d ./src/SupportFunctions/arm_q15_to_f64.o ./src/SupportFunctions/arm_q15_to_float.d ./src/SupportFunctions/arm_q15_to_float.o ./src/SupportFunctions/arm_q15_to_q31.d ./src/SupportFunctions/arm_q15_to_q31.o ./src/SupportFunctions/arm_q15_to_q7.d ./src/SupportFunctions/arm_q15_to_q7.o ./src/SupportFunctions/arm_q31_to_f64.d ./src/SupportFunctions/arm_q31_to_f64.o ./src/SupportFunctions/arm_q31_to_float.d ./src/SupportFunctions/arm_q31_to_float.o ./src/SupportFunctions/arm_q31_to_q15.d ./src/SupportFunctions/arm_q31_to_q15.o ./src/SupportFunctions/arm_q31_to_q7.d ./src/SupportFunctions/arm_q31_to_q7.o ./src/SupportFunctions/arm_q7_to_f64.d ./src/SupportFunctions/arm_q7_to_f64.o ./src/SupportFunctions/arm_q7_to_float.d ./src/SupportFunctions/arm_q7_to_float.o ./src/SupportFunctions/arm_q7_to_q15.d ./src/SupportFunctions/arm_q7_to_q15.o ./src/SupportFunctions/arm_q7_to_q31.d ./src/SupportFunctions/arm_q7_to_q31.o ./src/SupportFunctions/arm_quick_sort_f32.d ./src/SupportFunctions/arm_quick_sort_f32.o ./src/SupportFunctions/arm_selection_sort_f32.d ./src/SupportFunctions/arm_selection_sort_f32.o ./src/SupportFunctions/arm_sort_f32.d ./src/SupportFunctions/arm_sort_f32.o ./src/SupportFunctions/arm_sort_init_f32.d ./src/SupportFunctions/arm_sort_init_f32.o ./src/SupportFunctions/arm_weighted_sum_f16.d ./src/SupportFunctions/arm_weighted_sum_f16.o ./src/SupportFunctions/arm_weighted_sum_f32.d ./src/SupportFunctions/arm_weighted_sum_f32.o

.PHONY: clean-src-2f-SupportFunctions

