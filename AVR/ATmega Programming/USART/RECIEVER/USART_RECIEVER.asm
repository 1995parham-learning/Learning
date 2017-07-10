;
; USART_RECIEVER.asm
;
; Created: 5/27/2017 7:54:22 AM
; Author : aligholamee
;
; Program to connect the atmega16 with the virtual DB9 port through MAX232
.include "m16_LCD_4bit.inc"
.def ROW = R21
.def COL = R25
.def BAUD_LOW = R19
.def BAUD_HIGH = R24
.def TEMP2 = R20
.def LCD_GUARD = R22
.def RECIEVE_STATUS = R23
;======================VECTORS==========================================

;======================VECTORS==========================================

;======================MAIN PROGRAM=====================================
start:
;======================USART_INIT=======================================
	; Set the LCD_GUARD to 15
	ldi LCD_GUARD,10
	; Load row and col with 0 for compare purpose
	ldi COL,0
	ldi ROW,100

	; Set the baud rate to 4800 bps
	ldi BAUD_LOW,12
	ldi BAUD_HIGH,0
	; Configure the baud rate
	out UBRRH,BAUD_HIGH
	out UBRRL,BAUD_LOW

	; Enable USART send and recieve + Their interrupts
	ldi TEMP,(1 << UCSZ2)|(1 << RXEN)|(1 << TXEN)|(1 << TXCIE)|(1 << RXCIE)
	out UCSRB,TEMP

	; Configure the clock generation mode
	; Configure the USART polarity mode 
	; The even parity will be used
	; Configure the stop bits
	; Configure the data bits = 9 bits for data
	ldi TEMP,(1 << URSEL)|(0 << UPM0)|(0 << UPM0)|(0 << UMSEL)|(1 << USBS)|(1 << UCSZ0)|(1 << UCSZ1)
	out UCSRC,TEMP
;======================USART_INIT=======================================
RECIEVE_DATA_SECTION:
	; Simply grab the data from the usart input 
	; Tha DATA_RECIEVE routine has to be called all the time
	call DATA_RECIEVE
	rjmp RECIEVE_DATA_SECTION

;======================MAIN PROGRAM=====================================

;======RECIEVING THE DATA==========
DATA_RECIEVE:
	; Wait for the data to be recieved 
	sbis UCSRA,RXC
	rjmp DATA_RECIEVE
	; Get the status and 9th bit, then the data from buffer
	in RECIEVE_STATUS,UCSRA
	in TEMP2,UCSRB
	in TEMP,UDR
	; If error, return -1
	andi r18,(1 << FE)|(1 << DOR)
	breq USART_ReceiveNoError

	ldi TEMP2, HIGH(-1)
	ldi TEMP, LOW(-1)
USART_ReceiveNoError:
	; Filter the 9th bit, then return
	lsr TEMP2
	andi TEMP2, 0x01

	mov argument,TEMP
	call LCD_putchar
	call LCD_delay
	ret
;======RECIEVING THE DATA==========
