#include<avr/io.h>
#define F_CPU 1000000
#include<util/delay.h>
#include<avr/adc.h>
#include<avr/lcd.h>
void initpwm()
{
TCCR0|=(1<<WGM01)|(1<<COM00)|(1<<CS01);
DDRB=0b00001000;
}

void main()
{
lcd_init();
lcd_command(0x8f);
initpwm();
adc_init();
	while(1)
	{
	int i=adc_read(0);
	i=i/4;
	lcd_number(i);
	OCR0=i;
	_delay_ms(10);
	
	}

}
