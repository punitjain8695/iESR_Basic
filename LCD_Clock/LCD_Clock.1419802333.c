#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#define rs 0
#define rw 0
#define LCD PORTC
#define en 2
char *str;

void lcd_init()
{
lcd_command(0X02);		// home screen
lcd_command(0X28);		// 4 bit mode
lcd_command(0X0c);		// screen on cursor off
lcd_command(0X06);		//auto increment
}

void lcd_command(char cmd)
{

LCD=(cmd&0xf0);
LCD&=~(1<<rs);
LCD&=~(1<<rw);
LCD|=(1<<en);
_delay_ms(10);		
LCD&=~(1<<en);

LCD=(cmd<<4)&0xf0;
LCD|=(1<<en);
_delay_ms(10);
LCD&=~(1<<en);

}

void lcd_data(char data)
{
LCD=data&0xf0;
LCD|=(1<<rs);
LCD|=(1<<en);
_delay_ms(10);
LCD&=~(1<<en);

LCD=(data<<4)&0xf0;
LCD|=(1<<rs);
LCD|=(1<<en);
_delay_ms(10);
LCD&=~(1<<en);
}

void lcd_string(unsigned char *str)
{
char d=0;

while(str[d]!='\0')
{
lcd_data(str[d]);
d++;
_delay_ms(10);
}
}

void lcd_number(unsigned int no)
{
lcd_command(0x04);
int value=0;
value=no%10;
lcd_data(48+value);
value=no/10;
lcd_data(48+value);

lcd_command(0x06);
}



void main()
{
int i,hr,min,sec;
DDRC=0xff;

lcd_init();
lcd_command(0x85);
lcd_string(":");
lcd_command(0x8A);
lcd_string(":");
lcd_command(0x8E);
lcd_string("S");
lcd_command(0x89);
lcd_string("M");
lcd_command(0x84);
lcd_string("H");

for (hr=1;hr<24;hr++)
{
for (min=1;min<60;min++)
{
for (sec=0;sec<60;sec++)
{
lcd_command(0x8C);
lcd_number(sec);
_delay_ms(900);
}
lcd_command(0x87);
lcd_number(min);
}
lcd_command(0x82);
lcd_number(hr);
}

}
