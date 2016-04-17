#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#include<string.h>
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
_delay_ms(2);		
LCD&=~(1<<en);

LCD=(cmd<<4)&0xf0;
LCD|=(1<<en);
_delay_ms(2);
LCD&=~(1<<en);

}

void lcd_data(char data)
{
LCD=data&0xf0;
LCD|=(1<<rs);
LCD|=(1<<en);
_delay_ms(2);
LCD&=~(1<<en);

LCD=(data<<4)&0xf0;
LCD|=(1<<rs);
LCD|=(1<<en);
_delay_ms(2);
LCD&=~(1<<en);
}

void lcd_string_forward(unsigned char *str)
{
char d=0;

while(str[d]!='\0')
{
lcd_data(str[d]);
d++;
_delay_ms(1);
}
}



void main()
{
DDRA=0;
DDRC=255;



lcd_init();
int i=0,j=0;
while(1)
{
if( (PINA & 0x01) == 0x01)
{
while( (PINA & 0x01) == 0x01);
i++;
}

if( (PINA & 0x02) == 0x02)
{
while( (PINA & 0x02) == 0x02);
j++;
}

lcd_command(0x80);
lcd_string_forward("Sensor In : ");
lcd_number(i);
lcd_command(0xc0);
lcd_string_forward("Sensor out : ");
lcd_number(j);

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

