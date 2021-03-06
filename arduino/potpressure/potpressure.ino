/*
  Analog input, analog output, serial output
 
 Reads an analog input pin, maps the result to a range from 0 to 255
 and uses the result to set the pulsewidth modulation (PWM) of an output pin.
 Also prints the results to the serial monitor.
 
 The circuit:
 * potentiometer connected to analog pin 0.
   Center pin of the potentiometer goes to the analog pin.
   side pins of the potentiometer go to +5V and ground
 * LED connected from digital pin 9 to ground
 
 created 29 Dec. 2008
 modified 9 Apr 2012
 by Tom Igoe
 
 This example code is in the public domain.
 
 */

// These constants won't change.  They're used to give names
// to the pins used:
const int analogInPot = A0;  // Analog input pin that the potentiometer is attached to
const int analogInPressure = A2;  // Analog input pin that the potentiometer is attached to
const int analogOutLed = 9; // Analog output pin that the LED is attached to

int potValue = 0;        // value read from the pot
int ledOutputValue = 0;        // value output to the PWM (analog out)
int pressureValue = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in values:
  potValue = analogRead(A0); // pot poort uitlezen            
 pressureValue = analogRead(A2);  

// Write the value from the pot to the monitor          
  Serial.print("potValue:");
  Serial.println(potValue);  
  // write the value from the led to the monitor
  Serial.print("ledOutputValue:");  
  Serial.println(ledOutputValue);  
  // write the value from the pressure to the monitor
  Serial.print("pressureValue:");
  Serial.println(pressureValue);     // the raw analog reading

  // map it to the range of the analog out:
  ledOutputValue = map(potValue, 0, 1023, 0, 255);  
  // change the analog out value:
  analogWrite(analogOutLed,ledOutputValue);  // dit gaat naar de led!!



  // wait 1 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(1);                    
}
