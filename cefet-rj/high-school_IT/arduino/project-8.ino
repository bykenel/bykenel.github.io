/*
  [Circuit] - v3: https://www.tinkercad.com/things/kdYYtmwI9pt?sharecode=-NpQ_uYLzydNcweA2drNWgzpMbDqP7yp8DO_LPqCvBs
*/

// v3 - PIR Sensor
int led1 = 6;
int led2 = 5;
int pir = 3;
int trigger;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(pir, INPUT);
}

void loop() {
  trigger = digitalRead(pir);
  if (trigger == LOW) {
    digitalWrite(led1, HIGH); digitalWrite(led2, LOW);
  }
  else {
    digitalWrite(led1, LOW); digitalWrite(led2, HIGH);
  }
}


/* v2 - Distance Alarm Prototype
#include <Ultrasonic.h>

Ultrasonic ultrasonic(8,7);
const int buzzer = 13;
int led = 9;
long distance;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  distance = ultrasonic.read(CM);
  Serial.print(distance);
  Serial.println("cm");
  delay(100);
  if (distance <= 20) {
    tone (buzzer, distance, 100); 
    digitalWrite(led, HIGH); delay(100); digitalWrite(led, LOW);
  }
  else if (distance <= 80) {
    tone (buzzer, distance, 100); 
    digitalWrite(led, HIGH); delay(600); digitalWrite(led, LOW);
  }
}
*/


/* v1 - HC-SR04 Sensor
#include <Ultrasonic.h>

Ultrasonic ultrasonic(8,7);
long distance;

void setup() {
  Serial.begin(9600);
}

void loop() {
  distance = ultrasonic.read(CM);
  Serial.print(distance);
  Serial.println("cm");
  delay(100);
}
*/
