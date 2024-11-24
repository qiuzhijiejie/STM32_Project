#include "stm32f10x.h"  
#include "bsq_led.h"
#include "KEY.h"



int main(void)
{
	KEY1_GPI0_Config();
	KEY2_GPI0_Config();
	
	LEDG_GPI0_Config();
	LEDR_GPI0_Config();
//	LEDB_GPI0_Config();
	
	
	while(1)
	{
		if(KEY_Scan( KEY2GPIO_PORT,KEY2_GPIO_Pin)==KEY_ON)
		{
			LEDG_TOGGLE;
		}
		if(KEY_Scan( KEY1GPIO_PORT,KEY1_GPIO_Pin)==KEY_ON)
		{
			LEDR_TOGGLE;

		}
//		else if (KEY_Scan(KEY1GPIO_PORT, KEY1_GPIO_Pin) == KEY_ON || 
//         KEY_Scan(KEY2GPIO_PORT, KEY2_GPIO_Pin) == KEY_ON)

//		{
//			LEDB_TOGGLE;
//		}
			
	}
		
	
}


