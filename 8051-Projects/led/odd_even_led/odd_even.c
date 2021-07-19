#include<REG51F.H>

void delay(unsigned long int time);
void odd_even(unsigned int no_of_led);

void main(){
	int new=0;
	do{
		odd_even(8);
		P0 = 0xFF;
		delay(250);
		P0=0x00;
		delay(250);
	}while(new>0);
	while(1){}
}

void odd_even(unsigned int no_of_led){
	unsigned int i,a,half;
	half = no_of_led/2;
	a=1;
	P0 = a;
	delay(500);
	for(i=1;i<half;i++){
		a = a<<2;
		P0 = a;
		delay(500);	
	}

	a=2;
	P0 = a;
	delay(500);
	for(i=1;i<half;i++){
		a = a<<2;
		P0 = a;
		delay(500);	
	}
}


void delay(unsigned long int time){			  //Delay Function
	unsigned long int i;
	unsigned int j;

	for(i=0;i<time;i++){
		for(j=0;j<120;j++){
			
		}
	}
}                                                                                                                                                                                                                                                