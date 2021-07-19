#include "delay.h"

//--------------Variable Declaration--------------//
unsigned int value_array[] = {						   //0123456789
0x00FC0000, 0x00600000, 0x00DA0000,
0x00F20000, 0x00660000, 0x00B60000,
0x00BE0000, 0x00E00000, 0x00FE0000, 0x00F60000		   
};

unsigned int ds1,ds2,ds3,ds4,ds5;


//-------------------Functions-------------------//
void rotate(){
	ds5=ds1;
	ds1=ds2;
	ds2=ds3;
	ds3=ds4;
	ds4=ds5;
}


void display_ssd(unsigned int a, unsigned int b, unsigned int c, unsigned int d){	
	IO1DIR=0X00010000;	//output directon  p1.16
	IO0SET=value_array[d];	//port 0 output PATTERN 0F ZER0(FC)
	Delay(10);
	IO0CLR=value_array[d];	

	IO1DIR=0X00020000;	//output direction p1.17
	IO0SET=value_array[c];
	Delay(10);
	IO0CLR=value_array[c];	

	IO1DIR=0X00040000;	//output direction p1.18
	IO0SET=value_array[b];
	Delay(10);
	IO0CLR=value_array[b];

	IO1DIR=0X00080000;	//output direction p1.19
	IO0SET=value_array[a];
	Delay(10);
	IO0CLR=value_array[a];
}