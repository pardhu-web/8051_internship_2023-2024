//  Program to blink the LEDs. LEDs are connected to port 0.

#include<reg51.h>

void delay(int time)        //This function produces a delay in msec.
{
    int i,j;
    for(i=0;i<time;i++)
     for(j=0;j<1275;j++);
}

void main()
{
     unsigned char i,x=0x01;
	 P0=0x0ff;
	 for(i=0;i<=7;i++)
	 {
	 	delay(50);
		P0=~x;
		x<<=1;
	 }
	 delay(50);
	 P0=0x55;
     while(1)
     {
         
          delay(50);
          P0=~P0;
          
     }
}
