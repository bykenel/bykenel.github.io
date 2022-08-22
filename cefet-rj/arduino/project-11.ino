/*
  [More Info] - https://www.arduino.cc/reference/en/libraries/liquidcrystal/
*/

// v1 - Liquid Crystal Display
#include <LiquidCrystal.h>

const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
const int backLight = 10;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 

void setup() {
  pinMode(backLight, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("(^w^)");
  digitalWrite(backLight, HIGH);
}

void loop(){
    
}
