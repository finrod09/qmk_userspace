#include <qp.h>
#include "fonts.qff.h"
#include "painter_common.h"

#ifndef VIEWPORT_OFFSET_Y
#    define VIEWPORT_OFFSET_Y 25
#endif

void keyboard_post_init_painter(void) {
    if (is_keyboard_left()) {
        // make device
        qp_display = qp_st7735_make_spi_device(

            SCREEN_WIDTH, SCREEN_HEIGHT + VIEWPORT_OFFSET_Y, LCD_CS_PIN, LCD_DC_PIN, LCD_RESET_PIN, LCD_SPI_DIVISOR, LCD_SPI_MODE);

        // init with rotation
        qp_init(qp_display, QP_ROTATION_270); // Initialise the display

        // set offset: this device is actually taller and doesn't draw the top rows
        qp_set_viewport_offsets(qp_display, 0, VIEWPORT_OFFSET_Y);

        // blacken out the surface
        qp_rect(qp_display, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 255, 0, 255, true);

        // load font
        qp_font = qp_load_font_mem(font_hack11);

        // rainbows!
        for (int i = 0; i <= SCREEN_HEIGHT; i++) {
            qp_rect(qp_display, 0, i, 10, i + 1, (uint8_t)(255.0f / SCREEN_HEIGHT * i), 255, 255, true);
        }

        gpio_set_pin_output(LCD_BL_PIN);
    }
}

static bool _tft_bl_on = false;

void tft_off(void) {
    if (_tft_bl_on) {
        qp_power(qp_display, false);
        gpio_write_pin_low(LCD_BL_PIN);
        _tft_bl_on = false;
        dprintf("tft now off!\n");
    }
}
void tft_on(void) {
    if (!_tft_bl_on) {
        qp_power(qp_display, true);
        gpio_write_pin_high(LCD_BL_PIN);
        _tft_bl_on = true;
        dprintf("tft now on!\n");
    }
}

bool housekeeping_task_painter_device(void) {
    if (is_keyboard_left()) {
        return true;
    } else {
        return false;
    }
}
