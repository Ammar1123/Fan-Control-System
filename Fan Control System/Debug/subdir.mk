################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../Application.c \
../DcMotor.c \
../LCD.c \
../Timer0.c \
../gpio.c \
../lm35_sensor.c 

OBJS += \
./ADC.o \
./Application.o \
./DcMotor.o \
./LCD.o \
./Timer0.o \
./gpio.o \
./lm35_sensor.o 

C_DEPS += \
./ADC.d \
./Application.d \
./DcMotor.d \
./LCD.d \
./Timer0.d \
./gpio.d \
./lm35_sensor.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


