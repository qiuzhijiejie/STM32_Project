#ifndef __systick_H__
#define __systick_H__

#include "stm32f10x.h"
#include "core_cm3.h"

void Systen_Delay_us(uint32_t us);
void Systen_Delay_ms(uint32_t ms);
void TimingDelay_Decrement(void);
void SysTick_Init(void);
void Delay_us(__IO u32 nTime);


#endif
