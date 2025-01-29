

#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
#include<stdio.h>

#include<string.h>
#include"MAX6675.h"
#include"ssd1306.h"
#include"MCP4725.h"




void Error_Handler(void);



/* Private defines -----------------------------------------------------------*/
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define B1_EXTI_IRQn EXTI15_10_IRQn
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define RELAY_BUTTON_Pin GPIO_PIN_10
#define RELAY_BUTTON_GPIO_Port GPIOC
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB



#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
