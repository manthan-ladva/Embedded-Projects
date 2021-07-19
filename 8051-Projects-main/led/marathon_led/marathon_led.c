#include<REG51F.H>

void delay(unsigned long int time);
void marathon(unsigned int no_of_led);

void main(){
	unsigned int loop=0;
	while(loop<3){
		marathon(8);
		loop++;
		if(loop==3){
			P0 = 0xFF;
			delay(250);
			P0 = 0x00;
		}
	}
	while(1){}
}

void delay(unsigned long int time){			  //Delay Function
	unsigned long int i;
	unsigned int j;

	for(i=0;i<time;i++){
		for(j=0;j<120;j++){
			
		}
	}
}

void marathon(unsigned int no_of_led){
	unsigned int i,j, value=1;

	P0 = value;
	delay(500);

	for(i=1;i<no_of_led;i++){
		value = value<<1;
		P0 = value;
		delay(500);

		if(i == no_of_led-1){
			for(j=no_of_led-1;j>1;j--){
				value = value>>1;
				P0 = value;
				delay(500);
			}
		}
	}
} 