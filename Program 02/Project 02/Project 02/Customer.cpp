// Customer.cpp
// Customer Class member function definitions

#include "stdafx.h"
#include<iomanip>
#include<sstream>
#include<string>
#include<vector>
#include "Customer.h" // including the definition of class Customer from Customer.h

using namespace std;
// YOU WILL PROBABLY WANT TO DEFINE A CONSTRUCTOR AS WELL

int Customer::customerCount = 0;
// Define all the setter functions
void Customer::setCustID(int newID) { custID = newID; }
// TRY AND USE THE this KEYWORD HERE. RENAME TO name FIRST.
void Customer::setName(string newName) { name = newName; }
void Customer::setAddress(string newAddress) { address = newAddress; }
void Customer::setOrderNums(int newOrderNum) { 
	orderNums.push_back(newOrderNum);
	//orderNum++;
}
void Customer::setCustomerCreationTime(string z) { customerCreationTime = z; }
void Customer::setCustomerCount() { customerCount++; }

// Define all the getter functions
int Customer::getCustID() { return custID; }
string Customer::getName() { return name; }
string Customer::getAddress() {	return address; }
int Customer::getOrderNums(int custNum) { return orderNums[custNum]; }// THIS SHOULD RETURN THE VECTOR I THINK??
string Customer::getCustomerCreationTime() { return customerCreationTime; }//RETURN AS AN SSTREAM STR
int Customer::getCustomerCount() { return customerCount; }