#pragma once

#ifndef SCREEN_HEIGHT
#    define SCREEN_HEIGHT 80
#endif
#ifndef SCREEN_WIDTH
#    define SCREEN_WIDTH 160
#endif

void keyboard_post_init_painter_device(void);
bool housekeeping_task_painter_device(void);

void tft_off(void);
void tft_on(void);
