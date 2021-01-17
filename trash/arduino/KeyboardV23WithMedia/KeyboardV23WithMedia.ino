/* 
    Keyboard with a separate button for toggling between modes on the keyboard.
*/

#include "HID-Project.h"
#include "Keypad.h"

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
