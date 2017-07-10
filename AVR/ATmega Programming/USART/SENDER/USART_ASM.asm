;
; USART_ASM.asm
;
; Created: 5/21/2017 9:32:59 PM
; Author : aligholamee
;
; Program to connect the atmega16 with the virtual DB9 port through MAX232
.include "m16_LCD_4bit.inc"
.def ROW = R21
.def COL = R25
.def BAUD_LOW = R19
.def BAUD_HIGH = R24
.def TEMP2 = R20
.def DATA_TO_BE_SENT = R22
.def SEMAPHORE = R23
;======================VECTORS==========================================

;======================VECTORS==========================================

;======================MAIN PROGRAM=====================================
start:
;======================USART_INIT=======================================
	; Load row and col with 0 for compare purpose
	ldi COL,'0'
	ldi ROW,'0'

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
DATA_SENDING_SECTION:
	; In this section, the keypad will be analyzed to see if any button is pressed
	; Analayze the keypad
	; If nothing was pressed, jump to recieve data section
	; Check the keypad buttons press status
	call FIND_PRESSED	
	cpi ROW,'0'
	breq DATA_SENDING_SECTION
	call DATA_TRANSMIT
	/*rjmp DATA_SENDING_SECTION*/
end:
	jmp end
;======TRANSMITTING THE DATA=======
DATA_TRANSMIT:
	call BIG_DELAY
	call MIX_TOGETHER
GET_BACK:
	; Wait for the UDRE to get set(UDR CLEARED)
	sbis UCSRA,UDRE
	rjmp DATA_TRANSMIT
	; Do a simple parity check before sending data
	; This is not optional because the parity bit will be send with other 8 bits as bit #9
	;call TRANSMITTER_PARITY_CHECK
	; Copy 9th bit from r17 to TXB8
	cbi UCSRB,TXB8
	; Enable USART send and recieve + Their interrupts
	out UDR,DATA_TO_BE_SENT
	; Data is now being sent
	ret
;======TRANSMITTING THE DATA=======
;===========FIND KEY===============
FIND_PRESSED:
	
FIND_COL:
	; Configure the DDRC
	ldi TEMP,0x0F
	out DDRC,TEMP

	; Configure the pull-ups
	; The ones that are input will be set as pull-up
	ldi TEMP,0xF0
	out PORTC,TEMP

	; Find the column easily by checking the PINC high bits
	sbis PINC,4
	ldi COL,'1'
	sbis PINC,5
	ldi COL,'2'
	sbis PINC,6
	ldi COL,'3'
	sbis PINC,7
	ldi COL,'4'

FIND_ROW:
	; Configure the DDRC
	ldi TEMP,0xF0
	out DDRC,TEMP

	; Configure the PORTC low bits pull-up
	ldi TEMP,0x0F
	out PORTC,TEMP
	
	; Find the row easily by checking the PINC low bits
	sbis PINC,0
	ldi ROW,'1'
	sbis PINC,1
	ldi ROW,'2'
	sbis PINC,2
	ldi ROW,'3'
	sbis PINC,3
	ldi ROW,'4'
	; now we have the pressed key row and column return to main routine
	ret

MIX_TOGETHER:
	cpi ROW,'0'
	breq ROW_1
	cpi ROW,'1'
	breq ROW_2
	cpi ROW,'2'
	breq ROW_3
	cpi ROW,'3'
	breq ROW_4
	
ROW_1:
	cpi COL,'0'
	breq DATA_IS_0
	cpi COL,'1'
	breq DATA_IS_1
	cpi COL,'2'
	breq DATA_IS_2
	cpi COL,'3'
	breq DATA_IS_3
ROW_2:
	cpi COL,'0'
	breq DATA_IS_4
	cpi COL,'1'
	breq DATA_IS_5
	cpi COL,'2'
	breq DATA_IS_6
	cpi COL,'3'
	breq DATA_IS_7
ROW_3:
	cpi COL,'0'
	breq DATA_IS_8
	cpi COL,'1'
	breq DATA_IS_9
	cpi COL,'2'
	breq DATA_IS_A
	cpi COL,'3'
	breq DATA_IS_B
ROW_4:
	cpi COL,'0'
	breq DATA_IS_C
	cpi COL,'1'
	breq DATA_IS_D
	cpi COL,'2'
	breq DATA_IS_E
	/*cpi COL,'3'
	breq DATA_IS_F*/


DATA_IS_0:
	ldi DATA_TO_BE_SENT,'0'
	jmp GET_BACK
DATA_IS_1:
	ldi DATA_TO_BE_SENT,'1'
	jmp GET_BACK
DATA_IS_2:
	ldi DATA_TO_BE_SENT,'2'
	jmp GET_BACK
DATA_IS_3:
	ldi DATA_TO_BE_SENT,'3'
	jmp GET_BACK
DATA_IS_4:
	ldi DATA_TO_BE_SENT,'4'
	jmp GET_BACK
DATA_IS_5:
	ldi DATA_TO_BE_SENT,'5'
	jmp GET_BACK
DATA_IS_6:
	ldi DATA_TO_BE_SENT,'6'
	jmp GET_BACK
DATA_IS_7:
	ldi DATA_TO_BE_SENT,'7'
	jmp GET_BACK
DATA_IS_8:
	ldi DATA_TO_BE_SENT,'8'
	jmp GET_BACK
DATA_IS_9:
	ldi DATA_TO_BE_SENT,'9'
	jmp GET_BACK
DATA_IS_A:
	ldi DATA_TO_BE_SENT,'A'
	jmp GET_BACK
DATA_IS_B:
	ldi DATA_TO_BE_SENT,'B'
	jmp GET_BACK
DATA_IS_C:
	ldi DATA_TO_BE_SENT,'C'
	jmp GET_BACK
DATA_IS_D:
	ldi DATA_TO_BE_SENT,'D'
	jmp GET_BACK
DATA_IS_E:
	ldi DATA_TO_BE_SENT,'E'
	jmp GET_BACK

BIG_DELAY:
	ldi TEMP2,0xFF
loop1:
	dec TEMP2
	brne loop1
	ret