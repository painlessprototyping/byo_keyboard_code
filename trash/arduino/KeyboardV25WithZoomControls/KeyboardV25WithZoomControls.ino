/*
 * Setup: 
 * 1. Install Keypad Library
 *  1.1 Click Sketch -> Include Library -> Manage Libraries
 *  1.2 Search "Keypad"
 *  1.3 Install library by Mark Stanley, Alexander Brevig
 */

 /* 
  *  Useful Resources:
  *  https://www.arduino.cc/reference/en/language/functions/usb/keyboard/
  *  https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardmodifiers/
  *  For Media Keys, check out https://github.com/NicoHood/HID 
  */

#include "Keyboard.h"
#include "Keypad.h" 

const byte ROWS = 3; 
const byte COLUMNS = 2; 

/* 
 *  The matrix below is rotated by 90 degrees 
 *  so that the top left key on the
 *  keyboard is 1.
 */
char keys[ROWS][COLUMNS] = {
  {'7', '4'},
  {'8', '5'},
  {'8', '5'},
};

byte rowPins[ROWS] = {10, 11,12};
byte colPins[COLUMNS] = {7, 9};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLUMNS );

void setup() {
  Serial.begin(9600);
  Serial.println("Working...");
}

void loop() {
  char key = keypad.getKey();
  if (key) {
     switch (key) {
      case '1':
        /* Alt+V: Start/stop video */
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press('v');
        break;
      case '2':
        /* Alt+V: Start/stop video */
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press('v');
        break;
      case '3':
        /* Alt+S: Launch share screen window and stop screen share */
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press('s');
        break;
      case '4':
        /* Alt+S: Launch share screen window and stop screen share */
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press('f');
        break;
      case '5':
        /* Alt+H: Display/hide in-meeting chat panel */
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press('h');
        break;
      case '6':
        /* Alt+Y: Raise/lower hand */
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press('y');
        break;
    }
     Keyboard.releaseAll(); 
    delay(100);
  }
}
