#ifndef __bsq_led_H__
#define __bsq_led_H__


#include "stm32f10x.h"

#define  OFF     0 
#define  ON      1                //带参的宏定义

void LEDG_GPI0_Config(void);
#define LED1_GPIO_PORT    GPIOB
#define LED_G_GPIO_Pin    GPIO_Pin_0
#define LEDG_Clk		  RCC_APB2Periph_GPIOB

#define LED_G(a)    if(a) GPIO_ResetBits(GPIOB,GPIO_Pin_0);\
					else GPIO_SetBits(GPIOB,GPIO_Pin_0)\
//                            \ C语言的续行符


void LEDB_GPI0_Config(void);
#define LED2_GPIO_PORT    GPIOB
#define LED_B_GPIO_Pin    GPIO_Pin_1
#define LEDB_Clk		  RCC_APB2Periph_GPIOB

#define LED_B(a)    if(a) GPIO_ResetBits(GPIOB,GPIO_Pin_1);\
					else GPIO_SetBits(GPIOB,GPIO_Pin_1)\
						
						
						
void LEDR_GPI0_Config(void);						
#define LED3_GPIO_PORT    GPIOB
#define LED_R_GPIO_Pin    GPIO_Pin_5
#define LEDR_Clk		  RCC_APB2Periph_GPIOB

#define LED_R(a)    if(a) GPIO_ResetBits(GPIOB,GPIO_Pin_5);\
					else GPIO_SetBits(GPIOB,GPIO_Pin_5)\
				 				

#define LED_RON     LED_R(ON);\
				    LED_G(OFF);\
				    LED_B(OFF)

#define LED_GON     LED_G(ON);\
				    LED_R(OFF);\
				    LED_B(OFF)
					
#define LED_BON     LED_B(ON);\
				    LED_G(OFF);\
				    LED_R(OFF)
					
					
#define LED_OFF     LED_R(OFF); \
                    LED_G(OFF); \
                    LED_B(OFF)
	
#endif

