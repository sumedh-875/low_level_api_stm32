#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_gpio.h"
#include "stm32f4xx.h"

void TIM2_IRQHandler(void);
int main()
{
	LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOD);
	LL_GPIO_SetPinMode(GPIOD, LL_GPIO_PIN_12, LL_GPIO_MODE_OUTPUT);

	LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM2);
	//Set Prescaler 16Mhz input frequency
	LL_TIM_SetPrescaler(TIM2, 1600-1);
	//Set Auto Reload Register value
	LL_TIM_SetAutoReload(TIM2, 10000-1);
	//Enable the timer
	LL_TIM_EnableCounter(TIM2);

	LL_TIM_ClearCounter(TIM2);

	NVIC_EnableIRQ(TIM_IRQ);

	LL_PPP_EnableIT_BITNAME(+)

	while(1)
	{

	}
}
