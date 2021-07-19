#include <LPC214X.H>
#include <string.h>
#include "brains.h"
#include "ssd.h"
#include "uart.h"
#include "delay.h"
#include "lcd.h"


//-------------------Preprocessor Declaration---------------//
#define Newline		Transmit_String("\r\n");


//--------------------Variable Declaration------------------//
char ADefaltString[][MAX_LEN_RFID_STRING+1] = { 
	"510060156B4F",
	"51005ECF35F5",
};//	"5100702D979B",
//};												  						  //RFID Card Database

unsigned int pass_value[] = {0x00CE0000, 0x00EE0000, 0x00B60000, 0x00B60000}; //PASS SSD Values
unsigned int fail_value[] = {0x008E0000, 0x00EE0000, 0x00600000, 0x001C0000}; //FAIL SSD Values


//----------------------RFID Comparison Function----------------------//
int Compare_RFID(const char *Str1){		   
	int Idx, Status = 0;							      //Compare RFID Function
	for (Idx=0; Idx<sizeof(ADefaltString)/sizeof(ADefaltString[0]); Idx++) {	 
		
		Transmit_String(Str1);			   //Here Idx<length of 2 dimension string
		Newline;
		Transmit_String(ADefaltString[Idx]);
		Newline;
		
		if(0 == strcmp(Str1, ADefaltString[Idx])){
			Status = 1;
			break;
		}
		else Status = 0;
	}
	return (Status);
}


void ssd_brain(void){								 //Main Function for SSD Output
	char *AReceiveId;					 
	int i, Status = 0;

	Init_Uart();
	while(1) {
		AReceiveId = Receive_String();
		Status = Compare_RFID(AReceiveId);

		if (1 == Status) {
			for(i=0;i<100;i++) display_ssd(pass_value[0], pass_value[1], pass_value[2], pass_value[3]);
		}
		else {
			for(i=0;i<100;i++) display_ssd(fail_value[0], fail_value[1], fail_value[2], fail_value[3]);
		}
	}
}


void lcd_brain(void){								 //Main Function for LCD Output
	char *AReceiveId;
	int i, Status = 0;

	Init_Uart();
	lcd_init();

	Delay(15);
	display_lcd(0,0x00000083);
	lcd_string("Welcome To");
	display_lcd(0,0x000000C0);
	lcd_string("Manthan Security");

	Delay(3000);	

	while(1){
		display_lcd(0,0x00000001);
	
		display_lcd(0,0x00000083);
		lcd_string("Please Scan");
		display_lcd(0,0x000000C2);
		lcd_string("Your ID Card");

		for(i=0;i<3;i++){								//For-loop is used for TryAgain in Else part
			AReceiveId = Receive_String();
			Status = Compare_RFID(AReceiveId);			

			if (1 == Status) {
				display_lcd(0,0x00000001);
	
				display_lcd(0,0x00000081);
				lcd_string("Access Granted");
				display_lcd(0,0x000000C0);
				lcd_string("You May Proceed");
	
				Delay(2500);
				display_lcd(0,0x00000001);
				break;
			}
			else {
				char try_again[13] = "Try Again ";
				char c [][2] = {"1", "2", "3"};
				char of_3 [6] = " Of 3";
				strcat(try_again, c[i]);
				strcat(try_again, of_3);

				display_lcd(0,0x00000001);
	
				display_lcd(0,0x00000082);
				lcd_string("Access Denied");
				display_lcd(0,0x000000C0);
				lcd_string(try_again);

				if(i==2){
					Delay(2500);
					break;
				}
			}
		}
	}
}
