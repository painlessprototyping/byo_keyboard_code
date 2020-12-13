# # CircuitPython IO demo #1 - General Purpose I/O
# https://github.com/adafruit/Adafruit_CircuitPython_Bundle/releases
# https://learn.adafruit.com/matrix-keypad/python-circuitpython
import time
import board
import digitalio
import adafruit_matrixkeypad

cols = [digitalio.DigitalInOut(x) for x in (board.D11, board.D12, board.D13)]
rows = [digitalio.DigitalInOut(x) for x in (board.D10, board.D9, board.D7)]
keys = ((1, 2,3),
        (4,5,6),
        (7,8,9),
    )
keypad = adafruit_matrixkeypad.Matrix_Keypad(rows, cols, keys)

while True:
    keys = keypad.pressed_keys
    if keys:
        print("Pressed: ", keys)
    time.sleep(0.1)