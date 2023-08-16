/* myTurtable.h
*  This file contains all turntable macros and definitions.
*
*  Any related activities that need to occur on startup need to
*  be included in myAutomation.h to ensure they are in the 
*  correct order when compiled.
*/

// Define the turntable route macro
#define EX_TURNTABLE(route_id, reserve_id, vpin, steps, activity, desc, rotary_encoder, position) \
  ROUTE(route_id, desc) \
    RESERVE(reserve_id) \
    SET(1+rotary_encoder) \
    SERVO(2+rotary_encoder, position, Instant) \
    MOVETT(vpin, steps, activity) \
    WAITFOR(vpin) \
    RESET(1+rotary_encoder) \
    FREE(reserve_id) \
    DONE

EX_TURNTABLE(TTROUTE_1, EXTT_1, 600, 676, Turn, "Roundhouse stall 1", 700, 1)
EX_TURNTABLE(TTROUTE_2, EXTT_1, 600, 738, Turn, "Roundhouse stall 2", 700, 2)
EX_TURNTABLE(TTROUTE_3, EXTT_1, 600, 800, Turn, "Roundhouse stall 3", 700, 3)
EX_TURNTABLE(TTROUTE_4, EXTT_1, 600, 862, Turn, "Roundhouse stall 4", 700, 4)
EX_TURNTABLE(TTROUTE_5, EXTT_1, 600, 924, Turn, "Roundhouse stall 5", 700, 5)
EX_TURNTABLE(TTROUTE_6, EXTT_1, 600, 987, Turn, "Roundhouse stall 6", 700, 6)
EX_TURNTABLE(TTROUTE_7, EXTT_1, 600, 2276, Turn, "Storage track", 700, 7)
EX_TURNTABLE(TTROUTE_8, EXTT_1, 600, 2400, Turn, "Yard connection", 700, 8)
EX_TURNTABLE(TTROUTE_9, EXTT_1, 600, 0, Home, "Home turntable", 700, 0)
EX_TURNTABLE(TTROUTE_10, EXTT_1, 600, 0, Calibrate, "Calibrate turntable", 700, 9)

ALIAS(EXTT_1, 255)
ALIAS(TTROUTE_1)
ALIAS(TTROUTE_2)
ALIAS(TTROUTE_3)
ALIAS(TTROUTE_4)
ALIAS(TTROUTE_5)
ALIAS(TTROUTE_6)
ALIAS(TTROUTE_7)
ALIAS(TTROUTE_8)
ALIAS(TTROUTE_9)
ALIAS(TTROUTE_10)
