#include<REG51F.H>

sbit SWITCH0 = P2^0;
sbit SWITCH1 = P2^1;
sbit SWITCH2 = P2^2;
sbit SWITCH3 = P2^3;

void display(unsigned int your_value1, unsigned int your_value2, unsigned int your_value3, unsigned int your_value4);
void ssd_switch(unsigned int a, unsigned int b, unsigned int c, unsigned int d);
void delay(unsigned long int time);

void main(){
	while(1){
		display(4,5,7,2);
	}
}

void display(unsigned int your_value1, unsigned int your_value2, unsigned int your_value3, unsigned int your_value4){
	unsigned long int value_array[] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFE, 0xF6}; //0123456789
	
	ssd_switch(1,1,1,0);
	P0 = value_array[your_value1];
	delay(1);
	P0 = 0x00;

	ssd_switch(1,1,0,1);
	P0 = value_array[your_value2];
	delay(1);
	P0 = 0x00;

	ssd_switch(1,0,1,1);
	P0 = value_array[your_value3];
	delay(1);
	P0 = 0x00;

	ssd_switch(0,1,1,1);
	P0 = value_array[your_value4];
	delay(1);
	P0 = 0x00;
}

void ssd_switch(unsigned int a, unsigned int b, unsigned int c, unsigned int d){
	SWITCH0 = a;
	SWITCH1 = b;
	SWITCH2 = c;
	SWITCH3 = d;
}

void delay(unsigned long int time){			  //Delay Function
	unsigned long int i;
	unsigned int j;

	for(i=0;i<time;i++){
		for(j=0;j<120;j++){
			
		}
	}
}