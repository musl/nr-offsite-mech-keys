/* Copyright 2016-2017 Yang Liu
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <math.h>
#include <avr/eeprom.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "progmem.h"
#include "timer.h"
#include "rgblight.h"
#include "debug.h"
#include "led_tables.h"
#include "mxss_frontled.h"

#ifndef RGBLIGHT_LIMIT_VAL
#define RGBLIGHT_LIMIT_VAL 255
#endif

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#define LED_PTRTOIND(ptr) ((uint32_t) (ptr - led)/sizeof(LED_TYPE))

void copyrgb(LED_TYPE *src, LED_TYPE *dst);

__attribute__ ((weak))
const uint8_t RGBLED_BREATHING_INTERVALS[] PROGMEM = {30, 20, 10, 5};
__attribute__ ((weak))
const uint8_t RGBLED_RAINBOW_MOOD_INTERVALS[] PROGMEM = {120, 60, 30};
__attribute__ ((weak))
const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {100, 50, 20};
__attribute__ ((weak))
const uint8_t RGBLED_SNAKE_INTERVALS[] PROGMEM = {100, 50, 20};
__attribute__ ((weak))
const uint8_t RGBLED_KNIGHT_INTERVALS[] PROGMEM = {127, 63, 31};
__attribute__ ((weak))
const uint16_t RGBLED_GRADIENT_RANGES[] PROGMEM = {360, 240, 180, 120, 90};
__attribute__ ((weak))
const uint16_t RGBLED_RGBTEST_INTERVALS[] PROGMEM = {1024};

rgblight_config_t rgblight_config;

LED_TYPE led[RGBLED_NUM];

bool rgblight_timer_enabled = false;

extern uint8_t fled_mode;
extern uint8_t fled_val;
extern LED_TYPE fleds[2];
hs_set fled_hs[2];

void sethsv(uint16_t hue, uint8_t sat, uint8_t val, LED_TYPE *led1) {
  uint8_t r = 0, g = 0, b = 0, base, color;
  
  // if led is front leds, cache the hue and sat values
  if (led1 == &led[RGBLIGHT_FLED1]) {
      fled_hs[0].hue = hue;
      fled_hs[0].sat = sat;
  } else if (led1 == &led[RGBLIGHT_FLED2]) {
      fled_hs[1].hue = hue;
      fled_hs[1].sat = sat;
  }

  if (val > RGBLIGHT_LIMIT_VAL) {
      val=RGBLIGHT_LIMIT_VAL; // limit the val
  }

  if (sat == 0) { // Acromatic color (gray). Hue doesn't mind.
    r = val;
    g = val;
    b = val;
  } else {
    base = ((255 - sat) * val) >> 8;
    color = (val - base) * (hue % 60) / 60;

    switch (hue / 60) {
      case 0:
        r = val;
        g = base + color;
        b = base;
        break;
      case 1:
        r = val - color;
        g = val;
        b = base;
        break;
      case 2:
        r = base;
        g = val;
        b = base + color;
        break;
      case 3:
        r = base;
        g = val - color;
        b = val;
        break;
      case 4:
        r = base + color;
        g = base;
        b = val;
        break;
      case 5:
        r = val;
        g = base;
        b = val - color;
        break;
    }
  }
  r = pgm_read_byte(&CIE1931_CURVE[r]);
  g = pgm_read_byte(&CIE1931_CURVE[g]);
  b = pgm_read_byte(&CIE1931_CURVE[b]);

  setrgb(r, g, b, led1);
}

void setrgb(uint8_t r, uint8_t g, uint8_t b, LED_TYPE *led1) {
  (*led1).r = r;
  (*led1).g = g;
  (*led1).b = b;
}

void copyrgb(LED_TYPE *src, LED_TYPE *dst) {
  (*dst).r = (*src).r;
  (*dst).g = (*src).g;
  (*dst).b = (*src).b;
}

uint32_t eeconfig_read_rgblight(void) {
  return eeprom_read_dword(EECONFIG_RGBLIGHT);
}
void eeconfig_update_rgblight(uint32_t val) {
  eeprom_update_dword(EECONFIG_RGBLIGHT, val);
}
void eeconfig_update_rgblight_default(void) {
  dprintf("eeconfig_update_rgblight_default\n");
  rgblight_config.enable = 1;
  rgblight_config.mode = 1;
  rgblight_config.hue = 0;
  rgblight_config.sat = 255;
  rgblight_config.val = RGBLIGHT_LIMIT_VAL;
  rgblight_config.speed = 0;
  eeconfig_update_rgblight(rgblight_config.raw);
}
void eeconfig_debug_rgblight(void) {
  dprintf("rgblight_config eprom\n");
  dprintf("rgblight_config.enable = %d\n", rgblight_config.enable);
  dprintf("rghlight_config.mode = %d\n", rgblight_config.mode);
  dprintf("rgblight_config.hue = %d\n", rgblight_config.hue);
  dprintf("rgblight_config.sat = %d\n", rgblight_config.sat);
  dprintf("rgblight_config.val = %d\n", rgblight_config.val);
  dprintf("rgblight_config.speed = %d\n", rgblight_config.speed);
}

void rgblight_init(void) {
  debug_enable = 1; // Debug ON!
  dprintf("rgblight_init called.\n");
  dprintf("rgblight_init start!\n");
  if (!eeconfig_is_enabled()) {
    dprintf("rgblight_init eeconfig is not enabled.\n");
    eeconfig_init();
    eeconfig_update_rgblight_default();
  }
  rgblight_config.raw = eeconfig_read_rgblight();
  if (!rgblight_config.mode) {
    dprintf("rgblight_init rgblight_config.mode = 0. Write default values to EEPROM.\n");
    eeconfig_update_rgblight_default();
    rgblight_config.raw = eeconfig_read_rgblight();
  }
  eeconfig_debug_rgblight(); // display current eeprom values

  #ifdef RGBLIGHT_ANIMATIONS
    rgblight_timer_init(); // setup the timer
  #endif

  if (rgblight_config.enable) {
    rgblight_mode_noeeprom(rgblight_config.mode);
  }
}

void rgblight_update_dword(uint32_t dword) {
  rgblight_config.raw = dword;
  eeconfig_update_rgblight(rgblight_config.raw);
  if (rgblight_config.enable)
    rgblight_mode(rgblight_config.mode);
  else {
    #ifdef RGBLIGHT_ANIMATIONS
      rgblight_timer_disable();
    #endif
      rgblight_set();
  }
}

void rgblight_increase(void) {
  uint8_t mode = 0;
  if (rgblight_config.mode < RGBLIGHT_MODES) {
    mode = rgblight_config.mode + 1;
  }
  rgblight_mode(mode);
}
void rgblight_decrease(void) {
  uint8_t mode = 0;
  // Mode will never be < 1. If it ever is, eeprom needs to be initialized.
  if (rgblight_config.mode > 1) {
    mode = rgblight_config.mode - 1;
  }
  rgblight_mode(mode);
}
void rgblight_step(void) {
  uint8_t mode = 0;
  mode = rgblight_config.mode + 1;
  if (mode > RGBLIGHT_MODES) {
    mode = 1;
  }
  rgblight_mode(mode);
}
void rgblight_step_reverse(void) {
  uint8_t mode = 0;
  mode = rgblight_config.mode - 1;
  if (mode < 1) {
    mode = RGBLIGHT_MODES;
  }
  rgblight_mode(mode);
}

uint8_t rgblight_get_mode(void) {
  if (!rgblight_config.enable) {
    return false;
  }

  return rgblight_config.mode;
}

void rgblight_mode_eeprom_helper(uint8_t mode, bool write_to_eeprom) {
  if (!rgblight_config.enable) {
    return;
  }
  if (mode < 1) {
    rgblight_config.mode = 1;
  } else if (mode > RGBLIGHT_MODES) {
    rgblight_config.mode = RGBLIGHT_MODES;
  } else {
    rgblight_config.mode = mode;
  }
  if (write_to_eeprom) {
    eeconfig_update_rgblight(rgblight_config.raw);
    xprintf("rgblight mode [EEPROM]: %u\n", rgblight_config.mode);
  } else {
    xprintf("rgblight mode [NOEEPROM]: %u\n", rgblight_config.mode);
  }
  if (rgblight_config.mode == 1) {
    #ifdef RGBLIGHT_ANIMATIONS
      rgblight_timer_disable();
    #endif
  } else if ((rgblight_config.mode >= 2 && rgblight_config.mode <= 24) ||
	     rgblight_config.mode == 35 ) {
    // MODE 2-5, breathing
    // MODE 6-8, rainbow mood
    // MODE 9-14, rainbow swirl
    // MODE 15-20, snake
    // MODE 21-23, knight
    // MODE 24, xmas
    // MODE 35  RGB test

    #ifdef RGBLIGHT_ANIMATIONS
      rgblight_timer_enable();
    #endif
  } else if (rgblight_config.mode >= 25 && rgblight_config.mode <= 34) {
    // MODE 25-34, static gradient

    #ifdef RGBLIGHT_ANIMATIONS
      rgblight_timer_disable();
    #endif
  }
  rgblight_sethsv_noeeprom(rgblight_config.hue, rgblight_config.sat, rgblight_config.val);
}

void rgblight_mode(uint8_t mode) {
  rgblight_mode_eeprom_helper(mode, true);
}

void rgblight_mode_noeeprom(uint8_t mode) {
  rgblight_mode_eeprom_helper(mode, false);
}


void rgblight_toggle(void) {
  xprintf("rgblight toggle [EEPROM]: rgblight_config.enable = %u\n", !rgblight_config.enable);
  if (rgblight_config.enable) {
    rgblight_disable();
  }
  else {
    rgblight_enable();
  }
}

void rgblight_toggle_noeeprom(void) {
  xprintf("rgblight toggle [NOEEPROM]: rgblight_config.enable = %u\n", !rgblight_config.enable);
  if (rgblight_config.enable) {
    rgblight_disable_noeeprom();
  }
  else {
    rgblight_enable_noeeprom();
  }
}

void rgblight_enable(void) {
  rgblight_config.enable = 1;
  // No need to update EEPROM here. rgblight_mode() will do that, actually
  //eeconfig_update_rgblight(rgblight_config.raw);
  xprintf("rgblight enable [EEPROM]: rgblight_config.enable = %u\n", rgblight_config.enable);
  rgblight_mode(rgblight_config.mode);
}

void rgblight_enable_noeeprom(void) {
  rgblight_config.enable = 1;
  xprintf("rgblight enable [NOEEPROM]: rgblight_config.enable = %u\n", rgblight_config.enable);
  rgblight_mode_noeeprom(rgblight_config.mode);
}

void rgblight_disable(void) {
  rgblight_config.enable = 0;
  eeconfig_update_rgblight(rgblight_config.raw);
  xprintf("rgblight disable [EEPROM]: rgblight_config.enable = %u\n", rgblight_config.enable);
  #ifdef RGBLIGHT_ANIMATIONS
    //rgblight_timer_disable();
  #endif
  _delay_ms(50);
  rgblight_set();
}

void rgblight_disable_noeeprom(void) {
  rgblight_config.enable = 0;
  xprintf("rgblight disable [noEEPROM]: rgblight_config.enable = %u\n", rgblight_config.enable);
  #ifdef RGBLIGHT_ANIMATIONS
    rgblight_timer_disable();
  #endif
  _delay_ms(50);
  rgblight_set();
}


// Deals with the messy details of incrementing an integer
uint8_t increment( uint8_t value, uint8_t step, uint8_t min, uint8_t max ) {
    int16_t new_value = value;
    new_value += step;
    return MIN( MAX( new_value, min ), max );
}

uint8_t decrement( uint8_t value, uint8_t step, uint8_t min, uint8_t max ) {
    int16_t new_value = value;
    new_value -= step;
    return MIN( MAX( new_value, min ), max );
}

void rgblight_increase_hue(void) {
  uint16_t hue;
  hue = (rgblight_config.hue+RGBLIGHT_HUE_STEP) % 360;
  rgblight_sethsv(hue, rgblight_config.sat, rgblight_config.val);
}
void rgblight_decrease_hue(void) {
  uint16_t hue;
  if (rgblight_config.hue-RGBLIGHT_HUE_STEP < 0) {
    hue = (rgblight_config.hue + 360 - RGBLIGHT_HUE_STEP) % 360;
  } else {
    hue = (rgblight_config.hue - RGBLIGHT_HUE_STEP) % 360;
  }
  rgblight_sethsv(hue, rgblight_config.sat, rgblight_config.val);
}
void rgblight_increase_sat(void) {
  uint8_t sat;
  if (rgblight_config.sat + RGBLIGHT_SAT_STEP > 255) {
    sat = 255;
  } else {
    sat = rgblight_config.sat + RGBLIGHT_SAT_STEP;
  }
  rgblight_sethsv(rgblight_config.hue, sat, rgblight_config.val);
}
void rgblight_decrease_sat(void) {
  uint8_t sat;
  if (rgblight_config.sat - RGBLIGHT_SAT_STEP < 0) {
    sat = 0;
  } else {
    sat = rgblight_config.sat - RGBLIGHT_SAT_STEP;
  }
  rgblight_sethsv(rgblight_config.hue, sat, rgblight_config.val);
}
void rgblight_increase_val(void) {
  uint8_t val;
  if (rgblight_config.val + RGBLIGHT_VAL_STEP > RGBLIGHT_LIMIT_VAL) {
    val = RGBLIGHT_LIMIT_VAL;
  } else {
    val = rgblight_config.val + RGBLIGHT_VAL_STEP;
  }
  rgblight_sethsv(rgblight_config.hue, rgblight_config.sat, val);
}
void rgblight_decrease_val(void) {
  uint8_t val;
  if (rgblight_config.val - RGBLIGHT_VAL_STEP < 0) {
    val = 0;
  } else {
    val = rgblight_config.val - RGBLIGHT_VAL_STEP;
  }
  rgblight_sethsv(rgblight_config.hue, rgblight_config.sat, val);
}
void rgblight_increase_speed(void) {
    rgblight_config.speed = increment( rgblight_config.speed, 1, 0, 3 );
    eeconfig_update_rgblight(rgblight_config.raw);//EECONFIG needs to be increased to support this
}

void rgblight_decrease_speed(void) {
    rgblight_config.speed = decrement( rgblight_config.speed, 1, 0, 3 );
    eeconfig_update_rgblight(rgblight_config.raw);//EECONFIG needs to be increased to support this
}

void rgblight_sethsv_noeeprom_old(uint16_t hue, uint8_t sat, uint8_t val) {
  if (rgblight_config.enable) {
    LED_TYPE tmp_led;
    sethsv(hue, sat, val, &tmp_led);
    fled_hs[0].hue = fled_hs[1].hue = hue;
    fled_hs[0].sat = fled_hs[1].sat = sat;
    // dprintf("rgblight set hue [MEMORY]: %u,%u,%u\n", inmem_config.hue, inmem_config.sat, inmem_config.val);
    rgblight_setrgb(tmp_led.r, tmp_led.g, tmp_led.b);
  }
}

void rgblight_sethsv_eeprom_helper(uint16_t hue, uint8_t sat, uint8_t val, bool write_to_eeprom) {
  if (rgblight_config.enable) {
    if (rgblight_config.mode == 1) {
      // same static color
      LED_TYPE tmp_led;
      sethsv(hue, sat, val, &tmp_led);
      
      fled_hs[0].hue = fled_hs[1].hue = hue;
      fled_hs[0].sat = fled_hs[1].sat = sat;
      
      rgblight_setrgb(tmp_led.r, tmp_led.g, tmp_led.b);
    } else {
      // all LEDs in same color
      if (rgblight_config.mode >= 2 && rgblight_config.mode <= 5) {
        // breathing mode, ignore the change of val, use in memory value instead
        val = rgblight_config.val;
      } else if (rgblight_config.mode >= 6 && rgblight_config.mode <= 14) {
        // rainbow mood and rainbow swirl, ignore the change of hue
        hue = rgblight_config.hue;
      } else if (rgblight_config.mode >= 25 && rgblight_config.mode <= 34) {
        // static gradient
        uint16_t _hue;
        int8_t direction = ((rgblight_config.mode - 25) % 2) ? -1 : 1;
        uint16_t range = pgm_read_word(&RGBLED_GRADIENT_RANGES[(rgblight_config.mode - 25) / 2]);
        for (uint8_t i = 0; i < RGBLED_NUM; i++) {
          _hue = (range / RGBLED_NUM * i * direction + hue + 360) % 360;
          dprintf("rgblight rainbow set hsv: %u,%u,%d,%u\n", i, _hue, direction, range);
          sethsv(_hue, sat, val, (LED_TYPE *)&led[i]);
        }
        rgblight_set();
      }
    }
    rgblight_config.hue = hue;
    rgblight_config.sat = sat;
    rgblight_config.val = val;
    if (write_to_eeprom) {
      eeconfig_update_rgblight(rgblight_config.raw);
      xprintf("rgblight set hsv [EEPROM]: %u,%u,%u\n", rgblight_config.hue, rgblight_config.sat, rgblight_config.val);
    } else {
      xprintf("rgblight set hsv [NOEEPROM]: %u,%u,%u\n", rgblight_config.hue, rgblight_config.sat, rgblight_config.val);
    }
  }
}

void rgblight_sethsv(uint16_t hue, uint8_t sat, uint8_t val) {
  rgblight_sethsv_eeprom_helper(hue, sat, val, true);
}

void rgblight_sethsv_noeeprom(uint16_t hue, uint8_t sat, uint8_t val) {
  rgblight_sethsv_eeprom_helper(hue, sat, val, false);
}

uint16_t rgblight_get_hue(void) {
  return rgblight_config.hue;
}

uint8_t rgblight_get_sat(void) {
  return rgblight_config.sat;
}

uint8_t rgblight_get_val(void) {
  return rgblight_config.val;
}

void rgblight_setrgb(uint8_t r, uint8_t g, uint8_t b) {
  if (!rgblight_config.enable) { return; }

  for (uint8_t i = 0; i < RGBLED_NUM; i++) {
    led[i].r = r;
    led[i].g = g;
    led[i].b = b;
  }
  rgblight_set();
}

void rgblight_setrgb_at(uint8_t r, uint8_t g, uint8_t b, uint8_t index) {
  if (!rgblight_config.enable || index >= RGBLED_NUM) { return; }

  led[index].r = r;
  led[index].g = g;
  led[index].b = b;
  rgblight_set();
}

void rgblight_sethsv_at(uint16_t hue, uint8_t sat, uint8_t val, uint8_t index) {
  if (!rgblight_config.enable) { return; }

  LED_TYPE tmp_led;
  sethsv(hue, sat, val, &tmp_led);
  rgblight_setrgb_at(tmp_led.r, tmp_led.g, tmp_led.b, index);
}

void rgblight_set(void) {
  if (!rgblight_config.enable) {
    for (uint8_t i = 0; i < RGBLED_NUM; i++) {
      if (i == RGBLIGHT_FLED1 && i == RGBLIGHT_FLED2)
          continue;
      
      led[i].r = 0;
      led[i].g = 0;
      led[i].b = 0;
    }
  }
  
  switch (fled_mode) {
      case FLED_OFF:
      setrgb(0, 0, 0, &led[RGBLIGHT_FLED1]);
      setrgb(0, 0, 0, &led[RGBLIGHT_FLED2]);
      break;
      
      case FLED_INDI:
      copyrgb(&fleds[0], &led[RGBLIGHT_FLED1]);
      copyrgb(&fleds[1], &led[RGBLIGHT_FLED2]);
      break;
      
      case FLED_RGB:
      if (fled_hs[0].hue == 0 && fled_hs[0].hue == 0 && (rgblight_config.mode >= 15 && rgblight_config.mode <= 23))
          setrgb(0, 0, 0, &led[RGBLIGHT_FLED1]);
      else
        sethsv(fled_hs[0].hue, fled_hs[0].sat, fled_val, &led[RGBLIGHT_FLED1]);
      
      if (fled_hs[1].hue == 0 && fled_hs[1].hue == 0 && (rgblight_config.mode >= 15 && rgblight_config.mode <= 23))
          setrgb(0, 0, 0, &led[RGBLIGHT_FLED2]);
      else
          sethsv(fled_hs[1].hue, fled_hs[1].sat, fled_val, &led[RGBLIGHT_FLED2]);
      break;
      
      default:
      break;
  }

   ws2812_setleds(led, RGBLED_NUM);
}

#ifdef RGBLIGHT_ANIMATIONS

// Animation timer -- AVR Timer3
void rgblight_timer_init(void) {
  // static uint8_t rgblight_timer_is_init = 0;
  // if (rgblight_timer_is_init) {
  //   return;
  // }
  // rgblight_timer_is_init = 1;
  // /* Timer 3 setup */
  // TCCR3B = _BV(WGM32) // CTC mode OCR3A as TOP
  //       | _BV(CS30); // Clock selelct: clk/1
  // /* Set TOP value */
  // uint8_t sreg = SREG;
  // cli();
  // OCR3AH = (RGBLED_TIMER_TOP >> 8) & 0xff;
  // OCR3AL = RGBLED_TIMER_TOP & 0xff;
  // SREG = sreg;

  rgblight_timer_enabled = true;
}
void rgblight_timer_enable(void) {
  rgblight_timer_enabled = true;
  dprintf("TIMER3 enabled.\n");
}
void rgblight_timer_disable(void) {
  rgblight_timer_enabled = false;
  dprintf("TIMER3 disabled.\n");
}
void rgblight_timer_toggle(void) {
  rgblight_timer_enabled ^= rgblight_timer_enabled;
  dprintf("TIMER3 toggled.\n");
}

