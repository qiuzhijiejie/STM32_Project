#include "stm32f103-GPIO.h"

//函数功能：设置引脚为高电平
void GPIO_SetBit(GPIO_TypeDef *GPIOx,uint16_t GPIO_pin)
{
	GPIOB->BSRR = GPIO_pin;
}

//函数功能：设置引脚为低电平
void ResetBits(GPIO_TypeDef *GPIOx,uint16_t GPIO_pin)
{
	GPIOB->BRR = GPIO_pin;
}