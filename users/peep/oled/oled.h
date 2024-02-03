void oled_inc_brightness(bool reverse);

void oled_whatisthis(void);

bool  oled_whatisthis_keypress(uint16_t keycode, uint8_t mods);
char* keycode_to_string(uint16_t keycode, uint8_t mods);

void should_clear_oled(void);
