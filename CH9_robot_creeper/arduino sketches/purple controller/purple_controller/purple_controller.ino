#include <Wire.h>

const int button1Pin = 5;
const int button2Pin = 6;
const int switch1Pin = 9;
const int ledRed = 10;
const int ledGreen = 11;

const int pot1Pin = A0;

int button1State = 0;
int button2State = 0;
int switch1State = 0;
int pot1State = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(switch1Pin, INPUT_PULLUP);
  pinMode(pot1Pin, INPUT_PULLUP);

  //LED SHINES YELLOW FOR BOOTUP
  digitalWrite(ledRed, HIGH);
  digitalWrite(ledGreen, HIGH);

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

    //LED GLOWS GREEN IF SERIAL IS AVAILABLE
    digitalWrite(ledRed, LOW);
    digitalWrite(ledGreen, HIGH);
    
    process_incoming_command(cmd);
  }
  else
  {
    //LED GLOWS RED IF SERIAL IS UNAVAILABLE
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledGreen, LOW);
    //END LEDS
  }


  //LETS LISTEN TO THE ARCADE BUTTONS

  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);


  //ARE BOTH PRESSED?

  if ((button1State == HIGH) && (button2State == HIGH)) {
    Serial.write('*');
    Serial.write(1);
  }

  //IS JUST ONE PRESSED?

  else if (button1State == HIGH) {
    Serial.write('*');
    Serial.write(2);
  }

  else if (button2State == HIGH) {
    Serial.write('*');
    Serial.write(3);
  }
  else {
    Serial.write('*');
    Serial.write(0);
  }


  //LISTENING TO THE SWITCH

  switch1State = digitalRead(switch1Pin);
  if (switch1State == HIGH) {
    Serial.write('*');
    Serial.write(4);
  }
  else {
    Serial.write('*');
    Serial.write(0);
  }

  //LISTENING TO POT & REMAPPING POT VALUE FROM 0-1023 TO 5-9.
  //THIS NUMBER BECOMES THE COMMAND SENT
  pot1State = analogRead(pot1Pin);
  int pot1Command = map(pot1State, 0, 5, 1023, 9);
  Serial.write('*');
  Serial.write(pot1Command);


  delay(50); //limit how fast we update
}


//STATUS DISPLAY

//MAKE INTO IF/ELSE

void process_incoming_command(char cmd)
{
  int speed = 0;
  switch (cmd)
  {
    case 1:
    //LED SHINES GREEN IF CREEPER'S PING RECEIVED
    digitalWrite(ledRed, LOW);
    digitalWrite(ledGreen, HIGH);
      break;

  }
}







