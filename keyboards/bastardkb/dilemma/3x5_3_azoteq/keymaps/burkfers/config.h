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
#pragma once

/* Charybdis-specific features. */
#define DILEMMA_MINIMUM_DEFAULT_DPI 500
#define DILEMMA_DEFAULT_DPI_CONFIG_STEP 100
#define DILEMMA_MINIMUM_SNIPING_DPI 100
#define DILEMMA_SNIPING_DPI_CONFIG_STEP 100

#define DILEMMA_CONFIG_SYNC

#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_ACTIVITY_ENABLE

#undef RGB_MATRIX_DEFAULT_MODE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS

#define RGB_MATRIX_DEFAULT_HUE 200

#define DYNAMIC_KEYMAP_LAYER_COUNT 12

#define AZOTEQ_IQS5XX_PRESS_AND_HOLD_ENABLE true

#define ONESHOT_TAP_TOGGLE 5 /* Tapping this number of times holds the key until tapped once again. */

#undef POINTING_DEVICE_TASK_THROTTLE_MS
#define POINTING_DEVICE_TASK_THROTTLE_MS 2

#define POINTING_DEVICE_DEBUG

#define SELECT_SOFT_SERIAL_SPEED 4
// #define SERIAL_DEBUG

#define MACCEL_LIMIT 0.5

#define RGB_MATRIX_TIMEOUT 60000
