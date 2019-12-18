
/*
 Stepper Motor Control - one revolution

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.

 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.


 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe

 */

#include <Stepper.h>

const int stepsPerRevolution = 20;  // change this to fit the number of steps per revolution
// for your motor
const int buttonPin = 12; 

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 5, 9, 10, 11);

int potPin = A0;    // select the input pin for the potentiometer
//int ledPin = 13;   // select the pin for the LED
int val = 0;    
int buttonState = 0; 

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(60);
  pinMode(buttonPin, INPUT_PULLUP);
  // initialize the serial port:
  Serial.begin(9600);
  
}

void loop() {
     
  buttonState = digitalRead(buttonPin);
    //int newVal=0;
   val = analogRead(potPin);    // read the value from the sensor
   int newVal=map(val,0,1023,100,800);
    //Serial.println(newVal);
    myStepper.setSpeed(newVal);
//
//     while (buttonState == LOW)
//     {
//      myStepper.setSpeed(0);
//     }
    if (buttonState == LOW)
    {
//    // turn LED on:
//    Serial.println("Low");
//    delay(2000);
    //myStepper.setSpeed(0);
//   // digitalWrite(ledPin, HIGH);
  } 
  else {
////    // turn LED off:
//        Serial.println("HIGh");
//        myStepper.setSpeed(newVal);   
myStepper.step(stepsPerRevolution);   
////       
////    //digitalWrite(ledPin, LOW);
}

   
  //Serial.println(val);

  
  // step one revolution  in one direction:
  //Serial.println("clockwise");
  




 // delay(500);

  // step one revolution in the other direction:
 // Serial.println("counterclockwise");
  
  //myStepper.step(-stepsPerRevolution);
  
  //delay(500);
}
