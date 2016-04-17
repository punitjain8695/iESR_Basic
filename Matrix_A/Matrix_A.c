#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
void main()
{
	DDRB=0b11111111;
	DDRC=0b11111111;
	while(2)
	{
	int i=0;	
	while(i<100)
	{
		PORTB=0b11000011;
		PORTC=0b10000000;
		_delay_ms(5);
		PORTB=0b01111110;
		PORTC=0b00110011;
		_delay_ms(5);
		i++;
	}
	PORTB=0b00000000;
	PORTC=0b00000000;
	PORTC<<1;
	PORTB<<1;
	_delay_ms(200);
	}

}
