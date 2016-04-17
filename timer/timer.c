#include<avr/io.h>
#define F_CPU 1000000
#include<util/delay.h>
#include<avr/adc.h>
void initpwm()
{
TCCR0|=(1<<WGM01)|(1<<COM00)|(1<<CS01);
DDRB=0b00001000;
}

void main()
{
initpwm();
adc_init();
	while(1)
	{
	int i=adc_read(0);
	i=i/4;
	OCR0=i;
	_delay_ms(10);
	
	}

}
