#include<REG51F.H>

void T0Delay(){
	TMOD = 0x10;
	//TL1 = 0xA4;
	T1 = 0x3500;
	TR1 = 1;
	while(TF1==0);
	TR1 = 0;
	TF1 = 0;
}

void main(){
	P0 = 0xFF;
	while(1){
		P0 = ~P0;
		T0Delay();
	}
}