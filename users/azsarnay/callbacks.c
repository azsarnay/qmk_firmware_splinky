// Copyright 2021 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "azsarnay.h"

#ifdef CUSTOM_DYNAMIC_MACROS_ENABLE
#    include "keyrecords/dynamic_macros.h"
#endif

__attribute__((weak)) void keyboard_post_init_keymap(void) {}
void                       keyboard_post_init_user(void) {
// #if defined(CUSTOM_RGBLIGHT)
//     keyboard_post_init_rgb_light();
// #endif
#if defined(CUSTOM_RGB_MATRIX)
    keyboard_post_init_rgb_matrix();
#endif

#ifdef CUSTOM_UNICODE_ENABLE
    keyboard_post_init_unicode();
#endif
    keyboard_post_init_keymap();
}

#ifdef RGB_MATRIX_ENABLE
void rgb_matrix_update_pwm_buffers(void);
#endif

__attribute__((weak)) void shutdown_keymap(void) {}
void                       shutdown_user(void) {
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_set_color_all(rgb_matrix_get_val(), 0x00, 0x00);
    rgb_matrix_update_pwm_buffers();
#endif // RGB_MATRIX_ENABLE


    shutdown_keymap();
}


__attribute__((weak)) void suspend_wakeup_init_keymap(void) {}
void                       suspend_wakeup_init_user(void) {
    suspend_wakeup_init_keymap();
}

// No global matrix scan code, so just run keymap's matrix
// scan function
__attribute__((weak)) void matrix_scan_keymap(void) {}
void                       matrix_scan_user(void) {
    matrix_scan_keymap();
}

// on layer change, no matter where the change was initiated
// Then runs keymap's layer change check
__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) {
    return state;
}
layer_state_t layer_state_set_user(layer_state_t state) {
    state = layer_state_set_keymap(state);

#ifdef CONSOLE_ENABLE
    char layer_buffer[16 + 5];
    format_layer_bitmap_string(layer_buffer, state, default_layer_state);
    dprintf("layer state: %s\n", layer_buffer);
#endif

    return state;
}


__attribute__((weak)) void led_set_keymap(uint8_t usb_led) {}
void                       led_set_user(uint8_t usb_led) {
    led_set_keymap(usb_led);
}



__attribute__((weak)) void housekeeping_task_keymap(void) {}
void                       housekeeping_task_user(void) {
    static bool has_ran_yet;
    if (!has_ran_yet) {
        has_ran_yet = true;
        startup_user();
    }

    housekeeping_task_keymap();
}
