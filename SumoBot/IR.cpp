/*
 * IR.cpp
 *
 *  Created on: Feb 16, 2020
 *      Author: WinnieTrandinh
 */

#include "IR.h"
#include <Arduino.h>

IR::IR(int signalPin) {
	signal = signalPin;

	// setup pin
	pinMode(signal, INPUT);
}

IR::~IR() {
	// TODO Auto-generated destructor stub
}

bool IR::isWhite() {
	return (digitalRead(signal) == LOW);
}

