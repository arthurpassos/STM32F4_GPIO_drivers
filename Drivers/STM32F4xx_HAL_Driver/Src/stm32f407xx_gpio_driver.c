#include "stm32f407xx_gpio_driver.h"

#define NULL 0x0

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

/*
 *	@brief	Sets the GPIO port pull mode.
 *	@param	GPIOx: GPIO base address type casted to the struct
 *	@param	Pin: pin number
 *	@param	Type: 0x0 no pull-up or pull down, 0x1 pull-up, 0x2 pull-down, 0x3 reserved
 * */
void hal_gpio_set_pull(GPIO_TypeDef *GPIOx, uint16_t pin, GPIO_Pin_Pull_Mode pull)
{
	// first i clear what's in there.
	GPIOx->PUPDR &= ~(0x3 << pin * 2);

	// then i set the new cfg
	GPIOx->PUPDR |= (pull << pin * 2);
}

/*
 *	@brief	Sets the GPIO port pull mode.
 *	@param	GPIOx: GPIO base address type casted to the struct
 *	@param	Pin: pin number
 *	@param	Type: 0x0 no pull-up or pull down, 0x1 pull-up, 0x2 pull-down, 0x3 reserved
 * */
void hal_gpio_set_alt_func(GPIO_TypeDef *GPIOx, uint16_t pin, uint16_t alternateFunction)
{
	uint8_t index = 0;
	if(pin > 7)
	{
		index = 1;
	}

	GPIOx->AFR[index] &= ~(0x1111b << pin * 4);

	GPIOx->AFR[index] |= (alternateFunction << (pin % 8) * 4);
}

uint8_t hal_gpio_read_pin(GPIO_TypeDef *GPIOx, uint16_t pin)
{
	if(GPIOx == NULL)
		return 0;

	return ((GPIOx->IDR >> pin) & 0x1);
}

void hal_gpio_write_pin(GPIO_TypeDef *GPIOx, uint16_t pin, uint8_t data)
{
	if(GPIOx == NULL)
		return;

	if(data > 0)
		GPIOx->ODR |= 1 << pin;
	else
		GPIOx->ODR &= ~(1 << pin);
}

void hal_gpio_init(GPIO_TypeDef *GPIOx, GPIO_PIN_CONF_T gpio_conf)
{
	HAL_RCC_GPIOD_CLK_ENABLE();
	hal_gpio_set_alt_func(GPIOx, gpio_conf.pin, gpio_conf.alternateFunction);
	hal_gpio_set_output_speed(GPIOx, gpio_conf.pin, gpio_conf.speed);
	hal_gpio_set_output_type(GPIOx, gpio_conf.pin, gpio_conf.outputType);
	hal_gpio_set_pin_mode(GPIOx, gpio_conf.pin, gpio_conf.mode);
	hal_gpio_set_pull(GPIOx, gpio_conf.pin, gpio_conf.pull);
}
