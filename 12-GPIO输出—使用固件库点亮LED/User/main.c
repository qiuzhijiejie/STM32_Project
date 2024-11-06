#include "stm32f10x.h"  
#include "bsq_led.h"

void Delay(unsigned int xus)
{
	for(;xus!=0;xus--);
}


int main(void)
{
	LEDG_GPI0_Config();
	LEDB_GPI0_Config();
	LEDR_GPI0_Config();
	while(1)
	{
		
		//GPIO_SetBits(GPIOA,GPIO_Pin_0);
		LED_G(OFF);
		LED_B(OFF);
		LED_R(OFF);
//		Delay(0xFFFFF);
		//GPIO_ResetBits(GPIOA,GPIO_Pin_0);
		LED_G(ON);
//		LED_B(ON);
		LED_R(ON);
		Delay(0xFFFFF);
	}
		
	
	
	
}


