/*
 * Main.h
 *
 *  Created on: Feb 16, 2020
 *      Author: WinnieTrandinh
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <LinkedList.h>
#include <NewPing.h>
#include "IR.h"
#include "Motors.h"

// typedefs
enum States {
	white, enemy, hunt, wander, test
};
enum Direction {
	left, center, right, none
};

// pins

// ultrasonic
// digital output
const int trigPin1 = 1;
// analog input
const int echoPin1 = 19;
// digital output
const int trigPin2 = 2;
// digital input
const int echoPin2 = 5;
// distance in cm						******* change ********
const int maxDist = 20;

// motors
// digital output
const int motor1Pin1 = 10;
const int motor1Pin2 = 11;
// pmw digital output
const int motor1Enable = 9;
// digital output
const int motor2Pin1 = 13;
const int motor2Pin2 = 14;
// pmw digital output
const int motor2Enable = 12;
// time to turn 90 degrees in milliseconds
const int timeFor90 = 1000;

// IR
// digital output
const int LED1Pin = 8;
// digital input
const int signal1Pin = 6;
// digital output
const int LED2Pin = 15;
// digital input
const int signal2Pin = 7;

// miscellaneous
int timer;
const int maxLength = 5;
LinkedList<States> states;
LinkedList<Direction> prevDir;
Motors *motors;
NewPing *ultraLeft, *ultraRight;
IR *ILeft, *IRight;

// methods
void updateStates(States);
void updateDir(Direction);
bool getDir(NewPing*, NewPing*);
bool enemyFound(NewPing*, NewPing*, Direction);
bool getDir(IR*, IR*);
bool whiteFound(Direction);


#endif /* MAIN_H_ */
