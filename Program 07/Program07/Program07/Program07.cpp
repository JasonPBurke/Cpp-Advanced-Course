// Program07.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<cstdlib>
#include<sstream>
#include<vector>
using namespace std;

void outputLine(const string&, const string&, const string&, const string&,
				const string&, const string&, const string&);// prototype

int main()
{
	// ifstream constructor opens the file
	ifstream inCustomerMaster("CustomerMaster.txt", ios::in);
	ofstream outProcucts("Products.txt", ios::out);//create an out file to write product data to 
	ofstream outOrders("Orders.txt",ios::out);// create an out file to write order data to
	ifstream inOrders("Orders.txt", ios::in);// open Orders.txt for reading

	// exit program if ifstream could not open file
	if (!inCustomerMaster) {
		cerr << "File could not be opened" << endl;
		exit(EXIT_FAILURE);
	}// end if

	string custId, zip;// customerID and zipCode....changed from int
	string fName, lName, stAddress, city, state, lineTemp; // firstName, lastName, streetAddress, City, State
	vector<string> cityList(0);
	vector<string> stateList(0);
	vector<string> zipOrders(0);

	cout << "This program allows you to search customer data, save order data,\n"
		<< " and save and search product data using multiple files\n"
		<< "Please enter the number corrisponding to the following action you wish to take:\n";
	bool loopFlag = true;
	while (loopFlag) {
		int usrChoice;

		cout << "\n1) Enter 1 to add products to the Products.txt file\n"
			<< "2) Enter 2 to add orders to the Orders.txt file\n"
			<< "3) Enter 3 to list all the cities found in the CustomerMaster.txt file\n"
			<< "4) Enter 4 to list all the States found in the CustomerMaster.txt file\n"
			<< "5) Enter 5 to list all customer records for a city of your choosing\n"
			<< "6) Enter 6 to list all customer records for a state of your choosing\n"
			<< "7) Enter 7 to list all orders associated with a customerID of your choosing\n"
			<< "8) Enter 8 to list all orders associated with a zip code of your choosing\n"
			<< "9) Enter 9 to exit\n?";
		cin >> usrChoice;// add check here**************
		cin.clear();
		cin.ignore(100000, '\n');

		string searchCity, searchState;
		string productID, description, orderID, customerID, quantity, searchCustID, searchZip, orderTotal;
		double price;
		if (usrChoice == 1) {
			cout << "Enter the product info starting with the ProductID: ";
			cin >> productID;
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "\nNow the procuct description: ";
			getline(cin, description);
			cout << "\nAnd the price: ";
			cin >> price;
			outProcucts << productID << "%" << description << "%" << price << endl;
		}
		else if (usrChoice == 2) {
			cout << "Enter the order info starting with the OrderID: ";
			cin >> orderID;
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "Now the CustomerID: ";
			cin >> customerID;
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "Now the ProductID: ";
			cin >> productID;
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "Now the quantity: ";
			cin >> quantity;
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "And the OrderTotal: ";
			cin >> orderTotal;
			outOrders << orderID << "%" << customerID << "%" << productID
				<< "%" << quantity << "%" << orderTotal << endl;
		}
		else if (usrChoice == 3) {
			cout << endl << "Here is a list of all the cities in the CustomerMaster.txt file\n";
		}
		else if (usrChoice == 4) {
			cout << endl << "Here is a list of all the states in the CustomerMaster.txt file\n";
		}
		else if (usrChoice == 5) {
			cout << "Enter a city and i'll return all the customer info for customer in that city\n" << endl << "?";
			getline(cin, searchCity);
			cout << "\n\nCustomer List/Information for your chosen City:\n" << endl;
			cout << left << setw(13) << "Customer ID" << setw(15) << "First Name"
				<< setw(15) << "Last Name" << setw(32) << "Street Address"
				<< setw(20) << "City" << setw(13) << "State" << setw(10) << "Zip" << endl;
			cout << "-----------------------------------------------------------------------------------------------------------------\n";
		}
		else if (usrChoice == 6) {
			cout << "Enter a state (two letter uppercase) and i'll return all the customer info for customer in that state(eg. TX)" << endl << "?";
			cin >> searchState;
			cout << "\nCustomer List/Information for your chosen State:" << endl;
			cout << left << setw(13) << "Customer ID" << setw(15) << "First Name"
				<< setw(15) << "Last Name" << setw(32) << "Street Address"
				<< setw(20) << "City" << setw(13) << "State" << setw(10) << "Zip" << endl;
			cout << "-----------------------------------------------------------------------------------------------------------------\n";
		}
		else if (usrChoice == 7) {
			cout << "Enter the CustomerID you wish to find existing orders for: ";
			cin >> searchCustID;
			cout << "\nHere is a list of all customer orders associated with the CustomerID" << searchCustID << endl;
			cout << left << setw(20) << "\nOrder ID" << setw(20) << "Customer ID" << setw(20) << "Product ID"
				<< setw(20) << "Quantity" << setw(20) << "Order Total" << endl;
			cout << "--------------------------------------------------------------------------------------------\n";
		}
		else if (usrChoice == 8) {
			cout << "Enter the Zip Code you wish to find existing orders for: ";
			cin >> searchZip;
			cout << "\nHere is a list of all customer orders associated with the Zip Code" << searchCustID << endl;
			cout << left << setw(20) << "\nOrder ID" << setw(20) << "Customer ID" << setw(20) << "Product ID"
				<< setw(20) << "Quantity" << setw(20) << "Order Total" << endl;
			cout << "--------------------------------------------------------------------------------------------\n";
		}

		// READ THE LINE FIRST, THEN TOKENIZE IT
		string line;// to temp store the lines below

		while (getline(inCustomerMaster, line)) {
			istringstream tokenizer(line);// cache the line

			getline(tokenizer, custId, '%');// get tokens from the cached line
			getline(tokenizer, fName, '%');
			getline(tokenizer, lName, '%');
			getline(tokenizer, stAddress, '%');
			getline(tokenizer, city, '%');
			getline(tokenizer, state, '%');
			getline(tokenizer, zip);// last token gets remainder of cached line

			// FOR USER CHOICE 3
			// THIS WILL POPULATE THE CITYLIST VECTOR WITH ALL UNIQUE CITY NAMES found IN THE MASTER LIST
			if (usrChoice == 3) {
			
				for (int i = 0; i < 1; i++) {
					bool addCity = true;
					for (string c : cityList) {// go through cityList and if c is already there	
						if (city == c) {
							addCity = false;// if the city name is found in the list, dont add to list
						}// end if
					}// end for-each
					if (addCity) {// check if addCity is still true and add to vector if so.
						cityList.push_back(city);// add to vector	
					}// end if
				}// end for loop
			}
			// FOR USER CHOICE 4
			 // THIS WILL POPULATE THE STATELIST VECTOR WITH ALL UNIQUE STATE NAMES found in THE MASTER LIST
			if(usrChoice == 4) {
				for (int i = 0; i < 1; i++) {
					bool addState = true;
					for (string s : stateList) {// go through stateList and if s is already there	
						if (state == s) {
							addState = false;// if the state name is found in the list, dont add to list
						}// end if
					}// end for-each
					if (addState) {// check if addState is still true and add to vector if so.
						stateList.push_back(state);// add to vector	stateList
					}// end if
				}// end for loop
			}
			// USER CHOICE 5
			if (usrChoice == 5) {	// NEEDS TO BE IN THE INNER WHILE LOOP
				if (searchCity == city) {
					cout << left << setw(13) << custId << setw(15) << fName << setw(15) << lName << setw(32)
						<< stAddress << setw(20) << city << setw(13) << state << setw(10) << zip << endl;
				}// end inner if
			}// end else-if (5)

			 // USER CHOICE 6
			else if (usrChoice == 6) { // NEEDS TO BE IN THE INNER WHILE LOOP
				if (searchState == state) {// should use toupper here
					//cout << setw(13) << id << setw(15)
					//	<< fName << setw(15) << lName << setw(32) << address
					//	<< setw(20) << city << setw(13) << st << setw(10) << zip;
					cout << setw(13) << custId << setw(15) << fName << setw(15) << lName << setw(32)
						<< stAddress << setw(20) << city << setw(13) << state << setw(10) << zip << endl;
				}// end inner-if
			}// end else-if (6)

			 // USER CHOICE 7
			else if (usrChoice == 7) {
				string oLine;
				while (getline(inOrders, oLine)) {
					istringstream ordersTokenizer(oLine);
					getline(ordersTokenizer, orderID, '%');
					getline(ordersTokenizer, customerID, '%');
					getline(ordersTokenizer, productID, '%');
					getline(ordersTokenizer, quantity, '%');
					getline(ordersTokenizer, orderTotal);//total needs to be cast to char* when type double

					if (searchCustID == customerID) {
						cout << left << setw(20) << orderID << setw(20) << customerID << setw(20) << productID << setw(20)
							<< quantity << setw(20) << orderTotal << setw(20)<< endl;
					}// end if
				}// end while loop		
			}// end else-if (7)

			 // USER CHOICE 8
			else if (usrChoice == 8) {
				// FOR ANY ZIP CODES IN CUSTOMERMASTER THAT MATCH SEARCHZIP, SAVE CUSTOMERID TO A VECTOR
				if (searchZip == zip) {
					zipOrders.push_back(custId);
				}
			}// end else-if (8)
		}// end while-loop

		if (usrChoice == 1) { cout << "\nProduct data saved\n"; }
		else if (usrChoice == 2) { cout << "\nOrder data saved\n"; }
		else if (usrChoice == 3) {
			//cout << endl;
			for (string c : cityList) {// output the cities found in CustomerMaster.txt file saved to a vector
				cout << "City: " << c << endl;
			}
		}// end else-if (3)
		else if (usrChoice == 4) {
			for (string s : stateList) {// output the cities found in CustomerMaster.txt file saved to a vector
				cout << "State: " << s << endl;
			}
		}// end else-if (4)
		else if (usrChoice == 8) {
			// i have a populated vector that i can use against the tokenized orders.txt file
			string oLine;
			while (getline(inOrders, oLine)) {
				istringstream ordersTokenizer(oLine);
				getline(ordersTokenizer, orderID, '%');
				getline(ordersTokenizer, customerID, '%');
				getline(ordersTokenizer, productID, '%');
				getline(ordersTokenizer, quantity, '%');
				getline(ordersTokenizer, orderTotal);

				for (string id : zipOrders) {
					if (id == customerID) {
						cout << left << setw(20) << orderID << setw(20) << customerID << setw(20) << productID << setw(20)
							<< quantity << setw(20) << orderTotal << setw(20) << endl;
					}// end if 
				}// end for-each
			}// end while
		}// end else-if (8)

		else if (usrChoice == 9) {
			loopFlag = false;
			continue;
		}// end else-if (9)

		 // RESET THE FILEs TO READ FROM START AGAIN
		inCustomerMaster.clear();
		inCustomerMaster.seekg(0);
		inOrders.clear();
		inOrders.seekg(0);
	}// end while loop
	
	//return 0;
}// end main

//*********NOTHING IS BEING USED BELOW THIS LINE************************************
// YOU MAY WANT TO OVERRIDE THIS MULTIPLE TIMES FOR THE DIFFERENT OUTPUT OPTIONS....
void outputLine(const string &id, const string &fName, const string &lName, const string &address,
				const string &city, const string &st, const string &zip) {
	//cout << id;
	cout << setw(13) << id << setw(15)
		<< fName << setw(15) << lName << setw(32) << address
		<< setw(20) << city << setw(13) << st << setw(10) << zip;
}