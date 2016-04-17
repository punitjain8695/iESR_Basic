#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>


void Al()
{
PORTA=0b11111110;
PORTB=0b11011110;
_delay_ms(1);
PORTA=0b00010001;
PORTB=0b11100001;
_delay_ms(1);
}

void Bl()
{
PORTA=0b11111111;
PORTB=0b11111110;
_delay_ms(1);
PORTA=0b01101110;
PORTB=0b11011111;
_delay_ms(1);
PORTA=0b10010001;
PORTB=0b11100001;
_delay_ms(1);
}

void Cl()
{
PORTA=0b01111110;
PORTB=0b11111110;
_delay_ms(1);
PORTA=0b10000001;
PORTB=0b11100001;
_delay_ms(1);
PORTA=0b01000010;
PORTB=0b11011111;
_delay_ms(1);
}

void Dl()
{
PORTA=0b11111111;
PORTB=0b11111110;
_delay_ms(1);
PORTA=0b10000001;
PORTB=0b11100001;
_delay_ms(1);
PORTA=0b01111110;
PORTB=0b11011111;
_delay_ms(1);
}

void l()
{
PORTA=0;
PORTB=0;
_delay_ms(1);
}


void main()
{
DDRA=255;
DDRB=255;
DDRD=0xf0;
while(1)
{
PORTD=0xef;
_delay_ms(10);
if((PIND&0x01)==0)
{
while((PIND&0x01)==0)
{
l();
}
while((PIND&0x0f)==0x0f)
{
Al();
}
}
if((PIND&0x02)==0)
{
while((PIND&0x02)==0)
{
l();
}
while((PIND&0x0f)==0x0f)
{
Bl();
}
}
if((PIND&0x04)==0)
{
while((PIND&0x04)==0)
{
l();
}
while((PIND&0x0f)==0x0f)
{
Cl();
}
}
if((PIND&0x08)==0)
{
while((PIND&0x08)==0)
{
l();
}
while((PIND&0x0f)==0x0f)
{
Dl();
}
}

}
}
