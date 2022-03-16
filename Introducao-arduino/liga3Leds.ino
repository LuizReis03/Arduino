int lista[3] = {12, 14, 27};

void setup() {
  //declara os pinos
  pinMode(12, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(27, OUTPUT);
}

void loop() {
  for (int i = 0; i < 3; i++){
    digitalWrite(lista[i], HIGH);
    delay(500);
    digitalWrite(lista[i], LOW);
    delay(500);
  }
}
