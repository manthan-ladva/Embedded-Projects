#include <REG51F.H>

void init_uart()
{
	TMOD=0x20;
	TH1=0xFD;
	TR1=1;
	SCON=0x50;
}

void tx(unsigned int digit)
{
 	SBUF=digit;
	P0 = SBUF;
	while(TI==0);
	TI=0;
}

void delay(unsigned long int time){			  //Delay Function
	unsigned long int i;
	unsigned int j;

	for(i=0;i<time;i++){
		for(j=0;j<120;j++){
			
		}
	}
}

void main(){
	unsigned int i;
	init_uart();

	while(1){
		for(i=1;i<256;i++){
			tx(i);
			delay(50);
		}
	}

}