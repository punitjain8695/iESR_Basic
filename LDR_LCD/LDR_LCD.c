#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#include<string.h>
#include<avr/lcd.h>
#include<avr/adc.h>

void main()
{
DDRA=0;
DDRC=255;
lcd_init();

adc_init();
int b;
while(1)
{
b=adc_read(0);
char A[40]="LDR value";
lcd_command(0x01);
lcd_command(0x80);
lcd_string(A);
lcd_command(0x8f);
lcd_number(b);
lcd_command(0xc0);
if (b<200)
{
lcd_string("Extreme Dark");
}
if ((b>200)&&(b<400))
{
lcd_string("Dark");
}
if ((b>400)&&(b<600))
{
lcd_string("Low Darkness");
}
if ((b>600)&&(b<800))
{
lcd_string("Light Bright");
}
if (b>800)
{
lcd_string("Extreme Bright");
}
_delay_ms(1000);

}
}
