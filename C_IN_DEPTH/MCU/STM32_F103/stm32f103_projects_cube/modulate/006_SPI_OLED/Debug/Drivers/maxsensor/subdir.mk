################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/maxsensor/MAX6675.c 

OBJS += \
./Drivers/maxsensor/MAX6675.o 

C_DEPS += \
./Drivers/maxsensor/MAX6675.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/maxsensor/%.o Drivers/maxsensor/%.su Drivers/maxsensor/%.cyclo: ../Drivers/maxsensor/%.c Drivers/maxsensor/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"F:/MCU/MODULATING_VALVE/006_SPI_OLED/Drivers/maxsensor" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-maxsensor

clean-Drivers-2f-maxsensor:
	-$(RM) ./Drivers/maxsensor/MAX6675.cyclo ./Drivers/maxsensor/MAX6675.d ./Drivers/maxsensor/MAX6675.o ./Drivers/maxsensor/MAX6675.su

.PHONY: clean-Drivers-2f-maxsensor

