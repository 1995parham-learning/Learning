;
; HELLO_WORLD_MEM.asm
;
; Created: 4/16/2017 9:59:41 PM
; Author : Ali Gholami
;
; A program to show the grabbed data from an specific array in the flash and show them on the LCD
.include "m16_LCD_4bit.inc"
; Write an array of data in the flash section(code section)
.CSEG
LCDTABLE: .DB 14, 'M', 'Y', ' ', 'N', 'A', 'M', 'E', ' ', 'I', 'S', ' ', 'M', 'E', 'T', 'H', 'O', 'S'

.def counter = R15

start:
	; call LCD accroding to the number given in the first place of LCDTABLE
	ldi ZH, high(LCDTABLE << 1)
	ldi ZL, low(LCDTABLE << 1)
	lpm counter,Z+

LCD_CALL:
	; Check the end of the loop
	rcall LCD

	dec counter
	brne LCD_CALL

here:
	jmp here

; This routine will make the microcontroller to show the stored data in the address LCDTABLE
LCD:
	lpm argument, Z+
	rcall lcd_putchar
	ret
	