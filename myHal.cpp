//  Sample myHal.cpp file.
//
// To use this file, copy it to myHal.cpp and uncomment the directives and/or
// edit them to satisfy your requirements.  If you only want to use up to 
// two MCP23017 GPIO Expander modules and/or up to two PCA9685 Servo modules,
// then you don't need this file as DCC++EX configures these for free!

// Note that if the file has a .cpp extension it WILL be compiled into the build
// and the halSetup() function WILL be invoked.
//
// To prevent this, temporarily rename the file to myHal.txt or similar.
//

// The #if directive prevent compile errors for Uno and Nano by excluding the 
//  HAL directives from the build.
#if !defined(IO_NO_HAL)

// Include devices you need.
#include "IODevice.h"
#include "IO_HCSR04.h"    // Ultrasonic range sensor
#include "IO_VL53L0X.h"   // Laser time-of-flight sensor
#include "IO_DFPlayer.h"  // MP3 sound player


//==========================================================================
// The function halSetup() is invoked from CS if it exists within the build.
// The setup calls are included between the open and close braces "{ ... }".
// Comments (lines preceded by "//") are optional.
//==========================================================================

void halSetup() {

  //=======================================================================
  // The following directive defines a PCA9685 PWM Servo driver module.
  //=======================================================================
  // The parameters are: 
  //   First Vpin=100
  //   Number of VPINs=16 (numbered 100-115)
  //   I2C address of module=0x40

  //PCA9685::create(100, 16, 0x40);


  //=======================================================================
  // The following directive defines an MCP23017 16-port I2C GPIO Extender module.
  //=======================================================================
  // The parameters are: 
  //   First Vpin=196
  //   Number of VPINs=16 (numbered 196-211)
  //   I2C address of module=0x22

  MCP23017::create(196, 16, 0x22);
  MCP23017::create(212, 16, 0x23);


  // Alternative form, which allows the INT pin of the module to request a scan
  // by pulling Arduino pin 40 to ground.  Means that the I2C isn't being polled
  // all the time, only when a change takes place. Multiple modules' INT pins
  // may be connected to the same Arduino pin.

  //MCP23017::create(196, 16, 0x22, 40);


  //=======================================================================
  // The following directive defines an MCP23008 8-port I2C GPIO Extender module.
  //=======================================================================
  // The parameters are: 
  //   First Vpin=300
  //   Number of VPINs=8 (numbered 300-307)
  //   I2C address of module=0x22

  //MCP23008::create(300, 8, 0x22);


  //=======================================================================
  // The following directive defines a PCF8574 8-port I2C GPIO Extender module.
  //=======================================================================
  // The parameters are: 
  //   First Vpin=200
  //   Number of VPINs=8 (numbered 200-207)
  //   I2C address of module=0x23

  //PCF8574::create(200, 8, 0x23);


  // Alternative form using INT pin (see above)

  //PCF8574::create(200, 8, 0x23, 40);


  //=======================================================================
  // The following directive defines an HCSR04 ultrasonic ranging module.
  //=======================================================================
  // The parameters are: 
  //   Vpin=2000 (only one VPIN per directive)
  //   Number of VPINs=1
  //   Arduino pin connected to TRIG=30
  //   Arduino pin connected to ECHO=31
  //   Minimum trigger range=20cm (VPIN goes to 1 when <20cm)
  //   Maximum trigger range=25cm (VPIN goes to 0 when >25cm)
  // Note: Multiple devices can be configured by using a different ECHO pin
  // for each one.  The TRIG pin can be shared between multiple devices.
  // Be aware that the 'ping' of one device may be received by another
  // device and position them accordingly!

  //HCSR04::create(2000, 30, 31, 20, 25);
  //HCSR04::create(2001, 30, 32, 20, 25);


  //=======================================================================
  // The following directive defines a single VL53L0X Time-of-Flight range sensor.
  //=======================================================================
  // The parameters are:
  //   VPIN=5000
  //   Number of VPINs=1
  //   I2C address=0x29 (default for this chip)
  //   Minimum trigger range=200mm (VPIN goes to 1 when <20cm)
  //   Maximum trigger range=250mm (VPIN goes to 0 when >25cm)

  //VL53L0X::create(5000, 1, 0x29, 200, 250); 

  // For multiple VL53L0X modules, add another parameter which is a VPIN connected to the
  // module's XSHUT pin.  This allows the modules to be configured, at start,
  // with distinct I2C addresses.  In this case, the address 0x29 is only used during
  // initialisation to configure each device in turn with the desired unique I2C address.
  // The examples below have the modules' XSHUT pins connected to the first two pins of 
  // the first MCP23017 module (164 and 165), but Arduino pins may be used instead.
  // The first module here is given I2C address 0x30 and the second is 0x31.

  //VL53L0X::create(5000, 1, 0x30, 200, 250, 164); 
  //VL53L0X::create(5001, 1, 0x31, 200, 250, 165); 


  //=======================================================================
  // Play mp3 files from a Micro-SD card, using a DFPlayer MP3 Module.
  //=======================================================================
  // Parameters: 
  //   10000 = first VPIN allocated.
  //   10 = number of VPINs allocated.
  //   Serial1 = name of serial port (usually Serial1 or Serial2).
  // With these parameters, up to 10 files may be played on pins 10000-10009.
  // Play is started from EX-RAIL with SET(10000) for first mp3 file, SET(10001)
  // for second file, etc.  Play may also be initiated by writing an analogue
  // value to the first pin, e.g. SERVO(10000,23,0) will play the 23rd mp3 file.
  // SERVO(10000,23,30) will do the same thing, as well as setting the volume to 
  // 30 (maximum value).
  // Play is stopped by RESET(10000) (or any other allocated VPIN).
  // Volume may also be set by writing an analogue value to the second pin for the player, 
  // e.g. SERVO(10001,30,0) sets volume to maximum (30).
  // The EX-RAIL script may check for completion of play by calling WAITFOR(pin), which will only proceed to the
  // following line when the player is no longer busy.
  // E.g.
  //    SEQUENCE(1)
  //      AT(164)           // Wait for sensor attached to pin 164 to activate
  //      SET(10003)        // Play fourth MP3 file
  //      LCD(4, "Playing") // Display message on LCD/OLED
  //      WAITFOR(10003)    // Wait for playing to finish
  //      LCD(4, " ")       // Clear LCD/OLED line 
  //      FOLLOW(1)         // Go back to start

  // DFPlayer::create(10000, 10, Serial1);


}

#endif
