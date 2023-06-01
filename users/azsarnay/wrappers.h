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
/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/
#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif

// clang-format off
// #define LAYOUT_ergodox_wrapper(...)          LAYOUT_ergodox(__VA_ARGS__)
// #define LAYOUT_ergodox_pretty_wrapper(...)   LAYOUT_ergodox_pretty(__VA_ARGS__)
// #define KEYMAP_wrapper(...)                  LAYOUT(__VA_ARGS__)
// #define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)
// #define LAYOUT_ortho_4x12_wrapper(...)       LAYOUT_ortho_4x12(__VA_ARGS__)
// #define LAYOUT_ortho_5x12_wrapper(...)       LAYOUT_ortho_5x12(__VA_ARGS__)
// #define LAYOUT_gergo_wrapper(...)            LAYOUT_gergo(__VA_ARGS__)
// #define LAYOUT_split_3x6_3_wrapper(...)      LAYOUT_split_3x6_3(__VA_ARGS__)
// #define LAYOUT_split_3x5_3_wrapper(...)      LAYOUT_split_3x5_3(__VA_ARGS__)

/*
Blocks for each of the four major keyboard layouts
Organized so we can quickly adapt and modify all of them
at once, rather than for each keyboard, one at a time.
And this allows for much cleaner blocks in the keymaps.
For instance Tap/Hold for Control on all of the layouts

NOTE: These are all the same length.  If you do a search/replace
  then you need to add/remove underscores to keep the
  lengths consistent.
*/

#define _________________EMPTY_____________________       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

#define ______________COLEMAK_MOD_DH_L1____________       KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define ______________COLEMAK_MOD_DH_L2____________       KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define ______________COLEMAK_MOD_DH_L3____________       KC_Z,    KC_X,    KC_C,    KC_D,    KC_V
#define ________COLEMAK_MOD_DH_L2_CHARYBDIS________       LT(_POINTER, KC_A),    KC_R,    KC_S,    KC_T,    KC_G

#define ______________COLEMAK_MOD_DH_L1_HRMod______       KC_Q,    LALT_T(KC_W),LSFT_T(KC_F),RCTL_T(KC_P),    CMD_T(KC_B)
#define ______________COLEMAK_MOD_DH_L2_HRMod______       KC_A,    LALT_T(KC_R),LSFT_T(KC_S),RCTL_T(KC_T),    KC_G

#define ______________COLEMAK_MOD_DH_R1____________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define ______________COLEMAK_MOD_DH_R2____________       KC_M,    KC_N,    KC_E,    KC_I,    KC_O
#define ______________COLEMAK_MOD_DH_R3____________       KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLASH
#define ________COLEMAK_MOD_DH_R2_CHARYBDIS________       KC_M,    KC_N,    LT(_POINTER, KC_E), KC_I, KC_O

#define ______________COLEMAK_MOD_DH_R1_HRMod______       KC_J,    RCTL_T(KC_L),LSFT_T(KC_U),LALT_T(KC_Y),    KC_SCLN
#define ______________COLEMAK_MOD_DH_R2_HRMod______       KC_M,    RCTL_T(KC_N),LSFT_T(KC_E),LALT_T(KC_I),    KC_O

#define _____________BASE_LEFT_THUMB_______________		   LT(_BROWSER,KC_ESC),LT(_NAVNUM,KC_SPC), RCTL_T(KC_TAB)
// #define _____________BASE_RIGHT_THUMB______________		   LT(_SYM,KC_ENT),LSFT_T(KC_DEL),  LT(_MCRO,KC_BSPC)
#define _____________BASE_RIGHT_THUMB______________      LT(_SYM,KC_ENT),LSFT_T(KC_DEL),  LT(_TOG,KC_BSPC)
#define _____________BASE_RIGHT_THUMB_CHARYBDIS____		   LT(_SYM,KC_ENT),LSFT_T(KC_BSPC)


#define _________________NAVNUM_L1_________________        KC_BSPC, KC_CPY,    KC_UP,   KC_PST,   KC_CUT
#define _________________NAVNUM_L2_________________        KC_DEL,  KC_LEFT,   KC_DOWN, KC_RIGHT, KC_SPC
#define _________________NAVNUM_L3_________________        KC_BOTTM,KC_PSTHIST,KC_CMNT, KC_UNDO,  KC_REDO
#define _________________NAVNUM_LT_________________        XXXXXXX,    XXXXXXX,    XXXXXXX,

#define _________________NAVNUM_R1_________________        KC_LSFT, LGUI_T(KC_7),  KC_8, KC_9, KC_SLASH
#define _________________NAVNUM_R2_________________        KC_MINS, KC_4,  KC_5, KC_6, KC_PLUS 
#define _________________NAVNUM_R3_________________        KC_RCTL, KC_1,  KC_2, KC_3, KC_DOT
#define _________________NAVNUM_RT_________________        LALT_T(KC_EQL), SYM, LGUI_T(KC_0)
#define _________________NAVNUM_RT_CHARYBDIS_______        LALT_T(KC_EQL), KC_0

