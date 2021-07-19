#include <REG51F.H>


//-------------------Switch Declaration---------------//
sbit bl = P0^0;	//backlight
sbit rs = P0^1;
sbit rw = P0^2;
sbit en = P0^3;


//--------------------Function Declaration------------------//
void Delay(unsigned int time);
void lcd_string(unsigned char *ch);
void enable(void);
void init_lcd(void);
void display(unsigned char signal, unsigned char ch);


void main(){
	init_lcd();
	
	display(0,0x83);
	lcd_string("Welcome To");
	display(0,0xC0);
	lcd_string("Manthan Security");

	Delay(2000);
	display(0,0x01);

	display(0,0x81);
	lcd_string("Please Give Me");
	display(0,0xC2);
	lcd_string("Your ID Card");

	while(1);
}


void init_lcd(void){	
	Delay(15);
	bl=0;
//	display(0,0x03);
//	display(0,0x03);
//	display(0,0x03);
	display(0,0x02);
	display(0,0x28);
	display(0,0x0C);
	display(0,0x06);
	display(0,0x01);
}


void display(unsigned char signal, unsigned char ch){
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
		display(1, *ch);
		ch++;
	}
}


void Delay(unsigned int time) {		    //Delay Function
	unsigned int i,j;
	for(i=0;i<time;i++)
		for(j=0;j<120;j++);
}