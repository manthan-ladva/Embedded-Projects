#include "stm32f4xx.h"

//!--------------------------//Function Declaration
void Init_gpio(void);
void Delay(unsigned int time);
void Pattern1(void);
void Pattern2(void);
void Pattern3(void);


//!--------------------------//Variable Declaration
GPIO_InitTypeDef   All_Led;


//!--------------------------//Functions
int main(void)
{
	Init_gpio();
	while (1)
	{
		Pattern1();
		Pattern2();
		Pattern3();
		GPIO_WriteBit(GPIOD, GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15, Bit_RESET);
		Delay(1000);
	}
}


void Pattern1(void)
{
	unsigned int i;
	for(i=0;i<5;i++)
	{
		GPIO_WriteBit(GPIOD, GPIO_Pin_12|GPIO_Pin_14, Bit_SET);
		Delay(100);
		GPIO_WriteBit(GPIOD, GPIO_Pin_12|GPIO_Pin_14, Bit_RESET);

		GPIO_WriteBit(GPIOD, GPIO_Pin_13|GPIO_Pin_15, Bit_SET);
		Delay(100);
		GPIO_WriteBit(GPIOD, GPIO_Pin_13|GPIO_Pin_15, Bit_RESET);
	}
}


void Pattern2(void)
{
	unsigned int i;
	for(i=0;i<3;i++)
	{
		GPIO_WriteBit(GPIOD, GPIO_Pin_12, Bit_SET);
		Delay(100);
		GPIO_WriteBit(GPIOD, GPIO_Pin_12, Bit_RESET);
		Delay(100);

		GPIO_WriteBit(GPIOD, GPIO_Pin_13, Bit_SET);
		Delay(100);
		GPIO_WriteBit(GPIOD, GPIO_Pin_13, Bit_RESET);
		Delay(100);

		GPIO_WriteBit(GPIOD, GPIO_Pin_14, Bit_SET);
		Delay(100);
		GPIO_WriteBit(GPIOD, GPIO_Pin_14, Bit_RESET);
		Delay(100);

		GPIO_WriteBit(GPIOD, GPIO_Pin_15, Bit_SET);
		Delay(100);
		GPIO_WriteBit(GPIOD, GPIO_Pin_15, Bit_RESET);
		Delay(100);
	}
}


void Pattern3(void)
{
	unsigned int i;
	for(i=0;i<5;i++)
	{
		GPIO_WriteBit(GPIOD, GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15, Bit_SET);
		Delay(100);
		GPIO_WriteBit(GPIOD, GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15, Bit_RESET);
		Delay(100);
	}
}


void Init_gpio(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	All_Led.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;   //Initializing Pins
	All_Led.GPIO_Mode = GPIO_Mode_OUT;		//LED On Off is Output Mode
	All_Led.GPIO_Speed = GPIO_Speed_50MHz;  //Its Like VPBDIV in ARM7-LPC2148
	All_Led.GPIO_OType = GPIO_OType_PP;		//Push-Pull Type

	GPIO_Init(GPIOD, &All_Led);				//GPIO Init
}


void Delay(unsigned int time)
{
	unsigned int i;
	for(i=0; i<time*4000; i++);
}
