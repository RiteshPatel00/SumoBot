/*
 ******* Pseudocode *******
int timer
enum state
  - whiteLeft
  - whiteRight
  - whiteCenter
  - enemyLeft
  - enemyRight
  - enemyCenter
  - seek
  - wander
// array to store list of past states
// used for detecting repetition of states
// ex: enemyRight, enemyCenter, enemyRight, enemyCenter, etc
//  should increase turning speed


states []
switch state
  case whiteLeft
    turn right 90 deg
  case whiteRight
    turn left 90 deg
  case whiteCenter
    turn left/right 135 deg
  case enemyLeft
    motor left = 75
    motor right = 100
  case enemyRight
    motor left = 100
    motor right = 75
  case enemyCenter
    motor left = 100
    motor right = 100
  case seek
    turn until something found
    if not found by 360 deg rotation
      state = wander
  case wander
    move in wavelike motion (~)
    // done to maximize angle searched while travelling semi straight
    
*/
