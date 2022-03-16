#include <LiquidCrystal.h>

LiquidCrystal lcd(19, 23, 18, 17, 16, 15);
int x = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  while (1){
    lcd.setCursor(0, x);
    lcd.print("Subindo");
    x += 1;
    if (x == 2){
      x = 0;
    }
  delay (500);
  lcd.clear();
  }
}
