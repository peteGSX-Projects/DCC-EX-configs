// #include "myBigRoster.h"

ROSTER(2004, "QR 2004","Lights/*Horn/*Bell/*Whistle/*Brakes/Idiots/Crap Programming")
ROSTER(2006, "QR 2006", "Lights/*Horn")
ROSTER(2010, "QR 2010", "Lights/*Horn")
ROSTER(2014, "QR 2014", "Lights/*Horn")
ROSTER(2016, "QR 2016", "Lights/*Horn")
ROSTER(2020, "QR 2020", "Lights/*Horn")
ROSTER(2024, "QR 2024", "Lights/*Horn")
ROSTER(2026, "QR 2026", "Lights/*Horn")
ROSTER(2030, "QR 2030", "Lights/*Horn")

HAL(EXTurntable, 600, 1, 0x60)
EXTT_TURNTABLE(1, 600, 1800, "Tiny Test Turntable")
TT_ADDPOSITION(1, 1, 900, 800, "Stall 1")
TT_ADDPOSITION(1, 2, 1200, 900, "Stall 2")
TT_ADDPOSITION(1, 3, 1500, 1000, "Stall 3")
TT_ADDPOSITION(1, 4, 2700, 2600, "Rev stall 1")
TT_ADDPOSITION(1, 5, 3000, 2700, "Layout")
TT_ADDPOSITION(1, 6, 3300, 2800, "Rev stall 3")

DCC_TURNTABLE(2, 1800, "My EX-Turntable")
TT_ADDPOSITION(2, 1, 900, 800, "Stall 1")
TT_ADDPOSITION(2, 2, 1200, 900, "Stall 2")
TT_ADDPOSITION(2, 3, 1500, 1000, "Stall 3")
TT_ADDPOSITION(2, 4, 2700, 2600, "Rev stall 1")
TT_ADDPOSITION(2, 5, 3000, 2700, "Layout")
TT_ADDPOSITION(2, 6, 3300, 2800, "Rev stall 3")

PIN_TURNOUT(100, 100, "Turnout 100")
PIN_TURNOUT(101, 101, "Turnout 101")
PIN_TURNOUT(102, 102)

ROUTE(200, "Route 200")
  PRINT("Route 200 activated")
DONE

AUTOMATION(300, "Automation 300")
  PRINT("Automation 300 activated")
DONE

ROUTE(400, "Route 400")
  PRINT("Route 400 activated")
DONE