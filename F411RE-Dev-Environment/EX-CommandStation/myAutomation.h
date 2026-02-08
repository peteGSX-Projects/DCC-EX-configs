// No hardware devices
HAL_IGNORE_DEFAULTS

// Roster
ROSTER(3, "Loco 3", "Lights/*Horn")
ROSTER(33, "Loco 33", "Lights/*Horn")
ROSTER(333, "Loco 333", "Lights/*Horn")
ROSTER(3333, "Loco 3333", "Lights/*Horn")
ROSTER(10003, "Loco 10003", "Lights/*Horn")
ROSTER(2004, "QR 2004", "Lights/*Horn/Bell/Whistle/Brakes/Idiots/Crap Programming")
ROSTER(2006, "QR 2006", "Lights")
ROSTER(2010, "QR 2010", "Lights")
ROSTER(1001, "QR 1001", "Lights/Horn")
ROSTER(1002, "QR 1002", "Lights/Horn")
ROSTER(1003, "QR 1003", "Lights/Horn")
ROSTER(1004, "QR 1004", "Lights/Horn")
ROSTER(1005, "QR 1005", "Lights/Horn")
ROSTER(1006, "QR 1006", "Lights/Horn")
ROSTER(1007, "QR 1007", "Lights/Horn")
ROSTER(1008, "QR 1008", "Lights/Horn")
ROSTER(1009, "QR 1009", "Lights/Horn")

// Turnouts
VIRTUAL_TURNOUT(1, "Point 1")
VIRTUAL_TURNOUT(2, "Point 2")
VIRTUAL_TURNOUT(3, "Point 3")
VIRTUAL_TURNOUT(4, "Point 4")
VIRTUAL_TURNOUT(5, "Point 5")

// Turntables
DCC_TURNTABLE(2,0,"Fake DCC turntable")
TT_ADDPOSITION(2,1,200,45,"Fake 1")
TT_ADDPOSITION(2,2,201,90,"Fake 2")
TT_ADDPOSITION(2,3,202,180,"Fake 3")
TT_ADDPOSITION(2,4,203,270,"Fake 4")
TT_ADDPOSITION(2,5,203,270,"Fake 5")

// Routes
ROUTE(1, "Route 1")
  PRINT("Start Route 1")
DONE
ROUTE(2, "Route 2")
  PRINT("Start Route 2")
DONE
ROUTE(3, "Route 3")
  PRINT("Start Route 3")
DONE

// Automations
AUTOMATION(21, "Automation 1")
  PRINT("Start Automation 1")
  FWD(20)
  DELAY(2000)
  STOP
  DELAY(2000)
  REV(20)
  DELAY(2000)
  STOP
DONE
AUTOMATION(22, "Automation 2")
  PRINT("Start Automation 2")
  FWD(20)
  DELAY(2000)
  STOP
  DELAY(2000)
  REV(20)
  DELAY(2000)
  STOP
DONE
AUTOMATION(23, "Automation 3")
  PRINT("Start Automation 3")
  FWD(20)
  DELAY(2000)
  STOP
  DELAY(2000)
  REV(20)
  DELAY(2000)
  STOP
DONE
