#include <qp.h>
#include "config.h"
#include "fonts.qff.h"
#include "burkfers.h"

#include "hack11.qff.h"

static painter_device_t      display;
static painter_font_handle_t font;

#ifndef TFT_TIMEOUT
#    define TFT_TIMEOUT 120000
#endif

void keyboard_post_init_painter(void) {
    if (is_keyboard_left()) {
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
        font = qp_load_font_mem(font_hack11);

        qp_rect(display, 0, 0, 160, 81, 255, 0, 255, true);

        for (int i = 0; i <= 80; i++) {
            qp_rect(display, 0, i, 10, i+1, (uint8_t)(255.0f/80.0f*i), 255, 255, true);
        }
        static const char *text = "Hello there!";
        qp_drawtext(display, 20, 10, font, text);

        setPinOutput(LCD_BL_PIN);
    }
}

static bool _tft_bl_on = false;

void tft_off(void) {
    if (_tft_bl_on) {
        qp_power(display, false);
        writePinLow(LCD_BL_PIN);
        _tft_bl_on = false;
        dprintf("tft now off!\n");
    }
}
void tft_on(void) {
    if (!_tft_bl_on) {
        qp_power(display, true);
        writePinHigh(LCD_BL_PIN);
        _tft_bl_on = true;
        dprintf("tft now on!\n");
    }
}

void housekeeping_task_painter(void) {
#if TFT_TIMEOUT > 0
    /* the animation prevents the normal timeout from occuring */
    if (last_input_activity_elapsed() > TFT_TIMEOUT && last_led_activity_elapsed() > TFT_TIMEOUT) {
        tft_off();
        return;
    } else {
        tft_on();
    }

#endif
}
