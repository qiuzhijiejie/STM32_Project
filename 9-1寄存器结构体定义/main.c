#include "stm32f10x.h"                  // Device header
/*
作业：
1.实现GPIO其他寄存器映射
2.采用操作BSRR、BRR来编程，点亮LED 
*/

void delay_ms(int delay_ms);
void delay_us(int delay_us);
void init();


int main(void)
{
	//APB2外设时钟使能寄存器(RCC_APB2ENR) 
	RCC->APB2ENR |=(1<<3);
	
	
	//端口配置低寄存器(GPIOB->CRL)
//	GPIOB->CRL &=~(0x0f<<(4*0));//置0	
//	GPIOB->CRL |=(1<<(4*0));//绿色


	
	//端口输出数据寄存器(GPIOB->ODR)		
//	GPIOB->ODR &=~(1<<0);//绿色
//	GPIOB->ODR |= (0<<0); //两种方法
	
//	delay_ms(50);
//	init();
	

	
	

		
	while(1)
	{
		GPIOB->CRL |=(1<<(4*0));//绿色
//		GPIOB->ODR |= (1<<0); 
		
		GPIOB->BSRR =(0<<0);
//		GPIOB->BSRR =(1<<16);
		delay_ms(50);
		init();
		
		GPIOB->CRL |=(1<<(4*1));//蓝色
//		GPIOB->ODR &=~(1<<(1));//蓝色
		
		GPIOB->BSRR =(0<<1);
//		GPIOB->BSRR|=(1<<17);
		
		delay_ms(50);
		init();
		
		GPIOB->CRL|=(1<<(4*5));//红色
//		GPIOB->ODR &=~(1<<(5));//红色。ODR 是可读写寄存器
		
		GPIOB->BSRR =(0<<5);//低电平点亮
		GPIOB->BSRR =(0<<21);//BSRR 只需直接写入
		
		delay_ms(50);
		init();
		
	}

}


void SystemInit(void)
{
	
}

void init()
{
    *(unsigned int*)0x40010C00 = 0x44444444;
    GPIOB->ODR = 0x00000000;
}


void delay_ms(int delay_ms)//毫秒级的延时
{
    volatile unsigned int num;
    for (num = 0; num < delay_ms; num++)
    {
        delay_us(1000);
    }
}


void delay_us(int delay_us)//微秒级的延时
{
    volatile unsigned int num;
    volatile unsigned int t;

    for (num = 0; num < delay_us; num++)
    {
        t = 11;
        while (t != 0)
        {
            t--;
        }
    }
}
