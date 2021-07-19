#include<LPC21xx.h>

//--------------Function Declaration---------------//
void Delay (unsigned int time);
void pin_init(void);
void odd_even(void);


void main(){
	while(1) odd_even();
}


void odd_even(void){
	unsigned int value = 0x00010000;
	unsigned int i;

	pin_init();

	for(i=0;i<4;i++){
		IO0PIN = value;
		Delay(1000);
		value = value << 2;
	}
	value = 0x00020000;
	for(i=0;i<4;i++){
		IO0PIN = value;
		Delay(1000);
		value = value << 2;
	}

}


void pin_init(void){
	VPBDIV = 0x00; //Freq management 0x00 = 15MHz
	PINSEL1 = 0x00000000; //PINSEL1 = P0.16 to P0.31
	IO0DIR = 0x00FF0000; //LED Lies on P0.16 to P0.23
}


void Delay (unsigned int time){
 unsigned int i,j;
 for (i=0;i<=time;i++) for(j=0;j<=1500;j++);
}