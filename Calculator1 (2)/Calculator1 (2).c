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

DDRD=0xf0;

while(1)
{

PORTD=0xef;
_delay_ms(10);
if((PIND&0x01)==0x00)
{OCR0=59;
}
if((PIND&0x02)==0x00)
{OCR0=52;
}
if((PIND&0x04)==0x00)
{OCR0=46;
}
if((PIND&0x08)==0x00)
{OCR0=44;
}

PORTD=0xdf;
_delay_ms(10);
if((PIND&0x01)==0x00)
{OCR0=38;
}
if((PIND&0x02)==0x00)
{OCR0=34;
}
if((PIND&0x04)==0x00)
{OCR0=30;
}
if((PIND&0x08)==0x00)
{OCR0=28;
}
}

}

