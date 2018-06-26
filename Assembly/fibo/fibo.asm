; vim: ft=nasm
; In The Name of God
; =======================================
; [] File Name : fibo.asm
;
; [] Creation Date : 27-06-2018
;
; [] Created By : Parham Alvani <parham.alvani@gmail.com>
; =======================================
;
FIN_N equ 10

section .data
	number: db 1
	fib_even: dd 1
	fib_odd: dd 1

section .text
	global main
main:
	mov eax, 0
	mov edx, 0
	mov al, [number]
	inc al
	mov byte [number], al
	mov bl, 2
	div bl
	test ah, ah
	jz DO_EVEN
DO_ODD:
	mov eax, [fib_even]
	mov ebx, [fib_odd]
	add ebx, eax
	mov dword [fib_odd], ebx
	mov al, [number]
	cmp al, FIN_N
	jz FINISH
	jmp main
DO_EVEN:
	mov eax, [fib_even]
	mov ebx, [fib_odd]
	add eax, ebx
	mov dword [fib_even], eax
	mov al, [number]
	cmp al, FIN_N
	jz FINISH
	jmp main
FINISH:
	mov eax, 1
	mov ebx, 0
	int 80H
