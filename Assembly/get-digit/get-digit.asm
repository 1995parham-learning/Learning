section .data
	msg: db "Please enter a digit:> "
	msg_len equ $ - msg
section .bss
	char: resb 1
	digit: resb 1
section .text
	global main
main:
	mov eax, 4
	mov ebx, 1
	mov ecx, msg
	mov edx, msg_len
	int 80H
get_char:
	mov eax, 3
	mov ebx, 0
	mov ecx, char
	mov edx, 1
	int 80H

	mov byte ah, [char]
	mov al, '0'
	cmp ah, al
	jb get_char

	mov al, '9'
	cmp ah, al
	ja get_char

	mov al, '0'
	sub ah, al
	mov byte [digit], ah

	mov eax, 1
	mov ebx, 0
	int 80H

