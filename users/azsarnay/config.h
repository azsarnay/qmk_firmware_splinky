// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#ifdef IS_COMMAND
#    undef IS_COMMAND
#endif
#define IS_COMMAND() (((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) == MOD_MASK_SHIFT)

#if defined(SPLIT_KEYBOARD)
#    include "split/split_config.h"
#endif

#ifdef OLED_ENABLE
#    include "oled/oled_config.h"
#endif

#ifdef POINTING_DEVICE_ENABLE
#    include "pointing/pointing_config.h"
#endif // POINTING_DEVICE_ENABLE

#ifdef AUDIO_ENABLE
#    include "audio_config.h"
#endif // AUDIO_ENABLE

#if defined(WPM_ENABLE)
// #    define WPM_LAUNCH_CONTROL
// #    define WPM_UNFILTERED
#    define WPM_ALLOW_COUNT_REGRESSION
#    define WPM_SAMPLE_SECONDS 10
#    define WPM_SAMPLE_PERIODS 50
#    define WPM_ESTIMATED_WORD_SIZE 5
#endif

#define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE, UNICODE_MODE_MACOS


#if defined(PER_KEY_TAPPING)
#    define PERMISSIVE_HOLD_PER_KEY
#    define QUICK_TAP_TERM_PER_KEY
#    define HOLD_ON_OTHER_KEY
#    define RETRO_TAPPING_PER_KEY
#    define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#    define TAPPING_TERM_PER_KEY
#else
#    undef PERMISSIVE_HOLD
#endif


/* Disable unused and unneeded features to reduce on firmware size */
#ifdef LOCKING_SUPPORT_ENABLE
#    undef LOCKING_SUPPORT_ENABLE
#endif
#ifdef LOCKING_RESYNC_ENABLE
#    undef LOCKING_RESYNC_ENABLE
#endif

#ifdef CONVERT_TO_PROTON_C
// pins that are available but not present on Pro Micro
#    define A3 PAL_LINE(GPIOA, 3)
#    define A4 PAL_LINE(GPIOA, 4)
#    define A5 PAL_LINE(GPIOA, 5)
#    define A6 PAL_LINE(GPIOA, 6)
#    define A7 PAL_LINE(GPIOA, 7)
#    define A8 PAL_LINE(GPIOA, 8)
#    define A13 PAL_LINE(GPIOA, 13)
#    define A14 PAL_LINE(GPIOA, 14)
#    define A15 PAL_LINE(GPIOA, 15)
#    define B10 PAL_LINE(GPIOB, 10)
#    define B11 PAL_LINE(GPIOB, 11)
#    define B12 PAL_LINE(GPIOB, 12)
#    define C13 PAL_LINE(GPIOC, 13)
#    define C14 PAL_LINE(GPIOC, 14)
#    define C15 PAL_LINE(GPIOC, 15)
#endif

#define ENABLE_COMPILE_KEYCODE

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

/* --- PRINTF_BYTE_TO_BINARY macro's --- */
#define PRINTF_BINARY_PATTERN_INT8 "%c%c%c%c%c%c%c%c"
#define PRINTF_BYTE_TO_BINARY_INT8(i) (((i)&0x80ll) ? '1' : '0'), (((i)&0x40ll) ? '1' : '0'), (((i)&0x20ll) ? '1' : '0'), (((i)&0x10ll) ? '1' : '0'), (((i)&0x08ll) ? '1' : '0'), (((i)&0x04ll) ? '1' : '0'), (((i)&0x02ll) ? '1' : '0'), (((i)&0x01ll) ? '1' : '0')

#define PRINTF_BINARY_PATTERN_INT16 PRINTF_BINARY_PATTERN_INT8 " " PRINTF_BINARY_PATTERN_INT8
#define PRINTF_BYTE_TO_BINARY_INT16(i) PRINTF_BYTE_TO_BINARY_INT8((i) >> 8), PRINTF_BYTE_TO_BINARY_INT8(i)
#define PRINTF_BINARY_PATTERN_INT32 PRINTF_BINARY_PATTERN_INT16 " " PRINTF_BINARY_PATTERN_INT16
#define PRINTF_BYTE_TO_BINARY_INT32(i) PRINTF_BYTE_TO_BINARY_INT16((i) >> 16), PRINTF_BYTE_TO_BINARY_INT16(i)
#define PRINTF_BINARY_PATTERN_INT64 PRINTF_BINARY_PATTERN_INT32 " " PRINTF_BINARY_PATTERN_INT32
#define PRINTF_BYTE_TO_BINARY_INT64(i) PRINTF_BYTE_TO_BINARY_INT32((i) >> 32), PRINTF_BYTE_TO_BINARY_INT32(i)
/* --- end macros --- */

