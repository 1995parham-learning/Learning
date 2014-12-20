; In The Name Of God
; ========================================
; [] File Name : args.asm
; 
; [] Creation Date : 21-12-2014
;
; [] Last Modified : Sun 21 Dec 2014 02:02:24 AM IRST
;
; [] Created By : Parham Alvani (parham.alvani@gmail.com)
; =======================================
section .text
	global _start
_start:
	pop rax
	pop rsi
	mov rax, 1
	mov rdi, 1
	mov rdx, 4
	syscall

	mov rax, 60
	mov rdi, 1
	syscall
