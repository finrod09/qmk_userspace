#include "action_layer.h"
#include QMK_KEYBOARD_H
//#include "features/achordion.h"
#include "quantum.h"
#include "keycodes.h"
#include "burkfers.h"
#include "charybdis.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   // if (!process_achordion(keycode, record)) { return false; }

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
        default:
            return true; // process elsewhere
    }
}

void matrix_scan_user(void) {
  //achordion_task();
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  return 500;
}
void u_td_fn_boot(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        reset_keyboard();
    }
}

#ifdef EE_HANDS
void u_td_fn_make_l(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        // adapted from quantum.c, since we can't tap quantum codes

        SEND_STRING_DELAY("qmk flash ", TAP_CODE_DELAY);
        SEND_STRING_DELAY("-kb " QMK_KEYBOARD " -km " QMK_KEYMAP " -bl uf2-split-left" SS_TAP(X_ENTER), TAP_CODE_DELAY);
    }
}
void u_td_fn_make_r(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        // adapted from quantum.c, since we can't tap quantum codes

        SEND_STRING_DELAY("qmk flash ", TAP_CODE_DELAY);
        SEND_STRING_DELAY("-kb " QMK_KEYBOARD " -km " QMK_KEYMAP " -bl uf2-split-right " SS_TAP(X_ENTER), TAP_CODE_DELAY);
    }
}
#else
void u_td_fn_make(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        // adapted from quantum.c, since we can't tap quantum codes

        SEND_STRING_DELAY("qmk flash ", TAP_CODE_DELAY);
        SEND_STRING_DELAY("-kb " QMK_KEYBOARD " -km " QMK_KEYMAP " " SS_TAP(X_ENTER), TAP_CODE_DELAY);
    }
}
#endif

void u_td_fn_sysrq_reisub(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        register_mods(MOD_LALT);
        register_code(KC_PRINT_SCREEN);
        wait_ms(50);
        tap_code(KC_R);
        wait_ms(50);
        tap_code(KC_E);
        wait_ms(50);
        tap_code(KC_I);
        wait_ms(50);
        tap_code(KC_S);
        wait_ms(50);
        tap_code(KC_U);
        wait_ms(50);
        tap_code(KC_B);
        unregister_code(KC_PRINT_SCREEN);
        unregister_mods(MOD_LALT);
    }
}

void u_td_fn_clr(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        eeconfig_disable();
        soft_reset_keyboard();
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [U_TD_BOOT] = ACTION_TAP_DANCE_FN(u_td_fn_boot),
    [U_TD_CLR] = ACTION_TAP_DANCE_FN(u_td_fn_clr),
    [U_TD_PT_Z] = ACTION_TAP_DANCE_LAYER_MOVE(KC_Z, LAYER_POINTER),
    [U_TD_PT_SLSH] = ACTION_TAP_DANCE_LAYER_MOVE(KC_SLSH, LAYER_POINTER),
#ifdef EE_HANDS
    [U_TD_MAKEL] = ACTION_TAP_DANCE_FN(u_td_fn_make_l),
    [U_TD_MAKER] = ACTION_TAP_DANCE_FN(u_td_fn_make_r),
#else
    [U_TD_MAKE] = ACTION_TAP_DANCE_FN(u_td_fn_make),
#endif
    [U_TD_SYSRQ] = ACTION_TAP_DANCE_FN(u_td_fn_sysrq_reisub),
};


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

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
    if(layer_state_is(LAYER_POINTER)) { return true; } // don't use achordion on mouse layer

    switch (tap_hold_keycode) {
        case HOME_J:
        case HOME_K:
        case HOME_L:
        case HOME_SCLN:
            if (other_keycode == KC_ENT || other_keycode == LT(LAYER_SYM, KC_ENT)) { return true; } // allow gui+return as a one hand hold
            break;
        case LT(LAYER_FUN, KC_DEL): // combo result confuses achordion (has no handedness) - allow, because it's bilateral
        case LT(LAYER_SYM, KC_ENT):
        case LT(LAYER_MEDIA, KC_ESC):
        case LT(LAYER_NAV, KC_SPC):
        case LT(LAYER_POINTER, KC_TAB):
        case LT(LAYER_NUM, KC_BSPC):
        case DRGSCRL:
        case SNIPING:
            return true;
    }
    // Otherwise, follow the opposite hands rule.
    return achordion_opposite_hands(tap_hold_record, other_record);
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
