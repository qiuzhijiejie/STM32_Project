#include "stm32f103-GPIO.h"

//�������ܣ���������Ϊ�ߵ�ƽ
void GPIO_SetBit(GPIO_TypeDef *GPIOx,uint16_t GPIO_pin)
{
	GPIOB->BSRR = GPIO_pin;
}

//�������ܣ���������Ϊ�͵�ƽ
void ResetBits(GPIO_TypeDef *GPIOx,uint16_t GPIO_pin)
{
	GPIOB->BRR = GPIO_pin;
}