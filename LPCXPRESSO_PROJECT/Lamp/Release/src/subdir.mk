################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/cr_startup_lpc13.c \
../src/led.c \
../src/main.c \
../src/spi.c \
../src/uart.c 

OBJS += \
./src/cr_startup_lpc13.o \
./src/led.o \
./src/main.o \
./src/spi.o \
./src/uart.o 

C_DEPS += \
./src/cr_startup_lpc13.d \
./src/led.d \
./src/main.d \
./src/spi.d \
./src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DNDEBUG -D__USE_CMSIS=CMSISv2p00_LPC13xx -D__CODE_RED -D__REDLIB__ -I"C:\Users\Josh\Dropbox\Code\Lamp\LPC13xx_cmsis2_Lib\inc" -I"C:\Users\Josh\Dropbox\Code\Lamp\CMSISv2p00_LPC13xx\inc" -Os -Os -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


