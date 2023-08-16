/*
 *  © 2022 Peter Cole
 *
 *  This is the example position definition file for the DCC-EX integrated rotary encoder.
 * 
 *  It is highly recommended to copy this to "positions.h" and modify to suit your specific
 *  requirements.
 * 
 *  NOTE: Modifications to this file will be overwritten by future software updates.
 */

#ifndef POSITIONS_H
#define POSITIONS_H

/////////////////////////////////////////////////////////////////////////////////////
//  NOTE: All angles are expressed in degrees from the top of the display, or in other
//  words 12 o'clock on an analogue clock.
/////////////////////////////////////////////////////////////////////////////////////
#define HOME_ANGLE 180            // Define the angle in degrees for the home position mark
#define NUMBER_OF_POSITIONS 8  // Define the number of positions to be defined

/////////////////////////////////////////////////////////////////////////////////////
//  You must define the exact number of positions as defined for NUMBER_OF_POSITIONS.
//  The syntax must be correct for each line, and there must be no comma "," at the end
//  of the last defined position.
//  The syntax is:
/*
positionDefinition turntablePositions[NUMBER_OF_POSITIONS] = {
  {angle, id, "description"},
  {angle, id, "description"},
  ...
  {angle, id, "description"}
};
*/
//  Where:
//  angle - Specified in degrees from the top of the display (12 o'clock)
//  id - The identifier that will be sent to the CommandStation when selected (1 - 255)
//  "description" - A 10 character or less position description to display when selected
/////////////////////////////////////////////////////////////////////////////////////

positionDefinition turntablePositions[NUMBER_OF_POSITIONS] = {
  {166, 1, "Stall 1"},
  {173, 2, "Stall 2"},
  {180, 3, "Stall 3"},
  {187, 4, "Stall 4"},
  {194, 5, "Stall 5"},
  {201, 6, "Stall 6"},
  {76, 7, "Storage"},
  {90, 8, "Yard"},
};

#endif