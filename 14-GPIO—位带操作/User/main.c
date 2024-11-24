#include "stm32f10x.h"  
#include "bsq_led.h"
#include "KEY.h"

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
	KEY1_GPI0_Config();
	KEY2_GPI0_Config();
	
	LEDG_GPI0_Config();
	LEDR_GPI0_Config();

	
#if 0	
	while(1)
	{
		if(PAin(0)==KEY_ON)
		{

			while(PAin(0)==KEY_ON);
			LEDG_TOGGLE;
		}
		if(PCin(13)==KEY_ON)
		{

			while(PCin(13)==KEY_ON);
			LEDR_TOGGLE;
		}
			
	}
	
#else	
	while(1)
	{


		Pout(0) =1;
		Delay(0xFFFFFF);

		Pout(0) =0;
		Delay(0xFFFFFF);
	}
#endif	
}


