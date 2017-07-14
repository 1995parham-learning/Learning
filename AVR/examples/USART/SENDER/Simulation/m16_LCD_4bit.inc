;*******************************************************************************
;	File:	m16_LCD_4bit.inc
;      Title:	ATmega16 driver for LCD in 4-bit mode (HD44780)
;  Assembler:	AVR assembler/AVR Studio
;    Version:	1.0
;    Created:	April 5th, 2004
;     Target:	ATmega16
; Christoph Redecker, http://www.avrbeginners.net
;*******************************************************************************

; Some notes on the hardware:
;ATmega8 (clock frequency doesn't matter, tested with 1 MHz to 8 MHz)
; PORTA.1 -> LCD RS (register select)
; PORTA.2 -> LCD RW (read/write)
; PORTA.3 -> LCd E (Enable)
; PORTA.4 ... PORTA.7 -> LCD data.4 ... data.7
; the other LCd data lines can be left open or tied to ground.

#ifndef _M16_LCD_4BIT_INC_
#define _M16_LCD_4BIT_INC_
.include "m16def.inc"

.equ	LCD_RS	= 1
.equ	LCD_RW	= 2
.equ	LCD_E	= 3

.def	temp	= r16
.def	argument= r17		;argument for calling subroutines
.def	return	= r18		;return value from subroutines

.org 0
rjmp reset

reset:
	ldi	temp, low(RAMEND)
	out	SPL, temp
	ldi	temp, high(RAMEND)
	out	SPH, temp

;LCD after power-up: ("*" means black bar)
;|****************|
;|		  |

	rcall	LCD_init
	
;LCD now:
;|&		  | (&: cursor, blinking)
;|		  |
	
	rcall	LCD_wait
	/*ldi	argument, 'A'	;write 'A' to the LCD char data RAM
	rcall	LCD_putchar
	
;|A&		  |
;|		  |
	
	rcall	LCD_wait
	ldi	argument, 0x80	;now let the cursor go to line 0, col 0 (address 0)
	rcall	LCD_command	;for setting a cursor address, bit 7 of the commands has to be set
	
;|A		  | (cursor and A are at the same position!)
;|		  |
	
	rcall	LCD_wait
	rcall	LCD_getchar	;now read from address 0
	
;|A&		  | (cursor is also incremented after read operations!!!)
;|		  |
	
	push	return		;save the return value (the character we just read!)
	
	rcall	LCD_delay
	pop	argument	;restore the character
	rcall	LCD_putchar	;and print it again*/

;|AA&		  | (A has been read from position 0 and has then been written to the next pos.)
;|		  |
		
loop:	rjmp start	

lcd_command8:	;used for init (we need some 8-bit commands to switch to 4-bit mode!)
	in	temp, DDRA		;we need to set the high nibble of DDRA while leaving
					;the other bits untouched. Using temp for that.
	sbr	temp, 0b11110000	;set high nibble in temp
	out	DDRA, temp		;write value to DDRA again
	in	temp, PORTA		;then get the port value
	cbr	temp, 0b11110000	;and clear the data bits
	cbr	argument, 0b00001111	;then clear the low nibble of the argument
					;so that no control line bits are overwritten
	or	temp, argument		;then set the data bits (from the argument) in the
					;Port value
	out	PORTA, temp		;and write the port value.
	sbi	PORTA, LCD_E		;now strobe E
	nop
	nop
	nop
	cbi	PORTA, LCD_E
	in	temp, DDRA		;get DDRA to make the data lines input again
	cbr	temp, 0b11110000	;clear data line direction bits
	out	DDRA, temp		;and write to DDRA
ret

lcd_putchar:
	push	argument		;save the argmuent (it's destroyed in between)
	in	temp, DDRA		;get data direction bits
	sbr	temp, 0b11110000	;set the data lines to output
	out	DDRA, temp		;write value to DDRA
	in	temp, PORTA		;then get the data from PORTA
	cbr	temp, 0b11111110	;clear ALL LCD lines (data and control!)
	cbr	argument, 0b00001111	;we have to write the high nibble of our argument first
					;so mask off the low nibble
	or	temp, argument		;now set the argument bits in the Port value
	out	PORTA, temp		;and write the port value
	sbi	PORTA, LCD_RS		;now take RS high for LCD char data register access
	sbi	PORTA, LCD_E		;strobe Enable
	nop
	nop
	nop
	cbi	PORTA, LCD_E
	pop	argument		;restore the argument, we need the low nibble now...
	cbr	temp, 0b11110000	;clear the data bits of our port value
	swap	argument		;we want to write the LOW nibble of the argument to
					;the LCD data lines, which are the HIGH port nibble!
	cbr	argument, 0b00001111	;clear unused bits in argument
	or	temp, argument		;and set the required argument bits in the port value
	out	PORTA, temp		;write data to port
	sbi	PORTA, LCD_RS		;again, set RS
	sbi	PORTA, LCD_E		;strobe Enable
	nop
	nop
	nop
	cbi	PORTA, LCD_E
	cbi	PORTA, LCD_RS
	in	temp, DDRA
	cbr	temp, 0b11110000	;data lines are input again
	out	DDRA, temp
ret

lcd_command:	;same as LCD_putchar, but with RS low!
	push	argument
	in	temp, DDRA
	sbr	temp, 0b11110000
	out	DDRA, temp
	in	temp, PORTA
	cbr	temp, 0b11111110
	cbr	argument, 0b00001111
	or	temp, argument

	out	PORTA, temp
	sbi	PORTA, LCD_E
	nop
	nop
	nop
	cbi	PORTA, LCD_E
	pop	argument
	cbr	temp, 0b11110000
	swap	argument
	cbr	argument, 0b00001111
	or	temp, argument
	out	PORTA, temp
	sbi	PORTA, LCD_E
	nop
	nop
	nop
	cbi	PORTA, LCD_E
	in	temp, DDRA
	cbr	temp, 0b11110000
	out	DDRA, temp
ret

LCD_getchar:
	in	temp, DDRA		;make sure the data lines are inputs
	andi	temp, 0b00001111	;so clear their DDR bits
	out	DDRA, temp
	sbi	PORTA, LCD_RS		;we want to access the char data register, so RS high
	sbi	PORTA, LCD_RW		;we also want to read from the LCD -> RW high
	sbi	PORTA, LCD_E		;while E is high
	nop
	in	temp, PINA		;we need to fetch the HIGH nibble
	andi	temp, 0b11110000	;mask off the control line data
	mov	return, temp		;and copy the HIGH nibble to return
	cbi	PORTA, LCD_E		;now take E low again
	nop				;wait a bit before strobing E again
	nop	
	sbi	PORTA, LCD_E		;same as above, now we're reading the low nibble
	nop
	in	temp, PINA		;get the data
	andi	temp, 0b11110000	;and again mask off the control line bits
	swap	temp			;temp HIGH nibble contains data LOW nibble! so swap
	or	return, temp		;and combine with previously read high nibble
	cbi	PORTA, LCD_E		;take all control lines low again
	cbi	PORTA, LCD_RS
	cbi	PORTA, LCD_RW
ret					;the character read from the LCD is now in return

LCD_getaddr:	;works just like LCD_getchar, but with RS low, return.7 is the busy flag
	in	temp, DDRA
	andi	temp, 0b00001111
	out	DDRA, temp
	cbi	PORTA, LCD_RS
	sbi	PORTA, LCD_RW
	sbi	PORTA, LCD_E
	nop
	in	temp, PINA
	andi	temp, 0b11110000
	mov	return, temp
	cbi	PORTA, LCD_E
	nop
	nop
	sbi	PORTA, LCD_E
	nop
	in	temp, PINA
	andi	temp, 0b11110000
	swap	temp
	or	return, temp
	cbi	PORTA, LCD_E
	cbi	PORTA, LCD_RW
ret

LCD_wait:				;read address and busy flag until busy flag cleared
	rcall	LCD_getaddr
	andi	return, 0x80
	brne	LCD_wait
	ret


LCD_delay:
	clr	r2
	LCD_delay_outer:
	clr	r3
		LCD_delay_inner:
		dec	r3
		brne	LCD_delay_inner
	dec	r2
	brne	LCD_delay_outer
ret

LCD_init:
	
	ldi	temp, 0b00001110	;control lines are output, rest is input
	out	DDRA, temp
	
	rcall	LCD_delay		;first, we'll tell the LCD that we want to use it
	ldi	argument, 0x20		;in 4-bit mode.
	rcall	LCD_command8		;LCD is still in 8-BIT MODE while writing this command!!!

	rcall	LCD_wait
	ldi	argument, 0x28		;NOW: 2 lines, 5*7 font, 4-BIT MODE!
	rcall	LCD_command		;
	
	rcall	LCD_wait
	ldi	argument, 0x0F		;now proceed as usual: Display on, cursor on, blinking
	rcall	LCD_command
	
	rcall	LCD_wait
	ldi	argument, 0x01		;clear display, cursor -> home
	rcall	LCD_command
	
	rcall	LCD_wait
	ldi	argument, 0x06		;auto-inc cursor
	rcall	LCD_command
ret

#endif /********/
