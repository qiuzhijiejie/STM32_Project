#include "rcc.h"

void HSE_SySteClk(uint32_t RCC_PLLMul_x)
{
	__IO uint32_t StartUpCounter = 0, HSEStartUpStatus = 0;
	
	RCC_DeInit();//把RCC寄存器复位成复位值
	
	RCC_HSEConfig(RCC_HSE_ON);//使能HSE
	
	HSEStartUpStatus = RCC_WaitForHSEStartUp();
	
	if(HSEStartUpStatus==SUCCESS)
	{
		 //使能预取值
		 FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
		 FLASH_SetLatency(FLASH_Latency_2);
		
		
		
		 RCC_HCLKConfig( RCC_SYSCLK_Div1);
		 RCC_PCLK1Config(RCC_HCLK_Div2);
		 RCC_PCLK2Config(RCC_HCLK_Div1);
		
		 RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_x);
		 RCC_PLLCmd(ENABLE);
		
		 while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY)==0){}
			 
	     RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		
		 while(RCC_GetSYSCLKSource()!=0x08){}
	}	
	else
	{
		while(1)
		{
			
		}
	}

	
}
void HSI_SySteClk(uint32_t RCC_PLLMul_x)
{
	__IO uint32_t HSIStatus = 0, HSEStartUpStatus = 0;
	
	RCC_DeInit();//把RCC寄存器复位成复位值
	
	RCC_HSICmd(ENABLE);//使能HSI
	
	HSIStatus = RCC->CR & RCC_CR_HSIRDY;
	
	if(HSIStatus==RCC_CR_HSIRDY)
	{
		 //使能预取值
		 FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
		 FLASH_SetLatency(FLASH_Latency_2);
		
		
		
		 RCC_HCLKConfig( RCC_SYSCLK_Div1);
		 RCC_PCLK1Config(RCC_HCLK_Div2);
		 RCC_PCLK2Config(RCC_HCLK_Div1);
		
		 //配置锁相环2分屏
		 RCC_PLLConfig(RCC_PLLSource_HSI_Div2, RCC_PLLMul_x);
		
		//使能PLL
		 RCC_PLLCmd(ENABLE);
		
		//等待PLL稳定
		 while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY)==0);
		
		//选择系统时钟
	     RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		
		 while(RCC_GetSYSCLKSource()!=0x08){}
	}	
	else
	{//如果失败就
		while(1)
		{
			
		}
	}

	
}
