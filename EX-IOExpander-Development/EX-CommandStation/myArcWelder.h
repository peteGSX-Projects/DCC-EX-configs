// ************************************************************************************************** //
// "FX Arc Welder" with a Dual LEDs. One clear White LED on vpin112 and One Blue LED on vpin113        --- Tinkerer Level
//  IF you're using vpins 112 & 113 for a turnout or a point signal then use another vpin# on another a PCA9685 board
// A single button for Engine Driver R882 'FX Arc Welder On/Off' [Set] button turns it ON
// A second 2nd press from Engine Driver [Set] button allows it to cycle one more time then Stop and turns OFF
// ************************************************************************************************** //
 ROUTE(882, "FX Arc Welder On/Off") // Create a dummy One button press macro
   IF(222) UNLATCH(222) DONE ENDIF  // Dummy pin(222) Limits SEQUENCE(112)
    PRINT("FX Arc Welder ON")
    LATCH(222) START(112)  // SEQUENCE(112) Dual FX Arc Welder turns Vpins 112 & 113 rapidly On & Off
    DONE
    
  SEQUENCE(112)             // Dual LED FX Arc Welder {R1 200ohm on a PCA9685 Signal Board vpin 112 & 113}
   SET(1503)                      // Optional Start DFPlayer Sound file of electric welder File #4
// FADE(vpin, intensity, duration) intensity is from 0 to 4095 brightest.
   FADE(112, 4000, 50)    // Clear White LED
   FADE(113, 4000, 40)    // Clear Blue LED 
   FADE(113,  400, 40)
    DELAYRANDOM(50,600)
   FADE(113,    0, 20)
   FADE(112,    0, 20)   
    DELAYRANDOM(50,800)
   FADE(112, 4000, 40)  
   FADE(113, 4000, 60)  
   FADE(113,  250, 40)  
    DELAYRANDOM(50,100) 
   FADE(113,    0, 40)
   FADE(112,    0, 40)  
    DELAYRANDOM(50,600)
   FADE(112, 4000, 40)
   FADE(113, 4000, 40)
   FADE(113, 1000, 20)
    DELAYRANDOM(50,200)
   FADE(113,    0, 20)
   FADE(112,    0, 20)
    DELAYRANDOM(50,500)
   FADE(112, 4000, 60)
   FADE(113, 4000, 40)
   FADE(112,  500, 20) 
   FADE(113, 1000, 40) 
    DELAYRANDOM(50,300) 
   FADE(113,    0, 50)
   FADE(112,    0, 50)   
    DELAYRANDOM(200,1000)
   FADE(112, 4000, 40)
   FADE(113, 4000, 60)
   FADE(112,  600, 60)
   FADE(113, 1000, 40)
    DELAYRANDOM(100,200)
   FADE(113,  600, 40)
   FADE(113,    0, 20)
   FADE(112,    0, 20)
    DELAYRANDOM(50,200)
   FADE(113, 4000, 40) 
   FADE(112,  500, 40)
   FADE(112,    0, 20)
    DELAYRANDOM(50,200)
   IF(222) FOLLOW(112) ENDIF
    RESET(1500)       // Optional Stop DFPlayer Sound file
    FADE(112, 0, 0) PRINT("FX2 Arc Welder OFF") // Turn Dual Welder Off
    FADE(113, 0, 0)  // Turn Dual LED Welder Off
