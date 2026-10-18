#include <stdint.h>
#include "gpio_driver.h"
#include "stm32f407xx.h"

extern void button_led(void);



void button_led(void) {

	GPIO_Handle_t GpioBtn, GpioLed;

	GpioBtn.pGPIOx = GPIOA;
	GpioBtn.GPIO_PinConfig.PinNumber = GPIO_PIN_0;
	GpioBtn.GPIO_PinConfig.PinMode = GPIO_MODE_INPUT;
	GpioBtn.GPIO_PinConfig.PinPuPdControl = GPIO_PUPD_NONE;

	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&GpioBtn);

	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.PinNumber = GPIO_PIN_12;
	GpioLed.GPIO_PinConfig.PinMode = GPIO_MODE_OUTPUT;
	GpioLed.GPIO_PinConfig.PinOPType = GPIO_OTYPE_PP;
	GpioLed.GPIO_PinConfig.PinSpeed = GPIO_OSPEED_L;
	GpioLed.GPIO_PinConfig.PinPuPdControl = GPIO_PUPD_NONE;

	GPIO_PeriClockControl(GPIOD, ENABLE);
		GPIO_Init(&GpioLed);

	while(1) {
		if(GPIO_ReadInputPin(GPIOA, GPIO_PIN_0) == SET) {
			GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_12);

		}
	}
}
