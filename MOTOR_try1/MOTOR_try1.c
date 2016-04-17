#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
main()
{
DDRB=0b11111111;
while(1)
{
PORTB=0b00000001;
_delay_ms(150);
PORTB=0b00000010;
_delay_ms(150);
PORTB=0b00000100;
_delay_ms(150);
PORTB=0b00001000;
_delay_ms(150);
}
}
