# FlexKey #
## A Flexible Bluetooth Keyboard Emulator ##

FlexKey aims to bridge the gap between the ubiquitous computers in our lives
without adequate input devices, and those which we carry in our pockets
every day.

This repository contains the firmware for the FlexKey prototype.

## Bill of Materials ##

All components for the prototype were purchased from [Sparkfun][7].

+ [Sparkfun ProMicro 3.3V/8MHz][1]
+ [Sparkfun nRF52832 Breakout][2]
+ [Breadboard][3]
+ Break Away Headers ([male][4], and [female][5])
+ [Wire][6]

Additionally, programming the nRF52832 breakout using the included serial
bootloader requires a 3.3V UART interface, such as [this one][8].

Tools, such as a soldering iron, wire cutters, and wire strippers, are also
necessary for populating headers on the development boards and cutting
jumper wires for the breadboard.

## Environment ##

The firmware for the prototype was developed using the [Arduino IDE][9],
with the appropriate Sparkfun addons and plugins for the development
boards mentioned in the BoM. Refer to the Hookup Guides for the
[Pro Micro][10] and the [nRF52832][11] for instructions.

Additionally, a patch was applied to the nRF5 library variant.h file to route
the UART interface to different pins than those used for the bootloader.

Initial testing was done using the [nRF Toolbox App][12], as the Bluetooth code
used for reference was designed to work with that system.

## Credits ##

Open source libraries and example code:

+ [Sparkfun Hardware Definitions and Libraries][13]
+ [Sandeep Mistry's arduino-BLEPeripheral Library][14]

FlexKey is a capstone project by:

+ Rhys Barrie
+ Clint Brinker
+ Hamza Elmi
+ Zac Polikarpus
+ Ricky Richards
+ Jon Robinson

[1]: https://www.sparkfun.com/products/12587
[2]: https://www.sparkfun.com/products/13990
[3]: https://www.sparkfun.com/products/11317
[4]: https://www.sparkfun.com/products/116
[5]: https://www.sparkfun.com/products/115
[6]: https://www.sparkfun.com/products/11367
[7]: https://www.sparkfun.com/
[8]: https://www.sparkfun.com/products/13746
[9]: https://www.arduino.cc/
[10]: https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide
[11]: https://learn.sparkfun.com/tutorials/nrf52832-breakout-board-hookup-guide
[12]: https://github.com/NordicSemiconductor/Android-nRF-Toolbox
[13]: https://github.com/sparkfun/Arduino_Boards
[14]: https://github.com/sandeepmistry/arduino-BLEPeripheral
