#include "delay.h"
#include "dcmotor.h"


void forward(void){
	inp1 = 1;	 //forward
	inp2 = 0;
	inp3 = 1;
	inp4 = 0;
}


void reverse(void){
	inp1 = 0;	  //reverse
	inp2 = 1;
	inp3 = 0;
	inp4 = 1;
} 


void stop(void){
	inp1 = 0;	 //stop
	inp2 = 0;
	inp3 = 0;
	inp4 = 0;
}
