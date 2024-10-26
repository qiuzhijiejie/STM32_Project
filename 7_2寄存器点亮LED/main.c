#include "stm32f10x.h"                  // Device header

void delay_us(int delay_us);//微秒级的延时
void delay_ms(int delay_ms);//毫秒级的延时
void init();

int main(void)
{
	//APB2外设时钟使能寄存器(RCC_APB2ENR) 
	*(unsigned int*)0x40021018 |=((1)<<3);
	
	while(1)//交替亮LED
	{
		
	//端口配置低寄存器(GPIOB_CRL)
	*(unsigned int*)0x40010C00 |=((1)<<(4*0));//绿色
	//端口输出数据寄存器(GPIOB_ODR)
	*(unsigned int*)0x40010C0C &=~(1<<(0));//绿色
	delay_ms(50);
	init();
		
	*(unsigned int*)0x40010C00 |=((1)<<(4*1));//蓝色
	*(unsigned int*)0x40010C0C &=~(1<<(1));//蓝色
		
	delay_ms(50);
	init();
		
	*(unsigned int*)0x40010C00 |=((1)<<(4*5));//红色
	*(unsigned int*)0x40010C0C &=~(1<<(5));//红色
		
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
    *(unsigned int*)0x40010C0C = 0x00000000;
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
