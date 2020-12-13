/* 
    Keyboard with a separate button for toggling between modes on the keyboard.
*/

#include "HID-Project.h"
#include "Keypad.h"

const byte  ROWS = 3;
const byte COLUMNS = 2;
byte rowPins[ROWS] = {7,8,9};
byte colPins[COLUMNS] = {5,6};

char keys[ROWS][COLUMNS] = {
  {'3', '6'},
  {'2', '5'},
  {'1', '4'}
};

int button = 14;
int mode = 0;
int button_state;
int last_button_state;

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLUMNS );

void setup() {
  pinMode(button, INPUT);
  Serial.begin(9600);
}

void loop() {  
  char key = keypad.getKey();
    if (key) {
           switch (key) {
    case '1':
      Consumer.write(MEDIA_NEXT);
      break;
    case '2':
      Consumer.write(MEDIA_VOLUME_UP);
      break;
    case '3':
      Consumer.write(MEDIA_PLAY_PAUSE);  
      break;
    case '4':
      Consumer.write(MEDIA_PREVIOUS);
      break;
    case '5':
      Consumer.write(MEDIA_VOLUME_DOWN);
      break;
    case '6':
      Consumer.write(MEDIA_VOLUME_MUTE);
      break;  
      }
      Keyboard.releaseAll(); 
      delay(10);
    }
}
