;
; LED_TEST.asm
;
; Created: 4/1/2017 5:33:03 PM
; Author : Ali Gholami
;
; Program to test the LED ON/OFF states manually	
; This LED will stay on standby mode when not pressing the key
	start:
		/* set the PIND2 data direction to 0 for input */
		/* This one simulates the key */
		ldi R16, (0 << PD2)	; Make PD2 as input
		out DDRD,R16	; Configure the PIND2 as input
		/* set the PORTB7 data direction to 1 for output */
		/* this one causes the LED to be ON/OFF */
		ldi R17, (1 << PB7)	; Make PB7 as output 
		out DDRB,R17	; Configure the PORTB7 as output

	OFF_MODE:
		nop
		/* Put the PORTB7 to 0 */ 
		ldi R18,(0 << PB7)
		out PORTB,R18
		/* Skip if PIN 2 in PORT D is set */
		sbis PIND,2
		jmp OFF_MODE	; Branch to the OFF_MODE if the key isn't pressed yet

		call delay
		/* Make sure to clear the PIND2 before we continue */
		cbi PIND,2
	ON_MODE:
		nop
		/* Put the PORTB to 1 */
		ldi R18,(1 << PB7)
		out PORTB,R18
		/* Skip if PIN 2 in PORT D is set */
		sbis PIND,2
		jmp ON_MODE	; Branch to the ON_MODE if the key isn't unpressed yet
	rjmp start

delay:
    ldi r16, 0xFF
delay_loop_1:
    dec r16
    brne delay_loop_1
    ret