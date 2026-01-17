// No hardware devices
HAL_IGNORE_DEFAULTS

// Roster
ROSTER(2004, "QR 2004", "Lights/*Horn/Bell/Whistle/Brakes/Idiots/Crap Programming")
ROSTER(2006, "QR 2006", "Lights")
ROSTER(2010, "QR 2010", "Lights")
ROSTER(1001, "QR 1001 - Testing", "Lights/Horn")
ROSTER(1002, "QR 1002 - Testing", "Lights/Horn")
ROSTER(1003, "QR 1003 - Testing", "Lights/Horn")
ROSTER(1004, "QR 1004 - Testing", "Lights/Horn")
ROSTER(1005, "QR 1005 - Testing", "Lights/Horn")
ROSTER(1006, "QR 1006 - Testing", "Lights/Horn")
ROSTER(1007, "QR 1007 - Testing", "Lights/Horn")
ROSTER(1008, "QR 1008 - Testing", "Lights/Horn")
ROSTER(1009, "QR 1009 - Testing", "Lights/Horn")

// Turnouts
VIRTUAL_TURNOUT(1, "Point 1")
VIRTUAL_TURNOUT(2, "Point 2")
VIRTUAL_TURNOUT(3, "Point 3")
VIRTUAL_TURNOUT(4, "Point 4")
VIRTUAL_TURNOUT(5, "Point 5")
VIRTUAL_TURNOUT(6, "Point 6")
VIRTUAL_TURNOUT(7, "Point 7")
VIRTUAL_TURNOUT(8, "Point 8")
VIRTUAL_TURNOUT(9, "Point 9")
VIRTUAL_TURNOUT(10, "Point 10")
VIRTUAL_TURNOUT(11, "Point 11")
VIRTUAL_TURNOUT(12, "Point 12")
VIRTUAL_TURNOUT(13, "Point 13")
VIRTUAL_TURNOUT(14, "Point 14")
VIRTUAL_TURNOUT(15, "Point 15")

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
ROUTE(1, "Route 1")
  PRINT("Start Route 1")
DONE
ROUTE(2, "Route 2")
  PRINT("Start Route 2")
DONE
ROUTE(3, "Route 3")
  PRINT("Start Route 2")
DONE
ROUTE(4, "Route 4")
  PRINT("Start Route 4")
DONE
ROUTE(5, "Route 5")
  PRINT("Start Route 5")
DONE
ROUTE(6, "Route 6")
  PRINT("Start Route 6")
DONE
ROUTE(7, "Route 7")
  PRINT("Start Route 7")
DONE
ROUTE(8, "Route 8")
  PRINT("Start Route 8")
DONE
ROUTE(9, "Route 9")
  PRINT("Start Route 9")
DONE
ROUTE(10, "Route 10")
  PRINT("Start Route 10")
DONE
ROUTE(11, "Route 11")
  PRINT("Start Route 11")
DONE
ROUTE(12, "Route 12")
  PRINT("Start Route 12")
DONE
ROUTE(13, "Route 13")
  PRINT("Start Route 13")
DONE

// Automations
AUTOMATION(20, "Automation 1")
  PRINT("Start Automation 1")
  FWD(20)
  DELAY(2000)
  STOP
  REV(20)
  DELAY(2000)
  STOP
DONE
AUTOMATION(21, "Automation 2")
  PRINT("Start Automation 2")
  FWD(20)
  DELAY(2000)
  STOP
  REV(20)
  DELAY(2000)
  STOP
DONE
AUTOMATION(22, "Automation 3")
  PRINT("Start Automation 3")
  FWD(20)
  DELAY(2000)
  STOP
  REV(20)
  DELAY(2000)
  STOP
DONE
AUTOMATION(23, "Automation 4")
  PRINT("Start Automation 4")
  FWD(20)
  DELAY(2000)
  STOP
  REV(20)
  DELAY(2000)
  STOP
DONE
AUTOMATION(24, "Automation 5")
  PRINT("Start Automation 5")
  FWD(20)
  DELAY(2000)
  STOP
  REV(20)
  DELAY(2000)
  STOP
DONE
AUTOMATION(25, "Automation 6")
  PRINT("Start Automation 6")
  FWD(20)
  DELAY(2000)
  STOP
  REV(20)
  DELAY(2000)
  STOP
DONE
AUTOMATION(26, "Automation 7")
  PRINT("Start Automation 7")
  FWD(20)
  DELAY(2000)
  STOP
  REV(20)
  DELAY(2000)
  STOP
DONE
AUTOMATION(27, "Automation 8")
  PRINT("Start Automation 8")
  FWD(20)
  DELAY(2000)
  STOP
  REV(20)
  DELAY(2000)
  STOP
DONE
AUTOMATION(28, "Automation 9")
  PRINT("Start Automation 9")
  FWD(20)
  DELAY(2000)
  STOP
  REV(20)
  DELAY(2000)
  STOP
DONE
AUTOMATION(29, "Automation 10")
  PRINT("Start Automation 10")
  FWD(20)
  DELAY(2000)
  STOP
  REV(20)
  DELAY(2000)
  STOP
DONE
AUTOMATION(30, "Automation 11")
  PRINT("Start Automation 11")
  FWD(20)
  DELAY(2000)
  STOP
  REV(20)
  DELAY(2000)
  STOP
DONE
AUTOMATION(31, "Automation 12")
  PRINT("Start Automation 12")
  FWD(20)
  DELAY(2000)
  STOP
  REV(20)
  DELAY(2000)
  STOP
DONE
AUTOMATION(32, "Automation 13")
  PRINT("Start Automation 13")
  FWD(20)
  DELAY(2000)
  STOP
  REV(20)
  DELAY(2000)
  STOP
DONE
