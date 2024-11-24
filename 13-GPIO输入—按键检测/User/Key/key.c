#include "key.h"
#include "stm32f10x_gpio.h"

void KEY1_GPI0_Config(void)
{
	GPIO_InitTypeDef GPI0_InitStrucr;//��ʼ���ṹ��
	
	/*���������˿ڵ�ʱ��*/ 
    RCC_APB2PeriphClockCmd( KEY1_Clk, ENABLE);
	
	// ���ð���������Ϊ�������� 
	GPI0_InitStrucr.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	
	//ѡ�񰴼������� 
	GPI0_InitStrucr.GPIO_Pin = GPIO_Pin_0;

	//ʹ�ýṹ���ʼ������ 
    GPIO_Init(KEY1GPIO_PORT,&GPI0_InitStrucr);
}




void KEY2_GPI0_Config(void)
{
	GPIO_InitTypeDef GPI0_InitStrucr;//��ʼ���ṹ��
	
    RCC_APB2PeriphClockCmd( KEY2_Clk, ENABLE);
	
	GPI0_InitStrucr.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPI0_InitStrucr.GPIO_Pin  = GPIO_Pin_13;

    GPIO_Init(KEY2GPIO_PORT,&GPI0_InitStrucr);
}



 /*
  * @brief   ����Ƿ��а������� 
  * @param  GPIOx:����Ķ˿�, x�����ǣ�A...G�� 
  * @param  GPIO_PIN:����Ķ˿�λ�� ������GPIO_PIN_x��x������0...15�� 
  * @retval  ������״̬ 
  * @arg KEY_ON:�������� 
  * @arg KEY_OFF:����û���� 
  */ 
uint16_t KEY_Scan(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin)== KEY_ON)
	{
		/*�ȴ������ͷ� */ 
		while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin)== KEY_ON);
		return KEY_ON;	
	}
	else
	return KEY_OFF;
}




