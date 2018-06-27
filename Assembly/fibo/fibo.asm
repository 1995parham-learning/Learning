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

; Computes Nth fibonacci number
; 1 1 2

N equ 10

section .data
	number: db 1 ; current sequence number
	fib_even: dd 1 ; a = a + b if number is even
	fib_odd: dd 1 ; b = a + b if number is odd

section .text
global _start
_start:
	mov eax, 0
	mov edx, 0
	mov al, [number]
	inc al
	mov byte [number], al
	mov bl, 2
	div bl
	test ah, ah
	jz do_even
do_odd:
	mov eax, [fib_even]
	mov ebx, [fib_odd]
	add ebx, eax
	mov dword [fib_odd], ebx
	mov al, [number]
	cmp al, N
	jz finish
	jmp _start
do_even:
	mov eax, [fib_even]
	mov ebx, [fib_odd]
	add eax, ebx
	mov dword [fib_even], eax
	mov al, [number]
	cmp al, N
	jz finish
	jmp _start
finish:
	mov rax, 60 ; invoke exit system call
	xor rdi, rdi ; status code 0
	syscall
