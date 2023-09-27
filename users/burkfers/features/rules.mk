SRC += $(USER_PATH)/features/taps/tap_dances.c

#ifeq ($(strip $(COMBO_ENABLE)), yes)
	VPATH += keyboards/gboards
	INTROSPECTION_KEYMAP_C = $(USER_PATH)/features/combos/combos.c
#endif
