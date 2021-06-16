import time
import board
import digitalio
import adafruit_matrixkeypad
import usb_hid
from adafruit_hid.keyboard import Keyboard
from adafruit_hid.keyboard_layout_us import KeyboardLayoutUS

time.sleep(1)

# Uncomment the following code for 6 Key (V2.5)
# cols = [digitalio.DigitalInOut(x) for x in (board.D11, board.D12, board.D13)]
# rows = [digitalio.DigitalInOut(x) for x in (board.D9, board.D10)]
# keys = (
#     (0,1,2),
#     (3,4,5),
# )

# Uncomment the following code for 9 Key (V2.6)
# cols = [digitalio.DigitalInOut(x) for x in (board.D11, board.D12, board.D13)]
# rows = [digitalio.DigitalInOut(x) for x in (board.D7, board.D9, board.D10)]
# keys = (
#     (6,7,8),
#     (3,4,5),
#     (0,1,2),
# )

keypad = adafruit_matrixkeypad.Matrix_Keypad(rows, cols, keys)

while True:
    keys = keypad.pressed_keys
    if keys:
        print(keys)
    time.sleep(0.1)