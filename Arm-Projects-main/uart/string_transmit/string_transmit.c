#include <LPC214X.H>


void init_uart(void);
void tx(unsigned char ch);
void delay(unsigned int time);
void pin_init(void);


int main(void){
	unsigned int i;

	pin_init();
	init_uart();

	while(1){
		for(i=0;i<256;i++){
			tx(i);
			delay(50);
		}
	}
}


void pin_init(void){
	VPBDIV = 0x00;
	PINSEL0 = 0x00000005;
	PINSEL1 = 0x00000000;
	IO0DIR = 0x00FF0000;
}


void init_uart(void){
	U0FCR = 0x07;
	U0LCR = 0x83;
	U0DLL = 98;
	U0LCR = 0x03;
}


void tx(unsigned int ch){
	U0THR = ch;
	IO0PIN = U0THR<<16;
	while((U0LSR & 0x20)==0);  //wait until transmitted i.e. while(TI==0); in 8051
}


void delay(unsigned int time){			  //Delay Function
	unsigned long int i;
	unsigned int j;

	for(i=0;i<time;i++)	for(j=0;j<1500;j++);
}