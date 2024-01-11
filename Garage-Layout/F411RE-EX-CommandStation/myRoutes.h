/* myRoutes.h
*  This file contains all routes.
*
*  Any related activities that need to occur on startup need to
*  be included in myAutomation.h to ensure they are in the 
*  correct order when compiled.
*/

// Join/unjoin programming track
ROUTE(JOIN_ROUTE, "Join Programming Track")
  JOIN
DONE

ROUTE(UNJOIN_ROUTE, "Unjoin Programming Track")
  UNJOIN
DONE

ROUTE(MAIN_TO_TURNTABLE_ROUTE, "Main to turntable")
  THROW(YARD_ACCESS)
  THROW(STORAGE_1_AND_MAINTENANCE)
  CLOSE(STORAGE_2)
  CLOSE(STORAGE_3)
  CLOSE(TURNTABLE_ACCESS)
DONE
