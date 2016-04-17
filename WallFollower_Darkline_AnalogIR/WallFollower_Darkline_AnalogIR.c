#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#include<avr/lcd.h>

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

//Left Wall follower
main()
{
adc_init();
lcd_init();

unsigned int i=255,j=255;
int p= 5,n=10;
DDRA=0;
DDRB=255;
DDRC=255;
PORTB=0;
while(1)
{
i=adc_read(0);	//Left IR
j=adc_read(1);	//Front IR
if(j<600)
{
if(i<400)
{PORTB=0b00000001;
//while((j<600)&&(i<400));
_delay_ms(p);
PORTB=0;
_delay_ms(n);}
if(i>400 && i<800)
{PORTB=0b00000101;
//while((j<600)&&(i>400 && i<800));
_delay_ms(p);
PORTB=0;
_delay_ms(n);}
if(i>800)
{PORTB=0b00000100;
//while((j<600)&&(i>800));
_delay_ms(p);
PORTB=0;
_delay_ms(n);}
}
else if(j>600)
{
PORTB=0b00000110;
//while(j>600);
_delay_ms(p);
PORTB=0;
_delay_ms(n);
}

}
}


