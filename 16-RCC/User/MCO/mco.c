#include "mco.h"
#include "stm32f10x_rcc.h"


void MCO_Config(void)
{
	GPIO_InitTypeDef GPI0_InitStrucr;//初始化结构体
	
	/*开启按键端口的时钟*/ 
    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE);
	
	
    //选择按键的引脚 
	GPI0_InitStrucr.GPIO_Pin = GPIO_Pin_8;
	
	// 设置按键的引脚为浮空输入 
	GPI0_InitStrucr.GPIO_Mode = GPIO_Mode_AF_PP;

	
	GPI0_InitStrucr.GPIO_Speed = GPIO_Speed_50MHz; 

	//使用结构体初始化按键 
    GPIO_Init(GPIOA,&GPI0_InitStrucr);
}

