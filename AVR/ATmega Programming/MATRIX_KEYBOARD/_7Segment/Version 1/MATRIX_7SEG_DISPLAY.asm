;
; MATRIX_7SEG_DISPLAY.asm
;
; Created: 4/15/2017 12:45:18 PM
; Author : Ali Gholami
;
; This code is written to identify and DISPLAY_ the pressed number in the keyboard
rjmp RESET
ldi r22,0x00
.org int0addr
	;inc r22
	;out PORTB,r22
	ldi r16,(1<<PD2)
	out ddrd,r16
	ldi r16,0x00
	out portd,r16
	rjmp start
RESET:
	ldi r16,low(ramend)
	out spl,r16
	ldi r16,high(ramend)
	out sph,r16
	ldi r16,0xff
	out ddrb,r16
	ldi r16,0xff
	out PINB,r16

	ldi r16,0b00000000
	out ddrc,r16
	ldi r16,0b11111111
	out ddra,r16
	ldi r16,0b11111111
	out PORTC,r16
	ldi r16,0b00000000
	out PORTA,r16

	ldi r16,(0<<PD2)
	out ddrd,r16

	in r16,MCUCR
	ori r16,(0 << ISC11) | (1 << ISC10)
	out MCUCR,r16

	ldi R16, (1 << INT0)
	out GICR, R16

	sei

	rjmp TYPE_1

loop:
	rjmp loop

TYPE_1:
	ldi r16,0b00000000
	out ddrc,r16
	ldi r16,0b11111111
	out ddra,r16
	ldi r16,0b11111111
	out PORTC,r16
	ldi r16,0b00000000
	out PORTA,r16
	/*
	ldi r16,(1<<PD2)
	out ddrd,r16
	ldi r16,0x00
	out portd,r16
	*/ino nazashtam felan

	out ddrd,r16

	rjmp start

	sei
	rjmp loop
TYPE_2:
	ldi r16,0b11111111
	out ddrc,r16
	ldi r16,0b00000000
	out ddra,r16
	ldi r16,0b00000000
	out PORTC,r16
	ldi r16,0b11111111
	out PORTA,r16
	rjmp inner

start:
	in r17,PINA
	rjmp TYPE_2
endO:
	rjmp TYPE_1
inner:
	in r18,PINC
	call ON_MODE
	rjmp endO
OFF_MODE:
	ldi r16,0x00
	out PORTB,r16
	ret
ON_MODE:
	cpi r17,0b00000001
	breq COL_0
	cpi r17,0b00000010
	breq COL_1
	cpi r17,0b00000100
	breq COL_2
	cpi r17,0b00001000
	breq COL_3
	ret

COL_0:
	cpi r18,0b00000001
	breq DISPLAY_0
	cpi r18,0b00000010
	breq DISPLAY_1
	cpi r18,0b00000100
	breq DISPLAY_2
	cpi r18,0b00001000
	breq DISPLAY_3
	ret
COL_1:
	cpi r18,0b00000001
	breq DISPLAY_4
	cpi r18,0b00000010
	breq DISPLAY_5
	cpi r18,0b00000100
	breq DISPLAY_6
	cpi r18,0b00001000
	breq DISPLAY_7
	ret
COL_2:
	cpi r18,0b00000001
	breq DISPLAY_8
	cpi r18,0b00000010
	breq DISPLAY_9
	cpi r18,0b00000100
	breq DISPLAY_10
	cpi r18,0b00001000
	breq DISPLAY_11
	ret
COL_3:
	cpi r18,0b00000001
	breq DISPLAY_12
	cpi r18,0b00000010
	breq DISPLAY_13
	cpi r18,0b00000100
	breq DISPLAY_14
	cpi r18,0b00001000
	breq DISPLAY_15
	ret
DISPLAY_0:
	ldi r16,0x3f
	out PORTB,r16
	ret
DISPLAY_1:
	ldi r16,0x06
	out PORTB,r16
	ret
DISPLAY_2:
	ldi r16,0x5b
	out PORTB,r16
	ret
DISPLAY_3:
	ldi r16,0x4f
	out PORTB,r16
	ret
DISPLAY_4:
	ldi r16,0x66
	out PORTB,r16
	ret
DISPLAY_5:
	ldi r16,0x6d
	out PORTB,r16
	ret
DISPLAY_6:
	ldi r16,0x7d
	out PORTB,r16
	ret
DISPLAY_7:
	ldi r16,0x07
	out PORTB,r16
	ret
DISPLAY_8:
	ldi r16,0x7f
	out PORTB,r16
	ret
DISPLAY_9:
	ldi r16,0x6f
	out PORTB,r16
	ret
DISPLAY_10:
	ldi r16,0b01011111
	out PORTB,r16
	ret
DISPLAY_11:
	ldi r16,0b01111100
	out PORTB,r16
	ret
DISPLAY_12:
	ldi r16,0b01011000
	out PORTB,r16
	ret
DISPLAY_13:
	ldi r16,0b01011110
	out PORTB,r16
	ret
DISPLAY_14:
	ldi r16,0b11111001
	out PORTB,r16
	ret
DISPLAY_15:
	ldi r16,0b01110001
	out PORTB,r16
	ret
