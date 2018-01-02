#pragma once

#include<iostream>
#include<stdexcept>
#include<exception>
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
		catch (const int notFound) {
			cout << "\n*** Exception has occured.  The integer given is not in the list." << "  Please try again.\n";
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
				skipPtr1->nextPtr = currentPtr->nextPtr;//set skipPtr to the element after currentPtr..the one we want to skip
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

private:
	ListNode<NODETYPE>* firstPtr{ nullptr };// a pointer to the first node
	ListNode<NODETYPE>* lastPtr{ nullptr };// a pointer to the last node

										   // a utility function to allocate new node
	ListNode<NODETYPE>* getNewNode(const NODETYPE& value) {
		return new ListNode<NODETYPE>{ value };
	}
};