#if !defined(IO_NO_HAL)

// Include devices you need.
#include "IODevice.h"
#include "IO_EXTurntable.h"
// #include "IO_RotaryEncoder.h"
//==========================================================================
// The function halSetup() is invoked from CS if it exists within the build.
// The setup calls are included between the open and close braces "{ ... }".
// Comments (lines preceded by "//") are optional.
//==========================================================================

void halSetup() {
  MCP23017::create(196, 16, 0x22);

// Five defined below ready for allocation
  //MCP23017::create(212, 16, 0x23);
  //MCP23017::create(228, 16, 0x24);
  //MCP23017::create(244, 16, 0x25);
  //MCP23017::create(260, 16, 0x26);
  //MCP23017::create(276, 16, 0x27);

  EXTurntable::create(600, 1, 0x60);

  // RotaryEncoder::create(700, 1, 0x80);
}

#endif
