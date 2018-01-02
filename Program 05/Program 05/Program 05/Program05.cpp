// Program05.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

void virtualViaPointer(Package* const, double&);

int main() 
{
	cout << "This program calculates the cost for a package delivery " << endl
		<< "as a regular package, a two-day package, or an overnight package." << endl << endl;

	// BUILD A VECTOR OF PACKAGE POINTERS TO HOLD INSTANCES OF DERIVED CLASSES REFRENCED BY BASE CLASS POINTERS
	vector<Package *> packages{};
	bool keepGoing = true;
	static double costAccumulator;

	do {
		bool valid = false;
		char usrChoice;
		while (valid == false) {
			cout << "Enter A for a regular package, B for a two-day, or C for an overnight package(X to exit): ";
			
			cin >> usrChoice;
			cin.clear();
			cin.ignore(1024, '\n');
			if (toupper(usrChoice) == 'A' || toupper(usrChoice) == 'B' || toupper(usrChoice) == 'C' || toupper(usrChoice) == 'X') {
				valid = true;
			}
			else cout << "Invalid entry.  Please try again.\n" << endl;
		}
		

		string sName, sAddress, sCity, sState, rName, rAddress, rCity, rState;
		unsigned int sZip, rZip;
		double wt = 0, cstPerOz = 0, twoDayCost = 0, overnightCost = 0;

		if (toupper(usrChoice) == 'A') {}// do nothing, but dont enter the other loops
		else if (toupper(usrChoice) == 'B') {
			cout << endl << "Please enter the cost of the two-day fee: ";
			cin >> twoDayCost;
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if (toupper(usrChoice) == 'C') {
			cout << endl << "Please enter the additional cost-per-ounce rate for the overnight package: ";
			cin >> overnightCost;
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if (toupper(usrChoice) == 'X') {
			keepGoing = false;
			break;
		}

		cout << endl << "Please enter the sender's info" << endl;
		cout << " Name: ";
		getline(cin, sName);
		cout << " Address: ";
		getline(cin, sAddress);
		cout << " City: ";
		getline(cin, sCity);
		cout << " State: ";
		getline(cin, sState);
		cout << " Zip Code: ";
		cin >> sZip;
		cin.clear();
		cin.ignore(1024, '\n');

		cout << endl << "Please enter the receiver's info" << endl;
		cout << " Name: ";
		getline(cin, rName);
		cout << " Address: ";
		getline(cin, rAddress);
		cout << " City: ";
		getline(cin, rCity);
		cout << " State: ";
		getline(cin, rState);
		cout << " Zip Code: ";
		cin >> rZip;
		cin.clear();
		cin.ignore(1024, '\n');

		cout << endl << "Now enter the weight in ounces for the package: ";
		cin >> wt;
		cin.clear();
		cin.ignore(1024, '\n');
		cout << endl << "And the cost-per-ounce for the package: ";
		cin >> cstPerOz;
		cin.clear();
		cin.ignore(1024, '\n');

		// MAYBE DO AN IF-ELSE HERE TO CREATE ONLY THE APPROPRIATE OBJECT INSTEAD OF ALL 3
		// cant, as then im out of scope as soon as i leave the if-else
		// EDIT: IF I PUT THE packages.pushpback's IN THE IF-ELSE AS WELL, I AM IN SCOPE
		//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// NEED TO CREATE A NEW CLASS OBJECT FOR EACH PACKAGE ENTERED.  AS IS, OBJECT DATA IS JUST OVERWRITTEN
		/*
		// THIS BROKE THE PROGRAM.  VECTOR OUTPUT HELD ONLY THE LAST CLASS OBJECT DATA ENTERED
		if (toupper(usrChoice == 'A')) {
			Package *package = new Package{ sName, sAddress, sCity, sState, sZip, rName, rAddress,
				rCity, rState, rZip, wt, cstPerOz };
			{ packages.push_back(&package); }
		}
		else if (toupper(usrChoice == 'B')) {
			TwoDayPackage *twoDayPackage = new TwoDayPackage{ sName, sAddress, sCity, sState, sZip, rName,
				rAddress, rCity, rState, rZip, wt, cstPerOz, twoDayCost };
			{ packages.push_back(&twoDayPackage); }
		}
		else if (toupper(usrChoice == 'C')) {
			OvernightPackage *overnightPackage = new OvernightPackage{ sName, sAddress, sCity, sState, sZip, rName,
				rAddress, rCity, rState, rZip, wt, cstPerOz, overnightCost };
			{ packages.push_back(&overnightPackage); }
		}
		*/
		Package *package = new Package{ sName, sAddress, sCity, sState, sZip, rName, rAddress,
			rCity, rState, rZip, wt, cstPerOz };
		TwoDayPackage *twoDayPackage = new TwoDayPackage{ sName, sAddress, sCity, sState, sZip, rName,
			rAddress, rCity, rState, rZip, wt, cstPerOz, twoDayCost };
		OvernightPackage *overnightPackage = new OvernightPackage{ sName, sAddress, sCity, sState, sZip, rName,
			rAddress, rCity, rState, rZip, wt, cstPerOz, overnightCost };

		// STEP #05
		if (toupper(usrChoice) == 'A') { packages.push_back(package); }
		if (toupper(usrChoice) == 'B') { packages.push_back(twoDayPackage); }
		if (toupper(usrChoice) == 'C') { packages.push_back(overnightPackage); }


		cout << "\nWould you like to enter another package(Y/N)? ";
		char userChoice;

		while (true) {
			cin >> userChoice;
			cin.clear();
			cin.ignore(1024, '\n');
			if (toupper(userChoice) == 'N') {
				keepGoing = false;
				break;
			}
			else if (toupper(userChoice) == 'Y') { break; }
			else { cout << endl << "That is an invalid choice. Please enter Y or N: "; }
		}// 
		if (keepGoing == false) {
			cout << "\nPackage vector info report: " << endl;
			for (Package* employeePtr : packages) {
				virtualViaPointer(employeePtr, costAccumulator);
				// WHEN TRYING TO OUTPUT THE PACKAGES VECTOR FROM OUTSIDE THE WHILE LOOP, = EMPTY VECTOR
			}
		}
	} while (keepGoing == true);

	cout << "----------------------------------------------------" << endl;
	cout << "The total shipping cost for all packages is: $" << costAccumulator << endl;
	cout << "----------------------------------------------------\n" << endl << endl;
	
	system("PAUSE");
    return 0;
}

void virtualViaPointer(Package* const baseClassPtr, double &accumulator) {
	accumulator += baseClassPtr->calculateCost();

	cout << setprecision(2) << fixed;
	cout << endl << " Sender Info" << endl << " -----------" << endl;
	cout << " Name: " << baseClassPtr->getSenderName() << endl 
		<< " Address:" << baseClassPtr->getSenderAddress() << endl
		<< " City: " << baseClassPtr->getSenderCity() << endl 
		<< " State: " << baseClassPtr->getSenderState() << endl
		<< " Zip Code: " << baseClassPtr->getSenderZip() << endl << endl;
	//if(baseClassPtr->getTwoDayFee())
	cout << " Receiver Info" << endl << " -------------" << endl;
	cout << " Name: " << baseClassPtr->getRecieverName() << endl
		<< " Address:" << baseClassPtr->getRecieverAddress() << endl
		<< " City: " << baseClassPtr->getRecieverCity() << endl
		<< " State: " << baseClassPtr->getRecieverState() << endl
		<< " Zip Code: " << baseClassPtr->getRecieverZip() << endl << endl;
	cout << " Package Weight in Ounces: " << baseClassPtr->getWeight() << endl;
	cout << " Shipping Cost-Per-Ounce: $" << baseClassPtr->getCostPerOunce() << endl;
	// THESE ARE NOT WORKING....TYPEID'S ARE NOT MATCHING...FIND AN ALTERNITAVE TO DETERMINE 2DAY/OVERNIGHT
	// I THINK I NEED TO INCLUDE THE FUNCTIONS IN THE PACKAGE CLASS AND OVERRIDE THEM...CAN MAKE THEM VIRTUAL
	// YEP, WORKING NOW
	TwoDayPackage *twoDay = dynamic_cast<TwoDayPackage*>(baseClassPtr);
	if (twoDay) {
		cout << " Two-Day Shipping Fee: $" << twoDay->getTwoDayFee() << endl;
	}
	OvernightPackage *overnight = dynamic_cast<OvernightPackage*>(baseClassPtr);
	if (overnight) {
		cout << " Additional Cost-Per-Ounce for Overnight Package: $" << overnight->getOvernightRate() << endl;
	}
	cout << "\nTotal shipping cost for this " << typeid(*baseClassPtr).name()
		<< " is: $" << baseClassPtr->calculateCost() << endl << endl;
}

