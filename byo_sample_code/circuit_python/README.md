# Setup

1. [Install Mu Software](https://learn.adafruit.com/introducing-itsy-bitsy-m0/installing-mu-editor)
2. Update Bootloader to version 7.x
    - Plugin your device via USB to your computer. The storage drive will show up as an external USB disk.
    - Double tap RESET button to get to the bootloader, the device will un-mount the disk and re-mount as the bootloader ("ITSYBTSY") If device doesn't show up, try double tapping more slowly. 
    - Download the lastest 7.x bootloader https://circuitpython.org/board/itsybitsy_m0_express/
    - Extract, copy the file with the UF2 extension to the ITSYBTSY drive that shows up on your PC. No need to rename file. Device will reboot immediately after copy.
    - The device will reboot and mount its storage disk. Probably called "NO_NAME" however you can rename it to whatever you please.
    - Open the `boot_out.txt` file. You should see updated firmware version and date.
3. Update lib packages
    - Download the latest 7.x CircuitPython here: [https://github.com/adafruit/Adafruit_CircuitPython_Bundle/releases/download/20220715/adafruit-circuitpython-bundle-7.x-mpy-20220715.zip](https://github.com/adafruit/Adafruit_CircuitPython_Bundle/releases/download/20220715/adafruit-circuitpython-bundle-7.x-mpy-20220715.zip)
    - Extract and open the `lib/` folder, find and copy these files over to your device's `lib/` folder:
      - `adafruit_hid/` (folder)
      - `adafruit_dotstar.mpy`
      - `adafruit_matrixkeypad.mpy`
4. With ItsBitsy M0 connected open up the Mu software and copy over the following code.
```python
import time
while True:
    print("Hello World")
    time.sleep(1)
```
5. Open the `Serial` by clicking on the menu item in Mu and see `Hello World` displaying once a second.
6. Open an example code file in this folder and copy to device. 
7. Happy Making!
