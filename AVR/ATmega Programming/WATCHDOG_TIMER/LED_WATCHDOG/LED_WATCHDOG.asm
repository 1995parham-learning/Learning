;
; LED_WATCHDOG.asm
;
; Created: 4/2/2017 9:45:43 AM
; Author : Ali Gholami
;
; A program to turn the LED on by pressing a key and wait for another key to prevent the WDT from reseting it
; so it will keep alive all the time (button press must be less than 2.1s)
; in case the LED goes off, we can enable it by pressing that first key 

; Replace with your application code
start:
	/******************************************/
	/* Configure the input and output ports */
    /* set the PINB0 data direction to 0 for input */
	/* This one simulates the key */
	ldi R16, (1 << PB0)	; Load 0b00000001 in R16
    out DDRB,R16	; Configure the PINB0 as input

	/* set the PINB1 data direction to 0 for input */
	/* This one simulates the key */
	/* This key will work as WDR */
	clr R16			; Clear the R16
	ldi R16, (1 << PB1)	; Load 0b00000020 in R16
    out DDRB,R16	; Configure the PINB1 as input

	/* set the PORTB data direction to 1 for output */
	/* this one causes the LED to be ON/OFF */
	ldi R17, (1 << PB7)	; Load 0b10000000 in R17
	out DDRB,R17	; Configure the PORTB7 as output



	/********************************/
	/* Configure the Watchdog timer initial values for a 2.1s timeout */
	; WDP2, WDP1, WDP0 must be confgure in order to use the 2.1 s timeout in wdt prescaling
	; those bits are in WDTCR
	; to use 2.1(s) timeout we need to put WDP2..WDP0 to "111" according to the data sheet
	
	/* Prepare the number that must be written in WDTCR */
	ldi R20,0x0F	; Write 0b00001111 in R20

	/* last 1 is for the WDE(Watchdog Enable) */
	/* First three 1s are for the 2.1s config */
	/* Put the result in the WDTCR */
	out WDTCR,R20
	/* Now we have the initialized WDT for a 2.1(s) delay */

	/************************************/
	/* Wait for the button to make the LED on */
OFF_MODE:
	/* Put the PORTB to 0 */
	/* Keep the LED off */ 
	ldi R18,(0 << PB7)
	out PORTB,R18
	/* Check the content of PINB0 */
	/* Wait for the PINB0 to get pressed by the user */
	sbis PINB,0
	brne OFF_MODE	; Branch to the OFF_MODE if the key isn't pressed yet

	/* Keep the LED in ON_MODE for unlimited seconds - This will cause the WDT to reset everything */
ON_MODE:
	/* Put the PORTB to 1 */
	ldi R18,(1 << PB7)
	out PORTB,R18
	/* Check the other button if the user make this reset manually */
	/* Check the content of PINB1 */
	sbis PINB,1
	brne ON_MODE	; Branch to the ON_MODE if the key isn't unpressed yet

	/* Simply reset the watchdog if the button is pressed */
	wdr

    rjmp start
