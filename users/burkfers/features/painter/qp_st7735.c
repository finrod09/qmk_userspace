#include <qp.h>
#include "config.h"
#include "fonts.qff.h"
#include "burkfers.h"

static painter_device_t      display;
static painter_font_handle_t font;

void keyboard_post_init_painter(void) {
    display = qp_st7735_make_spi_device(

        80,              // panel_width
        160,             // panel_height
        LCD_CS_PIN,      // chip_select_pin,
        LCD_DC_PIN,      // dc_pin
        LCD_RESET_PIN,   // reset_pin
        LCD_SPI_DIVISOR, // spi_divisor
        LCD_SPI_MODE     // spi_mode
    );
    qp_init(display, QP_ROTATION_270); // Initialise the display
    font = qp_load_font_mem(ubuntu_mono_font);

    static const char *text = "Hello therea!";
    qp_drawtext(display, 10, 10, font, text);
}

static bool _bl_on;

void toggle_backlight(void) {
    _bl_on = !_bl_on;

    printf("backligh: %u\n", _bl_on);
    writePin(LCD_BL_PIN, _bl_on);
}

bool process_record_painter(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case PT_BL:
                dprintf("toggling backlight!\n");
                toggle_backlight();
                return false;
        }
    }
    return true;
}
