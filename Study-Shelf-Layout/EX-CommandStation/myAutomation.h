// Include aliases first before anything else.
#include "myAliases.h"

// HAL devices.
HAL_IGNORE_DEFAULTS
HAL(PCA9685,100,16,0x40) // Decouplers and semaphores
HAL(MCP23017,200,16,0x20) // Points
HAL(MCP23017,300,16,0x21) // Mimic panel LEDs
HAL(MCP23017,320,16,0x22) // Mimic panel buttons
HAL(EXTurntable,TURNTABLE_VPIN,TURNTABLE_ID,0x60)
HAL(EXSensorCAM,SENSORCAM_LEFT,80,0x11)
HAL(EXSensorCAM,SENSORCAM_RIGHT,80,0x12)
HAL(HALDisplay<OLED>, 0, {I2CMux_0, SubBus_0, 0x3c}, 132, 64)
HAL(HALDisplay<OLED>, 1, {I2CMux_0, SubBus_1, 0x3c}, 132, 64)

// Include other definition files here
#include "myPoints.h"
#include "myRoster.h"
#include "myRoutes.h"
#include "myTurntable.h"
