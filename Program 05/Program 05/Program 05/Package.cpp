#include "stdafx.h"
#include<iomanip>
#include<string>
#include<stdexcept>
#include<iostream>
#include "Package.h"
using namespace std;

Package::Package(const string& sName = "empty", const string& sAddress = "empty", const string& sCity = "empty",
	const string& sState = "empty", unsigned int sZip = 000000,
	const string& rName = "empty", const string& rAddress = "empty", const string& rCity = "empty",
	const string& rState = "empty", unsigned int rZip = 000000, double wt = 0.00, double costPerOz = 0.00)
	: senderName(sName), senderAddress(sAddress), senderCity(sCity), senderState(sState),
	senderZip(sZip), recieverName(rName), recieverAddress(rAddress), recieverCity(rCity),
	recieverState(rState), recieverZip(rZip)
{
	setWeight(wt);
	setCostPerOunce(costPerOz);
}

void Package::setSenderName(const string& name) { senderName = name; }
string Package::getSenderName() { return senderName; }
void Package::setSenderAddress(const string& address) { senderAddress = address; }
string Package::getSenderAddress() { return senderAddress; }
void Package::setSenderCity(const string& city) { senderCity = city; }
string Package::getSenderCity() { return senderCity; }
void Package::setSenderState(const string& state) { senderState = state; }
string Package::getSenderState() { return senderState; }
void Package::setSenderZip(unsigned int zip) { senderZip = zip; }
unsigned int Package::getSenderZip() { return senderZip; }

void Package::setRecieverName(const string& name) { recieverName = name; }
string Package::getRecieverName() { return recieverName; }
void Package::setRecieverAddress(const string& address) { recieverAddress = address; }
string Package::getRecieverAddress() { return recieverAddress; }
void Package::setRecieverCity(const string& city) { recieverCity = city; }
string Package::getRecieverCity() { return recieverCity; }
void Package::setRecieverState(const string& state) { recieverState = state; }
string Package::getRecieverState() { return recieverState; }
void Package::setRecieverZip(unsigned int zip) { recieverZip = zip; }
unsigned int Package::getRecieverZip() { return recieverZip; }

void Package::setWeight(double wt) {
	if (wt <= 0) {
		cout << "Weight must be greater than zero.";
	}
	else weight = wt;
}
void Package::setCostPerOunce(double cstPerOz) {
	if (cstPerOz <= 0) {
		cout << "Cost Per Ounce must be greater than zero.";
	}
	else costPerOunce = cstPerOz;
}

double Package::getWeight() { return weight; }
double Package::getCostPerOunce() { return costPerOunce; }


double Package::calculateCost() { // must verify inputs are > 0.. pass in wt and costPerOz
	return getWeight() * getCostPerOunce();// is a better way to get the info
}

//double Package::getTwoDayFee() { return 0.0; }// not sure how to do this w/o a return
//double Package::getOvernightRate() { return 0.0; }