#include "maccel.h"
#include "quantum.h"
#include "math.h"

static uint32_t maccel_timer;

static float maccel_a = MACCEL_STEEPNESS;
static float maccel_b = MACCEL_OFFSET;
static float maccel_c = MACCEL_LIMIT;

// wip: tell a user to insert the shim themselves instead of using _user here
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    return pointing_device_task_maccel(mouse_report);
}

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
