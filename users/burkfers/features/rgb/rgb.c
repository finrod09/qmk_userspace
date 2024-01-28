#include "burkfers.h"

const HSV hsv_colors[] = {
    [ hOFF]     = {  0,   0,   0},
    [hPRPL]     = {205, 255, 255},
    [hDPRP]     = {205, 255, 150},
    [hPINK]     = {251, 223, 255},
    [hDPNK]     = {251, 223, 155},
    [hCYAN]     = {128, 255, 255},
    [hLRED]     = {255, 239, 255},
    [hBLUE]     = {170, 215, 221},
    [hORNG]     = { 20, 208, 255},
    [ hRED]     = {  0, 255, 255},
    [hMGTA]     = {220, 255, 255},
    [hYELO]     = { 15, 255, 255},
    [hGREN]     = { 50, 255, 255},
};

__attribute__((weak)) bool is_custom_rgb_indicator(uint8_t index) {
    return (index == 12 || index == 13 || index == 14 || index == 30 || index == 31 || index == 32);
}
__attribute__((weak)) bool rgb_matrix_indicators_advanced_km(uint8_t led_min, uint8_t led_max) {
    return false;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
        int layer = get_highest_layer(layer_state|default_layer_state);
        bool caps_lock_on = host_keyboard_led_state().caps_lock;

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for(uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if(led_min <= index && index <= led_max) {
                    if(caps_lock_on && is_custom_rgb_indicator(index)) {
                        rgb_matrix_set_color(index, 223, 3, 252);
                    } else {
                        uint8_t color = pgm_read_byte(&ledmaps[layer][row][col]);
                        HSV hsv = hsv_colors[color];
                        if(hsv.s > 0)
                            hsv.v = rgb_matrix_config.hsv.v;
                        RGB rgb = hsv_to_rgb(hsv);
                        rgb_matrix_set_color( index, rgb.r, rgb.g, rgb.b );
                    }
                };
            };
        };
    return rgb_matrix_indicators_advanced_km(led_min, led_max);
}
