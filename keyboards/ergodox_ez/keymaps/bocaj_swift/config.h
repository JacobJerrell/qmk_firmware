#pragma once

/* Personal Configuration */
#define LEADER_TIMEOUT 250
#define LEADER_PER_KEY_TIMING

#define IGNORE_MOD_TAP_INTERRUPT
#define PREVENT_STUCK_MODIFIERS
#undef PERMISSIVE_HOLD
#undef RETRO_TAPPING

/* Save firmware space */
#ifndef NO_DEBUG
    #define NO_DEBUG
#endif // !NO_DEBUG

#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
    #define NO_PRINT
#endif // !NO_PRINT

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
