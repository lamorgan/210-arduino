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
const int analogInPin = A0;  // Analog input pin that the turbidity is attached to
const int analogInPin2 = A1; // Analog input pin that the Ph meter is attached to 

int blueled=13;

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
int phsensorValue = 0;        // ph value read
int phoutputValue = 0;          //ph value output
int phvalue=7;
int sensor=0;

//display screen
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7,8,9,10,11,12);

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  //blue LED
  pinMode(LED_BUILTIN, OUTPUT);
  //display screen words dont change
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.write("pH:");
  lcd.setCursor(0,1);
  lcd.write("Turbidity:");
  lcd.setCursor(14,1);
  lcd.write('%');
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // change the analog out value:
  phsensorValue = analogRead(analogInPin2);
  phoutputValue = map(phsensorValue, 0, 1023, 0, 255);

 
    //display screen values that change
  lcd.setCursor(4,0);
  lcd.print(phvalue);
  lcd.setCursor(11,1);
  lcd.print(round(sensorValue/9));
  delay(500);
  
  //controls led
  if((phvalue >= 6.5) && (phvalue <= 8.5) && (sensorValue >= 830))
{
  digitalWrite(LED_BUILTIN, HIGH);
}
else
{
  digitalWrite(LED_BUILTIN, LOW);
}



  // print the results to the serial monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print ("\t ph =");
  Serial.print(phsensorValue);
  Serial.print('\n');
  delay(2);



}




