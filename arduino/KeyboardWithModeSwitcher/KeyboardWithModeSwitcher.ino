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

int red_light_pin= 2;
int green_light_pin = 3;
int blue_light_pin = 4;
int button = 14;
int mode = 0;
int button_state;
int last_button_state;

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLUMNS );

void setup() {
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
  RGB_color(255,0,0);
}

void loop() {
  button_state = digitalRead(button);
    if (button_state == 1 && button_state != last_button_state){
      mode += 1;
      if(mode == 3){
        mode = 0;  
      }
      if(mode == 0){
        RGB_color(255,0,0);
      }
      if(mode == 1){
        RGB_color(0,255,0);
      }
      if(mode == 2){
        RGB_color(0,0,255);
      }
  }
  last_button_state = button_state;
  
  char key = keypad.getKey();
    if (key) {
      switch(mode){
        case 0:
          mode_0(key);
          break;
        case 1:
          mode_1(key);
          break;
        case 2:
          mode_2(key);
          break;        
      }
      Keyboard.releaseAll(); 
      delay(10);
    }
}

void mode_0 (char key){
  switch (key) {
    case '1':
      Keyboard.press('a');
      break;
    case '2':
      Keyboard.press('b');
      break;
    case '3':
      Keyboard.press('c'); 
      break;
    case '4':
      Keyboard.press('d');
      break;
    case '5':
      Keyboard.press('e');
      break;
    case '6':
      Keyboard.press('f');
      break;
  }
}

void mode_1 (char key){
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
}

void mode_2 (char key){
  switch (key) {
    case '1':
      Keyboard.press('1');
      break;
    case '2':
      Keyboard.press('2');
      break;
    case '3':
      Keyboard.press('3'); 
      break;
    case '4':
      Keyboard.press('4');
      break;
    case '5':
      Keyboard.press('5');
      break;
    case '6':
      Keyboard.press('6');
      break;
  }
}

void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
