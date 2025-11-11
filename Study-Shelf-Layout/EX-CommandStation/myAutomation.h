// Include aliases first before anything else.
#include "myAliases.h"

// Include other definition files here
#include "myPoints.h"
#include "myRoster.h"
#include "myTurntable.h"

// HAL devices.
HAL_IGNORE_DEFAULTS
HAL(PCA9685,100,16,0x40) // Decouplers and semaphores
HAL(MCP23017,200,16,0x20) // Points
HAL(MCP23017,300,16,0x21) // Mimic panel LEDs
HAL(MCP23017,320,16,0x22) // Mimic panel buttons
HAL(EXTurntable,TURNTABLE_VPIN,TURNTABLE_ID,0x60)
HAL(EXSensorCAM,SENSORCAM_LEFT,80,0x11)
HAL(EXSensorCAM,SENSORCAM_RIGHT,80,0x12)

