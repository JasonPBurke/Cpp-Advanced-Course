#pragma once
#ifndef OVERLOADDEMO_H
#define OVERLOADDEMO_H

#include<array>
#include<iomanip>
#include<iostream>

using namespace std;

class OverloadDemo {
	//declare non-member operator functions as friend here if needed
public:
	// constructors
	OverloadDemo();
	OverloadDemo(int, double, string);
	// Overloading the operators in the OverloadDemo class
	OverloadDemo operator+(const OverloadDemo&) const;// plus operator
	OverloadDemo operator-(const OverloadDemo&) const;// minus opertor
	OverloadDemo operator*(const OverloadDemo&) const;// multiply operator
	OverloadDemo operator/(const OverloadDemo&);// divide operator
	OverloadDemo& operator++();// prefix increment operator
	OverloadDemo operator++(int);//postfix increment operator
	OverloadDemo& operator--();// prefix decrement operator
	OverloadDemo operator--(int);// postfix decrement operator

	// SETTERS
	void setIntOne(int);
	void setDoubleOne(double);
	void setStringOne(string);
	// GETTERS
	int getIntOne();
	double getDoubleOne();
	string getStringOne();

private:
	// private data
	int intOne{};
	double doubleOne{};
	string stringOne{};
}; // end class OverloadDemo

#endif // !OVERLOADDEMO_H
