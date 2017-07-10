;
; SRAM_READ.asm
;
; Created: 5/30/2017 11:18:08 PM
; Author : aligholamee
;
; Reading from SRAM, The desired address is 1100H accroding to the question :D


;============== DEFS =================
.def TEMP = R16
.def DESIRED_ADDRESS_L = R17
.def DESIRED_ADDRESS_H = R18
.def DATA_READ = R19
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

	; put the port c and port d to output 
	ldi TEMP,0xFF
	out DDRC,TEMP
	out DDRD,TEMP

	; put the port a to input for reading purpose
	ldi TEMP,0x00
	out DDRA,TEMP
	
	; start the main program
	rjmp start
;=========== RESET ISR ===============

;========== MAIN PROGRAM =============
start:
	; Load the desired address: 0x1100
	ldi DESIRED_ADDRESS_L,0x00
	ldi DESIRED_ADDRESS_H,0x11
	rjmp MEM_READ
	rjmp start
;========== MAIN PROGRAM =============

;========== MEMORY READ ==============

;========== MEMORY READ ==============
MEM_READ:
	out PORTC,DESIRED_ADDRESS_L
	; Enable the chip select for the sram #3
	andi DESIRED_ADDRESS_H,0b01011111
	out PORTD,DESIRED_ADDRESS_H
	; 6 nops = 6 * 62.5 ns
	nop 
	nop
	nop
	nop
	nop
	nop
	in DATA_READ,PINC
	ret
;========== MEMORY READ ==============