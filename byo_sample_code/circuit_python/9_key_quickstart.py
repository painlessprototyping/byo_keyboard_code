"""
Welcome to the intro tutorial for the 9 Key BYO Keyboard!

Need Help? Join Discord:
https://discord.gg/RkTDf22MUz

Brand New to Circuit Python? Start here:
https://learn.adafruit.com/welcome-to-circuitpython
https://learn.adafruit.com/circuitpython-essentials/circuitpython-essentials
"""

# The following modules are included with CircuitPython, 
# read more about them in the links above.
import time
import board 
import digitalio

"""
The follow modules need to be installed.
Go to https://circuitpython.org/libraries and 
download Bundle Version 6.x
Copy the following to the ItsyBitsy lib folder:
    - adafruit_hid (folder)
    - adafruit_dotstar.mpy
    - adafruit_matrixkeypad.mpy
"""

# Read More about adafruit_matrixkeypad here: https://circuitpython.readthedocs.io/projects/matrixkeypad/en/latest/index.html
import adafruit_matrixkeypad 
# Read More about usb_hid here: https://learn.adafruit.com/circuitpython-essentials/circuitpython-hid-keyboard-and-mouse
import usb_hid 
from adafruit_hid.keyboard import Keyboard
from adafruit_hid.keycode import Keycode
from adafruit_hid.keyboard_layout_us import KeyboardLayoutUS

time.sleep(1) # We take a pause for 1 second while the ItsyBitsy gets started up.

# The following code is how we connect the board pins to be used in our code. 
rows = [
    digitalio.DigitalInOut(board.D10),
    digitalio.DigitalInOut(board.D9),
    digitalio.DigitalInOut(board.D7),
]

columns = [
    digitalio.DigitalInOut(board.D11),
    digitalio.DigitalInOut(board.D12),
    digitalio.DigitalInOut(board.D13),
]

# KEYBOARD_KEYS below is a list of 9 items. In programming counting starts at 0. 
# So output_values has 9 values that can be used
# to look up KEYBOARD_KEYS. 
output_values = (
    (0, 1, 2),
    (3, 4, 5),
    (6, 7, 8),
)

# The following code takes a collection of rows and columns and converts them to 
# one of the output_values. output_values is a 3 x 3, just like how the BYO Keyboard
# has 3 rows and 3 columns. When the first button is pressed, a 0 is output
# as seen in the code below. 
keypad = adafruit_matrixkeypad.Matrix_Keypad(rows, columns, output_values)

# Above we define output_values as 0 through 8. 0 will point to Keycode.ONE and so one. 
# For more Keycodes, check here: https://circuitpython.readthedocs.io/projects/hid/en/latest/index.html
KEYBOARD_KEYS = [
    Keycode.ONE,
    Keycode.TWO,
    Keycode.THREE,
    Keycode.FOUR,
    Keycode.FIVE,
    Keycode.SIX,
    Keycode.SEVEN,
    Keycode.EIGHT,
    Keycode.NINE,
]

# The following code sets up the ItsyBitsy as a keyboard
kbd = Keyboard(usb_hid.devices)

# This code will run forever since while True is always True
while True:
    # Check for the keys being pressed
    pressed_keys = keypad.pressed_keys

    if len(pressed_keys) > 0: 
        # This is a helpful way to debug if the keys are being pressed. 
        # Open The Serial from the menu above in Mu to see this.
        print(pressed_keys) 
        for pressed_key in pressed_keys: # For each pressed key
            kbd.send(KEYBOARD_KEYS[pressed_key]) # Send the value to the computer
        time.sleep(0.1) # Wait for a brief period before continuing
