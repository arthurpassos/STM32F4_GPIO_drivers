################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f407xx_gpio_driver.c 

OBJS += \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f407xx_gpio_driver.o 

C_DEPS += \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f407xx_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32F4xx_HAL_Driver/Src/%.o: ../Drivers/STM32F4xx_HAL_Driver/Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DSTM32F407xx -I"C:/Users/arthu/workspace/GPIO_Project/Inc" -I"C:/Users/arthu/workspace/GPIO_Project/Drivers/STM32F4xx_HAL_Driver/Inc" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"C:/Users/arthu/workspace/GPIO_Project/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/arthu/workspace/GPIO_Project/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


