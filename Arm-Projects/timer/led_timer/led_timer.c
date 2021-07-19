#include <LPC214X.H>


void pin_init(void){
	VPBDIV = 0x00; //Freq management 0x00 = 15MHz
	PINSEL0 = 0x00000080; //PINSEL1 = P0.0 to P0.15 where Timer_Match_0 is 80
	PINSEL1 = 0x00000000; //PINSEL1 = P1.16 to P1.31
	IO0DIR = 0x00FF0000; //LED Lies on P0.16 to P0.23
}


void timer(unsigned int time){
	T0TCR = 0x01;			 //timer enable
	T0PC = 0;				 //batsman (always 0 as per initial stage)
	T0PR = time;			 //non-striker
	T0TC = 0x00000000;		 //scoreboard (always 0 as per initial stage)
	T0MR0 = 15000;			 //scoreboard final
	//T0MCR = 0x000000002;	 //reset

	while(T0TC != T0MR0);
	//T0TCR = 0x02;
	T0MCR = 0x000000002;	 //reset
}


int main(void){
	pin_init();
	while(1){
		IO0SET	=	0X00F00000;
		timer(500);
		IO0CLR	=	0X00F00000;
		timer(500);
	}	
}
