#pragma once
// Customer.h
// Customer Class definition
// Member functions defined in Customer.cpp file

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<sstream> // to store a formatted customerCreationTime to output to main

// To prevent multiple inclusions of the header file
#ifndef CUSTOMER_H
#define CUSTOMER_H

using namespace std;

class Customer {

public:
	// Setters... THESE MAY NEED TO BE PRIVATE METHODS...SHOULD BE I THINK
	void setCustID(int);
	void setName(string);
	void setAddress(string);
	void setOrderNums(int);// adds a new order number to the vector orderNums
	void setCustomerCreationTime(string);// the function will get the time and store in a sstring??
	static void setCustomerCount();// THIS MAY NOT NEED TO BE STATIC...THE DATA IS STATIC, NOT THE FCTN
	// Getters
	int getCustID();
	string getName();
	string getAddress();
	int getOrderNums(int);// this should return the vector i think??
	string getCustomerCreationTime();// the function will get the time
	int getCustomerCount();
	
private:
	unsigned int custID;// {0};// SHOULD I ASSIGN A DEFAULT VALUE HERE?
	string name;// = "NONE";
	string address;// = "NONE";
	vector<int> orderNums;
	string customerCreationTime;// = "NONE";
	static int customerCount;// a member with an in-class initializer must be const
};

#endif