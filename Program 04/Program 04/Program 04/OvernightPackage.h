#pragma once
#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include "stdafx.h"
#include "Package.h"// include the base class headder file
#include<string>
using namespace std;

class OvernightPackage : public Package {
public:
	OvernightPackage(const string&, const string&, const string&, const string&, unsigned int,
		const string&, const string&, const string&, const string&, unsigned int, double, double, double);

	void setOvernightRate(double);// the overnightRate is an additional COST PER OUNCE RATE
	double getOvernightRate();
	double calculateCost();

private:// the overnightRate is an additional COST PER OUNCE RATE not a flat fee like 2-day is
	double overnightRate;
};
#endif