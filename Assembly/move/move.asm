; In The Name Of God
; ========================================
; [] File Name : move.asm
; 
; [] Creation Date : 21-12-2014
;
; [] Last Modified : Sun 21 Dec 2014 01:57:39 AM IRST
;
; [] Created By : Parham Alvani (parham.alvani@gmail.com)
; =======================================
section .data
	eight_bit_max_number: db 0xFF
	eight_bit_min_number: db 0x00
section .text
	global main
main:
	mov ah,[eight_bit_max_number]
	mov ax,[eight_bit_min_number]

	mov bh,[eight_bit_max_number]
	movzx bx,[eight_bit_min_number]

	mov eax,1
	mov ebx,0
	int 0x80
