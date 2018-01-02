#pragma once
#pragma once
// Product.h
// Product Class definition
// Member functions defined in Product.cpp file

// YOU NEED TO DETERMINE WHAT NEEDS TO REMAIN HERE...NOT ALL ARE APLICABLE
#include "stdafx.h"
#include<iomanip>// IS THIS USED??
#include<iostream>// NOT USED
#include<string>
#include<vector>// NOT USED
#include<sstream> // to store a formatted customerCreationTime to output to main// NOT USED YET

#ifndef PRODUCT_H
#define PRODUCT_H

using namespace std;

class Product {

public:
	// SETTERS
	void setProductNum(int);
	void setProductName(string);
	void setProductDescription(string);
	void setProductCreationTime(string);
	void setProductCount(); // static maybe
	// GETTERS
	int getProductNum();
	string getProductName();
	string getProductDescription();
	string getProductCreationTime();// MAYBE MAKE THIS CLASS A FRIEND OF ORDER AND CALL ITS FUNCTION
	static int getProductCount();
private:
	int productNum{ 0 };
	string productName = "NONE";
	string productDescription = "NONE";
	string productCreationTime = "NONE";
	static int productCount;
};

#endif