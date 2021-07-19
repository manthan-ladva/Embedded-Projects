#include<REG51F.H>

unsigned int count=0;
void T0Delay(){
	TMOD = 0x01;
	TH0 = 0x00;
	TL0 = 0x00;
	TR0 = 1;
	while(TF0==0);
	TR0 = 0;
	TF0 = 0;
}

void timer0_isr() interrupt 1{
	count++;
	//T0Delay();
	if(count == 2){
		P0 = ~P0;
		count = 0;
		T0Delay();
	}
}

void main(){
	P0 = 0xFF;
	while(1){
		T0Delay();
		EA = 1;
		ET0 = 1;
	}
}