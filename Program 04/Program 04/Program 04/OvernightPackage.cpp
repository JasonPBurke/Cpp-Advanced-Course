#include "stdafx.h"
#include "OvernightPackage.h"
#include<string>
using namespace std;

OvernightPackage::OvernightPackage(const string& sName, const string& sAddress, const string& sCity,
	const string& sState, unsigned int sZip,
	const string& rName, const string& rAddress, const string& rCity,
	const string& rState, unsigned int rZip, double wt, double costPerOz, double fee)
	: Package(sName, sAddress, sCity, sState, sZip, rName, rAddress, rCity, rState, rZip, wt, costPerOz) {
	setOvernightRate(fee);
}

void OvernightPackage::setOvernightRate(double rate) { overnightRate = rate; };
double OvernightPackage::getOvernightRate() { return overnightRate; };
double OvernightPackage::calculateCost() {
	return (getCostPerOunce() + getOvernightRate()) * getWeight();
};