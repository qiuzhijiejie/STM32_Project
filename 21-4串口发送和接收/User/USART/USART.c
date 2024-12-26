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


//����һ���ֽ�
void Send_Byte(USART_TypeDef *USARTx, char *data)  // �޸�Ϊָ������
{
    uint8_t i = 0;
    do
    {
        USART_SendData(USARTx, *(data + i));  // ���͵�ǰ�ַ�
        i++;  // �ƶ�����һ���ַ�
    } while (*(data + i) != '\0');  // ����ַ���������

    while (USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET);  // �ȴ��������
}


//���������ֽ�
void Send_HalfwordByte(USART_TypeDef *USARTx, uint16_t data)  // ����ָ����������
{
    uint8_t temp_h, temp_l;
    
    // �Ƚ�����ָ�룬��ȡ16λ���ݣ��ٽ���λ����
    temp_h = (data & 0xFF00) >> 8;  // ��8λ
    temp_l = (data & 0xFF);       // ��8λ

    // ���͸�8λ
    USART_SendData(USARTx, temp_h);
    while (USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET);  // �ȴ��������

    // ���͵�8λ
    USART_SendData(USARTx, temp_l);
    while (USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET);  // �ȴ��������
}



// �����ַ���
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


// ��������
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

