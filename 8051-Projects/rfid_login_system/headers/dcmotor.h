#include <REG51F.H>


#ifndef _DCMOTOR_H
#define _DCMOTOR_H


//----------------------------------------DcMotors Switch Ports
sbit en12=P1^0;		//enable pin
sbit en34=P1^5;		//enable pin
sbit inp1=P1^1;		//inp1 for mtr 1
sbit inp2=P1^2;		//inp2 for mtr 1
sbit inp3=P1^3;		//inp1 for mtr 2
sbit inp4=P1^4;		//inp2 for mtr 2


//----------------------------------------//Preprocessor
#define en12	1
#define en34	1


//----------------------------------------//Function Prototypes
void forward(void);
void reverse(void);
void stop(void);


#endif
