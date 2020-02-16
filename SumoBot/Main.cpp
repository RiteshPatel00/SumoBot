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
 // done to maximize angle searched while traveling semi straight

 */

// #include <stdio.h>
#include "Main.h"


// variables
int timer;
States state;
Motors motors;
Ultrasonic ultraLeft, ultraRight;
IR ILeft, IRight;

void setup() {
	// setup code
}

bool getDir(Ultrasonic ultraLeft, Ultrasonic ultraRight) {
	ultraLeft.getDist();

	Direction dir;
	if (ultraLeft.getDist() < 20) {
		if (ultraRight.getDist() < 20) {
			dir = right;
		} else {
			dir = left;
		}
	} else if (ultraRight.getDist() < 20) {
		dir = center;
	}
	return enemyFound(ultraLeft, ultraRight, dir);
}

bool enemyFound(Ultrasonic utraLeft, Ultrasonic ultraRight, Direction dir) {
	switch (dir) {
	case left:
		// enemy on left
		state = enemy;
		// set motors to soft turn left
		//motorLeft = 50;
		//motorRight = 75;
		motors.softLeft();
		return true;
	case right:
		// enemy on right
		state = enemy;
		// set motors to soft turn right
		//motorLeft = 75;
		//motorRight = 50;
		motors.softRight();
		return true;
	case center:
		// enemy in center
		state = enemy;
		// set motors to go straight
		if (ultraRight.getDist() < 3) {
			// pushing
			//motorLeft = 100;
			//motorRight =  100;
			motors.push();
		} else {
			//motorLeft = 75;
			//motorRight = 75;
			motors.forward();
		}
		return true;
	}
	return false;
}

bool getDir(IR ILeft, IR IRight) {
	Direction dir;
	if (ILeft.isWhite()) {
		if (IRight.isWhite()) {
			dir = center;
		} else {
			dir = left;
		}
	} else if (IRight.isWhite()) {
		dir = right;
	}
	return whiteFound(dir);
}

bool whiteFound(Direction dir) {
	switch (dir) {
	case left:
		// white on left
		state = white;
		// set motors to hard turn right
		//motorLeft = 100;
		//motorRight = -100;
		motors.hardRight();
		return true;
	case right:
		// white on right
		state = white;
		// set motors to hard turn left
		//motorLeft = -100;
		//motorRight = 100;
		motors.hardLeft();
		return true;
	}
	// case center not needed since direction turned can be either
	return false;
}

void loop() {

	switch (state) {
	case white:
		// add case if it sees white?
		// currently turning
		if (getDir(ultraLeft, ultraRight)) {
			// enemy found
			// do nothing else
		} else if (millis() - timeFor90 > timer) {
			state = wander;
			//motorLeft = 50;
			//motorRight = 50;
			motors.wander();
		}
		// else do nothing; continue turning
		break;
	case enemy:
		// currently going towards enemy
		// check for white; highest priority
	if (getDir(ILeft, IRight) ) {
				// white found
				// start timer
				timer = millis();
			}
		else if (getDir(ultraLeft, ultraRight) ) {
			// check if enemy changed positions
			// update state accordingly
		} else {
			// enemy lost
			state = hunt;
		}

	}

}
