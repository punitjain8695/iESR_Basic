#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
void main()
{
	DDRB=0b11111111;
	DDRC=0b11111111;
	int c=0;
	while(1){
	while(c<100)
	{
		PORTC=0b01111110;
		PORTB=0b11111111;
		_delay_ms(1);
		PORTC=0b10000001;
		PORTB=0b10000001;
		_delay_ms(1);
		c++;
	}
	int d=0;
	while(d<100)
	{
		PORTB=0b01111110;
		PORTC=0b10111101;
		_delay_ms(1);
		PORTB=0b01000010;
		PORTC=0b10000001;
		_delay_ms(1);
		d++;
	}
	}

}
