/* myTurtable.h
*  This file contains all turntable macros and definitions.
*
*  Any related activities that need to occur on startup need to
*  be included in myAutomation.h to ensure they are in the 
*  correct order when compiled.
*/

// Define the turntable route macro
#define EX_TURNTABLE(route_id, reserve_id, vpin, steps, activity, desc) \
  ROUTE(route_id, desc) \
    RESERVE(reserve_id) \
    MOVETT(vpin, steps, activity) \
    WAITFOR(vpin) \
    FREE(reserve_id) \
    DONE

EX_TURNTABLE(TTROUTE_1, EXTT_1, 600, 114, Turn, "Roundhouse stall 1")
EX_TURNTABLE(TTROUTE_2, EXTT_1, 600, 194, Turn, "Roundhouse stall 2")
EX_TURNTABLE(TTROUTE_3, EXTT_1, 600, 274, Turn, "Roundhouse stall 3")
EX_TURNTABLE(TTROUTE_4, EXTT_1, 600, 354, Turn, "Roundhouse stall 4")
EX_TURNTABLE(TTROUTE_5, EXTT_1, 600, 434, Turn, "Roundhouse stall 5")
EX_TURNTABLE(TTROUTE_6, EXTT_1, 600, 514, Turn, "Roundhouse stall 6")
EX_TURNTABLE(TTROUTE_7, EXTT_1, 600, 594, Turn, "Roundhouse stall 7")
EX_TURNTABLE(TTROUTE_8, EXTT_1, 600, 674, Turn, "Roundhouse stall 8")
EX_TURNTABLE(TTROUTE_9, EXTT_1, 600, 114, Turn, "Storage track")
EX_TURNTABLE(TTROUTE_10, EXTT_1, 600, 2500, Turn, "Layout connection")
EX_TURNTABLE(TTROUTE_11, EXTT_1, 600, 2660, Turn, "Home turntable")

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
ALIAS(TTROUTE_11)
