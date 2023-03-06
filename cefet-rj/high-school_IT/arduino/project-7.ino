/*
  [Circuit] - v1: https://www.tinkercad.com/things/8hW5lHdEOxh?sharecode=08OERrfG-v2GeIsmI-dT5N8Ass7GOd8qj5oAAHhI1T0
              v2: https://www.tinkercad.com/things/3JOBob75pTh?sharecode=evynyePrU0minI9VOwKwfFwpOX3nESZAw--_4Rf5Y9Y
*/

// v3 - DHT Sensor
#include <dht.h>

dht DHT;
uint32_t timer = 0;

void  setup(){
  Serial.begin(9600);
}

void loop() {
  if(millis() - timer >= 2000){
    DHT.read11(A1);

    Serial.print(DHT.humidity);
    Serial.println("%");

    Serial.print(DHT.temperature);
    Serial.println(" Celsius");

    timer = millis();
  }
}


/* v2 - LM35 Sensor
const int LM35 = A0;
float temperature ;

void  setup(){
  Serial.begin(9600);
}

void loop() {
  temperature = (float(analogRead(LM35))*5/(1023))/0.01;
  Serial.print("Temperatura: ");
  Serial.println(temperature);
  delay(2000);
}
*/


/* v1 - LDR Sensor
int ledPin = 7;
int ldrPin = 0;
int ldrValue = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  ldrValue = analogRead(ldrPin);
  
  if  (ldrValue >= 800) digitalWrite(ledPin,HIGH);
  else digitalWrite(ledPin,LOW);
  
  Serial.println (ldrValue);
  delay(100);
} 
*/