#define _________________ADJUST_L1_________________       RGB_TOG,  RGBRST,  XXXXXXX,  XXXXXXX, XXXXXXX
#define _________________ADJUST_L2_________________       RGB_MOD,  RGB_HUI, RGB_SAI, RGB_VAI,  RGB_SPI
#define _________________ADJUST_L3_________________       RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD,  RGB_SPD

#define _________________ADJUST_R1_________________       KC_F12, KC_F7,  KC_F8,  KC_F9,  KEY_SWITCHER1
#define _________________ADJUST_R2_________________       KC_F11, KC_F4,  KC_F5,  KC_F6,  KEY_SWITCHER2
#define _________________ADJUST_R3_________________       KC_F10, KC_F1,  KC_F2,  KC_F3,  KEY_SWITCHER3


#define _________________SYM_L1____________________       KC_PERC,   KC_AMPR,  KC_CIRC,  KC_LCBR,  KC_LBRC
#define _________________SYM_L2____________________       KC_AT,     KC_DLR,   KC_HASH,  KC_LPRN,  KC_PLUS
#define _________________SYM_L3____________________       KC_GRV,    KC_ASTR,  KC_TILD,  KC_LT,    KC_EQL
#define _________________SYM_LT____________________       KC_LGUI,   NAVNUM,   KC_LSFT

#define _________________SYM_R1____________________       KC_RBRC,  KC_RCBR, KC_QUES,  KC_EXLM,  KC_BSLS
#define _________________SYM_R2____________________       KC_MINS,  KC_RPRN, KC_COMM,  KC_DOT,   XXXXXXX
#define _________________SYM_R3____________________       KC_UNDS,  KC_GT,   KC_DQUO,  KC_QUOT,  KC_PIPE
#define _________________SYM_RT____________________       XXXXXXX,    XXXXXXX

#define __________________TOG_L1___________________       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
#define __________________TOG_L2___________________       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
#define __________________TOG_L3___________________       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
#define __________________TOG_R1___________________       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
#define __________________TOG_R2___________________       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
#define __________________TOG_R3___________________       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX

#define _________________MCRO_L1___________________       KC_CAPS,  XXXXXXX,   XXXXXXX,  KEY_SWITCHER1,  RGB_SPI
#define _________________MCRO_L2___________________       XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,        RGB_SPD
#define _________________MCRO_L3___________________       MMO,      GAME,      XXXXXXX,  KEY_SWITCHER1,  KEY_SWITCHER2
#define _________________MCRO_LT___________________       XXXXXXX,  XXXXXXX,   XXXXXXX


#define _________________MCRO_R1___________________       KC_SEC10,  XXXXXXX,   KC_SEC6,  KC_SEC4,   KC_SEC1
#define _________________MCRO_R2___________________       UC_FLIP,  UC_SHRG,    KC_SEC7,  KC_SEC5,   KC_SEC2
#define _________________MCRO_R3___________________       KC_PIC,   KC_MACPIC,  KC_SEC9,  KC_SEC8,   KC_SEC3
#define _________________MCRO_RT___________________       XXXXXXX,  XXXXXXX

#define _________________BROWSER_L1________________       MAC_WIN_LEFT, MAC_WIN_RIGHT,    TAB_NEW,     TAB_REOP,      MAC_EXPOSE
#define _________________BROWSER_L2________________       KC_F1,        TAB_BCK,          TAB_CLS,     TAB_FWD,       KC_F2
#define _________________BROWSER_L3________________       KC_ESC,       KC_DOT,           MACTAB_CLS,  MAC_TAB_BCK,   MAC_TAB_FWD
#define _________________BROWSER_LT________________       XXXXXXX,   XXXXXXX,   XXXXXXX

#define _________________BROWSER_R1________________       KC_WH_U,  KC_BTN1,  KC_MS_U,  KC_BTN2,  XXXXXXX
#define _________________BROWSER_R2________________       KC_WH_L,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_WH_R
#define _________________BROWSER_R3________________       KC_WH_D,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
#define _________________BROWSER_RT________________       KC_LSFT,  KC_BTN1

#define _________________POINTER_L1________________        KC_BSPC, KC_CPY,  KC_SPC, KC_PST,  KC_LCTL
#define _________________POINTER_L2________________        KC_DEL,  SNIPING, DRGSCRL, KC_LCTL, KC_LSFT
#define _________________POINTER_L3________________        XXXXXXX, XXXXXXX, XXXXXXX, KC_LGUI, KC_LALT
#define _________________POINTER_LT________________        KC_BTN2, KC_BTN1, KC_BTN3

#define _________________POINTER_R1________________        DPI_MOD, TAB_BCK, XXXXXXX, TAB_FWD, TAB_REOP
#define _________________POINTER_R2________________        DPI_RMOD, KC_BTN1, XXXXXXX, KC_BTN2, KC_BTN3
#define _________________POINTER_R3________________        S_D_RMOD, S_D_MOD, XXXXXXX, DRGSCRL, TAB_CLS
#define _________________POINTER_RT________________        XXXXXXX, MOUSE

