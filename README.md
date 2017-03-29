trinketHidToggle
=====================================

A [Trinket](https://learn.adafruit.com/introducing-trinket/introduction) firmware that sets the tiny board as a [HID device](https://en.wikipedia.org/wiki/Human_interface_device), so it's possible to send and receive messages via USB.

The sketch implements a very simple protocol:
- send 0 or 1 (as an unsigned char) to turn pin 1 off/on
- receive 0 or 1 (as an unsigned char) whenever pin 1 changes state

Dependencies
------------
[HID Serial Trinket](https://github.com/adafruit/rayshobby-hid-serial-trinket)

License
-------
GPL v.3
