#ifndef __USART_H__
#define __USART_H__

#include "stm32f10x.h"
#include <stdio.h>

// 串口USART1 
//#if USART_1
#define  USART_x    		  	  USART1 
#define  USART_Clk		   		  RCC_APB2Periph_USART1
#define  USART_APBxClkCmd  	  	  RCC_APB2PeriphClockCmd 
#define  USART_BAUDRATE     	  115200 
//GPIO 引脚宏定义 
#define  USART_GPIO_CLK           	   (RCC_APB2Periph_GPIOA) 
#define  DEBUG_USART_APBxClkCmd   	   RCC_APB2PeriphClockCmd 
#define  USART_TX_GPIO_PORT       	   GPIOA
#define  USART_TX_GPIO_PIN        	   GPIO_Pin_9 
#define  USART_RX_GPIO_PORT       	   GPIOA 
#define  USART_RX_GPIO_PIN        	   GPIO_Pin_10 
#define  DEBUG_USART_IRQ               USART1_IRQn //设备的中断向量
#define  DEBUG_USART_IRQHandler        USART1_IRQHandler 




//// 串口USART2
//#elif USART_2
//#define  USART_x    		  	  USART2 
//#define  USART_Clk		   		  RCC_APB1Periph_USART1
//#define  USART_APBxClkCmd  	  	  RCC_APB1PeriphClockCmd 
//#define  USART_BAUDRATE     	  115200 
////GPIO 引脚宏定义 
//#define  USART_GPIO_CLK           	   (RCC_APB2Periph_GPIOA) 
//#define  DEBUG_USART_GPIO_APBxClkCmd   RCC_APB2PeriphClockCmd 
//#define  USART_TX_GPIO_PORT       	   GPIOA
//#define  USART_TX_GPIO_PIN        	   GPIO_Pin_2
//#define  USART_RX_GPIO_PORT       	   GPIOA 
//#define  USART_RX_GPIO_PIN        	   GPIO_Pin_3 
//#define  DEBUG_USART_IRQ               USART2_IRQn //设备的中断向量
//#define  DEBUG_USART_IRQHandler        USART2_IRQHandler 




//// 串口USART3
//#elif USART_3
//#define  USART_x    		  	  USART3
//#define  USART_Clk		   		  RCC_APB1Periph_USART3
//#define  USART_APBxClkCmd  	  	  RCC_APB1PeriphClockCmd 
//#define  USART_BAUDRATE     	  115200 
////GPIO 引脚宏定义 
//#define  USART_GPIO_CLK           	   (RCC_APB2Periph_GPIOA) 
//#define  DEBUG_USART_GPIO_APBxClkCmd   RCC_APB2PeriphClockCmd 
//#define  USART_TX_GPIO_PORT       	   GPIOB
//#define  USART_TX_GPIO_PIN        	   GPIO_Pin_10
//#define  USART_RX_GPIO_PORT       	   GPIOB
//#define  USART_RX_GPIO_PIN        	   GPIO_Pin_11
//#define  DEBUG_USART_IRQ               USART3_IRQn //设备的中断向量
//#define  DEBUG_USART_IRQHandler        USART3_IRQHandler 



//// 串口USART4
//#elif USART_4
//#define  USART_x    		  	  USART4
//#define  USART_Clk		   		  RCC_APB1Periph_USART4
//#define  USART_APBxClkCmd  	  	  RCC_APB1PeriphClockCmd 
//#define  USART_BAUDRATE     	  115200 
////GPIO 引脚宏定义 
//#define  USART_GPIO_CLK           	   (RCC_APB2Periph_GPIOC) 
//#define  DEBUG_USART_GPIO_APBxClkCmd   RCC_APB2PeriphClockCmd 
//#define  USART_TX_GPIO_PORT       	   GPIOC
//#define  USART_TX_GPIO_PIN        	   GPIO_Pin_10
//#define  USART_RX_GPIO_PORT       	   GPIOC
//#define  USART_RX_GPIO_PIN        	   GPIO_Pin_11
//#define  DEBUG_USART_IRQ               USART4_IRQn //设备的中断向量
//#define  DEBUG_USART_IRQHandler        USART4_IRQHandler 




//// 串口USART5
//#elif USART_5
//#define  USART_x    		  	  USART5
//#define  USART_Clk		   		  RCC_APB1Periph_USART5
//#define  USART_APBxClkCmd  	  	  RCC_APB1PeriphClockCmd 
//#define  USART_BAUDRATE     	  115200 
////GPIO 引脚宏定义 
//#define  USART_GPIO_CLK           	   (RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD) 
//#define  DEBUG_USART_GPIO_APBxClkCmd   RCC_APB2PeriphClockCmd 
//#define  USART_TX_GPIO_PORT       	   GPIOC
//#define  USART_TX_GPIO_PIN        	   GPIO_Pin_12
//#define  USART_RX_GPIO_PORT       	   GPIOD
//#define  USART_RX_GPIO_PIN        	   GPIO_Pin_2
//#define  DEBUG_USART_IRQ               USART5_IRQn //设备的中断向量
//#define  DEBUG_USART_IRQHandler        USART5_IRQHandler 

//#endif



void NVIC_Configuration(void);
void USART_Config(void);
void Send_Byte(USART_TypeDef *USARTx, char *data)  ;
void Send_HalfwordByte(USART_TypeDef *USARTx, uint16_t data)  ;
void Send_String(USART_TypeDef *USARTx, uint8_t *str);
void Send_Arr(USART_TypeDef* USARTx, uint8_t *arr,uint8_t num);




#endif

