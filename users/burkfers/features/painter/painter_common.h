#pragma once

#include "qp.h"

#ifdef QP_ST7735_ENABLE
#    include "qp_st7735.h"
#endif

#define QP_THROTTLE 5

#ifndef TFT_TIMEOUT
#    ifdef RGB_MATRIX_TIMEOUT
#        define TFT_TIMEOUT RGB_MATRIX_TIMEOUT
#    else
#        define TFT_TIMEOUT 120000
#    endif
#endif

painter_device_t      qp_display;
painter_font_handle_t qp_font;

void keyboard_post_init_painter(void);
void housekeeping_task_painter(void);

extern const char* layer_to_string[];

void render_layer_name(uint16_t x, uint16_t y);
void render_mods(uint16_t x, uint16_t y);
void render_mods_right(uint16_t x, uint16_t y);
