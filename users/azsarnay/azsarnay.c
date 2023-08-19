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