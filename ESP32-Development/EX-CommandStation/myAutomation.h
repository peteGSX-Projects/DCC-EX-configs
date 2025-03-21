// IR sensor testing
// HAL(EXIOExpander,800,2,0x50)
// HAL(EXIOExpander,810,1,0x51)

// AUTOSTART SEQUENCE(100)
//   IF(800)
//     PRINT("Sensor 800 activated")
//   ENDIF
//   IF(801)
//     PRINT("Sensor 801 activated")
//   ENDIF
// FOLLOW(100)

AUTOMATION(100, "Throttle Handoff")
  FWD(20)
  DELAY(2000)
  FON(0)
  DELAY(5000)
  STOP
  DELAY(2000)
  REV(5000)
  FOFF(0)
  DELAY(2000)
  STOP
DONE

// Display testing
// AUTOSTART SEQUENCE(101)
//   SCREEN(1,0,"Test screen 0 row 0")
//   SCREEN(1,1,"Test screen 0 row 1")
//   SCREEN(1,2,"Test screen 0 row 2")
//   DELAY(3000)
//   SCREEN(1,0,"Change row 0 to a really long line of text for more screen function testing")
//   SCREEN(1,1,"Change row 1 to something")
//   SCREEN(1,2,"Row 2")
//   DELAY(3000)
//   SCREEN(1,0,"Suzuki Katanas rule")
//   SCREEN(1,1,"EXRAIL is cool")
//   SCREEN(1,2,"Coffee is good")
//   DELAY(3000)
// FOLLOW(101)

// Roster
ROSTER(2004, "QR 2004", "Lights/Horn/Bell/Whistle/Brakes/Idiots/Crap Programming")
ROSTER(2006, "QR 2006", "Lights")
ROSTER(2010, "QR 2010", "Lights")
ROSTER(1001, "QR 1001 - Testing", "Lights/Horn")
ROSTER(1002, "QR 1002 - Testing", "Lights/Horn")
ROSTER(1003, "QR 1003 - Testing", "Lights/Horn")
ROSTER(1004, "QR 1004 - Testing", "Lights/Horn")
ROSTER(1005, "QR 1005 - Testing", "Lights/Horn")
// ROSTER(1006, "QR 1006 - Testing", "Lights/Horn")
// ROSTER(1007, "QR 1007 - Testing", "Lights/Horn")
// ROSTER(1008, "QR 1008 - Testing", "Lights/Horn")
// ROSTER(1009, "QR 1009 - Testing", "Lights/Horn")

// Turntables
DCC_TURNTABLE(2,0,"Fake DCC turntable")
TT_ADDPOSITION(2,1,200,45,"Fake 1")
TT_ADDPOSITION(2,2,201,90,"Fake 2")
TT_ADDPOSITION(2,3,202,180,"Fake 3")
TT_ADDPOSITION(2,4,203,270,"Fake 4")
TT_ADDPOSITION(2,5,203,270,"Fake 5")
TT_ADDPOSITION(2,6,203,270,"Fake 6")
TT_ADDPOSITION(2,7,203,270,"Fake 7")
TT_ADDPOSITION(2,8,203,270,"Fake 8")
TT_ADDPOSITION(2,9,203,270,"Fake 9")
TT_ADDPOSITION(2,10,203,270,"Fake 10")
TT_ADDPOSITION(2,11,203,270,"Fake 11")

// Routes
ROUTE(1, "Test route 1")
  THROW(101)
  DELAY(1000)
  THROW(102)
  DELAY(1000)
  CLOSE(101)
  DELAY(1000)
  CLOSE(102)
DONE

// Turnouts
#define PULSE 50

#define ROKUHANTURNOUT(t, p1, p2, desc, ali) \
PIN_TURNOUT(t, 0, desc) \
ALIAS(ali, t) \
DONE \
ONCLOSE(t) \
SET(p1) \
SET(p2)DELAY(PULSE)RESET(p2) \
DONE \
ONTHROW(t) \
RESET(p1) \
SET(p2)DELAY(PULSE)RESET(p2) \
DONE \

ROKUHANTURNOUT(101, 802, 803, "Turnout 1", TRN_1)
ROKUHANTURNOUT(102, 804, 805, "Turnout 2", TRN_2)
ROKUHANTURNOUT(103, 806, 807, "Turnout 3", TRN_3)
ROKUHANTURNOUT(104, 808, 809, "Turnout 4", TRN_4)
ROKUHANTURNOUT(105, 810, 811, "Turnout 5", TRN_5)
ROKUHANTURNOUT(106, 812, 813, "Turnout 6", TRN_6)
ROKUHANTURNOUT(107, 814, 815, "Turnout 7", TRN_7)
ROKUHANTURNOUT(108, 816, 817, "Turnout 8", TRN_8)
ROKUHANTURNOUT(109, 818, 819, "Turnout 9", TRN_9)
ROKUHANTURNOUT(110, 820, 821, "Turnout 10", TRN_10)
ROKUHANTURNOUT(111, 822, 823, "Turnout 11", TRN_11)
ROKUHANTURNOUT(112, 824, 825, "Turnout 12", TRN_12)
ROKUHANTURNOUT(113, 826, 827, "Turnout 13", TRN_13)
ROKUHANTURNOUT(114, 818, 829, "Turnout 14", TRN_14)
ROKUHANTURNOUT(115, 830, 831, "Turnout 15", TRN_15)
