// All decoupler definitions and handlers live here.

/* Decoupler macro
*
*  This macro defines the decoupler event handlers and routes.
*
*  Call this macro with:
*  DECOUPLER(route_id,servo_pin,led_pin,button_pin,description)
*
*  Where:
*  route_id = Route ID used to publish to throttles
*  servo_pin = Vpin controlling the decoupler servo
*  led_pin = Vpin of the mimic panel state LED
*  button_pin = Vpin of the mimic panel push button
*  description = Text description of the decoupler route that appears in throttles
*
*  Adjust the DECOUPLE_TIME (in ms) below as required.
*
*  Adjust ACTIVE_POSITION and INACTIVE_POSITION as required.
*/
#define DECOUPLE_TIME 10000
#define ACTIVE_POSITION 400 // PWM value for raising the servo/magnet
#define INACTIVE_POSITION 100 // PWM value for lowering the servo/magnet

#define DECOUPLER(route_id,servo_pin,led_pin,button_pin,description) \
ONBUTTON(button_pin) \
  START(route_id) \
DONE \
ROUTE(route_id,description) \
  SET(led_pin) \  
  SERVO(servo_pin,ACTIVE_POSITION,Instant) \
  DELAY(DECOUPLE_TIME) \
  SERVO(servo_pin,INACTIVE_POSITION,Instant) \
  RESET(led_pin) \
DONE

DECOUPLER(DECOUPLER_MAIN,DECOUPLER_MAIN_SERVO,DECOUPLER_MAIN_LED,DECOUPLER_MAIN_BUTTON,"Main decoupler")
DECOUPLER(DECOUPLER_SIDING_1,DECOUPLER_SIDING_1_SERVO,DECOUPLER_SIDING_1_LED,DECOUPLER_SIDING_1_BUTTON,"Siding 1 decoupler")
DECOUPLER(DECOUPLER_SIDING_2,DECOUPLER_SIDING_2_SERVO,DECOUPLER_SIDING_2_LED,DECOUPLER_SIDING_2_BUTTON,"Siding 2 decoupler")
DECOUPLER(DECOUPLER_LOOP_SIDING,DECOUPLER_LOOP_SIDING_SERVO,DECOUPLER_LOOP_SIDING_LED,DECOUPLER_LOOP_SIDING_BUTTON,"Loop siding decoupler")
