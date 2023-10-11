#include "action_layer.h"
#include QMK_KEYBOARD_H
#include "quantum.h"
#include "keycodes.h"
#include "burkfers.h"
#include "charybdis.h"

/******************
   CUSTOM KEYCODES
  *****************/
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) { return false; }

    static bool dotcomm_state = true; // true=dot; false=comma
    const uint16_t mod_shift = get_mods() & MOD_MASK_SHIFT;

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
        case C_LT:
            if(record->event.pressed) {
                static uint8_t current_default_layer = LAYER_QWERTY;
                switch(current_default_layer) {
                    case LAYER_QWERTY:
                        default_layer_set(1UL << LAYER_GAME);
                        current_default_layer = LAYER_GAME;
                        break;
                    case LAYER_GAME:
                    default:
                        default_layer_set(1UL << LAYER_QWERTY);
                        current_default_layer = LAYER_QWERTY;
                        break;
                };
            } else {

            }
            return false; // no further processing
        case DOTCOMM: // thanks wimads!
            if (record->event.pressed && record->tap.count == 2) {//swap DOTCOMM state
                    dotcomm_state = !dotcomm_state; //swap state
                    tap_code16(KC_BSPC);            //remove character output from first tap
                } else if (record->event.pressed && dotcomm_state) {//when state is true
                    if (mod_shift) { //send comm when shifted
                        unregister_mods(mod_shift);
                        tap_code16(KC_COMM);
                        register_mods(mod_shift);
                    } else { //send dot by default
                        tap_code16(KC_DOT);
                    }
                } else if (record->event.pressed) {//when state is false
                    if (mod_shift) { //send dot when shifted
                        unregister_mods(mod_shift);
                        tap_code16(KC_DOT);
                        register_mods(mod_shift);
                    } else { //send comm by default
                        tap_code16(KC_COMM);
                    }
                }
                return false;
        case C_PTRD:
            layer_off(LAYER_POINTER);
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

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(LAYER_MEDIA, KC_ESC):
        case LT(LAYER_NAV, KC_SPC):
        case LT(LAYER_NUM,KC_BSPC):
        case LT(LAYER_SYM, KC_ENT):
        case LT(LAYER_POINTER, KC_TAB):
        case LT(LAYER_FUN, KC_DEL):
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}
