#define TAPPING_TERM 200
#define PERMISSIVE_HOLD
#define QUICK_TAP_TERM_PER_KEY

#define ENABLE_COMPILE_KEYCODE

#define TAP_CODE_DELAY 17

#include "features/config.h"

#ifdef POINTING_DEVICE_ENABLE
#    ifdef MACCEL_ENABLE
#        define MACCEL_DEBUG
#        define MACCEL_USE_KEYCODES
#        define EECONFIG_USER_DATA_SIZE 20
#        undef PRINTF_SUPPORT_DECIMAL_SPECIFIERS
#        define PRINTF_SUPPORT_DECIMAL_SPECIFIERS 1
#    endif
#    define MOUSE_EXTENDED_REPORT
#endif
