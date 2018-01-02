#pragma once

#include<iostream>
#include<stdexcept>
#include<exception>
#include<array>
#include "ListNode.h" // ListNode class Definition

template<typename NODETYPE>
class List {
public:
	//DESTRUCTOR
	~List() {
		if (!isEmpty()) {
			std::cout << "Destroying nodes ...\n";

			ListNode<NODETYPE>* currentPtr{ firstPtr };
			ListNode<NODETYPE>* tempPtr{ nullptr };

			while (currentPtr != nullptr) {// delete the remaining nodes
				tempPtr = currentPtr;
				std::cout << tempPtr->data << "\n";
				currentPtr = currentPtr->nextPtr;
				delete tempPtr;
			}// end while
		}//end if
		std::cout << "All nodes destroyed\n\n";
	}// end destructor


	 // insert node at specified 'index'
	void insertAtIndex(const NODETYPE& value) {
		ListNode<NODETYPE>* newPtr{ getNewNode(value) };// new node
		ListNode<NODETYPE>* currentPtr{ firstPtr };// use to iterate through the list

		std::cout << "enter the index where you wish to place the value: ";
		int index;
		int iter = 0;
		std::cin >> index;
		try {
			if (index > this->size()) {
				throw index;// throw exception if index entered is out of range for our list
			}
		}
		catch (const int& errorIndex) {
			cout << "\n*** Exception occured inserting at index [" << errorIndex << "].  Please try again.\n";
			return;
		}// end try/catch block
		if (index == 0) {
			insertAtFront(value);// delegate work to insertAtFront function
			return;
		}
		while (iter < index - 1 && currentPtr->nextPtr != nullptr) {
			currentPtr = currentPtr->nextPtr;
			iter++;
		}
		newPtr->nextPtr = currentPtr->nextPtr;
		currentPtr->nextPtr = newPtr;
	}// end insertAtIndex()

	 // insert node at the front of the list
	void insertAtFront(const NODETYPE& value) {
		ListNode<NODETYPE>* newPtr{ getNewNode(value) }; // new node
		if (isEmpty()) {// list not empty
			firstPtr = lastPtr = newPtr;
		}
		else {
			newPtr->nextPtr = firstPtr;// point new node to old first node
			firstPtr = newPtr;
		}

	}// end insertAtFront()

	 // insert node at back of list
	void insertAtBack(const NODETYPE& value) {
		ListNode<NODETYPE>* newPtr{ getNewNode(value) };// new node
		if (isEmpty()) {
			firstPtr = lastPtr = newPtr;// new list has only one node
		}
		else {
			lastPtr->nextPtr = newPtr;// update previous last node
			lastPtr = newPtr; // new last node
		}
	}// end insertAtBack

	 // remove node by the value it contains/points to
	bool removeByValue(NODETYPE& value) {
		ListNode<NODETYPE>* currentPtr{ firstPtr };// use to iterate through the list
		ListNode<NODETYPE>* skipPtr1{ firstPtr };// a pointer to help remove node by value
		try {
			if (isEmpty()) {
				throw exception{};// throw exception if list is empty
			}
			bool valueIn = false;
			while (currentPtr != nullptr) {// check if the user value exists in the List
				if (currentPtr->data == value) {
					valueIn = true;
					break;
				}
				currentPtr = currentPtr->nextPtr;
			}
			if (!valueIn) throw value;// throw exception if value is not in list			
		}
		catch (const exception& error) {
			cout << "\n*** " << error.what() << ": exception has occured." << "  Please try again.\n";
			return false;
		}
		if (firstPtr->data == value) { return removeFromFront(value); }
		else if (lastPtr->data == value) { return removeFromBack(value); }
		currentPtr = firstPtr;//****
		while (currentPtr->nextPtr != nullptr) {
			if (currentPtr->data == value) {// node found using the value it points to
				if (firstPtr == lastPtr) {
					firstPtr = lastPtr = nullptr;// leave list empty
					return true;// delete successful
				}
				skipPtr1->nextPtr = currentPtr->nextPtr;//set skipPtr to the element after currentPtr..the one we want to skip to
			}
			skipPtr1 = currentPtr;// this will now always be one node behind the currentPtr
			if (currentPtr->nextPtr != nullptr) { currentPtr = currentPtr->nextPtr; }// iterate through the list			
		}// end while			
		return true;
	}// end removeByValue

