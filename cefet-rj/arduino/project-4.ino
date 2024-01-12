/*
  [Circuit] - https://www.tinkercad.com/things/jNNoUbgpfa8?sharecode=B4f1ccE7KIEXzuClohs2EI-TYFc7oyorWqczLGBU51E
*/

// v4 - Serial Monitor Converter + LED
int number;
int port[]= {3,4,5,6,7,8,9,10};

void setup() {
  Serial.begin(9600);
  for(int i = 0; i < 0; i++)
    pinMode(port[i], OUTPUT);
}

void loop() {
  if (Serial.available( )> 0)
    number = Serial.parseInt();
  
  Serial.print("Decimal: ");
  Serial.println(number, DEC);
  
  Serial.print("Binario: ");
  Serial.println(number, BIN);
  
  Serial.println(" ");

  number = number % 255;
  for(int i = 0; i < 8; i++)
    digitalWrite(port[i], bitRead(number, i));
    delay (500);
}


/* v3 - Serial Monitor Converter
int number1;
float number2;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()>0)
    number1 = Serial.parseInt();
  
  Serial.print("Decimal: ");
  Serial.println(number1, DEC);
  
  Serial.print("Binario: ");
  Serial.println(number1, BIN);

  Serial.print("Octal: ");
  Serial.println(number1, OCT);

  Serial.print("Hexadecimal: ");
  Serial.println(number1, HEX);

  if (Serial.available()>0)
    number2 = Serial.parseFloat();
  
  Serial.print("Float: ");
  Serial.println(number2, 3);
  
  Serial.println(" ");
  delay(5000);
} */


/* v2 - Serial Monitor Read II
char char1 = 'a';
char char2 = 66; //ASCII
char number1 = '2';
char number2 = 55; //ASCII

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(char1);
  Serial.println(char1, DEC); //ASCII
  Serial.println(" ");
  
  Serial.println(char2);
  Serial.println(char2, DEC); //ASCII
  Serial.println(" ");
  
  Serial.println(number1);
  Serial.println(number1, DEC); //ASCII
  Serial.println(" ");
  
  Serial.println(number2);
  Serial.println(number2, DEC); //ASCII
  Serial.println(" ");

  Serial.println(char1 + char2); //ASCII
  Serial.println(number1 + number2); //ASCII
  Serial.println(char1 + number2); //ASCII
  Serial.println(char2 + number1); //ASCII
  
  Serial.println(" ");
  delay(20000);
} */


/* v1 - Serial Monitor Read
float number1 = 3.2222;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(number1);
  Serial.println(number1, 1);
  Serial.println(" ");
  
  number += 0.0005;
  Serial.print("add: ");
  Serial.println(number1, 4);
  Serial.println(" ");
  
  delay(5000);
} */
