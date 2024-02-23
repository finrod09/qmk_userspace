/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 * Copyright 2023 casuanoob <casuanoob@hotmail.com> (@casuanoob)
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
#pragma once

#define DYNAMIC_KEYMAP_LAYER_COUNT 8

/* Mouse acceleration */
#define MACCEL_STEEPNESS 1.0 // steepness of accel curve
#define MACCEL_OFFSET 1.0    // X-offset of accel curve
#define MACCEL_LIMIT 6.0     // maximum scale factor
#define MACCEL_DEBUG
#define MACCEL_USE_KEYCODES
#define EECONFIG_USER_DATA_SIZE 20
#undef POINTING_DEVICE_TASK_THROTTLE_MS
#define POINTING_DEVICE_TASK_THROTTLE_MS 10
#define MOUSE_EXTENDED_REPORT
#undef PRINTF_SUPPORT_DECIMAL_SPECIFIERS
#define PRINTF_SUPPORT_DECIMAL_SPECIFIERS 1

#define DILEMMA_MINIMUM_DEFAULT_DPI 200
#define DILEMMA_DEFAULT_DPI_CONFIG_STEP 100
#define DILEMMA_MINIMUM_SNIPING_DPI 100
#define DILEMMA_SNIPING_DPI_CONFIG_STEP 100
