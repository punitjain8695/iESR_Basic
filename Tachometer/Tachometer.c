#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#include<avr/lcd.h>
main()
{
DDRC=255;
DDRB=255;
DDRA=0;
PORTB=0;
lcd_init();

lcd_command(0x80);
lcd_string("R P M = ");

_delay_ms(500);

while(1)
{

while((PINA&0x01) == 0x00);

int rpm=0;
int r=0;

for (int i=0;i<10000;i++)
{
PORTB=1;
if((PINA&0x01) == 0x01)
{
while((PINA&0x01) == 0x01);
r++;
}
_delay_ms(1);
}

rpm=r*6;
lcd_command(0x8f);
lcd_number(rpm);

PORTB=0;
_delay_ms(60000);
}
}
