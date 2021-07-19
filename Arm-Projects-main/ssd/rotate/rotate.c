#include<LPC21xx.h>
#include "header_files\ssd_functions.h"

//--------------Function Declaration---------------//
void pin_init(void);


//-------------------Functions-------------------//
void main(void){
	unsigned int i;
	pin_init();
	ds1=5;
	ds2=2;
	ds3=3;
	ds4=4;
	
	while(1){
		for(i=0;i<50;i++) display_ssd(ds4,ds3,ds2,ds1);
		rotate();
	}
} 


void pin_init(void){
	VPBDIV = 0x00; //Freq management 0x00 = 15MHz
	PINSEL1 = 0x00000000; //PINSEL1 = P0.16 to P0.31 where GPIO is 00
	PINSEL2 = 0x00000000; //PINSEL1 = P1.16 to P1.31 where GPIO is 00
	IO0DIR = 0x00FF0000; //LED Lies on P0.16 to P0.23
}