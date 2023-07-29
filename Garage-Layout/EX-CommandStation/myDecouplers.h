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

#define DECOUPLER(p1, desc, led_pin) \
    ROUTE(300+p1, desc) \
        SERVO(p1, 400, Instant) \
        SET(led_pin) \
        DELAY(DECOUPLE_TIME) \
        SERVO(p1, 100, Instant) \
        UNSET(led_pin) \
    DONE

DECOUPLER(101, "Container decoupler", DECOUPLER1_LED)
DECOUPLER(102, "Car decoupler", DECOUPLER2_LED)
DECOUPLER(103, "Warehouse decoupler", DECOUPLER3_LED)
DECOUPLER(104, "Storage 3 decoupler", DECOUPLER4_LED)
DECOUPLER(105, "Storage 2 decoupler", DECOUPLER5_LED)
DECOUPLER(106, "Storage 1 decoupler", DECOUPLER6_LED)
DECOUPLER(107, "Maintenance decoupler", DECOUPLER7_LED)
DONE
