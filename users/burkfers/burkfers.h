#pragma once

#include "quantum.h"
#include "features/features.h"

enum my_user_keycodes {
    C_LT = QK_USER, // CUSTOM_LAYERTOGGLE
    CAPS_WORD_LOCK,
    L_LOCK,
    QK_KM
};

enum user_layers {
    LAYER_BASE = 0,
    LAYER_BASE2,
    LAYER_BASE3,
    LAYER_GAME,
    LAYER_NUM,
    LAYER_NAV,
    LAYER_FUN,
    LAYER_MEDIA,
    LAYER_SYM,
    LAYER_POINTER,
    LAYER_KM
};

#define DOTCOMM LT(24, KC_DOT)

#ifdef RGB_MATRIX_ENABLE
enum colors {
    hOFF = 0,
    hPRPL,
    hDPRP,
    hPINK,
    hDPNK,
    hCYAN,
    hLRED,
    hBLUE,
    hORNG,
    hRED,
    hMGTA,
    hYELO,
    hGREN,
};
extern const uint8_t PROGMEM ledmaps[][MATRIX_ROWS][MATRIX_COLS];
#endif

#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)
#define HOME_J RSFT_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)
#define RALT_W RALT_T(KC_W)
#define RALT_O RALT_T(KC_O)
