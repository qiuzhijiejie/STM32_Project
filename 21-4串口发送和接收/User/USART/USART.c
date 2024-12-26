#include "usart.h"



void NVIC_Configuration(void)
{
	NVIC_InitTypeDef  NVIC_InitStructure;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitStructure.NVIC_IRQChannel=DEBUG_USART_IRQ;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
	
	NVIC_Init(&NVIC_InitStructure);
	
}



void USART_Config(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	USART_InitTypeDef USART_InitStruct;
	
    DEBUG_USART_APBxClkCmd(USART_GPIO_CLK, ENABLE);
    USART_APBxClkCmd(USART_Clk, ENABLE);
	
	//USART1_TX
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Pin=USART_TX_GPIO_PIN;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(USART_TX_GPIO_PORT,&GPIO_InitStruct);
	
	//USART1_RX
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Pin=USART_RX_GPIO_PIN;
	GPIO_Init(USART_TX_GPIO_PORT,&GPIO_InitStruct);
	
	USART_InitStruct.USART_BaudRate=USART_BAUDRATE;
	USART_InitStruct.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_InitStruct.USART_Mode=USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStruct.USART_Parity=USART_Parity_No;
	USART_InitStruct.USART_StopBits=USART_StopBits_1;
	USART_InitStruct.USART_WordLength=USART_WordLength_8b;
	
	USART_Init(USART_x,&USART_InitStruct);
	
	
	NVIC_Configuration();
	USART_ITConfig(USART_x,USART_IT_RXNE,ENABLE);
	USART_Cmd(USART_x,ENABLE);

}


//发送一个字节
void Send_Byte(USART_TypeDef *USARTx, char *data)  // 修改为指针类型
{
    uint8_t i = 0;
    do
    {
        USART_SendData(USARTx, *(data + i));  // 发送当前字符
        i++;  // 移动到下一个字符
    } while (*(data + i) != '\0');  // 检查字符串结束符

    while (USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET);  // 等待发送完成
}


//发送两个字节
void Send_HalfwordByte(USART_TypeDef *USARTx, uint16_t data)  // 接收指针类型数据
{
    uint8_t temp_h, temp_l;
    
    // 先解引用指针，获取16位数据，再进行位运算
    temp_h = (data & 0xFF00) >> 8;  // 高8位
    temp_l = (data & 0xFF);       // 低8位

    // 发送高8位
    USART_SendData(USARTx, temp_h);
    while (USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET);  // 等待发送完成

    // 发送低8位
    USART_SendData(USARTx, temp_l);
    while (USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET);  // 等待发送完成
}



// 发送字符串
void Send_String(USART_TypeDef* USARTx, uint8_t *str)
{
    uint8_t i=0; 
    do
    {
		while (USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET); 
        USART_SendData(USARTx, *(str + i)); 
        i++; 
    } while (*(str + i) != '\0'); 
    while (USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET); 
}


// 发送数组
void Send_Arr(USART_TypeDef* USARTx, uint8_t *arr,uint8_t num)
{
	uint8_t i; 
	for(i=0;i<num;i++)
	{
		while (USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET); 
        USART_SendData(USARTx, (arr[i])); 
		
	}
    while (USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET); 
}




int fputc(int ch, FILE *f) 
{
	while (USART_GetFlagStatus(USART_x, USART_FLAG_TC) == RESET);
	USART_SendData(USART_x,(uint8_t) ch);
	while (USART_GetFlagStatus(USART_x, USART_FLAG_TC) == RESET);
	return ch;
}

