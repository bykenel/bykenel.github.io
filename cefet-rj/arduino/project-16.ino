// v1 - Liquid Crystal Display + Keyboard + DHT Sensor + Servo
#include <LiquidCrystal.h>
#include <dht.h>
#include <Servo.h>

//Liquid Crystal Display
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
const int backLight = 10;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//DHT
dht DHT;
uint32_t timer = 0;
long DHThumidity;
long DHTtemperature;

//SERVO
#define SERVO A2 //Digital Port A2 PWM
Servo servo;
int pos; //Position
int i = 15;

void setup() {
  pinMode(backLight, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  digitalWrite(backLight, HIGH);
  servo.attach(SERVO);
  servo.write(0);
}

void loop(){
  DHT.read11(A1);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T: "); lcd.print(DHT.temperature); lcd.print(" C");
  lcd.setCursor(0, 1);
  lcd.print("H: "); lcd.print(DHT.humidity); lcd.print(" %");

  Serial.println(analogRead(0));
  if ((analogRead(0)) < 200) {
    moveServo();
  }
}

void moveServo() {
   pos += i;
   if (pos >= 180 || pos <= 0) {i *= -1;}
   Serial.println(pos);
   servo.write(pos);
   delay(100);
}
