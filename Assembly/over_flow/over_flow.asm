section .data
	big_data: dd 0xFFFFFFFF
section .text
	global main
main:
	mov eax,[big_data]
	add eax,1

	mov eax,1
	mov ebx,0
	int 0x80
