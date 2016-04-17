#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#include<avr/lcd.h>
main()
{
int rpm=0;
DDRC=0;
DDRB=255;
PORTB=0;
lcd_init();
lcd_command(0x80);

while(1)
{
while((PINA&0x01) == 0x01);
for (int i=0;i<10000;i++)
{

if((PINA&0x01) == 0x00)
{
while((PINA&0x01) == 0x00);
rpm++;
_delay_ms(1);
}
}
PORTB=0;
lcd_number(rpm/6);
}
}
