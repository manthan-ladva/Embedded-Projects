#include<pic.h>

#define switch0 RA1
#define switch1 RC0
#define switch2 RC1
#define switch3 RC2

unsigned int numbers[] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFE, 0xF6}; //0123456789

void delay(unsigned int time);
void tris(void);
void ssd_switch(unsigned int a, unsigned int b, unsigned int c, unsigned int d);
void display_ssd(unsigned int a, unsigned int b, unsigned int c, unsigned int d);


void main(void){
	tris();
	while(1) display_ssd(9,1,8,0);
}

void display_ssd(unsigned int a, unsigned int b, unsigned int c, unsigned int d){
	ssd_switch(1,1,1,0);
	PORTB = numbers[a];
	delay(1);
	PORTB = 0x00;

	ssd_switch(1,1,0,1);
	PORTB = numbers[b];
	delay(1);
	PORTB = 0x00;

	ssd_switch(1,0,1,1);
	PORTB = numbers[c];
	delay(1);
	PORTB = 0x00;

	ssd_switch(0,1,1,1);
	PORTB = numbers[d];
	delay(1);
	PORTB = 0x00;
}

void ssd_switch(unsigned int a, unsigned int b, unsigned int c, unsigned int d){
	switch0 = a;
	switch1 = b;
	switch2 = c;
	switch3 = d;
}

void tris(void){
	TRISA1 = 0;
	TRISB = 0x00;
	TRISC = 0xF8;
}

void delay(unsigned int time){ 
  unsigned int i,j;
  for(i=0;i<time;i++) for(j=0;j<40;j++);		//We are using 4Mhz crystal freq. in "PIC" therfore 4*10=40 that's why we are using 40. 
}