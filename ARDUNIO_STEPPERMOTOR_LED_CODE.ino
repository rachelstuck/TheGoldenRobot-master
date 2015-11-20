/*
ONE STEPPER AND LEDS

CONTROLS LEDS AND ONE STEPPER MOTOR FOR HORIZONTAL COMPONENT.

CREATED 5 NOVEMBER 2015
NORA REGEB MAVRAKIS

*/

//int led = 12;           // the pin that the LED is attached to
//int brightness = 140;    // how bright the LED is from 0 to 255
//int fadeAmount = 140;    // how many points to fade the LED by

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61);
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61);

// Connect a stepper motor with 200 steps per revolution (1.8 degree)
// to motor port #2 (M3 and M4)
Adafruit_StepperMotor *myMotor1 = AFMS.getStepper(200, 2);

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 13 to be an output:
  //pinMode(led, OUTPUT);
  pinMode(13, OUTPUT);

  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Stepper test!");

  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz

  myMotor1->setSpeed(40);  // 0.4 rpm

  // set the brightness of pin 13:
  //analogWrite(led, brightness);
  
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second


  Serial.println("Single coil steps");
  myMotor1->step(100, FORWARD, SINGLE);
    delay(2000);  //2000 ms
  myMotor1->step(100, BACKWARD, SINGLE);
    delay(2000);  //2000 ms


  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second 
  }

void loop() {
}


