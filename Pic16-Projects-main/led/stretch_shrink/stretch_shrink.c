#include<pic.h>

void delay(unsigned int time);
void stretch_shrink(void);

void main(void){
	while(1) stretch_shrink();
}


void stretch_shrink(void){
	TRISB = 0x00;
	unsigned int a,b,i,value;
	value = 1;
	a = value<<3;
	b = value<<4;
	for(i=1;i<4;i++){
		PORTB = a+b;
		delay(250);
		a = a>>1;
		b = b<<1;
	}
	for(i=1;i<4;i++){
		PORTB = a+b;
		delay(250);
		a = a<<1;
		b = b>>1;
	}
	
}


void delay(unsigned int time){ 
  unsigned int i,j;
  for(i=0;i<time;i++) for(j=0;j<40;j++);		//We are using 4Mhz crystal freq. in "PIC" therfore 4*10=40 that's why we are using 40. 
}