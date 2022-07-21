/*
  [Circuit] - https://www.tinkercad.com/things/jf8Y3uW70Tq?sharecode=Ih1cIS2i4uazdbtXu9KrwdWPay3_udzKnpWqFJnEoNk
*/

// v1 - Morse Code Transmitter
const int buzzer = 13;
int led = 9;
int button = 2;
const int sendButton = 8;
volatile byte state = LOW;
int start;
String w;
String result;
      
void setup()
{
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(sendButton, INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(button), write, CHANGE);
}

void loop() {
  if (!digitalRead(sendButton) == LOW) {
    Serial.println(w);
    if(w == ".-") result += "A";
    else if(w == "-...")result += "B";
    else if(w == "-.-.")result += "C";
    else if(w == "-..")result += "D";
    else if(w == ".")result += "E";
    else if(w == "..-.")result += "F";
    else if(w == "--.")result += "G";
    else if(w == "....")result += "H";
    else if(w == "..")result += "I";
    else if(w == ".---")result += "J";
    else if(w == "-.-")result += "K";
    else if(w == ".-..")result += "L";
    else if(w == "--")result += "M";
    else if(w == "-.")result += "N";
    else if(w == "---")result += "O";
    else if(w == ".--.")result += "P";
    else if(w == "--.-")result += "Q";
    else if(w == ".-.")result += "R";  
    else if(w == "...")result += "S";
    else if(w == "-")result += "T";
    else if(w == "..-")result += "U";
    else if(w == "...-")result += "V";
    else if(w == ".--")result += "W";
    else if(w == "-..-")result += "X";
    else if(w == "-.--")result += "Y";
    else if(w == "--..")result += "Z";
    else if(w == ".----")result += "1";
    else if(w == "..---")result += "2";
    else if(w == "...--")result += "3";
    else if(w == "....-")result += "4";
    else if(w == ".....")result += "5";
    else if(w == "-....")result += "6";
    else if(w == "--...")result += "7";
    else if(w == "---..")result += "8";
    else if(w == "----.")result += "9";
    else if(w == "-----")result += "0";
    else result = "?";
    
    Serial.println(result);
    w = "";
    delay(1000);
  }
}

void write(){
  state = !state;
  if (state) {
    start = millis();
  } else {
      int interval = millis()-start;
      if (interval < 500) {
        w = w + ".";
        digitalWrite(led, HIGH); delay(500); digitalWrite(led, LOW);
        tone (buzzer, 330, 100);
      } else {
          w = w + "-";
          digitalWrite(led, HIGH); delay(3000); digitalWrite(led, LOW);
          tone (buzzer, 1596, 200);
        }
    }
}
