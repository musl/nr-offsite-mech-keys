# TGR Alice

![TGR Alice](https://i.imgur.com/cJohEqS.jpg)

An ergonomic 60% keyboard.

Keyboard Maintainer: [Felipe Coury](https://github.com/fcoury)  
Hardware Supported: TGR Alice  
Hardware Availability: Group buy finished  

Make example for this keyboard (after setting up your build environment):

    make alice:default

See [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) then the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information.


ps2avrGB keyboard firmware
==========================

This keyboard uses the port of the QMK firmware for boards that are based on the
ps2avrGB firmware.

Note that this is a complete replacement for the firmware, so you won't be
using Bootmapper Client to change any keyboard settings, since not all the
USB report options are supported.

## Installing

First, install the requirements. These commands are for OSX, but all you
need is the AVR toolchain and `bootloadHID` for flashing:

```
$ brew cask install crosspack-avr
$ brew install --HEAD https://raw.githubusercontent.com/robertgzr/homebrew-tap/master/bootloadhid.rb
$ pip install pyusb
```

Then, with the keyboard plugged in, simply run this command from the
`qmk_firmware` directory:

```
$ make alice
$ bootloadHID -r alice_default.hex
```

## Setting the board to bootloader mode

Hold the ESC key (the one before the 1! key, in case you remaped it).

## Troubleshooting

From my experience, it's really hard to brick these boards. But these
tricks have been useful when it got stuck in a weird scenario.

1. Try plugging the board in while holding the bootloader key. This will force
   it to boot only the bootloader without loading the firmware. Once this is
   done, just reflash the board with the original firmware.
2. Sometimes USB hubs can act weird, so try connecting the board directly
   to your computer or plugging/unplugging the USB hub.
