// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM combo_ESC[] = {KC_Q, KC_W, COMBO_END};

const uint16_t PROGMEM combo_ENT[] = {KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM combo_DEL[] = {KC_COMM, KC_DOT, COMBO_END};

const uint16_t PROGMEM combo_CtrlZ[] = {LCTL_T(KC_Z), KC_X, COMBO_END};

const uint16_t PROGMEM combo_Mute[] = {KC_VOLD, KC_VOLU, COMBO_END};
const uint16_t PROGMEM combo_Play[] = {KC_MPRV, KC_MNXT, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_ESC, KC_ESC),
    COMBO(combo_ENT, KC_ENT),
    COMBO(combo_DEL, KC_DEL),

    COMBO(combo_CtrlZ, LCTL(KC_Z)),

    COMBO(combo_Mute, KC_MUTE),
    COMBO(combo_Play, KC_MPLY)
};

enum unicode_names {
    AE_uC,
    AE_lC,
    OE_uC,
    OE_lC,
    UE_uC,
    UE_lC,
    SS,
    EURO
};

const uint32_t PROGMEM unicode_map[] = {
    [AE_uC]  = 0x00C4, //Ä
    [AE_lC] = 0x00E4,  //ä
    [OE_uC]  = 0x00D6, //Ö
    [OE_lC] = 0x00F6,  //ö
    [UE_uC]  = 0x00DC, //Ü
    [UE_lC] = 0x00FC,  //ü
    [SS] = 0x00DF,     //ß
    [EURO] = 0x20AC    //€
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( //base Colemak DHm
        KC_TAB,       KC_W, KC_F, KC_P,       KC_B,                       KC_J, KC_L,    KC_U,    KC_Y,   KC_SCLN,
        LSFT_T(KC_A), KC_R, KC_S, LT(3,KC_T), KC_G,                       KC_M, KC_N,    KC_E,    KC_I,   RSFT_T(KC_O),
        LCTL_T(KC_Z), KC_X, KC_C, KC_D,       KC_V,                       KC_K, KC_H,    KC_COMM, KC_DOT, RCTL_T(KC_SLSH),
                      KC_LALT,                LT(2,KC_SPACE),             LT(1,KC_BSPC), KC_RGUI
    ),
    [1] = LAYOUT( //function keys and mouse
        KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F12,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_MAKE,
        KC_LSFT, KC_F4, KC_F5, KC_F6, KC_F11,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RSFT,
        KC_LCTL, KC_F1, KC_F2, KC_F3, KC_F10,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RCTL,
                        KC_TRNS,     KC_TRNS,          KC_TRNS,          KC_TRNS
    ),
    [2] = LAYOUT( //numpad and symbols
        KC_Q,            KC_7, KC_8, KC_9, KC_EQL,             UP(AE_lC,AE_uC), KC_GRV,  S(KC_9),    S(KC_0),    UM(EURO),
        LSFT_T(KC_0),    KC_4, KC_5, KC_6, KC_MINS,            UP(OE_lC,OE_uC), KC_QUOT, S(KC_LBRC), S(KC_RBRC), UM(SS),
        LCTL_T(KC_PSLS), KC_1, KC_2, KC_3, KC_PDOT,            UP(UE_lC,UE_uC), KC_NUBS, KC_LBRC,    KC_RBRC,    KC_RCTL,
                         KC_TRNS,          KC_TRNS,            KC_TRNS,          KC_TRNS
    ),
    [3] = LAYOUT( //navigation
        LCTL(KC_Z), KC_VOLD, KC_VOLU, KC_TRNS, KC_NUM,        KC_INS,  KC_HOME,       KC_UP,   KC_END,         KC_NO,
        KC_LSFT,    KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,       KC_PGUP, KC_LEFT,       KC_DOWN, KC_RIGHT,       KC_RSFT,
        KC_LCTL,    KC_F13,  KC_F14,  KC_F15,  UC_WINC,       KC_PGDN, LCTL(KC_LEFT), KC_NO,   LCTL(KC_RIGHT), KC_RCTL,
                             KC_TRNS,          KC_TRNS,       KC_ENT,                 KC_RALT
    )
};
