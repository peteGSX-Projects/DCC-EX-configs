/* myOutputs.h
*  This file contains all defined outputs including decouplers.
*
*  Outputs typically don't have actual definitions in EX-RAIL and
*  therefore this is typically just a list of aliases.
*
*  Decouplers require some automation which is defined here.
*/

/* Decoupler turnout macro
*  This macro defines decouplers as turnouts as well as providing the
*  automation to raise and lower decoupling magnets.
*
*  Call this macro with:
*  DECOUPLE(t, p1, desc, ali)
*
*  Where:
*  d = decoupler ID
*  p1 = servo control pin
*  desc = description of the decoupler
*  ali = alias assigned to the decoupler ID
*
*  Adjust the DECOUPLE_TIME (in ms) below as required.
*
*  When a turnout command is sent to one of the defined turnouts, the macro
*  will close or throw the turnout using the defined PULSE time.
*
*  This also ensures all decouplers are defined as part of the compilation.
*/
#define DECOUPLE_TIME 10000

/*
#define DECOUPLE(d, p1, desc, ali) \
SERVO_TURNOUT(d, p1, active_angle, inactive_angle, profile, desc)
DONE \
ALIAS(ali, d) \
DONE \
ONCLOSE(d) \
SET(p1) \
SET(p2)DELAY(PULSE)RESET(p2) \
DONE \
ONTHROW(t) \
RESET(p1) \
SET(p2)DELAY(PULSE)RESET(p2) \
DONE
*/

// Define the decouplers
//DECOUPLE()

// Define other output aliases here
