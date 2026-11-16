//added keypad library to detect when the button is pressed
#include <Keypad.h>

// defining the number of columns and rows
const byte ROWS = 4; 
const byte COLS = 4; 

// defining the keys that are on the keypad in an array
char hexaKeys[ROWS][COLS] = {
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

// shows the adruino pins that are connected to the rows and columns
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

// creates keypad opject: connect keypad information
// together to recognize where and which puttons are pressed
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

// begins the function to run when the Arduino is switched on
void setup() {
  Serial.begin(9600); 
}


void loop() {
// reads which button is pressed
char customKey = customKeypad.getKey(); 
// if statement to print out which button is pressed
if (customKey) {
Serial.println(customKey); 
}

// NEXT: check if answer (customKey) matches the answer

}