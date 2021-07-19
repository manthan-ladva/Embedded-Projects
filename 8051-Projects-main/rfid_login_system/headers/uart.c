#include<REG51F.H>
#include<string.h>
#include "uart.h"


//----------------------UART Functions----------------------//
void Init_Uart(void){						     //UART INIT Function
	TMOD = 0x20;
	TH1 = 0xFD;
	TR1 = 1;
	SCON = 0x50;
}


void Transmit(unsigned char Abyte){             //UART Transmit Function
	SBUF = Abyte;
	while(0 == TI);      //wait until transmitted 
	TI = 0;
}


void Transmit_String(unsigned char *Abyte){		//UART Transmit String Function
	while('\0' != *Abyte){
		Transmit(*Abyte);
		Abyte++;
	}
}


unsigned char Receive(void){ 		 	        //UART Receive Function
	unsigned char Abyte;

	while(0 == RI);      //wait until received
	Abyte = SBUF;
	RI = 0;

	return (Abyte);
}


unsigned char *Receive_String(void){ 			//UART Receive String Function
	static unsigned char AString[MAX_LEN_RFID_STRING + 1];
	int Idx = 0;

	memset(AString, 0, sizeof(AString)); //Used to clear the string
	for(Idx=0; Idx<MAX_LEN_RFID_STRING; Idx++){
		AString[Idx] = Receive();
	}
	AString[Idx] = '\0';

	return (AString);
}