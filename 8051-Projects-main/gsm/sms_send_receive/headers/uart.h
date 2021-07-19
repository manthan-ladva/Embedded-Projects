#ifndef _UART_H
#define _UART_H

//----------------------------------------//Preprocessor
#define MSG_LENGTH		99

//----------------------------------------//Function Prototypes
void Init_Uart(void);
void Transmit(char Abyte);
void Transmit_String(char *Abyte);
char Receive(void);
char *Receive_String(void);

#endif