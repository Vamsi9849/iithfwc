#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>
int main (void)
{

 bool x=0,y=0,z=0,w=0,A=0,B=0,C=0,D=0;
 
 DDRD =  0b00111100;
 DDRB =  0b11000011;
 PORTB = 0b00111100;   // 2,3,4,5 as inputs


while(1)
{

z = (PINB & (1 << PINB5)) == (1 << PINB5);
x = (PINB & (1 << PINB4)) == (1 << PINB4);
y = (PINB & (1 << PINB3)) == (1 << PINB3);
w = (PINB & (1 << PINB2)) == (1 << PINB2);
A=(!z&w)|(!z&x)|(!z&y&!x)|(z&!y&!x&!w);
B = (!z&y&!x&!w)|(!y&!x&w)|(!z&!y&x);
C = (!z&!x&w)|(!y&!x&w)|(!z&x&!w);
D=(!z&w)|(!y&!x&w);
PORTD |=(D<<2);
PORTD |=(C<<3);
PORTD |=(B<<4);
PORTD |=(A<<5);

}
return 0;
}
