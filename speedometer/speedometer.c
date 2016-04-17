#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#include<avr/lcd.h>
main()
{
DDRC=0xff;
DDRB=255;
DDRA=0;
lcd_init();
lcd_command(0x80);
while(1)
{
int speed=0;
int r=0;

while((PINA&0x01)==0);
PORTB=0x0a;
while((PINA&0x01)==1)
{
_delay_ms(1);
r++;
}
PORTB=0;
speed=1*1000/r;
lcd_command(0x80);
lcd_number(speed);
_delay_ms(1000);
lcd_command(0x01);
}

}
