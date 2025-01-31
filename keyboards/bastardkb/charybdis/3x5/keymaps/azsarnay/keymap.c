
/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
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
#include QMK_KEYBOARD_H

#define LAYOUT_charybdis_3x5_wrapper(...) LAYOUT_charybdis_3x5(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT_charybdis_3x5_wrapper(
  //,--------------------------------------------.                    ,--------------------------------------------.
      ______________COLEMAK_MOD_DH_L1_HRMod______,                     ______________COLEMAK_MOD_DH_R1_HRMod______,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      ______________COLEMAK_MOD_DH_L2____________,                     ________COLEMAK_MOD_DH_R2_CHARYBDIS________,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      ______________COLEMAK_MOD_DH_L3____________,                     ______________COLEMAK_MOD_DH_R3____________,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
               _____________BASE_LEFT_THUMB_______________,   _____________BASE_RIGHT_THUMB_CHARYBDIS____
                             //`--------------------------'  `--------------------------'

  ),

    [_GAME] = LAYOUT_charybdis_3x5_wrapper(
  //,--------------------------------------------.                    ,--------------------------------------------.
      ___________________GAME_L1_________________,                      ___________________GAME_R1_________________,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      ___________________GAME_L2_________________,                      ___________________GAME_R2_________________,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      ___________________GAME_L3_________________,                      ___________________GAME_R3_________________,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
              ___________________GAME_LT_________________,    ___________________GAME_RT_________________
                            //`--------------------------'   `--------------------------'
),

  [_GAMEL2] = LAYOUT_charybdis_3x5_wrapper(
  //,--------------------------------------------.                    ,--------------------------------------------.
      ___________________GAMEL2_L1_______________,                      ___________________GAMEL2_R1_______________,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      ___________________GAMEL2_L2_______________,                      ___________________GAMEL2_R2_______________,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      ___________________GAMEL2_L3_______________,                      ___________________GAMEL2_R3_______________,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
              ___________________GAMEL2_LT_______________,    ___________________GAMEL2_RT_______________
                            //`--------------------------'   `--------------------------'
),


 [_MMO] = LAYOUT_charybdis_3x5_wrapper(
  //,--------------------------------------------.                    ,--------------------------------------------.
      ___________________MMO_L1__________________,                      ___________________MMO_R1__________________,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      ___________________MMO_L2__________________,                      ___________________MMO_R2__________________,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      ___________________MMO_L3__________________,                      ___________________MMO_R3__________________,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
              ___________________MMO_LT__________________,    ___________________MMO_RT__________________
                            //`--------------------------'   `--------------------------'
),

  [_MMOL2] = LAYOUT_charybdis_3x5_wrapper(
  //,--------------------------------------------.                    ,--------------------------------------------.
      ___________________MMOL2_L1________________,                      ___________________MMOL2_R1________________,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      ___________________MMOL2_L2________________,                      ___________________MMOL2_R2________________,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      ___________________MMOL2_L3________________,                      ___________________MMOL2_R3________________,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
               ___________________MMOL2_LT________________,    ___________________MMOL2_RT________________
                            //`--------------------------'   `--------------------------'
),

  [_NAVNUM] = LAYOUT_charybdis_3x5_wrapper(
  //,--------------------------------------------.                    ,--------------------------------------------.
      _________________NAVNUM_L1_________________,                      _________________NAVNUM_R1_________________,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _________________NAVNUM_L2_________________,                      _________________NAVNUM_R2_________________,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _________________NAVNUM_L3_________________,                      _________________NAVNUM_R3_________________,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                _________________NAVNUM_LT_________________,     _________________NAVNUM_RT_CHARYBDIS_______
                            //`--------------------------'   `--------------------------'
),

  [_SYM] = LAYOUT_charybdis_3x5_wrapper(
  //,--------------------------------------------.                    ,--------------------------------------------.
      _________________SYM_L1____________________,                      _________________SYM_R1____________________,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _________________SYM_L2____________________,                      _________________SYM_R2____________________,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _________________SYM_L3____________________,                      _________________SYM_R3____________________,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                _________________SYM_LT____________________,      _________________SYM_RT____________________
                            //`--------------------------'   `--------------------------'
),

  [_BROWSER] = LAYOUT_charybdis_3x5_wrapper(
  //,--------------------------------------------.                    ,--------------------------------------------.
      _________________BROWSER_L1________________,                      _________________ADJUST_R1_________________,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _________________BROWSER_L2________________,                      _________________ADJUST_R2_________________,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _________________BROWSER_L3________________,                      _________________ADJUST_R3_________________,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                _________________BROWSER_LT________________,      _________________BROWSER_RT________________
                            //`--------------------------'   `--------------------------'
),


  [_MCRO] = LAYOUT_charybdis_3x5_wrapper(
  //,--------------------------------------------.                    ,--------------------------------------------.
      _________________MCRO_L1___________________,                      _________________MCRO_R1___________________,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _________________MCRO_L2___________________,                      _________________MCRO_R2___________________,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _________________MCRO_L3___________________,                      _________________MCRO_R3___________________,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                _________________MCRO_LT___________________,      _________________MCRO_RT___________________
                            //`--------------------------'   `--------------------------'
),

  [_POINTER] = LAYOUT_charybdis_3x5_wrapper(
  //,--------------------------------------------.                    ,--------------------------------------------.
      _________________POINTER_L1________________,                      _________________POINTER_R1________________,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _________________POINTER_L2________________,                      _________________POINTER_R2________________,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _________________POINTER_L3________________,                      _________________POINTER_R3________________,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                _________________POINTER_LT________________,     _________________POINTER_RT________________
                            //`--------------------------'   `--------------------------'
),


//   [_TEMPLATE] = LAYOUT_split_3x5_3(
//   //,--------------------------------------------.                    ,--------------------------------------------.
//       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
//       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
//       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
//                                 XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
//                             //`--------------------------'   `--------------------------'
// ),


};



#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
#        endif  // RGB_MATRIX_ENABLE
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_kb(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode_noeeprom(RGB_MATRIX_STARTUP_MODE);
#        endif  // RGB_MATRIX_ENABLE
    }
    matrix_scan_user();
}
#    endif  // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_kb(layer_state_t state) {
    state = layer_state_set_user(state);
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif  // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif      // POINTING_DEVICE_ENABLE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_POINTER, KC_E):
            return TAPPING_TERM + 300;
        case LT(_MMOL2,KC_SPC):
            return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }
}



