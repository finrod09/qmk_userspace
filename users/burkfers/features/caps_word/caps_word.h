#pragma once

#include "action.h"

bool caps_word_lock_on;

void caps_word_lock_enable(void);
void caps_word_lock_disable(void);
void process_caps_word_lock(uint16_t keycode, const keyrecord_t *record);
