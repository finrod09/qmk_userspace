#pragma once

#include "keycodes.h"
#include "features/features.h" // IWYU pragma: keep

enum my_user_keycodes {
    C_LT = QK_USER, // CUSTOM_LAYERTOGGLE
    CAPS_WORD_LOCK,
    L_LOCK,
#ifdef MACCEL_ENABLE
    MA_TOGGLE,
    MA_TAKEOFF,
    MA_GROWTH_RATE,
    MA_OFFSET,
    MA_LIMIT,
    MA_TOGG,
#endif // MACCEL_ENABLE
    KC_LAYER_BASE,
    KC_LAYER_BASE2,
    KC_LAYER_BASE3,
    QK_KM
};

#ifdef MACCEL_ENABLE
#    define MA_TOG MA_TOGGLE
#    define MA_TKO MA_TAKEOFF
#    define MA_GRO MA_GROWTH_RATE
#    define MA_OFS MA_OFFSET
#    define MA_LMT MA_LIMIT
#else
#    define MA_TOG KC_NO
#    define MA_TKO KC_NO
#    define MA_GRO KC_NO
#    define MA_OFS KC_NO
#    define MA_LMT KC_NO
#endif

enum user_layers {
    // clang-format off
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
    // clang-format on
};

#define DOTCOMM LT(24, KC_DOT)

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
