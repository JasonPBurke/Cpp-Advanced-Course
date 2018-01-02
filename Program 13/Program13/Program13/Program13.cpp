// Program13.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<iostream>
#include<string>
#include<stdexcept>
#include<random>
#include<ctime>
#include "List.h"
#include "SearchNSort.h"
using namespace std;


// USER MENU
void instructions() {
	cout << "Enter one of the following (options 7 and 8 are new):\n"
		<< " 1.) Insert at beginning of the list\n"
		<< " 2.) Insert at end of the list\n"
		<< " 3.) Delete from beginning of the list\n"
		<< " 4.) Delete from end of the list\n"
		<< " 5.) Insert at a location(index value) in the list\n"
		<< " 6.) Delete a node from the list based on its value\n"
		<< " 7.) Perform search and sort operations on the list\n"
		<< " 8.) Auto-fill the list with ten random integers\n"
		<< " 9.) End list processing\n";
}

// FUNCTION TO TEST A LIST
template<typename T>
void testList(List<T>& listObject, const string& typeName) {

	int choice;
	T value; // to store input value

	do {
		listObject.print();
		instructions(); // display menu
		try {
			cout << "? ";
			cin >> choice;
			cin.clear();
			cin.ignore(1024, '\n');
			if (choice < 1 || choice > 9) throw exception{};
		}
		catch (exception& error) {
			cout << "\n*** " << error.what() << ": exception occured." << "  Please try again.\n\n";
			choice = 0;
			continue;
		}
		int returnInt = -1;
		switch (choice) {
		case 1: // insert at beginning
			cout << "Enter " << typeName << ": ";
			cin >> value;
			listObject.insertAtFront(value);
			break;
		case 2:// insert at end
			cout << "Enter " << typeName << ": ";
			cin >> value;
			listObject.insertAtBack(value);
			break;
		case 3:// delete from beginning
			if (listObject.removeFromFront(value)) {
				cout << value << " removed from list\n";
			}
			break;
		case 4:// delete from end
			if (listObject.removeFromBack(value)) {
				cout << value << " removed from list\n";
			}
			break;
		case 5:// insert at an index value in the list
			cout << "Enter " << typeName << ": ";
			cin >> value;
			listObject.insertAtIndex(value);
			break;
		case 6:// remove a node based on value
			cout << "Enter the value to be removed: ";
			cin >> value;
			if (listObject.removeByValue(value)) {
				cout << value << " removed from list\n";
			}
			break;
		case 7:// let user do search/sort operations on list
			//selectionSort2(listObject);
			listObject.optionsList();
			break;
		case 8:// TO AUTO-GENERATE A RANDOM LIST OF INTEGERS FOR TESTING EASE
			default_random_engine engine{ static_cast<unsigned int>(time(nullptr)) };
			uniform_int_distribution<unsigned int> randInt{ 10,99 };
			for (size_t x = 0; x < 10; ++x) {
				listObject.insertAtFront(randInt(engine));// fill the list with 10 random ints
			}
		}// end switch
	} while (choice < 9);// end do-while	
}// end test list function


int main()
{
	cout << "----------------------------------------------------------------------\n";
	cout << " This program desmostrates custom templatized data structures.\n"
		<< " For this demonstration we will be using integers as the data type.\n"
		<< " You will also have the option to use search and sort operations on\n"
		<< " the List created with the Class List Template\n";
	cout << "----------------------------------------------------------------------\n\n";
	List<int> integerList;
	testList(integerList, "integer");

	return 0;
}// end main

