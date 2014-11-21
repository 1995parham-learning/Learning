section .data
	A: db 1
section .bss
	W: resb 2
section .text
	global _start
_start:
	jmp main
	
	times 1000 * 1000 * 10 db 1

main:	
	mov eax, cs
	
	; mov ds, eax
	; sysenter
	mov dx, 0x50
	in ax, dx
	mov [W], ax
	
	mov eax, 4
	mov ebx, 1
	mov ecx, W
	mov edx, 2
	int 80H

	; mov r8, 1
	; mov r9, 10
	; mov r10, 11
	
	mov eax, 1
	mov ebx, 0
	int 80h
