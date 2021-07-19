#include<pic.h>


void delay(unsigned int time);
void odd_even(void);


void main(void){
	while(1) odd_even();
}


void odd_even(void){
	TRISB = 0x00;
	unsigned int i, value;
	
	value=2;
	for(i=0;i<4;i++){
		PORTB = value;
		value = value<<2;
		delay(500);
	}
	value=1;
	for(i=0;i<4;i++){
		PORTB = value;
		value = value<<2;
		delay(500);
	}
}



void delay(unsigned int time){ 
  unsigned int i,j;
  for(i=0;i<time;i++) for(j=0;j<40;j++);		//We are using 4Mhz crystal freq. in "PIC" therfore 4*10=40 that's why we are using 40. 
}