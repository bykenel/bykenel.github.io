// v1 - Liquid Crystal Display + DHT
#include <LiquidCrystal.h>
#include <dht.h>

const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
const int backLight = 10;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//DHT
dht DHT;
uint32_t timer = 0;
long DHThumidity;
long DHTtemperature;

void setup() {
  pinMode(backLight, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("LCD + DHT");
  digitalWrite(backLight, HIGH);
}

void loop(){
  DHT.read11(A1);
  Serial.println(analogRead(0));

  if ((analogRead(0)) < 200) {
    up();
  }
  else if ((analogRead(0)) < 400) {
    down();
  }
       
  Serial.print(DHT.humidity); Serial.println(" %");
  Serial.print(DHT.temperature); Serial.println(" Celsius");
}

void up() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("HUMIDITY:");
  lcd.setCursor(0, 1);
  lcd.print(DHT.humidity);
}

void down() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("TEMPERATURE:");
  lcd.setCursor(0, 1);
  lcd.print(DHT.temperature);
} 
