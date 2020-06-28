; In The Name Of God
; ========================================
; [] File Name : over_flow.asm
; 
; [] Creation Date : 21-12-2014
;
; [] Last Modified : Sun 21 Dec 2014 02:00:17 AM IRST
;
; [] Created By : Parham Alvani (parham.alvani@gmail.com)
; =======================================
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
