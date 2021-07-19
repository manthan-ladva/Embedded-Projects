#ifndef _UART_H
#define _UART_H

//----------------------------------------//Preprocessor
#define MAX_LEN_RFID_STRING		12	  //12 is the length of the RFID Number

//----------------------------------------//Function Prototypes
void Init_Uart(void);
void Transmit(unsigned char Abyte);
void Transmit_String(unsigned char *Abyte);
unsigned char Receive(void);
unsigned char *Receive_String(void);

#endif