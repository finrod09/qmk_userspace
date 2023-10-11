SRC += $(USER_PATH)/features/taps/tap_dances.c \
       $(USER_PATH)/features/rgb/rgb.c \
       $(USER_PATH)/features/caps_word/caps_word.c \
       $(USER_PATH)/features/layer_lock/layer_lock.c

#ifeq ($(strip $(COMBO_ENABLE)), yes)
	VPATH += keyboards/gboards
	INTROSPECTION_KEYMAP_C = $(USER_PATH)/features/combos/combos.c
#endif

SRC += $(USER_PATH)/features/achordion/achordion.c \
       $(USER_PATH)/features/achordion/achordion_callbacks.c \
