#include "quantum.h"
#include "oled_assets.h"
#include "oled.h"

static uint8_t oled_brightness = 128;

#ifndef OLED_BRIGHTNESS_STEP
#   define OLED_BRIGHTNESS_STEP 64
#endif

static bool whatisthis_enabled = false;
static uint16_t whatisthis_lastkc;

bool oled_task_user(void) {
    oled_set_brightness(oled_brightness);

    if (!whatisthis_enabled) {
        oled_write_ln_P(PSTR("Untitled Pieboard"), false);

        oled_set_cursor(0,1);
        oled_write_raw_P(smallbird_image_L1, sizeof(smallbird_image_L1));
        oled_set_cursor(0,2);
        oled_write_raw_P(smallbird_image_L2, sizeof(smallbird_image_L2));
    } else {
        oled_set_cursor(0,0);
        oled_write_raw_P(smallbird_image_L1, sizeof(smallbird_image_L1));
        oled_set_cursor(4,0);
        oled_write_ln_P(PSTR("Huh?"), false);
        oled_set_cursor(0,1);
        oled_write_raw_P(smallbird_image_L2, sizeof(smallbird_image_L2));
        oled_set_cursor(4,1);
        oled_write_ln("kc goes here", false);
    }
    
    return true;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

void oled_inc_brightness(bool reverse) {
    if (!reverse) {
        oled_brightness += OLED_BRIGHTNESS_STEP;
    } else {
        oled_brightness -= OLED_BRIGHTNESS_STEP;
    }
}

void oled_whatisthis(void) {
    whatisthis_enabled = !whatisthis_enabled;
    oled_clear();
}

void oled_whatisthis_keypress(uint16_t keycode) {
    whatisthis_lastkc = keycode;
}
