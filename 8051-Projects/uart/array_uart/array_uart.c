#include <REG51F.H>
#include <string.h>

unsigned char i;
unsigned char table[]="Hello I Am Manthan.I am Embedded Engineer";

void init_uart(void){
	TMOD = 0x20;
	TH1 = 0xFD;
	TR1	= 1;
	SCON = 0x50;
}

void tx(unsigned char ch){
	SBUF = ch;	
	while(TI == 0);
	TI = 0;
}

void main(void){
	unsigned int length;
	length = strlen(table);
	init_uart();
	for(i=0;i<length;i++){
		tx(table[i]);
//		if(table[i] == '.'){
//			tx("\r");
//			tx("\n");
//		}
	}
	while(1);
}