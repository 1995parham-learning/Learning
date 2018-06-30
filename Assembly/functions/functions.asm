; vim: ft=nasm
; In The Name of God
; =======================================
; [] File Name : functions.asm
;
; [] Creation Date : 30-06-2018
;
; [] Created By : Parham Alvani <parham.alvani@gmail.com>
; =======================================
;
section .text
global _start

; sum(n) = 1 + 2 + ... + n
sum:
	; arguments: rdi, rsi, rdx, rcx, r8, r9, the rest is passed on to the stack in reverse order
	xor r10, r10
.loop:
	test rax, rax
	jz .zero
	add r10, rax
	dec rax
	jmp .loop
.zero:
	; return values: rax, rdx
	mov rax, r10
	ret
