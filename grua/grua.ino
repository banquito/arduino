#include <MotorShield.h>

const int buttonPin = 2;
const int ledPin = 13;
int buttonState = 0;
MS_DCMotor motor(MOTOR_A);
int gruaState = 0;
void setup() {
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin,INPUT);
  // engage the motor's brake 
  motor.run(BRAKE);
  motor.setSpeed(255);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
    
    if(gruaState==HIGH){
      motor.run(FORWARD|RELEASE);
    } else {
      motor.run(BACKWARD|RELEASE);
    }
  } else {
    digitalWrite(ledPin, LOW);
    motor.run(BRAKE);
    
    if(gruaState==HIGH){
      gruaState=LOW;
    } else {
      gruaState=HIGH;
    }
  }
  
  // set direction to forward and release the brake in a single call
  
}

