#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#include<avr/lcd.h>

void main()
{
DDRA=0xf0;
DDRB=255;
DDRC=255;
lcd_init();
lcd_command(0x80);
while(1)
{

PORTA=0xef;
_delay_ms(10);
if((PORTA&0x01)==0x00)
{PORTB=1;
lcd_data(65);}
if((PORTA&0x02)==0x00)
{PORTB=2;
lcd_data(66);}
if((PORTA&0x04)==0x00)
{PORTB=3;
lcd_data(67);}
if((PORTA&0x08)==0x00)
{PORTB=4;
lcd_data(68);}

PORTA=0xdf;
_delay_ms(10);
if((PORTA&0x01)==0x00)
{PORTB=5;
lcd_data(69);}
if((PORTA&0x02)==0x00)
{PORTB=6;
lcd_data(70);}
if((PORTA&0x04)==0x00)
{PORTB=7;
lcd_data(71);}
if((PORTA&0x08)==0x00)
{PORTB=8;
lcd_data(72);}

PORTA=0xbf;
_delay_ms(10);
if((PORTA&0x01)==0x00)
{PORTB=9;
lcd_data(73);}
if((PORTA&0x02)==0x00)
{PORTB=10;
lcd_data(74);}
if((PORTA&0x04)==0x00)
{PORTB=11;
lcd_data(75);}
if((PORTA&0x08)==0x00)
{PORTB=12;
lcd_data(76);}

PORTA=0x7f;
_delay_ms(10);
if((PORTA&0x01)==0x00)
{PORTB=13;
lcd_data(77);}
if((PORTA&0x02)==0x00)
{PORTB=14;
lcd_data(78);}
if((PORTA&0x04)==0x00)
{PORTB=15;
lcd_data(79);}
if((PORTA&0x08)==0x00)
{PORTB=16;
lcd_data(80);}
}
}
