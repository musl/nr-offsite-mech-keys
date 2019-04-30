# QMK Setup Guide



## What is QMK?

QMK is an open source keyboard firmware that supports a ton of different keyboards and micro controllers. 

## What are we building?

https://keeb.io/products/bdn9-3x3-9-key-macropad-rotary-encoder-support?variant=15959960944734

## Getting setup

Regardless of the method of setup for compiling the firmware, the QMK Toolbox the easiest way to flash firmware. 

1. Download [QMK.Toolbox.app.zip](https://github.com/musl/nr-offsite-mech-keys/blob/master/QMK.Toolbox.app.zip) (or grab it locally if you have the repository checked out) and unzip it. Run the application and you should see this window. You're ready to flash a prebuilt firmware!

![Screen Shot 2019-04-28 at 3.58.51 PM](assets/qmk_toolbox.png)



## Compiling easy way

1. Open a terminal
2. Clone the this repository which has qmk_firmware vendored. 

```bash
git clone https://github.com/musl/nr-offsite-mech-keys.git
cd qmk_firmware
```

2. Make sure you have Docker for Mac installed https://docs.docker.com/docker-for-mac/install/

   ``` bash
   $ docker --version
   Docker version 18.09.2, build 6247962
   ```


3. cd into the qmk_firmware subdirectory

   ```bash
   $ cd qmk_firmware
   ```

4. Run the utility script to compile the firmware with docker

   ```bash
   $ util/docker_build.sh keyboard:keymap
   ```

   For our macropod, run this command

   ```bash
   $ ./util/docker_build.sh keebio/bdn9:default
   # this will output the hex into the root qmk_firmware directory
   $ ls | grep hex
   keebio_bdn9_default.hex
   ```

   5. Follow the flashing guide to flash the resulting firmware binary onto the macropod.

## Compiling harder way

1. Go follow the guide for the full qmk setup here: https://docs.qmk.fm/#/newbs_getting_started

   