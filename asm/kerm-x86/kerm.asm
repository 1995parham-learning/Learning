; In The Name Of God
; ========================================
; [] File Name : kerm.asm
; 
; [] Creation Date : 21-12-2014
;
; [] Last Modified : Sun 21 Dec 2014 01:56:13 AM IRST
;
; [] Created By : Parham Alvani (parham.alvani@gmail.com)
; =======================================
section .text
	global main
main:
	mov eax, cs
	; mov ds, eax
	; sysenter
	; in ax, 64h
	;mov r8, 1
	;mov r9, 10
	;mov r10, 11
	mov eax, 1
	mov ebx, 0
	int 80h
