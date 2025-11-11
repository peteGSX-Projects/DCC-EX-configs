// All point definitions and handlers live here.

/* Rokuhan point macro
*
*  This macro defines Rokuhan points as well as ensuring that these
*  points are driven only by a short pulse to prevent coil burn out.
*
*  Call this macro with:
*  ROKUHANPOINT(point_id, direction_pin, enable_pin, led_pin, button_pin, description)
*
*  Where:
*  point_id = Point/turnout ID used to control it
*  direction_pin = Vpin controlling L293D polarity
*  enable_pin = Vpin connected to the L293D enable pin
*  led_pin = Vpin of the mimic panel state LED
*  button_pin = Vpin of the mimic panel push button to toggle the point state
*  description = Text description of the point that appears in throttles
*
*  Adjust the PULSE time (in ms) below as required, 50 seems reliable.
*
*  When a turnout command is sent to one of the defined points, the macro
*  will close or throw the point using the defined PULSE time.
*
*  Further to this, the macro sets up the ONBUTTON() event handler for the toggle button,
*  as well as controlling the state of the mimic panel LED (green closed, red thrown)
*
*  This also ensures all points are defined as part of the compilation.
*/
#define PULSE 50

#define ROKUHAN_POINT(point_id,direction_pin,enable_pin,led_pin,button_pin,description) \
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
ONBUTTON(button_pin) \
  TOGGLE_TURNOUT(point_id) \
DONE

// Turnout definitions using the ROKUHAN_POINT macro

ROKUHAN_POINT(POINT_LOOP_STATION_ENTRY,POINT_1_DIR,POINT_1_EN,POINT_1_LED,POINT_1_BUTTON,"Loop station entry")
ROKUHAN_POINT(POINT_LOOP_STATION_EXIT,POINT_2_DIR,POINT_2_EN,POINT_2_LED,POINT_2_BUTTON,"Loop station exit")
ROKUHAN_POINT(POINT_LOOP_SIDING,POINT_3_DIR,POINT_3_EN,POINT_3_LED,POINT_3_BUTTON,"Loop siding")
ROKUHAN_POINT(POINT_LOOP_YARD,POINT_4_DIR,POINT_4_EN,POINT_4_LED,POINT_4_BUTTON,"Loop to yard")
ROKUHAN_POINT(POINT_MAIN_TURNTABLE,POINT_5_DIR,POINT_5_EN,POINT_5_LED,POINT_5_BUTTON,"Main to turntable")
ROKUHAN_POINT(POINT_MAIN_YARD,POINT_6_DIR,POINT_6_EN,POINT_6_LED,POINT_6_BUTTON,"Main to yard")
ROKUHAN_POINT(POINT_YARD_SIDING_1,POINT_7_DIR,POINT_7_EN,POINT_7_LED,POINT_7_BUTTON,"Yard siding 1")
ROKUHAN_POINT(POINT_YARD_LOOP,POINT_8_DIR,POINT_8_EN,POINT_8_LED,POINT_8_BUTTON,"Yard to loop")

ROUTE(CLOSE_ALL_POINTS,"Close all points")
  CLOSE(POINT_LOOP_STATION_ENTRY)
  CLOSE(POINT_LOOP_SIDING)
  CLOSE(POINT_MAIN_TURNTABLE)
  CLOSE(POINT_YARD_SIDING_1)
  DELAY(4000) // Let CDUs recharge
  CLOSE(POINT_LOOP_STATION_EXIT)
  CLOSE(POINT_LOOP_YARD)
  CLOSE(POINT_MAIN_YARD)
  CLOSE(POINT_YARD_LOOP)
DONE
