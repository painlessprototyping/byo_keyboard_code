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
  {'3', '6'},
  {'2', '5'},
  {'1', '4'}
};

byte rowPins[ROWS] = {7,8,9};
byte colPins[COLUMNS] = {5,6};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLUMNS );

void setup() {
  Keyboard.begin();
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    switch (key) {
      case '1':
        /* Volume Up */
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_UP_ARROW);
        break;
      case '2':
        /* Next Song */
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_RIGHT_ARROW);
        break;
      case '3':
        /* Pause/Play */
        Keyboard.press(0x20);
        break;
      case '4':
        /* Previous Song */
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_DOWN_ARROW);
        break;
      case '5':
        /* Volume Down */
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_LEFT_ARROW);
        break;
      case '6':

        break;
    }
     Keyboard.releaseAll(); 
    delay(100);
  }
}
