section .data
	hello: db "Hello world!", 10, 0
	hello_len equ $-hello

section .text
	global hello_writer
hello_writer:
	mov eax, 4
	mov ebx, 1
	mov ecx, hello
	mov edx, hello_len
	int 0x80
	mov eax, 4
	mov ebx, 1
	mov rcx, rdi
	mov rdx, rsi
	int 0x80
	ret
