//#include <P89V51Rx2.H>
#include <REG51F.h>

void delay(unsigned long int time);

void main() {
	while(1) {
		P0 = 0xFF;	// All LEDs ON
		delay(500);
		P0 = 0x00;	// All LEDs OFF
		delay(500);
	}
}

void delay(unsigned long int time) {
	unsigned long int i;
	unsigned int j;

	for (i=0; i<time; i++)
	{
		for (j=0; j<120; j++)
		{
		}
	}
}