#include "HID-Project.h"
#include "Keypad.h" w

const byte ROWS = 3; 
const byte COLUMNS = 2; 

/* 
 *  The matrix below is rotated by 90 degrees 
 *  so that the top left key on the
 *  keyboard is 1.
 */
char keys[ROWS][COLUMNS] = {
  {'1', '4'},
  {'2', '5'},
  {'3', '6'},
};

byte rowPins[ROWS] = {11,12,13};
byte colPins[COLUMNS] = {9, 10};
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLUMNS );

void setup() {
  Serial.begin(9600);
  Consumer.begin();
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    Serial.println(key);
    delay(10);
  }
}
