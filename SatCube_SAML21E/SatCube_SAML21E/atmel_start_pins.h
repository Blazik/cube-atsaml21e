/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef ATMEL_START_PINS_H_INCLUDED
#define ATMEL_START_PINS_H_INCLUDED

#include <hal_gpio.h>

// SAML21 has 9 pin functions

#define GPIO_PIN_FUNCTION_A 0
#define GPIO_PIN_FUNCTION_B 1
#define GPIO_PIN_FUNCTION_C 2
#define GPIO_PIN_FUNCTION_D 3
#define GPIO_PIN_FUNCTION_E 4
#define GPIO_PIN_FUNCTION_F 5
#define GPIO_PIN_FUNCTION_G 6
#define GPIO_PIN_FUNCTION_H 7
#define GPIO_PIN_FUNCTION_I 8

#define MCU_1_STATUS_1 GPIO(GPIO_PORTA, 2)
#define MCU_1_STATUS_2 GPIO(GPIO_PORTA, 3)
#define PA04 GPIO(GPIO_PORTA, 4)
#define PA05 GPIO(GPIO_PORTA, 5)
#define MCU_1_STATUS_3 GPIO(GPIO_PORTA, 6)
#define MCU_2_STATUS_1 GPIO(GPIO_PORTA, 7)
#define PA08 GPIO(GPIO_PORTA, 8)
#define PA09 GPIO(GPIO_PORTA, 9)
#define MCU_2_STATUS_2 GPIO(GPIO_PORTA, 10)
#define MCU_2_STATUS_3 GPIO(GPIO_PORTA, 11)
#define POWER_BLOCK_2 GPIO(GPIO_PORTA, 14)
#define POWER_BLOCK_1 GPIO(GPIO_PORTA, 15)
#define PA16 GPIO(GPIO_PORTA, 16)
#define PA17 GPIO(GPIO_PORTA, 17)
#define MCU_3_STATUS_1 GPIO(GPIO_PORTA, 18)
#define MCU_3_STATUS_2 GPIO(GPIO_PORTA, 19)
#define MCU_3_STATUS_3 GPIO(GPIO_PORTA, 22)
#define MCU_2_EN GPIO(GPIO_PORTA, 23)
#define BLOCK_2_EN GPIO(GPIO_PORTA, 24)
#define BLOCK_1_EN GPIO(GPIO_PORTA, 25)
#define MCU_3_EN GPIO(GPIO_PORTA, 27)

#endif // ATMEL_START_PINS_H_INCLUDED
