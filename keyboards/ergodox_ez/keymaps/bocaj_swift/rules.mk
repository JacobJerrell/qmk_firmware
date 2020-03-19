LEADER_ENABLE = yes
KEY_LOCK_ENABLE = yes
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes

TAP_DANCE_ENABLE = no
AUTO_SHIFT_ENABLE = no
CONSOLE_ENABLE = no
SWAP_HANDS_ENABLE = no

SRC += bocaj_swift.c \
	   secrets.c

ifeq ($(strip $(NO_SECRETS)), yes)
    OPT_DEFS += -DNO_SECRETS
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
  SRC += tap_dances.c
endif

ifeq ($(strip $(MACROS_ENABLED)), yes)
    OPT_DEFS += -DMACROS_ENABLED
endif

EXTRAFLAGS += -flto
