/* myPinAliases.h
* This file contains aliases for the pin names on my layout.
*/

// Point aliases for 3 x MCP23017s in my point controller
ALIAS(POINT1_DIR,164)
ALIAS(POINT2_DIR,165)
ALIAS(POINT3_DIR,166)
ALIAS(POINT4_DIR,167)
ALIAS(POINT5_DIR,168)
ALIAS(POINT6_DIR,169)
ALIAS(POINT7_DIR,170)
ALIAS(POINT8_DIR,171)
ALIAS(POINT9_DIR,180)
ALIAS(POINT10_DIR,181)
ALIAS(POINT11_DIR,182)
ALIAS(POINT12_DIR,183)
ALIAS(POINT13_DIR,184)
ALIAS(POINT14_DIR,185)
ALIAS(POINT15_DIR,186)
ALIAS(POINT16_DIR,187)
ALIAS(POINT17_DIR,196)
ALIAS(POINT18_DIR,197)
ALIAS(POINT19_DIR,198)
ALIAS(POINT20_DIR,199)
ALIAS(POINT21_DIR,200)
ALIAS(POINT22_DIR,201)
ALIAS(POINT1_EN,172)
ALIAS(POINT2_EN,173)
ALIAS(POINT3_EN,174)
ALIAS(POINT4_EN,175)
ALIAS(POINT5_EN,176)
ALIAS(POINT6_EN,177)
ALIAS(POINT7_EN,178)
ALIAS(POINT8_EN,179)
ALIAS(POINT9_EN,188)
ALIAS(POINT10_EN,189)
ALIAS(POINT11_EN,190)
ALIAS(POINT12_EN,191)
ALIAS(POINT13_EN,192)
ALIAS(POINT14_EN,193)
ALIAS(POINT15_EN,194)
ALIAS(POINT16_EN,195)
ALIAS(POINT17_EN,204)
ALIAS(POINT18_EN,205)
ALIAS(POINT19_EN,206)
ALIAS(POINT20_EN,207)
ALIAS(POINT21_EN,208)
ALIAS(POINT22_EN,209)

// Power relay to turn on power to the points
ALIAS(POINT_POWER,211)

// Mimic panel toggle switches on F412ZG CN11 outer pins
PC10 - POINT1_CLOSE, 800
PC12 - POINT1_THROW, 802
PF6 - POINT2_CLOSE, 804
PF7 - POINT2_THROW
PA15 - POINT3_CLOSE
PB7 - POINT3_THROW
PC13 - POINT4_CLOSE
PC2 - POINT4_THROW
PC3 - POINT5_CLOSE
PD4 - POINT5_THROW
PD5 - POINT6_CLOSE
PD6 - POINT6_THROW
PD7 - POINT7_CLOSE
PE3 - POINT7_THROW
PF1 - POINT8_CLOSE
PF0 - POINT8_THROW
PD1 - POINT9_CLOSE
PD0 - POINT9_THROW
PG0 - POINT10_CLOSE
PE1 - POINT10_THROW
PG9 - POINT11_CLOSE
PG12 - POINT11_THROW

// Mimic panel toggle switches and push buttons on F412ZG CN11 inner pins
PC11 - POINT12_CLOSE
PD2 - POINT12_THROW
PA0 – POINT13_CLOSE
PA1 – POINT13_THROW
PA4 – POINT14_CLOSE
PB0 – POINT14_THROW
PC1 - POINT15_CLOSE
PC0 - POINT15_THROW
PD3 - NC
PG2 - NC
PG3 - NC
PE2 - NC
PE4 - NC
PE5 - NC
PF2 - NC
PF8 - DECOUPLER1_BUTTON
PF9 - DECOUPLER2_BUTTON
PG1 - DECOUPLER3_BUTTON
PE6 - DECOUPLER4_BUTTON
PG15 - DECOUPLER5_BUTTON
PG10 - DECOUPLER6_BUTTON
PG13 - DECOUPLER7_BUTTON
PG11 - NC