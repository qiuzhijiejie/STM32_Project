#include "stm32f10x.h"                  // Device header
#include "stm32f103-GPIO.h"

#define LED_GPIO_PORT   GPIOB
#define LED_GPIO_CLK    (RCC->APB2ENR  |=  ( (1) << 3 ))
#define LED_GPIO_PIN    GPIO_Pin_1

void Delay(uint32_t xus)
{
	for(;xus!=0;xus--);
}



int main(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; 
	
	//APB2外设时钟使能寄存器(RCC_APB2ENR) 
	LED_GPIO_CLK;
	
	GPIO_InitStructure.GPIO_Pin = LED_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed50_MHz;
	
	GPIO_Init(LED_GPIO_PORT, &GPIO_InitStructure);//初始化函数
	
	while(1)
	{
		GPIO_SetBit(LED_GPIO_PORT,LED_GPIO_PIN);
		Delay(1000000);
		ResetBits(LED_GPIO_PORT,LED_GPIO_PIN);
		Delay(1000000);
	}
	
	
}

void SystemInit(void)
{
	
}
