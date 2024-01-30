#define Data P2
sbit rs = P3^0;
sbit en = P3^1;


void lcd_begin();
void lcd_cmd(int val);
void lcd_data(unsigned char ch);
void display(unsigned char msz[]);
void delay(unsigned int value);


void lcd_begin()
{
lcd_cmd(0x38);
lcd_cmd(0x0c);
lcd_cmd(0x06);
lcd_cmd(0x01);
}

void lcd_cmd(int val)
{
rs = 0;
Data = val;
en=1;
delay(2);
en=0;
}

void lcd_data(unsigned char ch)
{
rs=1;
Data = ch;
en=1;
delay(2);
en=0;
}

void display(unsigned char msz[])
{
	unsigned int k=0;
	for(k=0;msz[k]!='\0';k++)
	{
	lcd_data(msz[k]);
	}
}

void delay(unsigned int value)
{
unsigned int i,j=0;
for(i=0;i<=value;i++)
{
for(j=0;j<=1000;j++);
}
}

