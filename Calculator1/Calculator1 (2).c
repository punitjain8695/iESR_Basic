#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#include<avr/lcd.h>
#define maxsize  
char A[maxsize]={0},B[maxsize]={0};
char a=0,b=0,choice=0;
int num1=0,num2=0,ans=0,i=0,j=0;

char getcha()
{
int a=0;

//1st row

PORTA=0xef;
_delay_ms(10);
if((PINA&0x01)==0x00)
{
while((PINA&0x01)==0x00);
PORTB=1;
a = (49);
}
if((PINA&0x02)==0x00)
{
while((PINA&0x02)==0x00);
PORTB=2;
a = (50);
}
if((PINA&0x04)==0x00)
{
while((PINA&0x04)==0x00);
PORTB=3;
a = (51);
}
if((PINA&0x08)==0x00)
{
while((PINA&0x08)==0x00);
PORTB=4;
a = ('+');
}

//2nd row

PORTA=0xdf;
_delay_ms(10);
if((PINA&0x01)==0x00)
{
while((PINA&0x01)==0x00);
PORTB=5;
a = (52);
}
if((PINA&0x02)==0x00)
{
while((PINA&0x02)==0x00);
PORTB=6;
a = (53);
}
if((PINA&0x04)==0x00)
{
while((PINA&0x04)==0x00);
PORTB=7;
a = (54);
}
if((PINA&0x08)==0x00)
{
while((PINA&0x08)==0x00);
PORTB=8;
a = ('-');
}
//3rd row

PORTA=0xbf;
_delay_ms(10);
if((PINA&0x01)==0x00)
{
while((PINA&0x01)==0x00);
PORTB=9;
a = (55);
}
if((PINA&0x02)==0x00)
{
while((PINA&0x02)==0x00);
PORTB=10;
a = (56);
}
if((PINA&0x04)==0x00)
{
while((PINA&0x04)==0x00);
PORTB=11;
a = (57);
}
if((PINA&0x08)==0x00)
{
while((PINA&0x08)==0x00);
PORTB=12;
a = ('/');
}
//4th row

PORTA=0x7f;
_delay_ms(10);
if((PINA&0x01)==0x00)
{
while((PINA&0x01)==0x00);
PORTB=13;
a = (67);
}
if((PINA&0x02)==0x00)
{
while((PINA&0x02)==0x00);
PORTB=14;
a = (48);
}
if((PINA&0x04)==0x00)
{
while((PINA&0x04)==0x00);
PORTB=15;
a = ('=');
}
if((PINA&0x08)==0x00)
{
while((PINA&0x08)==0x00);
PORTB=16;
a = ('*');
}


return a;
}

calc()
{
switch (choice)
{
case '+' : ans=num1+num2;
break;

case '-' : 

if(num1>=num2)
ans=num1-num2;
else ans=num2-num1;
break;

case '/' : 
if(num1>=num2)
ans=num1/num2;
else ans=num2/num1;
break;

case '*' : ans=num1*num2;
break;
}

}


void main()
{
DDRC=255;
lcd_init();
DDRA=0xf0;

start:


num1=0,num2=0,i=0,j=0,
lcd_command(0x01);
lcd_command(0x80);
lcd_string("   Calculator");
char c=0x80;
_delay_ms(1000);
lcd_command(0x01);
lcd_command(c);

//enter 1st number
firnum:

while(1)
{
b=getcha();
if(b!=0)
{
if((b=='+')||(b=='-')||(b=='/')||(b=='*')||(b=='=')||(b==67))
{
if(b=='=')
{
//equal to
lcd_command(0xce);
lcd_number(ans);
_delay_ms(3500);
goto start;
}

if(b==67)
{
num1=num1/10;
c--;
lcd_command(c);
lcd_data(32);
i--;
goto firnum;
}

else
{
lcd_command(c);
choice=b;
lcd_data(32);
lcd_data(choice);
lcd_data(32);
c++;c++;c++;
goto secnum;
}
}
else  if(b>47 && b<59)
{
lcd_command(c);
lcd_data(b);
num1=(num1*10)+(b-48);
A[i]=b;
i++;
c++;
}
}
}
// enter 2nd number

secnum:

while(1)
{
b=getcha();
if((b=='=')||(b==67))
{
if(b=='=')
{
//equal to
calc();
lcd_command(0xce);
lcd_number(ans);
_delay_ms(3500);
goto start;
}

if(b==67)
{
num1=num1/10;
lcd_command(--c);
lcd_data(32);
i--;
c++;
}

}
else if(b>47 && b<59)
{
lcd_data(b);
num2=(num2*10)+(b-48);
B[j]=b;
j++;
c++;
}
}
}


