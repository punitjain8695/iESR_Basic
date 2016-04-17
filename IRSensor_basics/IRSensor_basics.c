#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
void main()
{
DDRA=0;
DDRB=255;
while(1)
{

if((PINA&0x01) == 0x01)
{

if((PINA&0x02) == 0x02)
{
PORTB=255;
_delay_ms(350);

}}
else{
PORTB=0;}


}
}
