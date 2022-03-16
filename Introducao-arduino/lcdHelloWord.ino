#include <LiquidCrystal.h>

LiquidCrystal lcd(19, 23, 18, 17, 16, 15);
void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Hello");
  lcd.setCursor(0, 1);
  lcd.print("World");
}
void loop() {
  
}
