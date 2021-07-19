#include "ssd.h"
#include "delay.h"
//#include<REG51F.H>

//----------------------SSD Functions----------------------//
void ssd_switch(unsigned int a, unsigned int b, unsigned int c, unsigned int d){				
	SWITCH0 = a;								   //SSD_Switch Function To Activate SSD
	SWITCH1 = b;
	SWITCH2 = c;
	SWITCH3 = d;
}


void display(unsigned int your_value1, unsigned int your_value2, unsigned int your_value3, unsigned int your_value4){	
	ssd_switch(1,1,1,0);						    //Display Function for SSD
	P0 = your_value1;
	Delay(1);
	P0 = 0x00;

	ssd_switch(1,1,0,1);
	P0 = your_value2;
	Delay(1);
	P0 = 0x00;

	ssd_switch(1,0,1,1);
	P0 = your_value3;
	Delay(1);
	P0 = 0x00;

	ssd_switch(0,1,1,1);
	P0 = your_value4;
	Delay(1);
	P0 = 0x00;
}