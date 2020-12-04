#include <Adafruit_DotStar.h>

#define NUMPIXELS 1 // Number of LEDs in strip
int PIXEL = 0;
// Here's how to control the LEDs from any two pins:
#define DATAPIN    41
#define CLOCKPIN   40
Adafruit_DotStar strip(NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);
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
  {'3', '6'},
  {'2', '5'},
  {'1', '4'}
};

byte rowPins[ROWS] = {10,9,7};
byte colPins[COLUMNS] = {11,12};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLUMNS );

void setup() {
  Serial.begin(9600);
  Consumer.begin();
    strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip.setPixelColor(0, 0, 255, 255);
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
 
  char key = keypad.getKey();
  if (key) {
    switch (key) {
      case '1':
        strip.setPixelColor(PIXEL, 50, 0, 0);
        strip.show();
        Consumer.write(MEDIA_NEXT);
        break;
      case '2':
        strip.setPixelColor(PIXEL, 50, 0, 0);
        strip.show();
        Consumer.write(MEDIA_VOLUME_UP);
        break;
      case '3':
        strip.setPixelColor(PIXEL, 50, 0, 10);
        strip.show();
        Consumer.write(MEDIA_PLAY_PAUSE);  
        break;
      case '4':
        strip.setPixelColor(PIXEL, 50, 0, 0);
        Consumer.write(MEDIA_PREVIOUS);
        break;
      case '5':
        strip.setPixelColor(PIXEL, 50, 0, 0);
        strip.show();
        Consumer.write(MEDIA_VOLUME_DOWN);
        break;
      case '6':
        strip.setPixelColor(PIXEL, 0, 0, 10);
        strip.show();
        Consumer.write(MEDIA_VOLUME_MUTE);
        break;
    }
     Keyboard.releaseAll(); 
    delay(100);
  }
}
