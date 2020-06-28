section .bss
	number1: resd 1
	number2: resd 1
	result:  resb 5
section .text
	global main
main:
	mov eax,3
	mov ebx,0
	mov ecx,number1
	mov edx,4
	int 0x80

	mov eax,3
	mov ebx,0
	mov ecx,number2
	mov edx,4
	int 0x80

	mov eax,4
	mov ebx,1
	mov ecx,[number1]
	add ecx,[number2]
	mov [result],dword ecx
	mov [result+4],byte 10
	mov ecx,result
	mov edx,5
	int 0x80

	mov eax,1
	mov ebx,0
	int 0x80
