#include "stm32f10x.h"                  // Device header
#include "stm32f103-GPIO.h"

int main(void)
{
	//APB2����ʱ��ʹ�ܼĴ���(RCC_APB2ENR) 
	RCC->APB2ENR |=(1<<3);
	
	
	//�˿����õͼĴ���(GPIOB->CRL)
	GPIOB->CRL &=~(0x0f<<(4*0));//��0	
	GPIOB->CRL |=(1<<(4*0));//��ɫ


	GPIO_SetBit(GPIOB,GPIO_Pin_0);

	ResetBits(GPIOB,GPIO_Pin_0);

}

void SystemInit(void)
{
	
}
