#include<stdio.h>

void main()
{
    unsigned long int value_array[] = {0xFC, 0x0C, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFE, 0xF6}; //0123456789
	int i;

	for(i=9;i>=0;i--){
		//ssd_switch(1,1,1,0);
		printf("%x",value_array[i]);
		//delay(100);
		//P0 = 0x00;
	}
}
