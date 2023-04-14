/* myAutomation.h
*  All layout startup activities are included directly in here.
*  Other automation files must be included after the startup
*  sequence.
*/

// Include pin aliases as these are used throughout
#include "myPinAliases.h"

// These things need to happen at startup
AUTOSTART

// Make sure point power is off
RESET(POINT_POWER)

// Make sure all enable pins are low
RESET(POINT1_EN)
RESET(POINT2_EN)
RESET(POINT3_EN)
RESET(POINT4_EN)
RESET(POINT5_EN)
RESET(POINT6_EN)
RESET(POINT7_EN)
RESET(POINT8_EN)
RESET(POINT9_EN)
RESET(POINT10_EN)
RESET(POINT11_EN)
RESET(POINT12_EN)
RESET(POINT13_EN)
RESET(POINT14_EN)
RESET(POINT15_EN)
RESET(POINT16_EN)
RESET(POINT17_EN)
RESET(POINT18_EN)
RESET(POINT19_EN)
RESET(POINT20_EN)
RESET(POINT21_EN)
RESET(POINT22_EN)

// Turn power relay on and wait 1/2 a second
SET(POINT_POWER)
DELAY(500)

// Close all turnouts
CLOSE(TOUT_1)
CLOSE(TOUT_2)
CLOSE(TOUT_3)
CLOSE(TOUT_4)
CLOSE(TOUT_5)
CLOSE(TOUT_6)
CLOSE(TOUT_7)
CLOSE(TOUT_8)
CLOSE(TOUT_9)
CLOSE(TOUT_10)
CLOSE(TOUT_11)
CLOSE(TOUT_12)
CLOSE(TOUT_13)
CLOSE(TOUT_14)
CLOSE(TOUT_15)
CLOSE(TOUT_16)
CLOSE(TOUT_17)
CLOSE(TOUT_18)
CLOSE(TOUT_19)
CLOSE(TOUT_20)
CLOSE(TOUT_21)
CLOSE(TOUT_22)

START(TTROUTE_1)

DONE

#include "myTurnoutTesting.h"
#include "myTurntable.h"
#include "myRoster.h"

// Startup sequences start here.

/* Turnout startup sequence
*  This section defines startup actions for turnouts:
*  - Set L293D enable pins low
*  - Turn the turnout power relay on
*  - Close all turnouts
*/

// Ensure all L293D enable pins are RESET before providing turnout power
// This is to prevent turnout coil burnout
// RESET(MA_IND_1_EN)
// RESET(IND_MA_1_EN)
// RESET(MA_IND_2_EN)
// RESET(IND_MA_2_EN)
// RESET(YD_E_EN)
// RESET(IIND_E1_EN)
// RESET(IIND_E2_EN)
// RESET(CAR_E_EN)
// RESET(CON_E_EN)
// RESET(WH_E_EN)
// RESET(DIST_E_EN)
// RESET(DIST_S_EN)
// RESET(TBA_E_EN)
// RESET(YD_1_EN)
// RESET(RUN_E_EN)
// RESET(RR_E_EN)
// RESET(TT_E_EN)
// RESET(RUN_1_EN)
// RESET(RUN_2_EN)
// RESET(YD_2_EN)
// RESET(YD_3_EN)
// RESET(YD_4_EN)

// // Turn the turnout power relay on
// // Relay control sits on the last pin of the last MCP23017
// // Short delay to ensure relay is on first
// SET(TOUT_PWR)
// DELAY(TURNOUT_DELAY)

// // Close all turnouts on start up
// // Turnouts MA_IND_1/IND_MA_1, MA_IND_2/IND_MA_2, and RUN_1/RUN_2 operate together
// // so only need to close the first of the pairs.
// // Only closing two at once to be nice to the power supply and regulator.
// CLOSE(MA_IND_1)
// DELAY(TURNOUT_DELAY)
// CLOSE(MA_IND_2)
// DELAY(TURNOUT_DELAY)
// CLOSE(YD_E)
// CLOSE(IIND_E1)
// DELAY(TURNOUT_DELAY)
// CLOSE(IIND_E2)
// CLOSE(CAR_E)
// DELAY(TURNOUT_DELAY)
// CLOSE(CON_E)
// CLOSE(WH_E)
// DELAY(TURNOUT_DELAY)
// CLOSE(DIST_E)
// CLOSE(DIST_S)
// DELAY(TURNOUT_DELAY)
// CLOSE(TBA_E)
// CLOSE(YD_1)
// DELAY(TURNOUT_DELAY)
// CLOSE(RUN_E)
// CLOSE(RR_E)
// DELAY(TURNOUT_DELAY)
// CLOSE(TT_E)
// CLOSE(RUN_1)
// DELAY(TURNOUT_DELAY)
// CLOSE(YD_2)
// CLOSE(YD_3)
// DELAY(TURNOUT_DELAY)
// CLOSE(YD_4)

// // This is the end of all the startup sequences.
// DONE

// // External automation files included here.
// #include "myTurnouts.h"
// #include "myTurntable.h"
// #include "myRoutes.h"
// #include "myRoster.h"
// #include "mySensors.h"
// #include "myDecouplers.h"
// #include "myRollingRoad.h"
