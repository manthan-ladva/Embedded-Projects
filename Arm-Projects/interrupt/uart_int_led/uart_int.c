#include <LPC214X.H>


char cha;


//--------------Function Declaration--------------//
void init_arm(void);
void timer(unsigned int time);
void init_uart(void);
void Transmit(char ch);
char Receive(void);
void uart_interrupt(void);
void uart_int_isr(void) __irq;


//-------------------Functions-------------------//
int main(void){
	init_arm();
	init_uart();
	IO0PIN = 0x00FF0000;
	uart_interrupt();
	while(1);
}


//------------------------------------//Arm Function
void init_arm(void){
	VPBDIV = 0x00;				//1/4 clock selected=15mhz
	PINSEL0 = 0x00000005;		//Uart 
	PINSEL1 = 0x00000000;		//used as gpio pin p16-31 on port 0
	IO0DIR  = 0x00FF0000;		//set direction for output for port0 16-23	
}


//------------------------------------//Interrupt Function
void uart_int_isr(void) __irq{
	if(U0IIR & 0x00000004){			//Receive Interrupt Generated
		IO0PIN = 0x00010000;
		cha = Receive();
		timer(500);
		Transmit(cha);
		timer(500);
	}
	if(U0IIR & 0x00000002) IO0PIN = 0x00F10000;
	timer(500);
	IO0PIN = 0x00FF0000;
	VICVectAddr = 0x00000000;
}


void uart_interrupt(void){
	VICIntEnable=0X00000040;				//Interupt Enable
	VICIntSelect=0X00000000;				//irq interrupt selected
	VICVectCntl0=0X00000026;				//timer0 irq interrupt enabled.....
	VICVectAddr0=(unsigned)uart_int_isr;  	//Calling Interrupt
}


//------------------------------------//Timer Function
void timer(unsigned int time){ 
	T0TCR=0x01; 			//timer selectd
	T0PC=0;					//by default prescaler counter is 0
	T0PR=time;				//10ms count
	T0TC=0;					//by default timer counter is 0
  	T0MR0=15000;			//count for 1sec=(10000 will count 1500 times)  
  	T0MCR=0x00000002;		//interrupt selected and tc will be reset
	
	while(T0TC != T0MR0);
	T0TCR = 0x02;    	
}


//------------------------------------//Uart Function
void init_uart(void){
	U0FCR = 0x07;
	U0LCR = 0x83;
	U0DLL = 98;
	U0LCR = 0x03;
	U0IER = 0x00000003;
}


void Transmit(char ch){
	U0THR = ch;
	while((U0LSR & 0x40)==0);  //wait until transmitted i.e. while(TI==0); in 8051
}

/*
void Transmit_String(char *ch){
	while('\0' != *ch){
		Transmit(*ch);
		ch++;
	}
}
*/

char Receive(void){
	char serial_data;
	while((U0LSR & 0x01)==0);  //wait until received i.e. while(RI==0); in 8051
	serial_data = U0RBR;

	return (serial_data);
}
