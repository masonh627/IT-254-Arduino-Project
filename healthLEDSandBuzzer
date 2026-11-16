// Title: IT 254 Group Project
// Author: Mason Hedger
// Description: Mason's portion of the code.

// Setup 
const int LEDPINS[3] = {2,3,4};
const int BUZZERPIN = 5;
const int PLUSHEALTHPIN = 6;
const int MINUSHEALTHPIN =  7;
int playerHealth = 3;
bool canPress = true;

// Plays a static noise on the buzzer
void playBuzzer(int time, int freq){
  tone(BUZZERPIN, freq);
  delay(time);
  noTone(BUZZERPIN);
}

// Function that controls updating LEDS when player health changes
void updateLEDS(){
  // Loop through all LEDS
  for(int i = 0; i < sizeof(LEDPINS); i++){
    if(i <= (playerHealth - 1)){
      digitalWrite(LEDPINS[i], HIGH);
    }
    else{
      digitalWrite(LEDPINS[i], LOW);
    }
  }
}

void increaseHealth(){
  // Check player health is not 3
  if(playerHealth < 3){
    playerHealth++;
    updateLEDS();
    playBuzzer(100, 750);
  }
}

void decreaseHealth(){
  // Check player health is not 0
  if(playerHealth > 0){
    playerHealth--;
    updateLEDS();
    playBuzzer(100, 1000);
  }
}

void setup() {
  // Setup LEDS
  updateLEDS();

  pinMode(BUZZERPIN, OUTPUT);
}

void loop() {
  // Check if the plus health button is pressed
  if(digitalRead(PLUSHEALTHPIN) && canPress){
    canPress = false;
    increaseHealth();
    canPress = true;
  }

  // Check if the minus health button is pressed
  if(digitalRead(MINUSHEALTHPIN) && canPress){
    canPress = false;
    decreaseHealth();
    canPress = true;
  }
}
