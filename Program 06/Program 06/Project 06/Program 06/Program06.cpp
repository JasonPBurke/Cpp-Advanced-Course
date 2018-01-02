// Program06.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <iostream>
#include <limits>
#include "PhoneNumber.h"
using namespace std;

int main() {

	PhoneNumber phone;

	do {
		cout << "Enter phone number in the following format: (555) 555-5555" << endl;

		// cin >> phone invokes operator>> by implicitly issuing
		// the non-member function call operator>>(cin, phone)
		cin >> phone;

		// HERE YOU WILL CHECK THE FAIL BIT AND ALLOW THE USER TO ENTER ANOTHER PHONE NUMBER
		if (cin.fail() == 1) {

			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.clear();
			cout << "You have entered an invalid phone number.  Would you like to enter another number? (Y/N): ";			
			char userChoice;
			cin >> userChoice;
			if (toupper(userChoice) == 'Y') {
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.clear();
				continue;
			}
			else if (toupper(userChoice) == 'N') {
				cout << "GoodBye" << endl;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.clear();
				cin.get();
				return 0; //exit when you put this in a do-while
			}
			else cout << "There was an error.\n";				
		}

		if (cin.fail() == 0) break; // leave the do-while if no failure found
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.clear();
	} while (true);

	// cout << phone invokes operator<< by implicitly issuing
	// the non-member function call operator<<(cout, phone)
	cout << "\nThe phone number entered was:\n" << phone << endl;

	// Graceful Exit
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.clear();
	cout << "\n\n<ENTER> to exit: ";
	cin.get();

    return 0;
}