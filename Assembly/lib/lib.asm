%macro .string 2+
	%1: db %2
	%1_len equ $-%1
%endmacro

%macro multipush 1-*
	%rep %0
		push %1
		%rotate 1
	%endrep
%endmacro

%macro multipop 1-*
	%rep %0
		%rotate -1
		pop %1
	%endrep
%endmacro

%macro return_to_os 0
	mov rax, 60
	mov rdi, 0
	syscall
%endmacro

%macro write 3
	mov rax, 1
	mov rdi, %1
	mov rsi, %2
	mov rdx, %3
	syscall
%endmacro

%macro read 3
	mov rax, 0
	mov rdi, %1
	mov rsi, %2
	mov rdx, %3
	syscall
%endmacro

section .data
	.string parham, "Parham", 10
section .text
	global _start
_start:
	write 1, parham, parham_len
	return_to_os
