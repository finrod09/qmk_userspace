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
#define CHARYBDIS_MINIMUM_DEFAULT_DPI 400
#define CHARYBDIS_DEFAULT_DPI_CONFIG_STEP 100
#define CHARYBDIS_MINIMUM_SNIPING_DPI 50
#define CHARYBDIS_SNIPING_DPI_CONFIG_STEP 10

#define CHARYBDIS_CONFIG_SYNC

#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_ACTIVITY_ENABLE

#define SPLIT_HAND_PIN GP15
#define SPLIT_HAND_PIN_LOW_IS_LEFT
#define USB_VBUS_PIN GP19

#define MOUSE_EXENDED_REPORT
#undef POINTING_DEVICE_TASK_THROTTLE_MS
#define POINTING_DEVICE_TASK_THROTTLE_MS 5

#define MACCEL_STEEPNESS 0.8 // steepness of accel curve
#define MACCEL_OFFSET 1.1    // X-offset of accel curve
#define MACCEL_LIMIT 4.5     // maximum scale factor
#define MACCEL_DEBUG
