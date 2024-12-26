#include "stm32f10x.h"  
#include "bsq_led.h"
#include "usart.h"

int main(void)
{
	uint8_t ch;
	USART_Config();
	LEDR_GPI0_Config();
	LEDG_GPI0_Config();
	LEDB_GPI0_Config();
	LED_OFF;
	printf("´®¿Ú¿ØÖÆRGBµÆ\n");
	
	while(1)
	{
		ch=getchar();
		printf("ch=%c\n",ch);

		switch(ch)
		{
			case '1':LED_RON;
				break;
			case '2':LED_GON;
				break;
			case '3':LED_BON;
				break;
			default:LED_OFF;
				break;
		}		
	}
		
}


