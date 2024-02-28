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
#ifdef COMBO_ENABLE
#    include "g/keymap_combo.h"
#endif

#define TD_BOOT TD(U_TD_BOOT)
#define TD_CLR TD(U_TD_CLR)
#define TD_MAKE TD(U_TD_MAKE)
#define TD_SYSR TD(U_TD_SYSRQ)

#define ___GACS_L___(k01, k02, k03, k04) LGUI_T(KC_##k01), LALT_T(KC_##k02), LCTL_T(KC_##k03), LSFT_T(KC_##k04)
#define ___GAC_L___(k01, k02, k03) LGUI_T(KC_##k01), LALT_T(KC_##k02), LCTL_T(KC_##k03)
#define ___GACS_R___(k01, k02, k03, k04) RSFT_T(KC_##k01), RCTL_T(KC_##k02), LALT_T(KC_##k03), RGUI_T(KC_##k04)
#define ___GAC_R___(k01, k02, k03) RCTL_T(KC_##k01), LALT_T(KC_##k02), RGUI_T(KC_##k03)
#define PT_TOGG TG(LAYER_POINTER)
#define ALG(k01) RALT_T(KC_##k01)

#define LAYOUT_wrapper(...) LAYOUT_split_3x5_3(__VA_ARGS__)

#define LAYER_QWERTY LAYER_BASE
#define LAYER_CANARY LAYER_BASE2

#define DF_QWER DF(LAYER_QWERTY)
#define DF_CANA DF(LAYER_CANARY)

#define M_NUM LT(LAYER_NUM, KC_M)

#define GAME TG(LAYER_GAME)
#define MCRPD DF(LAYER_MACROPAD)

enum km_layers { LAYER_MACROPAD = LAYER_KM };

#define OS_LGUI OSM(MOD_LGUI)
#define OS_LALT OSM(MOD_LALT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LSFT OSM(MOD_LSFT)

#define THUML1 QK_LEAD
#define THUML2 OSM(MOD_LSFT)
#define THUML3 LT(LAYER_NAV, KC_SPC)
#define THUMR1 LT(LAYER_NUM, KC_ENT)
#define THUMR2 LT(LAYER_SYM, KC_BSPC)

#ifdef ALT_LAYOUT_ENABLE
#    define ALT_LYT TO(LAYER_ALT_LAYOUT)
#else
#    define ALT_LYT KC_NO
#endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_QWERTY] = LAYOUT_wrapper(
  // ╭─────────────────────────────────────────────╮ ╭──────────────────────────────────────────────╮
          KC_Q,  ALG(W),    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,  ALG(O),    KC_P,
  // ├─────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
            ___GAC_L___(A, S, D),      KC_F,    KC_G,       KC_H,    KC_J, ___GAC_R___(K, L, QUOT),
  // ├─────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  // ╰─────────────────────────────────────────────┤ ├──────────────────────────────────────────────╯
                          THUML1,  THUML2,  THUML3,     THUMR1,  THUMR2, KC_MUTE
