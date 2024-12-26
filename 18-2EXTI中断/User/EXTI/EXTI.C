#include "Exti.h"
static void EXTI0_NVIC_Config(void)//3.初始化NVIV,用于初始化
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    NVIC_InitTypeDef NVIC0_InitStruct;

    NVIC0_InitStruct.NVIC_IRQChannel = EXTI_Line0_Interrupt;
    NVIC0_InitStruct.NVIC_IRQChannelPreemptionPriority = 1; 
    NVIC0_InitStruct.NVIC_IRQChannelSubPriority = 1;      
    NVIC0_InitStruct.NVIC_IRQChannelCmd = ENABLE;

    NVIC_Init(&NVIC0_InitStruct);
}


static void EXTI13_NVIC_Config(void)
{
    NVIC_InitTypeDef NVIC13_InitStruct;

    NVIC13_InitStruct.NVIC_IRQChannel = EXTI15_10_IRQn;
    NVIC13_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;  
    NVIC13_InitStruct.NVIC_IRQChannelSubPriority = 1;        
    NVIC13_InitStruct.NVIC_IRQChannelCmd = ENABLE;

    NVIC_Init(&NVIC13_InitStruct);
}


void EXTI0_KEY1_Config(void)//2.初始化EXTI用于产生中断/事件
{
    GPIO_InitTypeDef GPIO_InitStruct;
    EXTI_InitTypeDef EXTI_InitStruct;

    // 配置中断优先级
    EXTI0_NVIC_Config();

    // 开启按键端口的时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//初始化要连接的EXTI的GPIO

    // 设置按键的引脚为浮空输入
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0; // PA0
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    // 初始化 EXTI
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE); // 开启 AFIO 时钟
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0); // 连接 PA0 到 EXTI0

    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStruct.EXTI_Line = External_interrupt_line_0;
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling; // 下降沿触发
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStruct);
}



void EXTI13_KEY2_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    EXTI_InitTypeDef EXTI_InitStruct;

    // 配置中断优先级
    EXTI13_NVIC_Config();

    // 开启按键端口的时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    // 设置按键的引脚为浮空输入
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13; // PC13
    GPIO_Init(GPIOC, &GPIO_InitStruct);

    // 初始化 EXTI
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE); // 开启 AFIO 时钟
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource13); // 连接 PC13 到 EXTI13

    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStruct.EXTI_Line = External_interrupt_line_13;
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling; // 下降沿触发
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStruct);
}
