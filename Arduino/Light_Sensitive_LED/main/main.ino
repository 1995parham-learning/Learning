// Light Sensitive LED, Arduino by MohamadKh75
// 2017-07-02
// ********************


const int LED = 13;   //LED is connected to pin 9
const int LDR = A0;   //LDR is connected to pin 9
int LDR_status = analogRead(LDR);
bool is_on = false;   //true = LED is on  -  false = LED is off
bool prev = false;    //true = LED is on  -  false = LED is off

void setup()
{
  Serial.begin(9600);   //Set the serial conncetion to check the result in Serial Monitor
  pinMode(LED, OUTPUT);    //set digital pin as output
  pinMode(LDR, INPUT);   //set analog pin as input
}

void loop()
{
  LDR_status = analogRead(LDR);   //read the LDR status


  if (LDR_status <= 300)    //if it's Dark
    {
    prev = digitalRead(LED);    //read the previous state
    
    digitalWrite(LED, HIGH);    //turn the LED on
    is_on = true;   //state that LED is on
    }

  else    //so it's Light
    {
    prev = digitalRead(LED);    //read the previous state
    
    digitalWrite(LED, LOW);   //turn the LED off
    is_on = false;    //state that LED is off
    }


  if (is_on)    //if LED is on
      {
      if(!prev)   //and if previous state is off
        Serial.println("It's Dark! Let's have some light :D");
      }

  else    //if LED is off
      {
      if(prev)    //and if previous state is on
        Serial.println("Enough! LED is off!");
      }
}
