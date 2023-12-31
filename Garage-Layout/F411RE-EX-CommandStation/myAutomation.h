// Configure tracks
SET_TRACK(A,MAIN)
SET_TRACK(B,PROG)
SET_TRACK(C,MAIN)
SET_TRACK(D,MAIN)

// Define I2C devices here
#include "IO_RotaryEncoder.h"
HAL(MCP23017, 164, 16, 0x20)
HAL(MCP23017, 180, 16, 0x21)
HAL(MCP23017, 196, 16, 0x22)
HAL(EXTurntable, 600, 1, 0x60)
HAL(RotaryEncoder, 700, 3, 0x70)
HAL(EXIOExpander, 800, 97, 0x66)
