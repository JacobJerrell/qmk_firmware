#include "bocaj_swift.h"

__attribute__ ((weak))
void matrix_scan_secrets(void) {}

void tap(uint16_t keycode) { register_code(keycode); unregister_code(keycode); };

uint16_t layer_switch_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    uint8_t layer = get_highest_layer(layer_state);
    uint8_t modifiers = get_mods();

    // For semi-advanced macros that need a little more control
    switch (keycode) {
        case MC_LSWP:
            if (modifiers & MODS_SHIFT_MASK) {
                layer_move(0);
                return false;
            }
            if (record->event.pressed) {
                layer_switch_timer = timer_read();
                switch (layer) {
                    case 0:
                        layer_move(_RAISE);
                        break;
                    case _RAISE:
                        layer_move(_MOUSE);
                        break;
                    case _MOUSE:
                        layer_move(_LOWER);
                        break;
                    case _LOWER:
                        layer_move(0);
                        return false;
                }
            } else {
                if (timer_elapsed(layer_switch_timer) > TAPPING_TERM) {
                    layer_move(layer - 1);
                    return false;
                }
            }
            return false;
    }

    // Basic Macros
    if (record->event.pressed) {
        switch (keycode) {
            case KC_EPRM:
                eeconfig_init();
                return false;
            case KC_VRSN:
                SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
            case MC_WRKM:
                set_single_persistent_default_layer(_WORKMAN);
                layer_move(0);
                ergodox_blink_all_leds();
                return false;
            case MC_ARRW:
                SEND_STRING("->");
                return false;
        }
    } else {
        switch (keycode) {
            case MC_LOCK:
                layer_move(0);
                SEND_STRING(SS_LCTRL(SS_LGUI("q")));
                return true;
        }
    }
    return true;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
    static bool has_ran_yet;
    uint8_t layer = biton32(layer_state);
    uint8_t modifiers = get_mods();

    if (!has_ran_yet) {
        has_ran_yet = true;
        startup_user();
    }

    if (layer == _WORKMAN) {
        if (modifiers & MODS_SHIFT_MASK) {
            ergodox_right_led_1_on();
            ergodox_right_led_1_set( 25 );
        } else {
            ergodox_right_led_1_off();
        }
        if (modifiers & MODS_CTRL_MASK || modifiers & MODS_GUI_MASK) {
            if ((modifiers & MODS_CTRL_MASK) && (modifiers & MODS_GUI_MASK)) {
                ergodox_right_led_2_on();
                ergodox_right_led_2_set( 50 );
            } else {
                ergodox_right_led_2_on();
                ergodox_right_led_2_set( 10 );
            }
        } else {
            ergodox_right_led_2_off();
        }
        if (modifiers & MODS_ALT_MASK) {
            ergodox_right_led_3_on();
            ergodox_right_led_3_set( 10 );
        } else {
            ergodox_right_led_3_off();
        }
    }


    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        // Website Refresh / XCode "Run"
        SEQ_ONE_KEY(KC_R) {
            SEND_STRING(SS_LGUI("r"));
        }

        // Mac copy line down (Leader -> d, d)
        SEQ_TWO_KEYS(KC_D, KC_D) {
            register_code(KC_LSHIFT);
            register_code(KC_HOME);
            unregister_code(KC_HOME);
            unregister_code(KC_LSHIFT);
            SEND_STRING(SS_LGUI("c"));
            tap(KC_END);
            tap(KC_ENTER);
            SEND_STRING(SS_LGUI("v"));
        }

        SEQ_TWO_KEYS(KC_B, KC_D) {
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION " Built at: " QMK_BUILDDATE);
        }
        #ifndef NO_SECRETS
        matrix_scan_secrets();
        #endif // !NO_SECRETS
    }
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case _RAISE:
            ergodox_right_led_1_on();
            break;
        case _MOUSE:
            ergodox_right_led_2_on();
            break;
        case _LOWER:
            ergodox_right_led_3_on();
            break;
        case _ADJUST:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
          break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }

    ergodox_right_led_1_set(25);
    ergodox_right_led_2_set(25);
    ergodox_right_led_3_set(25);

    return state;
};
