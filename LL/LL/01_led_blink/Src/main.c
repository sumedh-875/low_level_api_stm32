#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_gpio.h"


int main()
{
	LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOD);
	LL_GPIO_SetPinMode(GPIOD, LL_GPIO_PIN_12, LL_GPIO_MODE_OUTPUT);
	while(1)
	{
		LL_GPIO_TogglePin (GPIOD, LL_GPIO_PIN_12);
		for(int i = 0; i<90000; i++);
	}
}
