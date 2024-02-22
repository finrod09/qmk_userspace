// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Define a type for as many tap dance states as you need
typedef enum { TD_NONE, TD_UNKNOWN, TD_SINGLE_TAP, TD_SINGLE_HOLD, TD_DOUBLE_TAP } td_state_t;

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

typedef struct {
    bool       is_press_action;
    td_state_t state;
} td_tap_t;

// Our custom TD keys
enum {
    U_TD_BOOT = 0,
    U_TD_CLR,
#ifdef EE_HANDS
    U_TD_MAKER,
    U_TD_MAKEL,
#else
    U_TD_MAKE,
#endif
    U_TD_SYSRQ,
    U_SLS_PT,
};
