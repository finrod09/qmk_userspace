#include "quantum.h"
#include "oled_assets.h"

bool oled_task_user(void) {
    oled_set_brightness(127);

    oled_write_ln_P(PSTR("Untitled Pieboard"), false);

    oled_set_cursor(0,1);
    oled_write_raw_P(smallbird_image_L1, sizeof(smallbird_image_L1));
    oled_set_cursor(0,2);
    oled_write_raw_P(smallbird_image_L2, sizeof(smallbird_image_L2));

    
    return true;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}
