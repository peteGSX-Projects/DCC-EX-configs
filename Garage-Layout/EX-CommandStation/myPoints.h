/* myPoints.h
*  This file contains all point macros and definitions.
*
*  Any related activities that need to occur on startup need to
*  be included in myAutomation.h to ensure they are in the 
*  correct order when compiled.
*/

/* Rokuhan point macro
*  This macro defines Rokuhan points as well as ensuring that these
*  points are driven only by a short pulse to prevent coil burn out.
*
*  Call this macro with:
*  ROKUHANPOINT(point_id, dir_pin, en_pin, description, alias)
*
*  Where:
*  point_id = Point/turnout ID used to control it
*  dir_pin = Direction pin
*  en_pin = Enable pin
*  description = Text description of the point that appears in throttles
*  alias = Alias assigned to the point ID to be used in automations/routes
*
*  Adjust the PULSE time (in ms) below as required, 50 seems reliable.
*
*  When a turnout command is sent to one of the defined points, the macro
*  will close or throw the point using the defined PULSE time.
*
*  This also ensures all points are defined as part of the compilation.
*/
#define PULSE 50

#define ROKUHANPOINT(point_id, dir_pin, en_pin, description, alias) \
VIRTUAL_TURNOUT(point_id, description) \
ALIAS(alias, point_id) \
DONE \
ONCLOSE(point_id) \
SET(dir_pin) \
SET(en_pin)DELAY(PULSE)RESET(en_pin) \
DONE \
ONTHROW(point) \
RESET(dir_pin) \
SET(en_pin)DELAY(PULSE)RESET(en_pin) \
DONE

// Turnout definitions using the ROKUHANPOINT macro

ROKUHANPOINT(3,POINT5_DIR,POINT5_EN,"Point 3",POINT3)
ROKUHANPOINT(4,POINT6_DIR,POINT6_EN,"Point 4",POINT4)
ROKUHANPOINT(5,POINT7_DIR,POINT7_EN,"Point 5",POINT5)
ROKUHANPOINT(6,POINT8_DIR,POINT8_EN,"Point 6",POINT6)
ROKUHANPOINT(7,POINT9_DIR,POINT9_EN,"Point 7",POINT7)
ROKUHANPOINT(8,POINT10_DIR,POINT10_EN,"Point 8",POINT8)
ROKUHANPOINT(9,POINT11_DIR,POINT11_EN,"Point 9",POINT9)
ROKUHANPOINT(10,POINT12_DIR,POINT12_EN,"Point 10",POINT10)
ROKUHANPOINT(11,POINT13_DIR,POINT13_EN,"Point 11",POINT11)
ROKUHANPOINT(12,POINT14_DIR,POINT14_EN,"Point 12",POINT12)

/* Rokuhan point pair macro
*  This macro defines Rokuhan points as pairs as well as ensuring that these
*  points are driven only by a short pulse to prevent coil burn out.
*
*  Two turnouts are configured by this macro to operate together when closing/throwing.
*
*  Call this macro with:
*  ROKUHANPOINTPAIR(point1_id, point1_dir, point1_en, point2_dir, point2_en, description, alias)
*
*  Where:
*  point1_id = turnout ID for the first turnout
*  point1_dir = direction pin for the first turnout
*  point1_en = enable pin for the first turnout
*  description = description of the turnout pair
*  alias = alias assigned to the first turnout ID (this is the only alias defined)
*  point2_dir = direction pin for the second turnout
*  point2_en = enable pin for the second turnout
*
*  Adjust the PULSE time (in ms) below as required, 50 seems reliable (defined above).
*
*  When a turnout command is sent to one of the defined points, the macro
*  will close or throw the point using the defined PULSE time.
*
*  This also ensures all points are defined as part of the compilation.
*/
#define ROKUHANPOINTPAIR(point1_id, point1_dir, point1_en, point2_dir, point2_en, description, alias) \
VIRTUAL_TURNOUT(point1_id, description) \
ALIAS(alias, point1_id) \
DONE \
ONCLOSE(point1_id) \
SET(point1_dir) SET(point2_dir) \
SET(point1_en) SET(point2_en) DELAY(PULSE) RESET(point1_en) RESET(point2_en) \
DONE \
ONTHROW(point1_id) \
RESET(point1_dir) RESET(point2_dir) \
SET(point1_en) SET(point2_en) DELAY(PULSE) RESET(point1_en) RESET(point2_en) \
DONE

ROKUHANPOINTPAIR(1,POINT1_DIR,POINT1_EN,POINT2_DIR,POINT2_EN,"Point pair 1",POINT1)
ROKUHANPOINTPAIR(2,POINT3_DIR,POINT3_EN,POINT4_DIR,POINT4_EN,"Point pair 2",POINT2)
