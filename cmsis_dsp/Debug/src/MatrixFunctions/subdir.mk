################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/MatrixFunctions/MatrixFunctions.c \
../src/MatrixFunctions/MatrixFunctionsF16.c \
../src/MatrixFunctions/arm_householder_f16.c \
../src/MatrixFunctions/arm_householder_f32.c \
../src/MatrixFunctions/arm_householder_f64.c \
../src/MatrixFunctions/arm_mat_add_f16.c \
../src/MatrixFunctions/arm_mat_add_f32.c \
../src/MatrixFunctions/arm_mat_add_q15.c \
../src/MatrixFunctions/arm_mat_add_q31.c \
../src/MatrixFunctions/arm_mat_cholesky_f16.c \
../src/MatrixFunctions/arm_mat_cholesky_f32.c \
../src/MatrixFunctions/arm_mat_cholesky_f64.c \
../src/MatrixFunctions/arm_mat_cmplx_mult_f16.c \
../src/MatrixFunctions/arm_mat_cmplx_mult_f32.c \
../src/MatrixFunctions/arm_mat_cmplx_mult_q15.c \
../src/MatrixFunctions/arm_mat_cmplx_mult_q31.c \
../src/MatrixFunctions/arm_mat_cmplx_trans_f16.c \
../src/MatrixFunctions/arm_mat_cmplx_trans_f32.c \
../src/MatrixFunctions/arm_mat_cmplx_trans_q15.c \
../src/MatrixFunctions/arm_mat_cmplx_trans_q31.c \
../src/MatrixFunctions/arm_mat_init_f16.c \
../src/MatrixFunctions/arm_mat_init_f32.c \
../src/MatrixFunctions/arm_mat_init_f64.c \
../src/MatrixFunctions/arm_mat_init_q15.c \
../src/MatrixFunctions/arm_mat_init_q31.c \
../src/MatrixFunctions/arm_mat_inverse_f16.c \
../src/MatrixFunctions/arm_mat_inverse_f32.c \
../src/MatrixFunctions/arm_mat_inverse_f64.c \
../src/MatrixFunctions/arm_mat_ldlt_f32.c \
../src/MatrixFunctions/arm_mat_ldlt_f64.c \
../src/MatrixFunctions/arm_mat_mult_f16.c \
../src/MatrixFunctions/arm_mat_mult_f32.c \
../src/MatrixFunctions/arm_mat_mult_f64.c \
../src/MatrixFunctions/arm_mat_mult_fast_q15.c \
../src/MatrixFunctions/arm_mat_mult_fast_q31.c \
../src/MatrixFunctions/arm_mat_mult_opt_q31.c \
../src/MatrixFunctions/arm_mat_mult_q15.c \
../src/MatrixFunctions/arm_mat_mult_q31.c \
../src/MatrixFunctions/arm_mat_mult_q7.c \
../src/MatrixFunctions/arm_mat_qr_f16.c \
../src/MatrixFunctions/arm_mat_qr_f32.c \
../src/MatrixFunctions/arm_mat_qr_f64.c \
../src/MatrixFunctions/arm_mat_scale_f16.c \
../src/MatrixFunctions/arm_mat_scale_f32.c \
../src/MatrixFunctions/arm_mat_scale_q15.c \
../src/MatrixFunctions/arm_mat_scale_q31.c \
../src/MatrixFunctions/arm_mat_solve_lower_triangular_f16.c \
../src/MatrixFunctions/arm_mat_solve_lower_triangular_f32.c \
../src/MatrixFunctions/arm_mat_solve_lower_triangular_f64.c \
../src/MatrixFunctions/arm_mat_solve_upper_triangular_f16.c \
../src/MatrixFunctions/arm_mat_solve_upper_triangular_f32.c \
../src/MatrixFunctions/arm_mat_solve_upper_triangular_f64.c \
../src/MatrixFunctions/arm_mat_sub_f16.c \
../src/MatrixFunctions/arm_mat_sub_f32.c \
../src/MatrixFunctions/arm_mat_sub_f64.c \
../src/MatrixFunctions/arm_mat_sub_q15.c \
../src/MatrixFunctions/arm_mat_sub_q31.c \
../src/MatrixFunctions/arm_mat_trans_f16.c \
../src/MatrixFunctions/arm_mat_trans_f32.c \
../src/MatrixFunctions/arm_mat_trans_f64.c \
../src/MatrixFunctions/arm_mat_trans_q15.c \
../src/MatrixFunctions/arm_mat_trans_q31.c \
../src/MatrixFunctions/arm_mat_trans_q7.c \
../src/MatrixFunctions/arm_mat_vec_mult_f16.c \
../src/MatrixFunctions/arm_mat_vec_mult_f32.c \
../src/MatrixFunctions/arm_mat_vec_mult_q15.c \
../src/MatrixFunctions/arm_mat_vec_mult_q31.c \
../src/MatrixFunctions/arm_mat_vec_mult_q7.c 

