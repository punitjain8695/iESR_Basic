#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>

void main()
{
DDRD=0xf0;
DDRB=255;

while(1)
{

PORTD=0xef;
_delay_ms(10);
if((PIND&0x01)==0x00)
{PORTB=1;
}
if((PIND&0x02)==0x00)
{PORTB=2;
}
if((PIND&0x04)==0x00)
{PORTB=3;
}
if((PIND&0x08)==0x00)
{PORTB=4;
}

PORTD=0xdf;
_delay_ms(10);
if((PIND&0x01)==0x00)
{PORTB=5;
}
if((PIND&0x02)==0x00)
{PORTB=6;
}
if((PIND&0x04)==0x00)
{PORTB=7;
}
if((PIND&0x08)==0x00)
{PORTB=8;
}

PORTD=0xbf;
_delay_ms(10);
if((PIND&0x01)==0x00)
{PORTB=9;
}
if((PIND&0x02)==0x00)
{PORTB=10;
}
if((PIND&0x04)==0x00)
{PORTB=11;
}
if((PIND&0x08)==0x00)
{PORTB=12;
}

PORTD=0x7f;
_delay_ms(10);
if((PIND&0x01)==0x00)
{PORTB=13;
}
if((PIND&0x02)==0x00)
{PORTB=14;
}
if((PIND&0x04)==0x00)
{PORTB=15;
}
if((PIND&0x08)==0x00)
{PORTB=16;
}
}
}
