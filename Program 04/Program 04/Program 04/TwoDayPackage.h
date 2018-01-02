#pragma once
#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "stdafx.h"
#include<string>
//#include<iomanip>
//#include<iostream>
#include "Package.h"// include the base class headder file
using namespace std;

class TwoDayPackage : public Package {
public:
	TwoDayPackage(const string&, const string&, const string&, const string&, unsigned int,
		const string&, const string&, const string&, const string&, unsigned int, double, double, double);

	void setTwoDayFee(double);
	double getTwoDayFee();
	double calculateCost();
private:
	double twoDayFee;
};
#endif