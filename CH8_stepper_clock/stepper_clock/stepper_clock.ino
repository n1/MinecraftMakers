
#include <Wire.h>
#include "RTClib.h"
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

RTC_DS1307 RTC;
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_StepperMotor *myMotor = AFMS.getStepper(513, 2);
const int limitSwitch = 3;

void setup() {

  Serial.begin(9600);
  Wire.begin();
  RTC.begin();
  AFMS.begin(); 

  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }

  myMotor->setSpeed(10);  // 10 rpm

//call the function that calibrates the stepper so that midnight is step 0.
  calibrate_Stepper();

}

void loop() {

  int currentStep;

//let's determine the time according to the RTC.
  DateTime now = RTC.now();
  int hourDisplay = (now.hour(), DEC);
  Serial.print(hourDisplay);
  Serial.print(':');
  int minuteDisplay = (now.minute(), DEC);
  Serial.println(minuteDisplay);

  //total time elapsed since midnight  
  int minutesElapsed=((hourDisplay * 60) + minuteDisplay);

  //map minutesElapsed: 24:00 (minute 1440) maps to 513 to get number of steps
  int timeSteps = map(minutesElapsed, 0, 1440, 0, 513);
  
      Serial.print("minutes elapsed: ");
    Serial.print(minutesElapsed);
      Serial.print("equals this number of steps: ");
          Serial.println(timeSteps);

  //while statement telling the Arduino how many steps to take
  while (currentStep < timeSteps) {
    myMotor->step(1, FORWARD, MICROSTEP);      
  }
}

//this function rotates the motor until the limit switch engages, creating step 0.
void calibrate_Stepper() {

  while (digitalRead(limitSwitch) == LOW)
  {
    myMotor->step(1, FORWARD, MICROSTEP);
  }

  int currentStep = 0;
  delay(10);

}











