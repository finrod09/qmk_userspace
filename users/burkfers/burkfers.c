#include "action_layer.h"
#include QMK_KEYBOARD_H
#include "quantum.h"
#include "keycodes.h"
#include "burkfers.h"
#include "charybdis.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    static bool dotcomm_state = true; // true=dot; false=comma
    const uint16_t mod_shift = get_mods() & MOD_MASK_SHIFT;
    switch(keycode) {
        case C_LT:
            if(record->event.pressed) {
                static uint8_t current_default_layer = LAYER_BASE;
                switch(current_default_layer) {
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

void matrix_scan_user(void) {
}

#ifdef RGB_MATRIX_ENABLE
const HSV hsv_colors[] = {
    [ hOFF]     = {  0,   0,   0},
    [hPRPL]     = {205, 255, 255},
    [hDPRP]     = {205, 255, 150},
    [hPINK]     = {251, 223, 255},
    [hDPNK]     = {251, 223, 155},
    [hCYAN]     = {128, 255, 255},
    [hLRED]     = {255, 239, 255},
    [hBLUE]     = {170, 215, 221},
    [hORNG]     = { 20, 208, 255},
    [ hRED]     = {  0, 255, 255},
    [hMGTA]     = {220, 255, 255},
    [hYELO]     = { 15, 255, 255},
    [hGREN]     = { 50, 255, 255},
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
        int layer = get_highest_layer(layer_state|default_layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for(uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if(led_min <= index && index <= led_max) {
                    uint8_t color = pgm_read_byte(&ledmaps[layer][row][col]);
                    HSV hsv = hsv_colors[color];
                    if(hsv.s > 0)
                        hsv.v = rgb_matrix_config.hsv.v;
                    RGB rgb = hsv_to_rgb(hsv);
                    rgb_matrix_set_color( index, rgb.r, rgb.g, rgb.b );
                };
            };
        };
    return false;
}
#endif

bool is_mouse_record_user(uint16_t keycode, keyrecord_t* record) {
    switch(keycode) {
        case DRGSCRL:
        case SNIPING:
        case S_D_MOD:
        case DPI_MOD:
            return true;
        default:
            return false;
    }
}

#ifdef THUMB_COMBOS
const uint16_t PROGMEM thumbcombos_base_right[] = {LT(LAYER_SYM, KC_ENT), LT(LAYER_NUM, KC_BSPC), COMBO_END};
const uint16_t PROGMEM thumbcombos_base_left[] = {LT(LAYER_NAV, KC_SPC), LT(LAYER_POINTER, KC_TAB), COMBO_END};
const uint16_t PROGMEM thumbcombos_nav[] = {KC_ENT, KC_BSPC, COMBO_END};
//const uint16_t PROGMEM thumbcombos_mouse[] = {KC_BTN2, KC_BTN1, COMBO_END};
const uint16_t PROGMEM thumbcombos_media[] = {KC_MSTP, KC_MPLY, COMBO_END};
#ifdef THUMB_COMBOS_LEFT
const uint16_t PROGMEM thumbcombos_num[] = {KC_0, KC_MINS, COMBO_END};
const uint16_t PROGMEM thumbcombos_sym[] = {KC_RPRN, KC_UNDS, COMBO_END};
const uint16_t PROGMEM thumbcombos_fun[] = {KC_SPC, KC_TAB, COMBO_END};
#endif
combo_t key_combos[] = {
  COMBO(thumbcombos_base_right, LT(LAYER_FUN, KC_DEL)),
  COMBO(thumbcombos_nav, KC_DEL),
//  COMBO(thumbcombos_mouse, KC_BTN3),
  COMBO(thumbcombos_media, KC_MUTE),
#ifdef THUMB_COMBOS_LEFT
  COMBO(thumbcombos_base_left, LT(LAYER_MEDIA, KC_ESC)),
  COMBO(thumbcombos_num, KC_DOT),
  COMBO(thumbcombos_sym, KC_LPRN),
  COMBO(thumbcombos_fun, KC_APP)
#endif
};
#endif
