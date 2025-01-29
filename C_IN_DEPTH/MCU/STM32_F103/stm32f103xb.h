#ifndef STM32F103XB_H
#define STM32F103XB_H

#include <stdint.h>

#define RCC_BASE 0x40021000
#define GPIOC_BASE 0x40011000

// RCC (Reset and Clock Control) registers
#define RCC_APB2ENR (*(volatile uint32_t *)(RCC_BASE + 0x18))

// GPIOC registers
#define GPIOC_CRH (*(volatile uint32_t *)(GPIOC_BASE + 0x04))
#define GPIOC_ODR (*(volatile uint32_t *)(GPIOC_BASE + 0x0C))

// RCC_APB2ENR bit definitions
#define RCC_APB2ENR_IOPCEN (1 << 4)  // Enable GPIOC clock

// GPIOC_CRH bit definitions for pin 13 (PC13)
#define GPIO_CRH_MODE13_1 (1 << 20)  // Output mode, 2 MHz
#define GPIO_CRH_CNF13 (0 << 22)     // General purpose output push-pull

// GPIOC_ODR bit definitions
#define GPIO_ODR_ODR13 (1 << 13)     // Output data bit for PC13

#endif // STM32F103XB_H

