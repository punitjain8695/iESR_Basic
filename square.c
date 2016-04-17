#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
void main()
{
	DDRB=0b11111111;
	DDRC=0b11111111;
	while(1)
	{
		PORTC=0b01111110;
		PORTB=0b11111111;
		_delay_ms(5);
		PORTC=0b10000001;
		PORTB=0b10000001;
		_delay_ms(5);
	}

}
