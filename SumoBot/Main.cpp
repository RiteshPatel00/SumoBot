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

#include "Main.h"

void setup() {
	// setup connection
	Serial.begin(9600);

	// call constructors
	// states = new LinkedList<States>;
	// prevDir = new LinkedList<Direction>;
	ultraLeft = new NewPing(trigPin1, echoPin1, maxDist);
	ultraRight = new NewPing(trigPin2, echoPin2, maxDist);
	motors = new Motors(motor1Pin1, motor1Pin2, motor1Enable, motor2Pin1,
			motor2Pin2, motor2Enable);
	ILeft = new IR(LED1Pin, signal1Pin);
	IRight = new IR(LED2Pin, signal2Pin);
}

void updateStates(States state) {
	// adds state at start of list
	states.unshift(state);
	if (states.size() >= maxLength) {
		// removes last state
		states.pop();
	}
}

void updateDir(Direction dir) {
	// adds direction at start of list
	prevDir.unshift(dir);
	if (prevDir.size() >= maxLength) {
		// removes last direction
		prevDir.pop();
	}
}

bool getDir(NewPing *ultraLeft, NewPing *ultraRight) {
	Direction dir;
	if (ultraLeft->ping_cm() < 20) {
		if (ultraRight->ping_cm() < 20) {
			updateDir(right);
		} else {
			updateDir(left);
		}
	} else if (ultraRight->ping_cm() < 20) {
		updateDir(center);
	} else {
		updateDir(none);
	}
	return enemyFound(ultraLeft, ultraRight, prevDir.get(0) );
}

bool enemyFound(NewPing *utraLeft, NewPing *ultraRight, Direction dir) {
	switch (dir) {
	case left:
		// enemy on left
		updateStates(enemy);
		// set motors to soft turn left
		// motorLeft = 50;
		// motorRight = 75;
		motors->softLeft();
		return true;
	case right:
		// enemy on right
		updateStates(enemy);
		// set motors to soft turn right
		// motorLeft = 75;
		// motorRight = 50;
		motors->softRight();
		return true;
	case center:
		// enemy in center
		updateStates(enemy);
		// set motors to go straight
		if (ultraRight->ping_cm() < 3) {
			// pushing
			// motorLeft = 100;
			// motorRight =  100;
			motors->forward(100);
		} else {
			// motorLeft = 75;
			// motorRight = 75;
			motors->forward(75);
		}
		return true;
	}
	// dir = none
	return false;
}

bool getDir(IR *ILeft, IR *IRight) {
	Direction dir;
	if (ILeft->isWhite()) {
		if (IRight->isWhite()) {
			updateDir(center);
		} else {
			updateDir(left);
		}
	} else if (IRight->isWhite()) {
		updateDir(right);
	} else {
		updateDir(none);
	}
	return whiteFound(prevDir.get(0) );
}

bool whiteFound(Direction dir) {
	switch (dir) {
	case left:
		// white on left
		updateStates(white);
		// set motors to hard turn right
		// motorLeft = 100;
		// motorRight = -100;
		motors->hardRight(100);
		return true;
	case right:
		// white on right
		updateStates(white);
		// set motors to hard turn left
		// motorLeft = -100;
		// motorRight = 100;
		motors->hardLeft(100);
		return true;
	}
	// case center not needed since direction turned can be either
	// return false if dir = none
	return false;
}

Direction getPrevDir() {
	Direction dir;
	// start at 1 since first direction is none
	int i = 1;
	while (i < maxLength) {
		dir = prevDir.get(i);
		if (dir != center || dir != none) {
			return dir;
		}
		i++;
	}
	return dir;
}

void loop() {

	// switch cases with most recent state
	switch (states.get(0) ) {
	case white:
		// check for enemies,
		// check if turn complete
		// add case if it sees white?

		// currently turning
		if (getDir(ultraLeft, ultraRight)) {
			// enemy found
			// state updated to enemy
		} else if (millis() - timeFor90 > timer) {
			// turn complete
			updateStates(wander);
			// motorLeft = 50;
			// motorRight = 50;
			motors->wander();
		}
		// else do nothing; continue turning
		break;
	case enemy:
		// check for white,
		// update enemy position

		// currently going towards enemy
		// check for white; highest priority
		if (getDir(ILeft, IRight)) {
			// white found
			// state updated to white
			// start timer
			timer = millis();
		} else if (getDir(ultraLeft, ultraRight)) {
			// check if enemy changed positions
			// update state and motors accordingly
		} else {
			// enemy lost
			updateStates(hunt);
			// begin turn for hunt
			timer = millis();
			if (getPrevDir() == left) {
				// enemy previously seen on left
				motors->hardLeft(50);
			} else {
				// enemy previously seen on right
				motors->hardRight(50);
			}
		}
		break;
	default:
		// state = hunt or wander
		// check for white,
		// check for enemy,
		// check if 360 deg turn complete if hunting

		// currently turning
		if (getDir(ILeft, IRight)) {
			// white found
			// state updated to white
			// reset timer
			timer = millis();
		} else if (getDir(ultraLeft, ultraRight)) {
			// enemy found
			// state updated to enemy
		} else if ( (states.get(0) == hunt) && (millis() - (timeFor90*4) > timer) ) {
			// turn complete for hunt
			updateStates(wander);
			// motorLeft = 50;
			// motorRight = 50;
			motors->wander();
		}
		break;
	case test:
		// testing code here
		break;
	}

}
