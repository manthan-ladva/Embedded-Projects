#include <LPC214X.H>
#include <string.h>


char serial_data;
char table[]="Hello I Am Manthan.I am Embedded Engineer";


void init_uart(void);
void Transmit(unsigned char ch);
void Transmit_String(unsigned char *ch);
unsigned char Receive();


int main(void){
	unsigned int i,length;
	init_uart();

	VPBDIV = 0x00;
	PINSEL0 = 0x00000005;

	length = strlen(table);
	for(i=0;i<length;i++){
		Transmit(table[i]);
	}
	Transmit_String("\r\n");
	while(1);
}


void init_uart(void){
	U0FCR = 0x07;
	U0LCR = 0x83;
	U0DLL = 98;
	U0LCR = 0x03;
}


void Transmit(unsigned char ch){
	U0THR = ch;
	while((U0LSR & 0x20)==0);  //wait until transmitted i.e. while(TI==0); in 8051
}


void Transmit_String(unsigned char *ch){
	while('\0' != *ch){
		Transmit(*ch);
		ch++;
	}
}


unsigned char Receive(){
	while((U0LSR & 0x01)==0);  //wait until received i.e. while(RI==0); in 8051
	serial_data = U0RBR;

	return (serial_data);

}