C_DEPS += \
./src/MatrixFunctions/MatrixFunctions.d \
./src/MatrixFunctions/MatrixFunctionsF16.d \
./src/MatrixFunctions/arm_householder_f16.d \
./src/MatrixFunctions/arm_householder_f32.d \
./src/MatrixFunctions/arm_householder_f64.d \
./src/MatrixFunctions/arm_mat_add_f16.d \
./src/MatrixFunctions/arm_mat_add_f32.d \
./src/MatrixFunctions/arm_mat_add_q15.d \
./src/MatrixFunctions/arm_mat_add_q31.d \
./src/MatrixFunctions/arm_mat_cholesky_f16.d \
./src/MatrixFunctions/arm_mat_cholesky_f32.d \
./src/MatrixFunctions/arm_mat_cholesky_f64.d \
./src/MatrixFunctions/arm_mat_cmplx_mult_f16.d \
./src/MatrixFunctions/arm_mat_cmplx_mult_f32.d \
./src/MatrixFunctions/arm_mat_cmplx_mult_q15.d \
./src/MatrixFunctions/arm_mat_cmplx_mult_q31.d \
./src/MatrixFunctions/arm_mat_cmplx_trans_f16.d \
./src/MatrixFunctions/arm_mat_cmplx_trans_f32.d \
./src/MatrixFunctions/arm_mat_cmplx_trans_q15.d \
./src/MatrixFunctions/arm_mat_cmplx_trans_q31.d \
./src/MatrixFunctions/arm_mat_init_f16.d \
./src/MatrixFunctions/arm_mat_init_f32.d \
./src/MatrixFunctions/arm_mat_init_f64.d \
./src/MatrixFunctions/arm_mat_init_q15.d \
./src/MatrixFunctions/arm_mat_init_q31.d \
./src/MatrixFunctions/arm_mat_inverse_f16.d \
./src/MatrixFunctions/arm_mat_inverse_f32.d \
./src/MatrixFunctions/arm_mat_inverse_f64.d \
./src/MatrixFunctions/arm_mat_ldlt_f32.d \
./src/MatrixFunctions/arm_mat_ldlt_f64.d \
./src/MatrixFunctions/arm_mat_mult_f16.d \
./src/MatrixFunctions/arm_mat_mult_f32.d \
./src/MatrixFunctions/arm_mat_mult_f64.d \
./src/MatrixFunctions/arm_mat_mult_fast_q15.d \
./src/MatrixFunctions/arm_mat_mult_fast_q31.d \
./src/MatrixFunctions/arm_mat_mult_opt_q31.d \
./src/MatrixFunctions/arm_mat_mult_q15.d \
./src/MatrixFunctions/arm_mat_mult_q31.d \
./src/MatrixFunctions/arm_mat_mult_q7.d \
./src/MatrixFunctions/arm_mat_qr_f16.d \
./src/MatrixFunctions/arm_mat_qr_f32.d \
./src/MatrixFunctions/arm_mat_qr_f64.d \
./src/MatrixFunctions/arm_mat_scale_f16.d \
./src/MatrixFunctions/arm_mat_scale_f32.d \
./src/MatrixFunctions/arm_mat_scale_q15.d \
./src/MatrixFunctions/arm_mat_scale_q31.d \
./src/MatrixFunctions/arm_mat_solve_lower_triangular_f16.d \
./src/MatrixFunctions/arm_mat_solve_lower_triangular_f32.d \
./src/MatrixFunctions/arm_mat_solve_lower_triangular_f64.d \
./src/MatrixFunctions/arm_mat_solve_upper_triangular_f16.d \
./src/MatrixFunctions/arm_mat_solve_upper_triangular_f32.d \
./src/MatrixFunctions/arm_mat_solve_upper_triangular_f64.d \
./src/MatrixFunctions/arm_mat_sub_f16.d \
./src/MatrixFunctions/arm_mat_sub_f32.d \
./src/MatrixFunctions/arm_mat_sub_f64.d \
./src/MatrixFunctions/arm_mat_sub_q15.d \
./src/MatrixFunctions/arm_mat_sub_q31.d \
./src/MatrixFunctions/arm_mat_trans_f16.d \
./src/MatrixFunctions/arm_mat_trans_f32.d \
./src/MatrixFunctions/arm_mat_trans_f64.d \
./src/MatrixFunctions/arm_mat_trans_q15.d \
./src/MatrixFunctions/arm_mat_trans_q31.d \
./src/MatrixFunctions/arm_mat_trans_q7.d \
./src/MatrixFunctions/arm_mat_vec_mult_f16.d \
./src/MatrixFunctions/arm_mat_vec_mult_f32.d \
./src/MatrixFunctions/arm_mat_vec_mult_q15.d \
./src/MatrixFunctions/arm_mat_vec_mult_q31.d \
./src/MatrixFunctions/arm_mat_vec_mult_q7.d 

