#include <LPC214X.H>

//--------------Function Declaration---------------//
void blink_led(void);
void Delay (unsigned int time);


//--------------All Function---------------//
void main(void){
	while(1) blink_led();
}

void blink_led(void){
	unsigned int i,value = 0x00010000;  //Value for Led Blink

	VPBDIV = 0x00; //Freq management 0x00 = 15MHz
	PINSEL1 = 0x00000000; //PINSEL1 = P0.16 to P0.31
	IO0DIR = 0x00FF0000; //LED Lies on P0.16 to P0.23

	for(i=0;i<7;i++){
		IO0PIN = value;
		Delay(250);
		value = value<<1;
	}
	for(i=0;i<7;i++){
		IO0PIN = value;
		Delay(250);
		value = value>>1;
	}
	value = 0x00010000;
}


void Delay (unsigned int time){
 unsigned int i,j;
 for (i=0;i<=time;i++) for(j=0;j<=1500;j++);
}


