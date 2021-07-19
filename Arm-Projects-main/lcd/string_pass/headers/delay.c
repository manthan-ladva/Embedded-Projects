//#include <LPC214X.H>
#include "delay.h"


void Delay(unsigned int time){
	unsigned int i,j;
	for (i=0;i<=time;i++) for(j=0;j<=1500;j++);
}
