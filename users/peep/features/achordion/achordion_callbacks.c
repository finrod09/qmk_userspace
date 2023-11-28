#include "peep.h"

void matrix_scan_user(void) {
  achordion_task();
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
    switch (other_keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            other_keycode &= 0xff;  // Get base keycode.
    }

    switch (tap_hold_keycode) {
        case LGUI_T(KC_A):
            if (other_keycode == KC_SPC) { return true; }
            break;
        case RGUI_T(KC_QUOT):
            if (other_keycode == KC_ENT) { return true; }
            break;
  }

  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
//    if(IS_LAYER_ON(LAYER_POINTER)) {
//        return 0;
//    } else {
        switch(tap_hold_keycode) {
            case LT(LAYER_MEDIA, KC_ESC):
                return 0;
            default:
                return 600;
        }
//    }
}
