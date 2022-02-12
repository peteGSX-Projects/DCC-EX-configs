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
RESET(p1) \
SET(p2)DELAY(25)RESET(p2)

// Initial pin states to close and enable off for L293D
//SET(164)
//RESET(172)
SET(32)
RESET(33)

// Turnout definitions below
PIN_TURNOUT(101, 0, "Main to inner loop 1")
//PIN_TURNOUT(101, 164, "Main to inner loop 1")
//PIN_TURNOUT(102, 165, "Main to inner loop 2")
//PIN_TURNOUT(103, 166, "Inner loop to main 1")
//PIN_TURNOUT(104, 167, "Inner loop to main 2")
DONE

// What to do when turnout command sent
//ROKUHANTURNOUT(101, 164, 172)
ROKUHANTURNOUT(101, 32, 33)
DONE
