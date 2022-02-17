/* myAutomation.h
*  All layout setup and automation items are defined here.
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

/* Startup sequence
*  This section defines startup actions:
*  - Set L293D enable pins low
*  - Turn the turnout power relay on
*  - Close all turnouts
*/

// Ensure all L293D enable pins are RESET before providing turnout power
// This is to prevent turnout coil burnout
RESET(172)
RESET(173)
RESET(174)
RESET(175)
RESET(176)
RESET(177)
RESET(178)
RESET(179)
RESET(188)
RESET(189)
RESET(190)
RESET(191)
RESET(192)
RESET(193)
RESET(194)
RESET(195)
RESET(204)
RESET(205)
RESET(206)
RESET(207)
RESET(208)
RESET(209)

// Turn the turnout power relay on
// Relay control sits on the last pin of the last MCP23017
SET(211)

// Close all turnouts on start up
// Turnouts MA_IND_1/IND_MA_1, MA_IND_2/IND_MA_2, and RUN_1/RUN_2 operate together
// so only need to close the first of the pairs.
CLOSE(MA_IND_1)
CLOSE(MA_IND_2)
DELAY(TURNOUT_DELAY)
CLOSE(YD_E)
CLOSE(IIND_E1)
CLOSE(IIND_E2)
CLOSE(CAR_E)
DELAY(TURNOUT_DELAY)
CLOSE(CON_E)
CLOSE(WH_E)
CLOSE(DIST_E)
CLOSE(DIST_S)
DELAY(TURNOUT_DELAY)
CLOSE(TBA_E)
CLOSE(YD_1)
CLOSE(RUN_E)
CLOSE(RR_E)
DELAY(TURNOUT_DELAY)
CLOSE(TT_E)
CLOSE(RUN_1)
CLOSE(YD_2)
DELAY(TURNOUT_DELAY)
CLOSE(YD_3)
CLOSE(YD_4)

// This is the end of the startup sequence
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

// Define the turntable DCC turnouts
TURNOUT(201, 51, 0, "Stall 1 entry")
ALIAS(ST_1, 201)
TURNOUT(202, 51, 1, "Stall 2 entry")
ALIAS(ST_2, 202)
TURNOUT(203, 51, 2, "Stall 3 entry")
ALIAS(ST_3, 203)
TURNOUT(204, 51, 3, "Stall 4 entry")
ALIAS(ST_4, 204)
TURNOUT(205, 52, 0, "Stall 5 entry")
ALIAS(ST_5, 205)
TURNOUT(206, 52, 1, "Stall 6 entry")
ALIAS(ST_6, 206)
TURNOUT(207, 52, 2, "Stall 7 entry")
ALIAS(ST_7, 207)
TURNOUT(208, 52, 3, "Stall 8 entry")
ALIAS(ST_8, 208)
TURNOUT(209, 53, 0, "Storage track 3 entry")
ALIAS(STOR_3, 209)
TURNOUT(210, 53, 1, "Storage track 2 entry")
ALIAS(STOR_2, 210)
TURNOUT(211, 53, 2, "Storage track 1 entry")
ALIAS(STOR_1, 211)
TURNOUT(212, 53, 3, "Layout connection")
ALIAS(TT_LAYOUT, 212)
DONE

/* Main loop ROUTE
*  Simple route for main loop continuous running
*/
ROUTE(1, "Main loop")
    IFTHROWN(MA_IND_1) CLOSE(MA_IND_1) DONE
    IFTHROWN(MA_IND_2) CLOSE(MA_IND_2) DONE
    DONE

/* Industry loop ROUTE
*  Simple route for industry loop continuous running
*/
ROUTE(2, "Industry loop")
    IFTHROWN(IND_MA_1) CLOSE(IND_MA_1) DONE
    IFTHROWN(IND_MA_2) CLOSE(IND_MA_2) DONE
    DELAY(TURNOUT_DELAY)
    IFTHROWN(YD_E) CLOSE(YD_E) DONE
    IFTHROWN(IIND_E1) CLOSE(IIND_E1) DONE
    IFTHROWN(IIND_E2) CLOSE(IIND_E2) DONE
    DELAY(TURNOUT_DELAY)
    IFTHROWN(CON_E) CLOSE(CON_E) DONE
    IFTHROWN(WH_E) CLOSE(WH_E) DONE
    IFTHROWN(DIST_E) CLOSE(DIST_E) DONE
    IFTHROWN(TBA_E) CLOSE(TBA_E) DONE
    DONE

/* Inner industry loop ROUTE
*  Simple route for inner industry loop continuous running
*/
ROUTE(3, "Inner industry loop")
    IFTHROWN(IND_MA_1) CLOSE(IND_MA_1) DONE
    IFTHROWN(IND_MA_2) CLOSE(IND_MA_2) DONE
    DELAY(TURNOUT_DELAY)
    IFTHROWN(YD_E) CLOSE(YD_E) DONE
    IFCLOSED(IIND_E1) THROW(IIND_E1) DONE
    IFCLOSED(IIND_E2) THROW(IIND_E2) DONE
    IFTHROWN(CAR_E) CLOSE(CAR_E) DONE
    DONE

/* Industry loop to turntable ROUTE
*  Define a ROUTE to get to the turntable from the industry loop
*  Set all turnouts correctly for entry from industry loop
*  Align turntable with the layout connection track
*  Loco can now be driven to the end of the siding ready to enter turntable
*  After the locos passes over sensor 1, throw the turntable entry turnout
*  Loco can then be driven onto turntable
*/
ROUTE(4, "Industry loop to turntable")
    IFCLOSED(YD_E) THROW(YD_E) DONE
    IFCLOSED(YD_1) THROW(YD_1) DONE
    IFTHROWN(RUN_E) CLOSE(RUN_E) DONE
    IFCLOSED(RR_E) THROW(RR_E) DONE
    DELAY(TURNOUT_DELAY)
    IFTHROWN(TT_E) CLOSE(TT_E) DONE
    IFTHROWN(RUN_1) CLOSE(RUN_1) DONE
    CLOSE(TT_LAYOUT)
    AFTER(1) THROW(TT_E) DONE
    DONE