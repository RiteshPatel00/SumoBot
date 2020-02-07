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
  // 	should increase turning speed
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

// variables
int timer;
enum States = {white, enemy, hunt, wander};
enum Direction = {left, center, right, none};

void setup() {
  // setup code
}

boolean getDir(Ultrasonic left, Ultrasonic right) {
  Direction dir;
  if (left.getDist < 20) {
    if (right.getDist < 20) {
      dir = right;
    } else {
      dir = left;
    }
  } else if (right.getDist < 20) {
    dir = center;
  }
  return enemyFound(left, right, dir);
}

boolean enemyFound(Ultrasonic utraLeft, Ultrasonic ultraRight, Direction dir) {
  switch (dir) {
    case left:
      // enemy on left
      state = enemy;
      // set motors to soft turn left
      motorLeft = 50;
      motorRight = 75;
      return True;
    case right:
      // enemy on right
      state = enemy;
      // set motors to soft turn right
      motorLeft = 75;
      motorRight = 50;
      return True
    case center:
      // enemy in center
      state = enemy;
      // set motors to go straight
      if (ultraRight.getDist() < 3) {
        // pushing
        motorLeft = 100;
        motorRight =  100;
      } else {
        motorLeft = 75;
        motorRight = 75;
      }
      return True;
    }
    return False;
}

boolean getDir(IR left, IR right) {
  Direction dir;
  if (left.isWhite(left)) {
    if (right.isWhite(right) ) {
      dir = center;
    } else {
      dir = left;
    }
  } else if (right.isWhite(right)) {
    dir = right;
  }
  return whiteFound(dir);
}

boolean whiteFound(Direction dir) {
  switch (dir) {
    case left:
      // white on left
      state = white;
      // set motors to hard turn right
      motorLeft = 100;
      motorRight = -100;
      return True;
    case right:
      // white on right
      state = white;
      // set motors to hard turn left
      motorLeft = -100;
      motorRight = 100;
      return True
    }
    // case center not needed since direction turned can be either
    return False;
}

void loop() {

  switch (States) {
    case white:
      // add case if it sees white?
      // currently turning
      if (getDir(ultraLeft, ultraRight) ) {
        // enemy found
        // do nothing else
      } else if (system.time - (time to turn 180) > timer) {
        state = wander;
        motorLeft = 50;
        motorRight = 50;
      }
      // else do nothing; continue turning
      break;
    case enemy:
      // currently going towards enemy
      // check for white; highest priority
      if (getDir(ILeft, IRight) {
        // white found
        // start timer
        timer = system.time;
      } else if (getDir(ultraLeft, ultraRight) ) {
        // check if enemy changed positions
        // update state accordingly
      } else {
        // enemy lost
        state = hunt;
      }
      
  }

}
