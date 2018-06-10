################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/com/tandon/Node.cpp \
../src/com/tandon/global.cpp 

OBJS += \
./src/com/tandon/Node.o \
./src/com/tandon/global.o 

CPP_DEPS += \
./src/com/tandon/Node.d \
./src/com/tandon/global.d 


# Each subdirectory must supply rules for building sources it contributes
src/com/tandon/%.o: ../src/com/tandon/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


