// TODO header

// todo: how to include

#pragma once
#include "quantum.h"

#define MACCEL_STEEPNESS 0.6    // steepness of accel curve
#define MACCEL_OFFSET 0.8 // X-offset of accel curve
#define MACCEL_LIMIT 3.5  // maximum scale factor

/*
 * Requires enabling float support for printf!
 *
 * #undef PRINTF_SUPPORT_DECIMAL_SPECIFIERS
 * #define PRINTF_SUPPORT_DECIMAL_SPECIFIERS 1
 */
#define MACCEL_DEBUG

/*
 * Accumulate fractions of mouse movement resulting from scaling, prevents cursor stall at low speeds
 */
#define MACCEL_ACCUM

report_mouse_t pointing_device_task_maccel(report_mouse_t mouse_report);
