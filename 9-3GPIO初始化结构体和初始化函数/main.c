#include "stm32f10x.h"                  // Device header
#include "stm32f103-GPIO.h"

int main(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; 
	
	//APB2����ʱ��ʹ�ܼĴ���(RCC_APB2ENR) 
	RCC->APB2ENR |=(1<<3);
	
	GPIO_SetBit(GPIOB,GPIO_Pin_0);
	ResetBits(GPIOB,GPIO_Pin_0);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;//��ɫ
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;//��ɫ
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;//��ɫ
	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed50_MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT_PP;

	GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ������
	
}

void SystemInit(void)
{
	
}
