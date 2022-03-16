#include <analogWrite.h>
#define potPin 36
int valPot = 0;

void setup() {
  Serial.begin(9600);
  pinMode (27, OUTPUT);
}

void loop() {
  valPot = analogRead(potPin);
  analogWrite(27, valPot/16);
  Serial.println(valPot);
  delay(100);
}
