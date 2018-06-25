/*
 * stm32f407xx_gpio_driver.h
 *
 *  Created on: 24 de jun de 2018
 *      Author: arthu
 */

#ifndef STM32F4XX_HAL_DRIVER_INC_STM32F407XX_GPIO_DRIVER_H_
#define STM32F4XX_HAL_DRIVER_INC_STM32F407XX_GPIO_DRIVER_H_

#include "stdint.h"
#include "stm32f407xx.h"

typedef enum
{
	GPIO_Pin_Mode_Input = 0,
	GPIO_Pin_Mode_Output,
	GPIO_Pin_Mode_Alternate,
	GPIO_Pin_Mode_Analog
} GPIO_Pin_Mode;

typedef enum
{
	GPIO_Pin_Op_Type_PUSH_PULL = 0,
	GPIO_Pin_Op_Type_OPEN_DRAIN
} GPIO_Pin_Op_Type;

typedef enum
{
	GPIO_Pin_Speed_SLOW = 0,
	GPIO_Pin_Speed_MEDIUM,
	GPIO_Pin_Speed_HIGH,
	GPIO_Pin_Speed_VERY_HIGH
} GPIO_Pin_Speed;

typedef enum
{
	GPIO_Pin_Pull_Mode_No_Pull_Push = 0,
	GPIO_Pin_Pull_Mode_Pull_Up,
	GPIO_Pin_Pull_Mode_Pull_Down
} GPIO_Pin_Pull_Mode;


#define HAL_RCC_GPIOA_CLK_ENABLE()			(RCC->AHB1ENR |= 1 << 0)
#define HAL_RCC_GPIOB_CLK_ENABLE()			(RCC->AHB1ENR |= 1 << 1)
#define HAL_RCC_GPIOC_CLK_ENABLE()			(RCC->AHB1ENR |= 1 << 2)
#define HAL_RCC_GPIOD_CLK_ENABLE()			(RCC->AHB1ENR |= 1 << 3)
#define HAL_RCC_GPIOE_CLK_ENABLE()			(RCC->AHB1ENR |= 1 << 4)
#define HAL_RCC_GPIOF_CLK_ENABLE()			(RCC->AHB1ENR |= 1 << 5)
#define HAL_RCC_GPIOG_CLK_ENABLE()			(RCC->AHB1ENR |= 1 << 6)
#define HAL_RCC_GPIOH_CLK_ENABLE()			(RCC->AHB1ENR |= 1 << 7)

typedef struct
{
	uint32_t pin;
	GPIO_Pin_Mode mode;
	GPIO_Pin_Op_Type outputType;
	GPIO_Pin_Pull_Mode pull;
	GPIO_Pin_Speed speed;
	uint16_t alternateFunction;
} GPIO_PIN_CONF_T;

void hal_gpio_init(GPIO_TypeDef *GPIOx, GPIO_PIN_CONF_T gpio_conf);

uint8_t hal_gpio_read(GPIO_TypeDef *GPIOx, uint16_t pin);

void hal_gpio_write(GPIO_TypeDef *GPIOx, uint16_t pin, uint8_t data);

void hal_gpio_set_alt_func(GPIO_TypeDef *GPIOx, uint16_t pin, uint16_t alternateFunction);

//-------------- maybe static? ----------------

void hal_gpio_set_pin_mode(GPIO_TypeDef *GPIOx, uint16_t pin, GPIO_Pin_Mode mode);

void hal_gpio_set_output_speed(GPIO_TypeDef *GPIOx, uint16_t pin, GPIO_Pin_Speed speed);

void hal_gpio_set_output_type(GPIO_TypeDef *GPIOx, uint16_t pin, GPIO_Pin_Op_Type type);

// ------------- end maybe static ----------------
#endif /* STM32F4XX_HAL_DRIVER_INC_STM32F407XX_GPIO_DRIVER_H_ */
