// Program12.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<iostream>
#include<string>
#include<stdexcept>
#include "List.h"
using namespace std;


// USER MENU
void instructions() {
	cout << "Enter one of the following:\n"
		<< " 1) Insert at beginning of the list\n"
		<< " 2) Insert at end of the list\n"
		<< " 3) Delete from beginning of the list\n"
		<< " 4) Delete from end of the list\n"
		<< " 5) Insert at a location(index value) in the list\n"
		<< " 6) Delete a node from the list based on its value\n"
		<< " 7) End list processing\n";
}

// FUNCTION TO TEST A LIST
template<typename T>
void testList(List<T>& listObject, const string& typeName) {
	cout << "Testing a List of " << typeName << " values\n";
	//instructions(); // display menu

	int choice;
	T value; // to store input value

	do {
		instructions(); // display menu
		try {
			cout << "? ";
			cin >> choice;
			cin.clear();
			cin.ignore(1024, '\n');
			if (choice < 1 || choice > 7) throw exception{};
		}
		catch (exception& error) {
			cout << "\n*** " << error.what() << ": exception occured." << "  Please try again.\n\n";
			choice = 0;
			continue;
		}

		switch (choice) {
		case 1: // insert at beginning
			cout << "Enter " << typeName << ": ";
			cin >> value;
			listObject.insertAtFront(value);
			listObject.print();
			break;
		case 2:// insert at end
			cout << "Enter " << typeName << ": ";
			cin >> value;
			listObject.insertAtBack(value);
			listObject.print();
			break;
		case 3:// delete from beginning
			if (listObject.removeFromFront(value)) {
				cout << value << " removed from list\n";
			}
			listObject.print();
			break;
		case 4:// delete from end
			if (listObject.removeFromBack(value)) {
				cout << value << " removed from list\n";
			}
			listObject.print();
			break;
		case 5:// insert at an index value in the list
			cout << "Enter " << typeName << ": ";
			cin >> value;
			listObject.insertAtIndex(value);
			listObject.print();
			break;
		case 6:// remove a node based on value
			cout << "Enter the value to be removed: ";
			cin >> value;
			if (listObject.removeByValue(value)) {
				cout << value << " removed from list\n";
			}
			listObject.print();
			break;
		}// end switch
	} while (choice < 7);// end do-while
}// end test list function


int main()
{
	cout << "This program desmostrates custom templatized data structures.\n"
		<< "For this demonstration we will be using integers as the data type.\n\n";
	List<int> integerList;
	testList(integerList, "integer");

	//List<double> doubleList;
	//testList(doubleList, "double");
	return 0;
}

