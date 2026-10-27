// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("LIGHT       TEMP");
}
void loop() {
  int light_value = analogRead(A0);
  int updated_value = light_value/10;

  int temp_value = analogRead(A1);

  lcd.setCursor(0, 1);
  lcd.print("                ");  // clears leftover digits
  lcd.setCursor(1, 1);
  lcd.print(updated_value);

  lcd.setCursor(13, 1);
  lcd.print(temp_value);

  delay(250);
}

