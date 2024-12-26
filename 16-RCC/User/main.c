#include "stm32f10x.h"  
#include "bsq_led.h"
#include "KEY.h"
#include "RCC.h"
#include "MCO.h"

#define ODR_addr  (GPIOB_BASE+ 0X0C)
#define Pout(n)  *(unsigned int*)((ODR_addr & 0xF0000000)+0x02000000+((ODR_addr & 0x00FFFFFF)<<5)+(n<<2)) 
	

#define IDRA_addr (GPIOA_BASE+ 0X08)
#define PAin(n)  *(unsigned int*)((IDRA_addr & 0xF0000000)+0x02000000+((IDRA_addr & 0x00FFFFFF)<<5)+(n<<2)) 
	
#define IDRC_addr (GPIOC_BASE+ 0X08)
#define PCin(n)  *(unsigned int*)((IDRC_addr & 0xF0000000)+0x02000000+((IDRC_addr & 0x00FFFFFF)<<5)+(n<<2)) 

void Delay(unsigned int xus)
{
	for(;xus!=0;xus--);
}

int main(void)
{
//	HSE_SySteClk( RCC_PLLMul_9);
	
	HSI_SySteClk(RCC_PLLMul_4);
	MCO_Config();
	RCC_MCOConfig(RCC_MCO_SYSCLK);

//	LEDG_GPI0_Config();
	LEDR_GPI0_Config();

	
	while(1)
	{


		LED_R(ON);
		Delay(0xFFFFF);

		LED_R(OFF);
		Delay(0xFFFFF);
	}

}


