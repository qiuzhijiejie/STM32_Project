#include "stm32f10x.h"  
#include "bsq_led.h"
#include "exti.h"

void EXTI0_IRQHandler(void)//4.中断服务函数
{
	//   中断标志位
	if(EXTI_GetITStatus(EXTI_Line0)!=0)
	{
		LEDG_TOGGLE
	}
	EXTI_ClearITPendingBit(EXTI_Line0);
	//    中断清除位
}

void EXTI15_10_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line13)!=0)
	{
		LEDB_TOGGLE
	}
	EXTI_ClearITPendingBit(EXTI_Line13);
	
}

int main(void)
{
	LEDG_GPI0_Config();
	EXTI0_KEY1_Config();
	
	LEDB_GPI0_Config();
	EXTI13_KEY2_Config();
	
	while(1)
	{

	}

}


