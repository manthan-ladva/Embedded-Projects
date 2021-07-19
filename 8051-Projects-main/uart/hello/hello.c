#include <REG51F.H>

void init_uart(void);
void tx(unsigned char ch);

void main(void)
{
	init_uart();

	tx('H');
	tx('e');
	tx('l');
	tx('l');
	tx('o');
	tx(' ');

	while(1)
	{
	}

}

void init_uart(void)
{
	TMOD=0x20;
	TH1=0xfd;
	TR1=1;
	SCON=0x50;
}

void tx(unsigned char ch)
{
 	SBUF=ch;
	while(TI==0);
	TI=0;
}