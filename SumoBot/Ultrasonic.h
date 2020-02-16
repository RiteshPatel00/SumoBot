/*
 * Ultrasonic.h
 *
 *  Created on: Feb 16, 2020
 *      Author: WinnieTrandinh
 */

/*
 methods:
 - getDist()

 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

class Ultrasonic {
public:
	Ultrasonic();

	int getDist();

	virtual ~Ultrasonic();
};

#endif /* ULTRASONIC_H_ */
