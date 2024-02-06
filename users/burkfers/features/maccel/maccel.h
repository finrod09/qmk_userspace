/* Copyright 2024 burkfers (@burkfers)
 * Copyright 2023 Wimads (@wimads)
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

#include "quantum.h"

#define MACCEL_STEEPNESS 0.6 // steepness of accel curve
#define MACCEL_OFFSET 0.8    // X-offset of accel curve
#define MACCEL_LIMIT 3.5     // maximum scale factor

/*
 * Requires enabling float support for printf!
 *
 * #undef PRINTF_SUPPORT_DECIMAL_SPECIFIERS
 * #define PRINTF_SUPPORT_DECIMAL_SPECIFIERS 1
 */
#define MACCEL_DEBUG

report_mouse_t pointing_device_task_maccel(report_mouse_t mouse_report);
