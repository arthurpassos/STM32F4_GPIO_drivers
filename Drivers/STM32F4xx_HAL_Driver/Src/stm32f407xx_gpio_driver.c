#include "stm32f407xx_gpio_driver.h"

/*
 *	@brief	Sets the GPIO port mode.
 *	@param	GPIOx: GPIO base address type casted to the struct
 *	@param	Pin: pin number
 *	@param	Mode: input, output, alternate and dialog
 * */

void hal_gpio_set_pin_mode(GPIO_TypeDef *GPIOx, uint16_t pin, GPIO_Pin_Mode mode)
{
	// as we use 2 bits for each pin
	// the pin 3 (starting from pin 0, bit 0) configuration, is located at the bit 6-7.
	// so if i shift the mode by the pin multiplied by two, i get the exact location to put the new cfg.
	const uint8_t offset = 2;

	// first i clear whats in there
	GPIOx->MODER &= ~(0x3 << pin * offset);
	// then i set to the new mode
	GPIOx->MODER |= (mode << pin * offset);
}

/*
 *	@brief	Sets the GPIO port output speed.
 *	@param	GPIOx: GPIO base address type casted to the struct
 *	@param	Pin: pin number
 *	@param	Speed: low, medium, high, very high
 * */
void hal_gpio_set_output_speed(GPIO_TypeDef *GPIOx, uint16_t pin, GPIO_Pin_Speed speed)
{
	// as we use 2 bits for each pin
	// the pin 3 (starting from pin 0, bit 0) configuration, is located at the bit 6-7.
	// so if i shift the mode by the pin multiplied by two, i get the exact location to put the new cfg.
	const uint8_t offset = 2;

	// first i clear whats in there
	GPIOx->OSPEEDR &= ~(0x3 << pin * offset);

	// then i set the new cfg
	GPIOx->OSPEEDR |= (speed << pin * offset);
}

/*
 *	@brief	Sets the GPIO port output type.
 *	@param	GPIOx: GPIO base address type casted to the struct
 *	@param	Pin: pin number
 *	@param	Type: push-pull or open drain
 * */
void hal_gpio_set_output_type(GPIO_TypeDef *GPIOx, uint16_t pin, GPIO_Pin_Op_Type type)
{
	// first i clear whats in there
	GPIOx->OTYPER &= ~(0 << pin);

	// then i set the new cfg
	GPIOx->OTYPER |= (type << pin);
}

void hal_gpio_init(GPIO_TypeDef *GPIOx, GPIO_PIN_CONF_T gpio_conf)
{

}
