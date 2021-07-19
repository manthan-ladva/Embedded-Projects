#include <LPC214X.H>


char cha;
int uart_int_rec = 0;


//--------------Function Declaration--------------//
void init_arm(void);

void delay(unsigned int time);
void timer0(unsigned int time);

void init_uart(void);
void Transmit(char ch);
char Receive(void);

void interrupt(void);

//-------------------Functions-------------------//
void timer_int1_fiq(void) __irq
{
	T0TCR = 1;
	IO0PIN = 0x00020000;
	T0IR = 0x01;
	VICVectAddr = 0x00000000;
}


void uart_int0_irq(void) __irq {
	if(U0IIR & 0x00000004){			//Receive Interrupt Generated
		cha = U0RBR;
		uart_int_rec = 1;
	}
	VICVectAddr = 0x00000000;
}


int main(void)
{
	init_arm();
	init_uart();
	IO0PIN = 0x00FF0000;
	interrupt();

	while(1) {
		if (uart_int_rec) {
			IO0PIN = 0x00040000;
			Transmit(cha);
			uart_int_rec = 0;	
		}
		else {
			IO0PIN = 0x00FF0000;
		}
		delay(1000);
	}
}


//------------------------------------//Arm Function
void init_arm(void){
	VPBDIV = 0x00;				//1/4 clock selected=15mhz
	PINSEL0 = 0x00000085;		//Timer0 Match & Uart
	PINSEL1 = 0x00000000;		//used as gpio pin p16-31 on port 0
	IO0DIR  = 0x00FF0000;		//set direction for output for port0 16-23	
}


//------------------------------------//Interrupt Function
void interrupt(void){
	VICIntEnable=0X00000050;				//Interupt Enable UART0 & Timer0
	VICIntSelect=0X00000010;				//Timer0 = FIQ & UART0 = IRQ
	VICVectCntl0=0X00000026;				//UART0 irq interrupt enabled.....
	VICVectAddr0=(unsigned)uart_int0_irq;  	//Calling Interrupt
	VICVectCntl1=0X00000024;				//Timer0 fiq interrupt enabled....
	VICVectAddr1=(unsigned)timer_int1_fiq;  //Calling Interrupt

	timer0(1000); //interrupt_timer0 fiq
}


void timer0(unsigned int time){ 
	T0TCR=0x01; 			//timer selectd
	T0PC=0;				//by default prescaler counter is 0
	T0PR=time;			//10ms count
	T0TC=0;				//by default timer counter is 0
  	T0MR0=15000;			//count for 1sec=(10000 will count 1500 times)  
  	T0MCR=0x00000003;		//interrupt selected and tc will be reset    	
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


void delay (unsigned int time){
 unsigned int i,j;
 for (i=0;i<=time;i++) for(j=0;j<=1500;j++);
}
