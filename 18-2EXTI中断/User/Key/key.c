#include "key.h"
#include "stm32f10x_gpio.h"

void KEY1_GPI0_Config(void)
{
	GPIO_InitTypeDef GPI0_InitStrucr;//初始化结构体
	
	/*开启按键端口的时钟*/ 
    RCC_APB2PeriphClockCmd( KEY1_Clk, ENABLE);
	
	// 设置按键的引脚为浮空输入 
	GPI0_InitStrucr.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	
	//选择按键的引脚 
	GPI0_InitStrucr.GPIO_Pin = GPIO_Pin_0;

	//使用结构体初始化按键 
    GPIO_Init(KEY1GPIO_PORT,&GPI0_InitStrucr);
}




void KEY2_GPI0_Config(void)
{
	GPIO_InitTypeDef GPI0_InitStrucr;//初始化结构体
	
    RCC_APB2PeriphClockCmd( KEY2_Clk, ENABLE);
	
	GPI0_InitStrucr.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPI0_InitStrucr.GPIO_Pin  = GPIO_Pin_13;

    GPIO_Init(KEY2GPIO_PORT,&GPI0_InitStrucr);
}



 /*
  * @brief   检测是否有按键按下 
  * @param  GPIOx:具体的端口, x可以是（A...G） 
  * @param  GPIO_PIN:具体的端口位， 可以是GPIO_PIN_x（x可以是0...15） 
  * @retval  按键的状态 
  * @arg KEY_ON:按键按下 
  * @arg KEY_OFF:按键没按下 
  */ 
uint16_t KEY_Scan(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin)== KEY_ON)
	{
		/*等待按键释放 */ 
		while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin)== KEY_ON);
		return KEY_ON;	
	}
	else
	return KEY_OFF;
}




