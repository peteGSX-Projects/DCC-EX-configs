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
*  ROKUHANPOINT(point_id,dir_pin,en_pin,description,led_pin,close_pin,throw_pin)
*
*  Where:
*  point_id = Point/turnout ID used to control it
*  sequence_id = Sequence ID to monitor for mimic panel inputs
*  dir_pin = Direction Vpin
*  en_pin = Enable Vpin
*  description = Text description of the point that appears in throttles
*  led_pin = Vpin that sets/resets mimic panel LED
*  close_pin = Vpin that triggers a CLOSE event from the mimic panel
*  throw_pin = Vpin that triggers a THROW event from the mimic panel
*
*  Adjust the PULSE time (in ms) below as required, 50 seems reliable.
*
*  When a turnout command is sent to one of the defined points, the macro
*  will close or throw the point using the defined PULSE time.
*
*  This also ensures all points are defined as part of the compilation.
*/
#define PULSE 50

#define ROKUHANPOINT(point_id,sequence_id,dir_pin,en_pin,description,led_pin,close_pin,throw_pin) \
VIRTUAL_TURNOUT(point_id, description) \
DONE \
ONCLOSE(point_id) \
  SET(dir_pin) \
  SET(en_pin)DELAY(PULSE)RESET(en_pin) \
  RESET(led_pin) \
DONE \
ONTHROW(point_id) \
  RESET(dir_pin) \
  SET(en_pin)DELAY(PULSE)RESET(en_pin) \
  SET(led_pin) \
DONE \
AUTOSTART SEQUENCE(sequence_id) \
  IF(close_pin) \
    AFTER(close_pin) \
      IFTHROWN(point_id) \
        CLOSE(point_id) \
      ENDIF \
  ENDIF \
  IF(throw_pin) \
    AFTER(throw_pin) \
      IFCLOSED(point_id) \
        THROW(point_id) \
      ENDIF \
  ENDIF \
FOLLOW(point_id)

// Turnout definitions using the ROKUHANPOINT macro

ROKUHANPOINT(CONTAINER_SIDING,CONTAINER_SIDING_SEQ,POINT5_DIR,POINT5_EN,"Container siding",POINT5_LED,POINT5_CLOSE,POINT5_THROW)
ROKUHANPOINT(CAR_SIDING,CAR_SIDING_SEQ,POINT6_DIR,POINT6_EN,"Car siding",POINT6_LED,POINT6_CLOSE,POINT6_THROW)
ROKUHANPOINT(WAREHOUSE_SIDING,WAREHOUSE_SIDING_SEQ,POINT7_DIR,POINT7_EN,"Warehouse siding",POINT7_LED,POINT7_CLOSE,POINT7_THROW)
ROKUHANPOINT(INDUSTRY_LOOP_EAST,INDUSTRY_LOOP_EAST_SEQ,POINT8_DIR,POINT8_EN,"Industry East",POINT8_LED,POINT8_CLOSE,POINT8_THROW)
ROKUHANPOINT(TURNTABLE_ACCESS,TURNTABLE_ACCESS_SEQ,POINT9_DIR,POINT9_EN,"Turntable access",POINT9_LED,POINT9_CLOSE,POINT9_THROW)
ROKUHANPOINT(STORAGE_3,STORAGE_3_SEQ,POINT10_DIR,POINT10_EN,"Storage 3",POINT10_LED,POINT10_CLOSE,POINT10_THROW)
ROKUHANPOINT(STORAGE_2,STORAGE_2_SEQ,POINT11_DIR,POINT11_EN,"Storage 2",POINT11_LED,POINT11_CLOSE,POINT11_THROW)
ROKUHANPOINT(MAINTENANCE,MAINTENANCE_SEQ,POINT12_DIR,POINT12_EN,"Maintenance",POINT12_LED,POINT12_CLOSE,POINT12_THROW)
ROKUHANPOINT(STORAGE_1_AND_MAINTENANCE,STORAGE_1_AND_MAINTENANCE_SEQ,POINT13_DIR,POINT13_EN,"Storage 1 and maintenance",POINT13_LED,POINT13_CLOSE,POINT13_THROW)
ROKUHANPOINT(YARD_ACCESS,YARD_ACCESS_SEQ,POINT14_DIR,POINT14_EN,"Yard access",POINT14_LED,POINT14_CLOSE,POINT14_THROW)
ROKUHANPOINT(INDUSTRY_LOOP_WEST,INDUSTRY_LOOP_WEST_SEQ,POINT15_DIR,POINT15_EN,"Industry West",POINT15_LED,POINT15_CLOSE,POINT15_THROW)

