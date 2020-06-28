; In The Name Of God
; ========================================
; [] File Name : bootloader.asm
; 
; [] Creation Date : 21-12-2014
;
; [] Last Modified : Wed 31 Dec 2014 06:23:22 PM IRST
;
; [] Created By : Parham Alvani (parham.alvani@gmail.com)
; =======================================
section .text
	org 07C00H

	jmp short Start

Msg:	db "Parham Alvani"
EndMsg:

Start:	xor dx, dx
	mov ds, dx
	cld

Print:	mov es, dx

	mov ah, 06H	; cls
	mov ch, 0	; start point row
	mov cl, 0	; start point column
	mov dh, 25	; end point row
	mov dl, 80	; end point column
	mov al, 25	; number line of scroll
	mov bh, 0	; color of new screen
	int 10H
	
	mov dx, es

	mov si, Msg
	
	mov bx, 000EH
	mov cx, 1

Char:	mov ah, 2
	int 10H
	lodsb
	mov ah, 9
	int 10H

	inc dl

	cmp dl, 80
	jne Skip
	xor dl, dl
	inc dh

	cmp dh, 25
	jne Skip
	xor dh, dh

Skip:	cmp si, EndMsg
	jne Char
	xor cx, cx
	mov cx, 0FFFH
	jmp Sleep

Sleep:
	times 64 nop
	loop Sleep
	jmp Print

times 0200H - 2 - ($ - $$) db 0

	dw 0AA55H
