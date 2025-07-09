// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM combo_esc[] = {KC_TAB, KC_Q, COMBO_END};
const uint16_t PROGMEM combo_enter[] = {KC_K, KC_L, COMBO_END};

const uint16_t PROGMEM combo_capsword[] = {KC_LSFT, RSFT_T(KC_SLSH), COMBO_END};


combo_t key_combos[] = {
    COMBO(combo_esc, KC_ESC),
    COMBO(combo_enter, KC_ENT),

    COMBO(combo_capsword, CW_TOGG)
};

enum unicode_names {
    AE_uC,
    AE_lC,
    OE_uC,
    OE_lC,
    UE_uC,
    UE_lC,
    SS,
    EURO,
    DEG
};

const uint32_t PROGMEM unicode_map[] = {
    [AE_uC]  = 0x00C4,
    [AE_lC] = 0x00E4,
    [OE_uC]  = 0x00D6,
    [OE_lC] = 0x00F6,
    [UE_uC]  = 0x00DC,
    [UE_lC] = 0x00FC,
    [SS] = 0x00DF,
    [EURO] = 0x20AC,
    [DEG] = 0x00B0
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( //base
        KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,                           KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_NO,
        MO(3),   KC_A, KC_S, KC_D, KC_F, KC_G,                           KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_NO, //ISO Enter Position
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,                  KC_MPLY, KC_N, KC_M, KC_COMM, KC_DOT, RSFT_T(KC_SLSH),
        KC_LCTL, KC_LGUI, KC_LALT, LT(2,KC_SPACE), LT(2,KC_SPACE), /*2.25Space Position*/  LT(1,KC_BSPC), KC_NO, KC_NO, KC_RCTL
    ),
    [1] = LAYOUT( //function keys
        KC_TRNS, KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F12,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_F4, KC_F5, KC_F6, KC_F11,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_MAKE, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F10,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,                  KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS
    ),
    [2] = LAYOUT( //numpad and symbols
        KC_TRNS, KC_Q,    KC_7, KC_8, KC_9, KC_EQL,                      UP(AE_lC,AE_uC), KC_GRV,  S(KC_9),    S(KC_0),    UM(EURO), KC_TRNS,
        KC_TRNS, KC_0,    KC_4, KC_5, KC_6, KC_MINS,                     UP(OE_lC,OE_uC), KC_QUOT, S(KC_LBRC), S(KC_RBRC), UM(SS),   KC_TRNS,
        KC_TRNS, KC_PSLS, KC_1, KC_2, KC_3, KC_PDOT,            KC_TRNS, UP(UE_lC,UE_uC), KC_NUBS, KC_LBRC,    KC_RBRC,    UM(DEG),
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS,                                 KC_TRNS, KC_TRNS
    ),
    [3] = LAYOUT( //navigation
        KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_NUM,                 KC_INS,  KC_HOME,    KC_UP,   KC_END,      KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_MPLY, KC_TRNS,                KC_PGUP, KC_LEFT,    KC_DOWN, KC_RIGHT,    KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_F13,  KC_F14,  KC_F15,  KC_TRNS,       KC_TRNS, KC_PGDN, C(KC_LEFT), KC_TRNS, C(KC_RIGHT), KC_TRNS,
        KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_DEL,                  KC_ENT,  KC_TRNS,                          KC_TRNS, KC_TRNS
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [1] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [2] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [3] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}
};
#endif

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(1,KC_BSPC): // Baselayer Right Spacebar, (Backspace)
            return 100;
        default:
            return QUICK_TAP_TERM; // quick tap term is disabled by default
    }
}