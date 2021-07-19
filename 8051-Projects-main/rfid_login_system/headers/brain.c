#include<REG51F.H>
#include<string.h>
#include "lcd.h"
#include "ssd.h"
#include "uart.h"
#include "delay.h"
#include "brain.h"
#include "dcmotor.h"


//-------------------Preprocessor Declaration---------------//
#define Newline		Transmit_String("\r\n");


//--------------------Function Declaration------------------//
int Compare_RFID(unsigned char *Str1);
void ssd_brain(void);
void lcd_brain(void);


//--------------------Variable Declaration------------------//
unsigned char ADefaltString[][MAX_LEN_RFID_STRING+1] = { 
	"510060156B4F",
	"51005ECF35F5",
};//	"5100702D979B",
//};												  //RFID Card Database
													   
unsigned int pass_value[] = {0xCE, 0xEE, 0xB6, 0xB6}; //PASS SSD Values
unsigned int fail_value[] = {0x8E, 0xEE, 0x60, 0x1C}; //FAIL SSD Values


//----------------------RFID Comparison Function----------------------//
int Compare_RFID(char *Str1){		   
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
		else{
			Status = 0;
		}
	}
	return (Status);
}


void ssd_brain(void){								 //Main Function for SSD Output
	unsigned char *AReceiveId;					 
	int i, Status = 0;

	Init_Uart();
	while(1) {
		AReceiveId = Receive_String();
		Status = Compare_RFID(AReceiveId);

		if (1 == Status) {
			for(i=0;i<100;i++){
				display(pass_value[0], pass_value[1], pass_value[2], pass_value[3]);
				forward();				   //DcMotor Forward
			}
			Delay(1000);
			stop();				//DcMotor Stop
			Delay(1000);
			reverse();		   //DcMotor Reverse
			Delay(1000);
			stop();
		}
		else {
			for(i=0;i<100;i++){
				display(fail_value[0], fail_value[1], fail_value[2], fail_value[3]);
			}
		}
	}
}


void lcd_brain(void){					//Main Function for LCD Output
	unsigned char *AReceiveId;
	int i, Status = 0;

	Init_Uart();
	init_lcd();

	display_lcd(0,0x83);
	lcd_string("Welcome To");
	display_lcd(0,0xC0);
	lcd_string("Manthan Security");

	Delay(500);							 

	while(1){
		display_lcd(0,0x01);
	
		display_lcd(0,0x83);
		lcd_string("Please Scan");
		display_lcd(0,0xC2);
		lcd_string("Your ID Card");
		
		for(i=0;i<3;i++){								//For-loop is used for TryAgain in Else part
			AReceiveId = Receive_String();
			Status = Compare_RFID(AReceiveId);			

			if (1 == Status) {
				display_lcd(0,0x01);
	
				display_lcd(0,0x81);
				lcd_string("Access Granted");
				display_lcd(0,0xC0);
				lcd_string("You May Proceed");

				forward();				   	//DcMotor Forward
				Delay(3000);
				stop();						//DcMotor Stop
				Delay(1000);
				reverse();		   			//DcMotor Reverse
				Delay(3000);
				stop();
	
				Delay(750);
				display_lcd(0,0x01);
				break;
			}
			else {
				char try_again[13] = "Try Again ";
				char c [][2] = {"1", "2", "3"};
				char of_3 [6] = " Of 3";
				strcat(try_again, c[i]);
				strcat(try_again, of_3);

				display_lcd(0,0x01);
	
				display_lcd(0,0x82);
				lcd_string("Access Denied");
				display_lcd(0,0xC0);
				lcd_string(try_again);

				if(i==2){
					Delay(500);
					break;
				}
			}

		}
	}
}
