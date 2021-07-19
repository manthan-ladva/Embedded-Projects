#include<LPC21xx.h>

//--------------Function Declaration---------------//
void Delay (unsigned long int time);
void pin_init(void);
void display_ssd(unsigned int a, unsigned int b, unsigned int c, unsigned int d);


//--------------Variable Declaration--------------//
unsigned int value_array[] = {						   //0123456789
0x00FC0000, 0x00600000, 0x00DA0000,
0x00F20000, 0x00660000, 0x00B60000,
0x00BE0000, 0x00E00000, 0x00FE0000, 0x00F60000		   
};  


//-------------------Functions-------------------//
int main(void){
	pin_init();
	while(1) display_ssd(0,1,2,3);
}

void display_ssd(unsigned int a, unsigned int b, unsigned int c, unsigned int d){	
	IO1DIR=0X00010000;	//output directon  p1.16	
	IO0PIN=
	IO0SET=value_array[d];	//port 0 output PATTERN 0F ZER0(FC)
	Delay(10);
	IO0CLR=value_array[d];		

	IO1DIR=0X00020000;	//output direction p1.17	
	IO0SET=value_array[c];
	Delay(10);
	IO0CLR=value_array[c];		

	IO1DIR=0X00040000;	//output direction p1.18	
	IO0SET=value_array[b];
	Delay(10);
	IO0CLR=value_array[b];

	IO1DIR=0X00080000;	//output direction p1.19	
	IO0SET=value_array[a];
	Delay(10);
	IO0CLR=value_array[a];
}  


void pin_init(void){
	VPBDIV = 0x00; //Freq management 0x00 = 15MHz
	PINSEL1 = 0x00000000; //PINSEL1 = P0.16 to P0.31 where GPIO is 00
	PINSEL2 = 0x00000000; //PINSEL1 = P1.16 to P1.31
	IO0DIR = 0x00FF0000; //LED Lies on P0.16 to P0.23
	IO1DIR = 0x000F0000;
}


void Delay (unsigned long int time){
 unsigned int i,j;
 for (i=0;i<=time;i++) for(j=0;j<=1500;j++);
}
