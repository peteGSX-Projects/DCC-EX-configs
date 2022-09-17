#if !defined(IO_NO_HAL)

// Include devices you need.
#include "IODevice.h"
#include "IO_EXTurntable.h"
#include "IO_RotaryEncoder.h"

//==========================================================================
// The function halSetup() is invoked from CS if it exists within the build.
// The setup calls are included between the open and close braces "{ ... }".
// Comments (lines preceded by "//") are optional.
//==========================================================================

void halSetup() {
  EXTurntable::create(600, 1, 0x60);
  EXTurntable::create(601, 1, 0x61);
  RotaryEncoder::create(700, 1, 0x80);
}

#endif
