#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#include<avr/adc.h>

void main()
{
DDRC=0xff;
DDRA=0xf0;

adc_init();
unsigned int i=0,j=0;
while(1)
{
i=adc_read(0);
j=adc_read(1);

if(i>600)
{
if(j<600)
{
PORTA|=(1<<7);  // this is equivalent to PORTA|=0b10000000;
}
else if(j>600)
{
PORTA&=0b01111111;
}
}
}
}











