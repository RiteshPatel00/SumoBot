/*
 * IR.h
 *
 *  Created on: Feb 16, 2020
 *      Author: WinnieTrandinh
 */

#ifndef IR_H_
#define IR_H_

class IR {
public:
	IR(int);

	bool isWhite();

	virtual ~IR();
private:
	int signal;
};

#endif /* IR_H_ */
