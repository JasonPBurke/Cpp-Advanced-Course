// Order.cpp
// Order Class member function definitions

#include "stdafx.h"
#include<iomanip>
#include<sstream>
#include<string>
#include<vector>
#include "Order.h" // including the definition of class Order from Order.h

using namespace std;
// CONSTRUCTOR GOES HERE

int Order::orderCount = 0;
// SETTER FUNCTIONS
void Order::setOrderNum(int newOrderNum){ orderNum = newOrderNum; }
void Order::setCustID(int newCustID) { custID = newCustID; }
void Order::setProductNums(int newProdNum) { productNums.push_back(newProdNum); }
void Order::setOrderCreationTime(string CT) { orderCreationTime = CT;  }
void Order::setOrderCount() { orderCount++; }// increment order count

// GETTER FUNCTIONS
int Order::getOrderNum() { return orderNum; }
int Order::getCustID() { return custID; }
int Order::getProductNums(int myOrderNum) { return productNums[myOrderNum]; }
string Order::getOrderCreationTime() { return orderCreationTime; }
int Order::getOrderCount() { return orderCount; }

