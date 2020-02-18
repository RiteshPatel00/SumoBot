/*
 * IR.cpp
 *
 *  Created on: Feb 16, 2020
 *      Author: WinnieTrandinh
 */

#include "IR.h"
#include <Arduino.h>

IR::IR(int LEDPin, int signalPin) {
	LED = LEDPin;
	signal = signalPin;

	// setup pins
	pinMode(LED, OUTPUT);
	pinMode(signal, INPUT);

	// turn on LED
	digitalWrite(LED, HIGH);
}

IR::~IR() {
	// TODO Auto-generated destructor stub
}

bool IR::isWhite() {
	return (digitalRead(signal) == HIGH);
}