void rgblight_show_solid_color(uint8_t r, uint8_t g, uint8_t b) {
  rgblight_enable();
  rgblight_mode(1);
  rgblight_setrgb(r, g, b);
}

void rgblight_task(void) {
  if (rgblight_timer_enabled) {
    // mode = 1, static light, do nothing here
    if (rgblight_config.mode >= 2 && rgblight_config.mode <= 5) {
      // mode = 2 to 5, breathing mode
      rgblight_effect_breathing(rgblight_config.mode - 2);
    } else if (rgblight_config.mode >= 6 && rgblight_config.mode <= 8) {
      // mode = 6 to 8, rainbow mood mod
      rgblight_effect_rainbow_mood(rgblight_config.mode - 6);
    } else if (rgblight_config.mode >= 9 && rgblight_config.mode <= 14) {
      // mode = 9 to 14, rainbow swirl mode
      rgblight_effect_rainbow_swirl(rgblight_config.mode - 9);
    } else if (rgblight_config.mode >= 15 && rgblight_config.mode <= 20) {
      // mode = 15 to 20, snake mode
      rgblight_effect_snake(rgblight_config.mode - 15);
    } else if (rgblight_config.mode >= 21 && rgblight_config.mode <= 23) {
      // mode = 21 to 23, knight mode
      rgblight_effect_knight(rgblight_config.mode - 21);
    } else if (rgblight_config.mode == 24) {
      // mode = 24, christmas mode
      rgblight_effect_christmas();
    } else if (rgblight_config.mode == 35) {
      // mode = 35, RGB test
      rgblight_effect_rgbtest();
    }
  }
}

