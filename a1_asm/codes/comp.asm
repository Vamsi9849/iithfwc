.include  "/home/user/m328Pdef.inc"
ldi r16,0b00111100
out DDRD,r16
ldi r17,0b11000011
out DDRB,r17
ldi r17,0b11111111
out PORTB,r17
loop:
        in r17,PINB
        mov r20,r17
        com r20
        inc r20
        out PORTD,r20
        rjmp loop
start:
        rjmp start
