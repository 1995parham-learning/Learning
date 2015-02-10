; In The Name Of God
; ========================================
; [] File Name : reverse.asm
; 
; [] Creation Date : 10-02-2015
;
; [] Last Modified : Tue 10 Feb 2015 11:24:47 AM IRST
;
; [] Created By : Parham Alvani (parham.alvani@gmail.com)
; =======================================
section .data
	array:	dd 1, 2, 3
	arrayLen: dd 3

section .text
global main

main:
	push dword array
	push dword [arrayLen]
	call reverse
	add esp, 8


reverse:
	push ebp		; setup stack
	mov ebp, esp
	sub esp, 0x40		; 64 bytes of local stack space

	; put parameters into registers
	mov ebx, [ebp + 12]           ; array
	mov edi, [ebp + 8]            ; len

	; set up loop
	mov ecx, 0

; push all the values onto the stack
.loopPush:
	mov eax, 4
	mul ecx
	push dword [ebx + eax]
	inc ecx
	cmp ecx, edi
	jl .loopPush
	mov ecx, 0

; pop all the values from the stack
.loopPop:
	mov eax, 4
	mul ecx
	pop dword [ebx + eax]
	inc ecx
	cmp ecx, edi
	jl .loopPop

; print the array
	;push dword [ebp+12]
	;push dword [ebp+8]
	;call printArray
	;add esp, 8

.end:
	mov esp,ebp	; undo "sub esp,0x40" above 																	
	pop ebp
	mov eax, ebx	; return the reversed array
	ret