	 // delete a node from the front of the list
	bool removeFromFront(NODETYPE& value) {
		if (isEmpty()) { return false; }// delete unsuccessful
		else {
			ListNode<NODETYPE>* tempPtr{ firstPtr };// hold item to delete

			if (firstPtr == lastPtr) {
				firstPtr = lastPtr = nullptr; // no nodes remain after removal
			}
			else {
				firstPtr = firstPtr->nextPtr;// point to previous 2nd node
			}

			value = tempPtr->data;// return data being removed
			delete tempPtr;// reclaim previous front node
			return true;// delete successful
		}
	}// end removeFromFront

	 // delete from the back of the list
	bool removeFromBack(NODETYPE& value) {
		if (isEmpty()) { return false; }
		else {
			ListNode<NODETYPE>* tempPtr{ lastPtr };// hold item to delete
			if (firstPtr == lastPtr) {// list has just one element
				firstPtr = lastPtr = nullptr;// no nodes remain after removal
			}
			else {
				ListNode<NODETYPE>* currentPtr{ firstPtr };

				// locate the second to last element in the list..
				while (currentPtr->nextPtr != lastPtr) {
					currentPtr = currentPtr->nextPtr;// move to the next node
				}

				lastPtr = currentPtr;// remove the last node
				currentPtr->nextPtr = nullptr;// this is now the last node in the list
			}
			value = tempPtr->data;// return value from old last node
			delete tempPtr;// reclaim former last node
			return true;// delete successful
		}
	}// end removeFromBack

	 // return size of list as integer
	int size() {
		ListNode<NODETYPE>* currentPtr{ firstPtr };
		int listSize = 0;
		while (currentPtr != nullptr) {
			listSize++;
			currentPtr = currentPtr->nextPtr;
		}
		return listSize;
	}// end size

	 // is list empty?
	bool isEmpty() const {
		return firstPtr == nullptr;
	}// end isEmpty

	 // display contents of list
	void print() const {
		if (isEmpty()) {
			std::cout << "The list is empty\n\n";
			return;
		}
		ListNode<NODETYPE>* currentPtr{ firstPtr };

		std::cout << "\nThe list is: ";
		while (currentPtr != nullptr) {// get element data
			std::cout << currentPtr->data << ' ';
			currentPtr = currentPtr->nextPtr;
		}
		std::cout << "\n\n";
	}// end print()



	 // THIS FUNCTION PRESENTS THE USER WITH AN OPTION SCREEN FOR SEARCH AND SORT OPERATIONS
	 // IT VALIDATES THAT THE USER CHOICE IS IN RANGE OF 1-5 AND RETURNS THAT INT TO THE CALLER.
	void optionsList() {
		cout << "----------------------------------------------------------------------\n";
		cout << " This portion of the program will allow you to choose between four\n"
			<< " searching and sorting options to perform on the Class List Template\n"
			<< " that we just finished processing.\n";
		cout << "----------------------------------------------------------------------\n";
		int userChoice = -1;
		while (true) {
			while (true) {
				print();
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
				int searchInt, searchResult = -1;
				cin >> searchInt;
				cin.clear();
				cin.ignore(1024, '\n');
				searchResult = linearSearch(searchInt);
				if (searchResult == -1) { cout << endl << searchInt << " was not found in the list.\n"; }
				else { cout << endl << searchResult << " was found in the list.\n"; }			
			}
			else if (userChoice == 2) {
				cout << "Sorting with selection sort...\n";
				selectionSort();
			}
			else if (userChoice == 3) {
				cout << "Sorting with mergeSort...\n";
				//ListNode<NODETYPE>* listPtr{ firstPtr };
				//mergeSort(listPtr, 0, this->size() - 1);// pg 859
				array<int, this->size()> newArrayList;
				mergeSort(newArrayList, 0, this->size() - 1);// pg 859
			}
			else if (userChoice == 4) {
				cout << "Enter the integer you wish to search for in the list: ";
				int searchInt, searchResult = -1;
				cin >> searchInt;
				cin.clear();
				cin.ignore(1024, '\n');
				searchResult = binarySearch(searchInt);
				if (searchResult == -1) { cout << endl << searchInt << " was not found in the list.\n"; }
				else { cout << endl << searchResult << " was found in the list.\n"; }
			}
			else break;// return to list operations		
		}
		return;
	}// end optionList()

