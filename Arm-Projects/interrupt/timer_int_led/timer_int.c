#include <LPC214X.H>


void init_timer(unsigned int time);
void init_arm(void);
void timer_interrupt(void);


void isr_t0(void) __irq{
	T0TCR = 1;
	IO0PIN = ~IO0PIN;
	T0IR = 0x01;
	VICVectAddr = 0x00000000;
}


int main(void){
	init_arm();
	IO0PIN = 0x00BB0000;
	timer_interrupt();
	while(1);
}


void timer_interrupt(void){
	VICIntEnable=0x00000010;	//timer0 interrupt selected...
	VICIntSelect=0x00000000;	//irq interrupt selected
	VICVectCntl0=0x00000024;	//timer0 irq interrupt enabled.....
	VICVectAddr0=(unsigned)isr_t0;  //
	
	init_timer(1000);				//timer initialize
}
					

void init_arm(void){
	VPBDIV = 0x00;				//1/4 clock selected=15mhz
	PINSEL1 = 0x00000000;		//used as gpio pin p16-31 on port 0
	IO0DIR  = 0x00FF0000;		//set direction for output for port0 16-23	
}


void init_timer(unsigned int time){ 
	T0TCR=0x01; 			//timer selectd
	T0PC=0;				//by default prescaler counter is 0
	T0PR=time;			//10ms count
	T0TC=0;				//by default timer counter is 0
  	T0MR0=15000;			//count for 1sec=(10000 will count 1500 times)  
  	T0MCR=0x00000003;		//interrupt selected and tc will be reset    	
}
