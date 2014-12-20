; In The Name Of God
; ========================================
; [] File Name : address.asm
; 
; [] Creation Date : 21-12-2014
;
; [] Last Modified : Sun 21 Dec 2014 01:52:06 AM IRST
;
; [] Created By : Parham Alvani (parham.alvani@gmail.com)
; =======================================
section .data
	A: db '1', '2', '3', '4'
section .text
	global main
main:
	mov rax, A
	mov rbx, [rax]
	inc rax
	mov rbx, [rax]
	
	mov rbx, [rax + 1]

	mov rax, 1
	mov rbx, [A + rax]
	mov rbx, [A + 2]
	lea rbx, [A + rax * 4 + 10]

	lea rax, [0x000000000000]

	mov eax, 1
	mov ebx, 0
	int 80H
