#ifndef INC_MAX6675_H_
#define INC_MAX6675_H_

#include"stm32f1xx_hal.h"

// ------------------------- Defines -------------------------
#define SSPORT   GPIOB     // GPIO Port of Chip Select(Slave Select)
#define SSPIN  GPIO_PIN_1  // GPIO PIN of Chip Select(Slave Select)

// ------------------------- Functions  ----------------------
float Max6675_Read_Temp(void);
#endif