/* Rokuhan point pair macro
*  This macro defines Rokuhan points as pairs as well as ensuring that these
*  points are driven only by a short pulse to prevent coil burn out.
*
*  Two turnouts are configured by this macro to operate together when closing/throwing.
*
*  Call this macro with:
*  ROKUHANPOINTPAIR(point_id,point1_dir,point1_en,point2_dir,point2_en,description,led_pin1,led_pin2,close_pin1,throw_pin1,close_pin2,throw_pin2)
*
*  Where:
*  point_id = Point/turnout ID to control the virtual turnout
*  sequence_id = Sequence ID to monitor for mimic panel inputs
*  point1_dir = direction pin for the first physical turnout
*  point1_en = enable pin for the first physical turnout
*  point2_dir = direction pin for the second turnout
*  point2_en = enable pin for the second turnout
*  description = description of the turnout pair
*  led_pin1 = Vpin that sets/resets the mimic panel LED for the first physical turnout
*  led_pin2 = Vpin that sets/resets the mimic panel LED for the second physical turnout
*  close_pin1 = Vpin that triggers a CLOSE event from the mimic panel for the first physical turnout
*  throw_pin1 = Vpin that triggers a THROW event from the mimic panel for the first physical turnout
*  close_pin2 = Vpin that triggers a CLOSE event from the mimic panel for the second physical turnout
*  throw_pin2 = Vpin that triggers a THROW event from the mimic panel for the second physical turnout
*
*  Adjust the PULSE time (in ms) below as required, 50 seems reliable (defined above).
*
*  When a turnout command is sent to one of the defined points, the macro
*  will close or throw the point using the defined PULSE time.
*
*  This also ensures all points are defined as part of the compilation.
*/
#define ROKUHANPOINTPAIR(point_id,sequence_id,point1_dir,point1_en,point2_dir,point2_en,description,led_pin1,led_pin2,close_pin1,throw_pin1,close_pin2,throw_pin2) \
VIRTUAL_TURNOUT(point_id, description) \
DONE \
ONCLOSE(point_id) \
SET(point1_dir) SET(point2_dir) \
SET(point1_en) SET(point2_en) DELAY(PULSE) RESET(point1_en) RESET(point2_en) \
RESET(led_pin1) RESET(led_pin2) \
DONE \
ONTHROW(point_id) \
RESET(point1_dir) RESET(point2_dir) \
SET(point1_en) SET(point2_en) DELAY(PULSE) RESET(point1_en) RESET(point2_en) \
SET(led_pin1) SET(led_pin2) \
DONE \
AUTOSTART SEQUENCE(sequence_id) \
  IF(close_pin1) \
    AFTER(close_pin1) \
      IFTHROWN(point_id) \
        CLOSE(point_id) \
      ENDIF \
  ENDIF \
  IF(throw_pin1) \
    AFTER(throw_pin1) \
      IFCLOSED(point_id) \
        THROW(point_id) \
      ENDIF \
  ENDIF \
  IF(close_pin2) \
    AFTER(close_pin2) \
      IFTHROWN(point_id) \
        CLOSE(point_id) \
      ENDIF \
  ENDIF \
  IF(throw_pin2) \
    AFTER(throw_pin2) \
      IFCLOSED(point_id) \
        THROW(point_id) \
      ENDIF \
  ENDIF \
FOLLOW(point_id)

ROKUHANPOINTPAIR(STATION_SIDING_WEST,STATION_SIDING_WEST_SEQ,POINT1_DIR,POINT1_EN,POINT2_DIR,POINT2_EN,"Station West",POINT1_LED,POINT2_LED,POINT1_CLOSE,POINT1_THROW,POINT2_CLOSE,POINT2_THROW)
ROKUHANPOINTPAIR(STATION_SIDING_EAST,STATION_SIDING_EAST_SEQ,POINT3_DIR,POINT3_EN,POINT4_DIR,POINT4_EN,"Station East",POINT3_LED,POINT4_LED,POINT3_CLOSE,POINT3_THROW,POINT4_CLOSE,POINT4_THROW)
