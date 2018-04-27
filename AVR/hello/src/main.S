; vim: set ft=avr8bit:

.section .text
.global main

main:
	ldi r16, 10
	ldi r20, 0
	ldi r21, 3

again:
	add r20, r21
	dec r16
	brne again
