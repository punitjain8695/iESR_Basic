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

void lcd_string_back(unsigned char *str)
{
char d=strlen(str)-1;

while(d>0)
{
lcd_data(str[d]);
d--;
_delay_ms(1);
}
}





void main()
{
unsigned char c;
DDRC=0xff;
lcd_init();
char A[40]="Type your text here I wou ";
int l = 0x80 + (strlen(A)-2);
while(1)
{

for(c=0x8f;c>=0x80;c--)
{
lcd_command(c);
lcd_string_forward(A);
_delay_ms(350);
lcd_command(0x01);
_delay_ms(15);
}
for(c=l;c>=0x80;c--)
{
lcd_command(0x04);
lcd_command(c);
lcd_string_back(A);
_delay_ms(350);
lcd_command(0x01);
_delay_ms(5);
}


}

}
