section .text
	global main
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
