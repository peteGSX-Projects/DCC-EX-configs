/* myTurnouts.h
*  This file contains all turnout macros and definitions.
*
*  Any related activities that need to occur on startup need to
*  be included in myAutomation.h to ensure they are in the 
*  correct order when compiled.
*/

// TURNOUT_DELAY is used to spread power supply load out between lots of
// turnout changes as they use ~700mA each. Do two turnouts at once max.
#define TURNOUT_DELAY 100

/* Rokuhan turnout macro
*  This macro defines Rokuhan turnouts as well as ensuring that these
*  turnouts are driven only by a short pulse to prevent coil burn out.
*
*  Call this macro with:
*  ROKUHANTURNOUT(t, p1, p2, desc, ali)
*
*  Where:
*  t = turnout ID
*  p1 = direction pin
*  p2 = enable pin
*  desc = description of the turnout
*  ali = alias assigned to the turnout ID
*
*  Adjust the PULSE time (in ms) below as required, 25 seems reliable.
*
*  When a turnout command is sent to one of the defined turnouts, the macro
*  will close or throw the turnout using the defined PULSE time.
*
*  This also ensures all turnouts are defined as part of the compilation.
*/
#define PULSE 25

#define ROKUHANTURNOUT(t, p1, p2, desc, ali) \
PIN_TURNOUT(t, 0, desc) \
ALIAS(ali, t) \
DONE \
ONCLOSE(t) \
SET(p1) \
SET(p2)DELAY(PULSE)RESET(p2) \
DONE \
ONTHROW(t) \
RESET(p1) \
SET(p2)DELAY(PULSE)RESET(p2) \
DONE

// Turnout definitions using the ROKUHANTURNOUT macro

// Industry loop turnouts
ROKUHANTURNOUT(105, 168, 176, "Yard entrance", YD_E)
ROKUHANTURNOUT(106, 169, 177, "Inner industry loop entrance 1", IIND_E1) // Behind roundhouse
ROKUHANTURNOUT(107, 170, 178, "Inner industry loop entrance 2", IIND_E2) // To right of main turnouts
ROKUHANTURNOUT(108, 171, 179, "Car loading entrance", CAR_E)
ROKUHANTURNOUT(109, 180, 188, "Container loading entrance", CON_E)
ROKUHANTURNOUT(110, 181, 189, "Warehouse siding entrance", WH_E)
ROKUHANTURNOUT(111, 182, 190, "Distribution centre entrance", DIST_E)
ROKUHANTURNOUT(112, 183, 191, "Distribution centre split", DIST_S)
ROKUHANTURNOUT(113, 184, 192, "TBA industry siding entrance", TBA_E)

// Yard turnouts
ROKUHANTURNOUT(114, 185, 193, "Yard 1", YD_1) // First left turnout after entrance)
ROKUHANTURNOUT(115, 186, 194, "Runaround siding entry", RUN_E) // Entry to siding with runaround
ROKUHANTURNOUT(116, 187, 195, "Rolling road entry", RR_E)
ROKUHANTURNOUT(117, 196, 204, "Turntable entry", TT_E)
ROKUHANTURNOUT(120, 199, 207, "Yard 2", YD_2) // Right turnout
ROKUHANTURNOUT(121, 200, 208, "Yard 3", YD_3) // Left turnout
ROKUHANTURNOUT(122, 201, 209, "Yard 4", YD_4) // Left turnout
DONE

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

// Turnout definitions using the ROKUHANTURNOUTPAIR macro

// Main to industry loop turnout definitions
ROKUHANTURNOUTPAIR(101, 164, 172, "Main to industry loop 1", MA_IND_1, 102, 165, 173, "Industry loop to main 1", IND_MA_1) // Pair of left turnouts
ROKUHANTURNOUTPAIR(103, 166, 174, "Main to industry loop 2", MA_IND_2, 104, 167, 175, "Industry loop to main 2", IND_MA_2) // Pair of right turnouts)

// Runaround yard turnouts
ROKUHANTURNOUTPAIR(118, 197, 205, "Runaround 1", RUN_1, 119, 198, 206, "Runaround 2", RUN_2) // Pair of right turnouts for runaround

/*
*  Define the turnout pairs that need to operate simultaneously
*/

// Turnout power relay
ALIAS(TOUT_PWR, 211)

// Turnout enable pin aliases
ALIAS(MA_IND_1_EN, 172)
ALIAS(IND_MA_1_EN, 173)
ALIAS(MA_IND_2_EN, 174)
ALIAS(IND_MA_2_EN, 175)
ALIAS(YD_E_EN, 176)
ALIAS(IIND_E1_EN, 177)
ALIAS(IIND_E2_EN, 178)
ALIAS(CAR_E_EN, 179)
ALIAS(CON_E_EN, 188)
ALIAS(WH_E_EN, 189)
ALIAS(DIST_E_EN, 190)
ALIAS(DIST_S_EN, 191)
ALIAS(TBA_E_EN, 192)
ALIAS(YD_1_EN, 193)
ALIAS(RUN_E_EN, 194)
ALIAS(RR_E_EN, 195)
ALIAS(TT_E_EN, 204)
ALIAS(RUN_1_EN, 205)
ALIAS(RUN_2_EN, 206)
ALIAS(YD_2_EN, 207)
ALIAS(YD_3_EN, 208)
ALIAS(YD_4_EN, 209)
