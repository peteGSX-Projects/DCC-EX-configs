/* myRoutes.h
*  This file contains all routes.
*
*  Any related activities that need to occur on startup need to
*  be included in myAutomation.h to ensure they are in the 
*  correct order when compiled.
*/

// Join/unjoin programming track
ROUTE(1, "Join Programming Track")
  JOIN
DONE

ROUTE(2, "Unjoin Programming Track")
  UNJOIN
DONE
