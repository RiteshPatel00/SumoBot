/*
 * Motors.cpp
 *
 *  Created on: Feb 16, 2020
 *      Author: WinnieTrandinh
 */

//				***** calibrate motors *****

#include <Arduino.h>
#include "Motors.h"

// motor 1 = right
// motor 2 = left
int m1p1, m1p2, m2p1, m2p2;

Motors::Motors(int pin1, int pin2, int pin3, int pin4) {
	m1p1 = pin1;
	m1p2 = pin2;
	m2p1 = pin3;
	m2p2 = pin4;
}

Motors::~Motors() {
	// TODO Auto-generated destructor stub
}

// pwm based off 0-100 scale
void Motors::cw(int pin1, int pin2, int val) {
	val = (val/100)*255;
	analogWrite(pin1, val);
	analogWrite(pin2, 0);
}

void Motors::ccw(int pin1, int pin2, int val) {
	val = (val/100)*255;
	analogWrite(pin1, 0);
	analogWrite(pin2, val);
}

void Motors::stop(int pin1, int pin2) {
	analogWrite(pin1, 0);
	analogWrite(pin2, 0);
}

void Motors::softLeft() {
	// motorLeft = 50;
	// motorRight = 75;
	cw(m1p1, m1p2, 75);
	ccw(m2p1, m2p2, 50);
}

void Motors::softRight() {
	// motorLeft = 75;
	// motorRight = 50;
	cw(m1p1, m1p2, 50);
	ccw(m2p1, m2p2, 75);
}

void Motors::hardLeft() {
	// motorLeft = -100;
	// motorRight = 100;
	cw(m1p1, m1p2, 100);
	cw(m2p1, m2p2, 100);
}

void Motors::hardRight() {
	// motorLeft = 100;
	// motorRight = -100;
	ccw(m1p1, m1p2, 100);
	ccw(m2p1, m2p2, 100);
}

void Motors::forward(int val) {
	cw(m1p1, m1p2, val);
	ccw(m2p1, m2p2, val);
}

void Motors::wander() {
	// motorLeft = 50;
	// motorRight = 50;
}
