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

#define ROKUHANPOINT(point_id,dir_pin,en_pin,description,alias,led_pin,close_pin,throw_pin) \
ALIAS(alias, point_id) \
VIRTUAL_TURNOUT(alias, description) \
DONE \
ONCLOSE(alias) \
  SET(dir_pin) \
  SET(en_pin)DELAY(PULSE)RESET(en_pin) \
  RESET(led_pin) \
DONE \
ONTHROW(alias) \
  RESET(dir_pin) \
  SET(en_pin)DELAY(PULSE)RESET(en_pin) \
  SET(led_pin) \
DONE \
AUTOSTART SEQUENCE(alias) \
  IF(close_pin) \
    AFTER(close_pin) \
      IFTHROWN(alias) \
        CLOSE(alias) \
      ENDIF \
  ENDIF \
  IF(throw_pin) \
    AFTER(throw_pin) \
      IFCLOSED(alias) \
        THROW(alias) \
      ENDIF \
  ENDIF \
FOLLOW(alias)

// Turnout definitions using the ROKUHANPOINT macro

ROKUHANPOINT(3,POINT5_DIR,POINT5_EN,"Container siding",CONTAINER_SIDING,POINT5_LED,POINT5_CLOSE,POINT5_THROW)
ROKUHANPOINT(4,POINT6_DIR,POINT6_EN,"Car siding",CAR_SIDING,POINT6_LED,POINT6_CLOSE,POINT6_THROW)
ROKUHANPOINT(5,POINT7_DIR,POINT7_EN,"Warehouse siding",WAREHOUSE_SIDING,POINT7_LED,POINT7_CLOSE,POINT7_THROW)
ROKUHANPOINT(6,POINT8_DIR,POINT8_EN,"Industry loop east",INDUSTRY_LOOP_EAST,POINT8_LED,POINT8_CLOSE,POINT8_THROW)
ROKUHANPOINT(7,POINT9_DIR,POINT9_EN,"Turntable access",TURNTABLE_ACCESS,POINT9_LED,POINT9_CLOSE,POINT9_THROW)
ROKUHANPOINT(8,POINT10_DIR,POINT10_EN,"Storage 3",STORAGE_3,POINT10_LED,POINT10_CLOSE,POINT10_THROW)
ROKUHANPOINT(9,POINT11_DIR,POINT11_EN,"Storage 2",STORAGE_2,POINT11_LED,POINT11_CLOSE,POINT11_THROW)
ROKUHANPOINT(10,POINT12_DIR,POINT12_EN,"Maintenance",MAINTENANCE,POINT12_LED,POINT12_CLOSE,POINT12_THROW)
ROKUHANPOINT(11,POINT13_DIR,POINT13_EN,"Storage 1 and maintenance",STORAGE_1_AND_MAINTENANCE,POINT13_LED,POINT13_CLOSE,POINT13_THROW)
ROKUHANPOINT(12,POINT14_DIR,POINT14_EN,"Yard access",YARD_ACCESS,POINT14_LED,POINT14_CLOSE,POINT14_THROW)
ROKUHANPOINT(13,POINT15_DIR,POINT15_EN,"Industry loop west",INDUSTRY_LOOP_WEST,POINT15_LED,POINT15_CLOSE,POINT15_THROW)

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
#define ROKUHANPOINTPAIR(point_id,point1_dir,point1_en,point2_dir,point2_en,description,alias,led_pin1,led_pin2,close_pin1,throw_pin1,close_pin2,throw_pin2) \
ALIAS(alias, point_id) \
VIRTUAL_TURNOUT(alias, description) \
DONE \
ONCLOSE(alias) \
SET(point1_dir) SET(point2_dir) \
SET(point1_en) SET(point2_en) DELAY(PULSE) RESET(point1_en) RESET(point2_en) \
RESET(led_pin1) RESET(led_pin2) \
DONE \
ONTHROW(alias) \
RESET(point1_dir) RESET(point2_dir) \
SET(point1_en) SET(point2_en) DELAY(PULSE) RESET(point1_en) RESET(point2_en) \
SET(led_pin1) SET(led_pin2) \
DONE \
AUTOSTART SEQUENCE(alias) \
  IF(close_pin1) \
    AFTER(close_pin1) \
      IFTHROWN(alias) \
        CLOSE(alias) \
      ENDIF \
  ENDIF \
  IF(throw_pin1) \
    AFTER(throw_pin1) \
      IFCLOSED(alias) \
        THROW(alias) \
      ENDIF \
  ENDIF \
  IF(close_pin2) \
    AFTER(close_pin2) \
      IFTHROWN(alias) \
        CLOSE(alias) \
      ENDIF \
  ENDIF \
  IF(throw_pin2) \
    AFTER(throw_pin2) \
      IFCLOSED(alias) \
        THROW(alias) \
      ENDIF \
  ENDIF \
FOLLOW(alias)

ROKUHANPOINTPAIR(1,POINT1_DIR,POINT1_EN,POINT2_DIR,POINT2_EN,"Station siding west",STATION_SIDING_WEST,POINT1_LED,POINT2_LED,POINT1_CLOSE,POINT1_THROW,POINT2_CLOSE,POINT2_THROW)
ROKUHANPOINTPAIR(2,POINT3_DIR,POINT3_EN,POINT4_DIR,POINT4_EN,"Station siding east",STATION_SIDING_EAST,POINT3_LED,POINT4_LED,POINT3_CLOSE,POINT3_THROW,POINT4_CLOSE,POINT4_THROW)