// Effects
void rgblight_effect_breathing(uint8_t interval) {
  static uint8_t pos = 0;
  static uint16_t last_timer = 0;
  float val;

  if (timer_elapsed(last_timer) < pgm_read_byte(&RGBLED_BREATHING_INTERVALS[interval])) {
    return;
  }
  last_timer = timer_read();


  // http://sean.voisen.org/blog/2011/10/breathing-led-with-arduino/
  val = (exp(sin((pos/255.0)*M_PI)) - RGBLIGHT_EFFECT_BREATHE_CENTER/M_E)*(RGBLIGHT_EFFECT_BREATHE_MAX/(M_E-1/M_E));
  rgblight_sethsv_noeeprom_old(rgblight_config.hue, rgblight_config.sat, val);
  pos = (pos + 1) % 256;
}
void rgblight_effect_rainbow_mood(uint8_t interval) {
  static uint16_t current_hue = 0;
  static uint16_t last_timer = 0;

  if (timer_elapsed(last_timer) < pgm_read_byte(&RGBLED_RAINBOW_MOOD_INTERVALS[interval])) {
    return;
  }
  last_timer = timer_read();
  rgblight_sethsv_noeeprom_old(current_hue, rgblight_config.sat, rgblight_config.val);
  current_hue = (current_hue + 1) % 360;
}
void rgblight_effect_rainbow_swirl(uint8_t interval) {
  static uint16_t current_hue = 0;
  static uint16_t last_timer = 0;
  uint16_t hue;
  uint8_t i;
  if (timer_elapsed(last_timer) < pgm_read_byte(&RGBLED_RAINBOW_SWIRL_INTERVALS[interval / 2])) {
    return;
  }
  last_timer = timer_read();
  for (i = 0; i < RGBLED_NUM; i++) {
    hue = (360 / RGBLED_NUM * i + current_hue) % 360;
    sethsv(hue, rgblight_config.sat, rgblight_config.val, (LED_TYPE *)&led[i]);
  }
  rgblight_set();

  if (interval % 2) {
    current_hue = (current_hue + 1) % 360;
  } else {
    if (current_hue - 1 < 0) {
      current_hue = 359;
    } else {
      current_hue = current_hue - 1;
    }
  }
}
void rgblight_effect_snake(uint8_t interval) {
  static uint8_t pos = 0;
  static uint16_t last_timer = 0;
  uint8_t i, j;
  int8_t k;
  int8_t increment = 1;
  if (interval % 2) {
    increment = -1;
  }
  if (timer_elapsed(last_timer) < pgm_read_byte(&RGBLED_SNAKE_INTERVALS[interval / 2])) {
    return;
  }
  last_timer = timer_read();
  
  fled_hs[0].hue = fled_hs[1].hue = 0;
  fled_hs[0].sat = fled_hs[1].sat = 0;
  
  for (i = 0; i < RGBLED_NUM; i++) {
    led[i].r = 0;
    led[i].g = 0;
    led[i].b = 0;

    for (j = 0; j < RGBLIGHT_EFFECT_SNAKE_LENGTH; j++) {
      k = pos + j * increment;
      if (k < 0) {
        k = k + RGBLED_NUM;
      }
      if (i == k) {
        sethsv(rgblight_config.hue, rgblight_config.sat, (uint8_t)(rgblight_config.val*(RGBLIGHT_EFFECT_SNAKE_LENGTH-j)/RGBLIGHT_EFFECT_SNAKE_LENGTH), (LED_TYPE *)&led[i]);
      }
    }
  }
  rgblight_set();
  if (increment == 1) {
    if (pos - 1 < 0) {
      pos = RGBLED_NUM - 1;
    } else {
      pos -= 1;
    }
  } else {
    pos = (pos + 1) % RGBLED_NUM;
  }
}
void rgblight_effect_knight(uint8_t interval) {
  static uint16_t last_timer = 0;
  if (timer_elapsed(last_timer) < pgm_read_byte(&RGBLED_KNIGHT_INTERVALS[interval])) {
    return;
  }
  last_timer = timer_read();

  static int8_t low_bound = 0;
  static int8_t high_bound = RGBLIGHT_EFFECT_KNIGHT_LENGTH - 1;
  static int8_t increment = 1;
  uint8_t i, cur;

  // Set all the LEDs to 0
  for (i = 0; i < RGBLED_NUM; i++) {
    led[i].r = 0;
    led[i].g = 0;
    led[i].b = 0;
  }
  // Determine which LEDs should be lit up
  for (i = 0; i < RGBLIGHT_EFFECT_KNIGHT_LED_NUM; i++) {
    cur = (i + RGBLIGHT_EFFECT_KNIGHT_OFFSET) % RGBLED_NUM;

    if (i >= low_bound && i <= high_bound) {
      sethsv(rgblight_config.hue, rgblight_config.sat, rgblight_config.val, (LED_TYPE *)&led[cur]);
    } else {
      if (i == RGBLIGHT_FLED1 || i == RGBLIGHT_FLED2) {
          fled_hs[0].hue = fled_hs[1].hue = 0;
          fled_hs[0].sat = fled_hs[1].sat = 0;
      }
        
      led[cur].r = 0;
      led[cur].g = 0;
      led[cur].b = 0;
    }
  }
  rgblight_set();

  // Move from low_bound to high_bound changing the direction we increment each
  // time a boundary is hit.
  low_bound += increment;
  high_bound += increment;

  if (high_bound <= 0 || low_bound >= RGBLIGHT_EFFECT_KNIGHT_LED_NUM - 1) {
    increment = -increment;
  }
}


