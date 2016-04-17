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
char1();
char3();
char6();
char7();
char8();
lcd_command(0xc0);
lcd_data(0);
lcd_data(2);
lcd_data(5);
lcd_data(6);
lcd_data(' ');
lcd_data(' ');
lcd_data(7);
lcd_data(2);

char2();
char4();
char5();
lcd_command(0x80);
lcd_data(1);
lcd_data(3);
lcd_data(4);
lcd_data(1);
lcd_data(' ');
lcd_data(' ');
lcd_data(' ');
lcd_data(1);

_delay_ms(1000);

char9();
_delay_ms(1000);

}

void char1()
{
lcd_command(0x40);

lcd_data(0b00010001);
lcd_data(0b00010001);
lcd_data(0b00010001);
lcd_data(0b00001111);
lcd_data(0b00000001);
lcd_data(0b00000001);
lcd_data(0b00001011);
lcd_data(0b00000111);


}


void char2()
{
lcd_command(0x48);

lcd_data(0x00);
lcd_data(0x00);
lcd_data(0x00);
lcd_data(0x00);
lcd_data(0x00);
lcd_data(0x00);
lcd_data(0x00);
lcd_data(0x1f);
}

void char3()
{
lcd_command(0x50);

lcd_data(0b00000001);
lcd_data(0b00000001);
lcd_data(0b00011111);
lcd_data(0b00010101);
lcd_data(0b00001001);
lcd_data(0b00000001);
lcd_data(0b00000001);
lcd_data(0b00000001);
}

void char4()
{
lcd_command(0x58);

lcd_data(0b00000000);
lcd_data(0b00000000);
lcd_data(0b00000000);
lcd_data(0b00000000);
lcd_data(0b00000001);
lcd_data(0b00000010);
lcd_data(0b00000100);
lcd_data(0b00011111);
}

void char5()
{
lcd_command(0x60);

lcd_data(0b00000000);
lcd_data(0b00000000);
lcd_data(0b00000000);
lcd_data(0b00000000);
lcd_data(0b00010000);
lcd_data(0b00001000);
lcd_data(0b00001000);
lcd_data(0b00011111);
}


void char6()
{
lcd_command(0x68);

lcd_data(0b00001000);
lcd_data(0b00001000);
lcd_data(0b00001000);
lcd_data(0b00001000);
lcd_data(0b00001000);
lcd_data(0b00001000);
lcd_data(0b00001000);
lcd_data(0b00001000);
}

void char7()
{
lcd_command(0x70);

lcd_data(0b00000001);
lcd_data(0b00000001);
lcd_data(0b00000001);
lcd_data(0b00001111);
lcd_data(0b00010001);
lcd_data(0b00010001);
lcd_data(0b00010001);
lcd_data(0b00001001);
}

void char8()
{
lcd_command(0x78);

lcd_data(0b00000001);
lcd_data(0b00000001);
lcd_data(0b00000001);
lcd_data(0b00010111);
lcd_data(0b00010101);
lcd_data(0b00001101);
lcd_data(0b00000001);
lcd_data(0b00000001);
}

void char9()
{
lcd_command(0x60);

lcd_data(0b00000000);
lcd_data(0b00000000);
lcd_data(0b00000000);
lcd_data(0b00000000);
lcd_data(0b00010010);
lcd_data(0b00001010);
lcd_data(0b00001100);
lcd_data(0b00011111);
lcd_command(0x86);
lcd_data(4);
}
