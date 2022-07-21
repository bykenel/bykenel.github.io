/*
  [Circuit] - https://www.tinkercad.com/things/a4OAtS5isya?sharecode=6EvOcrQ_7AAatrEseB1rlpD_IW3Asx5Ef5CA6diQmK8
*/

// v2 - LED Activator Button + Counter
int led = 10;
int button = 2;
int buttonState = 0;

int count = 0; //v2

void ledOn(int i) {
  digitalWrite(led, HIGH);
  delay(i*1000);
  digitalWrite(led,LOW);
}

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  buttonState = digitalRead(button);
  if(buttonState == HIGH){
    count++;
    ledOn(count);
  }
}


/* v1 - LED Activator Button
int led = 10;
int button = 2;
int buttonState = 0;

int count = 0; //v2

void ledOn() {
  digitalWrite(led, HIGH);
  delay(3000);
  digitalWrite(led,LOW);
}

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  buttonState = digitalRead(button);
  if(buttonState == HIGH){
    ledOn();
  }
}
*/
