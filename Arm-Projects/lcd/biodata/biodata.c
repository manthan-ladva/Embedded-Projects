#include <LPC214X.H>
#include "headers/delay.h"
#include "headers/uart.h"


//---------------------Function Declarations
void pin_init(void);
void enable(void);
void display(unsigned int signal, char ch);
void lcd_string(char *ch);
void lcd_init(void);


int main(void){
	pin_init();
	lcd_init();
	
	while(1){
		Delay(15);
		display(0,0x00000084);			//Data in 1st line with leaving 3 space
		lcd_string("Hii I Am");
		display(0,0x000000C1);			//Data in 2nd line with leaving 1 space
		lcd_string("Manthan Ladva");
	
		Delay(2000);
		display(0,0x00000001);			//Clearing the display or else it will overwrite
	
		display(0,0x00000083);
		lcd_string("I Am An");
		display(0,0x000000C0);
		lcd_string("Embedded Enginer");
	
		Delay(2000);
		display(0,0x00000001);
	
		display(0,0x00000085);
		lcd_string("& Also");
		display(0,0x000000C2);
		lcd_string("M.L. Enginner");

		Delay(2000);
		display(0,0x00000001);
	}
}


void pin_init(void){
	VPBDIV = 0x00; //15MHz
	PINSEL0 = 0x00000005;
	PINSEL1 = 0x00000000;
	IO0DIR = 0x00FF0000;
}


void lcd_init(void){
	Delay(5);
	IO0CLR = 0x00010000;        //backlight = p0.16 = 0; to on	
	display(0,0x00000003);		//;for 4 bit mode	                	
	display(0,0x00000003);		//;for 4 bit mode	 		        
	display(0,0x00000003);		//;for 4 bit mode		               	
	display(0,0x00000002);		//;Return Cursor and LCD to Home Position		            	
	display(0,0x00000028);		//;for rows and columns			            	
	display(0,0x0000000c);		//;turn disp on turn cursor on cursor blink on	            		
	display(0,0x00000006);		//;Inc Cursor After Each Byte Written to Disp      		
	//display(0,0x0000001c);	//;disp shift on, shift right	               		
	display(0,0x00000001);		//;clr disp
    Delay(5);
}


void enable(void){		   
	IO0SET = 0x00080000;				 //en=1
	Delay(5);
	IO0CLR = 0x00080000;				 //en=0
}


void display(unsigned int signal, char ch){
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
		display(1, *ch);
		ch++;
	}
}
