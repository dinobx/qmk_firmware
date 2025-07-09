// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM test_combo1[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM test_combo2[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM test_combo3[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM test_combo4[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM test_combo5[] = {RALT_T(KC_COMM), RCTL_T(KC_DOT), COMBO_END};
const uint16_t PROGMEM test_combo6[] = {KC_VOLD, KC_VOLU, COMBO_END};
const uint16_t PROGMEM test_combo7[] = {KC_MPRV, KC_MNXT, COMBO_END};

combo_t key_combos[] = {
    COMBO(test_combo1, KC_ESC),
    COMBO(test_combo2, KC_TAB),
    COMBO(test_combo3, KC_BSPC),
    COMBO(test_combo4, KC_ENT),
    COMBO(test_combo5, KC_DEL),
    COMBO(test_combo6, KC_MUTE),
    COMBO(test_combo7, KC_MPLY)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_31(    //base layer qwerty
        KC_Q,           KC_W,              KC_E,           KC_R,           KC_T,    KC_Y,    KC_U,    KC_I,                KC_O,               KC_P,
        LT(1,KC_A),     KC_S,              KC_D,           KC_F,           KC_G,    KC_H,    KC_J,    KC_K,                KC_L,               LT(3,KC_SCLN),
        LSFT_T(KC_Z),   LCTL_T(KC_X),      LALT_T(KC_C),   LGUI_T(KC_V),   KC_B,    KC_N,    KC_M,    RALT_T(KC_COMM),     RCTL_T(KC_DOT),     RSFT_T(KC_SLSH),
        LT(2,KC_SPACE)
    ),
    [1] = LAYOUT_31(    //nav layer
        KC_TRNS,    KC_VOLD,    KC_VOLU,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_HOME,    KC_UP,      KC_END,     KC_TRNS,
        KC_TRNS,    KC_MPRV,    KC_MNXT,    KC_TRNS,    KC_TRNS,    KC_PGUP,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_TRNS,
        KC_LSFT,    KC_LCTL,    KC_LALT,    KC_LGUI,    KC_TRNS,    KC_PGDN,    KC_TRNS,    KC_RALT,    KC_RCTL,    KC_RSFT,
        KC_TRNS
    ),
    [2] = LAYOUT_31(    //symbols layer
        KC_TRNS,    KC_7,       KC_8,    KC_9,    KC_EQL,     KC_PSLS,    KC_TRNS,    S(KC_9),     S(KC_0),    KC_TRNS,
        KC_0,       KC_4,       KC_5,    KC_6,    KC_MINS,    KC_PAST,    KC_QUOT,    S(KC_LBRC),  S(KC_RBRC), KC_TRNS,
        KC_LSFT,    KC_1,       KC_2,    KC_3,    KC_PDOT,    KC_TRNS,    KC_NUBS,    KC_LBRC,     KC_RBRC,    KC_LSFT,
        KC_TRNS
    ),
    [3] = LAYOUT_31(    //function layer
        KC_TRNS,    KC_F7,    KC_F8,    KC_F9,    KC_F12,    KC_TRNS,    KC_BTN1,    KC_MS_U,    KC_BTN2,    KC_TRNS,
        KC_TRNS,    KC_F4,    KC_F5,    KC_F6,    KC_F11,    KC_WH_U,    KC_MS_L,    KC_MS_D,    KC_MS_R,    KC_TRNS,
        KC_LSFT,    KC_F1,    KC_F2,    KC_F3,    KC_F10,    KC_WH_D,    KC_TRNS,    KC_RALT,    KC_RCTL,    KC_RSFT,
        KC_TRNS
    )
};