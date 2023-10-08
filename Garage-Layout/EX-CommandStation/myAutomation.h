/* myAutomation.h
*  All layout startup activities are included directly in here.
*  Other automation files must be included after the startup
*  sequence.
*/

// Include pin aliases as these are used throughout
#include "myPinAliases.h"

// Include extra device drivers
#include "IO_RotaryEncoder.h"

// Define I2C devices here
HAL(MCP23017, 164, 16, 0x20)
HAL(MCP23017, 180, 16, 0x21)
HAL(MCP23017, 196, 16, 0x22)
HAL(EXTurntable, 600, 1, 0x60)
HAL(RotaryEncoder, 700, 3, 0x70)
HAL(EXIOExpander, 800, 97, 0x66)

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
CLOSE(STATION_SIDING_WEST)
CLOSE(STATION_SIDING_EAST)
CLOSE(CONTAINER_SIDING)
CLOSE(CAR_SIDING)
CLOSE(WAREHOUSE_SIDING)
CLOSE(INDUSTRY_LOOP_EAST)
CLOSE(TURNTABLE_ACCESS)
CLOSE(STORAGE_3)
CLOSE(STORAGE_2)
CLOSE(MAINTENANCE)
CLOSE(STORAGE_1_AND_MAINTENANCE)
CLOSE(YARD_ACCESS)
CLOSE(INDUSTRY_LOOP_WEST)

START(TTROUTE_1)

DONE

#include "myPoints.h"
#include "myTurntable.h"
#include "myRoster.h"
#include "myRoutes.h"
#include "myMimicPanel.h"
#include "myDecouplers.h"
