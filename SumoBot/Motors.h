/*
 * Motors.h
 *
 *  Created on: Feb 16, 2020
 *      Author: WinnieTrandinh
 */

#ifndef MOTORS_H_
#define MOTORS_H_

class Motors {
public:
	Motors();

	void softLeft();
	void softRight();
	void hardLeft();
	void hardRight();
	void push();
	void forward();
	void wander();

	virtual ~Motors();
};

#endif /* MOTORS_H_ */
