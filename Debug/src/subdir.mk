################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Lab4Test.cpp \
../src/Location.cpp \
../src/Map.cpp \
../src/Robot.cpp 

OBJS += \
./src/Lab4Test.o \
./src/Location.o \
./src/Map.o \
./src/Robot.o 

CPP_DEPS += \
./src/Lab4Test.d \
./src/Location.d \
./src/Map.d \
./src/Robot.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


