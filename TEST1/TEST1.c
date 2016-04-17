#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
int c=0;


void Al()
{
while(1)
{
PORTA=0b11111110;
PORTB=0b11011110;
_delay_ms(1);
PORTA=0b00010001;
PORTB=0b11100001;
_delay_ms(1);

}
}

void Bl()
{
while(1)
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
}

void Cl()
{
while(1)
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
}

void Dl()
{
while(1)
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
11111
}
}

void func()
{

//while(1)
{


func();
//switch(c)
//{
//case 1 : {Al();}
//case 2 : {Bl();}
//case 3 : {Cl();}
//case 4 : {Dl();}
//}

}
}

void l()
{

PORTA=0;
PORTB=0;
_delay_ms(10);
func();

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
if(((PIND&0x01)==0x00)||c==1)
{
while((PIND&0x0f)==0x0f)
{
c=1;
Al();
}
}
else if(((PIND&0x02)==0x00)||c==2)
{
while((PIND&0x0f)==0x0f)
{
c=2;
Bl();
}
}
else if(((PIND&0x04)==0x00)||c==3)
{
while((PIND&0x0f)==0x0f)
{
c=3;
Cl();
}
}
else if(((PIND&0x08)==0x00)||(c==4))
{
while((PIND&0x0f)==0x0f)
{
c=4;
Dl();
}
}
}
}
