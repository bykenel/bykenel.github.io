/*
  [Circuit] - v1: https://www.tinkercad.com/things/bBJH9XURARP?sharecode=i2uB9gZWAIEn1dkTpm-WvwAHRTTkSD9Njj0Rv18yP84
              v2: https://www.tinkercad.com/things/79Wb5mFzl2L?sharecode=9I1_ixw-LL8a9CxPYzbdQkvHxqufzMbCuyGaPlN-m8Y
*/

// v2 - Servo + Button
#include <Servo.h>
#define SERVO 6 //Digital Port 6 PWM
Servo servo;
int pos; //Position
int i = 5;
int button = 2;
int buttonState = 0;

void setup() {
  pinMode(button, INPUT);
  Serial.begin(9600);
  servo.attach(SERVO);
  servo.write(0);
}

void loop() {
  int buttonState = digitalRead(button);
  if(buttonState == HIGH){
    pos += i;
    if (pos >= 180 || pos <= 0) {i *= -1;}
    Serial.println(pos);
    servo.write(pos);
    delay(100);
  }
}


/* v1 - Servo
#include <Servo.h>
#define SERVO 6 //Digital Port 6 PWM
Servo servo;
int pos; //Position

void setup() {
  servo.attach(SERVO);
  Serial.begin(9600);
  servo.write(0);
}

void loop() {
  for(pos = 0; pos < 180; pos++) {
    servo.write(pos);
    delay(15);
  }

  for(pos = 180; pos >= 0; pos--) {
    servo.write(pos);
  }
}
*/
