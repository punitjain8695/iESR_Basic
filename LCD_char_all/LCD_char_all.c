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

void lcd_string(unsigned char *str)
{
char d=0;

while(str[d]!='\0')
{
lcd_data(str[d]);
d++;
_delay_ms(350);
}
}




void main()
{
int i,j,a,b,c;
DDRC=0xff;
lcd_init();

while(1)
{

for(i=0;i<255;i++)
{
j=i%100;
a=i/100;
b=j/10;
c=j%10;

lcd_command(0x80);
lcd_data(i);
lcd_data(' ');
lcd_data(48+a);
lcd_data(48+b);
lcd_data(48+c);
_delay_ms(1000);

lcd_command(0x80);
lcd_data(' ');
lcd_data(' ');
lcd_data(' ');
lcd_data(' ');
lcd_data(' ');
_delay_ms(500);
}

}

}







