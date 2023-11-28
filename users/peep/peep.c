#include "action_layer.h"
#include QMK_KEYBOARD_H
#include "quantum.h"
#include "keycodes.h"
#include "peep.h"
#include "charybdis.h"

/******************
   CUSTOM KEYCODES
  *****************/
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) { return false; }

    if (!process_layer_lock(keycode, record, L_LOCK)) { return false; }
    process_caps_word_lock(keycode, record);

    switch(keycode) {
        case CAPS_WORD_LOCK:
            // Toggle `caps_word_lock_on`
            if (record->event.pressed) {
                if (caps_word_lock_on) {
                    caps_word_lock_disable();
                    return false;
                } else {
                    caps_word_lock_enable();
                    return false;
                }
            }
            return false;
        default:
            return true; // process elsewhere
    }
}


/******************
    USER CALLBACKS
  *****************/
#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
void shutdown_user(void) {
    rgb_matrix_set_color_all(200, 10, 10);
    rgb_matrix_update_pwm_buffers();
#endif // RGB_MATRIX_ENABLE
}
