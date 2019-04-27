# QMK Setup Guide

QMK is an open source keyboard firmware that supports a ton of different keyboards and micro controllers. 

//TODO links to docs/downloads/etc

// TODO TOC

// TODO look into running qmk_config/qmk_api/qmk_compiler locally in case network access is an issue

## Every which way

// TODO check if Toolbox needs external deps for flashing or if they are bundled in

Regardless of the method of setup for compiling the firmware, the QMK Toolbox the easiest way to flash firmware. 

1. Download and install the QMK Toolbox. This tool allows for very easy flashing of firmware onto keyboards using a GUI and automatic controller detection. Get the Toolbox here:

## Easy way 

// Change to use the provided hex that is checked into this repo


1. Use https://config.qmk.fm/#/ for creating your keymap. This lets you define the keymap, compile it, and download the resulting hex file to flash using the Toolbox; all without installing any dependencies or cloning the firmware repository. 

## Hard way

1. Clone the qmk_firmware repository. 

```bash
git clone --recurse-submodules https://github.com/qmk/qmk_firmware.git
cd qmk_firmware
```

2. Make sure you have Docker for Mac installed https://docs.docker.com/docker-for-mac/install/


3. Follow the guide here: https://docs.qmk.fm/#/getting_started_build_tools?id=docker to get setup for compiling with Docker. 

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

