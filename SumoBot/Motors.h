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
	// motor 1 = right
	// motor 2 = left
	int m1p1, m1p2, m1e, m2p1, m2p2, m2e;

	void cw(int, int, int, int);
	void ccw(int, int, int, int);
	void stop(int, int, int);
};

#endif /* MOTORS_H_ */