	int linearSearch (int key) {

		ListNode<NODETYPE>* currentPtr{ firstPtr };
		while (currentPtr != nullptr) {
			if (key == currentPtr->data) {
				return currentPtr->data;
			}
			currentPtr = currentPtr->nextPtr;
		}
		return -1;
	}// end linearSearch()

	void selectionSort() {
		ListNode<NODETYPE>* iterPtr{ firstPtr };// set to first element
		ListNode<NODETYPE>* smallestPtr{ firstPtr };// set to first element
		ListNode<NODETYPE>* currentPtr{ firstPtr->nextPtr };// set to second element
		while (iterPtr->nextPtr != nullptr) {// SHOULD BE TO SIZE-1 NOW
			smallestPtr = iterPtr;
			currentPtr = iterPtr;
			while (currentPtr != nullptr) {
				if (currentPtr->data < smallestPtr->data) {
					smallestPtr = currentPtr;//save current smallest num till another is found
				}
				currentPtr = currentPtr->nextPtr;
			}//end inner while
			swap(smallestPtr->data, iterPtr->data);// swap the smallestPtr data with the iterPtr data
			iterPtr = iterPtr->nextPtr;// move iterPtr to next node
		}// end outer while
	}// END selectionSort

	void mergeSort(array<int, 10> myArray, size_t low, size_t high) {		 // mid ele-end = 1 set; firstptr-mid ele -1

		//ListNode<NODETYPE>* head{ firstPtr };// set to middle element..should round up if size is even
		ListNode<NODETYPE>* listA{ firstPtr };
		ListNode<NODETYPE>* listB{ nullptr };
		ListNode<NODETYPE>* dummy{ firstPtr };
		ListNode<NODETYPE>* dummy2{ firstPtr };

		array<int, 10> newArrayList;
		size_t iter = 0;
		while (head != nullptr) {
			newArrayList[iter] = head->data;
			iter++;
			head = head->nextPtr;
		}
		for (size_t i : newArrayList)
			cout << i << " ";
		if (
			head == nullptr || head->nextPtr == nullptr) return;// base case of <=1 element list
		size_t middle1 = 0, middle2 = 0;
		if ((high - low) >= 1) {
			middle1 = (low + high) / 2;
			middle2 = (middle1 + 1);
			for (size_t i = 0; i < middle1; ++i) {// set dummy to middle element in list(last element of left list)
				listA = listA->nextPtr;
			}
			//listB = listA->nextPtr;// now listB should be starting at the middle element.
			//listA->nextPtr = nullptr;// end listA by setting its next node to nullptr
			//listA = firstPtr;
			//dummy2 = listB;// dummy2 now shows  the starting point for listB

			mergeSort(listA, low, middle1);
			//mergeSort(listB, middle2, high);

			//merge(low, middle1, middle2, high);
			//sortedMerge(listA, listB);
			//************ADDED A PRINT*************
			std::cout << "\nlistA is: ";
			while (listA != nullptr) {// get element data
				std::cout << listA->data << ' ';
				listA = listA->nextPtr;
			}
			std::cout << "\n\n";
			
			std::cout << "\nlistB is: ";
			while (listB != nullptr) {// get element data
				std::cout << listB->data << ' ';
				listB = listB->nextPtr;
			}
			std::cout << "\n\n";

			std::cout << "head is: ";
			while (head != nullptr) {// get element data
				std::cout << head->data << ' ';
				head = head->nextPtr;
			}
			std::cout << "\n\n";
			//*************************************//
			

			//while (dummy->nextPtr != nullptr) {
				//listB->data = dummy->data;// copy 
			//	listB->nextPtr = dummy->nextPtr;
			//	listB = listB->nextPtr;
			//	dummy = dummy->nextPtr;
			//}
			//listB->data = dummy->data;// copy last node to list a
		}
	}


