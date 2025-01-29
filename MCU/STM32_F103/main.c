#include "stm32f103xb.h"

#define DELAY_COUNT 1000000

void delay(int count) {
    for (volatile int i = 0; i < count; i++) {
        __asm__("nop");
    }
}

int main(void) {
    // Enable GPIOC clock by setting the corresponding bit in RCC_APB2ENR
    RCC_APB2ENR |= RCC_APB2ENR_IOPCEN;

    // Set PC13 as output (2 MHz, general-purpose output push-pull)
    GPIOC_CRH &= ~GPIO_CRH_MODE13_1;   // Clear MODE13 bits
    GPIOC_CRH |= GPIO_CRH_MODE13_1;    // Set MODE13 bits for 2 MHz output speed
    GPIOC_CRH &= ~GPIO_CRH_CNF13;      // Clear CNF13 bits for general-purpose output

    while (1) {
        GPIOC_ODR |= GPIO_ODR_ODR13;  // Turn LED on (set PC13 high)
        delay(DELAY_COUNT);           // Delay
        GPIOC_ODR &= ~GPIO_ODR_ODR13; // Turn LED off (set PC13 low)
        delay(DELAY_COUNT);           // Delay
    }

    return 0;
}

