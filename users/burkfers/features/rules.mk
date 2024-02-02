SRC += $(USER_PATH)/features/taps/tap_dances.c \
       $(USER_PATH)/features/caps_word/caps_word.c \
       $(USER_PATH)/features/layer_lock/layer_lock.c

SRC += $(USER_PATH)/features/achordion/achordion.c \
       $(USER_PATH)/features/achordion/achordion_callbacks.c \


ifeq ($(strip $(LEDMAP_ENABLE)), yes)
	SRC += $(USER_PATH)/features/rgb/rgb.c
	OPT_DEFS += -DLEDMAP_ENABLE
endif


ifeq ($(strip $(LEADER_ENABLE)), yes)
	SRC += $(USER_PATH)/features/leader/leader.c
	OPT_DEFS += -DLEADER_ENABLE
endif
