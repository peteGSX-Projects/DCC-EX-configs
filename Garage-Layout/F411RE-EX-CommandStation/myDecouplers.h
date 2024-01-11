/* myDecouplers.h
*  This file contains all decoupler definitions.
*
*  Decouplers have a magnet mounted on a servo arm and
*  these are moved into position and away again when
*  a route is called.
*/

/* Decoupler ROUTES macro
*  This macro defines the servo action, call with:
*  DECOUPLER(p1, desc, raised, lowered, led_pin)
*
*  Where:
*  - p1 = servo PWM Vpin
*  - desc = description to appear in Engine Driver
*  - raised = servo PWM value for the raised position
*  - lowered = servo PWM value for the lowered position
*  - led_pin = Vpin for the mimic panel LED
*  - route_id = ID of the route to create
*
*  The route ID is calculated by adding 300 to the pin.
*/
#define DECOUPLE_TIME 10000

#define DECOUPLER(p1, desc, raised, lowered, led_pin, route_id) \
    ROUTE(route_id, desc) \
        SERVO(p1, raised, Instant) \
        SET(led_pin) \
        DELAY(DECOUPLE_TIME) \
        SERVO(p1, lowered, Instant) \
        RESET(led_pin) \
    DONE

DECOUPLER(DECOUPLER1, "Warehouse decoupler", 400, 100, DECOUPLER1_LED, WAREHOUSE_DECOUPLER)
DECOUPLER(DECOUPLER2, "Car loading decoupler", 400, 100, DECOUPLER2_LED, CAR_DECOUPLER)
DECOUPLER(DECOUPLER3, "Container decoupler", 400, 100, DECOUPLER3_LED, CONTAINER_DECOUPLER)
DECOUPLER(DECOUPLER4, "Storage 3 decoupler", 400, 100, DECOUPLER4_LED, STORAGE3_DECOUPLER)
DECOUPLER(DECOUPLER5, "Storage 2 decoupler", 400, 100, DECOUPLER5_LED, STORAGE2_DECOUPLER)
DECOUPLER(DECOUPLER6, "Storage 1 decoupler", 400, 100, DECOUPLER6_LED, STORAGE1_DECOUPLER)
DECOUPLER(DECOUPLER7, "Maintenance decoupler", 400, 100, DECOUPLER7_LED, MAINTENANCE_DECOUPLER)
DONE
