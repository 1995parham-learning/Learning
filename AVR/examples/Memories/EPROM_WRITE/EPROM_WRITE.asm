;
; EPROM_WRITE.asm
;
; Created: 5/31/2017 12:24:21 AM
; Author : aligholamee
;
; This program will write a byte to a desired address in the EPROM


;============== DEFS =================
.def TEMP = R16
.def DESIRED_ADDRESS_L = R17
.def DESIRED_ADDRESS_H = R18
.def DATA_TO_BE_WRITTEN = R19
;============== DEFS =================

;============ VECTORS ================
.org 0x00
	jmp RESET_ISR 
;============ VECTORS ================

;=========== RESET ISR ===============
RESET_ISR:
	; Setup the stack pointer
	ldi TEMP,HIGH(RAMEND)
	out SPH,TEMP
	ldi TEMP,LOW(RAMEND)
	out SPL,TEMP

	; put the port c and port d and port a to output 
	ldi TEMP,0xFF
	out DDRC,TEMP
	out DDRD,TEMP
	out DDRA,TEMP 
	; put the port b - 1st bit as output
	ldi TEMP,0x01
	out DDRB,TEMP
	
	; start the main program
	rjmp start
;=========== RESET ISR ===============

;========== MAIN PROGRAM =============
start:
	; Load the desired address: 0x1100
	ldi DESIRED_ADDRESS_L,0x00
	ldi DESIRED_ADDRESS_H,0x33
	ldi DATA_TO_BE_WRITTEN,0x44
	rjmp MEM_WRITE
	rjmp start
;========== MAIN PROGRAM =============
here:
	rjmp here
;========== MEMORY WRITE ==============
MEM_WRITE:
	; Put the data on the port a
	out PORTA,DATA_TO_BE_WRITTEN
	; put the address low byte on the address lines
	out PORTC,DESIRED_ADDRESS_L
	; EPROM Chip Enable
	andi DESIRED_ADDRESS_H,0b11011111
	; Make PGM high then low to write the data
	; Make OE high to avoid reading
	ori DESIRED_ADDRESS_H,0b11000000
	; put the address high byte on the address lines
	out PORTD,DESIRED_ADDRESS_H
	; 2 nops = 2 * 62.5 ns > Twlwh
	nop 
	nop
	; Make PGM low to write the data
	cbi PORTD,7
	; 1 nop = 1 * 62.5 ns > Twhdw
	nop
	rjmp here
;========== MEMORY WRITE ==============