#ifndef EECONFIG_USER_DATA_SIZE
#    define EECONFIG_USER_DATA_SIZE 8
#endif


// Use custom magic number so that when switching branches, EEPROM always gets reset
#define EECONFIG_MAGIC_NUMBER (uint16_t)0x1339

/* Set Polling rate to 1000Hz */
#define USB_POLLING_INTERVAL_MS 1

// Quick reset for Splinky board
// #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
// #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 250U

#if defined(SPLIT_KEYBOAD)
#    define SPLIT_MODS_ENABLE
#endif

#define MACRO_TIMER 5

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_SLEEP
#    if defined(__AVR__) && !defined(__AVR_AT90USB1286__)
#        undef RGBLIGHT_ANIMATIONS
#        define RGBLIGHT_EFFECT_BREATHING
#        define RGBLIGHT_EFFECT_KNIGHT
#        define RGBLIGHT_EFFECT_STATIC_GRADIENT

// #        define RGBLIGHT_EFFECT_TWINKLE
#    else
#        define RGBLIGHT_ANIMATIONS
#    endif
#endif  // RGBLIGHT_ENABLE

#ifdef RGB_MATRIX_ENABLE
// #   define RGB_MATRIX_KEYPRESSES // reacts to keypresses
// #   define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
// #   define RGB_DISABLE_AFTER_TIMEOUT 0 // number of ticks to wait until disabling effects
// #   define RGB_DISABLE_WHEN_USB_SUSPENDED true // turn off effects when suspended
// #   define RGB_MATRIX_FRAMEBUFFER_EFFECTS
// #   define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
#   define RGB_MATRIX_LED_FLUSH_LIMIT 200 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
// #   define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
#   define RGB_MATRIX_HUE_STEP 8
#   define RGB_MATRIX_SAT_STEP 8
#   define RGB_MATRIX_VAL_STEP 8
#   define RGB_MATRIX_SPD_STEP 10

