// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include QMK_KEYBOARD_H

#ifdef TAP_DANCE_ENABLE
#    include "features/taps/tap_dances.h"
#endif

#ifdef COMBO_ENABLE
#    include "features/combos/config.h"
#endif
