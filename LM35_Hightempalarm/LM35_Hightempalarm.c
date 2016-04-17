#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#include<avr/adc.h>
#include<avr/lcd.h>

void main()
{
DDRC=0xff;
DDRA=0xf0;

lcd_init();
lcd_command(0x80);
lcd_string("Temp:");
lcd_command(0xc0);
lcd_string("ADC value");
adc_init();

unsigned int i=0;
unsigned int t=0;

while(1)
{
i=adc_read(0);

t=(i*500)/1023;



if (t>35)
{
while(t>35)
{
PORTA|=(1<<7);
lcd_data(0x01);
_delay_ms(1000);

lcd_command(0x80);
lcd_string("Alert");
lcd_command(0xc0);
lcd_string("High Temperature");

PORTA&=0b01111111;

_delay_ms(1000);
}
}

else
{
lcd_command(0x8f);
lcd_number(t);
lcd_command(0xcf);
lcd_number(i);

}
}
}
