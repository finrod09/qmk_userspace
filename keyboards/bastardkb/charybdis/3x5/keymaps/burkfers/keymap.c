/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "keycodes.h"
#include "modifiers.h"
#include "quantum.h"
#include QMK_KEYBOARD_H
#include "burkfers.h"
#include "g/keymap_combo.h"

#define TD_BOOT TD(U_TD_BOOT)
#define TD_CLR TD(U_TD_CLR)
#define TD_MAKE TD(U_TD_MAKE)
#define TD_SYSR TD(U_TD_SYSRQ)

#define ALGR_W RALT_T(KC_W)
#define ALGR_O RALT_T(KC_O)
#define ___GACS_L___(k01, k02, k03, k04) LGUI_T(KC_##k01), LALT_T(KC_##k02), LCTL_T(KC_##k03), LSFT_T(KC_##k04)
#define ___GACS_R___(k01, k02, k03, k04) RSFT_T(KC_##k01), RCTL_T(KC_##k02), LALT_T(KC_##k03), RGUI_T(KC_##k04)
#define ALG(k01) RALT_T(KC_##k01)

#define PT_TOGG TG(LAYER_POINTER)

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

#define LAYER_QWERTY LAYER_BASE

#define M_NUM LT(LAYER_NUM, KC_M)

