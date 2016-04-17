#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>

void main()
{
DDRD=255;
PORTD=0b10111101;

}
