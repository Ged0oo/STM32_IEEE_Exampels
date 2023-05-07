################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/DC_MOTOR_program.c \
../Src/GPIO_program.c \
../Src/KEYPAD_program.c \
../Src/LCD_program.c \
../Src/LED_program.c \
../Src/RCC_program.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/DC_MOTOR_program.o \
./Src/GPIO_program.o \
./Src/KEYPAD_program.o \
./Src/LCD_program.o \
./Src/LED_program.o \
./Src/RCC_program.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/DC_MOTOR_program.d \
./Src/GPIO_program.d \
./Src/KEYPAD_program.d \
./Src/LCD_program.d \
./Src/LED_program.d \
./Src/RCC_program.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/DC_MOTOR_program.cyclo ./Src/DC_MOTOR_program.d ./Src/DC_MOTOR_program.o ./Src/DC_MOTOR_program.su ./Src/GPIO_program.cyclo ./Src/GPIO_program.d ./Src/GPIO_program.o ./Src/GPIO_program.su ./Src/KEYPAD_program.cyclo ./Src/KEYPAD_program.d ./Src/KEYPAD_program.o ./Src/KEYPAD_program.su ./Src/LCD_program.cyclo ./Src/LCD_program.d ./Src/LCD_program.o ./Src/LCD_program.su ./Src/LED_program.cyclo ./Src/LED_program.d ./Src/LED_program.o ./Src/LED_program.su ./Src/RCC_program.cyclo ./Src/RCC_program.d ./Src/RCC_program.o ./Src/RCC_program.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

