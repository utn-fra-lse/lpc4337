################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/WindowFunctions/subdir.mk
-include src/TransformFunctions/subdir.mk
-include src/SupportFunctions/subdir.mk
-include src/StatisticsFunctions/subdir.mk
-include src/SVMFunctions/subdir.mk
-include src/QuaternionMathFunctions/subdir.mk
-include src/MatrixFunctions/subdir.mk
-include src/InterpolationFunctions/subdir.mk
-include src/FilteringFunctions/subdir.mk
-include src/FastMathFunctions/subdir.mk
-include src/DistanceFunctions/subdir.mk
-include src/ControllerFunctions/subdir.mk
-include src/ComplexMathFunctions/subdir.mk
-include src/CommonTables/subdir.mk
-include src/BayesFunctions/subdir.mk
-include src/BasicMathFunctions/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := cmsis_dsp
BUILD_ARTIFACT_EXTENSION := a
BUILD_ARTIFACT_PREFIX := lib
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all:
	+@$(MAKE) --no-print-directory main-build && $(MAKE) --no-print-directory post-build

# Main-build Target
main-build: libcmsis_dsp.a

# Tool invocations
libcmsis_dsp.a: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Archiver'
	arm-none-eabi-ar -r  "libcmsis_dsp.a" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) libcmsis_dsp.a
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "libcmsis_dsp.a" ; # arm-none-eabi-objdump -h -S "libcmsis_dsp.a" >"libcmsis_dsp.lss"
	-@echo ' '

.PHONY: all clean dependents main-build post-build

-include ../makefile.targets
