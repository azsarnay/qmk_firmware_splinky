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
#include QMK_KEYBOARD_H

#include "keyrecords/wrappers.h"
#include "keyrecords/process_records.h"
#include "callbacks.h"
// #include "eeconfig_users.h"


#if defined(RGB_MATRIX_ENABLE)
#    include "rgb/rgb_matrix_stuff.h"
#endif
// #ifdef SPLIT_KEYBOARD
// #    include "split/transport_sync.h"
// #endif
#ifdef POINTING_DEVICE_ENABLE
#    include "pointing/pointing.h"
#endif
#ifdef OS_DETECTION_ENABLE
#    include "os_detection.h"
#endif
#ifdef UNICODE_COMMON_ENABLE
#    include "keyrecords/unicode.h"
#endif


/* Define layer names */
enum userspace_layers {
    _COLEMAK  = 0,
    _GAME,
    _GAMEL2,
    _GAMEL3,
    _MMO,
    _MMOL2,
    _NAVNUM,
    _SYM,
    _MCRO,
    _BROWSER,
    _POINTER,
    _MOUSEP,
    _QWERTY,
};

// #define _MOUSE _MACROS

bool          mod_key_press_timer(uint16_t code, uint16_t mod_code, bool pressed);
bool          mod_key_press(uint16_t code, uint16_t mod_code, bool pressed, uint16_t this_timer);
// void          matrix_init_keymap(void);
// void          matrix_init_secret(void);
// void          shutdown_keymap(void);
// void          suspend_power_down_keymap(void);
// void          suspend_wakeup_init_keymap(void);
void          matrix_scan_keymap(void);
void          matrix_scan_secret(void);
layer_state_t layer_state_set_keymap(layer_state_t state);
layer_state_t default_layer_state_set_keymap(layer_state_t state);
void          led_set_keymap(uint8_t usb_led);
// void          eeconfig_init_keymap(void);
bool          hasAllBitsInMask(uint8_t value, uint8_t mask);

// clang-format off
typedef union {
    uint32_t raw;
    struct {
        bool     rgb_layer_change     :1;
        bool     is_overwatch         :1;
        bool     nuke_switch          :1;
        bool     swapped_numbers      :1;
        bool     rgb_matrix_idle_anim :1;
        bool     mouse_jiggler        :1;
        uint8_t  align_reserved       :2;
        uint8_t  oled_brightness      :8;
        uint32_t reserved             :15;
        bool     check                :1;
    };
} userspace_config_t;
// clang-format on


// _Static_assert(sizeof(userspace_config_t) == sizeof(uint32_t), "Userspace EECONFIG out of spec.");

extern userspace_config_t userspace_config;

void        set_keyboard_lock(bool enable);
bool        get_keyboard_lock(void);
void        toggle_keyboard_lock(void);
const char* get_layer_name_string(layer_state_t state, bool alt_name);

