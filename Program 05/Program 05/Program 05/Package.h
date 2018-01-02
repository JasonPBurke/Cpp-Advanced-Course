//#pragma once

#ifndef PACKAGE_H
#define PACKAGE_H

#include "stdafx.h"
#include<string>
using namespace std;

class Package {

public:
	// CONSTRUCTOR: initialize all data
	Package(const string&, const string&, const string&, const string&, unsigned int,
		const string&, const string&, const string&, const string&, unsigned int, double, double);
	// VIRTUAL DESTRUCTOR
	virtual ~Package() = default;
	// SETTERS
	void setSenderName(const string&);
	void setSenderAddress(const string&);
	void setSenderCity(const string&);
	void setSenderState(const string&);
	void setSenderZip(unsigned int);

	void setRecieverName(const string&);
	void setRecieverAddress(const string&);
	void setRecieverCity(const string&);
	void setRecieverState(const string&);
	void setRecieverZip(unsigned int);

	void setWeight(double);
	void setCostPerOunce(double);//

								 // GETTERS
	string getSenderName();
	string getSenderAddress();
	string getSenderCity();
	string getSenderState();
	unsigned int getSenderZip();

	string getRecieverName();
	string getRecieverAddress();
	string getRecieverCity();
	string getRecieverState();
	unsigned int getRecieverZip();

	double getWeight();
	double getCostPerOunce();

	// MEMBER FUNCTIONS
	// USING virtual TO ALLOW FOR POLYMORPHIC BEHAVIOR WHEN USING DERIVED CLASSES
	virtual double calculateCost();// must verify inputs are > 0.. pass in wt and costPerOz
	//virtual double getTwoDayFee();
	//virtual double getOvernightRate();

private:
	// SENDER INFO DATA
	string senderName;
	string senderAddress;
	string senderCity;
	string senderState;
	unsigned int senderZip;
	// RECIEVER INFO DATA
	string recieverName;
	string recieverAddress;
	string recieverCity;
	string recieverState;
	unsigned int recieverZip;

	double weight = 0;
	double costPerOunce = 0;
};
#endif