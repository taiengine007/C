#include "u8g2.h"
#include "stm32f1xx_hal.h"

extern I2C_HandleTypeDef hi2c1;

uint8_t u8x8_byte_hw_i2c(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr) {
    switch(msg) {
        case U8X8_MSG_BYTE_SEND: {
            HAL_I2C_Master_Transmit(&hi2c1, (uint16_t)(u8x8->i2c_address << 1), (uint8_t*)arg_ptr, arg_int, HAL_MAX_DELAY);
            break;
        }
        case U8X8_MSG_BYTE_INIT: {
            break;
        }
        case U8X8_MSG_BYTE_SET_DC:
        case U8X8_MSG_BYTE_START_TRANSFER:
        case U8X8_MSG_BYTE_END_TRANSFER:
            break;
    }
    return 0;
}

void u8g2Init() {
    static u8g2_t u8g2;
    u8g2_Setup_sh1106_i2c_128x64_noname_f(&u8g2, U8G2_R0, u8x8_byte_hw_i2c, u8x8_gpio_and_delay_stm32);
    u8g2_InitDisplay(&u8g2);
    u8g2_SetPowerSave(&u8g2, 0);
    u8g2_ClearBuffer(&u8g2);
    u8g2_DrawStr(&u8g2, 0, 20, "Hello World!");
    u8g2_SendBuffer(&u8g2);
}
