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

#define DECOUPLER(p1, desc, led_pin, alias) \
    ALIAS(alias, 300+p1) \
    ROUTE(300+p1, desc) \
        SERVO(p1, 400, Instant) \
        SET(led_pin) \
        DELAY(DECOUPLE_TIME) \
        SERVO(p1, 100, Instant) \
        RESET(led_pin) \
    DONE

DECOUPLER(101, "Warehouse decoupler", DECOUPLER1_LED, WAREHOUSE_DECOUPLER)
DECOUPLER(102, "Car loading decoupler", DECOUPLER2_LED, CAR_DECOUPLER)
DECOUPLER(103, "Container decoupler", DECOUPLER3_LED, CONTAINER_DECOUPLER)
DECOUPLER(104, "Storage 3 decoupler", DECOUPLER4_LED, STORAGE3_DECOUPLER)
DECOUPLER(105, "Storage 2 decoupler", DECOUPLER5_LED, STORAGE2_DECOUPLER)
DECOUPLER(106, "Storage 1 decoupler", DECOUPLER6_LED, STORAGE1_DECOUPLER)
DECOUPLER(107, "Maintenance decoupler", DECOUPLER7_LED, MAINTENANCE_DECOUPLER)
DONE
