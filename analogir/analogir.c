#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#include<avr/lcd.h>

void adc_init();
unsigned int adc_read(char ch);

void main()
{
DDRC=0xff;
lcd_init();
lcd_command(0x80);
lcd_string("ADC1 Value");
lcd_command(0xc0);
lcd_string("ADC2 Value");
adc_init();
unsigned int i=0,j=0;
while(1)
{
i=adc_read(0);
j=adc_read(1);
lcd_command(0x8c);
lcd_data(32);
lcd_data(32);
lcd_data(32);
lcd_data(32);
lcd_command(0x8f);
lcd_number(i);
lcd_command(0xcc);
lcd_data(32);
lcd_data(32);
lcd_data(32);
lcd_data(32);
lcd_command(0xcf);
lcd_number(j);
_delay_ms(1000);
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










