#include <stdint.h>
#include "gpio_driver.h"
#include "stm32f407xx.h"


int main() {
	button_interrupt();

	while(1);
}


