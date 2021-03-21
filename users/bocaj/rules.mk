# Include the mk file from the correct dir instead of this
ifeq ($(strip $(USE_V2)), yes)
SRC += v2/bocaj.c \
       v2/process_records.c
else
SRC += v1/bocaj.c \
       v1/process_records.c

    LEADER_ENABLE = yes
    MOUSEKEY_ENABLE = yes
    EXTRAKEY_ENABLE = yes

    ifneq ($(PLATFORM),CHIBIOS)
        LTO_ENABLE        = yes
    endif
    SPACE_CADET_ENABLE    = no
    GRAVE_ESC_ENABLE      = no

    ifneq ($(strip $(NO_SECRETS)), yes)
        ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
            SRC += secrets.c
        endif
        ifeq ($(strip $(NO_SECRETS)), lite)
            OPT_DEFS += -DNO_SECRETS
        endif
    endif
endif


