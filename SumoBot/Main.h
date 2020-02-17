/*
 * Main.h
 *
 *  Created on: Feb 16, 2020
 *      Author: WinnieTrandinh
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <NewPing.h>
// #include <Arduino_FreeRTOS.h>
// #include <EEPROM.h>
#include "IR.h"
#include "Motors.h"

// typedefs
enum States {
	white, enemy, hunt, wander
};
enum Direction {
	left, center, right, none
};


// constants
// ultrasonic
const int trigPin1 = 1;
const int echoPin1 = 2;
const int trigPin2 = 3;
const int echoPin2 = 4;
const int maxDist = 20;

// motors
const int motor1Pin1 = 5;
const int motor1Pin2 = 6;
const int motor2Pin1 = 7;
const int motor2Pin2 = 8;
// time to turn 90 degrees
const int timeFor90 = 1000;

// methods
bool getDir(NewPing*, NewPing*);
bool enemyFound(NewPing*, NewPing*, Direction);
bool getDir(IR, IR);
bool whiteFound(Direction);


#endif /* MAIN_H_ */
