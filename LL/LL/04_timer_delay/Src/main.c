//Generate 1 Sec delay using timer

#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_gpio.h"
#include "stm32f4xx_ll_tim.h"

void Timer2_1s_Delay(void);

int main()
{
	//Enable clock for GPIO Port D
	LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOD);
	//Set pin PD12 as output pin
	LL_GPIO_SetPinMode(GPIOD, LL_GPIO_PIN_12, LL_GPIO_MODE_OUTPUT);

	Timer2_1s_Delay();
	while(1)
	{
		while(!(LL_TIM_IsActiveFlag_UPDATE (TIM2)));
		LL_TIM_ClearFlag_UPDATE(TIM2);
		LL_GPIO_TogglePin(GPIOD, LL_GPIO_PIN_12);
	}
}

void Timer2_1s_Delay()
{
	//Enable clock for timer2
	LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM2);
	//Set Prescaler 16Mhz input frequency
	LL_TIM_SetPrescaler(TIM2, 1600-1);
	//Set Auto Reload Register value
	LL_TIM_SetAutoReload(TIM2, 10000-1);
	//Enable the timer
	LL_TIM_EnableCounter(TIM2);
}

