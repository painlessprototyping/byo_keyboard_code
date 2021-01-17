# Get firmware from: https://circuitpython.org/
# Get library from: https://github.com/adafruit/Adafruit_CircuitPython_Bundle/releases/tag/20201203
# Tutorial: https://learn.adafruit.com/adafruit-feather-m0-express-designed-for-circuit-python-circuitpython/circuitpython-hid-keyboard-and-mouse
import time
 
import board
import digitalio
import usb_hid
from adafruit_hid.keyboard import Keyboard
from adafruit_hid.keyboard_layout_us import KeyboardLayoutUS
from adafruit_hid.keycode import Keycode
 
time.sleep(1)  # Sleep for a bit to avoid a race condition on some systems
control_key = Keycode.SHIFT
keyboard = Keyboard(usb_hid.devices)

keyboard.press(Keycode.A)  # "Press"...
keyboard.release_all()  # ..."Release"!
