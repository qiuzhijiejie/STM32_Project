#ifndef __stm32f10x_GPIO_H 
#define __stm32f10x_GPIO_H

#include "stm32f10x.h"

#define GPIO_Pin_0              ((uint16_t)0x0001)  /*!< 选择Pin0 (1<<0) */ 
#define GPIO_Pin_1              ((uint16_t)0x0002)  /*!< 选择Pin1 (1<<1)*/ 
#define GPIO_Pin_2              ((uint16_t)0x0004)  /*!< 选择Pin2 (1<<2)*/ 
#define GPIO_Pin_3              ((uint16_t)0x0008)  /*!< 选择Pin3 (1<<3)*/ 
#define GPIO_Pin_4              ((uint16_t)0x0010)  /*!< 选择Pin4 */ 
#define GPIO_Pin_5              ((uint16_t)0x0020)  /*!< 选择Pin5 */ 
#define GPIO_Pin_6              ((uint16_t)0x0040)  /*!< 选择Pin6 */ 
#define GPIO_Pin_7              ((uint16_t)0x0080)  /*!< 选择Pin7 */ 
#define GPIO_Pin_8              ((uint16_t)0x0100)  /*!< 选择Pin8 */ 
#define GPIO_Pin_9              ((uint16_t)0x0200)  /*!< 选择Pin9 */ 
#define GPIO_Pin_10             ((uint16_t)0x0400)  /*!< 选择Pin10 */ 
#define GPIO_Pin_11             ((uint16_t)0x0800)  /*!< 选择Pin11 */ 
#define GPIO_Pin_12             ((uint16_t)0x1000)  /*!< 选择Pin12 */ 
#define GPIO_Pin_13             ((uint16_t)0x2000)  /*!< 选择Pin13 */ 
#define GPIO_Pin_14             ((uint16_t)0x4000)  /*!< 选择Pin14 */ 
#define GPIO_Pin_15             ((uint16_t)0x8000)  /*!< 选择Pin15 */ 




/** 
  * GPIO输出速率枚举定义 
  */ 
typedef enum
{
	GPIO_Speed10_MHz = 1,// 10MHZ        (01)b 
	GPIO_Speed2_MHz,	 // 2MHZ         (10)b 
	GPIO_Speed50_MHz	 // 50MHZ        (11)b 

}GPIOSpeed_TypeDef;


 
/** 
  * GPIO工作模式枚举定义 
 */ 
typedef enum
{
   GPIO_Mode_AIN = 0X0,          //模拟输入 0000 0000
   GPIO_Mode_IN_FLOATING = 0X04, //浮空输入 0000 0100
   GPIO_Mode_IPD = 0X28, 		 //上拉输入 0010 1000	
   GPIO_Mode_IPU = 0X48,		 //下拉输入 0100 1000
	
   GPIO_Mode_OUT_OD = 0X14,	 //开漏输出 0001 0100	
   GPIO_Mode_OUT_PP = 0X10,	 //推挽输出 0001 0000
   GPIO_Mode_AF_OD  = 0X1C,	 //复用开漏输出 0001 1100
   GPIO_Mode_AP_PP  = 0X18,	 //复用推挽输出 0001 1000	

}GPIOMode_TypeDef;

/*
 * GPIO初始化结构体类型定义 
 */ 
typedef struct
{
 uint16_t GPIO_Pin;//选择要配置的GPIO引脚可输入 GPIO_Pin_ 定义的宏 
	
 GPIOSpeed_TypeDef GPIO_Speed ;//选择GPIO引脚的速率 
	
 GPIOMode_TypeDef GPIO_Mode ;//选择GPIO引脚的工作模式 
	
}GPIO_InitTypeDef;



void ResetBits(GPIO_TypeDef *GPIOx,  uint16_t GPIO_pin);
void GPIO_SetBit(GPIO_TypeDef *GPIOx, uint16_t GPIO_pin);
void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct);

#endif
