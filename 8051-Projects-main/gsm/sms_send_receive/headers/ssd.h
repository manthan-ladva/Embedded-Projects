#include<REG51F.H>

#ifndef _SSD_H
#define _SSD_H

//----------------------------------------SSD Switch Ports
sbit SWITCH0 = P2^0;
sbit SWITCH1 = P2^1;
sbit SWITCH2 = P2^2;
sbit SWITCH3 = P2^3;

//----------------------------------------//Function Prototypes
void ssd_switch(unsigned int a, unsigned int b, unsigned int c, unsigned int d);
void display(unsigned int your_value1, unsigned int your_value2, unsigned int your_value3, unsigned int your_value4);

#endif