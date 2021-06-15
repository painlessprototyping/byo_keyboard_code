#include "Keyboard.h"
#include "Keypad.h"
#include <Adafruit_DotStar.h>

#define NUMPIXELS 1 // Number of LEDs in strip

// Here's how to control the LEDs from any two pins:
#define DATAPIN    41
#define CLOCKPIN   40
Adafruit_DotStar strip(NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);

const byte ROWS = 3;
const byte COLUMNS = 2;

/*
    The matrix below is rotated by 90 degrees
    so that the top left key on the
    keyboard is 1.
*/
char keys[ROWS][COLUMNS] = {
    {'1', '4'},
    {'2', '5'},
    {'3', '6'},
};

byte rowPins[ROWS] = {11, 12, 13};
byte colPins[COLUMNS] = {9, 10};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLUMNS);

bool isHeld = false;
int previousKey = 0;

String keyMappingUpdate = String("");

int keyMappings[6] = {177,179,129,128,130,32};

void setup()
{
    Serial.begin(9600);
    Keyboard.begin();
    strip.begin();
    strip.show(); // Initialize all pixels to 'off'
    keypad.addEventListener(keypadEvent); //add an event listener for this keypad
} 

void loop()
{
  char key = keypad.getKey();
  if (Serial.available() > 0) 
  {
    // read the incoming:
    keyMappingUpdate = Serial.readString();
    strip.setPixelColor(0, 255, 127, 0);
    strip.show();
    Serial.println(keyMappingUpdate);
    for (int i = 0; i < 6; i++) 
    {
      keyMappings[i] = getValue(keyMappingUpdate, ',', i).toInt();
    }
    delay(10);
    strip.setPixelColor(0, 0, 0, 0);
    strip.show();    
  }
  delay(10);
}


String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

void keypadEvent(KeypadEvent key)
{
  switch (keypad.getState())
  {
    case PRESSED:
        switch (key)
        {
            Serial.println(key);
        case '1':
            Keyboard.press(keyMappings[0]);
            break;
        case '2':
            Keyboard.press(keyMappings[1]);
            break;
        case '3':
            Keyboard.press(keyMappings[2]);
            break;
        case '4':
            Keyboard.press(keyMappings[3]);
            break;
        case '5':
            Keyboard.press(keyMappings[4]);
            break;
        case '6':
            Keyboard.press(keyMappings[5]);
            break;
        }
    break;
    case RELEASED:
        Keyboard.releaseAll();
    break;
  }
}
