/*
Copyright 2020 Jacob Jerrell <jacob.jerrell@gmail.com> @JacobJerrell

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "bocaj_swift.h"

/// Adds an initial layer of abstraction by persisting tap/hold keys and thumb cluster
#define LAYOUT_ergodox_bocaj_base_wrapper(...)       LAYOUT_ergodox_bocaj_base(__VA_ARGS__)

/** Further abstracts the layer creation process by persisting edge keys that I've seldom found reason to change */
#define LAYOUT_ergodox_bocaj_condensed_wrapper(...)     LAYOUT_ergodox_bocaj_condensed(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_WORKMAN] = LAYOUT_ergodox_bocaj_condensed_wrapper(
        _______________________HOME_TOP_LHS________________________,     _______________________HOME_TOP_RHS________________________,
                _______________WORKMAN_LHS_1_______________,                     _______________WORKMAN_RHS_1_______________,
                _______________WORKMAN_LHS_2_______________,                     _______________WORKMAN_RHS_2_______________,
                _______________WORKMAN_LHS_3_______________,                     _______________WORKMAN_RHS_3_______________,
                        KC_LWR, KC_MSE, KC_UP, KC_LEFT,                                 KC_RIGHT, KC_DOWN, KC_NO, KC_NO
    ),

    [_RAISE] = LAYOUT_ergodox_bocaj_condensed_wrapper(
        ________________________7_TRNS_KEYS________________________,     ________________________7_TRNS_KEYS________________________,
                _______, _______, KC_UP,   _______,  _______,                    _______,  KC_7,  KC_8,    KC_9,   KC_PAST,
                _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______,                    _______,  KC_4,  KC_5,    KC_6,   KC_PPLS,
                ________________5_TRNS_KEYS________________,                     _______,  KC_1,  KC_2,    KC_3,   KC_PMNS,
                    _______, _______, _______, _______,                                    KC_0,  KC_PDOT, KC_COMM,KC_PEQL
    ),

    // Wrapping Mouse-Wheel Keys with `X_T()` style functions seems
    // to break the mouse button. So we can't use the wrapper here.
    [_MOUSE] = LAYOUT_ergodox_pretty_wrapper(
         ________________________7_TRNS_KEYS________________________,         ________________________7_TRNS_KEYS________________________,
      _______,_______,_______,KC_MS_WH_DOWN,_______, _______,_______,         ________________________7_TRNS_KEYS________________________,
      _______,_______,KC_MS_WH_LEFT,KC_MS_WH_UP,KC_MS_WH_RIGHT,_______,               ____________________6_TRNS_KEYS____________________,
      _______,_______,KC_ACL0, KC_ACL1, KC_ACL2, _______, _______,            ________________________7_TRNS_KEYS________________________,
           ________________5_TRNS_KEYS________________,                                   ________________5_TRNS_KEYS________________,
                                            ____________________TRANS_THUMB_CLUSTER____________________
    ),

    [_LOWER] = LAYOUT_ergodox_bocaj_base_wrapper(
        _______________________LOWER_TOP_LHS_______________________,         _______________________LOWER_TOP_RHS_______________________,
        _______,________________SYMBOLS_LHS________________,_______,         _______,________________SYMBOLS_RHS________________,_______,
        _______,________________NUMBERS_LHS________________,                         ________________NUMBERS_RHS________________,_______,
        _______,_______, KC_MRWD, KC_MPLY, KC_MFFD, _______,_______,         ________________________7_TRNS_KEYS________________________,
          ________________5_TRNS_KEYS________________,                                      ________________5_TRNS_KEYS________________
    ),

    [_ADJUST] = LAYOUT_ergodox_pretty_wrapper(
        ____________________6_TRNS_KEYS____________________, KC_RST,        KC_EPRM,____________________6_TRNS_KEYS____________________,
        _______, _______,KC_MRWD,KC_MPLY, KC_MFFD, _______, _______,        ________________________7_TRNS_KEYS________________________,
        _______, KC__MUTE, KC__VOLDOWN, KC__VOLUP, MC_LOCK, _______,                ____________________6_TRNS_KEYS____________________,
        ________________________7_TRNS_KEYS________________________,        ________________________7_TRNS_KEYS________________________,
          ________________5_TRNS_KEYS________________,                                    ________________5_TRNS_KEYS________________,
                                          ____________________TRANS_THUMB_CLUSTER____________________
    )
};
