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
#include "azsarnay.h"

#if defined(KEYBOARD_handwired_dactyl_manuform_5x6_right_trackball)
#    define PLACEHOLDER_SAFE_RANGE KEYMAP_SAFE_RANGE
#else
#    define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif

enum userspace_custom_keycodes {
    VRSN = PLACEHOLDER_SAFE_RANGE,  // Prints QMK Firmware and board info
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
    PIN,
    RHEL,
    AD,
    WIN,
    DRAG,
    SHRUG,
    UNLCK,
    JOIN,
    CMD_LAST,
    KEY_SWITCHER2,
    KEY_SWITCHER1,
    KEY_SWITCHER3,
    KEY_SWITCHER4,
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
    KC_CCCV,                        // Hold to copy, tap to paste
    KC_NUKE,                        // NUCLEAR LAUNCH DETECTED!!!
    UC_FLIP,                        // (ಠ痊ಠ)┻━┻
    UC_TABL,                        // ┬─┬ノ( º _ ºノ)
    UC_SHRG,                        // ¯\_(ツ)_/¯
    UC_DISA,                        // ಠ_ಠ
    NEW_SAFE_RANGE,                  // use "NEWPLACEHOLDER for keymap specific codes
};

bool process_record_secrets(uint16_t keycode, keyrecord_t *record);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);

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


#ifdef CUSTOM_UNICODE_ENABLE
void keyboard_post_init_unicode(void);
#endif