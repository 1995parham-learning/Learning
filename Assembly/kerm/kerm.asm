section .data
	A: db 1
section .text
	global _start
_start:
	jmp main
	
	times 1000 * 1000 * 10 db 1

main:	
	mov eax, cs
	
	; mov ds, eax
	; sysenter
	; in ax, 64h
	
	mov r8, 1
	mov r9, 10
	mov r10, 11
	
	mov eax, 1
	mov ebx, 0
	int 80h
