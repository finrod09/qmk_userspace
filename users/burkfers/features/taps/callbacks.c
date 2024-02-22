// Copyright 2021 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "action.h"

// TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            return 275;
            // case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            // if (QK_MOD_TAP_GET_MODS(keycode) & MOD_LGUI) {
            // return 300;
            // }
        default:
            return TAPPING_TERM;
    }
}