#define GAME TG(LAYER_GAME)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_QWERTY] = LAYOUT_wrapper(
  // ╭─────────────────────────────────────────────╮ ╭──────────────────────────────────────────────╮
          KC_Q,  ALGR_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,  ALGR_O,    KC_P,
  // ├─────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
        ___GACS_L___(   A,   S,   D,   F),    KC_G,       KC_H, ___GACS_R___(   J,   K,    L, QUOT),
  // ├─────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  // ╰─────────────────────────────────────────────┤ ├──────────────────────────────────────────────╯
 LT(LAYER_MEDIA, KC_ESC),       LT(LAYER_NAV, KC_SPC), LT(LAYER_POINTER, KC_TAB), LT(LAYER_NUM,KC_BSPC),     LT(LAYER_SYM, KC_ENT)
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [LAYER_NUM] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭──────────────────────────────────────────────╮
       KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,    XXXXXXX, XXXXXXX, XXXXXXX, KC_ALGR, TD_SYSR,
  // ├─────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
       KC_SCLN,    KC_4,    KC_5,    KC_6,  KC_EQL,    XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
  // ├─────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
        KC_GRV,    KC_1,    KC_2,    KC_3, KC_BSLS,    XXXXXXX, XXXXXXX,  TD_CLR, TD_MAKE, TD_BOOT,
  // ╰─────────────────────────────────────────────┤ ├──────────────────────────────────────────────╯
                         DOTCOMM,    KC_0, KC_MINS,    XXXXXXX, XXXXXXX
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_NAV] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭──────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    C(KC_Y), C(KC_V), C(KC_C), C(KC_X), C(KC_Z),
  // ├─────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
       KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_DEL,
  // ├─────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
       TD_BOOT, TD_MAKE,  TD_CLR, XXXXXXX,    GAME,    KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_INS,
  // ╰─────────────────────────────────────────────┤ ├──────────────────────────────────────────────╯
                         XXXXXXX, XXXXXXX, XXXXXXX,    KC_BSPC,  KC_ENT
  //             ╰─────────────────────────────────╯ ╰──────────────────╯
  ),

    [LAYER_FUN] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭──────────────────────────────────────────────╮
        KC_F12,   KC_F7,   KC_F8,   KC_F9, KC_PSCR,    XXXXXXX, XXXXXXX, XXXXXXX, KC_ALGR, TD_SYSR,
  // ├─────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
        KC_F11,   KC_F4,   KC_F5,   KC_F6, KC_SCRL,    XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
  // ├─────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
        KC_F10,   KC_F1,   KC_F2,   KC_F3, KC_PAUS,    XXXXXXX, XXXXXXX,  TD_CLR, TD_MAKE, TD_BOOT,
  // ╰─────────────────────────────────────────────┤ ├──────────────────────────────────────────────╯
                          KC_APP,  KC_SPC,  QK_REP,    XXXXXXX, XXXXXXX
  //                   ╰──────────────────────────╯ ╰──────────────────╯
  ),
  [LAYER_MEDIA] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭──────────────────────────────────────────────╮
       XXXXXXX, KC_ALGR, XXXXXXX, XXXXXXX, KC_MNXT,    RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG,
  // ├─────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
       KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_MPLY,    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
  // ├─────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
       TD_BOOT, TD_MAKE,  TD_CLR, XXXXXXX, KC_MPRV,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├──────────────────────────────────────────────╯
                         XXXXXXX, XXXXXXX, XXXXXXX,    KC_MSTP, KC_MPLY
  //             ╰─────────────────────────────────╯ ╰──────────────────╯
  ),
     [LAYER_SYM] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭──────────────────────────────────────────────╮
       KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,    XXXXXXX, XXXXXXX, XXXXXXX, KC_ALGR, TD_SYSR,
  // ├─────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
       KC_COLN,  KC_DLR, KC_PERC, KC_CIRC, KC_PLUS,    XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
  // ├─────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
       KC_TILD, KC_EXLM,   KC_AT, KC_HASH, KC_PIPE,    XXXXXXX, XXXXXXX,  TD_CLR, TD_MAKE, TD_BOOT,
  // ╰─────────────────────────────────────────────┤ ├──────────────────────────────────────────────╯
                         KC_LPRN, KC_RPRN, KC_UNDS,    XXXXXXX, XXXXXXX
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [LAYER_POINTER] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       _______, _______, _______, _______, _______,   DPI_MOD, S_D_MOD, _______, _______,  L_LOCK,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       _______, _______, _______, _______, _______,   KC_BTN4, KC_BTN5, PM_MO(PM_CARET), PM_MO(PM_VOL), PM_MO(PM_HISTORY),
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       _______, _______, _______, _______, _______,   KC_BTN2, KC_BTN1, SNIPING, DRGSCRL, KC_BTN3,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, _______,  L_LOCK,   _______, _______
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [LAYER_GAME] = LAYOUT_wrapper(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,      KC_H, ___GACS_R___(   J,   K,   L, QUOT),
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,      KC_N,    KC_M, KC_COMM,  KC_DOT,    GAME,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                            KC_ESC,  KC_SPC, M_NUM,   _______, MO(LAYER_NAV)
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on

#ifdef RGB_MATRIX_ENABLE
// clang-format off
const uint8_t PROGMEM ledmaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_QWERTY] = LAYOUT(
  // ╭───────────────────────────────────╮ ╭────────────────────────────────────╮
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ╰───────────────────────────────────┤ ├────────────────────────────────────╯
                     hMGTA, hCYAN, hYELO,    hBLUE, hGREN
  //               ╰─────────────────────╯ ╰──────────────╯
  ),
  [LAYER_NUM] = LAYOUT(
  // ╭───────────────────────────────────╮ ╭────────────────────────────────────╮
       hCYAN, hBLUE, hBLUE, hBLUE, hCYAN,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
       hCYAN, hBLUE, hBLUE, hBLUE, hCYAN,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
       hCYAN, hBLUE, hBLUE, hBLUE, hCYAN,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ╰───────────────────────────────────┤ ├────────────────────────────────────╯
                     hBLUE, hBLUE, hBLUE,     hOFF,  hOFF
  //               ╰─────────────────────╯ ╰──────────────╯
  ),
  [LAYER_NAV] = LAYOUT(
  // ╭───────────────────────────────────╮ ╭────────────────────────────────────╮
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,    hCYAN, hCYAN, hCYAN, hCYAN, hCYAN,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,    hCYAN, hCYAN, hCYAN, hCYAN, hCYAN,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,    hCYAN, hCYAN, hCYAN, hCYAN, hCYAN,
  // ╰───────────────────────────────────┤ ├────────────────────────────────────╯
                      hOFF,  hOFF,  hOFF,     hOFF,  hOFF
  //               ╰─────────────────────╯ ╰──────────────╯
  ),
  [LAYER_FUN] = LAYOUT(
  // ╭───────────────────────────────────╮ ╭────────────────────────────────────╮
        hRED,  hRED,  hRED,  hRED, hLRED,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hRED,  hRED,  hRED,  hRED, hLRED,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hRED,  hRED,  hRED,  hRED, hLRED,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ╰───────────────────────────────────┤ ├────────────────────────────────────╯
                     hLRED,  hOFF,  hOFF,     hOFF,  hOFF
  //               ╰─────────────────────╯ ╰──────────────╯
  ),
  [LAYER_MEDIA] = LAYOUT(
  // ╭───────────────────────────────────╮ ╭────────────────────────────────────╮
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,    hMGTA, hMGTA, hMGTA, hMGTA,  hOFF,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ╰───────────────────────────────────┤ ├────────────────────────────────────╯
                      hOFF,  hOFF,  hOFF,    hMGTA, hMGTA
  //               ╰─────────────────────╯ ╰──────────────╯
  ),
  [LAYER_SYM] = LAYOUT(
  // ╭───────────────────────────────────╮ ╭────────────────────────────────────╮
       hGREN, hGREN, hGREN, hGREN, hGREN,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
       hGREN, hGREN, hGREN, hGREN, hGREN,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
       hGREN, hGREN, hGREN, hGREN, hGREN,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ╰───────────────────────────────────┤ ├────────────────────────────────────╯
                     hGREN, hGREN, hGREN,     hOFF,  hOFF
  //               ╰─────────────────────╯ ╰──────────────╯
  ),
  [LAYER_POINTER] = LAYOUT(
  // ╭───────────────────────────────────╮ ╭────────────────────────────────────╮
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,    hYELO, hYELO,  hOFF,  hOFF,  hOFF,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,    hYELO, hYELO, hCYAN, hCYAN, hYELO,
  // ╰───────────────────────────────────┤ ├────────────────────────────────────╯
                      hOFF,  hOFF,  hOFF,     hOFF,  hOFF
  //               ╰─────────────────────╯ ╰──────────────╯
  ),
  [LAYER_GAME] = LAYOUT(
  // ╭───────────────────────────────────╮ ╭────────────────────────────────────╮
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hOFF, hPRPL, hPRPL, hPRPL,  hOFF,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ╰───────────────────────────────────┤ ├────────────────────────────────────╯
                      hOFF,  hOFF,  hOFF,     hOFF,  hOFF
  //               ╰─────────────────────╯ ╰──────────────╯
  ),
};
// clang-format on

#endif
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(LAYER_MEDIA, KC_ESC):
        case LT(LAYER_NAV, KC_SPC):
        case LT(LAYER_NUM, KC_BSPC):
        case LT(LAYER_SYM, KC_ENT):
        case LT(LAYER_POINTER, KC_TAB):
        case LT(LAYER_FUN, KC_DEL):
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    if (IS_LAYER_ON(LAYER_POINTER)) {
        return 0;
    } else {
        switch (tap_hold_keycode) {
            case LT(LAYER_MEDIA, KC_ESC):
            case LT(LAYER_NAV, KC_SPC):
            case LT(LAYER_NUM, KC_BSPC):
            case LT(LAYER_SYM, KC_ENT):
            case LT(LAYER_POINTER, KC_TAB):
            case LT(LAYER_FUN, KC_DEL):
                return 0;
            default:
                return 600;
        }
    }
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
        case game_zx_t:
        case game_rf_g:
        case game_fv_b:
            if (!layer_state_is(LAYER_GAME)) {
                return false;
            }
    }

    return true;
}

#ifdef MACCEL_ENABLE
#include "features/maccel/maccel.h"
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    return pointing_device_task_maccel(mouse_report);
}
#endif
