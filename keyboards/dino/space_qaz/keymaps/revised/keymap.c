// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM test_combo1[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM test_combo2[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM test_combo3[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM test_combo4[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM test_combo5[] = {KC_COMM, KC_DOT, COMBO_END};

const uint16_t PROGMEM test_combo6[] = {KC_VOLD, KC_VOLU, COMBO_END};
const uint16_t PROGMEM test_combo7[] = {KC_MPRV, KC_MNXT, COMBO_END};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

enum {
    SPACE_SYM_FN
};

td_state_t cur_dance(tap_dance_state_t *state);
void space_finished(tap_dance_state_t *state, void *user_data);
void space_reset(tap_dance_state_t *state, void *user_data);

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
        KC_Q,           KC_W,   KC_E,           KC_R,           KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,
        LSFT_T(KC_A),   KC_S,   KC_D,           LT(1,KC_F),     KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   RSFT_T(KC_SCLN),
        LCTL_T(KC_Z),   KC_X,   LALT_T(KC_C),   LGUI_T(KC_V),   KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, RCTL_T(KC_SLSH),
        TD(SPACE_SYM_FN)
    ),
    [1] = LAYOUT_31(    //nav layer
        KC_TRNS,    KC_VOLD,    KC_VOLU,    KC_TRNS,    KC_TRNS,    KC_INS,     KC_HOME,    KC_UP,      KC_END,     KC_TRNS,
        KC_LSFT,    KC_MPRV,    KC_MNXT,    KC_TRNS,    KC_TRNS,    KC_PGUP,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_RSFT,
        KC_LCTL,    KC_TRNS,    KC_LALT,    KC_TRNS,    KC_TRNS,    KC_PGDN,    KC_TRNS,    KC_TRNS,    KC_RCTL,    KC_RCTL,
        KC_TRNS
    ),
    [2] = LAYOUT_31(    //symbols layer
        KC_PAST,            KC_7,       KC_8,    KC_9,    KC_EQL,     KC_TRNS,    KC_GRV,    KC_LPRN,     KC_RPRN,    KC_TRNS,
        LSFT_T(KC_0),       KC_4,       KC_5,    KC_6,    KC_MINS,    KC_TRNS,    KC_QUOT,    KC_LCBR,     KC_RCBR,    KC_RSFT,
        LCTL_T(KC_PSLS),    KC_1,       KC_2,    KC_3,    KC_PDOT,    KC_TRNS,    KC_NUBS,    KC_LBRC,     KC_RBRC,    KC_RCTL,
        KC_TRNS
    ),
    [3] = LAYOUT_31(    //symbols layer
        KC_TRNS,    KC_F7,  KC_F8,  KC_F9,  KC_F12, KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
        KC_LSFT,    KC_F4,  KC_F5,  KC_F6,  KC_F11, KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
        KC_LCTL,    KC_F1,  KC_F2,  KC_F3,  KC_F10, KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
        KC_TRNS
    )
};

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state -> pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    } else return TD_UNKNOWN;
}

static td_tap_t spacetap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void space_finished(tap_dance_state_t *state, void *user_data) {
    spacetap_state.state = cur_dance(state);
    switch (spacetap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_SPACE); break;
        case TD_SINGLE_HOLD: layer_on(2); break;
        case TD_DOUBLE_TAP: tap_code(KC_SPACE); register_code(KC_SPACE); break;
        case TD_DOUBLE_HOLD: layer_on(3); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_SPACE); register_code(KC_SPACE); break;
        default: break;
    }
}

void space_reset(tap_dance_state_t *state, void *user_data) {
    switch (spacetap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_SPACE); break;
        case TD_SINGLE_HOLD: layer_off(2); break;
        case TD_DOUBLE_TAP: unregister_code(KC_SPACE); break;
        case TD_DOUBLE_HOLD: layer_off(3); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_SPACE); break;
        default: break;
    }
    spacetap_state.state = TD_NONE;
}

tap_dance_action_t tap_dance_actions[] = {
    [SPACE_SYM_FN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, space_finished, space_reset)
};