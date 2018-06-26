/*
 * main.c
 *
 *  Created on: 24 de jun de 2018
 *      Author: arthu
 */
#include "main.h"
#include "stm32f407xx_gpio_driver.h"

int main()
{
	GPIO_PIN_CONF_T gpio_conf;
	gpio_conf.alternateFunction = 0;
	gpio_conf.mode = GPIO_Pin_Mode_Output;
	gpio_conf.outputType = GPIO_Pin_Op_Type_PUSH_PULL;
	gpio_conf.pin = 13;
	gpio_conf.speed = GPIO_Pin_Speed_MEDIUM;

	hal_gpio_init(GPIOD, gpio_conf);

	hal_gpio_write_pin(GPIOD, gpio_conf.pin, 1);
	hal_gpio_write_pin(GPIOD, gpio_conf.pin, 0);

	return 1;
}

