// OverlaodDemo.cpp
// OverloadDemo Class member function definitions

#include<array>
#include<iostream>
#include "stdafx.h"
#include "OverloadDemo.h"

using namespace std;

OverloadDemo::OverloadDemo(){}// default constructor
OverloadDemo::OverloadDemo(int newInt, double newDouble, string newString) { 
	intOne = newInt; 
	doubleOne = newDouble;
	stringOne = newString;
}
OverloadDemo OverloadDemo::operator+(const OverloadDemo& other) const {
	OverloadDemo result;
	result.intOne = intOne + other.intOne;
	result.doubleOne = doubleOne + other.doubleOne;
	result.stringOne = stringOne + other.stringOne;
	return result;	 
}
//When subtracting strings, the shorter string's length is subtracted from the larger string's length
OverloadDemo OverloadDemo::operator-(const OverloadDemo& otherObj) const {
	OverloadDemo result;
	result.intOne = intOne - otherObj.intOne; // subtract obj2 intOne from obj1 intOne
	result.doubleOne = doubleOne - otherObj.doubleOne; // subtract obj2 doubleOne from obj1 doubleOne
	// Find the larger string and subtract the length of the shorter from it
	unsigned int newStringSize;//used to resize obj3's string length 
	if (stringOne.length() > otherObj.stringOne.length()) {
		newStringSize = stringOne.length() - otherObj.stringOne.length();
	} 
	else { 
		newStringSize = otherObj.stringOne.length() - stringOne.length();
	}
	result.stringOne = stringOne + otherObj.stringOne;// populate result.stringOne for resize
	result.stringOne.resize(newStringSize); // resize stringOne with newStringSize
	return result;
}
// When multiplied, the string will = (string1+string2)squared...or repeated
OverloadDemo OverloadDemo::operator*(const OverloadDemo& other) const {
	OverloadDemo result;
	result.intOne = intOne * other.intOne;
	result.doubleOne = doubleOne * other.doubleOne;
	result.stringOne = stringOne + other.stringOne + " " + stringOne + other.stringOne;// make string 
	return result;
}
// When devided, a string will = the length of the larger string devided by the length of the smaller str
OverloadDemo OverloadDemo::operator/(const OverloadDemo& otherObj) {
	OverloadDemo result;
	result.intOne = intOne / otherObj.intOne;
	result.doubleOne = doubleOne / otherObj.doubleOne;
	// Find the larger string and subtract the length of the shorter from it
	unsigned int newStringSize;//used to resize obj3's string length
	if (stringOne.length() > otherObj.stringOne.length()) {
		newStringSize = stringOne.length() / otherObj.stringOne.length();
	}
	else {
		newStringSize = otherObj.stringOne.length() / stringOne.length();
	}
	result.stringOne = stringOne + otherObj.stringOne + " " + stringOne + otherObj.stringOne;
	result.stringOne.resize(newStringSize); // resize stringOne with newStringSize
	return result;
}
// the prefix++ operator used on a string will increase the length by one, and fill it with stringOne[0]
OverloadDemo& OverloadDemo::operator++() {// ++prefix increment
	intOne++;
	doubleOne++;
	int newLength = stringOne.length() + 1;
	stringOne = stringOne + stringOne[0];
	return *this;
}
// The postfix++ operator used on a string will increase the length by one, and fill it with stringOne[0]
OverloadDemo OverloadDemo::operator++(int) {// postfix++ increment
	OverloadDemo temp{ *this };
	intOne++;
	doubleOne++;
	int newLength = stringOne.length() + 1;
	stringOne = stringOne + stringOne[0];
	return temp;
}
// The prefix-- operator used on a string will reduce the string length by one
OverloadDemo& OverloadDemo::operator--() {// --prefix decrement
	intOne--;
	doubleOne--;
	int newLength = stringOne.length() - 1;
	stringOne.resize(newLength);
	return *this;
}
// The postfix-- operator used on a string will reduce the string length by one
OverloadDemo OverloadDemo::operator--(int) {// postfix-- decrement
	OverloadDemo temp{ *this };
	intOne--;
	doubleOne--;
	int newLength = stringOne.length() - 1;
	stringOne.resize(newLength);
	return temp;
}
// SETTERS
void OverloadDemo::setIntOne(int intOne) { this->intOne = intOne; }
void OverloadDemo::setDoubleOne(double doubleOne) { this->doubleOne = doubleOne; }
void OverloadDemo::setStringOne(string stringOne) { this->stringOne = stringOne; }
// GETTERS
int OverloadDemo::getIntOne() { return intOne; }
double OverloadDemo::getDoubleOne() { return doubleOne; }
string OverloadDemo::getStringOne() { return stringOne; }

