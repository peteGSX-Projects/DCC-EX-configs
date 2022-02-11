/*
myTurnouts.h contains all my EX-RAIL turnout definitions.
*/

/*
Rokuhan turnout macro

This macro ensures only the short pulse required to change the turnout
position is used.

t = turnout ID
p1 = direction pin
p2 = enable pin
*/
#define ROKUHANTURNOUT(t,p1,p2) \
ONCLOSE(t) \
SET(p1) \
SET(p2)DELAY(25)RESET(p2) \
ONTHROW(t) \
RESET(p2) \
SET(p1)DELAY(25)RESET(p1)

// Turnout definitions below
PIN_TURNOUT(1, 164, "Main to inner loop 1")
PIN_TURNOUT(2, 165, "Main to inner loop 2")
PIN_TURNOUT(3, 166, "Inner loop to main 1")
PIN_TURNOUT(4, 167, "Inner loop to main 2")
DONE
