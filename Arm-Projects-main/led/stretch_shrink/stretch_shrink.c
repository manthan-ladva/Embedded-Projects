#include<LPC21xx.h>

//--------------Function Declaration---------------//
void Delay (unsigned long int time);
void pin_init(void);
void stretch_shrink(void);


void main(void){
	while(1) stretch_shrink();
}


void stretch_shrink(void){
	unsigned int msb = 0x00100000;
	unsigned int lsb = 0x00080000;
	unsigned int i;

	pin_init();

	for(i=0;i<3;i++){
		IO0PIN = msb+lsb;
		Delay(500);
		msb = msb<<1;
		lsb = lsb>>1;
	}

	for(i=0;i<3;i++){
		IO0PIN = msb+lsb;
		Delay(500);
		msb = msb>>1;
		lsb = lsb<<1;
	}
}


void pin_init(void){
	VPBDIV = 0x00; //Freq management 0x00 = 15MHz
	PINSEL1 = 0x00000000; //PINSEL1 = P0.16 to P0.31
	IO0DIR = 0x00FF0000; //LED Lies on P0.16 to P0.23
}


void Delay (unsigned long int time){
 unsigned int i,j;
 for (i=0;i<=time;i++) for(j=0;j<=1500;j++);
}