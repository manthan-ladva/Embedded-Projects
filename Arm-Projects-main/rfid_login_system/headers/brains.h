#ifndef _BRAINS_H
#define _BRAINS_H


#include "uart.h"


//-------------------Preprocessor Declaration---------------//
#define Newline		Transmit_String("\r\n");

/*
//--------------------Variable Declaration------------------//
extern char ADefaltString[][MAX_LEN_RFID_STRING+1] = { 
	"510060156B4F",
	"51005ECF35F5",
};//	"5100702D979B",
//};												  						  //RFID Card Database

extern unsigned int pass_value[] = {0x00CE0000, 0x00EE0000, 0x00B60000, 0x00B60000}; //PASS SSD Values
extern unsigned int fail_value[] = {0x008E0000, 0x00EE0000, 0x00600000, 0x001C0000}; //FAIL SSD Values 
*/

//----------------------------------------//Function Prototypes
void ssd_brain(void);
void lcd_brain(void);
int Compare_RFID(const char *Str1);


#endif