void rgblight_effect_christmas(void) {
  static uint16_t current_offset = 0;
  static uint16_t last_timer = 0;
  uint16_t hue;
  uint8_t i;
  if (timer_elapsed(last_timer) < RGBLIGHT_EFFECT_CHRISTMAS_INTERVAL) {
    return;
  }
  last_timer = timer_read();
  current_offset = (current_offset + 1) % 2;
  for (i = 0; i < RGBLED_NUM; i++) {
    hue = 0 + ((i/RGBLIGHT_EFFECT_CHRISTMAS_STEP + current_offset) % 2) * 120;
    sethsv(hue, rgblight_config.sat, rgblight_config.val, (LED_TYPE *)&led[i]);
  }
  rgblight_set();
}

void rgblight_effect_rgbtest(void) {
  static uint8_t pos = 0;
  static uint16_t last_timer = 0;
  static uint8_t maxval = 0;
  uint8_t g; uint8_t r; uint8_t b;

  if (timer_elapsed(last_timer) < pgm_read_word(&RGBLED_RGBTEST_INTERVALS[0])) {
    return;
  }

  if( maxval == 0 ) {
      LED_TYPE tmp_led;
      sethsv(0, 255, RGBLIGHT_LIMIT_VAL, &tmp_led);
      maxval = tmp_led.r;
  }
  last_timer = timer_read();
  g = r = b = 0;
  switch( pos ) {
    case 0: r = maxval; break;
    case 1: g = maxval; break;
    case 2: b = maxval; break;
  }
  rgblight_setrgb(r, g, b);
  pos = (pos + 1) % 3;
}

#endif /* RGBLIGHT_ANIMATIONS */
