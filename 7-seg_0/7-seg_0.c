#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
void main()
{
	DDRB=0b11111111;
	PORTB=0b00000000;

}
