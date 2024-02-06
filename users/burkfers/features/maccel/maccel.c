#include "maccel.h"
#include "quantum.h"
#include "math.h"

static uint32_t maccel_timer;

static float maccel_a = MACCEL_STEEPNESS;
static float maccel_b = MACCEL_OFFSET;
static float maccel_c = MACCEL_LIMIT;

static float maccel_accum_x = 0;
static float maccel_accum_y = 0;

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
        const float speed = (sqrtf(mouse_report.x*mouse_report.x + mouse_report.y*mouse_report.y))/timer_elapsed32(maccel_timer);
        float scale_factor = maccel_c-(maccel_c-1)*expf(-1*(speed-maccel_b) * maccel_a);
        if (scale_factor <= 1) {
            scale_factor = 1;
        }
        const float x = (mouse_report.x * scale_factor);
        const float y = (mouse_report.y * scale_factor);
        maccel_timer  = timer_read32();

#ifdef MACCEL_DEBUG
        // printf("maccel: a = %8f, b = %8f, speed = %4f -> scale_factor = %f\r\n", maccel_a, maccel_b, speed, scale_factor);
        printf("maccel: x: %i, y: %i, speed %f -> factor %f; x': %3f, y': %3f\n", mouse_report.x, mouse_report.y, speed, scale_factor, x, y);
#endif

#ifdef MACCEL_ACCUM

        // accumulate remaining fraction
        maccel_accum_x += (x - mouse_report.x);
        maccel_accum_y += (y - mouse_report.y);

        // pay out accumulated fraction once it's whole
        if (maccel_accum_x >= 1) {
            mouse_report.x += 1;
            maccel_accum_x -= 1;
        } else if (maccel_accum_x <= -1) {
            mouse_report.x -= 1;
            maccel_accum_x += 1;
        }
        if (maccel_accum_y >= 1) {
            mouse_report.y += 1;
            maccel_accum_y -= 1;
        } else if (maccel_accum_y <= -1) {
            mouse_report.y -= 1;
            maccel_accum_y += 1;
        }
#    ifdef MACCEL_DEBUG
        printf("maccel accum: x: %3f, y: %3f\n", maccel_accum_x, maccel_accum_y);
#    endif // MACCEL_ACCUM
#endif     // MACCEL_ACCUM
        mouse_report.x = clamp_to_report(x);
        mouse_report.y = clamp_to_report(y);
    }
    return mouse_report;
}
