; In The Name Of God
; ========================================
; [] File Name : infinite-loop.asm
; 
; [] Creation Date : 21-12-2014
;
; [] Last Modified : Sun 21 Dec 2014 01:55:02 AM IRST
;
; [] Created By : Parham Alvani (parham.alvani@gmail.com)
; =======================================
section .text
	global main
main:
	mov eax, 0
	mov ebx, 2
wall:
	add eax, ebx
	jmp wall
