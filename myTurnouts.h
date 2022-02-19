/* myTurnouts.h
*  This file contains all turnout macros and definitions.
*
*  Any related activities that need to occur on startup need to
*  be included in myAutomation.h to ensure they are in the 
*  correct order when compiled.
*/

// TURNOUT_DELAY is used to spread power supply load out between lots of
// turnout changes as they use ~700mA each. Do four turnouts at once max.
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
DONE \
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

// Main to industry loop turnout definitions
ROKUHANTURNOUT(101, 164, 172, "Main to industry loop 1", MA_IND_1) // Pair of left turnouts
ROKUHANTURNOUT(102, 165, 173, "Industry loop to main 1", IND_MA_1)
ROKUHANTURNOUT(103, 166, 174, "Main to industry loop 2", MA_IND_2) // Pair of right turnouts)
ROKUHANTURNOUT(104, 165, 175, "Industry loop to main 2", IND_MA_2)

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
ROKUHANTURNOUT(118, 197, 205, "Runaround 1", RUN_1) // Pair of right turnouts for runaround
ROKUHANTURNOUT(119, 198, 206, "Runaround 2", RUN_2)
ROKUHANTURNOUT(120, 199, 207, "Yard 2", YD_2) // Right turnout
ROKUHANTURNOUT(121, 200, 208, "Yard 3", YD_3) // Left turnout
ROKUHANTURNOUT(122, 201, 209, "Yard 4", YD_4) // Left turnout
DONE

/*
*  Define the turnout pairs that need to operate simultaneously
*/

// Ensure main to industry loops turnouts operate together
ONCLOSE(MA_IND_1) CLOSE(IND_MA_1) DONE
ONTHROW(MA_IND_1) THROW(IND_MA_1) DONE
ONCLOSE(IND_MA_1) CLOSE(MA_IND_1) DONE
ONTHROW(IND_MA_1) THROW(MA_IND_1) DONE
ONCLOSE(MA_IND_2) CLOSE(IND_MA_2) DONE
ONTHROW(MA_IND_2) THROW(IND_MA_2) DONE
ONCLOSE(IND_MA_2) CLOSE(MA_IND_2) DONE
ONTHROW(IND_MA_2) THROW(MA_IND_2) DONE

// Ensure the runaround turnouts operate together
ONCLOSE(RUN_1) CLOSE(RUN_2) DONE
ONTHROW(RUN_1) THROW(RUN_2) DONE
ONCLOSE(RUN_2) CLOSE(RUN_1) DONE
ONTHROW(RUN_2) THROW(RUN_1) DONE
