// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include QMK_KEYBOARD_H

#ifdef TAP_DANCE_ENABLE
#    include "features/taps/tap_dances.h"
#endif

#ifdef RGB_MATRIX_ENABLE
#  ifdef LEDMAP_ENABLE
#    include "features/rgb/rgb.h"
#  endif
#endif

#include "features/caps_word/caps_word.h"

#include "features/achordion/achordion.h"

#include "features/layer_lock/layer_lock.h"

#ifdef LEADER_ENABLE
    #include "features/leader/leader.h"
#endif
