#include "painter_common.h"
#include <stdint.h>
#include "burkfers.h"
#include "features/painter/qp_st7735.h"
#include "qp.h"

static uint32_t painter_timer;

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

    if (timer_elapsed32(painter_timer) > QP_THROTTLE) {
        if (!housekeeping_task_painter_device()) {
            return;
        }
        painter_timer = timer_read32();

        render_layer_name(15, SCREEN_HEIGHT - (qp_font->line_height * 2) - 2);

        render_mods_right(SCREEN_WIDTH, SCREEN_HEIGHT - (qp_font->line_height * 2) - 2);
    }
}

static const char* arrow = "> ";

void render_mods(uint16_t x, uint16_t y) {
    static uint8_t last_mods = UINT8_MAX;
    const uint8_t  mods      = get_mods();
    if (mods == last_mods) {
        return;
    }
    qp_rect(qp_display, x, y, x + qp_textwidth(qp_font, "> GACS"), y + qp_font->line_height * 2, 255, 0, 255, true);
    qp_drawtext(qp_display, x, y, qp_font, " mods");
    qp_drawtext(qp_display, x, y + qp_font->line_height, qp_font, arrow);
    x = x + qp_textwidth(qp_font, arrow);
    if (mods & MOD_MASK_GUI) {
        qp_drawtext(qp_display, x, y + qp_font->line_height, qp_font, "G");
    }
    if (mods & MOD_MASK_ALT) {
        qp_drawtext(qp_display, x + qp_textwidth(qp_font, "G"), y + qp_font->line_height, qp_font, "A");
    }
    if (mods & MOD_MASK_CTRL) {
        qp_drawtext(qp_display, x + qp_textwidth(qp_font, "GA"), y + qp_font->line_height, qp_font, "C");
    }
    if (mods & MOD_MASK_SHIFT) {
        qp_drawtext(qp_display, x + qp_textwidth(qp_font, "GAC"), y + qp_font->line_height, qp_font, "S");
    }
    last_mods = mods;
}
void render_mods_right(uint16_t x, uint16_t y) {
    render_mods(x - qp_textwidth(qp_font, "> GACS"), y);
}

void render_layer_name(uint16_t x, uint16_t y) {
    static uint8_t last_highest_layer    = UINT8_MAX;
    uint8_t        current_highest_layer = get_highest_layer(layer_state);
    if (current_highest_layer == 0) {
        if (default_layer_state & 0) {
            current_highest_layer = 0;
        } else if (default_layer_state & 2) {
            current_highest_layer = 1;
        } else if (default_layer_state & 4) {
            current_highest_layer = 2;
        }
    }
    if (last_highest_layer == current_highest_layer) {
        return;
    }
    qp_rect(qp_display, x, y, x + qp_textwidth(qp_font, "> longlayer"), y + qp_font->line_height * 2, 255, 0, 255, true);
    qp_drawtext(qp_display, x, y, qp_font, " layer");
    qp_drawtext(qp_display, x, y + qp_font->line_height, qp_font, arrow);
    const char* layertext = layer_to_string[current_highest_layer];
    dprintf("%s\n", layertext);
    if (layertext != NULL) {
        qp_drawtext(qp_display, x + qp_textwidth(qp_font, arrow), y + qp_font->line_height, qp_font, layertext);
    }
    last_highest_layer = current_highest_layer;
}
