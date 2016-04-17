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
while(1)
{
if( (PINA & 0x01) == 0x01)
{
char A[40]="S1: Light Surface";
lcd_command(0x80);
lcd_string_forward(A);
}
else 
{
char A[40]="S1: Dark Surface";
lcd_command(0x80);
lcd_string_forward(A);
}

if( (PINA & 0x02) == 0x02)
{
char B[40]="S2: Light Surface";
lcd_command(0xc0);
lcd_string_forward(B);
}
else 
{
char A[40]="S2: Dark Surface";
lcd_command(0xc0);
lcd_string_forward(A);
}

_delay_ms(5);

}
}
