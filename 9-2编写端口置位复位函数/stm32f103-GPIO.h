#ifndef __stm32f10x_GPIO_H 
#define __stm32f10x_GPIO_H

#include "stm32f10x.h"

#define GPIO_Pin_0              ((uint16_t)0x0001)  /*!< ѡ��Pin0 (1<<0) */ 
#define GPIO_Pin_1              ((uint16_t)0x0002)  /*!< ѡ��Pin1 (1<<1)*/ 
#define GPIO_Pin_2              ((uint16_t)0x0004)  /*!< ѡ��Pin2 (1<<2)*/ 
#define GPIO_Pin_3              ((uint16_t)0x0008)  /*!< ѡ��Pin3 (1<<3)*/ 
#define GPIO_Pin_4              ((uint16_t)0x0010)  /*!< ѡ��Pin4 */ 
#define GPIO_Pin_5              ((uint16_t)0x0020)  /*!< ѡ��Pin5 */ 
#define GPIO_Pin_6              ((uint16_t)0x0040)  /*!< ѡ��Pin6 */ 
#define GPIO_Pin_7              ((uint16_t)0x0080)  /*!< ѡ��Pin7 */ 
#define GPIO_Pin_8              ((uint16_t)0x0100)  /*!< ѡ��Pin8 */ 
#define GPIO_Pin_9              ((uint16_t)0x0200)  /*!< ѡ��Pin9 */ 
#define GPIO_Pin_10             ((uint16_t)0x0400)  /*!< ѡ��Pin10 */ 
#define GPIO_Pin_11             ((uint16_t)0x0800)  /*!< ѡ��Pin11 */ 
#define GPIO_Pin_12             ((uint16_t)0x1000)  /*!< ѡ��Pin12 */ 
#define GPIO_Pin_13             ((uint16_t)0x2000)  /*!< ѡ��Pin13 */ 
#define GPIO_Pin_14             ((uint16_t)0x4000)  /*!< ѡ��Pin14 */ 
#define GPIO_Pin_15             ((uint16_t)0x8000)  /*!< ѡ��Pin15 */ 

void ResetBits(GPIO_TypeDef *GPIOx,  uint16_t GPIO_pin);
void GPIO_SetBit(GPIO_TypeDef *GPIOx, uint16_t GPIO_pin);

#endif
