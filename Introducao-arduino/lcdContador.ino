#include <LiquidCrystal.h>

LiquidCrystal lcd(19, 23, 18, 17, 16, 15);
int botao = 27;
int contador = 0;
void setup() {
  pinMode(27, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Ola");
  lcd.setCursor(0, 1);
  lcd.print("mundo");
}

void loop() {
  Serial.println(digitalRead(botao));
  if (digitalRead(botao) == LOW){
    contador +=1;
    delay(250);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(contador);
  }
  if (contador >= 10){
    contador = 0;
    delay(250);
    lcd.setCursor(0, 0);
    lcd.print(contador);
  }
}
