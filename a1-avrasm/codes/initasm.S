;enable pin 13 of Arduino as output
#define __SFR_OFFSET 0
#include <avr/io.h>

.global init

.section .text

init:
	ldi r16,0b00111100
        out DDRD,r16
        ldi r17,0b00000000
        out DDRB,r17





