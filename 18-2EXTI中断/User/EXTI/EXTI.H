#ifndef __Exti_H__
#define __Exti_H__

#include "stm32f10x.h"   

#define EXTI0_Clk		  RCC_APB2Periph_GPIOA
#define EXTI0_PORT    	  GPIOA
#define EXTI0_GPIO_Pin    GPIO_Pin_0
#define EXTI_Line0_Interrupt  EXTI0_IRQn
#define External_interrupt_line_0 EXTI_Line0


#define EXTI13_Clk		  RCC_APB2Periph_GPIOC
#define EXTI13_PORT    	  GPIOC
#define EXTI13_GPIO_Pin   GPIO_Pin_13
#define EXTI_Line15_10_Interrupt  EXTI15_10_IRQn
#define External_interrupt_line_13 EXTI_Line13


void EXTI0_KEY1_Config(void);
void EXTI13_KEY2_Config(void);

#endif
