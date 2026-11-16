#include <Arduino.h>
long num;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  randomSeed(analogRead(0));

  String level1_q[] = {"1011 to decimal", "good luck->yggv dmuc shift num:", "96 in binary", "9AB to decimal", "105 in hexadecimal", "name->lykc shift num:", "threat?A:Scary/B:Potential harm", "DNS port gate num:", "What is a high digital input?", "How many bytes is a word?"};
  String level1_a[] = {"9", "18", "0110 0000", "2475", "69", "24", "B", "53", "5", "4"};


  String level2_q[] = {"When was the 1st virus made?", "1001 0111 2s complementary", "How many keys in asymmetric?", "What is the common AES length?", "Least days to detect a breach?", "COPPA applies to kids < old", "_% has dealt with identity theft", "Most common password?"};
  String level2_a[] = {"1971", "0110 1001", "0010 0110 1111 0011", "26", "2", "128", "200", "13", "7", "123456"};

  String level3_q[] = {"Network layer is the _ layer", "x86 CPU is _ bit architecture", "Ethernet cable limit is _ meters", "How many lanes in HDMI 2.2?", "Instr. pipeling execute num:", "If TCP Seq=50 and data=487. Ack?", "Num of possible 8 num password?", "Num ip pack: 900bytes w/110limit", "3^x = 13 mod 17. x?"};
  String level3_a[] = {"3", "32", "30", "100", "4", "3", "537", "100000000", "9", "4"};

  num = random(10);
  Serial.println(level1_q[num]);

  delay(500);

  answer = Serial.readString()

  if(answer == level1_a[num]){
    Serial.println("Correct answer!");
  } else{
    Serial.println("Wrong.")
  }
}


void loop() {
  // Connection to python for ai hint bot (made limit 10 hints):
  if (Serial.available() > 0) {
      String hint = Serial.readStringUntil('\n'); // Read until newline
      Serial.println("Received hint: " + hint);   // Echo back to serial monitor
      // You can add code here to display hint on LCD, LED matrix, etc.
  }
}