	ListNode<NODETYPE>* sortedMerge(ListNode<NODETYPE>* listA, ListNode<NODETYPE>* listB) {
		ListNode<NODETYPE>* result{ firstPtr };// i think this will write over the starting list

		//************ADDED A PRINT*************
		std::cout << "\nresult at start of sortedMerge is: ";
		while (result != nullptr) {// get element data
			std::cout << result->data << ' ';
			result = result->nextPtr;
		}
		std::cout << "\n\n";
		result = firstPtr;
		/* Base cases */
		if (listA == nullptr)
			return(listB);
		else if (listB == nullptr)
			return(listA);

		if (listA->data <= listB->data) {
			result = listA;
			result->nextPtr = sortedMerge(listA->nextPtr, listB);
		}
		else {
			result = listB;
			result->nextPtr = sortedMerge(listA, listB->nextPtr);
		}
		//************ADDED A PRINT*************
		std::cout << "\nresult in sortedMerge is: ";
		while (result != nullptr) {// get element data
			std::cout << result->data << ' ';
			result = result->nextPtr;
		}
		std::cout << "\n\n";
		return result;
	}// end sortedMerge()


	//void mergeSort(size_t low, size_t high) {		 // mid ele-end = 1 set; firstptr-mid ele -1
	//	ListNode<NODETYPE>* middlePtr1{ firstPtr };// set to middle element..should round up if size is even
	//	ListNode<NODETYPE>* middlePtr2{ firstPtr };
	//	ListNode<NODETYPE> dummyList{ nullptr };
	//	size_t middle1 = 0, middle2 = 0;

	//	cout << "Low: " << low << "\nHigh: " << high << endl;

	//	if ((high - low) >= 1) {
	//		middle1 = (low + high) / 2;
	//		middle2 = (middle1 + 1);
	//		for (size_t i = 0; i < middle1; ++i) {// set middlePtr to middle element in list
	//			middlePtr1 = middlePtr1->nextPtr;
	//		}
	//		if (middlePtr1->nextPtr != nullptr) { 
	//			middlePtr2 = middlePtr1->nextPtr;
	//		}			

	//		cout << "middlePtr1 points to: " << middlePtr1->data << " --Middle1: " << middle1 << endl;
	//		cout << "middlePtr2 points to: " << middlePtr2->data << " --Middle2: " << middle2 << endl;
	//		
	//		mergeSort(low, middle1);
	//		cout << "list in mergeSort: ";
	//		print();
	//		cout << "*************On to mergeSort the second half of the list**********\n";
	//		mergeSort(middle2, high);

	//		merge(low, middle1, middle2, high);

