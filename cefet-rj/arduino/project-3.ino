/*
  [Circuit] - https://www.tinkercad.com/things/gMKhoWDNx5t?sharecode=rq4Syph_xlTCdAGzrjpG4yd_TTCqzBdZ27L3vr11UyE
*/

// v3 - Traffic Light + Pedestrian Traffic Light + Activator Button
int ledGreen = 13;
int ledYellow = 12;
int ledRed = 11;

int ledGreen2 = 10;
int ledRed2 = 9;

int button = 2;
int buttonState = 0;

void turnOn (int port) {
  digitalWrite(port, HIGH);
}

void turnOff (int port) {
  digitalWrite(port, LOW);
}  

void setup() {
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);
  
  pinMode(ledGreen2, OUTPUT);
  pinMode(ledRed2, OUTPUT);
  
  pinMode(button, INPUT);
}

void loop() {
  turnOn(ledGreen); turnOn(ledRed2);
  buttonState = digitalRead(button);
  
  if (buttonState == HIGH) {
    delay(2000); turnOff(ledGreen);
    turnOn(ledYellow); delay(3000); turnOff(ledYellow); turnOff(ledRed2);
    turnOn(ledRed); turnOn(ledGreen2); delay(5000);
    turnOff(ledRed); turnOff(ledGreen2);
  }  
}


/* v2 - Traffic Light + Pedestrian Traffic Light
int ledGreen = 13;
int ledYellow = 12;
int ledRed = 11;

int ledGreen2 = 10;
int ledRed2 = 9;

void turnOn (int port) {
  digitalWrite(port, HIGH);
}

void turnOff (int port) {
  digitalWrite(port, LOW);
}  

void setup() {
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);
  
  pinMode(ledGreen2, OUTPUT);
  pinMode(ledRed2, OUTPUT);
}

void loop() {
  turnOn(ledGreen);
  turnOn(ledRed2);
  delay(5000);
  turnOff(ledGreen);
  
  turnOn(ledYellow);
  delay(2000);
  turnOff(ledYellow);
  turnOff(ledRed2);
  
  turnOn(ledRed);
  turnOn(ledGreen2);
  delay(3500);
  turnOff(ledRed);
  turnOff(ledGreen2);
}
/*


/* v1 - Traffic Light
int ledGreen = 13;
int ledYellow = 12;
int ledRed = 11;

void turnOn (int port) {
  digitalWrite(port, HIGH);
}

void turnOff (int port) {
  digitalWrite(port, LOW);
}  

void setup() {
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);
}

void loop() {
  turnOn(ledGreen);
  delay(5000);
  turnOff(ledGreen);
  
  turnOn(ledYellow);
  delay(2000);
  turnOff(ledYellow);
  
  turnOn(ledRed);
  delay(3500);
  turnOff(ledRed);
}
*/
