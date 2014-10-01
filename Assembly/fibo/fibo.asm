section .data

NUMBER:		equ 10
FIB_EVEN:	dd 1
FIB_ODD:	dd 1

section .text
	mov ecx, 0
	mov eax, [FIN_EVEN]
	mov ebx, [FIN_ODD]

