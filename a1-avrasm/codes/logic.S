#define __SFR_OFFSET 0
#include <avr/io.h>
.global loop

.section .text
loop:
     in r17,PINB
        mov r20,r17
        com r20
        inc r20
        out PORTD,r20
        rjmp loop
start:
        rjmp start
