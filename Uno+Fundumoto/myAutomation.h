/* Rokuhan turnout pair macro
*  This macro defines Rokuhan turnouts as pairs as well as ensuring that these
*  turnouts are driven only by a short pulse to prevent coil burn out.
*
*  Two turnouts are configured by this macro to operate together when closing/throwing.
*
*  Call this macro with:
*  ROKUHANTURNOUTPAIR(t1, t1p1, t1p2, t1desc, t1ali, t2, t2p1, t2p2, t2desc, t2ali)
*
*  Where:
*  t1 = turnout ID for the first turnout
*  t1p1 = direction pin for the first turnout
*  t1p2 = enable pin for the first turnout
*  t1desc = description of the first turnout
*  t1ali = alias assigned to the first turnout ID
*  t2 = turnout ID for the second turnout
*  t2p1 = direction pin for the second turnout
*  t2p2 = enable pin for the second turnout
*  t2desc = description of the second turnout
*  t2ali = alias assigned to the second turnout ID
*
*  Adjust the PULSE time (in ms) below as required, 25 seems reliable (defined above).
*
*  When a turnout command is sent to one of the defined turnouts, the macro
*  will close or throw the turnout using the defined PULSE time.
*
*  This also ensures all turnouts are defined as part of the compilation.
*/
#define ROKUHANTURNOUTPAIR(t1, t1p1, t1p2, t1desc, t1ali, t2, t2p1, t2p2, t2desc, t2ali) \
PIN_TURNOUT(t1, 0, t1desc) \
ALIAS(t1ali, t1) \
PIN_TURNOUT(t2, 0, t2desc) \
ALIAS(t2ali, t2) \
DONE \
ONCLOSE(t1) \
SET(t1p1)SET(t2p1) \
SET(t1p2)SET(t2p2)DELAY(PULSE)RESET(t1p2)RESET(t2p2) \
DONE \
ONCLOSE(t2) \
SET(t1p1)SET(t2p1) \
SET(t1p2)SET(t2p2)DELAY(PULSE)RESET(t1p2)RESET(t2p2) \
DONE \
ONTHROW(t1) \
RESET(t1p1)RESET(t2p1) \
SET(t1p2)SET(t2p2)DELAY(PULSE)RESET(t1p2)RESET(t2p2) \
DONE \
ONTHROW(t2) \
RESET(t1p1)RESET(t2p1) \
SET(t1p2)SET(t2p2)DELAY(PULSE)RESET(t1p2)RESET(t2p2) \
DONE

ROKUHANTURNOUTPAIR(101, 16, 17, "Turnout 1", TRN_1, 102, 9, 8, "Turnout 2", TRN_2) // Pair of turnouts
