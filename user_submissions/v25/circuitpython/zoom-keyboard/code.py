# Write your code here :-)
# # CircuitPython IO demo #1 - General Purpose I/O
# https://github.com/adafruit/Adafruit_CircuitPython_Bundle/releases
# https://learn.adafruit.com/matrix-keypad/python-circuitpython
# Get firmware from: https://circuitpython.org/
# Get library from: https://github.com/adafruit/Adafruit_CircuitPython_Bundle/releases/tag/20201203

import time
import board
import digitalio
import adafruit_matrixkeypad
import usb_hid
from adafruit_hid.keyboard import Keyboard
from adafruit_hid.keyboard_layout_us import KeyboardLayoutUS
from adafruit_hid.keycode import Keycode
from adafruit_hid.consumer_control import ConsumerControl
from adafruit_hid.consumer_control_code import ConsumerControlCode

time.sleep(1)  # Sleep for a bit to avoid a race condition on some systems
# Set up a keyboard device.
kbd = Keyboard(usb_hid.devices)
control_key = Keycode.SHIFT
cc = ConsumerControl(usb_hid.devices)

cols = [digitalio.DigitalInOut(x) for x in (board.D11, board.D12, board.D13)]
rows = [digitalio.DigitalInOut(x) for x in (board.D9, board.D10)]
keys = (
    (0, 1, 2),
    (3, 4, 5),
)
keypad = adafruit_matrixkeypad.Matrix_Keypad(rows, cols, keys)

while True:
    keys = keypad.pressed_keys
    if keys:
        for key in keys:
            print(key)
            if (key == 0): #volume up
                cc.send(ConsumerControlCode.VOLUME_INCREMENT)
            if (key == 1): #toggle mute
                kbd.send(Keycode.COMMAND, Keycode.SHIFT, Keycode.V)
            if (key == 2): #toggle speaker mute
                 cc.send(ConsumerControlCode.MUTE)
            if (key == 3): #volume down
                 cc.send(ConsumerControlCode.VOLUME_DECREMENT)
            if (key == 4): #toggle mic mute
                kbd.send(Keycode.COMMAND, Keycode.SHIFT, Keycode.A)
            if (key == 5): #toggle screen share
                kbd.send(Keycode.COMMAND, Keycode.SHIFT, Keycode.S)
        time.sleep(0.2)
