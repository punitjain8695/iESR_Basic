#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#include<avr/lcd.h>
unsigned char loc=0x80;
char A[16];
char B[16];
int c=0;
int z=0;


int button(char ch)
{
int z=0;
while((PIND&ch)==0);
for(int i=0;i<750;i++)
{
_delay_ms(1);
if((PIND&ch)==0)
{
while((PIND&ch)==0);
z++;
if(z==4){z=0;}
}
}
loc++;
return z;
}


void passinput()
{
c=0;
while(1)
{
z=0;
lcd_command(loc);
//	1st row
PORTD=0xef;
_delay_ms(10);
if((PIND&0x01)==0)
{
z=button(0x01);
if(z==3)
{
lcd_data(49);
A[c]=49;
c++;
}
else 
{
lcd_data(65+z);
A[c]=65+z;
c++;
}
}

if((PIND&0x02)==0)
{
z=button(0x02);
if(z==3)
{
lcd_data(50);
A[c]=50;
c++;
}
else 
{
lcd_data(68+z);
A[c]=68+z;
c++;
}
}

if((PIND&0x04)==0)
{
z=button(0x04);
if(z==3)
{
lcd_data(51);
A[c]=51;
c++;
}
else lcd_data(71+z);
}
if((PIND&0x08)==0)
{
while((PIND&0x08)==0);
lcd_command(0x04);
loc--;
c--;
A[c]='\0';
lcd_command(loc);
lcd_data(' ');
lcd_command(loc);
lcd_command(0x06);
}

//	2nd row
PORTD=0xdf;
_delay_ms(10);
if((PIND&0x01)==0)
{
z=button(0x01);
if(z==3){lcd_data(52);}
else lcd_data(74+z);
}
if((PIND&0x02)==0)
{
z=button(0x02);
if(z==3){lcd_data(53);}
else lcd_data(77+z);
}
if((PIND&0x04)==0)
{
z=button(0x04);
if(z==3){lcd_data(54);}
else lcd_data(80+z);
if((PIND&0x08)==0)
{
while((PIND&0x08)==0);
lcd_command(0x80);
lcd_string("password set");
break;
}

//	3rd row
PORTD=0xbf;
_delay_ms(10);
if((PIND&0x01)==0)
{
z=button(0x01);
if(z==3){lcd_data(55);}
else lcd_data(83+z);
}
if((PIND&0x02)==0)
{
z=button(0x02);
if(z==3){lcd_data(56);}
else lcd_data(86+z);
}
if((PIND&0x04)==0)
{
z=button(0x04);
if(z==2){lcd_data(57);}
else lcd_data(89+z);
if((PIND&0x08)==0)
{
while((PIND&0x08)==0);
lcd_command(0x80);
lcd_string("Checking password");
break;}
}
}

//	4th row
PORTD=0x7f;
_delay_ms(10);
if((PIND&0x01)==0)
{
z=button(0x01);
lcd_data('*');
}
if((PIND&0x02)==0)
{
z=button(0x02);
lcd_data(48);
}
if((PIND&0x04)==0)
{
z=button(0x04);
lcd_data('#');
}

}
}

void main()
{

DDRD=0xf0;
DDRC=255;
lcd_init();
PORTD=0xef;

passinput();

}

