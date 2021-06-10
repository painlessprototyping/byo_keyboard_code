#include "Keyboard.h"
#include "Keypad.h"

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

void setup()
{
    Serial.begin(9600);
    Keyboard.begin();
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
            Keyboard.print("1");
            break;
        case '2':
            Keyboard.print("2");
            break;
        case '3':
            Keyboard.print("3");
            break;
        case '4':
            Keyboard.print("4");
            break;
        case '5':
            Keyboard.print("5");
            break;
        case '6':
            Keyboard.print("6");
            break;
        }
        Keyboard.releaseAll();
        delay(100);
    }
}