OBJS += \
./src/MatrixFunctions/MatrixFunctions.o \
./src/MatrixFunctions/MatrixFunctionsF16.o \
./src/MatrixFunctions/arm_householder_f16.o \
./src/MatrixFunctions/arm_householder_f32.o \
./src/MatrixFunctions/arm_householder_f64.o \
./src/MatrixFunctions/arm_mat_add_f16.o \
./src/MatrixFunctions/arm_mat_add_f32.o \
./src/MatrixFunctions/arm_mat_add_q15.o \
./src/MatrixFunctions/arm_mat_add_q31.o \
./src/MatrixFunctions/arm_mat_cholesky_f16.o \
./src/MatrixFunctions/arm_mat_cholesky_f32.o \
./src/MatrixFunctions/arm_mat_cholesky_f64.o \
./src/MatrixFunctions/arm_mat_cmplx_mult_f16.o \
./src/MatrixFunctions/arm_mat_cmplx_mult_f32.o \
./src/MatrixFunctions/arm_mat_cmplx_mult_q15.o \
./src/MatrixFunctions/arm_mat_cmplx_mult_q31.o \
./src/MatrixFunctions/arm_mat_cmplx_trans_f16.o \
./src/MatrixFunctions/arm_mat_cmplx_trans_f32.o \
./src/MatrixFunctions/arm_mat_cmplx_trans_q15.o \
./src/MatrixFunctions/arm_mat_cmplx_trans_q31.o \
./src/MatrixFunctions/arm_mat_init_f16.o \
./src/MatrixFunctions/arm_mat_init_f32.o \
./src/MatrixFunctions/arm_mat_init_f64.o \
./src/MatrixFunctions/arm_mat_init_q15.o \
./src/MatrixFunctions/arm_mat_init_q31.o \
./src/MatrixFunctions/arm_mat_inverse_f16.o \
./src/MatrixFunctions/arm_mat_inverse_f32.o \
./src/MatrixFunctions/arm_mat_inverse_f64.o \
./src/MatrixFunctions/arm_mat_ldlt_f32.o \
./src/MatrixFunctions/arm_mat_ldlt_f64.o \
./src/MatrixFunctions/arm_mat_mult_f16.o \
./src/MatrixFunctions/arm_mat_mult_f32.o \
./src/MatrixFunctions/arm_mat_mult_f64.o \
./src/MatrixFunctions/arm_mat_mult_fast_q15.o \
./src/MatrixFunctions/arm_mat_mult_fast_q31.o \
./src/MatrixFunctions/arm_mat_mult_opt_q31.o \
./src/MatrixFunctions/arm_mat_mult_q15.o \
./src/MatrixFunctions/arm_mat_mult_q31.o \
./src/MatrixFunctions/arm_mat_mult_q7.o \
./src/MatrixFunctions/arm_mat_qr_f16.o \
./src/MatrixFunctions/arm_mat_qr_f32.o \
./src/MatrixFunctions/arm_mat_qr_f64.o \
./src/MatrixFunctions/arm_mat_scale_f16.o \
./src/MatrixFunctions/arm_mat_scale_f32.o \
./src/MatrixFunctions/arm_mat_scale_q15.o \
./src/MatrixFunctions/arm_mat_scale_q31.o \
./src/MatrixFunctions/arm_mat_solve_lower_triangular_f16.o \
./src/MatrixFunctions/arm_mat_solve_lower_triangular_f32.o \
./src/MatrixFunctions/arm_mat_solve_lower_triangular_f64.o \
./src/MatrixFunctions/arm_mat_solve_upper_triangular_f16.o \
./src/MatrixFunctions/arm_mat_solve_upper_triangular_f32.o \
./src/MatrixFunctions/arm_mat_solve_upper_triangular_f64.o \
./src/MatrixFunctions/arm_mat_sub_f16.o \
./src/MatrixFunctions/arm_mat_sub_f32.o \
./src/MatrixFunctions/arm_mat_sub_f64.o \
./src/MatrixFunctions/arm_mat_sub_q15.o \
./src/MatrixFunctions/arm_mat_sub_q31.o \
./src/MatrixFunctions/arm_mat_trans_f16.o \
./src/MatrixFunctions/arm_mat_trans_f32.o \
./src/MatrixFunctions/arm_mat_trans_f64.o \
./src/MatrixFunctions/arm_mat_trans_q15.o \
./src/MatrixFunctions/arm_mat_trans_q31.o \
./src/MatrixFunctions/arm_mat_trans_q7.o \
./src/MatrixFunctions/arm_mat_vec_mult_f16.o \
./src/MatrixFunctions/arm_mat_vec_mult_f32.o \
./src/MatrixFunctions/arm_mat_vec_mult_q15.o \
./src/MatrixFunctions/arm_mat_vec_mult_q31.o \
./src/MatrixFunctions/arm_mat_vec_mult_q7.o 


