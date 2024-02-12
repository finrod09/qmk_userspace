#include <qp.h>
#include "fonts.qff.h"

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

    //    qp_power(display, false);
    setPinOutput(LCD_BL_PIN);
    writePinHigh(LCD_BL_PIN);
}
