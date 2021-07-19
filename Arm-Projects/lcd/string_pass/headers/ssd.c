#include "ssd.h"
#include "delay.h"
#include <LPC214X.H>


void display_ssd(unsigned int a, unsigned int b, unsigned int c, unsigned int d){	
	IO1DIR=0X00010000;	//output directon  p1.16
	IO0SET=d;			//port 0 output PATTERN 0F ZER0(FC)
	Delay(10);
	IO0CLR=d;		

	IO1DIR=0X00020000;	//output direction p1.17	
	IO0SET=c;
	Delay(10);
	IO0CLR=c;		

	IO1DIR=0X00040000;	//output direction p1.18	
	IO0SET=b;
	Delay(10);
	IO0CLR=b;

	IO1DIR=0X00080000;	//output direction p1.19	
	IO0SET=a;
	Delay(10);
	IO0CLR=a;
}
