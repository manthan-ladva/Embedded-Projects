#include<REG51F.H>

sbit SWITCH0 = P2^0;
sbit SWITCH1 = P2^1;
sbit SWITCH2 = P2^2;
sbit SWITCH3 = P2^3;

unsigned int value_array[] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFE, 0xF6}; //0123456789

void delay(unsigned long int time){			  //Delay Function
	unsigned long int i;
	unsigned int j;

	for(i=0;i<time;i++){
		for(j=0;j<120;j++){}
	}
}

void ssd_switch(unsigned int a, unsigned int b, unsigned int c, unsigned int d){
	SWITCH0 = a;
	SWITCH1 = b;
	SWITCH2 = c;
	SWITCH3 = d;
}

void swap(unsigned int *value1, unsigned int *value2, unsigned int *value3, unsigned int *value4){
	unsigned int temp;

	temp = *value1;
	*value1 = *value2;
	*value2 = *value3;
	*value3 = *value4;
	*value4 = temp;

	return;
}

void swapper(unsigned int a, unsigned int b, unsigned int c, unsigned int d){
	int i,j,k,l;
	for(i=0;i<4;i++){
		ssd_switch(1,1,1,0);
		P0 = a;
		delay(1);
		P0 = 0x00;
	
		ssd_switch(1,1,0,1);
		P0 = b;
		delay(1);
		P0 = 0x00;
	
		ssd_switch(1,0,1,1);
		P0 = c;
		delay(1);
		P0 = 0x00;
	
		ssd_switch(0,1,1,1);
		P0 = d;
		delay(1);
		P0 = 0x00;

		for(j=0;j<200;j++){for(k=0;k<100;k++){}}		
		swap(&a, &b, &c, &d);
		//delay(500);
		
	}	 
}

void main(){
	while(1){
		swapper(value_array[1], value_array[2], value_array[3], value_array[4]);
	}
}