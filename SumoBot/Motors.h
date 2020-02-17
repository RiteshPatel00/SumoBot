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
	Motors(int, int, int, int, int, int);

	void softLeft();
	void softRight();
	void hardLeft();
	void hardRight();
	void forward(int);
	void wander();

	virtual ~Motors();

private:
	void cw(int, int, int, int);
	void ccw(int, int, int, int);
	void stop(int, int, int);
};

#endif /* MOTORS_H_ */
