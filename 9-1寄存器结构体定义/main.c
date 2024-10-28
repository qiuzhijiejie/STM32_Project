#include "stm32f10x.h"                  // Device header
/*
��ҵ��
1.ʵ��GPIO�����Ĵ���ӳ��
2.���ò���BSRR��BRR����̣�����LED 
*/

void delay_ms(int delay_ms);
void delay_us(int delay_us);
void init();


int main(void)
{
	//APB2����ʱ��ʹ�ܼĴ���(RCC_APB2ENR) 
	RCC->APB2ENR |=(1<<3);
	
	
	//�˿����õͼĴ���(GPIOB->CRL)
//	GPIOB->CRL &=~(0x0f<<(4*0));//��0	
//	GPIOB->CRL |=(1<<(4*0));//��ɫ


	
	//�˿�������ݼĴ���(GPIOB->ODR)		
//	GPIOB->ODR &=~(1<<0);//��ɫ
//	GPIOB->ODR |= (0<<0); //���ַ���
	
//	delay_ms(50);
//	init();
	

	
	

		
	while(1)
	{
		GPIOB->CRL |=(1<<(4*0));//��ɫ
//		GPIOB->ODR |= (1<<0); 
		
		GPIOB->BSRR =(0<<0);
//		GPIOB->BSRR =(1<<16);
		delay_ms(50);
		init();
		
		GPIOB->CRL |=(1<<(4*1));//��ɫ
//		GPIOB->ODR &=~(1<<(1));//��ɫ
		
		GPIOB->BSRR =(0<<1);
//		GPIOB->BSRR|=(1<<17);
		
		delay_ms(50);
		init();
		
		GPIOB->CRL|=(1<<(4*5));//��ɫ
//		GPIOB->ODR &=~(1<<(5));//��ɫ��ODR �ǿɶ�д�Ĵ���
		
		GPIOB->BSRR =(0<<5);//�͵�ƽ����
		GPIOB->BSRR =(0<<21);//BSRR ֻ��ֱ��д��
		
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
