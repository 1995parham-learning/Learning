;
; MATRIX_7SEG_DISPLAY.asm
;
; Created: 4/15/2017 12:45:18 PM
; Author : Ali Gholami
;
; This code is written to identify and DISPLAY_ the pressed number in the keyboard

.org 0x00
	jmp RESET	; Reset vector

/**********************/
/*******INT0 ISR*******/
.org int0addr
	ldi r16,(1<<PD2)
	out ddrd,r16
	ldi r16,0x00
	out portd,r16
	jmp start



/***********************/
/*******RESET ISR*******/
RESET:
	; Stack init
	ldi r16,low(ramend)
	out spl,r16
	ldi r16,high(ramend)
	out sph,r16

	; DDRB output mode for 7 Segment
	ldi r16,0xff
	out ddrb,r16
	ldi r16,0xff
	out PINB,r16

	; DDRC - Half output - Half input
	ldi r16,0x00
	out ddrc,r16
	ldi r16,0xFF
	out ddra,r16

	; PORTC - Input half pull-up
	ldi r16,0xFF
	out PORTC,r16
	; PORTA - Input half pull-up
	ldi r16,0x00
	out PORTA,r16

	; PORTD - INPUT MODE for PD2
	ldi r16,(0<<PD2)
	out ddrd,r16

	; MCUCR Config - toggle mode for interrupt_0 sense control
	in r16,MCUCR
	ori r16,(0 << ISC11) | (1 << ISC10)
	out MCUCR,r16

	; Enable INT0 in GICR
	ldi R16, (1 << INT0)
	out GICR, R16

	; Enable Global Interrupt Flag
	sei
	jmp TYPE_1

WAIT_HERE:
	jmp WAIT_HERE

	; Mode 1 is similar to what we have done in RESET
TYPE_1:
	; DDRC - input
	ldi r16,0x00
	out ddrc,r16
	ldi r16,0xFF

	; DDRA - output
	out ddra,r16

	; PORTC - Input pull-up
	ldi r16,0xFF
	out PORTC,r16

	; PORTD - INPUT MODE for PD2
	ldi r16,0x00
	out PORTA,r16
	ldi r16,(1<<PD2)
	out ddrd,r16
	ldi r16,0x00
	out portd,r16

	out ddrd,r16
	ldi r16,0x00
	out portd,r16
	jmp start

	sei
	jmp WAIT_HERE
TYPE_2:
	ldi r16,0xFF
	out ddrc,r16
	ldi r16,0x00
	out ddra,r16
	ldi r16,0x00
	out PORTC,r16
	ldi r16,0xFF
	out PORTA,r16
	jmp RECURSIVE_LOOP
start:
	; Read PINA
	in r17,PINA
	jmp TYPE_2

	; In case of end, jump to type 1
endO:
	jmp TYPE_1

RECURSIVE_LOOP:
	; Read PINC
	in r18,PINC
	call FIND_COLUMN
	jmp endO

	; find the column number as simple as possible
	; labels for each column
	; First column check
FIND_COLUMN:
	cpi r17,0x01
	breq COL_0
	cpi r17,0x02
	breq COL_1
	cpi r17,0x03
	breq COL_2
	cpi r17,0x04
	breq COL_3
	ret

COL_0:
	cpi r18,0x01
	breq DISPLAY_0
	cpi r18,0x02
	breq DISPLAY_1
	cpi r18,0x03
	breq DISPLAY_2
	cpi r18,0x04
	breq DISPLAY_3
	ret

COL_1:
	cpi r18,0x01
	breq DISPLAY_4
	cpi r18,0x02
	breq DISPLAY_5
	cpi r18,0x03
	breq DISPLAY_6
	cpi r18,0x04
	breq DISPLAY_7
	ret

COL_2:
	cpi r18,0x01
	breq DISPLAY_8
	cpi r18,0x02
	breq DISPLAY_9
	cpi r18,0x03
	breq DISPLAY_10
	cpi r18,0x04
	breq DISPLAY_11
	ret

COL_3:
	cpi r18,0x01
	breq DISPLAY_12
	cpi r18,0x02
	breq DISPLAY_13
	cpi r18,0x03
	breq DISPLAY_14
	cpi r18,0x04
	breq DISPLAY_15
	ret

/**********************/
/*****Functions to Display******/
/****Results on the 7 Segment****/
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
	ldi r16,0x5F
	out PORTB,r16
	ret
DISPLAY_11:
	ldi r16,0x7C
	out PORTB,r16
	ret
DISPLAY_12:
	ldi r16,0x58
	out PORTB,r16
	ret
DISPLAY_13:
	ldi r16,0x5E
	out PORTB,r16
	ret
DISPLAY_14:
	ldi r16,0xF9
	out PORTB,r16
	ret
DISPLAY_15:
	ldi r16,0E71
	out PORTB,r16
	ret