	//	}	// end if
	//}// end mergeSort
				// equal to firstPtr						equal to lastPtr
	void merge( size_t left, size_t middle1, size_t middle2, size_t right ) {
		size_t leftIndex = left;// start of the first section
		ListNode<NODETYPE>* leftIndexPtr{ firstPtr };
		size_t rightIndex = middle2;// the start of the second section
		ListNode<NODETYPE>* rightIndexPtr{ firstPtr };
		size_t combinedIndex = left;// index to temporary working array
		ListNode<NODETYPE>* newListPtr{ firstPtr };// holding the new ordered data

		for ( size_t i = 0; i < middle2; ++i ) {// set rightIndexPtr to first node of second list
			rightIndexPtr = rightIndexPtr->nextPtr;
		}
		int iter = 0;
		while ( leftIndex <= middle1 && rightIndex <= right ) {
			if (leftIndexPtr->data <= rightIndexPtr->data) {
				newListPtr->data = leftIndexPtr->data;
				this->print();
				leftIndexPtr = leftIndexPtr->nextPtr;//go to next node on left list
				newListPtr = newListPtr->nextPtr;
				leftIndex++;
			}
			else {
				newListPtr->data = rightIndexPtr->data;
				this->print();
				rightIndexPtr = rightIndexPtr->nextPtr;//go to next node on right list
				newListPtr = newListPtr->nextPtr;
				rightIndex++;
			}
		}// end while
		
		cout << "middle2: " << middle2 << endl;
		cout << "rightIndex: " << rightIndex << endl;		
		if (leftIndex == middle2) {// if at the end of the left list..
			cout << "reached end of left list\n";
			while (rightIndex <= right) {
				newListPtr->data = rightIndexPtr->data;// ..copy the rest of the right list over
				newListPtr = newListPtr->nextPtr;
				rightIndexPtr = rightIndexPtr->nextPtr;
				iter++;
				cout << "iteration over right list: #" << iter << endl;				
				rightIndex++;
			}
		}
		else {			
			cout << "reached end of right list\n";
			cout << "leftIndex: " << leftIndex << endl;
			cout << "middle1: " << middle1 << endl;
			while (leftIndex <= middle1) {// if at the end of the right list..
				newListPtr->data = leftIndexPtr->data;// ..copy the rest of the left list over
				newListPtr = newListPtr->nextPtr;// move to next node 
				leftIndexPtr = leftIndexPtr->nextPtr;// move to next node
				iter++;
				cout << "iteration over left list: #" << iter << endl;				
				leftIndex++;
			}
		}
	}// end merge()

	int binarySearch(int key) {
		selectionSort();
		ListNode<NODETYPE>* middlePtr{ firstPtr };
		ListNode<NODETYPE>* searchBeginPtr{ firstPtr };
		ListNode<NODETYPE>* searchEndPtr{ lastPtr };
		int location = -1;
		for (int i = 0; i < this->size() / 2; ++i) {// set middlePtr to middle element in list
			middlePtr = middlePtr->nextPtr;
		}
		int midpoint = this->size() / 2;
		do {
			if (key == middlePtr->data) {
				location = middlePtr->data;
			}
			else if (key <= middlePtr->data) {// toss the back half of the list
				middlePtr = firstPtr;
				midpoint = midpoint / 2;
				for (int i = 0; i < midpoint - 1; i++) {// set the new middlePtr node
					if (middlePtr->nextPtr != nullptr) {
						middlePtr = middlePtr->nextPtr;
					}					
				}
			}
			else if (key >= middlePtr->data) {// toss the first half of the list
				midpoint = midpoint / 2;
				for (int i = 0; i < midpoint + 1; i++) {// set the new middlePtr node
					if (middlePtr->nextPtr != nullptr) {
						middlePtr = middlePtr->nextPtr;
					}
				}
			}
			searchBeginPtr = searchBeginPtr->nextPtr;
		} while (searchBeginPtr != searchEndPtr && location == -1);
		return location;
	}

private:
	ListNode<NODETYPE>* firstPtr{ nullptr };// a pointer to the first node
	ListNode<NODETYPE>* lastPtr{ nullptr };// a pointer to the last node

										   // a utility function to allocate new node
	ListNode<NODETYPE>* getNewNode(const NODETYPE& value) {
		return new ListNode<NODETYPE>{ value };
	}
};