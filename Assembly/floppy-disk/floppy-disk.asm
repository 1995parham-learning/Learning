section .text
	org 7C00H

	jmp short Start

Msg:	db "Hello world !!"
EndMsg:

Start:	mov bx, 000FH
	mov cx, 1
	xor dx, dx
	mov ds, dx
	cld

Print:	mov si, Msg

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
	jmp Print

times 0200H - 2 - ($ - $$) db 0

	dw 0AA55H
times 1474560 - ($ - $$) db 0
