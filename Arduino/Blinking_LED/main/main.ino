// Blinking LED, Arduino by MohamadKh75
// 2017-06-26
// ********************


const int LED = 13;   //connected to digital pin 13


void setup()
{
	pinMode(LED, OUTPUT);   //set digital pin as output
}


void loop()
{
	digitalWrite(LED, HIGH);    //turn on LED
	delay(1000);    //wait for 1000ms = 1 second

	digitalWrite(LED, LOW);    //turn off LED
	delay(1000);    //wait for 1000ms = 1 second
}
