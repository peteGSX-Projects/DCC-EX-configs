/* myTurtable.h
*  This file contains all turntable macros and definitions.
*
*  Any related activities that need to occur on startup need to
*  be included in myAutomation.h to ensure they are in the 
*  correct order when compiled.
*/

// Define the turntable DCC turnouts
TURNOUT(201, 51, 0, "Stall 1 entry")
ALIAS(ST_1, 201)
TURNOUT(202, 51, 1, "Stall 2 entry")
ALIAS(ST_2, 202)
TURNOUT(203, 51, 2, "Stall 3 entry")
ALIAS(ST_3, 203)
TURNOUT(204, 51, 3, "Stall 4 entry")
ALIAS(ST_4, 204)
TURNOUT(205, 52, 0, "Stall 5 entry")
ALIAS(ST_5, 205)
TURNOUT(206, 52, 1, "Stall 6 entry")
ALIAS(ST_6, 206)
TURNOUT(207, 52, 2, "Stall 7 entry")
ALIAS(ST_7, 207)
TURNOUT(208, 52, 3, "Stall 8 entry")
ALIAS(ST_8, 208)
TURNOUT(209, 53, 0, "Storage track 3 entry")
ALIAS(STOR_3, 209)
TURNOUT(210, 53, 1, "Storage track 2 entry")
ALIAS(STOR_2, 210)
TURNOUT(211, 53, 2, "Storage track 1 entry")
ALIAS(STOR_1, 211)
TURNOUT(212, 53, 3, "Layout connection")
ALIAS(TT_LAYOUT, 212)
DONE
