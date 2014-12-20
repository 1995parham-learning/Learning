; In The Name Of God
; ========================================
; [] File Name : 
; 
; [] Creation Date : 21-12-2014
;
; [] Last Modified : Sun 21 Dec 2014 01:45:20 AM IRST
;
; [] Created By : Parham Alvani (parham.alvani@gmail.com)
; =======================================
section .text
	global parham_print
parham_print:
	push rcx
	mov rcx, rdi
	
	push rdx
	mov rdx, rsi

	mov rax, 4

	push rbx
	mov rbx, 1

	int 80h

	pop rbx
	pop rdx
	pop rcx

	ret
