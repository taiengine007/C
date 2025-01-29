################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/MCP4725/MCP4725.c 

OBJS += \
./Drivers/MCP4725/MCP4725.o 

C_DEPS += \
./Drivers/MCP4725/MCP4725.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/MCP4725/%.o Drivers/MCP4725/%.su Drivers/MCP4725/%.cyclo: ../Drivers/MCP4725/%.c Drivers/MCP4725/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"F:/MCU/MODULATING_VALVE/019_ADCread_mcp4725valve_gpio/Drivers/MCP4725" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-MCP4725

clean-Drivers-2f-MCP4725:
	-$(RM) ./Drivers/MCP4725/MCP4725.cyclo ./Drivers/MCP4725/MCP4725.d ./Drivers/MCP4725/MCP4725.o ./Drivers/MCP4725/MCP4725.su

.PHONY: clean-Drivers-2f-MCP4725

