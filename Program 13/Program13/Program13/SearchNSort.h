#pragma once

#include<iostream>
#include<string>
#include "ListNode.h" // ListNode class Definition
using namespace std;

template<typename T>
class SearchNSort {
public:

	// THIS FUNCTION PRESENTS THE USER WITH AN OPTION SCREEN FOR SEARCH AND SORT OPERATIONS
	// IT VALIDATES THAT THE USER CHOICE IS IN RANGE OF 1-5 AND RETURNS THAT INT TO THE CALLER.
	void optionsList(List<T>& listObject){
		cout << "----------------------------------------------------------------------\n";
		cout << " This portion of the program will allow you to choose between four\n"
			<< " searching and sorting options to perform on the Class List Template\n"
			<< " that we just finished processing.\n";
		cout << "----------------------------------------------------------------------\n";
		int userChoice = -1;
		while (true) {			
			while (true) {
				cout << "\nPlease choose one of the following search and sort options to perform on our list:\n"
					<< " 1.) Linear Search\n 2.) Selection Sort\n 3.) Merge Sort\n"
					<< " 4.) Binary Search\n 5.) Return to List Operations\n";
				cout << "Please make your choice now: ";

				cin >> userChoice;
				cout << endl << endl;
				cin.clear();
				cin.ignore(1024, '\n');
				if (userChoice > 5 || userChoice < 1) {
					cout << "\n Invalid entry.  Please try again.\n";
				}
				else break;
			}// end while

			if (userChoice == 1) {
				cout << "Enter the integer you wish to search for in the list: ";
				int searchInt, searchResult;
				T sInt;
				searchResult = linearSearch(listObject, searchInt);
				//searchResult = linearSearch();
				cout << "searchResult is: " << searchResult << endl;
			}
			else if (userChoice == 2) {
				selectionSort();
			}
			else if (userChoice == 3) {
				mergeSort();
			}
			else if (userChoice == 4) {
				binarySearch();
			}
			else break;// return to list operations		
		}
		return;
	}// end optionList()

	//template<typename NODETYPE>
	//template<typename T, size_t size>
	//int linearSearch() {
	int linearSearch(List<T>& listObject, const T& key) { 
		cout << "in linearSearch\n";
		//for (size_t i{ 0 }; i < listObject.size(); i++) {
		//	if (key == listObject[i]) {
		//		return i;
		//	}
		//}
		ListNode<NODETYPE>* currentPtr{ firstPtr };
		while (currentPtr != nullptr) {
			if (key == currentPtr->data) {
				return currentPtr;
			}
		}
	return -1;
	}// end linearSearch()
	void selectionSort() { cout << "in selectionSort\n"; }
	void mergeSort() { cout << "in mergeSort\n"; }
	void binarySearch() { cout << "in binarySearch\n"; }

private:


};
