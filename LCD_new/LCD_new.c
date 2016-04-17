#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#include<avr/lcd.h>

void main()
{

DDRC=255;
lcd_init();
lcd_command(0x80);
lcd_data('a');

}



