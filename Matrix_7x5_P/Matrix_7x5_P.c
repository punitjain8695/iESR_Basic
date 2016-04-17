#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
void main()
{
	DDRB=0b11111111;
	DDRC=0b11111111;
	while(1)
	{
		a=0;
		while(
		PORTB=0b11111111;
		PORTC=0b11111100;
		_delay_ms(1);
		PORTB=0b11001100;
		PORTC=0b11000011;
		_delay_ms(1);
		PORTB=0b01111000;
		PORTC=0b10111111;
		_delay_ms(1);
		PORTB=0b00110000;
		PORTC=0b01111111;
		_delay_ms(1);
	}

}
