/* myTurntable.h
*  This file contains all turntable macros and definitions.
*
*  Any related activities that need to occur on startup need to
*  be included in myAutomation.h to ensure they are in the 
*  correct order when compiled.
*/

// Create EX-Turntable objects
EXTT_TURNTABLE(EXTT,EXTT_VPIN,180,"QR Turntable")
TT_ADDPOSITION(EXTT,1,676,166,"Stall 1")
TT_ADDPOSITION(EXTT,2,738,173,"Stall 2")
TT_ADDPOSITION(EXTT,3,800,180,"Stall 3")
TT_ADDPOSITION(EXTT,4,862,187,"Stall 4")
TT_ADDPOSITION(EXTT,5,924,194,"Stall 5")
TT_ADDPOSITION(EXTT,6,987,201,"Stall 6")
TT_ADDPOSITION(EXTT,7,2276,76,"Storage")
TT_ADDPOSITION(EXTT,8,2400,8,"Yard")

// Define the turntable route macro
#define EX_TURNTABLE(route_id,tt_id,position,activity,desc,rotary_encoder) \
  ROUTE(route_id, desc) \
    RESERVE(tt_id) \
    SET(1+rotary_encoder) \
    SERVO(2+rotary_encoder, position, Instant) \
    ROTATE(tt_id,position,activity) \
    WAITFORTT(tt_id) \
    RESET(1+rotary_encoder) \
    FREE(tt_id) \
    DONE

EX_TURNTABLE(TTROUTE_1, EXTT, 1, Turn, "Roundhouse stall 1", RE_VPIN)
EX_TURNTABLE(TTROUTE_2, EXTT, 2, Turn, "Roundhouse stall 2", RE_VPIN)
EX_TURNTABLE(TTROUTE_3, EXTT, 3, Turn, "Roundhouse stall 3", RE_VPIN)
EX_TURNTABLE(TTROUTE_4, EXTT, 4, Turn, "Roundhouse stall 4", RE_VPIN)
EX_TURNTABLE(TTROUTE_5, EXTT, 5, Turn, "Roundhouse stall 5", RE_VPIN)
EX_TURNTABLE(TTROUTE_6, EXTT, 5, Turn, "Roundhouse stall 6", RE_VPIN)
EX_TURNTABLE(TTROUTE_7, EXTT, 7, Turn, "Storage track", RE_VPIN)
EX_TURNTABLE(TTROUTE_8, EXTT, 8, Turn, "Yard connection", RE_VPIN)
EX_TURNTABLE(TTROUTE_9, EXTT, 0, Home, "Home turntable", RE_VPIN)
EX_TURNTABLE(TTROUTE_10, EXTT, 0, Calibrate, "Calibrate turntable", RE_VPIN)
