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

void main()
{
char c;
int i=75;

DDRC=0xff;
lcd_init();

c0();
c1();
c2();
c3();
c4();
c5();

while(1){

lcd_command(0x80);
lcd_data(0);
_delay_ms(1500);
for(c=0x81;c<0x8f;c++)
{
lcd_command(c);
lcd_data(1);
_delay_ms(i);

lcd_command(c);
lcd_data(2);
_delay_ms(i);

lcd_command(c);
lcd_data(3);
_delay_ms(i);

lcd_command(c);
lcd_data(4);
_delay_ms(i);

lcd_command(c);
lcd_data(32);
_delay_ms(i);
}
lcd_command(c);
lcd_data(4);
_delay_ms(5*i);
for(c=0x8f;c>0x80;c--)
{
lcd_command(c);
lcd_data(4);
_delay_ms(i);

lcd_command(c);
lcd_data(3);
_delay_ms(i);

lcd_command(c);
lcd_data(2);
_delay_ms(i);

lcd_command(c);
lcd_data(1);
_delay_ms(i);

lcd_command(c);
lcd_data(32);
_delay_ms(i);
}
int j=0;
for(j=0;j<10;j++)
{
_delay_ms(250);
lcd_command(0x80);
lcd_data(5);
_delay_ms(250);
lcd_command(0x80);
lcd_data(0);
}
_delay_ms(250);
lcd_command(0x80);
lcd_data(32);
_delay_ms(1000);

}
}

void c0()
{
lcd_command(0x40);


lcd_data(0b00001000);
lcd_data(0b00010100);
lcd_data(0b00001110);
lcd_data(0b00011101);
lcd_data(0b00011101);
lcd_data(0b00001110);
lcd_data(0b00010100);
lcd_data(0b00001000);
}

void c1()
{
lcd_command(0x48);


lcd_data(0b00000000);
lcd_data(0b00000000);
lcd_data(0b00000000);
lcd_data(0b00011000);
lcd_data(0b00011000);
lcd_data(0b00000000);
lcd_data(0b00000000);
lcd_data(0b00000000);
}
void c2()
{
lcd_command(0x50);

lcd_data(0b00000000);
lcd_data(0b00000000);
lcd_data(0b00000000);
lcd_data(0b00001100);
lcd_data(0b00001100);
lcd_data(0b00000000);
lcd_data(0b00000000);
lcd_data(0b00000000);
}
void c3()
{
lcd_command(0x58);


lcd_data(0b00000000);
lcd_data(0b00000000);
lcd_data(0b00000000);
lcd_data(0b00000110);
lcd_data(0b00000110);
lcd_data(0b00000000);
lcd_data(0b00000000);
lcd_data(0b00000000);
}
void c4()
{
lcd_command(0x60);


lcd_data(0b00000000);
lcd_data(0b00000000);
lcd_data(0b00000000);
lcd_data(0b00000011);
lcd_data(0b00000011);
lcd_data(0b00000000);
lcd_data(0b00000000);
lcd_data(0b00000000);
}

void c5()
{
lcd_command(0x68);


lcd_data(0b00010100);
lcd_data(0b00001000);
lcd_data(0b00010001);
lcd_data(0b00000010);
lcd_data(0b00000010);
lcd_data(0b00010001);
lcd_data(0b00001000);
lcd_data(0b00010100);
}
