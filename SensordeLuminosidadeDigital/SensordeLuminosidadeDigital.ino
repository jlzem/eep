#include <LiquidCrystal_I2C.h>

#define LDR_PIN 2

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  pinMode(LDR_PIN, INPUT);
  lcd.init();
  lcd.backlight();
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Status da Saida:  ");
  lcd.setCursor(0, 1);
  if (digitalRead(LDR_PIN) == LOW) {
    lcd.print("Desativada      ");
  } else {
    lcd.print("Ativada         ");
  }
  delay(100);
}
