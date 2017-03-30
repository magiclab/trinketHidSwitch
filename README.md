trinketHidToggle
=====================================

A [Trinket](https://learn.adafruit.com/introducing-trinket/introduction) firmware that sets the tiny board as a [HID device](https://en.wikipedia.org/wiki/Human_interface_device), so it's possible to send and receive messages via USB.

The sketch implements a very simple protocol:
- send 0 or 1 (as an unsigned char) to turn pin 2 off/on
- receive 0 or 1 (as an unsigned char) whenever pin 2 changes state

The LED connected to pin 1 turns on/off to show pin 2 status; it also blinks when the Trinket receives a ping message (any byte different from 0 or 1).

Dependencies
------------
[HID Serial Trinket](https://github.com/adafruit/rayshobby-hid-serial-trinket)

License
-------
GPL v.3
