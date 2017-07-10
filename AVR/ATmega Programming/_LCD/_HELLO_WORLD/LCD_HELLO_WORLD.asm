;
; LCD_HELLO_WORLD.asm
;
; Created: 4/16/2017 4:55:08 AM
; Author : Ali Gholami
;

; A program to write the "HELLO WORLD" string on the LCD
; The LCD connection will be done using some libraries
.include "m16_LCD_4bit.inc"

start:

	ldi argument,'H'
	call lcd_putchar

	ldi argument,'E'
	call lcd_putchar

	ldi argument,'L'
	call lcd_putchar

	ldi argument,'L'
	call lcd_putchar

	ldi argument,'O'
	call lcd_putchar

	ldi argument,' '
	call lcd_putchar

	ldi argument,'W'
	call lcd_putchar

	ldi argument,'o'
	call lcd_putchar

	ldi argument,'r'
	call lcd_putchar

	ldi argument,'l'
	call lcd_putchar

	ldi argument,'d'
	call lcd_putchar
	
END:
	jmp END