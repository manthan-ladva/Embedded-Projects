#include<pic.h>

void delay(unsigned int);

void main(){
	TRISB = 0; 
	//TRISB=0x00;		//port b made as output
	while(1){
		PORTB=0x11;		//01010101 this data will be display on port b
		delay(1000);

		PORTB=0x33;
		delay(1000);	
	}
}


void delay(unsigned int k){ 
  unsigned int i,j;
  for(i=0;i<k;i++) for(j=0;j<40;j++);		//We are using 4Mhz crystal freq. in "PIC" therfore 4*10=40 that's why we are using 40. 
}
	
		