/* myRollingRoad.h
*  This file contains the definition for the rolling
*  road and defines the WiThrottle ROUTEs.
*/

/* Programming mode ROUTE
*  This route ensures the rolling road is physically
*  separated from the siding, and UNJOINs from the
*  main track to allow service mode programming.
*/
ROUTE(501, "Rolling road progamming mode")
    SERVO(115, 0, Slow)
    UNJOIN
    DONE

/* Run in mode ROUTE
*  This route ensures the rolling road is physically
*  separated from the siding, and JOINs to the main
*  track to allow for motor run in.
*/
ROUTE(502, "Rolling road run in mode")
    SERVO(115, 0, Slow)
    JOIN
    DONE

/* Drive to main mode ROUTE
*  This route connects the rolling road to the siding
*  and JOINs to the main track to allow a loco to drive
*  back onto the main track.
*/
ROUTE(503, "Rolling road to main mode")
    SERVO(115, 200, Slow)
    JOIN
    DONE
