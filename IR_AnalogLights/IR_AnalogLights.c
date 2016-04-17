#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#include<avr/lcd.h>

void adc_init();
unsigned int adc_read(char ch);

void main()
{
DDRB=0xff;

adc_init();
unsigned int i=0,k=0;
while(1)
{
i=adc_read(0);
k=i/128;
switch(k)
{
	case 0 : 
	PORTB=0x01;
	break;
	case 1 : 
	PORTB=0x03;
	break;
	case 2 : 
	PORTB=0x07;
	break;
	case 3 :
	PORTB=0x0f;
	break;
	case 4 : 
	PORTB=0x1f;
	break;
	case 5 : 
	PORTB=0x3f;
	break;
	case 6 : 
	PORTB=0x7f;
	break;
	case 7 : 
	PORTB=0xff;
	break;
	default :
	PORTB=0;
	break;
}
}
}

void adc_init()
{
ADMUX=(1<<REFS0);
ADCSRA=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}

unsigned int adc_read(char ch)
{
ADMUX=0x40|ch;
ADCSRA|=(1<<ADSC);
while((ADCSRA&0b00010000)==0);
ADCSRA|=(1<<ADIF);
return ADC;
}
