/*
  [Circuit] - v1: https://www.tinkercad.com/things/3oleZcbaVkP?sharecode=7z3fKfBhoNnAiNRpY-Xr55g3-GkTEbmH2Pl1eHf8wHs
              v2: https://www.tinkercad.com/things/kSaDdVbrw9M?sharecode=GeyLh3zPe5bplLm8HZBPsfkBmg2U8tGzGnkixSsLazw
*/

// v2 - Trafic Light + Interrupt Pin
int ledGreen = 13;
int ledYellow = 12;
int ledRed = 11;
int interruptPin = 2;
volatile byte state = LOW;

void setInterval(int port, int interval){
  digitalWrite(port, HIGH);
  delay(interval);
  digitalWrite(port, LOW);
}

void setup() {
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE);
  
  digitalWrite(ledGreen, HIGH);
}

void loop() {
  if (state) {
    delay(5000);
    digitalWrite(ledGreen, LOW);
    setInterval(ledYellow, 3000);
    setInterval(ledRed, 2000);
    digitalWrite(ledGreen, HIGH);
    blink();
  }
}

void blink() {
  state = !state;
}


/* v1 - Interrupt Pin
const byte ledPin = 12;
const byte interruptPin = 2;
volatile byte state = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE);
}

void loop() {
  digitalWrite(ledPin, state);
}

void blink() {
  state = !state;
}
*/