// LT(LAYER_MEDIA, KC_ESC),       LT(LAYER_POINTER, KC_TAB),LT(LAYER_NAV, KC_SPC),  LT(LAYER_SYM, KC_ENT),LT(LAYER_NUM,KC_BSPC), KC_MUTE
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [LAYER_CANARY] = LAYOUT_wrapper(
  // ╭─────────────────────────────────────────────╮ ╭──────────────────────────────────────────────╮
          KC_W,    KC_L,    KC_Y,    KC_P,    KC_B,       KC_Z,    KC_F,    KC_O,    KC_U, KC_QUOT,
  // ├─────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
          KC_C,    KC_R,    KC_S,    KC_T,    KC_G,       KC_M,    KC_N,    KC_E,    KC_I,    KC_A,
  // ├─────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
          KC_Q,    KC_J,    KC_V,    KC_D,    KC_K,       KC_X,    KC_H, KC_SLSH, KC_COMM,  KC_DOT,
  // ╰─────────────────────────────────────────────┤ ├──────────────────────────────────────────────╯
 LT(LAYER_MEDIA, KC_ESC),       LT(LAYER_NAV, KC_SPC), QK_REP, LT(LAYER_NUM,KC_BSPC),     LT(LAYER_SYM, KC_ENT), KC_MUTE
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),
#ifdef ALT_LAYOUT_taipo
  [LAYER_ALT_LAYOUT] = LAYOUT_wrapper(
  // ╭─────────────────────────────────────────────╮ ╭──────────────────────────────────────────────╮
          KC_A, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(LAYER_BASE),
  // ├─────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
        TP_TLP,  TP_TLR,  TP_TLM,  TP_TLI, XXXXXXX,    XXXXXXX,  TP_TRI,  TP_TRM,  TP_TRR,  TP_TRP,
  // ├─────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
        TP_BLP,  TP_BLR,  TP_BLM,  TP_BLI, XXXXXXX,    XXXXXXX,  TP_BRI,  TP_BRM,  TP_BRR,  TP_BRP,
  // ╰─────────────────────────────────────────────┤ ├──────────────────────────────────────────────╯
                         XXXXXXX,  TP_LIT,  TP_LOT,     TP_ROT,  TP_RIT, XXXXXXX
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),
#endif
#ifdef ALT_LAYOUT_asetniop
  [LAYER_ALT_LAYOUT] = LAYOUT_wrapper(
  // ╭─────────────────────────────────────────────╮ ╭──────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(LAYER_BASE),
  // ├─────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
          KC_A,    KC_S,    KC_E,    KC_T, XXXXXXX,    XXXXXXX,    KC_N,    KC_I,    KC_O,    KC_P,
  // ├─────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├──────────────────────────────────────────────╯
                         XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),
