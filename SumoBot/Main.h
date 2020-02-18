/*
 * Main.h
 *
 *  Created on: Feb 16, 2020
 *      Author: WinnieTrandinh
 */

#ifndef MAIN_H_
#define MAIN_H_

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


// ultrasonic
// digital output
const int trigPin1 = 1;
// analog input
const int echoPin1 = 2;
// digital output
const int trigPin2 = 3;
// digital input
const int echoPin2 = 4;
// distance in cm
const int maxDist = 20;

// motors
// digital output
const int motor1Pin1 = 5;
const int motor1Pin2 = 6;
// analog output
const int motor1Enable = 9;
// digital output
const int motor2Pin1 = 7;
const int motor2Pin2 = 8;
// analog output
const int motor2Enable = 10;
// time to turn 90 degrees in milliseconds
const int timeFor90 = 1000;

// IR
// digital output
const int LED1Pin = 11;
// digital input
const int signal1Pin = 12;
// digital output
const int LED2Pin = 13;
// digital input
const int signal2Pin = 14;

// methods
bool getDir(NewPing*, NewPing*);
bool enemyFound(NewPing*, NewPing*, Direction);
bool getDir(IR*, IR*);
bool whiteFound(Direction);


#endif /* MAIN_H_ */
