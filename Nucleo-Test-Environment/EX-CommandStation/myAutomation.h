CLOSE(101)
CLOSE(102)

START(TTROUTE1)

DONE

ROUTE(JOIN_ROUTE, "Join prog/main")
  JOIN
  DONE

ROUTE(MIN_ACK, "Set minimum ACK for Rokuhan")
  PARSE("<D ACK LIMIT 6>")
  DONE

ROUTE(DEFAULT_ACK, "Set default ACK")
  PARSE("<D ACK LIMIT 50>")
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

// EX-Turntable routes
#define EX_TURNTABLE(route_id, reserve_id, vpin, steps, activity, desc, feedback_vpin) \
  ROUTE(route_id, desc) \
    SET(feedback_vpin) \
    RESERVE(reserve_id) \
    MOVETT(vpin, steps, activity) \
    WAITFOR(vpin) \
    FREE(reserve_id) \
    RESET(feedback_vpin) \
    DONE

// Turntable
EX_TURNTABLE(TTROUTE1, TURNTABLE, 600, 1155, Turn, "Turntable Position 1", 701)
EX_TURNTABLE(TTROUTE2, TURNTABLE, 600, 3200, Turn, "Turntable Position 2", 701)
EX_TURNTABLE(TTROUTE7, TURNTABLE, 600, 0, Home, "Turntable Homing", 701)
EX_TURNTABLE(TTROUTE8, TURNTABLE, 600, 0, Calibrate, "Turntable Calibration", 701)

// EX-Traverser routes
#define EX_TRAVERSER(route_id, reserve_id, vpin, steps, activity, desc) \
  ROUTE(route_id, desc) \
    RESERVE(reserve_id) \
    MOVETT(vpin, steps, activity) \
    WAITFOR(vpin) \
    FREE(reserve_id) \
    DONE

// Traverser
EX_TRAVERSER(TRROUTE1, TRAVERSER, 601, 500, Turn, "Traverser Position 1")
EX_TRAVERSER(TRROUTE2, TRAVERSER, 601, 600, Turn, "Traverser Position 2")
EX_TRAVERSER(TRROUTE3, TRAVERSER, 601, 700, Turn, "Traverser Position 3")
EX_TRAVERSER(TRROUTE4, TRAVERSER, 601, 800, Turn, "Traverser Position 4")
EX_TRAVERSER(TRROUTE5, TRAVERSER, 601, 900, Turn, "Traverser Position 5")
EX_TRAVERSER(TRROUTE6, TRAVERSER, 601, 1000, Turn, "Traverser Position 6")
EX_TRAVERSER(TRROUTE7, TRAVERSER, 601, 0, Home, "Traverser Homing")
EX_TRAVERSER(TRROUTE8, TRAVERSER, 601, 0, Calibrate, "Traverser Calibration")

Rotary encoder event handler
ONCHANGE(700)
  IFRE(700, 0)
    START(TTROUTE7)
  ENDIF
  IFRE(700, 1)
    START(TTROUTE1)
  ENDIF
  IFRE(700, 2)
    START(TTROUTE2)
  ENDIF
DONE

// Loco roster entries
ROSTER(2004, "QR 2004", "Lights")
ROSTER(2006, "QR 2006", "Lights")
ROSTER(2010, "QR 2010", "Lights")

// Aliases
ALIAS(TURNTABLE, 255)
ALIAS(TRAVERSER, 254)
ALIAS(TTROUTE1)
ALIAS(TTROUTE2)
ALIAS(TTROUTE3)
ALIAS(TTROUTE4)
ALIAS(TTROUTE5)
ALIAS(TTROUTE6)
ALIAS(TTROUTE7)
ALIAS(TTROUTE8)
ALIAS(TRROUTE1)
ALIAS(TRROUTE2)
ALIAS(TRROUTE3)
ALIAS(TRROUTE4)
ALIAS(TRROUTE5)
ALIAS(TRROUTE6)
ALIAS(TRROUTE7)
ALIAS(TRROUTE8)
ALIAS(JOIN_ROUTE)
ALIAS(MIN_ACK)
ALIAS(DEFAULT_ACK)