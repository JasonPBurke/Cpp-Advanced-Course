#include "stdafx.h"
#include "TwoDayPackage.h"
#include<string>

using namespace std;

TwoDayPackage::TwoDayPackage(const string& sName, const string& sAddress, const string& sCity,
	const string& sState, unsigned int sZip,
	const string& rName, const string& rAddress, const string& rCity,
	const string& rState, unsigned int rZip, double wt, double costPerOz, double fee)
	: Package(sName, sAddress, sCity, sState, sZip, rName, rAddress, rCity, rState, rZip, wt, costPerOz) {
	setTwoDayFee(fee);
}

void TwoDayPackage::setTwoDayFee(double fee) { twoDayFee = fee; }
double TwoDayPackage::getTwoDayFee() { return twoDayFee; }
double TwoDayPackage::calculateCost() { return getTwoDayFee() + (getWeight() * getCostPerOunce()); }
