
/*
Copyright 2020 Jacob Jerrell @JacobJerrell

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

#pragma once
#include QMK_KEYBOARD_H

#include "version.h"
#include "eeprom.h"
#include "wrappers.h"

enum keymap_layers {
    _WORKMAN = 0,
    //_QWERTY,
    _RAISE,
    _MOUSE,
    _LOWER,
    _ADJUST
};

enum custom_keycodes {
    KC_EPRM = SAFE_RANGE,
    KC_VRSN,
    RGB_SLD,
    MC_ARRW,
    MC_WRKM,
    MC_QWRT,
    MC_LOCK,
    MC_LSWP
};

// Layout beauti-/simpli-fication

#define KC_LWEN LT(_LOWER, KC_ENTER)
#define KC_ADJS TT(_ADJUST)
#define KC_RSE TT(_RAISE)
#define KC_LWR TT(_LOWER)
#define KC_MSE TT(_MOUSE)
#define KC_HME TO(_WORKMAN)
//#define KC_GAME TT(_DIABLO)

// Other Keycodes
#define KC_RST RESET

#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define MODS_CTRL_MASK  (MOD_BIT(KC_LCTL)|MOD_BIT(KC_RCTRL))
#define MODS_ALT_MASK  (MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))
#define MODS_GUI_MASK  (MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI))

void tap(uint16_t keycode);
