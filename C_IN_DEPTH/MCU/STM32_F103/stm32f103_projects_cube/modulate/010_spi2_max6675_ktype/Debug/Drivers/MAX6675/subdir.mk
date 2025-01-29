################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/MAX6675/MAX6675.c 

OBJS += \
./Drivers/MAX6675/MAX6675.o 

C_DEPS += \
./Drivers/MAX6675/MAX6675.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/MAX6675/%.o Drivers/MAX6675/%.su Drivers/MAX6675/%.cyclo: ../Drivers/MAX6675/%.c Drivers/MAX6675/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"F:/MCU/MODULATING_VALVE/010_spi2_max6675_ktype/Drivers/MAX6675" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-MAX6675

clean-Drivers-2f-MAX6675:
	-$(RM) ./Drivers/MAX6675/MAX6675.cyclo ./Drivers/MAX6675/MAX6675.d ./Drivers/MAX6675/MAX6675.o ./Drivers/MAX6675/MAX6675.su

.PHONY: clean-Drivers-2f-MAX6675

