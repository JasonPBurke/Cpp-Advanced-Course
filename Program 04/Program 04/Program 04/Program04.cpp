// Program04.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<iostream>
#include<iomanip>
#include<string>
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

int main() {
	
	cout << "This program calculates the cost for a package delivery " << endl
		 << "as a regular package, a two-day package, or an overnight package." << endl << endl;
	bool keepGoing = true;
	do {
		cout << "Enter A for a regular package, B for a two-day, or C for an overnight package(X to exit): ";
		char usrChoice;
		cin >> usrChoice;
		cin.clear();
		cin.ignore(1024, '\n');
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
			cout << endl << "Please enter the additional cost-per-ounce rate of the overnight fee: ";
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

		Package p{ sName, sAddress, sCity, sState, sZip, rName, rAddress,
			rCity, rState, rZip, wt, cstPerOz };
		TwoDayPackage twoDayP{ sName, sAddress, sCity, sState, sZip, rName,
			rAddress, rCity, rState, rZip, wt, cstPerOz, twoDayCost };
		OvernightPackage overnightP{ sName, sAddress, sCity, sState, sZip, rName,
			rAddress, rCity, rState, rZip, wt, cstPerOz, overnightCost };


		if (toupper(usrChoice) == 'A') {

			cout << endl << "A package weighing " << p.getWeight() << " ounces, with a cost-per-ounce of $"
				<< setprecision(2) << fixed << p.getCostPerOunce() << ", would cost $" << p.calculateCost() << " to ship." << endl;
			cout << endl << " Sender Info" << endl << " -----------" << endl;
			cout << " Name: " << p.getSenderName() << endl << " Address:" << p.getSenderAddress() << endl
				<< " City: " << p.getSenderCity() << endl << " State: " << p.getSenderState() << endl
				<< " Zip Code: " << p.getSenderZip() << endl << endl;

			cout << " Receiver Info" << endl << " -------------" << endl;
			cout << " Name: " << p.getRecieverName() << endl << " Address:" << p.getRecieverAddress() << endl
				<< " City: " << p.getRecieverCity() << endl << " State: " << p.getRecieverState() << endl
				<< " Zip Code: " << p.getRecieverZip() << endl << endl;
		}
		else if (toupper(usrChoice) == 'B') {
			cout << endl << "A package weighing " << twoDayP.getWeight() << " ounces with a cost-per-ounce of $"
				<< twoDayP.getCostPerOunce() << ", plus the two-day-fee of $" << twoDayP.getTwoDayFee() << "," << endl
				<< "would cost $" << setprecision(2) << fixed << twoDayP.calculateCost() << " to ship from sender to receiver." << endl;
			cout << endl << " Sender Info" << endl << " -----------" << endl;
			cout << " Name: " << twoDayP.getSenderName() << endl << " Address:" << twoDayP.getSenderAddress() << endl
				<< " City: " << twoDayP.getSenderCity() << endl << " State: " << twoDayP.getSenderState() << endl
				<< " Zip Code: " << twoDayP.getSenderZip() << endl << endl;

			cout << " Receiver Info" << endl << " -------------" << endl;
			cout << " Name: " << twoDayP.getRecieverName() << endl << " Address:" << twoDayP.getRecieverAddress() << endl
				<< " City: " << twoDayP.getRecieverCity() << endl << " State: " << twoDayP.getRecieverState() << endl
				<< " Zip Code: " << twoDayP.getRecieverZip() << endl << endl;
		}
		else if (toupper(usrChoice) == 'C') {
			cout << endl << "A package weighing " << overnightP.getWeight() << " ounces with a cost-per-ounce of $"
				<< setprecision(2) << fixed << overnightP.getCostPerOunce() << ", plus the additional cost per ounce rate of $"
				<< setprecision(2) << fixed << overnightP.getOvernightRate() << "," << endl
				<< "would cost $" << setprecision(2) << fixed << overnightP.calculateCost() << " to ship from sender to receiver." << endl;
			cout << endl << " Sender Info" << endl << " -----------" << endl;
			cout << " Name: " << overnightP.getSenderName() << endl << " Address:" << overnightP.getSenderAddress() << endl
				<< " City: " << overnightP.getSenderCity() << endl << " State: " << overnightP.getSenderState() << endl
				<< " Zip Code: " << overnightP.getSenderZip() << endl << endl;

			cout << " Receiver Info" << endl << " -------------" << endl;
			cout << " Name: " << overnightP.getRecieverName() << endl << " Address:" << overnightP.getRecieverAddress() << endl
				<< " City: " << overnightP.getRecieverCity() << endl << " State: " << overnightP.getRecieverState() << endl
				<< " Zip Code: " << overnightP.getRecieverZip() << endl << endl;
		}
		else if (toupper(usrChoice) == 'X') {
			keepGoing = false;// this is for the exit point ... use when you add a DO WHILE LOOP
		}
		cout << "Would you like to enter another package(Y/N)? ";
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
		}// end inner while loop
		
	} while (keepGoing == true); // end do-while

	//cout << "Total normal shipping cost for the package: $" << p.calculateCost() << endl << endl;
	//cout << "Total 2-day shipping cost for the package: $" << twoDayP.calculateCost() << endl << endl;
	//cout << "Total overnight shipping cost for the package: $" << overnightP.calculateCost() << endl << endl;
	cout << endl << "Goodbye" << endl << endl;
	system("PAUSE");
    return 0;
}

