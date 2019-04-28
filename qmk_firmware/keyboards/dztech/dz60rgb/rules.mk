# project specific files

## chip/board settings
#   the next two should match the directories in
#   <chibios>/os/hal/ports/$(MCU_FAMILY)/$(MCU_SERIES)
MCU_FAMILY = STM32
MCU_SERIES = STM32F3xx

# Linker script to use
#   it should exist either in <chibios>/os/common/ports/ARMCMx/compilers/GCC/ld/
#   or <this_dir>/ld/
MCU_LDSCRIPT = STM32F303xC

# Startup code to use
#  - it should exist in <chibios>/os/common/startup/ARMCMx/compilers/GCC/mk/
MCU_STARTUP = stm32f3xx

# Board: it should exist either in <chibios>/os/hal/boards/
#  or <this_dir>/boards
BOARD = GENERIC_STM32_F303XC

# Cortex version
MCU  = cortex-m4

# ARM version, CORTEX-M0/M1 are 6, CORTEX-M3/M4/M7 are 7
ARMV = 7

USE_FPU = yes

# Vector table for application
# 0x00000000-0x00001000 area is occupied by bootlaoder.*/
# The CORTEX_VTOR... is needed only for MCHCK/Infinity KB
# OPT_DEFS = -DCORTEX_VTOR_INIT=0x08005000
OPT_DEFS =

# Options to pass to dfu-util when flashing
DFU_ARGS = -d 0483:df11 -a 0 -s 0x08000000:leave


BACKLIGHT_ENABLE = no
BOOTMAGIC_ENABLE = lite           # Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes              # Mouse keys
EXTRAKEY_ENABLE = yes              # Audio control and System control
CONSOLE_ENABLE = no                # Console for debug
COMMAND_ENABLE = no                # Commands for debug and configuration
#SLEEP_LED_ENABLE = yes            # Breathing sleep LED during USB suspend
NKRO_ENABLE = no                 # USB Nkey Rollover
AUDIO_ENABLE = no
RGB_MATRIX_ENABLE = IS31FL3733     # Use RGB matrix
NO_USB_STARTUP_CHECK = no          # Disable initialization only when usb is plugged in
