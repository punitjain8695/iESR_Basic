#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
main()
{
int p= 5,n=10;
DDRA=0;
DDRB=255;
while(1)
{
if(((PINA & 0x01) == 0x01) && ((PINA & 0x02) == 0x02))
{
PORTB=0b00000101;
_delay_ms(p);
PORTB=0;
_delay_ms(n);
}
else if(((PINA & 0x01) == 0x01) && ((PINA & 0x02) == 0x00))
{
PORTB=0b00000001;
_delay_ms(p);
PORTB=0;
_delay_ms(n);
}
else if(((PINA & 0x01) == 0x00) && ((PINA & 0x02) == 0x02))
{
PORTB=0b00000100;
_delay_ms(p);
PORTB=0;
_delay_ms(n);
}
else if(((PINA & 0x01) == 0x00) && ((PINA & 0x02) == 0x00))
{
PORTB=0b00000000;
_delay_ms(p);
PORTB=0;
_delay_ms(n);
}
}
}
