/*
 * stm32f407xx_gpio_driver.h
 *
 *  Created on: 24 de jun de 2018
 *      Author: arthu
 */

#ifndef STM32F4XX_HAL_DRIVER_INC_STM32F407XX_GPIO_DRIVER_H_
#define STM32F4XX_HAL_DRIVER_INC_STM32F407XX_GPIO_DRIVER_H_

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

#endif /* STM32F4XX_HAL_DRIVER_INC_STM32F407XX_GPIO_DRIVER_H_ */
