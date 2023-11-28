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
#include "charybdis.h"
#include "keycodes.h"
#include "modifiers.h"
#include "quantum.h"
#include QMK_KEYBOARD_H
#include "burkfers.h"
#include "keymap_german.h"

#define TD_BOOT TD(U_TD_BOOT)
#define TD_CLR TD(U_TD_CLR)
#define TD_MAKR TD(U_TD_MAKER)
#define TD_MAKL TD(U_TD_MAKEL)
#define TD_SYSR TD(U_TD_SYSRQ)

#define ESC_MEDIA LT(LAYER_MEDIA, KC_ESC)
#define SS_RAIS LT(LAYER_RAISE, DE_SS)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_QWERTY] = LAYOUT(
  // ╭───────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────────╮
      ESC_MEDIA,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,     KC_8,    KC_9,      KC_0, SS_RAIS,
  // ├───────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────┤
        KC_LGUI,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        DE_Z,    KC_U,     KC_I,    KC_O,      KC_P, DE_ADIA,
  // ├───────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────┤
        KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,     KC_K,    KC_L,   DE_ODIA, DE_UDIA,
  // ├───────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────┤
        KC_LCTL,    DE_Y,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,  KC_COMM,  KC_DOT,   DE_MINS, KC_LALT,
  // ╰───────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────╯
                                    KC_ENT,  KC_SPC, KC_LSFT,     KC_BSPC, KC_RSFT,
                             LT(LAYER_RAISE,KC_TAB), KC_RALT,      KC_DEL
  //               ╰─────────────────────────────────────────╯ ╰──────────────────────────╯
  ),

    [LAYER_RAISE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       DE_CIRC, KC_HOME, XXXXXXX,   KC_UP, XXXXXXX, KC_PGUP,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DE_ACUT, DE_PLUS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MPLY,  KC_END, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DE_HASH,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MPRV, XXXXXXX, XXXXXXX, XXXXXXX, TD_BOOT, TD_MAKL,    TD_MAKR, TD_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, _______,    _______, _______,
                                           _______, _______,    _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [LAYER_MEDIA] = LAYOUT(
  // ╭──────────────────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_F12,      KC_F1,      KC_F2,      KC_F3,      KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       TD_SYSR,    KC_ALGR,    XXXXXXX,    XXXXXXX,    XXXXXXX, KC_MNXT,    RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG, XXXXXXX,
  // ├──────────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX,    KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT, KC_MPLY,    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______, XXXXXXX,
  // ├──────────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       TD_BOOT,     TD_CLR,    TD_MAKL,    XXXXXXX,    XXXXXXX, KC_MPRV,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                           XXXXXXX,    XXXXXXX, XXXXXXX,    KC_MSTP, KC_MPLY,
                                                       XXXXXXX, XXXXXXX,    KC_MUTE
  //                                  ╰─────────────────────────────────╯ ╰──────────────────╯
  )
};
// clang-format on

#ifdef RGB_MATRIX_ENABLE
// clang-format off
const uint8_t PROGMEM ledmaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_QWERTY] = LAYOUT(
  // ╭──────────────────────────────────────────╮ ╭───────────────────────────────────────────╮
       hDPNK, hDPNK, hDPNK, hDPNK, hDPNK, hDPNK,    hDPNK, hDPNK, hDPNK, hDPNK, hDPNK, hDPNK,
  // ├──────────────────────────────────────────┤ ├───────────────────────────────────────────┤
       hDPNK, hDPRP, hDPRP, hDPRP, hDPRP, hDPRP,    hDPRP, hDPRP, hDPRP, hDPRP, hDPRP, hDPNK,
  // ├───────-──────────────────────────────────┤ ├───────────────────────────────────────────┤
       hDPNK, hDPRP, hDPRP, hDPRP, hDPRP, hDPRP,    hDPRP, hDPRP, hDPRP, hDPRP, hDPRP, hDPNK,
  // ├──────────────────────────────────────────┤ ├───────────────────────────────────────────┤
       hDPNK, hDPRP, hDPRP, hDPRP, hDPRP, hDPRP,    hDPRP, hDPRP, hDPRP, hDPRP, hDPRP, hDPNK,
  // ╰──────────────────────────────────────────┤ ├───────────────────────────────────────────╯
                            hMGTA, hCYAN, hYELO,    hBLUE, hGREN,
                                    hOFF,  hOFF,    hLRED
  //                      ╰─────────────────────╯ ╰──────────────╯
  ),
  [LAYER_RAISE] = LAYOUT(
  // ╭──────────────────────────────────────────╮ ╭───────────────────────────────────────────╮
       hLRED, hLRED, hLRED, hLRED, hLRED, hLRED,    hLRED, hLRED, hLRED, hLRED, hLRED, hLRED,
  // ├──────────────────────────────────────────┤ ├───────────────────────────────────────────┤
        hOFF,  hOFF,  hOFF, hBLUE,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ├───────-──────────────────────────────────┤ ├───────────────────────────────────────────┤
        hOFF,  hOFF, hBLUE, hBLUE, hBLUE,  hOFF,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ├──────────────────────────────────────────┤ ├───────────────────────────────────────────┤
        hOFF,  hOFF,  hOFF,  hOFF,  hRED,  hRED,     hRED,  hRED,  hOFF,  hOFF,  hOFF,  hOFF,
  // ╰──────────────────────────────────────────┤ ├───────────────────────────────────────────╯
                             hOFF,  hOFF,  hOFF,     hOFF,  hOFF,
                                    hOFF,  hOFF,     hOFF
  //                      ╰─────────────────────╯ ╰──────────────╯
  ),
  [LAYER_MEDIA] = LAYOUT(
  // ╭──────────────────────────────────────────╮ ╭───────────────────────────────────────────╮
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ├──────────────────────────────────────────┤ ├───────────────────────────────────────────┤
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ├───────-──────────────────────────────────┤ ├───────────────────────────────────────────┤
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,  hOFF,    hMGTA, hMGTA, hMGTA, hMGTA,  hOFF,  hOFF,
  // ├──────────────────────────────────────────┤ ├───────────────────────────────────────────┤
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ╰──────────────────────────────────────────┤ ├───────────────────────────────────────────╯
                             hOFF,  hOFF,  hOFF,    hMGTA, hMGTA,
                                    hOFF,  hOFF,    hMGTA
  //                      ╰─────────────────────╯ ╰──────────────╯
  ),
  [LAYER_GAME] = LAYOUT(
  // ╭──────────────────────────────────────────╮ ╭───────────────────────────────────────────╮
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ├──────────────────────────────────────────┤ ├───────────────────────────────────────────┤
        hOFF,  hOFF,  hOFF, hPRPL,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
  // ├───────-──────────────────────────────────┤ ├───────────────────────────────────────────┤
        hOFF,  hOFF, hPRPL, hPRPL, hPRPL,  hOFF,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF, hCYAN,
  // ├──────────────────────────────────────────┤ ├───────────────────────────────────────────┤
        hOFF,  hOFF,  hOFF,  hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF, hCYAN,
  // ╰──────────────────────────────────────────┤ ├───────────────────────────────────────────╯
                             hOFF,  hOFF,  hOFF,     hOFF,  hOFF,
                                    hOFF,  hOFF,     hOFF
  //                      ╰─────────────────────╯ ╰──────────────╯
  ),
};
// clang-format on

#endif
