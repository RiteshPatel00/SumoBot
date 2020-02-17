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
int m1p1, m1p2, m1e, m2p1, m2p2, m2e;

Motors::Motors(int pin1, int pin2, int enable1, int pin3, int pin4, int enable2) {
	m1p1 = pin1;
	m1p2 = pin2;
	m1e = enable1;
	m2p1 = pin3;
	m2p2 = pin4;
	m2e = enable2;

	// reset pins
	stop(pin1, pin2, enable1);
	stop(pin3, pin4, enable2);
}

Motors::~Motors() {
	// TODO Auto-generated destructor stub
}

// input pwm off 0-100 scale
void Motors::cw(int pin1, int pin2, int enable, int val) {
	val = (int) ((val/100.0)*255);
	digitalWrite(pin1, HIGH);
	digitalWrite(pin2, LOW);
	analogWrite(enable, val);
}

void Motors::ccw(int pin1, int pin2, int enable, int val) {
	val = (int) ((val/100.0)*255);
	digitalWrite(pin1, LOW);
	digitalWrite(pin2, HIGH);
	analogWrite(enable, val);
}

void Motors::stop(int pin1, int pin2, int enable) {
	digitalWrite(pin1, 0);
	digitalWrite(pin2, 0);
	analogWrite(enable, 0);
}

void Motors::softLeft() {
	// motorLeft = 50;
	// motorRight = 75;
	cw(m1p1, m1p2, m1e, 75);
	ccw(m2p1, m2p2, m2e, 50);
}

void Motors::softRight() {
	// motorLeft = 75;
	// motorRight = 50;
	cw(m1p1, m1p2, m1e, 50);
	ccw(m2p1, m2p2, m2e, 75);
}

void Motors::hardLeft() {
	// motorLeft = -100;
	// motorRight = 100;
	cw(m1p1, m1p2, m1e, 100);
	cw(m2p1, m2p2, m2e, 100);
}

void Motors::hardRight() {
	// motorLeft = 100;
	// motorRight = -100;
	ccw(m1p1, m1p2, m1e, 100);
	ccw(m2p1, m2p2, m2e, 100);
}

void Motors::forward(int val) {
	cw(m1p1, m1p2, m1e, val);
	ccw(m2p1, m2p2, m2e, val);
}

void Motors::wander() {
	// motorLeft = 50;
	// motorRight = 50;
}
