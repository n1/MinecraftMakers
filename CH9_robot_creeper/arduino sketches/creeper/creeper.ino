#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"
#include <Servo.h> 
#include <Adafruit_NeoPixel.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Adafruit_DCMotor *leftMotors = AFMS.getMotor(3);
Adafruit_DCMotor *rightMotors = AFMS.getMotor(4);
Servo servo1;

#define PIN 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(14, PIN, NEO_GRB + NEO_KHZ800);

const int buzzerPin = 13;

void setup()
{
  Serial.begin(9600);
  AFMS.begin();  
  servo1.attach(10);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}


void loop() {
  if (Serial.available() >= 2)
  {
    char start = Serial.read();
    if (start != '*')
    {
      return;
    }

    char cmd = Serial.read();
    process_incoming_command(cmd);
  }



  delay(50); //limit how fast we update
}

void process_incoming_command(char cmd)
{
  int speed = 0;
  switch (cmd)
  {
  case 0:
    //DO NOTHING
    break;

  case 1:
    //DRIVE LEFT WHEELS
    leftMotors->setSpeed(200);
    leftMotors->run(RELEASE);
    break;

  case 2:
    //DRIVE RIGHT WHEELS
    rightMotors->setSpeed(200);
    rightMotors->run(RELEASE);
    break;

  case 3:
    //TURN ON EYES
    strip.setPixelColor(0, 255, 0, 0);
    strip.setPixelColor(1, 255, 0, 0);
    strip.setPixelColor(2, 255, 0, 0);
    strip.setPixelColor(3, 255, 0, 0);
    strip.setPixelColor(4, 255, 0, 0);
    strip.setPixelColor(5, 255, 0, 0);
    strip.setPixelColor(6, 255, 0, 0);
    strip.setPixelColor(7, 255, 0, 0);
    strip.setPixelColor(8, 255, 0, 0);
    strip.setPixelColor(9, 255, 0, 0);
    strip.setPixelColor(10, 255, 0, 0);
    strip.setPixelColor(11, 255, 0, 0);
    strip.setPixelColor(12, 255, 0, 0);
    strip.setPixelColor(13, 255, 0, 0);
    strip.show();
    break;

  case 4:
    //TURN OFF EYES
    strip.setPixelColor(0, 0, 0, 0);
    strip.setPixelColor(1, 0, 0, 0);
    strip.setPixelColor(2, 0, 0, 0);
    strip.setPixelColor(3, 0, 0, 0);
    strip.setPixelColor(4, 0, 0, 0);
    strip.setPixelColor(5, 0, 0, 0);
    strip.setPixelColor(6, 0, 0, 0);
    strip.setPixelColor(7, 0, 0, 0);
    strip.setPixelColor(8, 0, 0, 0);
    strip.setPixelColor(9, 0, 0, 0);
    strip.setPixelColor(10, 0, 0, 0);
    strip.setPixelColor(11, 0, 0, 0);
    strip.setPixelColor(12, 0, 0, 0);
    strip.setPixelColor(13, 0, 0, 0);
    strip.show();

    break;

  case 5:
    //TURN HEAD 90DEG LEFT
    servo1.write(0);
    delay(15); 
    break;

  case 6:
    //TURN HEAD 45DEG LEFT

    servo1.write(45);
    delay(15); 
    break;

  case 7:
    //TURN HEAD FORWARD
    servo1.write(90);
    delay(15); 
    break;

  case 8:
    //TURN HEAD 45DEG RIGHT
    servo1.write(135);
    delay(15);    
    break;

  case 9:
    //TURN HEAD 90DEG RIGHT
    servo1.write(180);
    delay(15); 
    break;

  }
}


