################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/alex/Arduino/libraries/Encoder/Encoder.cpp 

LINK_OBJ += \
./libraries/Encoder/Encoder.cpp.o 

CPP_DEPS += \
./libraries/Encoder/Encoder.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/Encoder/Encoder.cpp.o: /home/alex/Arduino/libraries/Encoder/Encoder.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/alex/Documents/sloeber//arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/alex/Documents/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"/home/alex/Documents/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.20/variants/eightanaloginputs" -I"/home/alex/Arduino/libraries/Encoder" -I"/home/alex/Arduino/libraries/Encoder/utility" -I"/home/alex/Arduino/libraries/eRCaGuy_Timer2_Counter" -I"/home/alex/Arduino/libraries/PID" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


