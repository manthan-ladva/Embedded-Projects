#include <LPC214X.H>

void rotate(void);

long unsigned int ds5,ds1,ds2,ds3,ds4;

//void rotate();

void inc(void);
void delay(unsigned int k);
void disp(void);
//----------------------------------------------------------------------------------------------------------
unsigned int lut[]={0x00fc0000,0x00600000,0x00da0000,0x00f20000,
                    0x00660000,0x00b60000,0x00be0000,0x00e00000,
	                 0x00fe0000,0x00f60000
                              };
//----------------------------------------------------------------------------------------------------------

int main(void)
     {
	unsigned int i;
	VPBDIV=0X00;                     //60/4=15MHZ

            //	PINSEL0=0X00000000;

	PINSEL1=0X00000000;	 //gpio
	PINSEL2=0X00000000;	 //gpio

	IO0DIR=0X00FF0000;	//direction output P0.16 TO P0.23
	 ds1=ds2=ds3=ds4=0;
	while(1)
	{  
	  for(i=0;i<12;i++)
	         {
		 disp();
	         }
		inc();
//	rotate();
//	delay(10);
	}
}
//===================================================
void inc()
{
   ds1++;
	if(ds1==10)
	{	ds1=0;
		ds2=ds2+1;
		if(ds2==10)
		{	
			ds2=0;
			ds3=ds3+1;	
			if(ds3==10)
			{
				ds3=0;
				ds4=ds4+1;
				if(ds4==10)
					{
						ds4=0;
						ds1=0;
					}
			}
		}
	}

}
  /*
void rotate()
{
	ds5=ds1;
	ds1=ds2;
	ds2=ds3;
	ds3=ds4;
	ds4=ds5;
}	*/
//===============================================================
void disp()
{
	
	IO1DIR=0X00010000;	//output directon  p1.16
	IO0SET=lut[ds1];	//port 0 output PATTERN 0F ZER0(FC)
	delay(10);
	IO0CLR=lut[ds1];	
	delay(10);

	IO1DIR=0X00020000;	//output direction p1.17
	IO0SET=lut[ds2];
	delay(10);
	IO0CLR=lut[ds2];	
	delay(10);

	IO1DIR=0X00040000;	//output direction p1.18
	IO0SET=lut[ds3];
	delay(10);
	IO0CLR=lut[ds3];

	IO1DIR=0X00080000;	//output direction p1.19
	IO0SET=lut[ds4];
	delay(10);
	IO0CLR=lut[ds4];
}  
//==============================================
void delay(unsigned int k)
{
	unsigned int i,j;
	for(i=0;i<k;i++)
		for(j=0;j<1500;j++);
}
//==============================================
