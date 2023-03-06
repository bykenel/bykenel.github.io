/*
  [More Info] - https://www.arduino.cc/reference/en/libraries/liquidcrystal/
*/

// v1 - Liquid Crystal Display + Keyboard
#include <LiquidCrystal.h>

const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
const int backLight = 10;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 

struct{
  int limit; 
  char *name; 
} keys[] = {
    { 50, "RIGHT " },
    { 150,"UP    " },
    { 350,"DOWN  " },
    { 500,"LEFT  " },
    { 750,"SELECT" },
    {1024,"      " }
  };

void setup() {
  pinMode(backLight, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("INSERT TEXT HERE");
  digitalWrite(backLight, HIGH);
}

void loop(){
  static int previousKey = -1;
  int reading = analogRead(A0);
  int newKey;
  for (newKey = 0; ; newKey++){
     if(reading < keys[newKey].limit){
     break;
     }
  }
  
  if(newKey != previousKey){
     lcd.setCursor(0,1);
     lcd.print(keys[newKey].name);
  }
}
