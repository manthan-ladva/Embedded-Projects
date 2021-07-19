#include <LPC214X.H>
#include "lcd.h"
#include "delay.h"


void lcd_init(void){
	Delay(5);
	IO0CLR = 0x00010000;        //backlight = p0.16 = 0; to on	
	display_lcd(0,0x00000003);		//;for 4 bit mode	                	
	display_lcd(0,0x00000003);		//;for 4 bit mode	 		        
	display_lcd(0,0x00000003);		//;for 4 bit mode		               	
	display_lcd(0,0x00000002);		//;Return Cursor and LCD to Home Position		            	
	display_lcd(0,0x00000028);		//;for rows and columns			            	
	display_lcd(0,0x0000000c);		//;turn disp on turn cursor on cursor blink on	            		
	display_lcd(0,0x00000006);		//;Inc Cursor After Each Byte Written to Disp      		
	//display_lcd(0,0x0000001c);	//;disp shift on, shift right	               		
	display_lcd(0,0x00000001);		//;clr disp
    Delay(5);
}


void enable(void){		   
	IO0SET = 0x00080000;				 //en=1
	Delay(5);
	IO0CLR = 0x00080000;				 //en=0
}


void display_lcd(unsigned int signal, char ch){
	Delay(5);
	IO0CLR = 0x00FF0000;
	
	if(1==signal) IO0SET = 0x00020000;	 //rs=1	 {Data}
	else IO0CLR = 0x00020000;			 //rs=0	 (Command)

	IO0CLR = 0x00040000;				 //rw=0 (Write)
	
	IO0PIN = ((IO0PIN & 0x000F0000) | (ch & 0x000000F0)<<16);
	enable();
	ch = ch<<4;
	IO0PIN = ((IO0PIN & 0x000F0000) | (ch & 0x000000F0)<<16);
	enable();
}


void lcd_string(char *ch){
	while(*ch !='\0'){
		display_lcd(1, *ch);
		ch++;
	}
}
