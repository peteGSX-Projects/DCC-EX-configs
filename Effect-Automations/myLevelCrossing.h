// Level crossing sequences that start/stop based on a LATCH triggered by a sensor

AUTOSTART SEQUENCE(EAST_CROSSING)
  AT(EAST_CROSSING_APPROACH)                // Approach sensor
  LATCH(EAST_CROSSING_LATCH)                // Trigger light sequence
  DELAY(2000)                               // Start lights before closing gates
  SERVO(EAST_CROSSING_GATE_1,100,Bounce)    // Close gate 1
  SERVO(EAST_CROSSING_GATE_2,100,Bounce)    // Close gate 2
  AFTER(EAST_CROSSING_DEPART)               // Departure sensor
  SERVO(EAST_CROSSING_GATE_1,400,Bounce)    // Open gate 1
  SERVO(EAST_CROSSING_GATE_2,400,Bounce)    // Open gate 2
  UNLATCH(EAST_CROSSING_LATCH)              // Stop light sequence
FOLLOW(EAST_CROSSING)                       // Wait for next train.

AUTOSTART SEQUENCE(EAST_CROSSING_LIGHTS)
  RESET(EAST_CROSSING_LIGHT1)   // Switch off light 1
  RESET(EAST_CROSSING_LIGHT2)   // Switch off light 2
  AT(EAST_CROSSING_LATCH)       // If sensor latched
  SET(EAST_CROSSING_LIGHT1)     // Light 1 on
  DELAY(500)
  RESET(EAST_CROSSING_LIGHT1)   // Light 1 off
  SET(EAST_CROSSING_LIGHT2)     // Light 2 on
  DELAY(500)
FOLLOW(EAST_CROSSING_LIGHTS)    // Keep running sequence

AUTOSTART SEQUENCE(WEST_CROSSING)
  AT(WEST_CROSSING_APPROACH)                // Approach sensor
  LATCH(WEST_CROSSING_LATCH)                // Trigger light sequence
  DELAY(2000)                               // Start lights before closing gates
  SERVO(WEST_CROSSING_GATE_1,100,Bounce)    // Close gate 1
  SERVO(WEST_CROSSING_GATE_2,100,Bounce)    // Close gate 2
  AFTER(WEST_CROSSING_DEPART)               // Departure sensor
  SERVO(WEST_CROSSING_GATE_1,400,Bounce)    // Open gate 1
  SERVO(WEST_CROSSING_GATE_2,400,Bounce)    // Open gate 2
  UNLATCH(WEST_CROSSING_LATCH)              // Stop light sequence
FOLLOW(WEST_CROSSING)                       // Wait for next train.

AUTOSTART SEQUENCE(WEST_CROSSING_LIGHTS)
  RESET(WEST_CROSSING_LIGHT1)   // Switch off light 1
  RESET(WEST_CROSSING_LIGHT2)   // Switch off light 2
  AT(WEST_CROSSING_LATCH)       // If sensor latched
  SET(WEST_CROSSING_LIGHT1)     // Light 1 on
  DELAY(500)
  RESET(WEST_CROSSING_LIGHT1)   // Light 1 off
  SET(WEST_CROSSING_LIGHT2)     // Light 2 on
  DELAY(500)
FOLLOW(WEST_CROSSING_LIGHTS)    // Keep running sequence
