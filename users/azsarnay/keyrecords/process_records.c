// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "azsarnay.h"
#include "version.h"
#ifdef OS_DETECTION_ENABLE
#    include "os_detection.h"
#endif
#ifdef CUSTOM_DYNAMIC_MACROS_ENABLE
#    include "keyrecords/dynamic_macros.h"
#endif

uint16_t copy_paste_timer;
// Defines actions for my global custom keycodes. Defined in azsarnay.h file
// Then runs the _keymap's record handier if not processed here

/**
 * @brief Keycode handler for keymaps
 *
 * This handles the keycodes at the keymap level, useful for keyboard specific customization
 */
__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}
__attribute__((weak)) bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
    return true;
}

/**
 * @brief Main user keycode handler
 *
 * This handles all of the keycodes for the user, including calling feature handlers.
 *
 * @param keycode Keycode from matrix
 * @param record keyrecord_t data structure
 * @return true Continue processing keycode and send to host
 * @return false Stop process keycode and do not send to host
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#if defined(OLED_ENABLE) && defined(CUSTOM_OLED_DRIVER)
    process_record_user_oled(keycode, record);
#endif // OLED

    if (!(process_record_keymap(keycode, record) && process_record_secrets(keycode, record)
#ifdef CUSTOM_RGB_MATRIX
          && process_record_user_rgb_matrix(keycode, record)
#endif
#ifdef CUSTOM_RGBLIGHT
          && process_record_user_rgb_light(keycode, record)
#endif
#ifdef CUSTOM_UNICODE_ENABLE
          && process_record_unicode(keycode, record)
#endif
#if defined(CUSTOM_POINTING_DEVICE)
          && process_record_pointing(keycode, record)
#endif
          && true)) {
        return false;
    }

    switch (keycode) {
        case JOIN:  // Destiny /join
            if (record->event.pressed) {
                send_string("/join ");
            }
            break;
    }
    return true;
}