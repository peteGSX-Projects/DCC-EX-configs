/* myTurnouts.h
*  This file contains all EX-RAIL turnout definitions and macros.
*/

/* Rokuhan turnout macro
*  This macro ensures only the short pulse required to change the turnout
*  position is used to prevent coil burnouts in the turnouts.
*
*  Call this macro with:
*  ROKUHANTURNOUT(t, p1, p2)
*
*  Where:
*  t = turnout ID
*  p1 = direction pin
*  p2 = enable pin
*
*  Adjust the PULSE time (in ms) below as required, 25 seems reliable.
*
*  When a turnout command is sent to one of the defined turnouts, the macro
*  will close or throw the turnout using the defined PULSE time.
*/
#define PULSE 25

#define ROKUHANTURNOUT(t,p1,p2) \
ONCLOSE(t) \
SET(p1) \
SET(p2)DELAY(PULSE)RESET(p2) \
DONE \
ONTHROW(t) \
RESET(p1) \
SET(p2)DELAY(PULSE)RESET(p2) \
DONE

// Main to industry loop turnout definitions
PIN_TURNOUT(101, 164, "1 Main to industry loop 1") // Pair of left turnouts
PIN_TURNOUT(102, 165, "2 Industry loop to main 1")
PIN_TURNOUT(103, 166, "3 Main to industry loop 2") // Pair of right turnouts
PIN_TURNOUT(104, 167, "4 Industry loop to main 2")

// Industry loop turnouts
PIN_TURNOUT(105, 168, "5 Yard entrance")
PIN_TURNOUT(106, 169, "6 Inner industry loop entrance 1") // Behind roundhouse
PIN_TURNOUT(107, 170, "7 Inner industry loop entrance 2") // To right of main turnouts
PIN_TURNOUT(108, 171, "8 Car loading entrance")
PIN_TURNOUT(109, 180, "9 Container loading entrance")
PIN_TURNOUT(110, 181, "10 Warehouse siding entrance")
PIN_TURNOUT(111, 182, "11 Distribution centre entrance")
PIN_TURNOUT(112, 183, "12 Distribution centre split")
PIN_TURNOUT(113, 184, "13 TBA industry siding")

// Yard turnouts
PIN_TURNOUT(114, 185, "14 Yard entry branch") // First left turnout after entrance
PIN_TURNOUT(115, 186, "15 Runaround siding") // Entry to siding with runaround
PIN_TURNOUT(116, 187, "16 Rolling road entry")
PIN_TURNOUT(117, 196, "17 Turntable entry")
PIN_TURNOUT(118, 197, "18 Runaround 1") // Pair of right turnouts for runaround
PIN_TURNOUT(119, 198, "19 Runaround 2")
PIN_TURNOUT(120, 199, "20 Yard 1") // Right turnout
PIN_TURNOUT(121, 200, "21 Yard 2") // Left turnout
PIN_TURNOUT(122, 201, "22 Yard 3") // Left turnout

// What to do when turnout command sent
ROKUHANTURNOUT(101, 164, 172)
ROKUHANTURNOUT(102, 165, 173)
ROKUHANTURNOUT(103, 166, 174)
ROKUHANTURNOUT(104, 165, 175)
ROKUHANTURNOUT(105, 168, 176)
ROKUHANTURNOUT(106, 169, 177)
ROKUHANTURNOUT(107, 170, 178)
ROKUHANTURNOUT(108, 171, 179)
ROKUHANTURNOUT(109, 180, 188)
ROKUHANTURNOUT(110, 181, 189)
ROKUHANTURNOUT(111, 182, 190)
ROKUHANTURNOUT(112, 183, 191)
ROKUHANTURNOUT(113, 184, 192)
ROKUHANTURNOUT(114, 185, 193)
ROKUHANTURNOUT(115, 186, 194)
ROKUHANTURNOUT(116, 187, 195)
ROKUHANTURNOUT(117, 196, 204)
ROKUHANTURNOUT(118, 197, 205)
ROKUHANTURNOUT(119, 198, 206)
ROKUHANTURNOUT(120, 199, 207)
ROKUHANTURNOUT(121, 200, 208)
ROKUHANTURNOUT(122, 201, 209)

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

// Placehoder here to turn a relay on to supply turnout power
// Relay control sits on the last pin of the last MCP23017
SET(211)

// Close all turnouts on start up
CLOSE(101)
CLOSE(102)
CLOSE(103)
CLOSE(104)
CLOSE(105)
CLOSE(106)
CLOSE(107)
CLOSE(108)
CLOSE(109)
CLOSE(110)
CLOSE(111)
CLOSE(112)
CLOSE(113)
CLOSE(114)
CLOSE(115)
CLOSE(116)
CLOSE(117)
CLOSE(118)
CLOSE(119)
CLOSE(120)
CLOSE(121)
CLOSE(122)
DONE
