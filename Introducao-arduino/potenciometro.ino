#define potPin 36
int valPot = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  valPot = analogRead(potPin);
  Serial.println(valPot);
  delay(100);
}
