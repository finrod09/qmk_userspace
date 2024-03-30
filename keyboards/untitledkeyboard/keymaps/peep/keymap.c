// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "peep.h"

#define LOWER MO(LAYER_LOWER)
#define TD_BOOT TD(U_TD_BOOT)
#define TD_CLR TD(U_TD_CLR)

#define TG_GAME TG(LAYER_GAME)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [LAYER_BASE] = LAYOUT(
//    ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
         KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   DE_SS,
//    ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_LGUI,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      DE_Z,    KC_U,    KC_I,    KC_O,    KC_P, DE_UDIA,
//    ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,      KC_H,    KC_J,    KC_K,    KC_L, DE_ODIA, DE_ADIA,
//    ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_LCTL,    DE_Y,    KC_X,    KC_C,    KC_V,    KC_B,      KC_N,    KC_M, KC_COMM,  KC_DOT, DE_MINS, KC_RALT,
//    ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                 KC_LALT, DE_LABK, KC_LSFT, KC_BTN3,  KC_SPC,    KC_ENT, KC_BSPC,   LOWER, DE_HASH,  KC_DEL
//             ╰─────────────────────────────────────────────╯ ╰───────────────────────────────────────────╯
    ),
    [LAYER_GAME] = LAYOUT(
//    ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
         KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0, TG_GAME,
//    ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_LGUI,   KC_T,    KC_Q,    KC_W,    KC_E,    KC_R,      DE_Z,    KC_U,    KC_I,    KC_O,    KC_P, DE_UDIA,
//    ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         KC_TAB,    KC_G,    KC_A,    KC_S,    KC_D,    KC_F,      KC_H,    KC_J,    KC_K,    KC_L, DE_ODIA, DE_ADIA,
//    ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_LCTL,    KC_B,    DE_Y,    KC_X,    KC_C,    KC_V,      KC_N,    KC_M, KC_COMM,  KC_DOT, DE_MINS, KC_RALT,
//    ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                 KC_LALT, DE_LABK, KC_LSFT, KC_BTN3, KC_SPC,     KC_ENT, KC_BSPC,   LOWER, DE_HASH,  KC_DEL
//             ╰─────────────────────────────────────────────╯ ╰───────────────────────────────────────────╯
    ),
    [LAYER_LOWER] = LAYOUT(
//    ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_HOME,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, TG_GAME,
//    ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        _______, XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX,   OLED_VI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_F12,
//    ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, TG_GAME,   TD_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, DE_PLUS, KC_PGUP,
//    ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    TD_CLR,  KC_WIT, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN,
//    ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                 _______, DE_CIRC, _______, XXXXXXX, KC_MUTE,   _______, _______, _______,  KC_INS,  KC_END
//             ╰─────────────────────────────────────────────╯ ╰───────────────────────────────────────────╯
    ),
    // clang-format on
};

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    debug_enable = true;
    debug_matrix = true;
    // debug_keyboard=true;
    // debug_mouse=true;
}

bool process_record_km(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
    return true;
}

void u_td_fn_boot(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        reset_keyboard();
    }
}
void u_td_fn_clr(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        eeconfig_disable();
        soft_reset_keyboard();
    }
}

tap_dance_action_t tap_dance_actions[] = {[U_TD_BOOT] = ACTION_TAP_DANCE_FN(u_td_fn_boot), [U_TD_CLR] = ACTION_TAP_DANCE_FN(u_td_fn_clr)};
