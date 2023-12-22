#include "quantum.h"
#include "oled_assets.h"

bool oled_task_user(void) {
    oled_write_ln_P(PSTR("Untitled Pieboard"), false);

    oled_set_cursor(0,1);
    oled_write_raw_P(smallbird_image, sizeof(smallbird_image));

    
    return false;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}
