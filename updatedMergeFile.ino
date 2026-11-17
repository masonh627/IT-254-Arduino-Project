#include <Arduino.h>
#include <LiquidCrystal.h>

long num;


const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void printWrapped(String text) {
  lcd.clear();

  // First line
  lcd.setCursor(0, 0);
  lcd.print(text.substring(0, min(16, (int)text.length())));

  // Second line
  if (text.length() > 16) {
    lcd.setCursor(0, 1);
    lcd.print(text.substring(16, min(32, (int)text.length())));
    }
}

void setup() {
  // put your setup code here, to run once:


  Serial.begin(9600);
  randomSeed(analogRead(0));
  lcd.begin(16, 2);

  String level1_q[] = {"1011 to decimal", "good luck->yggv dmuc shift num:", "96 in binary", "9AB to decimal", "105 in hexadecimal", "name->lykc shift num:", "threat?A:Scary/B:Potential harm", "DNS port gate num:", "What is a high digital input?", "How many bytes is a word?"};
  String level1_a[] = {"9", "18", "0110 0000", "2475", "69", "24", "B", "53", "5", "4"};


  String level2_q[] = {"When was the 1st virus made?", "1001 0111 2s complementary", "How many keys in asymmetric?", "What is the common AES length?", "Least days to detect a breach?", "COPPA applies to kids < old", "_% has dealt with identity theft", "Most common password?"};
  String level2_a[] = {"1971", "0110 1001", "0010 0110 1111 0011", "26", "2", "128", "200", "13", "7", "123456"};

  String level3_q[] = {"Network layer is the _ layer", "x86 CPU is _ bit architecture", "Ethernet cable limit is _ meters", "How many lanes in HDMI 2.2?", "Instr. pipeling execute num:", "If TCP Seq=50 and data=487. Ack?", "Num of possible 8 num password?", "Num ip pack: 900bytes w/110limit", "3^x = 13 mod 17. x?"};
  String level3_a[] = {"3", "32", "30", "100", "4", "3", "537", "100000000", "9", "4"};

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

  num = random(10);
  
  printWrapped(level1_q[num]);
  delay(150);

  String answer = Serial.readString();

 /* 
  if (answer == level1_q[num]){
    lcd.clear();
    lcd.setCursor(3);
    lcd.print("Correct!");
    lcd.setCursor(0, 2);
    lcd.print("Round 2:");
    delay(3000);
    num = random(10);
    printWrapped(level2_q[num]);
  } else {
    lcd.clear();
    lcd.print("incorrect!");
    delay(1000);
    lcd.clear();
    printWrapped(level1_q[num]);
  }

  */

}


void loop() {
  // Connection to python for ai hint bot (made limit 10 hints):
  if (Serial.available() > 0) {
      String hint = Serial.readStringUntil('\n'); // Read until newline
      Serial.println("Received hint: " + hint);   // Echo back to serial monitor
      // You can add code here to display hint on LCD, LED matrix, etc.
  }
}
