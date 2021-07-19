#include <REG51F.H>

sbit buzzer=P1^0;   //Buzzer in Universal Kit

void Delay(unsigned int time){
	unsigned int i,j;
	for(i=0;i<time;i++) for(j=0;j<120;j++);
} 


void main(void){
	while(1){
		buzzer = 1;			//On
		Delay(2000);
		buzzer = 0;			//Off
		Delay(2000);
	}
}