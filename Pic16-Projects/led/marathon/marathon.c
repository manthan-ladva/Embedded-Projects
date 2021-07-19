#include<pic.h>

void delay(unsigned int time);
void marathon(void);

void main(void)
{
	while(1) marathon();	
}

void marathon(void)
{
	TRISB = 0x00;
	unsigned int i,value = 0x01;
	for(i=0;i<8;i++)
	{
		PORTB = value<<i;
		delay(50);
	}
	for(i=0;i<6;i++)
	{
		value = 0x40;
		PORTB = value>>i;
		delay(50);
	}
}



void delay(unsigned int time){ 
  unsigned int i,j;
  for(i=0;i<time;i++) for(j=0;j<40;j++);		//We are using 4Mhz crystal freq. in "PIC" therfore 4*10=40 that's why we are using 40. 
}