#endif
  [LAYER_NUM] = LAYOUT_wrapper(
  // ╭─────────────────────────────────────────────╮ ╭──────────────────────────────────────────────╮
       KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,    XXXXXXX, XXXXXXX, XXXXXXX, KC_ALGR, TD_SYSR,
  // ├─────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
       KC_SCLN,    KC_4,    KC_5,    KC_6,  KC_EQL,    XXXXXXX, OS_LSFT, OS_LCTL, OS_LALT, OS_LGUI,
  // ├─────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
        KC_GRV,    KC_1,    KC_2,    KC_3, KC_BSLS,    XXXXXXX, XXXXXXX,  TD_CLR, TD_MAKE, TD_BOOT,
  // ╰─────────────────────────────────────────────┤ ├──────────────────────────────────────────────╯
                         DOTCOMM,    KC_0, KC_MINS,    XXXXXXX, XXXXXXX, KC_MUTE
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_NAV] = LAYOUT_wrapper(
  // ╭─────────────────────────────────────────────╮ ╭──────────────────────────────────────────────╮
       DF_QWER, ALT_LYT, DF_CANA, XXXXXXX, XXXXXXX,    C(KC_Y), C(KC_V), C(KC_C), C(KC_X), C(KC_Z),
  // ├─────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
       OS_LGUI, OS_LALT, OS_LCTL, OS_LSFT,   MCRPD,    KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_DEL,
  // ├─────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
       TD_BOOT, TD_MAKE,  TD_CLR, XXXXXXX,    GAME,    KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_INS,
  // ╰─────────────────────────────────────────────┤ ├──────────────────────────────────────────────╯
                         XXXXXXX, XXXXXXX, XXXXXXX,      KC_ENT,KC_BSPC, KC_MUTE
  //             ╰─────────────────────────────────╯ ╰──────────────────╯
  ),

    [LAYER_FUN] = LAYOUT_wrapper(
  // ╭─────────────────────────────────────────────╮ ╭──────────────────────────────────────────────╮
        KC_F12,   KC_F7,   KC_F8,   KC_F9, KC_PSCR,    XXXXXXX, XXXXXXX, XXXXXXX, KC_ALGR, TD_SYSR,
  // ├─────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
        KC_F11,   KC_F4,   KC_F5,   KC_F6, KC_SCRL,    XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
  // ├─────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
        KC_F10,   KC_F1,   KC_F2,   KC_F3, KC_PAUS,    XXXXXXX, XXXXXXX,  TD_CLR, TD_MAKE, TD_BOOT,
  // ╰─────────────────────────────────────────────┤ ├──────────────────────────────────────────────╯
                          KC_APP, QK_AREP,  KC_SPC,    XXXXXXX, XXXXXXX, KC_MUTE
  //                   ╰──────────────────────────╯ ╰──────────────────╯
  ),
  [LAYER_MEDIA] = LAYOUT_wrapper(
  // ╭─────────────────────────────────────────────╮ ╭──────────────────────────────────────────────╮
       XXXXXXX, KC_ALGR, XXXXXXX, XXXXXXX, KC_MNXT,    RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG,
  // ├─────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
       KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_MPLY,    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
  // ├─────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
       TD_BOOT, TD_MAKE,  TD_CLR, XXXXXXX, KC_MPRV,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├──────────────────────────────────────────────╯
                         XXXXXXX, XXXXXXX, XXXXXXX,    KC_MPLY, KC_MSTP, KC_MUTE
  //             ╰─────────────────────────────────╯ ╰──────────────────╯
  ),
     [LAYER_SYM] = LAYOUT_wrapper(
  // ╭─────────────────────────────────────────────╮ ╭──────────────────────────────────────────────╮
       KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,    XXXXXXX, XXXXXXX, XXXXXXX, KC_ALGR, TD_SYSR,
  // ├─────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
       KC_COLN,  KC_DLR, KC_PERC, KC_CIRC, KC_PLUS,    XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
  // ├─────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
       KC_TILD, KC_EXLM,   KC_AT, KC_HASH, KC_PIPE,    XXXXXXX, XXXXXXX,  TD_CLR, TD_MAKE, TD_BOOT,
  // ╰─────────────────────────────────────────────┤ ├──────────────────────────────────────────────╯
                         KC_LPRN, KC_RPRN, KC_UNDS,    XXXXXXX, XXXXXXX, KC_MUTE
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [LAYER_POINTER] = LAYOUT_wrapper(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       _______, _______, _______, _______, _______,   DPI_MOD, S_D_MOD, _______, _______,  L_LOCK,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       _______, _______, _______, _______, _______,   KC_BTN4, KC_BTN5, _______, _______, _______,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       _______, _______, _______, _______, _______,   KC_BTN2, KC_BTN1, SNIPING, DRGSCRL, KC_BTN3,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, _______,  L_LOCK,   _______, _______, KC_MUTE
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
                            KC_ESC,  M_NUM, KC_SPC,   _______, MO(LAYER_NAV), KC_MUTE
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [LAYER_MACROPAD] = LAYOUT_wrapper(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,      KC_H, ___GACS_R___(   J,   K,   L, QUOT),
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       C(A(KC_1)), C(A(KC_2)), C(A(KC_3)), C(A(KC_4)), C(A(KC_5)),      KC_N,    KC_M, KC_COMM,  KC_DOT, DF(LAYER_BASE),
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                            KC_P,  KC_Y, KC_SPC,   _______, MO(LAYER_NAV), KC_MUTE
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on

#ifdef RGB_MATRIX_ENABLE
// clang-format off
const uint8_t PROGMEM ledmaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_QWERTY] = LAYOUT_wrapper(
  // ╭───────────────────────────────────╮ ╭────────────────────────────────────╮
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ╰───────────────────────────────────┤ ├────────────────────────────────────╯
                     hMGTA, hYELO, hCYAN,    hGREN, hBLUE,  hOFF
  //               ╰─────────────────────╯ ╰──────────────╯
  ),
  [LAYER_CANARY] = LAYOUT_wrapper(
  // ╭───────────────────────────────────╮ ╭────────────────────────────────────╮
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ╰───────────────────────────────────┤ ├────────────────────────────────────╯
                     hMGTA, hCYAN, hYELO,    hGREN, hBLUE,  hOFF
  //               ╰─────────────────────╯ ╰──────────────╯
  ),
#ifdef ALT_LAYOUT_taipo
  [LAYER_ALT_LAYOUT] = LAYOUT_wrapper(
  // ╭───────────────────────────────────╮ ╭────────────────────────────────────╮
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
       hDMGT, hDMGT, hDMGT, hDMGT,  hOFF,     hOFF, hDMGT, hDMGT, hDMGT, hDMGT,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
       hDMGT, hDMGT, hDMGT, hDMGT,  hOFF,     hOFF, hDMGT, hDMGT, hDMGT, hDMGT,
  // ╰───────────────────────────────────┤ ├────────────────────────────────────╯
                      hOFF, hDMGT, hDMGT,    hDMGT, hDMGT,  hOFF
  //               ╰─────────────────────╯ ╰──────────────╯
  ),
#endif
#ifdef ALT_LAYOUT_asetniop
  [LAYER_ALT_LAYOUT] = LAYOUT_wrapper(
  // ╭───────────────────────────────────╮ ╭────────────────────────────────────╮
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
       hDMGT, hDMGT, hDMGT, hDMGT,  hOFF,     hOFF, hDMGT, hDMGT, hDMGT, hDMGT,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ╰───────────────────────────────────┤ ├────────────────────────────────────╯
                      hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF
  //               ╰─────────────────────╯ ╰──────────────╯
  ),
#endif
  [LAYER_NUM] = LAYOUT_wrapper(
  // ╭───────────────────────────────────╮ ╭────────────────────────────────────╮
       hCYAN, hBLUE, hBLUE, hBLUE, hCYAN,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
       hCYAN, hBLUE, hBLUE, hBLUE, hCYAN,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
       hCYAN, hBLUE, hBLUE, hBLUE, hCYAN,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ╰───────────────────────────────────┤ ├────────────────────────────────────╯
                     hBLUE, hBLUE, hBLUE,     hOFF,  hOFF,  hOFF
  //               ╰─────────────────────╯ ╰──────────────╯
  ),
  [LAYER_NAV] = LAYOUT_wrapper(
  // ╭───────────────────────────────────╮ ╭────────────────────────────────────╮
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,    hCYAN, hCYAN, hCYAN, hCYAN, hCYAN,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,    hCYAN, hCYAN, hCYAN, hCYAN, hCYAN,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,    hCYAN, hCYAN, hCYAN, hCYAN, hCYAN,
  // ╰───────────────────────────────────┤ ├────────────────────────────────────╯
                      hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF
  //               ╰─────────────────────╯ ╰──────────────╯
  ),
  [LAYER_FUN] = LAYOUT_wrapper(
  // ╭───────────────────────────────────╮ ╭────────────────────────────────────╮
        hRED,  hRED,  hRED,  hRED, hLRED,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hRED,  hRED,  hRED,  hRED, hLRED,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hRED,  hRED,  hRED,  hRED, hLRED,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ╰───────────────────────────────────┤ ├────────────────────────────────────╯
                     hLRED,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF
  //               ╰─────────────────────╯ ╰──────────────╯
  ),
  [LAYER_MEDIA] = LAYOUT_wrapper(
  // ╭───────────────────────────────────╮ ╭────────────────────────────────────╮
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,    hMGTA, hMGTA, hMGTA, hMGTA,  hOFF,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ╰───────────────────────────────────┤ ├────────────────────────────────────╯
                      hOFF,  hOFF,  hOFF,    hMGTA, hMGTA,  hOFF
  //               ╰─────────────────────╯ ╰──────────────╯
  ),
  [LAYER_SYM] = LAYOUT_wrapper(
  // ╭───────────────────────────────────╮ ╭────────────────────────────────────╮
       hGREN, hGREN, hGREN, hGREN, hGREN,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
       hGREN, hGREN, hGREN, hGREN, hGREN,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
       hGREN, hGREN, hGREN, hGREN, hGREN,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ╰───────────────────────────────────┤ ├────────────────────────────────────╯
                     hGREN, hGREN, hGREN,     hOFF,  hOFF,  hOFF
  //               ╰─────────────────────╯ ╰──────────────╯
  ),
  [LAYER_POINTER] = LAYOUT_wrapper(
  // ╭───────────────────────────────────╮ ╭────────────────────────────────────╮
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,    hYELO, hYELO,  hOFF,  hOFF,  hOFF,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,    hYELO, hYELO, hCYAN, hCYAN, hYELO,
  // ╰───────────────────────────────────┤ ├────────────────────────────────────╯
                      hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF
  //               ╰─────────────────────╯ ╰──────────────╯
  ),
  [LAYER_GAME] = LAYOUT_wrapper(
  // ╭───────────────────────────────────╮ ╭────────────────────────────────────╮
        hOFF,  hOFF, hPRPL,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hOFF, hPRPL, hPRPL, hPRPL,  hOFF,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ╰───────────────────────────────────┤ ├────────────────────────────────────╯
                      hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF
  //               ╰─────────────────────╯ ╰──────────────╯
  ),
  [LAYER_MACROPAD] = LAYOUT_wrapper(
  // ╭───────────────────────────────────╮ ╭────────────────────────────────────╮
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ╰───────────────────────────────────┤ ├────────────────────────────────────╯
                      hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF
  //               ╰─────────────────────╯ ╰──────────────╯
  ),
};
// clang-format off
#endif

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case THUML1:
        case THUML2:
        case THUML3:
        case THUMR1:
        case THUMR2:
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    if(IS_LAYER_ON(LAYER_POINTER)) {
        return 0;
    } else {
        switch(tap_hold_keycode) {
            case THUML1:
            case THUML2:
            case THUML3:
            case THUMR1:
            case THUMR2:
                return 0;
            default:
                return 600;
        }
    }
}

