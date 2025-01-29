################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/oled/ssd1306.c \
../Drivers/oled/ssd1306_fonts.c 

OBJS += \
./Drivers/oled/ssd1306.o \
./Drivers/oled/ssd1306_fonts.o 

C_DEPS += \
./Drivers/oled/ssd1306.d \
./Drivers/oled/ssd1306_fonts.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/oled/%.o Drivers/oled/%.su Drivers/oled/%.cyclo: ../Drivers/oled/%.c Drivers/oled/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"F:/MCU/MODULATING_VALVE/006_SPI_OLED/Drivers/oled" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-oled

clean-Drivers-2f-oled:
	-$(RM) ./Drivers/oled/ssd1306.cyclo ./Drivers/oled/ssd1306.d ./Drivers/oled/ssd1306.o ./Drivers/oled/ssd1306.su ./Drivers/oled/ssd1306_fonts.cyclo ./Drivers/oled/ssd1306_fonts.d ./Drivers/oled/ssd1306_fonts.o ./Drivers/oled/ssd1306_fonts.su

.PHONY: clean-Drivers-2f-oled

