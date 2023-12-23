#include "peep.h"
#include "quantum.h"
#ifdef OLED_ENABLE
#   include "oled/oled.h"
#endif

__attribute__((weak)) bool process_record_km(uint16_t keycode, keyrecord_t *record) {
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_km(keycode, record)) {
        return false;
    }

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

#ifdef OLED_ENABLE
    if (record->event.pressed) {
        oled_whatisthis_keypress(keycode);
    }
#endif
    return true;
};
