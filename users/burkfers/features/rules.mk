SRC += $(USER_PATH)/features/taps/tap_dances.c \
       $(USER_PATH)/features/caps_word/caps_word.c \
       $(USER_PATH)/features/layer_lock/layer_lock.c


ifeq ($(strip $(ACHORDION_ENABLE)), yes)
	SRC += $(USER_PATH)/features/achordion/achordion.c 
	SRC += $(USER_PATH)/features/achordion/achordion_callbacks.c
	OPT_DEFS += -DACHORDION_ENABLE
endif


ifeq ($(strip $(LEDMAP_ENABLE)), yes)
	SRC += $(USER_PATH)/features/rgb/rgb.c
	OPT_DEFS += -DLEDMAP_ENABLE
endif


ifeq ($(strip $(LEADER_ENABLE)), yes)
	SRC += $(USER_PATH)/features/leader/leader.c
	OPT_DEFS += -DLEADER_ENABLE
endif

ifeq ($(strip $(MACCEL_ENABLE)), yes)
	-include $(USER_PATH)/features/maccel/rules.mk
endif

ifeq ($(strip $(QP_ST7735_ENABLE)), yes)
	include $(USER_PATH)/features/painter/rules.mk
	OPT_DEFS += -DQP_ST7735_ENABLE
endif
