#include "uart.h"
#include <string.h>
#include <LPC214X.H>

void Init_Uart(void){
	U0FCR = 0x07;
	U0LCR = 0x83;
	U0DLL = 98;
	U0LCR = 0x03;
}


void Transmit(char ch){
	U0THR = ch;
	while((U0LSR & 0x20)==0);  //wait until transmitted i.e. while(TI==0); in 8051
}


void Transmit_String(const char *ch){
	while('\0' != *ch){
		Transmit(*ch);
		ch++;
	}
}


char Receive(void){
	char serial_data=0;

	while((U0LSR & 0x01)==0);  //wait until received i.e. while(RI==0); in 8051
	serial_data = U0RBR;

	return (serial_data);

}


char *Receive_String(void){
	static char AString[MAX_LEN_RFID_STRING + 1];
	int Idx = 0;

	memset(AString, 0, sizeof(AString)); //Used to clear the string
	for(Idx=0; Idx<MAX_LEN_RFID_STRING; Idx++){
		AString[Idx] = Receive();
	}
	AString[Idx] = '\0';

	return (AString);
}
