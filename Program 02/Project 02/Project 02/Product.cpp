// Product.cpp
// Product Class member function definitions

#include "stdafx.h"
//#include<iomanip>
//#include<sstream>
#include<string>
//#include<vector>
#include "Product.h" // including the definition of class Order from Order.h

using namespace std;
// CONSTRUCTOR GOES HERE

int Product::productCount = 0;
// SETTER FUNCTIONS
void Product::setProductNum(int newProdNum) { productNum = newProdNum; }
void Product::setProductName(string newProdName) { productName = newProdName; }
void Product::setProductDescription(string newProdDesc) { productDescription = newProdDesc; }
void Product::setProductCreationTime(string z) { productCreationTime = z; }
void Product::setProductCount() { 
	productCount++;
}

// GETTER FUNCTIONS
int Product::getProductNum() { return productNum; }
string Product::getProductName() { return productName; }
string Product::getProductDescription() { return productDescription; }
string Product::getProductCreationTime() { return productCreationTime; }
int Product::getProductCount() { return productCount; }