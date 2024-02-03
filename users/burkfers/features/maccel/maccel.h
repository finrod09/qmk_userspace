// TODO header

// todo: how to include

#pragma once

#include "quantum.h"

#define MACCEL_CURVE_A 7    //steepness of accel curve
#define MACCEL_CURVE_B 0.05 //X-offset of accel curve
#define MACCEL_CURVE_C 0.3  //Y-offset of accel curve
#define MACCEL_CURVE_D .1   //speed scaling factor

/* Requires enabling float support for printf!
 *
 * #undef PRINTF_SUPPORT_DECIMAL_SPECIFIERS
 * #define PRINTF_SUPPORT_DECIMAL_SPECIFIERS 1
 */
#define MACCEL_DEBUG

/* Accumulate fractions of mouse movement resulting from scaling, prevents cursor stall at low speeds */
#define MACCEL_ACCUM

#define MACCEL_HISTORY_TIME 100 // milliseconds of history to keep

report_mouse_t pointing_device_task_maccel(report_mouse_t mouse_report);

uint16_t reports_added = 0;
uint16_t reports_freed = 0;
