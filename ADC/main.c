#include<reg51.h>
#include"lcd.h"
#define ADC_data P1
sbit sc = P3^2;

void convert(unsigned int x);

void main()
{
//ADC_data = 0x00;
lcd_begin();
lcd_cmd(0x01);
lcd_cmd(0x80);
display("Welcome");
delay(10);
	while(1)
	{
	lcd_cmd(0xc0);
	sc = 1; 
	delay(10);
	sc=0;
	convert(ADC_data);
	delay(1);	
	}
}

void convert(unsigned int x)
{
 int d1,d2,d3;
 d3 = x%10;
 x = x/10;
 d2 = x%10;
 d1 = x/10;

 lcd_data(d1+48);
 lcd_data(d2+48);
 lcd_data(d3+48);
}




