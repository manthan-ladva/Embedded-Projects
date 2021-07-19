#include "stm32f4xx.h"

GPIO_InitTypeDef GPIO_Led;

void delay(unsigned int time);
void init_gpio(void);

int main(void)
{
	init_gpio();

	while (1)
	{
		GPIO_WriteBit(GPIOD, GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14, Bit_SET);
		delay(100);
		GPIO_WriteBit(GPIOD, GPIO_Pin_12|GPIO_Pin_13, Bit_RESET);
		delay(100);
	}
}



void delay(unsigned int time)
{
	unsigned int i;
	for(i=0; i<time*4000; i++);
}


void init_gpio(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	GPIO_Led.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14;
	GPIO_Led.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Led.GPIO_OType = GPIO_OType_PP;
	GPIO_Led.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(GPIOD, &GPIO_Led);
}

