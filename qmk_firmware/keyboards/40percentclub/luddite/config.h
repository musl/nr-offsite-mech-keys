#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0A0C
#define DEVICE_VER      0x1001
#define MANUFACTURER    di0ib
#define PRODUCT         Luddite
#define DESCRIPTION     Luddite Keyboard

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 8

/* key matrix pins */
#define MATRIX_ROW_PINS { D3, D2, D1, D0, D4, C6, D7, E6 }
#define MATRIX_COL_PINS { F4, F5, F6, F7, B1, B3, B2, B6 }
#define UNUSED_PINS

/* number of backlight levels */
#define BACKLIGHT_PIN B5
#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 4
#endif

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* ws2812 RGB LED */
#define RGB_DI_PIN B4
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 8    // Number of LEDs
// #define RGBLIGHT_HUE_STEP 10
// #define RGBLIGHT_SAT_STEP 17
// #define RGBLIGHT_VAL_STEP 17
