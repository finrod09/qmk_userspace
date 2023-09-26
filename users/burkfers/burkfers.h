#pragma once

#include "quantum.h"

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_GAME,
    LAYER_NUM,
    LAYER_NAV,
    LAYER_FUN,
    LAYER_MEDIA,
    LAYER_SYM,
    LAYER_POINTER,
};

enum my_keycodes {
    C_LT = SAFE_RANGE, // CUSTOM_LAYERTOGGLE
};

enum {
   U_TD_BOOT = 0,
   U_TD_CLR,
   U_TD_PT_Z,
   U_TD_PT_SLSH,
#ifdef EE_HANDS
   U_TD_MAKER,
   U_TD_MAKEL,
#else
   U_TD_MAKE,
#endif
   U_TD_SYSRQ,
};

#define DOTCOMM LT(10, KC_DOT)


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
