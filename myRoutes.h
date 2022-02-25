/* myRoutes.h
*  This file contains all routes.
*
*  Any related activities that need to occur on startup need to
*  be included in myAutomation.h to ensure they are in the 
*  correct order when compiled.
*/

/* Main loop ROUTE
*  Simple route for main loop continuous running
*/
ROUTE(1, "Main loop")
    IFTHROWN(MA_IND_1) CLOSE(MA_IND_1) ENDIF
    DELAY(TURNOUT_DELAY)
    IFTHROWN(MA_IND_2) CLOSE(MA_IND_2) ENDIF
    DONE

/* Industry loop ROUTE
*  Simple route for industry loop continuous running
*/
ROUTE(2, "Industry loop")
    IFTHROWN(IND_MA_1) CLOSE(IND_MA_1) ENDIF
    DELAY(TURNOUT_DELAY)
    IFTHROWN(IND_MA_2) CLOSE(IND_MA_2) ENDIF
    DELAY(TURNOUT_DELAY)
    IFTHROWN(YD_E) CLOSE(YD_E) ENDIF
    IFTHROWN(IIND_E1) CLOSE(IIND_E1) ENDIF
    DELAY(TURNOUT_DELAY)
    IFTHROWN(IIND_E2) CLOSE(IIND_E2) ENDIF
    DELAY(TURNOUT_DELAY)
    IFTHROWN(CON_E) CLOSE(CON_E) ENDIF
    IFTHROWN(WH_E) CLOSE(WH_E) ENDIF
    DELAY(TURNOUT_DELAY)
    IFTHROWN(DIST_E) CLOSE(DIST_E) ENDIF
    IFTHROWN(TBA_E) CLOSE(TBA_E) ENDIF
    DONE

/* Inner industry loop ROUTE
*  Simple route for inner industry loop continuous running
*/
ROUTE(3, "Inner industry loop")
    IFTHROWN(IND_MA_1) CLOSE(IND_MA_1) ENDIF
    DELAY(TURNOUT_DELAY)
    IFTHROWN(IND_MA_2) CLOSE(IND_MA_2) ENDIF
    DELAY(TURNOUT_DELAY)
    IFTHROWN(YD_E) CLOSE(YD_E) ENDIF
    IFCLOSED(IIND_E1) THROW(IIND_E1) ENDIF
    DELAY(TURNOUT_DELAY)
    IFCLOSED(IIND_E2) THROW(IIND_E2) ENDIF
    IFTHROWN(CAR_E) CLOSE(CAR_E) ENDIF
    DONE

/* Industry loop to turntable ROUTE
*  Define a ROUTE to get to the turntable from the industry loop
*  Set all turnouts correctly for entry from industry loop
*  Align turntable with the layout connection track
*  Loco can now be driven to the end of the siding ready to enter turntable
*  After the locos passes over sensor 1, throw the turntable entry turnout
*  Loco can then be driven onto turntable
*/
ROUTE(4, "Industry loop to turntable")
    IFCLOSED(YD_E) THROW(YD_E) ENDIF
    IFCLOSED(YD_1) THROW(YD_1) ENDIF
    DELAY(TURNOUT_DELAY)
    IFTHROWN(RUN_E) CLOSE(RUN_E) ENDIF
    IFCLOSED(RR_E) THROW(RR_E) ENDIF
    DELAY(TURNOUT_DELAY)
    IFTHROWN(TT_E) CLOSE(TT_E) ENDIF
    IFTHROWN(RUN_1) CLOSE(RUN_1) ENDIF
    DELAY(TURNOUT_DELAY)
    CLOSE(TT_LAYOUT)
    AFTER(TT_E_SNSR) THROW(TT_E) DONE
    DONE

/* Roundhouse stall 1 to industry loop ROUTE

*/

ROUTE(5, "Stall 1 to industry loop")
    CLOSE(TT_ST1)
    IFCLOSED(YD_E) THROW(YD_E) ENDIF
    IFCLOSED(YD_1) THROW(YD_1) ENDIF
    DELAY(TURNOUT_DELAY)
    IFTHROWN(RUN_E) CLOSE(RUN_E) ENDIF
    IFCLOSED(RR_E) THROW(RR_E) ENDIF
    DELAY(TURNOUT_DELAY)
    IFCLOSED(TT_E) THROW(TT_E) ENDIF
    IFTHROWN(RUN_1) CLOSE(RUN_1) ENDIF
    AFTER(TT_E_SNSR) THROW(TT_E) DONE
    DELAY(TURNOUT_DELAY)
    AFTER(ST1_E_SNSR) DELAY(2000) CLOSE(TT_LAYOUT) DONE
    AFTER(TT_E_SNSR) CLOSE(TT_E) DONE
    DONE
