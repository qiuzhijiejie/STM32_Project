#ifndef __rcc_H__
#define __rcc_H__

#include "stm32f10x.h"

void HSE_SySteClk(uint32_t RCC_PLLMul_x);

void HSI_SySteClk(uint32_t RCC_PLLMul_x);
#endif
