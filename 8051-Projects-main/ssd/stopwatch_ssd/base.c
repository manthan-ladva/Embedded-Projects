#include<REG51F.H>

sbit SWITCH0 = P2^0;
sbit SWITCH1 = P2^1;
sbit SWITCH2 = P2^2;
sbit SWITCH3 = P2^3;

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

void reset(){
	ssd_switch(1,1,1,0);
	P0 = 0xFF;
	delay(1);
	//P0 = 0x00;

	ssd_switch(1,1,0,1);
	P0 = 0xFF;
	delay(1);
	//P0 = 0x00;

	ssd_switch(1,0,1,1);
	P0 = 0xFF;
	delay(1);
	//P0 = 0x00;

	ssd_switch(0,1,1,1);
	P0 = 0xFF;
	delay(1);
	//P0 = 0x00;
}

void stopwatch(){
	unsigned int value_array[] = {0xFC, 0x0C, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFE, 0xF6}; //0123456789
	unsigned int minute[] = {0xFD, 0x61, 0xDB, 0xF3}; //0.1.2.3.
	unsigned int i,j,k,l,m;

	for(i=0;i<4;i++){
		for(j=0;j<6;j++){
			for(k=0;k<10;k++){
				for(l=0;l<10;l++){
					for(m=0;m<10;m++){
						ssd_switch(1,1,1,0);
						P0 = minute[i];
						delay(1);
						P0 = 0x00;
			
						ssd_switch(1,1,0,1);
						P0 = value_array[j];
						delay(1);
						P0 = 0x00;
			
						ssd_switch(1,0,1,1);
						P0 = value_array[k];
						delay(1);
						P0 = 0x00;
		
						ssd_switch(0,1,1,1);
						P0 = value_array[l];
						delay(1);
						P0 = 0x00;
					}
				}
			}
		}                                                                                                                                                                                                                     )
	}
}

void main(){
	int i;
	while(1){
		stopwatch();
		for(i=0;i<200;i++) reset();
	}
}