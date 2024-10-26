#include "stm32f10x.h"                  // Device header

void delay_us(int delay_us);//΢�뼶����ʱ
void delay_ms(int delay_ms);//���뼶����ʱ
void init();

int main(void)
{
	//APB2����ʱ��ʹ�ܼĴ���(RCC_APB2ENR) 
	*(unsigned int*)0x40021018 |=((1)<<3);
	
	while(1)//������LED
	{
		
	//�˿����õͼĴ���(GPIOB_CRL)
	*(unsigned int*)0x40010C00 |=((1)<<(4*0));//��ɫ
	//�˿�������ݼĴ���(GPIOB_ODR)
	*(unsigned int*)0x40010C0C &=~(1<<(0));//��ɫ
	delay_ms(50);
	init();
		
	*(unsigned int*)0x40010C00 |=((1)<<(4*1));//��ɫ
	*(unsigned int*)0x40010C0C &=~(1<<(1));//��ɫ
		
	delay_ms(50);
	init();
		
	*(unsigned int*)0x40010C00 |=((1)<<(4*5));//��ɫ
	*(unsigned int*)0x40010C0C &=~(1<<(5));//��ɫ
		
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


void delay_ms(int delay_ms)//���뼶����ʱ
{
    volatile unsigned int num;
    for (num = 0; num < delay_ms; num++)
    {
        delay_us(1000);
    }
}


void delay_us(int delay_us)//΢�뼶����ʱ
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