# Each subdirectory must supply rules for building sources it contributes
src/MatrixFunctions/%.o: ../src/MatrixFunctions/%.c src/MatrixFunctions/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -D__REDLIB__ -DCORE_M4 -D__USE_LPCOPEN -D__LPC43XX__ -I"/media/carlassaraf/DATA/facultad/TD III/2022_td3_512_carlassara/3.workspace/cmsis_dsp/inc" -I"/media/carlassaraf/DATA/facultad/TD III/2022_td3_512_carlassara/3.workspace/chip/lpc_chip_43xx/inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fsingle-precision-constant -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-MatrixFunctions

clean-src-2f-MatrixFunctions:
	-$(RM) ./src/MatrixFunctions/MatrixFunctions.d ./src/MatrixFunctions/MatrixFunctions.o ./src/MatrixFunctions/MatrixFunctionsF16.d ./src/MatrixFunctions/MatrixFunctionsF16.o ./src/MatrixFunctions/arm_householder_f16.d ./src/MatrixFunctions/arm_householder_f16.o ./src/MatrixFunctions/arm_householder_f32.d ./src/MatrixFunctions/arm_householder_f32.o ./src/MatrixFunctions/arm_householder_f64.d ./src/MatrixFunctions/arm_householder_f64.o ./src/MatrixFunctions/arm_mat_add_f16.d ./src/MatrixFunctions/arm_mat_add_f16.o ./src/MatrixFunctions/arm_mat_add_f32.d ./src/MatrixFunctions/arm_mat_add_f32.o ./src/MatrixFunctions/arm_mat_add_q15.d ./src/MatrixFunctions/arm_mat_add_q15.o ./src/MatrixFunctions/arm_mat_add_q31.d ./src/MatrixFunctions/arm_mat_add_q31.o ./src/MatrixFunctions/arm_mat_cholesky_f16.d ./src/MatrixFunctions/arm_mat_cholesky_f16.o ./src/MatrixFunctions/arm_mat_cholesky_f32.d ./src/MatrixFunctions/arm_mat_cholesky_f32.o ./src/MatrixFunctions/arm_mat_cholesky_f64.d ./src/MatrixFunctions/arm_mat_cholesky_f64.o ./src/MatrixFunctions/arm_mat_cmplx_mult_f16.d ./src/MatrixFunctions/arm_mat_cmplx_mult_f16.o ./src/MatrixFunctions/arm_mat_cmplx_mult_f32.d ./src/MatrixFunctions/arm_mat_cmplx_mult_f32.o ./src/MatrixFunctions/arm_mat_cmplx_mult_q15.d ./src/MatrixFunctions/arm_mat_cmplx_mult_q15.o ./src/MatrixFunctions/arm_mat_cmplx_mult_q31.d ./src/MatrixFunctions/arm_mat_cmplx_mult_q31.o ./src/MatrixFunctions/arm_mat_cmplx_trans_f16.d ./src/MatrixFunctions/arm_mat_cmplx_trans_f16.o ./src/MatrixFunctions/arm_mat_cmplx_trans_f32.d ./src/MatrixFunctions/arm_mat_cmplx_trans_f32.o ./src/MatrixFunctions/arm_mat_cmplx_trans_q15.d ./src/MatrixFunctions/arm_mat_cmplx_trans_q15.o ./src/MatrixFunctions/arm_mat_cmplx_trans_q31.d ./src/MatrixFunctions/arm_mat_cmplx_trans_q31.o ./src/MatrixFunctions/arm_mat_init_f16.d ./src/MatrixFunctions/arm_mat_init_f16.o ./src/MatrixFunctions/arm_mat_init_f32.d ./src/MatrixFunctions/arm_mat_init_f32.o ./src/MatrixFunctions/arm_mat_init_f64.d ./src/MatrixFunctions/arm_mat_init_f64.o ./src/MatrixFunctions/arm_mat_init_q15.d ./src/MatrixFunctions/arm_mat_init_q15.o ./src/MatrixFunctions/arm_mat_init_q31.d ./src/MatrixFunctions/arm_mat_init_q31.o ./src/MatrixFunctions/arm_mat_inverse_f16.d ./src/MatrixFunctions/arm_mat_inverse_f16.o ./src/MatrixFunctions/arm_mat_inverse_f32.d ./src/MatrixFunctions/arm_mat_inverse_f32.o ./src/MatrixFunctions/arm_mat_inverse_f64.d ./src/MatrixFunctions/arm_mat_inverse_f64.o ./src/MatrixFunctions/arm_mat_ldlt_f32.d ./src/MatrixFunctions/arm_mat_ldlt_f32.o ./src/MatrixFunctions/arm_mat_ldlt_f64.d ./src/MatrixFunctions/arm_mat_ldlt_f64.o ./src/MatrixFunctions/arm_mat_mult_f16.d ./src/MatrixFunctions/arm_mat_mult_f16.o ./src/MatrixFunctions/arm_mat_mult_f32.d ./src/MatrixFunctions/arm_mat_mult_f32.o ./src/MatrixFunctions/arm_mat_mult_f64.d ./src/MatrixFunctions/arm_mat_mult_f64.o ./src/MatrixFunctions/arm_mat_mult_fast_q15.d ./src/MatrixFunctions/arm_mat_mult_fast_q15.o ./src/MatrixFunctions/arm_mat_mult_fast_q31.d ./src/MatrixFunctions/arm_mat_mult_fast_q31.o ./src/MatrixFunctions/arm_mat_mult_opt_q31.d ./src/MatrixFunctions/arm_mat_mult_opt_q31.o ./src/MatrixFunctions/arm_mat_mult_q15.d ./src/MatrixFunctions/arm_mat_mult_q15.o ./src/MatrixFunctions/arm_mat_mult_q31.d ./src/MatrixFunctions/arm_mat_mult_q31.o ./src/MatrixFunctions/arm_mat_mult_q7.d ./src/MatrixFunctions/arm_mat_mult_q7.o ./src/MatrixFunctions/arm_mat_qr_f16.d ./src/MatrixFunctions/arm_mat_qr_f16.o ./src/MatrixFunctions/arm_mat_qr_f32.d ./src/MatrixFunctions/arm_mat_qr_f32.o ./src/MatrixFunctions/arm_mat_qr_f64.d ./src/MatrixFunctions/arm_mat_qr_f64.o ./src/MatrixFunctions/arm_mat_scale_f16.d ./src/MatrixFunctions/arm_mat_scale_f16.o ./src/MatrixFunctions/arm_mat_scale_f32.d ./src/MatrixFunctions/arm_mat_scale_f32.o ./src/MatrixFunctions/arm_mat_scale_q15.d ./src/MatrixFunctions/arm_mat_scale_q15.o ./src/MatrixFunctions/arm_mat_scale_q31.d ./src/MatrixFunctions/arm_mat_scale_q31.o ./src/MatrixFunctions/arm_mat_solve_lower_triangular_f16.d ./src/MatrixFunctions/arm_mat_solve_lower_triangular_f16.o ./src/MatrixFunctions/arm_mat_solve_lower_triangular_f32.d ./src/MatrixFunctions/arm_mat_solve_lower_triangular_f32.o ./src/MatrixFunctions/arm_mat_solve_lower_triangular_f64.d ./src/MatrixFunctions/arm_mat_solve_lower_triangular_f64.o ./src/MatrixFunctions/arm_mat_solve_upper_triangular_f16.d ./src/MatrixFunctions/arm_mat_solve_upper_triangular_f16.o ./src/MatrixFunctions/arm_mat_solve_upper_triangular_f32.d ./src/MatrixFunctions/arm_mat_solve_upper_triangular_f32.o ./src/MatrixFunctions/arm_mat_solve_upper_triangular_f64.d ./src/MatrixFunctions/arm_mat_solve_upper_triangular_f64.o ./src/MatrixFunctions/arm_mat_sub_f16.d ./src/MatrixFunctions/arm_mat_sub_f16.o ./src/MatrixFunctions/arm_mat_sub_f32.d ./src/MatrixFunctions/arm_mat_sub_f32.o ./src/MatrixFunctions/arm_mat_sub_f64.d ./src/MatrixFunctions/arm_mat_sub_f64.o ./src/MatrixFunctions/arm_mat_sub_q15.d ./src/MatrixFunctions/arm_mat_sub_q15.o ./src/MatrixFunctions/arm_mat_sub_q31.d ./src/MatrixFunctions/arm_mat_sub_q31.o ./src/MatrixFunctions/arm_mat_trans_f16.d ./src/MatrixFunctions/arm_mat_trans_f16.o ./src/MatrixFunctions/arm_mat_trans_f32.d ./src/MatrixFunctions/arm_mat_trans_f32.o ./src/MatrixFunctions/arm_mat_trans_f64.d ./src/MatrixFunctions/arm_mat_trans_f64.o ./src/MatrixFunctions/arm_mat_trans_q15.d ./src/MatrixFunctions/arm_mat_trans_q15.o ./src/MatrixFunctions/arm_mat_trans_q31.d ./src/MatrixFunctions/arm_mat_trans_q31.o ./src/MatrixFunctions/arm_mat_trans_q7.d ./src/MatrixFunctions/arm_mat_trans_q7.o ./src/MatrixFunctions/arm_mat_vec_mult_f16.d ./src/MatrixFunctions/arm_mat_vec_mult_f16.o ./src/MatrixFunctions/arm_mat_vec_mult_f32.d ./src/MatrixFunctions/arm_mat_vec_mult_f32.o ./src/MatrixFunctions/arm_mat_vec_mult_q15.d ./src/MatrixFunctions/arm_mat_vec_mult_q15.o ./src/MatrixFunctions/arm_mat_vec_mult_q31.d ./src/MatrixFunctions/arm_mat_vec_mult_q31.o ./src/MatrixFunctions/arm_mat_vec_mult_q7.d
	-$(RM) ./src/MatrixFunctions/arm_mat_vec_mult_q7.o

.PHONY: clean-src-2f-MatrixFunctions

