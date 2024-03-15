#include "burkfers.h"

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record, uint16_t other_keycode, keyrecord_t* other_record) {
    switch (other_keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            other_keycode &= 0xff; // Get base keycode.
    }

    switch (tap_hold_keycode) {
        case LGUI_T(KC_C):
        case LGUI_T(KC_A):
            if (other_keycode == KC_SPC) {
                return true;
            }
            break;
        case RGUI_T(KC_A):
        case RGUI_T(KC_QUOT):
            if (other_keycode == KC_ENT) {
                return true;
            }
            break;
        case LT(LAYER_NUM, KC_M):
            if (layer_state_is(LAYER_GAME)) {
                return true;
            }
            break;
    }

    // Otherwise, follow the opposite hands rule.
    return achordion_opposite_hands(tap_hold_record, other_record);
}
