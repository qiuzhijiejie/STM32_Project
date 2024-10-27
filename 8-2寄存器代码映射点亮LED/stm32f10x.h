//艰辛繁华,为我自知！
#define PERIPH_BASE  ((unsigned int)0x40000000)

#define APB1_BASE     (PERIPH_BASE)
#define APB2_BASE     (PERIPH_BASE+0X10000) 
#define AHB_BASE      (PERIPH_BASE+0X20000) 

#define  GPIOPortB_BASE     (APB2_BASE+0X0C00)

#define  RCC    (AHB_BASE+0x1000)

#define  RCC_APB2ENR      *(unsigned int*)(RCC+0x18)

#define  GPIOB_CRL        *(unsigned int*)(GPIOPortB_BASE+0X00)
#define  GPIOB_CRH        *(unsigned int*)(GPIOPortB_BASE+0X04)
#define  GPIOB_IDR        *(unsigned int*)(GPIOPortB_BASE+0X08)
#define  GPIOB_ODR        *(unsigned int*)(GPIOPortB_BASE+0X0c)
#define  GPIOB_BSRR       *(unsigned int*)(GPIOPortB_BASE+0X10)
#define  GPIOB_BRR        *(unsigned int*)(GPIOPortB_BASE+0X14)	