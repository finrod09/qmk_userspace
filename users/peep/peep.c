#include "peep.h"
#include "quantum.h"
#ifdef OLED_ENABLE
#    include "oled/oled.h"
#endif

__attribute__((weak)) bool process_record_km(uint16_t keycode, keyrecord_t *record) {
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_km(keycode, record)) {
        return false;
    }
#ifdef OLED_ENABLE
    if (record->event.pressed && (keycode == KC_WHATISTHIS || (keycode == (keycode & 0xff)))) {
        if (!oled_whatisthis_keypress(keycode, get_mods())) {
            return false;
        }
    }
#endif

    switch (keycode) {
#ifdef OLED_ENABLE
        case QK_OLED_VAI:
            if (record->event.pressed) {
                const bool is_shifted = get_mods() & MOD_MASK_SHIFT;
                oled_inc_brightness(is_shifted);
            }
            return false;
        case KC_WHATISTHIS:
            if (record->event.pressed) {
                oled_whatisthis();
            }
            return false;
#endif
    }

    return true;
};

layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef OLED_ENABLE
    should_clear_oled();
#endif

    return state;
}
