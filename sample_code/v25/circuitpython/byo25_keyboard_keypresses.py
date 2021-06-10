# Write your code here :-)
# # CircuitPython IO demo #1 - General Purpose I/O
# https://github.com/adafruit/Adafruit_CircuitPython_Bundle/releases
# https://learn.adafruit.com/matrix-keypad/python-circuitpython
# Get firmware from: https://circuitpython.org/
# Get library from: https://github.com/adafruit/Adafruit_CircuitPython_Bundle/releases/tag/20201203
# Tutorial: https://learn.adafruit.com/adafruit-feather-m0-express-designed-for-circuit-python-circuitpython/circuitpython-hid-keyboard-and-mouse

# Keycodes:
# https://circuitpython.readthedocs.io/projects/hid/en/latest/_modules/adafruit_hid/keycode.html

import time
import board
import digitalio
import adafruit_matrixkeypad
import usb_hid
from adafruit_hid.keyboard import Keyboard
from adafruit_hid.keycode import Keycode
from adafruit_hid.keyboard_layout_us import KeyboardLayoutUS

time.sleep(1)  # Sleep for a bit to avoid a race condition on some systems

cols = [digitalio.DigitalInOut(x) for x in (board.D11, board.D12, board.D13)]
rows = [digitalio.DigitalInOut(x) for x in (board.D9, board.D10)]
keys = (
    (0,1,2),
    (3,4,5),
)
keypad = adafruit_matrixkeypad.Matrix_Keypad(rows, cols, keys)

kbd = Keyboard(usb_hid.devices)

AVAILABLE_KEYS = [
    Keycode.ONE,
    Keycode.TWO,
    Keycode.THREE,
    Keycode.FOUR,
    Keycode.FIVE,
    Keycode.SIX
]

while True:
    keys = keypad.pressed_keys
    if keys:
        print(keys)
        for key in keys:
            kbd.send(AVAILABLE_KEYS[key])
    time.sleep(0.1)