bool combo_should_trigger_km(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
        case game_rf_t:
        case game_fv_g:
            if (!layer_state_is(LAYER_GAME)) {
                return false;
            }
        case lsft:
        case rsft:
        case esc:
            if (!layer_state_is(LAYER_BASE)) {
                return false;
            }
    }

    return true;
}

#ifdef ENCODER_MAP_ENABLE
// clang-format off
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LAYER_BASE]       = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_FUN]        = {ENCODER_CCW_CW(KC_LEFT, KC_RGHT)},
    [LAYER_NAV]        = {ENCODER_CCW_CW(KC_UP, KC_DOWN)},
    [LAYER_POINTER]    = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [LAYER_NUM]        = {ENCODER_CCW_CW(RGB_SPD, RGB_SPI)},
    [LAYER_SYM]        = {ENCODER_CCW_CW(KC_LEFT, KC_RGHT)},
    [LAYER_GAME]       = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_MACROPAD]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};
// clang-format on
#endif // ENCODER_MAP_ENABLE

bool is_custom_rgb_indicator(uint8_t index) {
    return HAS_FLAGS(g_led_config.flags[index], LED_FLAG_INDICATOR);
}

#ifdef MACCEL_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    return pointing_device_task_maccel(mouse_report);
}
#endif

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
#ifdef MACCEL_ENABLE
    if (!process_record_maccel(keycode, record, MA_TAKEOFF, MA_GROWTH_RATE, MA_OFFSET, MA_LIMIT)) {
        return false;
    }
    switch (keycode) {
        case MA_TOGG:
            if (record->event.pressed) {
                maccel_toggle_enabled();
                return false;
            }
    }
#endif
    return true;
}

const HSV hsv_colors[] = {
    // clang-format off
    [ hOFF] = {  0,   0,   0},
    [hPRPL] = {205, 255, 255},
    [hDPRP] = {205, 255, 150},
    [hPINK] = {251, 223, 255},
    [hDPNK] = {251, 223, 155},
    [hCYAN] = {128, 255, 255},
    [hLRED] = {255, 239, 255},
    [hBLUE] = {170, 215, 221},
    [hORNG] = { 20, 208, 255},
    [ hRED] = {  0, 255, 255},
    [hMGTA] = {220, 255, 255},
    [hYELO] = { 15, 255, 255},
    [hGREN] = { 50, 255, 255},
    [hDMGT] = {205, 196, 140}
    // clang-format on
};
