/*
  This is  test to see what is actually possible
  Uses 9 Keys (V2.5)
  Features & Instructions:
  The bottom right key is used to switch between different presets.
  It has 3 presets:
  1.Consumer Keys:Test Media Control like volume, mute etc.
  2.Single Keys: Numer 1-8
  3.Shortcuts and fulltext: Shortcuts and fulltext ;)

  The current presets is indicated by the color of the led (1=green,2=red,3=blue)
  It has 2 color animations, static and a breathing mode.
  There is support for an led-strip(tested with Ws2182)
  //Pinout
  //Power : USB
  //Data  : 5
  //Ground: G
  If no led-strip is connected, comment out the code for it (including the lib)

*/

#include "HID-Project.h"
#include "Keypad.h"

//-->using german layout
#define HID_CUSTOM_LAYOUT
#define LAYOUT_GERMAN
//<--

//-->Built in LED
#include <Adafruit_DotStar.h>
//how many pixel,board data pin,board clockpin
Adafruit_DotStar boardLED(1, 41, 40, DOTSTAR_BRG);
//limitis the brightness
#define boardLEDMaxBri 100
//<--

//-->LED Strip connected to pin 5 (WS2812)
#include <Adafruit_NeoPixel_ZeroDMA.h>
//how many pixel,pin
Adafruit_NeoPixel_ZeroDMA extLED (4,  5, NEO_RGB);
//limitis the brightness
#define extLEDMaxBri 100
//<--

//code for 9 Key (V2.6)
const byte ROWS = 3;
const byte COLUMNS = 3;
char keys[ROWS][COLUMNS] = {
  {'1', '4', '7'},
  {'2', '5', '8'},
  {'3', '6', '9'},
};
byte rowPins[ROWS] = {11, 12, 13};
byte colPins[COLUMNS] = {10, 9, 7};

//for switching through presets
int keyIndex;
unsigned int currMode;
//how many presets ?
#define ModeLength 3
//

char modeKeys[8]= {'1', '2', '3', '4', '5', '6', '7', '8'};

//timer function: animates the led(s)
unsigned int myTimer = 0;
unsigned long myTimeout = 50; //speed: lower faster // higher slower
unsigned int cycle = 0;
//array for the colors
uint32_t modeColors [ModeLength] = {boardLED.Color(255, 0, 0), boardLED.Color(0, 255, 0), boardLED.Color(0, 0, 255)};
//set mode
#define LED_MODE 1 //0 Solid 1 Breathing


Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLUMNS);

void setup()
{
  currMode = 0;
  keyIndex = 0;
  Keyboard.begin();
  Consumer.begin();
 //-->extLED
  extLED.begin();
  extLED.show();
 //<--
  boardLED.begin();  
  boardLED.show();
}

void loop()
{
  char key = keypad.getKey();
  if (key)
  {
    switch (key)
    {   Serial.println(key);

      case '1':
        if (currMode == 0)
          Consumer.write(MEDIA_NEXT);

        if (currMode == 1)
          Keyboard.write(modeKeys[0]);

        if (currMode == 2)
          Keyboard.print("shrek");
        break;
		
      case '2':
        if (currMode == 0)
          Consumer.write(MEDIA_VOLUME_UP);

        if (currMode == 1)
          Keyboard.write(modeKeys[1]);

        if (currMode == 2)
          Keyboard.print("//");
        break;
		
      case '3':
        if (currMode == 0)
          Consumer.write(MEDIA_PLAY_PAUSE);
        if (currMode == 1)
          Keyboard.write(modeKeys[2]);       
        if (currMode == 2)
        {
          Keyboard.write(KEY_LEFT_GUI);    
          Keyboard.write(KEY_TAB);  
        }               
        break;
		
      case '4':
        if (currMode == 0)        
          Consumer.write(MEDIA_PREVIOUS);
        
        if (currMode == 1)
          Keyboard.write(modeKeys[3]);
	  
        if (currMode == 2)
          Keyboard.print("#");
        break;
		
      case '5':
        if (currMode == 0)
          Consumer.write(MEDIA_VOLUME_DOWN);

        if (currMode == 1)
          Keyboard.write(modeKeys[4]);

        if (currMode == 2)
          Keyboard.print("github");         
        break;
		
      case '6':
        if (currMode == 0)
          Consumer.write(MEDIA_VOLUME_MUTE);

        if (currMode == 1)
          Keyboard.write(modeKeys[5]);

        if (currMode == 2)
        {
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_F4);
        }
        break;
		
      case '7':
        if (currMode == 0)   
        Consumer.write(MEDIA_VOLUME_MUTE);  
        
        if (currMode == 1)
            Keyboard.write(modeKeys[6]);

          if (currMode == 2)
          {
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_ESC);          
          }            
          break;
		  
        case '8':
          if (currMode == 0)  
           Consumer.write(MEDIA_VOLUME_MUTE);          

          if (currMode == 1)
            Keyboard.write(modeKeys[7]);

          if (currMode == 2)
          {         
            Keyboard.press(KEY_LEFT_ALT); 
            Keyboard.press(KEY_TAB);
          }   
          break;
		  
        case '9':
          if (currMode < ModeLength - 1)
          {
            currMode++;
          }
          else
          {
            currMode = 0;
          }
          Serial.print("cMode" + String(currMode, DEC));
          break;
        }
        
        Keyboard.releaseAll();
        delay(10);
    }
    
    setLED(modeColors[currMode], LED_MODE);
}

  void setLED(uint32_t _col , int _mode)
  {
    switch (_mode)
    {
      case 1:
        if (millis() > myTimeout + myTimer )
        {
          cycle++;
          myTimer = millis();
          if (cycle >= 100)
          {
            cycle = 0;
          }
        }
        setLedColBri(_col, cycle);
        break;
		
      default:
        setLedColBri(_col, 100);
        break;
    }

  }

  void setLedColBri(uint32_t _col, int _bri)
  {
    //-->extLED
    for (int i = 0; i < 4; i++)
    {
      extLED.setPixelColor(i, _col);
    }
    extLED.show();
    extLED.setBrightness(map(_bri, 0, 100, 0, extLEDMaxBri));
    //<--
    boardLED.setPixelColor(0,_col);
    boardLED.setBrightness(map(_bri, 0, 100, 0, boardLEDMaxBri));
    boardLED.show();
  }