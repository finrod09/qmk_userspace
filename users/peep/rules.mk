SRC += $(USER_PATH)/peep.c



ifeq ($(strip $(OLED_ENABLE)), yes)
	SRC += $(USER_PATH)/oled/oled.c
endif
