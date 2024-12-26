#include "stm32f10x.h"  
#include "bsq_led.h"
#include "systick.h"
int main(void)
{
	LEDG_GPI0_Config();
	SysTick_Init();
	while(1)
	{
		LED_G(OFF);
		Delay_us(50000);   
		LED_G(ON);
		Delay_us(50000);   
	}
	
}


