#pragma once
// Order.h
// Order Class definition
// Member functions defined in Order.cpp file

#include "stdafx.h"
#include<iomanip>
#include<iostream>
#include<string>
#include<vector>
#include<sstream> // to store a formatted customerCreationTime to output to main

#ifndef ORDER_H
#define ORDER_H

using namespace std;

class Order {

public:
	// SETTERS
	void setOrderNum(int);
	void setCustID(int);
	void setProductNums(int);
	void setOrderCreationTime(string);
	static void setOrderCount(); // static maybe

	// GETTERS
	int getOrderNum();
	int getCustID();
	int getProductNums(int);
	string getOrderCreationTime();// MAYBE MAKE THIS CLASS A FRIEND OF CUSTOMER AND CALL ITS FUNCTION
	static int getOrderCount();
private:
	int orderNum{ 0 };
	int custID{ 0 };
	vector<int> productNums;
	string orderCreationTime = "NONE";
	static int orderCount;
};

#endif