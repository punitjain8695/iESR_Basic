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
int i;
DDRC=0xff;
lcd_init();
while(1){

c11_0();
lcd_command(0x80);
lcd_data(0);



}
}

void c11_0()
{
lcd_command(0x40);


lcd_data(0x1f);
lcd_data(0x11);
lcd_data(0x11);
lcd_data(0x11);
lcd_data(0x1f);
lcd_data(0x11);
lcd_data(0x11);
lcd_data(0x11);
}
