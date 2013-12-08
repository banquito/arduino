#include <MotorShield.h>
#include <Servo.h>

const int motorPin = 2;
const int servoPin = 4;
const int ledPin = 13;

int pos = 0;
int gruaState = LOW;
int directionState = LOW;
int servoState = LOW;

MS_DCMotor motor(MOTOR_A);
Servo servo;

void setup() {
  pinMode(servoPin,INPUT);
  pinMode(motorPin,INPUT);
  pinMode(ledPin,OUTPUT);
  
  motor.run(BRAKE);
  motor.setSpeed(255);
  
  servo.attach(7);
  servo.write(0);  
}

void loop() {
  gruaState = digitalRead(motorPin);
  if (gruaState == HIGH) {
    if(directionState==HIGH){
      motor.run(FORWARD|RELEASE);
    } else {
      motor.run(BACKWARD|RELEASE);
    }
  } else {
    digitalWrite(ledPin, LOW);
    motor.run(BRAKE);
    
    if(directionState==HIGH){
      directionState=LOW;
    } else {
      directionState=HIGH;
    }
  }

  servoState = digitalRead(servoPin);
  if (servoState == HIGH) {
    if (pos != 180) {
      for(pos = 0; pos <= 180; pos += 1)
      {
        servo.write(pos);
        delay(10);
      }
    }
    pos = 180;
    servo.write(180);
    //delay(50);
    digitalWrite(ledPin, HIGH);    
  } else {
    if (pos != 0) {
      for(pos = 90; pos >= 0; pos -= 1)
      {
        servo.write(pos);
        delay(10);
      }
    }
    pos = 0;
    servo.write(0);
    //delay(50);
    digitalWrite(ledPin, LOW);        
  }
  
}

