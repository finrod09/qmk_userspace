// Copyright 2021 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "tap_dances.h"
#include "quantum.h"

void u_td_fn_boot(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        reset_keyboard();
    }
}

#ifdef EE_HANDS
void u_td_fn_make_l(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        // adapted from quantum.c, since we can't tap quantum codes

        SEND_STRING_DELAY("qmk flash ", TAP_CODE_DELAY);
        SEND_STRING_DELAY("-kb " QMK_KEYBOARD " -km " QMK_KEYMAP " -bl uf2-split-left -j 0" SS_TAP(X_ENTER), 1);
    }
}
void u_td_fn_make_r(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        // adapted from quantum.c, since we can't tap quantum codes

        SEND_STRING_DELAY("qmk flash ", TAP_CODE_DELAY);
        SEND_STRING_DELAY("-kb " QMK_KEYBOARD " -km " QMK_KEYMAP " -bl uf2-split-right -j 0" SS_TAP(X_ENTER), 1);
    }
}
#else
void u_td_fn_make(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        // adapted from quantum.c, since we can't tap quantum codes

        SEND_STRING_DELAY("qmk flash ", 1);
        SEND_STRING_DELAY("-kb " QMK_KEYBOARD " -km " QMK_KEYMAP "" SS_TAP(X_ENTER), 1);
    } else if (state->count == 3) {
        SEND_STRING_DELAY("qmk compile --compiledb -kb " QMK_KEYBOARD " -km " QMK_KEYMAP "" SS_TAP(X_ENTER), 1);
    }
}
#endif

void u_td_fn_sysrq_reisub(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        register_mods(MOD_LALT);
        register_code(KC_PRINT_SCREEN);
        wait_ms(50);
        tap_code(KC_R);
        wait_ms(50);
        tap_code(KC_E);
        wait_ms(50);
        tap_code(KC_I);
        wait_ms(50);
        tap_code(KC_S);
        wait_ms(50);
        tap_code(KC_U);
        wait_ms(50);
        tap_code(KC_B);
        unregister_code(KC_PRINT_SCREEN);
        unregister_mods(MOD_LALT);
    }
}

void u_td_fn_clr(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        eeconfig_disable();
        soft_reset_keyboard();
    }
}

// Associate our tap dance key with its functionality
tap_dance_action_t tap_dance_actions[] = {
    [U_TD_BOOT] = ACTION_TAP_DANCE_FN(u_td_fn_boot),          [U_TD_CLR] = ACTION_TAP_DANCE_FN(u_td_fn_clr),
#ifdef EE_HANDS
    [U_TD_MAKEL] = ACTION_TAP_DANCE_FN(u_td_fn_make_l),       [U_TD_MAKER] = ACTION_TAP_DANCE_FN(u_td_fn_make_r),
#else
    [U_TD_MAKE] = ACTION_TAP_DANCE_FN(u_td_fn_make),
#endif
    [U_TD_SYSRQ] = ACTION_TAP_DANCE_FN(u_td_fn_sysrq_reisub),
};
