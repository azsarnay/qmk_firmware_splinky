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

#include "azsarnay.h"
#include <stdio.h>
#include <ctype.h>

userspace_config_t userspace_config;

bool mod_key_press_timer(uint16_t code, uint16_t mod_code, bool pressed) {
    static uint16_t this_timer;
    if (pressed) {
        this_timer = timer_read();
    } else {
        if (timer_elapsed(this_timer) < TAPPING_TERM) {
            tap_code(code);
        } else {
            register_code(mod_code);
            tap_code(code);
            unregister_code(mod_code);
        }
    }
    return false;
}

bool mod_key_press(uint16_t code, uint16_t mod_code, bool pressed, uint16_t this_timer) {
    if (pressed) {
        this_timer = timer_read();
    } else {
        if (timer_elapsed(this_timer) < TAPPING_TERM) {
            tap_code(code);
        } else {
            register_code(mod_code);
            tap_code(code);
            unregister_code(mod_code);
        }
    }
    return false;
}

// __attribute__((weak)) void keyboard_pre_init_keymap(void) {}

// void keyboard_pre_init_user(void) {
//     userspace_config.raw = eeconfig_read_user();
//     keyboard_pre_init_keymap();
// }
// Add reconfigurable functions here, for keymap customization
// This allows for a global, userspace functions, and continued
// customization of the keymap.  Use _keymap instead of _user
// functions in the keymaps
__attribute__((weak)) void matrix_init_keymap(void) {}
__attribute__((weak)) void matrix_init_secret(void) {}

// Call user matrix init, set default RGB colors and then
// call the keymap's init function
void matrix_init_user(void) {
#if defined(BOOTLOADER_CATERINA) && defined(__AVR__)
    DDRD &= ~(1 << 5);
    PORTD &= ~(1 << 5);

    DDRB &= ~(1 << 0);
    PORTB &= ~(1 << 0);
#endif

    matrix_init_secret();
    matrix_init_keymap();
}

// __attribute__((weak)) void keyboard_post_init_keymap(void) {}

// void keyboard_post_init_user(void) {
// #if defined(RGBLIGHT_ENABLE)
//     keyboard_post_init_rgb_light();
// #endif
// #if defined(RGB_MATRIX_ENABLE)
//     keyboard_post_init_rgb_matrix();
// #endif
//     keyboard_post_init_keymap();
// }

// __attribute__((weak)) void shutdown_keymap(void) {}

// #ifdef RGB_MATRIX_ENABLE
// void rgb_matrix_update_pwm_buffers(void);
// #endif

// void shutdown_user(void) {
// #ifdef RGBLIGHT_ENABLE
//     rgblight_enable_noeeprom();
//     rgblight_mode_noeeprom(1);
//     rgblight_setrgb_red();
// #endif  // RGBLIGHT_ENABLE
// #ifdef RGB_MATRIX_ENABLE
//     // rgb_matrix_set_color_all(0xFF, 0x00, 0x00);
//     rgb_matrix_update_pwm_buffers();

// #endif  // RGB_MATRIX_ENABLE
//     shutdown_keymap();
// }

// __attribute__((weak)) void suspend_power_down_keymap(void) {}

// void suspend_power_down_user(void) {
// #ifdef OLED_DRIVER_ENABLE
//     oled_off();
// #endif
//     suspend_power_down_keymap();
// }

// __attribute__((weak)) void suspend_wakeup_init_keymap(void) {}

// void suspend_wakeup_init_user(void) { suspend_wakeup_init_keymap(); }

// __attribute__((weak)) void matrix_scan_keymap(void) {}

// __attribute__((weak)) void matrix_scan_secret(void) {}

// // No global matrix scan code, so just run keymap's matrix
// // scan function
// void matrix_scan_user(void) {
//     static bool has_ran_yet;
//     if (!has_ran_yet) {
//         has_ran_yet = true;
//         startup_user();
//     }

// #ifdef TAP_DANCE_ENABLE  // Run Diablo 3 macro checking code.
//     run_diablo_macro_check();
// #endif  // TAP_DANCE_ENABLE

// #if defined(RGBLIGHT_ENABLE)
//     matrix_scan_rgb_light();
// #endif  // RGBLIGHT_ENABLE
// // #if defined(RGB_MATRIX_ENABLE)
// //     matrix_scan_rgb_matrix();
// // #endif

