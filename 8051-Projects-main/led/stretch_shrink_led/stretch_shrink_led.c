#include<REG51F.H>

void delay(unsigned long int time);
void stretch_shrink(unsigned int no_of_led); 

void main(){
	while(1){
		stretch_shrink(8);
	}
}

void stretch_shrink(unsigned int no_of_led){
	unsigned int i,j,a,b,half;
	a = 1;
	b = 1;
	if(no_of_led%4==0){
		half = no_of_led/2;
		a = a<<half;
		b = b<<half-1;
		P0 = a+b;
		delay(500);	
		for(i=1;i<half;i++){
			a = a<<1;
			b = b>>1;
			P0 = a+b;
			delay(500);

			if(i==half-1){
				for(j=half;j>2;j--){
					a = a>>1;
					b = b<<1;
					P0 = a+b;
					delay(500);
				}
			}
		}
	}
}

void delay(unsigned long int time){			  //Delay Function
	unsigned long int i;
	unsigned int j;

	for(i=0;i<time;i++){
		for(j=0;j<120;j++){
			
		}
	}
}