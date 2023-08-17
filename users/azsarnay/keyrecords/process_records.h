// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include "azsarnay.h"

enum userspace_custom_keycodes {
    VRSN = QK_USER,  // Prints QMK Firmware and board info
    KC_SECRET_1,                    // test1
    KC_SECRET_2,                    // test2
    KC_SECRET_3,                    // test3
    KC_SECRET_4,                    // test4
    KC_SECRET_5,                    // test5
    KC_SECRET_6,
    KC_SECRET_7,
    KC_SECRET_8,
    KC_SECRET_9,
    KC_SECRET_10,
    KC_CCCV,         // Hold to copy, tap to paste
    KC_NUKE,         // NUCLEAR LAUNCH DETECTED!!!
    UC_FLIP,         // (ಠ痊ಠ)┻━┻
    UC_TABL,         // ┬─┬ノ( º _ ºノ)
    UC_SHRG,         // ¯\_(ツ)_/¯
    UC_DISA,         // ಠ_ಠ
    UC_IRNY,
    UC_CLUE,
    KEYLOCK, // Locks keyboard by unmounting driver
    KC_NOMODE,
    KC_WIDE,
    KC_SCRIPT,
    KC_BLOCKS,
    KC_REGIONAL,
    KC_AUSSIE,
    KC_ZALGO,
    KC_SUPER,
    KC_COMIC,
    KC_ACCEL,
    OLED_LOCK,
    OLED_BRIGHTNESS_INC,
    OLED_BRIGHTNESS_DEC,

    STORE_SETUPS,
    PRINT_SETUPS,

    PD_JIGGLER,

    DYN_MACRO_PROG,
    DYN_MACRO_KEY00,
    DYN_MACRO_KEY01,
    DYN_MACRO_KEY02,
    DYN_MACRO_KEY03,
    DYN_MACRO_KEY04,
    DYN_MACRO_KEY05,
    DYN_MACRO_KEY06,
    DYN_MACRO_KEY07,
    DYN_MACRO_KEY08,
    DYN_MACRO_KEY09,
    DYN_MACRO_KEY10,
    DYN_MACRO_KEY11,
    DYN_MACRO_KEY12,
    DYN_MACRO_KEY13,
    DYN_MACRO_KEY14,
    DYN_MACRO_KEY15,

    USER_SAFE_RANGE,

    KC_QWERTY,                      // Sets default layer to QWERTY
    KC_COLEMAK,                     // Sets default layer to COLEMAK
    KC_NUMGAME,
    GAME,
    GAMEL2,
    GAMEL3,
    MMO,
    MMOL2,
    KC_MAKE,                        // Run keyboard's customized make command
    KC_RGB_T,                       // Toggles RGB Layer Indication mode
    RGB_IDL,                        // RGB Idling animations
    RGBRST,
    NAVNUM,
    SYM,
    ADJUST,
    TOG,
    MCRO,
    BROWSER,
    POINTER,
    MOUSEP,


    JOIN,
    CMD_LAST,
};

bool process_record_secrets(uint16_t keycode, keyrecord_t *record);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
void post_process_record_keymap(uint16_t keycode, keyrecord_t *record);
#ifdef CUSTOM_UNICODE_ENABLE
bool process_record_unicode(uint16_t keycode, keyrecord_t *record);
#endif

#define NAVNUM   MO(_NAVNUM)
#define SYM   MO(_SYM)
#define ADJUST  MO(_ADJUST)
#define MCRO  MO(_MCRO)
#define TOG  MO(_TOG)
#define OS_NAV  OSL(_NAVNUM)
#define OS_SYM  OSL(_SYM)

#define KC_SEC1 KC_SECRET_1
#define KC_SEC2 KC_SECRET_2
#define KC_SEC3 KC_SECRET_3
#define KC_SEC4 KC_SECRET_4
#define KC_SEC5 KC_SECRET_5
#define KC_SEC6 KC_SECRET_6
#define KC_SEC7 KC_SECRET_7
#define KC_SEC8 KC_SECRET_8
#define KC_SEC9 KC_SECRET_9
#define KC_SEC10 KC_SECRET_10


#define KC_CPY LCTL(KC_C)
#define KC_PST LCTL(KC_V)
#define KC_PSTHIST LGUI(KC_V)
#define KC_CUT LCTL(KC_X)
#define KC_UNDO LCTL(KC_Z)
#define KC_REDO LCTL(KC_Y)
#define KC_PIC SGUI(KC_S)
#define KC_MACPIC RCS(KC_4)
#define KC_CMNT LCTL(KC_SLSH)
#define KC_BOTTM LCTL(KC_DOWN)
// #define KC_LSTCMD ESC(KC_DOT)

// Global tab forward and backward
#define TAB_FWD LCTL(KC_PGDN)
#define TAB_BCK LCTL(KC_PGUP)
#define MAC_TAB_BCK RSG(KC_TAB)
#define MAC_TAB_FWD LCMD(KC_TAB)

#define TAB_CLS LCTL(KC_W)
#define MACTAB_CLS LCMD(KC_W)
#define TAB_NEW LCTL(KC_T)
#define TAB_REOP RCS(KC_T)

#define MAC_EXPOSE LCMD(KC_UP)
#define MAC_WIN_LEFT LCMD(KC_LEFT)
#define MAC_WIN_RIGHT LCMD(KC_RIGHT)



#define ________ KC_NO

#define QWERTY  TG(_QWERTY)
#define COLEMAK DF(_COLEMAK)
#define NUMGAME DF(_NUMGAME)
#define GAME DF(_GAME)
#define MMO DF(_MMO)
#define POINTER DF(_POINTER)
#define MOUSEP DF(_MOUSEP)

#define KC_RESET RESET
#define KC_RST   KC_RESET


// #ifdef SWAP_HANDS_ENABLE
// #    define KC_C1R3 SH_T(KC_TAB)
// #elif defined(DRASHNA_LP)
// #    define KC_C1R3 TG(_GAMEPAD)
// #else // SWAP_HANDS_ENABLE
// #    define KC_C1R3 KC_TAB
// #endif // SWAP_HANDS_ENABLE


/* OSM keycodes, to keep things clean and easy to change */
#define KC_MLSF OSM(MOD_LSFT)
#define KC_MRSF OSM(MOD_RSFT)

#define OS_LGUI OSM(MOD_LGUI)
#define OS_RGUI OSM(MOD_RGUI)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_RALT OSM(MOD_RALT)
#define OS_MEH OSM(MOD_MEH)
#define OS_HYPR OSM(MOD_HYPR)

#define ALT_APP ALT_T(KC_APP)

#define MG_NKRO MAGIC_TOGGLE_NKRO

#define AUTO_CTN QK_AUTOCORRECT_TOGGLE
/*
Custom Keycodes for Diablo 3 layer
But since TD() doesn't work when tap dance is disabled
We use custom codes here, so we can substitute the right stuff
*/
#ifdef TAP_DANCE_ENABLE
#    define KC_D3_1 TD(TD_D3_1)
#    define KC_D3_2 TD(TD_D3_2)
#    define KC_D3_3 TD(TD_D3_3)
#    define KC_D3_4 TD(TD_D3_4)
#else // TAP_DANCE_ENABLE
#    define KC_D3_1 KC_1
#    define KC_D3_2 KC_2
#    define KC_D3_3 KC_3
#    define KC_D3_4 KC_4
#endif // TAP_DANCE_ENABLE

#define OL_LOCK OLED_LOCK
#define OL_BINC OLED_BRIGHTNESS_INC
#define OL_BDEC OLED_BRIGHTNESS_DEC
