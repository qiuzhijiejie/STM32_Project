#ifndef __key_H__
#define __key_H__

#include "stm32f10x.h"

/* 按键按下标置宏 
 * 按键按下为高电平，设置 KEY_ON=1， KEY_OFF=0 
 */ 

#define KEY_ON  1
#define KEY_OFF 0

#define KEY1_Clk		  RCC_APB2Periph_GPIOA
#define KEY1GPIO_PORT     GPIOA
#define KEY1_GPIO_Pin     GPIO_Pin_0
void KEY1_GPI0_Config(void);


#define KEY2_Clk		  RCC_APB2Periph_GPIOC
#define KEY2GPIO_PORT     GPIOC
#define KEY2_GPIO_Pin     GPIO_Pin_13
void KEY2_GPI0_Config(void);

uint16_t KEY_Scan(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);







#endif
