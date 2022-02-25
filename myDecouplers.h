/* myDecouplers.h
*  This file contains all decoupler definitions.
*
*  Decouplers have a magnet mounted on a servo arm and
*  these are moved into position and away again when
*  a route is called.
*/

/* Decoupler ROUTES macro
*  This macro defines the servo action, call with:
*  DECOUPLER(p1, desc)
*
*  Where:
*  - p1 = servo PWM pin
*  - desc = description to appear in Engine Driver
*
*  The route ID is calculated by adding 300 to the pin.
*/
#define DECOUPLE_TIME 10000

#define DECOUPLER(p1, desc) \
    ROUTE(300+p1, desc) \
        SERVO(p1, 10, Instant) \
        DELAY(DECOUPLE_TIME) \
        SERVO(p1, 200, Instant) \
    DONE

DECOUPLER(101, "Yard declouper 1 - right branch")
DECOUPLER(102, "Yard declouper 2 - run around entry")
DECOUPLER(103, "Run around declouper")
DECOUPLER(104, "Stall 7 declouper")
DECOUPLER(105, "Storage 1 declouper")
DECOUPLER(106, "Storage 2 declouper")
DECOUPLER(107, "Storage 3 declouper")
DECOUPLER(108, "Car loading declouper")
DECOUPLER(109, "Container loading declouper")
DECOUPLER(110, "Warehouse siding declouper")
DECOUPLER(111, "Distribution siding declouper")
DECOUPLER(112, "TBA siding declouper")
DONE
