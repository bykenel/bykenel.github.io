/*
  [Circuit] - https://www.tinkercad.com/things/du4mpkRHebd?sharecode=8rGOdj_gvZNfvPGvnz_MfA7RpYREJl6rM77dV2NUZns
*/

// v1 - Blink
int ledBlue = 13;
int ledRed = 12;

void setup() {
  pinMode(ledBlue, OUTPUT);
  pinMode(ledRed, OUTPUT);
}

void loop() {
  digitalWrite(ledBlue, HIGH);
  digitalWrite(ledRed, LOW);
  delay(500);
  digitalWrite(ledBlue, LOW);
  digitalWrite(ledRed, HIGH);
  delay(500);
}
