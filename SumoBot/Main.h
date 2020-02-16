/*
 * Main.h
 *
 *  Created on: Feb 16, 2020
 *      Author: WinnieTrandinh
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <Arduino.h>
// #include <Arduino_FreeRTOS.h>
// #include <EEPROM.h>
#include "IR.h"
#include "Ultrasonic.h"
#include "Motors.h"

// typedefs
enum States {
	white, enemy, hunt, wander
};
enum Direction {
	left, center, right, none
};


// constants
// time to turn 90 degrees
const int timeFor90 = 1000;

// methods
bool getDir(Ultrasonic, Ultrasonic);
bool enemyFound(Ultrasonic, Ultrasonic, Direction);
bool getDir(IR, IR);
bool whiteFound(Direction);


#endif /* MAIN_H_ */
