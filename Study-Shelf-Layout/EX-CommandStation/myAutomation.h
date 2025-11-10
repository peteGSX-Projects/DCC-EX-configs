// Include aliases first before anything else.
#include "myAliases.h"

// HAL devices.
HAL_IGNORE_DEFAULTS
HAL(PCA9685, 100, 16, 0x40)
HAL(MCP23017, 200, 16, 0x20)
HAL(MCP23017, 216, 16, 0x21)
HAL(MCP23017, 232, 16, 0x22)
HAL(EXTurntable, TURNTABLE_VPIN, TURNTABLE_ID, 0x60)
