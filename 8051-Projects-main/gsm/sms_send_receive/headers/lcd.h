#include<REG51F.H>

#ifndef _LCD_H
#define _LCD_H

//-----------------------------------------//LCD Switch Ports
sbit bl = P0^0;	//backlight
sbit rs = P0^1;
sbit rw = P0^2;
sbit en = P0^3;

//----------------------------------------//Function Prototypes
void lcd_string(unsigned char *ch);
void enable(void);
void init_lcd(void);
void display_lcd(unsigned char signal, unsigned char ch);

#endif