
#include "quantum.h"

void leader_end_user(void) {
    if (leader_sequence_one_key(QK_LEAD)) {
        tap_code(KC_ESC);
    } else if (leader_sequence_two_keys(KC_I, KC_P)) {
        SEND_STRING("192.168.0.10");
    } else if (leader_sequence_one_key(KC_F)) {
        set_oneshot_mods(MOD_BIT(KC_LSFT));
    }
}
