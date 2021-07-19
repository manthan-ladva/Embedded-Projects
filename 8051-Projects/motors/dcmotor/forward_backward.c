#include <REG51F.H>


sbit en12=P1^0;		//enable pin
sbit en34=P1^5;		//enable pin
sbit inp1=P1^1;		//inp1 for mtr 1
sbit inp2=P1^2;		//inp2 for mtr 1
sbit inp3=P1^3;		//inp1 for mtr 2
sbit inp4=P1^4;		//inp2 for mtr 2


void delay(unsigned int time);
void forward(void);
void reverse(void);
void stop(void);


#define en12 1
#define en34 1


void main(void){
	

	while(1){
		forward();
		stop();
		reverse();
		stop();
	}
}


void delay(unsigned int itime){
	unsigned int i,j;
	for(i=0;i<itime;i++) for(j=0;j<120;j++);
}


void forward(void){
	inp1 = 1;	 //forward
	inp2 = 0;
	inp3 = 1;
	inp4 = 0;

	delay(500);
	delay(500);
}


void reverse(void){
	inp1 = 0;	  //reverse
	inp2 = 1;
	inp3 = 0;
	inp4 = 1;

	delay(500);
	delay(500);
} 


void stop(void){
	inp1 = 0;	 //stop
	inp2 = 0;
	inp3 = 0;
	inp4 = 0;

	delay(500);
	delay(500);
}