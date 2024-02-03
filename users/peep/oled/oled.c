#include "quantum.h"
#include "oled_assets.h"
#include "oled.h"
#include "peep.h"
#include "keymap_german.h"

static uint8_t oled_brightness = 128;

#ifndef OLED_BRIGHTNESS_STEP
#    define OLED_BRIGHTNESS_STEP 64
#endif

static bool     whatisthis_enabled = false;
static uint16_t whatisthis_lastkc;
static uint8_t  whatisthis_lastmods;

static bool should_clear = false;

bool oled_task_user(void) {
    oled_set_brightness(oled_brightness);

    if (should_clear) {
        should_clear = false;
        oled_clear();
    }

    if (!whatisthis_enabled) {
        oled_write_ln_P(PSTR("Untitled Pieboard"), false);

        oled_set_cursor(0, 1);
        oled_write_raw_P(smallbird_image_L1, sizeof(smallbird_image_L1));
        oled_set_cursor(0, 2);
        oled_write_raw_P(smallbird_image_L2, sizeof(smallbird_image_L2));
        if (IS_LAYER_ON(LAYER_GAME)) {
            oled_set_cursor(0, 3);
            oled_write_ln_P(PSTR("Let's play a game!"), false);
        }
    } else {
        oled_set_cursor(0, 0);
        oled_write_raw_P(smallbird_image_L1, sizeof(smallbird_image_L1));
        oled_set_cursor(4, 0);
        if (whatisthis_lastkc == 0) {                                         // bird is first asked
            oled_write_ln_P(PSTR("What is this?"), false);                    // bird knows
            oled_set_cursor(0, 1);                                            // second line
            oled_write_raw_P(smallbird_image_L2, sizeof(smallbird_image_L2)); // bird bottom
        } else {
            char* str = keycode_to_string(whatisthis_lastkc, whatisthis_lastmods);

            if (str != NULL) {                                                    // known keycode
                oled_write_ln_P(PSTR("It's this!"), false);                       // bird knows
                oled_set_cursor(0, 1);                                            // second line
                oled_write_raw_P(smallbird_image_L2, sizeof(smallbird_image_L2)); // bird bottom
                oled_set_cursor(4, 1);                                            // second line fifth char
                oled_write_ln(str, false);                                        // write keycode text
            } else {
                oled_write_ln_P(PSTR("Huh?"), false);                             // bird doesn't know
                oled_set_cursor(0, 1);                                            // second line
                oled_write_raw_P(smallbird_image_L2, sizeof(smallbird_image_L2)); // bird bottom
                oled_set_cursor(4, 1);                                            // second line fifth char
                char* fmtstr = (char*)malloc(255 * sizeof(char));                 // allocate text buffer
                sprintf(fmtstr, "%u", whatisthis_lastkc);                         // print keycode num as str
                oled_write_ln(fmtstr, false);                                     // write out
                free(fmtstr);                                                     // cleanup!!
            }
        }
    }

    return true;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

void should_clear_oled(void) {
    should_clear = true;
}

void oled_inc_brightness(bool reverse) {
    if (!reverse) {
        oled_brightness += OLED_BRIGHTNESS_STEP;
    } else {
        oled_brightness -= OLED_BRIGHTNESS_STEP;
    }
}

void oled_whatisthis(void) {
    whatisthis_enabled = !whatisthis_enabled;
    oled_clear();
}

bool oled_whatisthis_keypress(uint16_t keycode, uint8_t mods) {
    if (keycode == KC_WHATISTHIS) {
        whatisthis_lastkc   = 0;
        whatisthis_lastmods = 0;
        return true;
    }
    whatisthis_lastkc   = keycode;
    whatisthis_lastmods = mods;
    return !whatisthis_enabled;
}

char* keycode_to_string(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_Q:
            return "q Q";
        case KC_W:
            return "r R";
        case KC_E:
            return "e E";
        case KC_R:
            return "r R";
        case KC_T:
            return "t T";
        case DE_Y:
            return "y Y";
        case KC_U:
            return "u U";
        case KC_I:
            return "i I";
        case KC_O:
            return "o O";
        case KC_P:
            return "p P";
        case KC_A:
            return "a A";
        case KC_S:
            return "s S";
        case KC_D:
            return "d D";
        case KC_F:
            return "f F";
        case KC_G:
            return "g G";
        case KC_H:
            return "h H";
        case KC_J:
            return "j J";
        case KC_K:
            return "k K";
        case KC_L:
            return "l L";
        case DE_Z:
            return "z Z";
        case KC_X:
            return "x X";
        case KC_C:
            return "c C";
        case KC_V:
            return "v V";
        case KC_B:
            return "b B";
        case KC_N:
            return "n N";
        case KC_M:
            return "m M";
        case KC_COMM:
            return ", ;";
        case KC_DOT:
            return ". :";
        case DE_MINS:
            return "- _";
        case DE_CIRC:
            return "^ °";
        case DE_LABK:
            return "< > |";

        case KC_1:
            return "1 !";
        case KC_2:
            return "2 \"";
        case KC_3:
            return "3 §";
        case KC_4:
            return "4 $";
        case KC_5:
            return "5 %";
        case KC_6:
            return "6 &";
        case KC_7:
            return "7 /";
        case KC_8:
            return "8 (";
        case KC_9:
            return "9 )";
        case KC_0:
            return "0 =";

        case KC_LSFT:
            return "Shift L";
        case KC_RSFT:
            return "Shift R";
        case KC_LCTL:
            return "Ctrl L";
        case KC_RCTL:
            return "Ctrl R";
        case KC_LALT:
            return "Alt";
        case KC_RALT:
            return "AltGr";
        case KC_ESC:
            return "Esc";
        case KC_TAB:
            return "Tab";
        case KC_BSPC:
            return "Backspace";
        case KC_ENT:
            return "Enter";
        case KC_DEL:
            return "Entf / Del";
        case KC_INS:
            return "Einfg / Ins";
        case KC_END:
            return "Ende";
        case KC_HOME:
            return "Pos1 / Home";

        case DE_SS:
            return "Sz ?";
        case DE_UDIA:
            return "ue Ue";
        case DE_ODIA:
            return "oe Oe";
        case DE_ADIA:
            return "ae Ae";
        case DE_HASH:
            return "# '";

        case KC_F1:
            return "F1";
        case KC_F2:
            return "F2";
        case KC_F3:
            return "F3";
        case KC_F4:
            return "F4";
        case KC_F5:
            return "F5";
        case KC_F6:
            return "F6";
        case KC_F7:
            return "F7";
        case KC_F8:
            return "F8";
        case KC_F9:
            return "F9";
        case KC_F10:
            return "F10";
        case KC_F11:
            return "F11";
        case KC_F12:
            return "F12";
    }

    return NULL;
}
