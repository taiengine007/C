# Makefile for STM32F103 LED Blink example

TARGET = your_firmware
MCU = cortex-m3
CFLAGS = -mcpu=$(MCU) -mthumb -nostdlib -g
LDFLAGS = -Tstm32f103.ld -nostartfiles

# List of source files
SRC = main.c

# Compiler and linker commands
CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
LD = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy

# Build rules
$(TARGET).elf: $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) -o $(TARGET).elf
	$(OBJCOPY) -O binary $(TARGET).elf $(TARGET).bin
	

clean:
	rm -f $(TARGET).elf $(TARGET).bin
