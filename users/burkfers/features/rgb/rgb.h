#pragma once

#include "color.h"
#include "progmem.h"

enum colors {
    hOFF = 0,
    hPRPL,
    hDPRP,
    hPINK,
    hDPNK,
    hCYAN,
    hLRED,
    hBLUE,
    hORNG,
    hRED,
    hMGTA,
    hDMGT,
    hYELO,
    hGREN,
};

extern const HSV hsv_colors[];

extern const uint8_t PROGMEM ledmaps[][MATRIX_ROWS][MATRIX_COLS];

bool rgb_matrix_indicators_advanced_user(uint8_t, uint8_t);
