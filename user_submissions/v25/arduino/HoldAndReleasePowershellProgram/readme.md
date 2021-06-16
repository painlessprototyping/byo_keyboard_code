Buttons Hold and Release and can be reprogrammed with Windows Powershell
--------------------------
I wanted the buttons to stay held down as long as I held them down (so I could use alt and control as modifiers in games) and be able to change the key mappings without opening up the Arduino IDE, so I have the Arduino poll the serial and update the internal keymapping via a string. I then created some Windows Powershell scripts to parse the serial ports, find the ItsyBitsy M0 and send it a string of the new keys (the keys are defined in Decimal format).
