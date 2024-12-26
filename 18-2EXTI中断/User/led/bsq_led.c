#include "bsq_led.h"


void LEDG_GPI0_Config(void)
{
	GPIO_InitTypeDef GPI0_InitStrucr;//初始化结构体
	
    RCC_APB2PeriphClockCmd( LEDG_Clk, ENABLE);
	
	GPI0_InitStrucr.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPI0_InitStrucr.GPIO_Pin   = LED_G_GPIO_Pin;
	GPI0_InitStrucr.GPIO_Speed = GPIO_Speed_50MHz;
	
    GPIO_Init(LED1_GPIO_PORT,&GPI0_InitStrucr);
}




void LEDB_GPI0_Config(void)
{
	GPIO_InitTypeDef GPI0_InitStrucr;//初始化结构体
	
    RCC_APB2PeriphClockCmd( LEDB_Clk, ENABLE);
	
	GPI0_InitStrucr.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPI0_InitStrucr.GPIO_Pin   = LED_B_GPIO_Pin;
	GPI0_InitStrucr.GPIO_Speed = GPIO_Speed_50MHz;
	
    GPIO_Init(LED1_GPIO_PORT,&GPI0_InitStrucr);
}



void LEDR_GPI0_Config(void)
{
	GPIO_InitTypeDef GPI0_InitStrucr;//初始化结构体
	
    RCC_APB2PeriphClockCmd( LEDR_Clk, ENABLE);
	
	GPI0_InitStrucr.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPI0_InitStrucr.GPIO_Pin   = LED_R_GPIO_Pin;
	GPI0_InitStrucr.GPIO_Speed = GPIO_Speed_50MHz;
	
    GPIO_Init(LED1_GPIO_PORT,&GPI0_InitStrucr);
}


