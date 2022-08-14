/* myTurtable.h
*  This file contains all turntable macros and definitions.
*
*  Any related activities that need to occur on startup need to
*  be included in myAutomation.h to ensure they are in the 
*  correct order when compiled.
*/

// Define the turntable DCC turnouts
TURNOUT(201, 51, 0, "TT Stall 1 entry")
ALIAS(TT_ST1, 201)
TURNOUT(202, 51, 1, "TT Stall 2 entry")
ALIAS(TT_ST2, 202)
TURNOUT(203, 51, 2, "TT Stall 3 entry")
ALIAS(TT_ST3, 203)
TURNOUT(204, 51, 3, "TT Stall 4 entry")
ALIAS(TT_ST4, 204)
TURNOUT(205, 52, 0, "TT Stall 5 entry")
ALIAS(TT_ST5, 205)
TURNOUT(206, 52, 1, "TT Stall 6 entry")
ALIAS(TT_ST6, 206)
TURNOUT(207, 52, 2, "TT Stall 7 entry")
ALIAS(TT_ST7, 207)
TURNOUT(208, 52, 3, "TT Stall 8 entry")
ALIAS(TT_ST8, 208)
TURNOUT(209, 53, 0, "TT Storage track 3 entry")
ALIAS(TT_STOR3, 209)
TURNOUT(210, 53, 1, "TT Storage track 2 entry")
ALIAS(TT_STOR2, 210)
TURNOUT(211, 53, 2, "TT Storage track 1 entry")
ALIAS(TT_STOR1, 211)
TURNOUT(212, 53, 3, "TT Layout connection")
ALIAS(TT_LAYOUT, 212)
DONE
