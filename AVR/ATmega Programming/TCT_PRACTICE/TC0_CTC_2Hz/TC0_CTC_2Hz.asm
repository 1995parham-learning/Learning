;
; TCT0_CTC_2Hz.asm
;
; Created: 5/8/2017 4:58:08 PM
; Author : aligholamee
;

;======================VECTORS==========================================
.def TEMP = R16
.def GLOBAL_COMPARE_MATCH_COUNTER = R17

; RESET Vector
.org $000
	jmp RESET_ISR

; TC0 Compare Match Vector
.org $026
	jmp TC0_ISR
;======================VECTORS==========================================


;======================TC0_COMPARE_MATCH_ISR=================================
TC0_ISR:
	cli
	; Simply increment the global counter for compare match
	inc GLOBAL_COMPARE_MATCH_COUNTER
	sei
	ret
;======================TC0_COMPARE_MATCH_ISR=================================


;======================RESET_ISR========================================
RESET_ISR:
	
	; Stack Init
	ldi TEMP,HIGH(RAMEND)	
	out SPH,TEMP
	ldi TEMP,LOW(RAMEND)
	out SPL,TEMP

	; Configure the clock source for TC0
	; The clock source is selected by the clock select logic which is controlled 
    ; by the clock select (CS02:0) bits located in the Timer/Counter Control Register (TCCR0)
	; Configure the TC0 Mode
	; Waveform Generation Mode Bits (WGM00 - WGM01)
	; These bits control the counting sequence of the counter, the source for the maximum (TOP)
	; counter value, and what type of Waveform Generation to be used
	; Configure the COM Bits
	; Since there are no compare matches going to happen in this program, 
	; we will make sure they are 0 :)
	ldi TEMP,(1 << CS02) | (0 << CS01) | (1 << CS00)| (0 << WGM00) | (0 << WGM01) | (0 << COM00) | (0 << COM01) 
	out TCCR0,TEMP

	; Set PB3 as output
	ldi TEMP,(1 << PB3)
	out DDRB,TEMP

	; Compare Match 0 interrupt enable 
	ldi TEMP,(1 << OCIE0)
	out TIMSK,TEMP

	; Reset the prescaler in the SFIOR
	ldi TEMP,(1 << PSR10)
	out SFIOR,TEMP

	; Set the value of OCR0 = 0xFF 
	ldi TEMP,0xFF
	out OCR0,TEMP

	; Global Interrupt Enable
	sei
;======================RESET_ISR========================================


;======================MAIN=============================================
start:
	; Check the value of GLOBAL_OVERFLOW_COUNTER
	cpi GLOBAL_COMPARE_MATCH_COUNTER,1
	brne start
    call TOGGLE_LED
	jmp start
;======================MAIN=============================================


;======================TOGGLE_LED=======================================
TOGGLE_LED:
	sbis PORTB,3
	jmp TURN_ON

TURN_OFF:
	ldi temp,(0 << PB3)
	out PORTB,temp
	ldi GLOBAL_COMPARE_MATCH_COUNTER,0
	ret
TURN_ON:
	ldi temp,(1 << PB3)
	out PORTB,temp
	ldi GLOBAL_COMPARE_MATCH_COUNTER,0
	; Get back to where you left ;)
	ret
;======================TOGGLE_LED=======================================