#define __________________MOUSE_L1_________________        KC_BSPC, KC_CPY,  XXXXXXX, KC_PST,  KC_LCTL
#define __________________MOUSE_L2_________________        KC_DEL,  SNIPING, DRGSCRL, KC_LCTL, KC_LSFT
#define __________________MOUSE_L3_________________        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT
#define __________________MOUSE_LT_________________        KC_BTN2, KC_BTN1, KC_BTN3

#define __________________MOUSE_R1_________________        DPI_MOD, TAB_BCK, TAB_NEW, TAB_FWD, TAB_REOP
#define __________________MOUSE_R2_________________        DPI_RMOD, KC_BTN1, KC_BTN2, DRGSCRL, SNIPING
#define __________________MOUSE_R3_________________        S_D_RMOD, S_D_MOD, TAB_CLS, KC_BTN3, XXXXXXX
#define __________________MOUSE_RT_________________        XXXXXXX, COLEMAK


#define ___________________MMO_L1__________________        KC_1, KC_2,  KC_W,  KC_3,    KC_4
#define ___________________MMO_L2__________________        KC_5, KC_A,  KC_S,  KC_D,    KC_6
#define ___________________MMO_L3__________________        KC_7, KC_8,  KC_9,  KC_0,    KC_EQL
#define ___________________MMO_LT__________________        LSFT_T(KC_N), KC_SPC, LALT_T(KC_C)

#define ___________________MMO_R1__________________        KC_X, KC_P,     KC_I,  KC_O,   KC_TAB
#define ___________________MMO_R2__________________        KC_Y, KC_BTN1,  KC_BTN2,  DRGSCRL,    KC_B
#define ___________________MMO_R3__________________        KC_Z, KC_A,     KC_BTN3,     KC_D,      KC_LBRC
#define ___________________MMO_RT__________________        LCTL_T(KC_E), LT(_MMOL2,KC_ESC)


#define ___________________MMOL2_L1________________        KC_F1, KC_F2,   KC_W,    KC_F3,    KC_F4
#define ___________________MMOL2_L2________________        KC_F5, KC_A,    KC_S,    KC_D,     KC_F6
#define ___________________MMOL2_L3________________        KC_F7, KC_F8,   KC_F9,   KC_F10,   KC_F11
#define ___________________MMOL2_LT________________        XXXXXXX, XXXXXXX, COLEMAK

#define ___________________MMOL2_R1________________        KC_L, KC_F,      KC_UP,    KC_G,     DPI_MOD
#define ___________________MMOL2_R2________________        KC_M, KC_LEFT,   KC_DOWN,  KC_RIGHT, DPI_RMOD
#define ___________________MMOL2_R3________________        KC_Q, KC_H,      KC_J,     KC_K,     KC_V
#define ___________________MMOL2_RT________________        COLEMAK, KC_ENT


#define ___________________GAME_L1_________________        KC_TAB,        KC_B,  KC_W,  KC_R,    KC_T
#define ___________________GAME_L2_________________        KC_ESC,        KC_A,  KC_S,  KC_D,    KC_E
#define ___________________GAME_L3_________________        LALT_T(KC_ENT), KC_1,  KC_2,  KC_LSFT, KC_F
#define ___________________GAME_LT_________________        KC_C, KC_SPC, KC_RCTL

#define ___________________GAME_R1_________________        KC_H, KC_M,     KC_F7,   KC_G,  DRGSCRL    
#define ___________________GAME_R2_________________        KC_K, KC_BTN1,  KC_BTN2, KC_Q,  KC_F6
#define ___________________GAME_R3_________________        KC_P, KC_N,     KC_F10,  KC_F9,    LT(_GAMEL2,KC_ENT)
#define ___________________GAME_RT_________________        KC_Q, LT(_GAMEL2,KC_ESC)


#define ___________________GAMEL2_L1_______________        KC_X, KC_V,     KC_UP,    KC_F2,      KC_F3
#define ___________________GAMEL2_L2_______________        KC_Y, KC_LEFT,  KC_DOWN,  KC_RIGHT,   KC_F4
#define ___________________GAMEL2_L3_______________        KC_Z, KC_PIC,   KC_I,     KC_J,       KC_F5
#define ___________________GAMEL2_LT_______________        XXXXXXX, COLEMAK, COLEMAK

#define ___________________GAMEL2_R1_______________        XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX    
#define ___________________GAMEL2_R2_______________        XXXXXXX, KC_BTN1,  KC_BTN2, DRGSCRL,  JOIN
#define ___________________GAMEL2_R3_______________        XXXXXXX, XXXXXXX,  KC_PIC,  XXXXXXX,  KC_ENT
#define ___________________GAMEL2_RT_______________        COLEMAK, COLEMAK


// clang-format on
