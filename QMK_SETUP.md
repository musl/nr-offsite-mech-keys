# QMK Setup Guide

QMK is an open source keyboard firmware that supports a ton of different keyboards and micro controllers. 

## Every which way

Regardless of the method of setup for compiling the firmware, the QMK Toolbox the easiest way to flash firmware. 

1. Download [QMK.Toolbox.app.zip](https://github.com/musl/nr-offsite-mech-keys/blob/master/QMK.Toolbox.app.zip) (or grab it locally if you have the repository checked out) and unzip it. Run the application and you should see this window. You're ready to flash a prebuilt firmware!

![Screen Shot 2019-04-28 at 3.58.51 PM](assets/qmk_toolbox.png)

## Easy way 

Use the provided prebuilt firmware binary here //TODO link and then follow the flashing guide here //TODO link

## Hard way

1. Clone the qmk_firmware repository. 

```bash
git clone --recurse-submodules https://github.com/qmk/qmk_firmware.git
cd qmk_firmware
```

2. Make sure you have Docker for Mac installed https://docs.docker.com/docker-for-mac/install/


3. Follow the guide here: https://docs.qmk.fm/#/getting_started_build_tools?id=docker to get setup for compiling with Docker. 
4. Follow the flashing guide here: //TODO link

## Harder way

At the end of this setup you will have a fully configured build and flash environment for QMK. Full docs from QMK here: https://docs.qmk.fm/#/newbs_getting_started?id=set-up-qmk


1. Clone the qmk_firmware repository. 

```bash
git clone --recurse-submodules https://github.com/qmk/qmk_firmware.git
cd qmk_firmware
```

2. Ensure you have homebrew installed and up to date https://brew.sh/

3. From the root of the repository, run the setup script

```bash
$ util/qmk_install.sh
```

4. Follow the flashing guide here: //TODO link