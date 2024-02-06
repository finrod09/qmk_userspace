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
#include "maccel.h"
#include "quantum.h"
#include "math.h"

static uint32_t maccel_timer;

#ifndef MACCEL_STEEPNESS
#define MACCEL_STEEPNESS 0.6 // steepness of accel curve
#endif
#ifndef MACCEL_OFFSET
#define MACCEL_OFFSET 0.8    // X-offset of accel curve
#endif
#ifndef MACCEL_LIMIT
#define MACCEL_LIMIT 3.5     // maximum scale factor
#endif

const float maccel_a = MACCEL_STEEPNESS;
const float maccel_b = MACCEL_OFFSET;
const float maccel_c = MACCEL_LIMIT;

// Clamp a value to the maximum report size to prevent over- and underflows
static inline mouse_xy_report_t clamp_to_report(float val) {
    if (val < XY_REPORT_MIN) {
        return XY_REPORT_MIN;
    } else if (val > XY_REPORT_MAX) {
        return XY_REPORT_MAX;
    } else {
        return val;
    }
}

report_mouse_t pointing_device_task_maccel(report_mouse_t mouse_report) {
    if (mouse_report.x != 0 || mouse_report.y != 0) {
        // Credit: @wimads
        const float speed        = (sqrtf(mouse_report.x * mouse_report.x + mouse_report.y * mouse_report.y)) / timer_elapsed32(maccel_timer);
        float       scale_factor = maccel_c - (maccel_c - 1) * expf(-1 * (speed - maccel_b) * maccel_a);
        if (scale_factor <= 1) {
            scale_factor = 1;
        }
        const float x = (mouse_report.x * scale_factor);
        const float y = (mouse_report.y * scale_factor);
        maccel_timer  = timer_read32();

#ifdef MACCEL_DEBUG
        printf("maccel: x: %i, y: %i, speed %f -> factor %f; x': %3f, y': %3f\n", mouse_report.x, mouse_report.y, speed, scale_factor, x, y);
#endif

        mouse_report.x = clamp_to_report(x);
        mouse_report.y = clamp_to_report(y);
    }
    return mouse_report;
}
