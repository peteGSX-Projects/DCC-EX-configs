/**
 * @file myAutomation.h
 * @brief Colours as defined in TFT_eSPI.h as a starting point.
 */
#define EXD_BLACK "`#000000`"
#define EXD_NAVY "`#000080`"
#define EXD_DARKGREEN "`#007800`"
#define EXD_DARKCYAN "`#007878`"
#define EXD_MAROON "`#780000`"
#define EXD_PURPLE "`#780080`"
#define EXD_OLIVE "`#787800`"
#define EXD_LIGHTGREY "`#D6D6D6`"
#define EXD_DARKGREY "`#787878`"
#define EXD_BLUE "`#0000FF`"
#define EXD_GREEN "`#00FF00`"
#define EXD_CYAN "`#00FFFF`"
#define EXD_RED "`#FF0000`"
#define EXD_MAGENTA "`#FF00FF`"
#define EXD_YELLOW "`#FFFF00`"
#define EXD_WHITE "`#FFFFFF`"
#define EXD_ORANGE "`#FFA500`"
#define EXD_GREENYELLOW "`#B7FF00`"
#define EXD_PINK "`#FFC0CB`"
#define EXD_BROWN "`#996600`"
#define EXD_GOLD "`#FFD700`"
#define EXD_SILVER "`#C6C6C6`"
#define EXD_SKYBLUE "`#87CEEB`"
#define EXD_VIOLET "`#9400D3`"

/**
 * @brief Row attributes that affect how they are displayed.
 */
#define UNDERLINE "`_`"
#define LINE "`-`"
#define TICKER "`~`"
#define NOTICKER "`!`"

/**
 * @brief Route 1 to test updating rows on screen 0 with attributes and colours.
 */
AUTOSTART
ROUTE(1, "Test")
SCREEN(0,0,"Row 0 default white")
SCREEN(0,1,EXD_ORANGE "ROW 1 orange")
SCREEN(0,2,"Row 2 starts white, " EXD_DARKCYAN "goes dark cyan, then " EXD_GREEN "green")
SCREEN(0,3,"ROW 3")
DELAY(2000)
SCREEN(0,0,"CLEAR 0")
SCREEN(0,1,"CLEAR 1")
SCREEN(0,2,"CLEAR 2")
SCREEN(0,3,"CLEAR 3")
DELAY(2000)
SCREEN(0,5,TICKER UNDERLINE EXD_RED "Underlined red text always tickers")
SCREEN(0,6,LINE "Horizontal line no text")
SCREEN(0,7,NOTICKER EXD_GREENYELLOW "Green yellow, never ticker")
SCREEN(0,8,"White text is " EXD_YELLOW "now yellow")
DELAY(2000)
SCREEN(0,5,"CLEAR 5")
SCREEN(0,6,"CLEAR 6")
SCREEN(0,7,"CLEAR 7")
SCREEN(0,8,"CLEAR 8")
DELAY(2000)
FOLLOW(1)
