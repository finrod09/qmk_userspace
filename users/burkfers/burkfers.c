#include "action_layer.h"
#include "process_combo.h"
#include QMK_KEYBOARD_H // IWYU pragma: keep
#include "burkfers.h"
#include "keycodes.h"
#include "quantum.h"

/******************
   CUSTOM KEYCODES
  *****************/
__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef MACCEL_ENABLE
    if (!process_record_maccel(keycode, record, MA_TOGGLE, MA_TAKEOFF, MA_GROWTH_RATE, MA_OFFSET, MA_LIMIT)) return false;
#endif
#ifdef ACHORDION_ENABLE
    if (!process_achordion(keycode, record)) {
        return false;
    }
#endif
    if (!process_record_keymap(keycode, record)) {
        return false;
    }

    static bool    dotcomm_state = true; // true=dot; false=comma
    const uint16_t mod_shift     = get_mods() & MOD_MASK_SHIFT;

    if (!process_layer_lock(keycode, record, L_LOCK)) {
        return false;
    }
    process_caps_word_lock(keycode, record);

    switch (keycode) {
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
            if (record->event.pressed) {
                static uint8_t current_default_layer = LAYER_BASE;
                switch (current_default_layer) {
                    case LAYER_BASE:
                        default_layer_set(1UL << LAYER_GAME);
                        current_default_layer = LAYER_GAME;
                        break;
                    case LAYER_GAME:
                    default:
                        default_layer_set(1UL << LAYER_BASE);
                        current_default_layer = LAYER_BASE;
                        break;
                };
            } else {
            }
            return false;                                          // no further processing
        case DOTCOMM:                                              // thanks wimads!
            if (record->event.pressed && record->tap.count == 2) { // swap DOTCOMM state
                dotcomm_state = !dotcomm_state;                    // swap state
                tap_code16(KC_BSPC);                               // remove character output from first tap
            } else if (record->event.pressed && dotcomm_state) {   // when state is true
                if (mod_shift) {                                   // send comm when shifted
                    unregister_mods(mod_shift);
                    tap_code16(KC_COMM);
                    register_mods(mod_shift);
                } else { // send dot by default
                    tap_code16(KC_DOT);
                }
            } else if (record->event.pressed) { // when state is false
                if (mod_shift) {                // send dot when shifted
                    unregister_mods(mod_shift);
                    tap_code16(KC_DOT);
                    register_mods(mod_shift);
                } else { // send comm by default
                    tap_code16(KC_COMM);
                }
            }
            return false;
        case KC_LAYER_BASE:
            if (record->event.pressed) {
                layer_clear();
                set_single_persistent_default_layer(LAYER_BASE);
            }
            return false;
        case KC_LAYER_BASE2:
            if (record->event.pressed) {
                layer_clear();
                set_single_persistent_default_layer(LAYER_BASE2);
            }
            return false;
        case KC_LAYER_BASE3:
            if (record->event.pressed) {
                layer_clear();
                set_single_persistent_default_layer(LAYER_BASE3);
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
bool shutdown_user(bool jump_to_bootloader) {
    rgb_matrix_set_color_all(200, 10, 10);
    rgb_matrix_update_pwm_buffers();
    return false;
#endif // RGB_MATRIX_ENABLE
}

void keyboard_post_init_user(void) {
#ifdef MACCEL_ENABLE
    keyboard_post_init_maccel();
#endif
    debug_enable = true;
    // debug_matrix=true;
    // debug_keyboard=true;
    // debug_mouse=true;
#ifdef QP_ST7735_ENABLE
    keyboard_post_init_painter();
#endif
}

void matrix_scan_user(void) {
#ifdef ACHORDION_ENABLE
    achordion_task();
#endif
}

__attribute__((weak)) bool combo_should_trigger_km(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record);

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    if (!combo_should_trigger_km(combo_index, combo, keycode, record)) {
        return false;
    }
    return true;
}

void housekeeping_task_user(void) {
#ifdef PAINTER_ENABLE
    housekeeping_task_painter();
#endif
}
