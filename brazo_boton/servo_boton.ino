#include <Servo.h>

const int buttonPin = 4;
const int ledPin = 13;
const int top = 90;

int buttonState = LOW;
boolean isOpen = false;
Servo servo1;
Servo servo2;

void setup() {
  pinMode(buttonPin,INPUT);
  pinMode(ledPin,OUTPUT);  
  servo1.attach(8);
  servo1.write(0);  
  servo2.attach(9);
  servo2.write(0);  
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
    if (isOpen) {
      closeArm();
      isOpen = false;
    } else {
      openArm();
      isOpen = true;
    }
  } else {
    digitalWrite(ledPin, LOW);
  }
}

void openArm() {
  for(int pos = 0; pos <= top; pos += 1)
  {
    servo1.write(pos);
    servo2.write(pos);        
    delay(5);
  }
}

void closeArm() {
  for(int pos = top; pos >= 0; pos -= 1)
  {
    servo1.write(pos);
    servo2.write(pos);        
    delay(5);
  }
}
