#include<REG51F.H>
#include<string.h>
#include "headers\lcd.h"
#include "headers\ssd.h"
#include "headers\uart.h"
#include "headers\delay.h"

void init_gsm(void);

void main(void){
	char temp, whole_string[8];
	char on[3] = "on";
	char of[3] = "of";
	unsigned int i;
	Delay(1000);
	init_uart();
	//init_lcd();
	init_gsm();
	P0=0x00;

	while(1){
START: 
		while(Receive() != '+');
		
		temp = Receive();
		if(temp != 'C') goto START;

		temp = Receive();
		if(temp != 'M') goto START;

		temp = Receive();
		if(temp != 'T') goto START;

		for(i=0;i<45;i++) temp = receive();
		
		for(i=0;i<8;i++){
			while(RI ==0);
			RI=0;
			whole_string[i] = SBUF;
		}	
		whole_string[i] = '\0';

		Transmit_String(whole_string);
		Transmit_String("\r\n");
		Transmit_String(on);

//		if(0 == strcmp(whole_string, on)){
//			P0 = 0xF0;
//			Delay(1000);
//		}
//		if(0 == strcmp(whole_string, of)){
//			P0 = 0x01;
//			Delay(1000);
//		}
	}
}

void init_gsm(void){
	Transmit_String("AT");	 //Initial AT Command
	Transmit(0x0D);			 //ASCII of Enter
	Delay(20);

	Transmit_String("ATE0"); //Echo Disable
	Transmit(0x0D);
	Delay(20);

	Transmit_String("AT+CMGF=1");   //SMS Mode
	Transmit(0x0D);
	Delay(20);

	Transmit_String("AT+CNMI=2,2,0,0,0");  //Terminal show not saved sms only
	Transmit(0x0D);
	Delay(20);
}


