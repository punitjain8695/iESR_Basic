#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
void main()
{
	DDRB=0b11111111;
	while(1)
	{
		PORTB=0b11111111;
		_delay_ms(1000);			// can be also like "_delay_us(X) for microseconds;"
		PORTB=0b00000000;			// can be like 255 in decimal or 0xff for hex
		_delay_ms(1000);
	}

}

