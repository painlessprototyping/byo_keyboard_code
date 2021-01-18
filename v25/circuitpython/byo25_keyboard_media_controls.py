# Write your code here :-)
# # CircuitPython IO demo #1 - General Purpose I/O
# https://github.com/adafruit/Adafruit_CircuitPython_Bundle/releases
# https://learn.adafruit.com/matrix-keypad/python-circuitpython
# Get firmware from: https://circuitpython.org/
# Get library from: https://github.com/adafruit/Adafruit_CircuitPython_Bundle/releases/tag/20201203
# Tutorial: https://learn.adafruit.com/adafruit-feather-m0-express-designed-for-circuit-python-circuitpython/circuitpython-hid-keyboard-and-mouse

import time
import board
import digitalio
import adafruit_matrixkeypad
import usb_hid
from adafruit_hid.keyboard import Keyboard
from adafruit_hid.keyboard_layout_us import KeyboardLayoutUS

time.sleep(1)  # Sleep for a bit to avoid a race condition on some systems

cols = [digitalio.DigitalInOut(x) for x in (board.D11, board.D12, board.D13)]
rows = [digitalio.DigitalInOut(x) for x in (board.D9, board.D10)]
keys = (
    (0,1,2),
    (3,4,5),
)
keypad = adafruit_matrixkeypad.Matrix_Keypad(rows, cols, keys)

while True:
    keys = keypad.pressed_keys
    if keys:
        print(keys)
    time.sleep(0.1)