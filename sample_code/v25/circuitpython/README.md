## Getting Started

### Update Bootloader to version 6.3
- Plugin your device via USB to your comptuer. The storage drive will show up as an external USB disk.
- Double tap reset button to get to bootloader, the device will un-mount the disk and re-mount as the bootloader ("ITSYBTSY")
- Download the lastest bootloader https://circuitpython.org/board/itsybitsy_m0_express/
- Extract, copy the UF2 file to the ITSYBTSY drive that shows up on your PC. No need to rename file. Device will reboot immediately after copy.
- The device will reboot and mount its storage disk. Probably called "NO_NAME" however you can rename it to whatever you please.
- Open the `boot_out.txt` file. You should see updated firmware version and date.

### Update lib packages
- Download the latest 6.3.0 CircuitPython here: https://github.com/adafruit/Adafruit_CircuitPython_Bundle/releases/download/20210611/adafruit-circuitpython-bundle-6.x-mpy-20210611.zip
- Extract and open the `lib/` folder, find and copy these files over to your device's `lib/` folder:
  - `adafruit_hid/` (folder)
  - `adafruit_dotstar.mpy`
  - `adafruit_matrixkeypad.mpy`
  - `digitalio.mpy`

### Run 

Copy over the example file. Reboot happens automatically on save.

### Console output

Baud rate: 115200

 - Windows: Use PuTTY
 - Mac/OSX:
   - Open terminal, run:
   - Get device: `ls /dev/tty.*`
   - Connect: `screen /dev/tty.usbmodem14301 115200`
   - Quit: Ctrl-A then Ctrl-D. To clean up session: `screen -ls` to get the session name. `screen -X -S <session-name quit`.
 - Arduino IDE
   - Open the program.
   - In the top Menu, select Tools:
   - Configure Board: *Adafruit Circuit Playground*
   - Configure Port: *usbmodem*
   - Click **Serial Monitor**

If you can't connect, there's likely a bug in your `code.py`, slim it down to the simplest possible code:

```python
import time
while True:
    print("hello world")
    time.sleep(1)
```
