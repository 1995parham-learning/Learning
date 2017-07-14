;
; EDGE_LED_INTERRUPT.asm
;
; Created: 4/13/2017 6:07:36 AM
; Author : Ali Gholami
;
; A program to turn the LED on/off by pressing the SW1 button

; Reserved 2 bytes: jump to reset at the beginnning
.org 0x00
	jmp RESET_ISR

; Configuration: Put the interrupt 1 vector at address $002
.org 0x04
	jmp HANDLE_SW1

HANDLE_SW1:
	sbis PORTD,7
	jmp ON_MODE

OFF_MODE:
	; Create a delay
	call SHORT_DELAY
	; turn off the LED
	ldi R16,(0 << PD7)
	out PORTD,R16
	; Enable Global interrupt flag
	sei
	ret 


ON_MODE:
	; Create a delay
	call SHORT_DELAY
	; Otherwise, Turn on the LED here, set PD7 as output for LED
	ldi R16,(1 << PD7)
	out PORTD,R16

	; Enable Global interrupt flag
	sei
	ret

.org $1C00
RESET_ISR:
	; Set the PD7 as output
	ldi R16,(1 << PD7)|(0 << PD3)
	out DDRD,R16

	; Set stack pointer to the top of ram 
	ldi R16,high(RAMEND)
	out SPH,R16
	ldi R16,low(RAMEND)
	out SPL,R16

	; Configure the Rising Edge in the interrupt sense control
	ldi R16,(1 << ISC11) | (1 << ISC10)
	out MCUCR,R16

	; Enable INT1
	ldi R16, (1 << INT1) 
	out GICR, R16

	/*; Configuration: IVSEL = 0, BOOTRST = 0
	; Make sure that the IVSEL is set to 0
	ldi R16,(0 << IVCE)
	out GICR,R16
	ldi R16,(0 << IVSEL)
	out GICR,R16*/

	; Enable Global interrupt flag
	sei

	; make 
start:
	rjmp start

	; A short delay for synchronization between press and reaction
SHORT_DELAY:
	ldi r25,2
LOOP:
	dec R25
	brne LOOP
	ret