//     matrix_scan_secret();

//     matrix_scan_keymap();
// }

// #ifdef AUDIO_ENABLE
// float doom_song[][2] = SONG(E1M1_DOOM);
// #endif

// __attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) { return state; }

// // on layer change, no matter where the change was initiated
// // Then runs keymap's layer change check
// layer_state_t layer_state_set_user(layer_state_t state) {
//     if (!is_keyboard_master()) {
//         return state;
//     }

//     // state = update_tri_layer_state(state, _NAVNUM, _SYM, _ADJUST);
// #if defined(RGBLIGHT_ENABLE)
//     state = layer_state_set_rgb_light(state);
// #endif  // RGBLIGHT_ENABLE
// // #if defined(AUDIO_ENABLE) && !defined(__arm__)
// //     static bool is_gamepad_on = false;
// //     if (layer_state_cmp(state, _GAMEPAD) != is_gamepad_on) {
// //         is_gamepad_on = layer_state_cmp(state, _GAMEPAD);
// //         if (is_gamepad_on) {
// //             PLAY_LOOP(doom_song);
// //         } else {
// //             stop_all_notes();
// //         }
// //     }
// // #endif
//     return layer_state_set_keymap(state);
// }

// __attribute__((weak)) layer_state_t default_layer_state_set_keymap(layer_state_t state) { return state; }

// // Runs state check and changes underglow color and animation
// layer_state_t default_layer_state_set_user(layer_state_t state) {
//     if (!is_keyboard_master()) {
//         return state;
//     }

//     state = default_layer_state_set_keymap(state);
// #if 0
// #    if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
//   state = default_layer_state_set_rgb(state);
// #    endif  // RGBLIGHT_ENABLE
// #endif
//     return state;
// }




/**
 * @brief Performs exact match for modifier values
 *
 * @param value the modifer varible (get_mods/get_oneshot_mods/get_weak_mods)
 * @param mask the modifier mask to check for
 * @return true Has the exact modifiers specifed
 * @return false Does not have the exact modifiers specified
 */
bool hasAllBitsInMask(uint8_t value, uint8_t mask) {
    value &= 0xF;
    mask &= 0xF;

    return (value & mask) == mask;
}

/**
 * @brief Tap keycode, with no mods
 *
 * @param kc keycode to use
 */
void tap_code16_nomods(uint16_t kc) {
    uint8_t temp_mod = get_mods();
    clear_mods();
    clear_oneshot_mods();
    tap_code16(kc);
    set_mods(temp_mod);
}

#ifdef I2C_SCANNER_ENABLE
#    include "i2c_master.h"
#    include "debug.h"

#    ifndef I2C_SCANNER_TIMEOUT
#        define I2C_SCANNER_TIMEOUT 50
#    endif

i2c_status_t i2c_start_bodge(uint8_t address, uint16_t timeout) {
    i2c_start(address);

    // except on ChibiOS where the only way is do do "something"
    uint8_t data = 0;
    return i2c_readReg(address, 0, &data, sizeof(data), I2C_SCANNER_TIMEOUT);
}

#    define i2c_start i2c_start_bodge

void do_scan(void) {
    uint8_t nDevices = 0;

    dprintf("Scanning...\n");

    for (uint8_t address = 1; address < 127; address++) {
        // The i2c_scanner uses the return value of
        // i2c_start to see if a device did acknowledge to the address.
        i2c_status_t error = i2c_start(address << 1, I2C_SCANNER_TIMEOUT);
        if (error == I2C_STATUS_SUCCESS) {
            i2c_stop();
            xprintf("  I2C device found at address 0x%02X\n", I2C_SCANNER_TIMEOUT);
            nDevices++;
        } else {
            // dprintf("  Unknown error (%u) at address 0x%02X\n", error, address);
        }
    }

    if (nDevices == 0)
        xprintf("No I2C devices found\n");
    else
        xprintf("done\n");
}

uint16_t scan_timer = 0;

// void housekeeping_task_i2c_scanner(void) {
//     if (timer_elapsed(scan_timer) > 5000) {
//         do_scan();
//         scan_timer = timer_read();
//     }
// }

void keyboard_post_init_i2c(void) {
    i2c_init();
    scan_timer = timer_read();
}
#endif

