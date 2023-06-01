/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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

#pragma once
// #define MASTER_RIGHT
// #define EE_HANDS
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_MUSIC_MODE
#undef  NO_ACTION_MACRO // May fix macro issue?? -didnt
#undef  NO_ACTION_FUNCTION // May fix macro issue?? -didnt
#define LAYER_STATE_16BIT // limit layers to 16
#define BILATERAL_COMBINATIONS 250
#ifndef TAPPING_TERM
#define CHARYBDIS_DRAGSCROLL_REVERSE_X
// #define ROTATIONAL_TRANSFORM_ANGLE -30
// #undef POINTING_DEVICE_INVERT_X
/**
 * \brief Configure the global tapping term (default: 200ms).
 *
 * If you have a lot of accidental mod activations, crank up the tapping term.
 *
 * See docs.qmk.fm/using-qmk/software-features/tap_hold#tapping-term
 */
#    define TAPPING_TERM 200
#endif  // TAPPING_TERM

//#define UNICODE_SELECTED_MODES UC_WINC

#define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE, UNICODE_MODE_MACOS

// RGB matrix support
#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_DISABLE_KEYCODES
#    undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
#    define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
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
#   define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH					// Hue & value pulse away from multiple key hits then fades value out
#   define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_RAINDROPS // Sets the default mode, if none has been set
#   define RGB_MATRIX_STARTUP_HUE 96 // Sets the default hue value, if none has been set
#   define RGB_MATRIX_STARTUP_SAT 255 // Sets the default saturation value, if none has been set
#   define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS // Sets the default brightness value, if none has been set
#   define RGB_MATRIX_STARTUP_HSV RGB_MATRIX_STARTUP_HUE, RGB_MATRIX_STARTUP_SAT, RGB_MATRIX_STARTUP_VAL
// #   define RGB_MATRIX_STARTUP_SPD 10 // Sets the default animation speed, if none has been set
// #    define RGB_MATRIX_KEYPRESSES
#endif

#ifdef POINTING_DEVICE_ENABLE
// Enable pointer acceleration, which increases the speed by ~2x for large
// displacement, while maintaining 1x speed for slow movements.  See also:
// - `CHARYBDIS_POINTER_ACCELERATION_FACTOR`
#    define CHARYBDIS_POINTER_ACCELERATION_ENABLE

// Automatically enable the pointer layer when moving the trackball.  See also:
// - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS`
// - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD`
// #define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#endif  // POINTING_DEVICE_ENABLE
