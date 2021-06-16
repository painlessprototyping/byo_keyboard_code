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
control_key = Keycode.SHIFT
cc = ConsumerControl(usb_hid.devices)

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

KEYS = [
    ConsumerControlCode.SCAN_NEXT_TRACK,
    ConsumerControlCode.VOLUME_INCREMENT,
    ConsumerControlCode.PLAY_PAUSE,
    ConsumerControlCode.SCAN_PREVIOUS_TRACK,
    ConsumerControlCode.VOLUME_DECREMENT,
    ConsumerControlCode.MUTE,
]

while True:
    keys = keypad.pressed_keys
    if keys:
        for key in keys:
            cc.send(KEYS[key])
        time.sleep(0.1)
