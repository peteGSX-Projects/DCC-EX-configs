/* myAutomation.h
*  All layout startup activities are included directly in here.
*  Other automation files must be included after the startup
*  sequence.
*/

// Include pin aliases as these are used throughout
#include "myPinAliases.h"

// Include extra device drivers
#include "IO_EXTurntable.h"
#include "IO_RotaryEncoder.h"

// Define I2C devices here
HAL(MCP23017, 164, 16, 0x20)
HAL(MCP23017, 180, 16, 0x21)
HAL(MCP23017, 196, 16, 0x22)
HAL(EXTurntable, 600, 1, 0x60)
HAL(RotaryEncoder, 700, 2, 0x70)

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

START(TTROUTE_1)

DONE

#include "myPoints.h"
#include "myTurntable.h"
#include "myRoster.h"
#include "myRoutes.h"
