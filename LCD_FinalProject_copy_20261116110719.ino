#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(3, 0);
  lcd.print("Welcome to") ;
  lcd.setCursor(4, 2);
  lcd.print("the game!");
  delay(3000);

  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("Round 1");
  lcd.setCursor(2,2);
  lcd.print("Question 1:");
  delay(3000);
  lcd.clear();
  delay(1000);
}