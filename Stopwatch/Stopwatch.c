#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#include<avr/lcd.h>

void main()
{
int i,hr,min,sec;
DDRC=0xff;

lcd_init();

lcd_command(0x85);
lcd_string(":");
lcd_command(0x8A);
lcd_string(":");
lcd_command(0x8E);
lcd_string("S");
lcd_command(0x89);
lcd_string("M");
lcd_command(0x84);
lcd_string("H");

for (hr=1;hr<24;hr++)
{
for (min=1;min<60;min++)
{
for (sec=0;sec<60;sec++)
{
lcd_command(0x8C);
lcd_number(sec);
_delay_ms(900);
}
lcd_command(0x87);
lcd_number(min);
}
lcd_command(0x82);
lcd_number(hr);
}

}
