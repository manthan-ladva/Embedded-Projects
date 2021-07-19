#include<LPC21xx.h>

//--------------Function Declaration---------------//
void Delay (unsigned long int time);
void pin_init(void);
void one_to_255(void);


void main(void){
	while(1){
		one_to_255();
		IO0PIN = 0x00000000;
		Delay(5000);
	}
}


void one_to_255(void){
	unsigned int led_value = 1;
	unsigned int i;

	pin_init();

	for(i=0;i<255;i++){
		IO0PIN = led_value << 16;
		led_value += 1;
		Delay(500);
	}
}


void pin_init(void){
	VPBDIV = 0x00; //Freq management 0x00 = 15MHz
	PINSEL1 = 0x00000000; //PINSEL1 = P0.16 to P0.31
	IO0DIR = 0x00FF0000; //LED Lies on P0.16 to P0.23
}


void Delay(unsigned long int time){
 unsigned int i,j;
 for (i=0;i<=time;i++) for(j=0;j<=1500;j++);
}