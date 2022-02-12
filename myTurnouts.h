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

// Set L293D enable off to start
RESET(172)
RESET(173)
RESET(174)
RESET(175)

// Turnout definitions below
PIN_TURNOUT(101, 164, "Main to inner loop 1")
PIN_TURNOUT(102, 165, "Main to inner loop 2")
PIN_TURNOUT(103, 166, "Inner loop to main 1")
PIN_TURNOUT(104, 167, "Inner loop to main 2")

// Placehoder here to turn a relay on to supply turnout power
// SET(xxx)
DONE

// What to do when turnout command sent
ROKUHANTURNOUT(101, 164, 172)
ROKUHANTURNOUT(102, 165, 173)
ROKUHANTURNOUT(103, 166, 174)
ROKUHANTURNOUT(104, 165, 175)
DONE
