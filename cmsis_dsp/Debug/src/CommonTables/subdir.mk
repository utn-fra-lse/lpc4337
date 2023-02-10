################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/CommonTables/CommonTables.c \
../src/CommonTables/CommonTablesF16.c \
../src/CommonTables/arm_common_tables.c \
../src/CommonTables/arm_common_tables_f16.c \
../src/CommonTables/arm_const_structs.c \
../src/CommonTables/arm_const_structs_f16.c \
../src/CommonTables/arm_mve_tables.c \
../src/CommonTables/arm_mve_tables_f16.c 

C_DEPS += \
./src/CommonTables/CommonTables.d \
./src/CommonTables/CommonTablesF16.d \
./src/CommonTables/arm_common_tables.d \
./src/CommonTables/arm_common_tables_f16.d \
./src/CommonTables/arm_const_structs.d \
./src/CommonTables/arm_const_structs_f16.d \
./src/CommonTables/arm_mve_tables.d \
./src/CommonTables/arm_mve_tables_f16.d 

OBJS += \
./src/CommonTables/CommonTables.o \
./src/CommonTables/CommonTablesF16.o \
./src/CommonTables/arm_common_tables.o \
./src/CommonTables/arm_common_tables_f16.o \
./src/CommonTables/arm_const_structs.o \
./src/CommonTables/arm_const_structs_f16.o \
./src/CommonTables/arm_mve_tables.o \
./src/CommonTables/arm_mve_tables_f16.o 


# Each subdirectory must supply rules for building sources it contributes
src/CommonTables/%.o: ../src/CommonTables/%.c src/CommonTables/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -D__REDLIB__ -DCORE_M4 -D__USE_LPCOPEN -D__LPC43XX__ -I"/media/carlassaraf/DATA/facultad/TD III/2022_td3_512_carlassara/3.workspace/cmsis_dsp/inc" -I"/media/carlassaraf/DATA/facultad/TD III/2022_td3_512_carlassara/3.workspace/chip/lpc_chip_43xx/inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fsingle-precision-constant -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-CommonTables

clean-src-2f-CommonTables:
	-$(RM) ./src/CommonTables/CommonTables.d ./src/CommonTables/CommonTables.o ./src/CommonTables/CommonTablesF16.d ./src/CommonTables/CommonTablesF16.o ./src/CommonTables/arm_common_tables.d ./src/CommonTables/arm_common_tables.o ./src/CommonTables/arm_common_tables_f16.d ./src/CommonTables/arm_common_tables_f16.o ./src/CommonTables/arm_const_structs.d ./src/CommonTables/arm_const_structs.o ./src/CommonTables/arm_const_structs_f16.d ./src/CommonTables/arm_const_structs_f16.o ./src/CommonTables/arm_mve_tables.d ./src/CommonTables/arm_mve_tables.o ./src/CommonTables/arm_mve_tables_f16.d ./src/CommonTables/arm_mve_tables_f16.o

.PHONY: clean-src-2f-CommonTables

