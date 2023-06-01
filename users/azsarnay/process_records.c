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
// #include "version.h"

uint16_t copy_paste_timer;

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

__attribute__((weak)) bool process_record_secrets(uint16_t keycode, keyrecord_t *record) { return true; }



int RGB_current_mode;

#ifdef RGBLIGHT_ENABLE
// Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif


// Defines actions tor my global custom keycodes. Defined in drashna.h file
// Then runs the _keymap's record handier if not processed here
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGBRST:
       #ifdef RGBLIGHT_ENABLE
         if (record->event.pressed) {
           eeconfig_update_rgblight_default();
           rgblight_enable();
           RGB_current_mode = rgblight_config.mode;
         }
       #endif
       #ifdef RGB_MATRIX_ENABLE
         if (record->event.pressed) {
           eeconfig_update_rgb_matrix_default();
           rgb_matrix_enable();
         }
       #endif
       break;
       case JOIN:  // Destiny /join
            if (record->event.pressed) {
                send_string("/join ");
            }
            break;
        case KEY_SWITCHER1:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_RCTL) SS_TAP(X_RCTL) "1" SS_TAP(X_ENT));
            }
            break;
        case KEY_SWITCHER2:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_RCTL) SS_TAP(X_RCTL) "2" SS_TAP(X_ENT));
            }
            break;
        case KEY_SWITCHER3:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_RCTL) SS_TAP(X_RCTL) "3" SS_TAP(X_ENT));
            }
            break;
        case KEY_SWITCHER4:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_RCTL) SS_TAP(X_RCTL) "4" SS_TAP(X_ENT));
            }
            break;

        case KC_CCCV:  // One key copy/paste
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {  // Hold, copy
                    tap_code16(LCTL(KC_C));
                } else {  // Tap, paste
                    tap_code16(LCTL(KC_V));
                }
            }
            break;
#ifdef UNICODE_ENABLE
        case UC_FLIP:  // (ノಠ痊ಠ)ノ彡┻━┻
            if (record->event.pressed) {
                send_unicode_string("(ノಠ益ಠ)ノ彡┻━┻");
            }
            break;
        case UC_TABL:  // ┬─┬ノ( º _ ºノ)
            if (record->event.pressed) {
                send_unicode_string("┬─┬ノ( º _ ºノ)");
            }
            break;
        case UC_SHRG:  // ¯\_(ツ)_/¯
            if (record->event.pressed) {
                send_unicode_string("¯\\_(ツ)_/¯");
            }
            break;
        case UC_DISA:  // ಠ_ಠ
            if (record->event.pressed) {
                send_unicode_string("ಠ_ಠ");
            }
            break;
#endif

#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
        case RGB_TOG:
            // Split keyboards need to trigger on key-up for edge-case issue
#    ifndef SPLIT_KEYBOARD
            if (record->event.pressed) {
#    else
            if (!record->event.pressed) {
#    endif
#    if defined(RGBLIGHT_ENABLE) && !defined(RGBLIGHT_DISABLE_KEYCODES)
                rgblight_toggle();
#    endif
#    if defined(RGB_MATRIX_ENABLE) && !defined(RGB_MATRIX_DISABLE_KEYCODES)
                rgb_matrix_toggle();
#    endif
            }
            return false;
            break;
        case RGB_MODE_FORWARD ... RGB_MODE_GRADIENT:  // quantum_keycodes.h L400 for definitions
            if (record->event.pressed) {
                bool is_eeprom_updated;
#    if defined(RGBLIGHT_ENABLE) && !defined(RGBLIGHT_DISABLE_KEYCODES)
                // This disables layer indication, as it's assumed that if you're changing this ... you want that disabled
                if (userspace_config.rgb_layer_change) {
                    userspace_config.rgb_layer_change = false;
                    dprintf("rgblight layer change [EEPROM]: %u\n", userspace_config.rgb_layer_change);
                    is_eeprom_updated = true;
                }
#    endif
#    if defined(RGB_MATRIX_ENABLE) && defined(RGB_MATRIX_FRAMEBUFFER_EFFECTS)
                if (userspace_config.rgb_matrix_idle_anim) {
                    userspace_config.rgb_matrix_idle_anim = false;
                    dprintf("RGB Matrix Idle Animation [EEPROM]: %u\n", userspace_config.rgb_matrix_idle_anim);
                    is_eeprom_updated = true;
                }
#    endif
                if (is_eeprom_updated) {
                    eeconfig_update_user(userspace_config.raw);
                }
            }
#endif
    }
    return process_record_secrets(keycode, record);
    // return true;
}

#ifdef OS_DETECTION_ENABLE
#    include "os_detection.h"
#endif

#ifdef OS_DETECTION_ENABLE
os_variant_t os_type;

uint32_t startup_exec(uint32_t trigger_time, void *cb_arg) {
    /* do something */

    if (is_keyboard_master()) {
        os_type = detected_host_os();
        if (os_type) {
            bool is_mac                  = (os_type == OS_MACOS) || (os_type == OS_IOS);
            keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = is_mac;
#    ifdef UNICODE_COMMON_ENABLE
            uint8_t mode = is_mac ? UNICODE_MODE_MACOS : UNICODE_MODE_WINCOMPOSE;
            if (mode != get_unicode_input_mode()) {
                set_unicode_input_mode(mode);
            }
#    endif
            switch (os_type) {
                case OS_UNSURE:
                    xprintf("unknown OS Detected\n");
                    break;
                case OS_LINUX:
                    xprintf("Linux Detected\n");
                    break;
                case OS_WINDOWS:
                    xprintf("Windows Detected\n");
                    break;
#    if 0
                case OS_WINDOWS_UNSURE:
                    xprintf("Windows? Detected\n");
                    break;
#    endif
                case OS_MACOS:
                    xprintf("MacOS Detected\n");
                    break;
                case OS_IOS:
                    xprintf("iOS Detected\n");
                    break;
#    if 0
                case OS_PS5:
                    xprintf("PlayStation 5 Detected\n");
                    break;
                case OS_HANDHELD:
                    xprintf("Nintend Switch/Quest 2 Detected\n");
                    break;
#    endif
            }
        }
    }

    return os_type ? 0 : 500;
}
#endif