#if defined(AUTOCORRECT_ENABLE)
#    if defined(AUDIO_ENABLE)
#        ifdef USER_SONG_LIST
float autocorrect_song[][2] = SONG(MARIO_GAMEOVER);
#        else
float autocorrect_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
#        endif
#    endif

bool apply_autocorrect(uint8_t backspaces, const char *str) {
    // if (layer_state_is(_GAMEPAD)) {
    //     return false;
    // }
    // TO-DO use unicode stuff for this.  Will probably have to reverse engineer
    // send string to get working properly, to send char string.

#    if defined(AUDIO_ENABLE)
    PLAY_SONG(autocorrect_song);
#    endif
    return true;
}
#endif

#if defined(CAPS_WORD_ENABLE)
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_MINS:
            if (!keymap_config.swap_lctl_lgui) {
                return true;
            }
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}

#    if !defined(NO_ACTION_ONESHOT)
void oneshot_locked_mods_changed_user(uint8_t mods) {
    if (mods & MOD_MASK_SHIFT) {
        del_mods(MOD_MASK_SHIFT);
        set_oneshot_locked_mods(~MOD_MASK_SHIFT & get_oneshot_locked_mods());
        caps_word_on();
    }
}
#    endif
#endif

void format_layer_bitmap_string(char *buffer, layer_state_t state, layer_state_t default_state) {
    for (int i = 0; i < 16; i++) {
        if (i == 0 || i == 4 || i == 8 || i == 12) {
            *buffer = ' ';
            ++buffer;
        }

        uint8_t layer = i;
        if ((default_state & ((layer_state_t)1 << layer)) != 0) {
            *buffer = 'D';
        } else if ((state & ((layer_state_t)1 << layer)) != 0) {
            *buffer = '1';
        } else {
            *buffer = '_';
        }
        ++buffer;
    }
    *buffer = 0;
}

// #if defined(OS_DETECTION_ENABLE) && defined(DEFERRED_EXEC_ENABLE)
// os_variant_t os_type;

// uint32_t startup_exec(uint32_t trigger_time, void *cb_arg) {
//     if (is_keyboard_master()) {
//         os_type = detected_host_os();
//         if (os_type) {
//             bool is_mac = (os_type == OS_MACOS) || (os_type == OS_IOS);
//             if (keymap_config.swap_lctl_lgui != is_mac) {
//                 keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = is_mac;
//                 eeconfig_update_keymap(keymap_config.raw);
//             }
// #    ifdef UNICODE_COMMON_ENABLE
//             set_unicode_input_mode_soft(keymap_config.swap_lctl_lgui ? UNICODE_MODE_MACOS : UNICODE_MODE_WINCOMPOSE);
// #    endif
//             switch (os_type) {
//                 case OS_UNSURE:
//                     xprintf("unknown OS Detected\n");
//                     break;
//                 case OS_LINUX:
//                     xprintf("Linux Detected\n");
//                     break;
//                 case OS_WINDOWS:
//                     xprintf("Windows Detected\n");
//                     break;
// #    if 0
//                 case OS_WINDOWS_UNSURE:
//                     xprintf("Windows? Detected\n");
//                     break;
// #    endif
//                 case OS_MACOS:
//                     xprintf("MacOS Detected\n");
//                     break;
//                 case OS_IOS:
//                     xprintf("iOS Detected\n");
//                     break;
// #    if 0
//                 case OS_PS5:
//                     xprintf("PlayStation 5 Detected\n");
//                     break;
//                 case OS_HANDHELD:
//                     xprintf("Nintend Switch/Quest 2 Detected\n");
//                     break;
// #    endif
//             }
//         }
//     }

//     return os_type ? 0 : 500;
// }
// #endif

static host_driver_t *host_driver          = 0;
static bool           host_driver_disabled = false;

void set_keyboard_lock(bool status) {
    if (!status && !host_get_driver()) {
        host_set_driver(host_driver);
    } else if (status && host_get_driver()) {
        host_driver = host_get_driver();
        clear_keyboard();
        host_set_driver(0);
    } else if (status) {
        clear_keyboard();
    }

    host_driver_disabled = status;
}

void toggle_keyboard_lock(void) {
    set_keyboard_lock(!host_driver_disabled);
}

bool get_keyboard_lock(void) {
    return host_driver_disabled;
}