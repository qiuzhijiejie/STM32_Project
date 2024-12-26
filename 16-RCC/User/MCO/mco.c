#include "mco.h"
#include "stm32f10x_rcc.h"


void MCO_Config(void)
{
	GPIO_InitTypeDef GPI0_InitStrucr;//��ʼ���ṹ��
	
	/*���������˿ڵ�ʱ��*/ 
    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE);
	
	
    //ѡ�񰴼������� 
	GPI0_InitStrucr.GPIO_Pin = GPIO_Pin_8;
	
	// ���ð���������Ϊ�������� 
	GPI0_InitStrucr.GPIO_Mode = GPIO_Mode_AF_PP;

	
	GPI0_InitStrucr.GPIO_Speed = GPIO_Speed_50MHz; 

	//ʹ�ýṹ���ʼ������ 
    GPIO_Init(GPIOA,&GPI0_InitStrucr);
}