#    define RGB_MATRIX_DISABLE_KEYCODES
#    undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
// #    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 110
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
#    ifndef RGB_DISABLE_WHEN_USB_SUSPENDED
#        define RGB_DISABLE_WHEN_USB_SUSPENDED true
#    endif
#   define DISABLE_RGB_MATRIX_ALPHAS_MODS						// Static dual hue, speed is hue for secondary hue
#   define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN					// Static gradient top to bottom, speed controls how much gradient changes
#   define DISABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT   			// Static gradient left to right, speed controls how much gradient changes
#   define DISABLE_RGB_MATRIX_BREATHING							// Single hue brightness cycling animation
#   define DISABLE_RGB_MATRIX_BAND_SAT							// Single hue band fading saturation scrolling left to right
#   define DISABLE_RGB_MATRIX_BAND_VAL							// Single hue band fading brightness scrolling left to right
#   define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT					// Single hue 3 blade spinning pinwheel fades saturation
#   define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL					// Single hue 3 blade spinning pinwheel fades brightness
#   define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT					// Single hue spinning spiral fades saturation
#   define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL					// Single hue spinning spiral fades brightness
#   define DISABLE_RGB_MATRIX_CYCLE_ALL							// Full keyboard solid hue cycling through full gradient
#   define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT					// Full gradient scrolling left to right
#   define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN						// Full gradient scrolling top to bottom
#   define DISABLE_RGB_MATRIX_CYCLE_OUT_IN						// Full gradient scrolling out to in
#   define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL					// Full dual gradients scrolling out to in
#   define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON			// Full gradent Chevron shapped scrolling left to right
#   define DISABLE_RGB_MATRIX_DUAL_BEACON						// Full gradient spinning around center of keyboard
#   define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL					// Full gradient spinning pinwheel around center of keyboard
#   define DISABLE_RGB_MATRIX_CYCLE_SPIRAL						// Full gradient spinning spiral around center of keyboard
#   define DISABLE_RGB_MATRIX_RAINBOW_BEACON					// Full tighter gradient spinning around center of keyboard
#   define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS					// Full dual gradients spinning two halfs of keyboard
#   define DISABLE_RGB_MATRIX_HUE_BREATHING
#   define DISABLE_RGB_MATRIX_HUE_PENDULUM
#   define DISABLE_RGB_MATRIX_HUE_WAVE
#   define ENABLE_RGB_MATRIX_RAINDROPS
#   define DISABLE_RGB_MATRIX_PIXEL_FRACTAL
#   define DISABLE_RGB_MATRIX_PIXEL_RAIN
// #   define DISABLE_RGB_MATRIX_RAINDROPS						// Randomly changes a single key's hue
#   define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS				// Randomly changes a single key's hue and saturation
#   define DISABLE_RGB_MATRIX_TYPING_HEATMAP					// How hot is your WPM!
#   define DISABLE_RGB_MATRIX_DIGITAL_RAIN						// That famous computer simulation
#   define DISABLE_RGB_MATRIX_SOLID_REACTIVE 					// Static single hue, pulses keys hit to shifted hue then fades to current hue
#   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE				// Pulses keys hit to hue & value then fades value out
#   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE				// Hue & value pulse near a single key hit then fades value out
#   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE			// Hue & value pulse near multiple key hits then fades value out
#   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS				// Hue & value pulse the same column and row of a single key hit then fades value out
#   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS			// Hue & value pulse the same column and row of multiple key hits then fades value out
#   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS				// Hue & value pulse away on the same column and row of a single key hit then fades value out
#   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS			// Hue & value pulse away on the same column and row of multiple key hits then fades value out
#   define DISABLE_RGB_MATRIX_SPLASH							// Full gradient & value pulse away from a single key hit then fades value out
#   define DISABLE_RGB_MATRIX_MULTISPLASH						// Full gradient & value pulse away from multiple key hits then fades value out
#   define DISABLE_RGB_MATRIX_SOLID_SPLASH						// Hue & value pulse away from a single key hit then fades value out
#   define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH
#   define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_RAINDROPS // Sets the default mode, if none has been set
#   define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_RAINDROPS
#   define RGB_MATRIX_STARTUP_HUE 96 // Sets the default hue value, if none has been set
#    undef RGB_MATRIX_DEFAULT_HUE					// Hue & value pulse away from multiple key hits then fades value out
#   define RGB_MATRIX_DEFAULT_HUE 96
#   define RGB_MATRIX_STARTUP_SAT 255 // Sets the default saturation value, if none has been set
#   define RGB_MATRIX_DEFAULT_SAT 255
#   define RGB_MATRIX_STARTUP_SPD 1
#   define RGB_MATRIX_DEFAULT_SPD 1
#   define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS // Sets the default brightness value, if none has been set
#   define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
#   define RGB_MATRIX_STARTUP_HSV RGB_MATRIX_STARTUP_HUE, RGB_MATRIX_STARTUP_SAT, RGB_MATRIX_STARTUP_VAL
// #    define RGB_MATRIX_KEYPRESSES
#    define SPLIT_TRANSPORT_MIRROR

#endif


#ifndef ONESHOT_TAP_TOGGLE
#    define ONESHOT_TAP_TOGGLE 2
#endif  // !ONESHOT_TAP_TOGGLE_

#ifndef ONESHOT_TIMEOUT
#    define ONESHOT_TIMEOUT 3000
#endif  // !ONESHOT_TIMEOUT

#ifdef QMK_KEYS_PER_SCAN
#    undef QMK_KEYS_PER_SCAN
#    define QMK_KEYS_PER_SCAN 2
#endif  // !QMK_KEYS_PER_SCAN

// this makes it possible to do rolling combos (zx) with keys that
// convert to other keys on hold (z becomes ctrl when you hold it,
// and when this option isn't enabled, z rapidly followed by x
// actually sends Ctrl-x. That's bad.)
// #define IGNORE_MOD_TAP_INTERRUPT
#undef PERMISSIVE_HOLD
//#define TAPPING_FORCE_HOLD
//#define RETRO_TAPPING
#define TAPPING_TERM_PER_KEY


#define FORCE_NKRO

#ifndef TAPPING_TOGGLE
#    define TAPPING_TOGGLE 1
#endif

#ifdef TAPPING_TERM
#    undef TAPPING_TERM
#endif  // TAPPING_TERM;
#define TAPPING_TERM 175

#undef TAP_CODE_DELAY
#define TAP_CODE_DELAY 5

/* Disable unused and unneeded features to reduce on firmware size */
#ifdef LOCKING_SUPPORT_ENABLE
#    undef LOCKING_SUPPORT_ENABLE
#endif
#ifdef LOCKING_RESYNC_ENABLE
#    undef LOCKING_RESYNC_ENABLE
#endif



