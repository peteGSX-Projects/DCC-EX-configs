/**
 * @file myAutomation.h
 * @brief Colours as defined in TFT_eSPI.h as a starting point.
 */
#define EXDISPLAY_BLACK "`0x0000`"
#define EXDISPLAY_NAVY "`0x000F`"
#define EXDISPLAY_DARKGREEN "`0x03E0`"
#define EXDISPLAY_DARKCYAN "`0x03EF`"
#define EXDISPLAY_MAROON "`0x7800`"
#define EXDISPLAY_PURPLE "`0x780F`"
#define EXDISPLAY_OLIVE "`0x7BE0`"
#define EXDISPLAY_LIGHTGREY "`0xD69A`"
#define EXDISPLAY_DARKGREY "`0x7BEF`"
#define EXDISPLAY_BLUE "`0x001F`"
#define EXDISPLAY_GREEN "`0x07E0`"
#define EXDISPLAY_CYAN "`0x07FF`"
#define EXDISPLAY_RED "`0xF800`"
#define EXDISPLAY_MAGENTA "`0xF81F`"
#define EXDISPLAY_YELLOW "`0xFFE0`"
#define EXDISPLAY_WHITE "`0xFFFF`"
#define EXDISPLAY_ORANGE "`0xFDA0`"
#define EXDISPLAY_GREENYELLOW "`0xB7E0`"
#define EXDISPLAY_PINK "`0xFE19`"
#define EXDISPLAY_BROWN "`0x9A60`"
#define EXDISPLAY_GOLD "`0xFEA0`"
#define EXDISPLAY_SILVER "`0xC618`"
#define EXDISPLAY_SKYBLUE "`0x867D`"
#define EXDISPLAY_VIOLET "`0x915C`"

/**
 * @brief Row attributes that affect how they are displayed.
 */
#define UNDERLINE "`__`"
#define LINE "`--`"
#define TICKER "`~~`"
#define NOTICKER "`!~`"

/**
 * @brief Route 1 to test updating rows on screen 0 with attributes and colours.
 */
AUTOSTART
ROUTE(1, "Test")
SCREEN(0,0,"Row 0 default white")
SCREEN(0,1,EXDISPLAY_ORANGE "ROW 1 orange")
SCREEN(0,2,"Row 2 starts white, " EXDISPLAY_DARKCYAN "goes dark cyan, then " EXDISPLAY_GREEN "green")
SCREEN(0,3,"ROW 3")
DELAY(2000)
SCREEN(0,0,"CLEAR 0")
SCREEN(0,1,"CLEAR 1")
SCREEN(0,2,"CLEAR 2")
SCREEN(0,3,"CLEAR 3")
DELAY(2000)
SCREEN(0,5,TICKER UNDERLINE EXDISPLAY_RED "Underlined red text always tickers")
SCREEN(0,6,LINE "Horizontal line no text")
SCREEN(0,7,NOTICKER EXDISPLAY_GREENYELLOW "Green yellow, never ticker")
SCREEN(0,8,"White text is " EXDISPLAY_YELLOW "now yellow")
DELAY(2000)
SCREEN(0,5,"CLEAR 5")
SCREEN(0,6,"CLEAR 6")
SCREEN(0,7,"CLEAR 7")
SCREEN(0,8,"CLEAR 8")
DELAY(2000)
FOLLOW(1)
