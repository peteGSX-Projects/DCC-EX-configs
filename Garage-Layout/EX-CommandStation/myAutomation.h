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

// Turn power relay on and wait 1/2 a second
SET(POINT_POWER)
DELAY(500)

// Close all turnouts
CLOSE(POINT1)
CLOSE(POINT2)
CLOSE(POINT3)
CLOSE(POINT4)
CLOSE(POINT5)
CLOSE(POINT6)
CLOSE(POINT7)
CLOSE(POINT8)
CLOSE(POINT9)
CLOSE(POINT10)
CLOSE(POINT11)
CLOSE(POINT12)
CLOSE(POINT13)
CLOSE(POINT14)

START(TTROUTE_1)

DONE

#include "myTurntable.h"
#include "myRoster.h"
