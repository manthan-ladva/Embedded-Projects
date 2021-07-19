#include "lcd.h"
#include "delay.h"
//#include<REG51F.H>


//----------------------LCD Functions----------------------//
void init_lcd(void){	
	Delay(15);
	bl=0;
	display_lcd(0,0x03);
	display_lcd(0,0x03);
	display_lcd(0,0x03);
	display_lcd(0,0x02);
	display_lcd(0,0x28);
	display_lcd(0,0x0C);
	display_lcd(0,0x06);
	display_lcd(0,0x01);
}


void display_lcd(unsigned char signal, unsigned char ch){
	Delay(5);
	rs=signal;
	rw=0;
	P0 = ((P0 & 0x0F) | (ch & 0xF0));
	enable();
	P0 = ((P0 & 0x0F) | ((ch<<4) & 0xF0));
	enable();
}


void enable(void){
	en=1;
	Delay(3);
	en=0;
}


void lcd_string(unsigned char *ch){
	while(*ch != '\0'){
		display_lcd(1, *ch);
		ch++;
	}
}