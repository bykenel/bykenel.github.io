// v1 - TCRT-5000 Sensor
int led = 8;
int infraRed =7;

void setup() {
  pinMode(infraRed, INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}

void loop() {
  if (digitalRead(infraRed) == LOW) {
    digitalWrite(led, LOW);
  } else {
     digitalWrite(led, HIGH);
  }
}
