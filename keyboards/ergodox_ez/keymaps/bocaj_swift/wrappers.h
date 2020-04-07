#pragma once
#include "bocaj_swift.h"

/**
 * Layout Abstraction
 */

/** Acts as a vessel to pass keycodes to the core `LAYOUT_ergodox_pretty` layout */
#define LAYOUT_ergodox_pretty_wrapper(...) LAYOUT_ergodox_pretty(__VA_ARGS__)

/** Defines the matrix for the simplified wrapper, then maps the input into the parent wrapper */
#define LAYOUT_ergodox_bocaj_base( \
    K00, K01, K02, K03, K04, K05, K06,       K07, K08, K09, K0A, K0B, K0C, K0D, \
    K10, K11, K12, K13, K14, K15, K16,       K17, K18, K19, K1A, K1B, K1C, K1D, \
    K20, K21, K22, K23, K24, K25,                 K26, K27, K28, K29, K2A, K2B, \
    K30, K31, K32, K33, K34, K35, K36,       K37, K38, K39, K3A, K3B, K3C, K3D, \
      K40, K41, K42, K43, K44,                         K45, K46, K47, K48, K49  \
  ) \
  LAYOUT_ergodox_pretty_wrapper( \
      K00,       K01,        K02,        K03,        K04,  K05, K06,                K07,  K08,       K09,        K0A,        K0B,       K0C,  K0D, \
      K10,       K11,        K12,        K13,        K14,  K15, K16,                K17,  K18,       K19,        K1A,        K1B,       K1C,  K1D, \
      K20,       K21,  SFT_T(K22), GUI_T(K23), ALT_T(K24), K25,                           K26, ALT_T(K27), GUI_T(K28), SFT_T(K29),      K2A,  K2B, \
      K30, CTL_T(K31),       K32,        K33,        K34,  K35, ALL_T(K36),   MEH_T(K37), K38,       K39,        K3A,        K3B, CTL_T(K3C), K3D, \
      K40,       K41,        K42,        K43,        K44,                                            K45,        K46,        K47,       K48,  K49, \
                                                   KC_APP,KC_HME, /* <- LHS/RHS -> */ KC_END,KC_ESC,                                               \
                                                           KC_NO, /* <- LHS/RHS -> */ KC_TRNS,                                                     \
                                      KC_SPACE,KC_BSPACE,KC_LEAD, /* <- LHS/RHS -> */ KC_LOCK,KC_TAB,KC_LWEN                                       \
)

/** Defines the matrix for the condensed wrapper, then maps the input into the parent wrapper */
#define LAYOUT_ergodox_bocaj_condensed( \
    K00, K01, K02, K03, K04, K05, K06,       K07, K08, K09, K0A, K0B, K0C, K0D, \
         K10, K11, K12, K13, K14,                 K15, K16, K17, K18, K19,      \
         K20, K21, K22, K23, K24,                 K25, K26, K27, K28, K29,      \
         K30, K31, K32, K33, K34,                 K35, K36, K37, K38, K39,      \
         K40, K41, K42, K43,                           K44, K45, K46, K47       \
    ) \
    LAYOUT_ergodox_bocaj_base_wrapper( \
            K00, K01, K02, K03, K04, K05, K06,               K07, K08, K09, K0A, K0B, K0C, K0D,     \
         KC_DEL, K10, K11, K12, K13, K14, KC_LPRN,       KC_RPRN, K15, K16, K17, K18, K19, KC_BSLS, \
         KC_RSE, K20, K21, K22, K23, K24,                         K25, K26, K27, K28, K29, KC_QUOT, \
        KC_LSFT, K30, K31, K32, K33, K34, KC_LBRC,       KC_RBRC, K35, K36, K37, K38, K39, KC_MSE,  \
         KC_MSE, K40, K41, K42, K43,                                   K44, K45, K46, K47, KC_ADJS  \
)

/* Keymap Blocks */

// Standard Block Length: ___________________________________________________________
#define ________________QWERTY_LHS1________________ KC_Q, KC_W, KC_E, KC_R, KC_T
#define ________________QWERTY_LHS2________________ KC_A, KC_S, KC_D, KC_F, KC_G
#define ________________QWERTY_LHS3________________ KC_Z, KC_X, KC_C, KC_V, KC_B

#define ________________QWERTY_RHS1________________ KC_Y, KC_U, KC_I, KC_O, KC_P
#define ________________QWERTY_RHS2________________ KC_H, KC_J, KC_K, KC_L, KC_SCLN
#define ________________QWERTY_RHS3________________ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLASH

#define _______________WORKMAN_LHS_1_______________ KC_Q, KC_D, KC_R, KC_W, KC_B
#define _______________WORKMAN_LHS_2_______________ KC_A, KC_S, KC_H, KC_T, KC_G
#define _______________WORKMAN_LHS_3_______________ KC_Z, KC_X, KC_M, KC_C, KC_V

#define _______________WORKMAN_RHS_1_______________ KC_J, KC_F, KC_U, KC_P, KC_SCLN
#define _______________WORKMAN_RHS_2_______________ KC_Y, KC_N, KC_E, KC_O, KC_I
#define _______________WORKMAN_RHS_3_______________ KC_K, KC_L, KC_COMM, KC_DOT, KC_SLASH


#define ________________NUMBERS_LHS________________ KC_1, KC_2, KC_3, KC_4, KC_5
#define ________________NUMBERS_RHS________________ KC_6, KC_7, KC_8, KC_9, KC_0
#define ________________SYMBOLS_LHS________________ KC_EXCLAIM, KC_AT, KC_HASH, KC_DOLLAR, KC_PERCENT
#define ________________SYMBOLS_RHS________________ KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_LEFT_PAREN, KC_RIGHT_PAREN

#define _______________________HOME_TOP_LHS________________________ KC_ESC,  KC_1, KC_2, KC_3, KC_4, KC_5, MC_ARRW
#define _______________________HOME_TOP_RHS________________________ KC_MINS, KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQUAL

#define _______________________LOWER_TOP_LHS_______________________ KC_GRAVE, KC_F1, KC_F2, KC_F3,  KC_F4,  KC_F5,  KC_F6
#define _______________________LOWER_TOP_RHS_______________________ KC_F7,    KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_F13

// Transparent Blocks
#define ________________5_TRNS_KEYS________________ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define ____________________6_TRNS_KEYS____________________ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define ________________________7_TRNS_KEYS________________________ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define ____________________TRANS_THUMB_CLUSTER____________________ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
