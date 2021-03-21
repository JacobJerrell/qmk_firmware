USE_V2 = no
 
ifeq ($(strip $(USE_V2)), yes)
	-include $(KEYMAP_PATH)/v2/rules.mk
else
	-include $(KEYMAP_PATH)/v1/rules.mk
endif