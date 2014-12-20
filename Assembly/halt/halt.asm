; In The Name Of God
; ========================================
; [] File Name : 
; 
; [] Creation Date : 21-12-2014
;
; [] Last Modified : Sun 21 Dec 2014 01:45:27 AM IRST
;
; [] Created By : Parham Alvani (parham.alvani@gmail.com)
; =======================================
section .text
	global _start
_start:
	hlt

	mov eax, 1
	mov ebx, 0
	int 80H
