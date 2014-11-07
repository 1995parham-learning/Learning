section .bss
	number: resb 2
	index: resb 2
section .text
	global main
main:
	mov eax,3	;READ SYSCALL
	mov ebx,0
	mov ecx,number
	mov edx,1
	int 0x80
	
	mov eax,4	;WRITE SYSCALL
	mov ebx,1
	mov [number+1],byte 0xA
	mov ecx,number
	mov edx,2
	int 0x80

	mov esi,0
for:
	mov eax,4
	mov ebx,1
	mov ecx,esi
	add ecx,48
	mov [index],byte ecx
	mov [index+1],byte 10
	mov ecx,index
	mov edx,2
	int 0x80
	inc esi
	cmp esi,10
	jne for
	
	mov eax,1	;EXIT SYSCALL
	mov ebx,0
	int 0x80
