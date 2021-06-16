import time
import board
import digitalio
import adafruit_matrixkeypad
import usb_hid
import adafruit_dotstar
from adafruit_hid.keyboard import Keyboard
from adafruit_hid.keyboard_layout_us import KeyboardLayoutUS
from adafruit_hid.keycode import Keycode
from adafruit_hid.consumer_control import ConsumerControl
from adafruit_hid.consumer_control_code import ConsumerControlCode

time.sleep(1) 
control_key = Keycode.SHIFT
cc = ConsumerControl(usb_hid.devices)
kbd = Keyboard(usb_hid.devices)
dot = adafruit_dotstar.DotStar(board.APA102_SCK, board.APA102_MOSI, 1, brightness=0.5)

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

KEYBOARDS = [
    {
        'color': (10,0,0),
        'keys': [
            lambda : cc.send(ConsumerControlCode.SCAN_NEXT_TRACK),
            lambda : cc.send(ConsumerControlCode.VOLUME_INCREMENT),
            lambda : cc.send(ConsumerControlCode.PLAY_PAUSE),
            lambda : cc.send(ConsumerControlCode.SCAN_PREVIOUS_TRACK),
            lambda : cc.send(ConsumerControlCode.VOLUME_DECREMENT),
            lambda : cc.send(ConsumerControlCode.MUTE),
        ]
    },
        {
        'color': (0,10,0),
        'keys': [
            lambda : kbd.send(Keycode.ONE),
            lambda : kbd.send(Keycode.TWO),
            lambda : kbd.send(Keycode.THREE),
            lambda : kbd.send(Keycode.FOUR),
            lambda : kbd.send(Keycode.FIVE),
            lambda : kbd.send(Keycode.SIX),
            lambda : kbd.send(Keycode.SEVEN),
            lambda : kbd.send(Keycode.EIGHT),
            lambda : kbd.send(Keycode.NINE)
        ]
    }
]
selected_keyboard = 0
while True:
    keys = keypad.pressed_keys
    dot[0] = KEYBOARDS[selected_keyboard]['color']
    if keys:
        if 0 in keys and 5 in keys:
            # if the first and sixth keys are pressed, change keyboard
            next_keyboard = selected_keyboard + 1
            if  next_keyboard == len(KEYBOARDS):
                selected_keyboard = 0
            else:
                selected_keyboard = next_keyboard
            time.sleep(2)
        for key in keys:
            KEYBOARDS[selected_keyboard]['keys'][key]()
        time.sleep(0.1)
