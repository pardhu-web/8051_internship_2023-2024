#include<reg51.h>

void serial_begin();
void serial_send(char ch);
char serial_read();
void delay(unsigned int x);
void serial_print(char msz[]);

void main()
{
serial_begin();
	while(1)
	{
 /*
	serial_print("Hello  ");  delay(100);
	   serial_send('W');
	   delay(100);
	   serial_send('E');
	   
	   delay(100);
	   serial_send('L');
	   
	   delay(100);
	   serial_send('C');
	   
	   delay(100);
	   serial_send('O');
	   
	   delay(100);
	   serial_send('M');
	   
	   delay(100);
	   serial_send('E');  */

	   char Data  = serial_read();
	   if(Data == 'f')
	   {
	   serial_print("Robot in forward direction");
	   }

	   else
	   {
	   serial_print("Invalid command");
	   }

	}

}


void serial_begin()
{
TMOD = 0X20;
SCON = 0X50;
TH1 = 0XFD;
TR1 = 1;
}


void serial_send(char ch)
{
SBUF  = ch;
while(TI == 0);
TI=0;
}

void serial_print(char msz[])
{
unsigned int a=0;
for(a=0;msz[a] != '\0';a++)
{
serial_send(msz[a]);
}
}


char serial_read()
{
 RI = 0;
 while(RI == 0);
 return SBUF;
}

void delay(unsigned int x)
{
unsigned int i,j=0;
for(i=0;i<=x;i++)
{
for(j=0;j<=1000;j++);
}

}