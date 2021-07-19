#include<REG51.h>

void delay(unsigned long int time);
void display();
void increment();

unsigned char seg[]={0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,0xfe,0xec};
unsigned char D1,D2,D3,D4;
unsigned int i;
sbit SW1=P2^0;
sbit SW2=P2^1;
sbit SW3=P2^2;
sbit SW4=P2^3;


void main()
{
	D1=0;
	D2=0;
	D3=0;
	D4=0;
	delay(1);

	while(1)
	{
		for(i=0;i<10;i++)
		display();
		increment();
	}
}
void display()
{
	SW1=0;
	SW2=SW3=SW4=1;
	P0=seg[D1];
	delay(1);
	P0=0x00;

	SW1=SW3=SW4=1;
	SW2=0;
	P0=seg[D2];
	delay(1);
	P0=0x00;

	SW1=SW2=SW4=1;
	SW3=0;
	P0=seg[D3];
	delay(1);
	P0=0x00;

	SW1=SW2=SW3=1;
	SW4=0;
	P0=seg[D4];
	delay(1);
	P0=0x00;
}

void increment()
{
	D1++;
	if(D1==10)
	{
		D1=0;
		D2++;
		if(D2==10)
		{
			D2=0;
			D3++;
			if(D3==10)
			{
				D3=0;
				D4++;
				if(D4==10)
				{
					D1=D2=D3=D4=0;
				}
			}
		}
	 }
}
void delay(unsigned int time)
{
	unsigned int i,j;
	for(i=0;i<time;i++){
		for(j=0;j<120;j++){
		}
	}
}



