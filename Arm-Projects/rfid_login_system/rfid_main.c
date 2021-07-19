#include<LPC214x.h>
#include "headers\brains.h"


//--------------Function Declaration---  ------------//
void pin_init(void);  


//-------------------Functions-------------------//
int main(void){
	pin_init();
	//ssd_brain();
	lcd_brain();
}


void pin_init(void){
	VPBDIV = 0x00; 		  //Freq management 0x00 = 15MHz
	PINSEL0 = 0x00000005; //UART 
	PINSEL1 = 0x00000000; //PINSEL1 = P0.16 to P0.31 where GPIO is 00
	PINSEL2 = 0x00000000; //PINSEL1 = P1.16 to P1.31
	IO0DIR = 0x00FF0000;  //LED Lies on P0.16 to P0.23
}
