// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include QMK_KEYBOARD_H // IWYU pragma: keep

#ifdef TAP_DANCE_ENABLE
#    include "features/taps/tap_dances.h" // IWYU pragma: keep
#endif

#ifdef RGB_MATRIX_ENABLE
#    ifdef LEDMAP_ENABLE
#        include "features/rgb/rgb.h" // IWYU pragma: keep
#    endif
#endif

#include "features/caps_word/caps_word.h" // IWYU pragma: keep

#ifdef ACHORDION_ENABLE
#    include "features/achordion/achordion.h" // IWYU pragma: keep
#endif

#include "features/layer_lock/layer_lock.h" // IWYU pragma: keep

#ifdef LEADER_ENABLE
#    include "features/leader/leader.h" // IWYU pragma: keep
#endif

#ifdef QP_ST7735_ENABLE
#    include "features/painter/qp_st7735.h" // IWYU pragma: keep
#endif
#ifdef PAINTER_ENABLE
#    include "features/painter/painter_common.h" // IWYU pragma: keep
#endif

#ifdef MACCEL_ENABLE
#    include "features/maccel/maccel.h" // IWYU pragma: keep
#endif
