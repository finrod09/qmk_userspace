#include "maccel.h"
#include "quantum.h"
#include "math.h"
#include "print.h"

static uint32_t maccel_timer;

static float maccel_a = MACCEL_CURVE_A;
static float maccel_b = MACCEL_CURVE_B;
static float maccel_c = MACCEL_CURVE_C;
static float maccel_d = MACCEL_CURVE_D;

static float maccel_accum_x = 0;
static float maccel_accum_y = 0;

// wip: tell a user to insert the shim themselves instead of using _user here
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    return pointing_device_task_maccel(mouse_report);
}

report_mouse_t pointing_device_task_maccel(report_mouse_t mouse_report) {
    if(mouse_report.x != 0 || mouse_report.y != 0) {

        // Credit: @wimads
        const float speed = maccel_d*(sqrtf(mouse_report.x*mouse_report.x + mouse_report.y*mouse_report.y))/timer_elapsed32(maccel_timer);
        float scale_factor = 1-(1-maccel_c)*expf(-1*(speed-maccel_b) * maccel_a);
        if (speed <= maccel_b) {
            scale_factor = maccel_c;
        }
        const float x = (mouse_report.x * scale_factor);
        const float y = (mouse_report.y * scale_factor);
        maccel_timer = timer_read32();

#ifdef MACCEL_DEBUG
        // printf("maccel: a = %8f, b = %8f, speed = %4f -> scale_factor = %f\r\n", maccel_a, maccel_b, speed, scale_factor);
        printf("maccel: x: %i, y: %i, speed %f -> factor %f; x': %3f, y': %3f\n", mouse_report.x, mouse_report.y, speed, scale_factor, x, y);
#endif

#ifdef MACCEL_ACCUM
        // report the integer part
        mouse_report.x = (mouse_xy_report_t)x;
        mouse_report.y = (mouse_xy_report_t)y;

        // accumulate remaining fraction
        maccel_accum_x += (x - mouse_report.x);
        maccel_accum_y += (y - mouse_report.y);

        // pay out accumulated fraction once it's whole
        if(maccel_accum_x >= 1 ) {
            mouse_report.x += 1;
            maccel_accum_x -= 1;
        } else if (maccel_accum_x <= -1) {
            mouse_report.x -= 1;
            maccel_accum_x += 1;
        }
        if(maccel_accum_y >= 1 ) {
            mouse_report.y += 1;
            maccel_accum_y -= 1;
        } else if (maccel_accum_y <= -1) {
            mouse_report.y -= 1;
            maccel_accum_y += 1;
        }
#ifdef MACCEL_DEBUG
        printf("maccel accum: x: %3f, y: %3f\n", maccel_accum_x, maccel_accum_y);
#endif // MACCEL_ACCUM
        #endif // MACCEL_ACCUM

    }
    return mouse_report;
}
