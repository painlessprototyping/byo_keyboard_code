#include "HID-Project.h"
#include "Keypad.h"

// Uncomment the following code for 6 Key (V2.5)
/*
const byte ROWS = 3;
const byte COLUMNS = 2;

char keys[ROWS][COLUMNS] = {
    {'1', '4'},
    {'2', '5'},
    {'3', '6'},
};

byte rowPins[ROWS] = {11, 12, 13};
byte colPins[COLUMNS] = {9, 10};
*/

// Uncomment the following code for 9 Key (V2.6)
/* 
const byte ROWS = 3;
const byte COLUMNS = 3;

char keys[ROWS][COLUMNS] = {
    {'1', '4', '7'},
    {'2', '5', '8'},
    {'3', '6', '9'},
};

byte rowPins[ROWS] = {11, 12, 13};
byte colPins[COLUMNS] = {10, 9, 7};
*/

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLUMNS);

void setup()
{
    Serial.begin(9600);
    Consumer.begin();
}

void loop()
{
    char key = keypad.getKey();
    if (key)
    {
        switch (key)
        {
            Serial.println(key);
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
        delay(100);
    }
}
