// Program08.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include<iostream>
#include<string>
#include<sstream>
#include<array>	
#include<vector>
#include<deque>
#include<list>
#include<forward_list>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<stack>
#include<queue>

using namespace std;

int pickSCType();
void populateArray();
void processArray(array<char, 20>);
void processVector(vector<char>);
void processDeque(deque<char>);
void processList(list<char>);
void processForwardList(forward_list<char>);
int pickOACType();
int pickUACType();
void processMultiset(multiset<int>);
void processSet(set<int>);
void processMap(map<int, double>);
void processMultimap(multimap<int, double>);

void processUMultiset(unordered_multiset<int>);
void processUSet(unordered_set<int>);
void processUMap(unordered_map<int, double>);
void processUMultimap(unordered_multimap<int, double>);
int pickContainerAdapterType();
void processStack(stack<int, vector<int>>);
void printStack(stack<int, vector<int>>);
void printQueue(queue<int>);
void printPriorityQueue(priority_queue<int>);
void processQueue(queue<int>);
void processPriorityQueue(priority_queue<int>);


// USED TO POPULATE LIST, VECTOR, AND DEQUE
template<typename T> T populateSC(T& tContainer) {// can add &
	cout << "\n Please enter the character data you wish to place in the container.  Press enter when done.\n ?";
	string tempString;
	getline(cin, tempString);

	tContainer.assign(tempString.cbegin(), tempString.cend());
	return tContainer; // return the populated container
}// end processSC

// POPULATE SET, MULTISET 
template<typename T> T populateOAC(T& tContainer) { // &
	cout << "\n Please enter the integer data you wish to place in the Associative Container: \n ?";
	string tempString;
	getline(cin, tempString);
	istringstream is(tempString);
	vector<int> v;
	int x;
	while (is >> x) v.push_back(x);
	tContainer.insert(v.begin(), v.end());
	return tContainer;
}

// POPULATE MAP, MULTIMAP
template<typename T> T populateOAMaps(T& tContainer) {
	while (true) {
		cout << "\n Enter an integer for the key value and a double for the value, seperated by a space: ";
		int key;
		double value;
		cin >> key >> value;
		tContainer.insert(make_pair(key, value));
		cout << "\n Enter another pair?(Y/N): ";
		char cont;
		cin >> cont;
		if (toupper(cont) == 'Y') continue;
		else if (toupper(cont) == 'N') break;
	}// end while(true)
	return tContainer;
}

// POPULATE CONTAINER ADAPTERS
template<typename T> T populateContainerAdapters(T& tContainer) {
	/*cout << "\n Enter the integer data you wish to use to populate the chosen container adapter: ";
	string tempString;
	getline(cin, tempString);
	for (auto i : tempString) {
		tContainer.push(i);
	}*/
	while (true) {
		cout << "Enter an integer to add to the container adapter: ";
		int newInt;
		cin >> newInt;
		cin.clear();
		cin.ignore(1024, '\n');
		tContainer.push(newInt);
		cout << "Enter another integer? (Y/N): ";
		char keepGoing;
		cin >> keepGoing;
		cin.clear();
		cin.ignore(1024, '\n');
		if (toupper(keepGoing) == 'Y') { continue; }
		else if (toupper(keepGoing) == 'N') { break; }
	}
	return tContainer;
}

int main()
{
	cout << "This program has you pick one of the first-class containers, and \n"
		"then lets you pick the iterator type for that container that you wish to use.\n"
		"You can then populate the container and manipulate the data stored therein.\n\n";

	int ContainerChoice;
	// I MAY NOT NEED THIS WHILE LOOP AT ALL
	while(true){
		// while loop so that i can verify the user enter is 1-4 and then continue
		while (true) {
			cout << "\n You can use one of the four container categories listed below:\n"
				" 1. Sequence Containers(using chars)\n"
				" 2. Ordered Associative Containers(using ints/doubles)\n"
				" 3. Unordered Associative Containers(using doubles)\n"
				" 4. Container Adapters\n";
			cout << " Please choose your container category now (enter number 1-4, 0 to exit): ";			
			cin >> ContainerChoice;
			cin.clear();
			cin.ignore(1024, '\n');
			if ( ContainerChoice < 0 || ContainerChoice > 4 ) {
				cout << "\nEntery must be a number between 1-4 inclusive.  Please try again.\n\n";
			}// end if
			else break;
		}// end while(true)

		if (ContainerChoice == 0) break;
		if (ContainerChoice == 1) {// if sequence containers
			int iteratorChoice = pickSCType();// this presents a list of iterators and returns an int 1-5
			if (iteratorChoice == 1) { // if user picks array
				populateArray();// this will call processArray() to let user manipulate array data
			}// end if choice 1
			else if (iteratorChoice == 2) {  // deque
				deque<char> intDeque;
				populateSC(intDeque);
				//intDeque = populateSC(intDeque);
				processDeque(intDeque);
			}// end choice 2
			else if ( iteratorChoice == 3 ) { // forward-list
				forward_list<char> charFList;
				populateSC(charFList);
				//charFList = populateSC(charFList);
				processForwardList(charFList);
			}
			else if ( iteratorChoice == 4 ) { // list
				list<char> charList;
				populateSC(charList);
				//charList = populateSC(charList);
				processList(charList);
			}
			else if ( iteratorChoice == 5 ) {  // vector		
				vector<char> charVector;// create a vector to populate
				charVector = populateSC(charVector);// this adds the data to the vector from user input
				processVector(charVector);// call function to allow user to manipulate vector data
			}// end choice 5
		}// end if sequence containers
		else if (ContainerChoice == 2) {// if ordered associative containers
			int iteratorChoice = pickOACType();
			if (iteratorChoice == 1) {// set
				set<int> intSet;
				intSet = populateOAC(intSet);
				//ostream_iterator<int> output{ cout," " };
				//copy(intSet.begin(), intSet.end(), output);
				processSet(intSet);
			}// end if set
			else if (iteratorChoice == 2) {// multiset
				multiset<int> intMultiset;
				intMultiset = populateOAC(intMultiset);
				processMultiset(intMultiset);
			}// end if multiset
			else if (iteratorChoice == 3) {// map
				map<int, double> intDoubleMap;
				populateOAMaps(intDoubleMap);
				processMap(intDoubleMap);
			}// end if map
			else if (iteratorChoice == 4) {// multimap
				multimap<int, double> intDoubleMultimap;
				populateOAMaps(intDoubleMultimap);
				processMultimap(intDoubleMultimap);
			}// end if multimap
		}// end if ordered associative containers
		else if (ContainerChoice == 3) {
			int iteratorChoice = pickUACType();
			if(iteratorChoice == 1){// unordered set
				unordered_set<int> intUSet;
				populateOAC(intUSet);
				processUSet(intUSet);
			}// end unordered set
			else if(iteratorChoice == 2){// unordered multiset
				unordered_multiset<int> intUMultiset;
				intUMultiset = populateOAC(intUMultiset);
				processUMultiset(intUMultiset);
			}
			else if(iteratorChoice == 3){// unordered map
				unordered_map<int, double> intDoubleUMap;
				populateOAMaps(intDoubleUMap);
				processUMap(intDoubleUMap);
			}
			else if(iteratorChoice == 4){// unordered multimap
				unordered_multimap<int, double> intDoubleUMultimap;
				populateOAMaps(intDoubleUMultimap);
				processUMultimap(intDoubleUMultimap);
			}
		}// end if unordered associative containers
		else if (ContainerChoice == 4) {// if container adapters
			int iteratorChoice = pickContainerAdapterType();
			if(iteratorChoice == 1){// stack
				stack<int, vector<int>> intVectorStack;
				populateContainerAdapters(intVectorStack);
				processStack(intVectorStack);
			}// end if stack
			else if(iteratorChoice == 2){// queue
				queue<int> intVectorQueue;
				populateContainerAdapters(intVectorQueue);;
				processQueue(intVectorQueue);
			}// end if queue
			else if(iteratorChoice == 3){// priority_queue
				priority_queue<int> intVectorPriorityQueue;
				populateContainerAdapters(intVectorPriorityQueue);
				//printPriorityQueue(intVectorPriorityQueue);
				processPriorityQueue(intVectorPriorityQueue);
			}// end if priority_queue
		}// end container adapters
	}// end while(outerLoop)

	system("pause");
    return 0;
}// end main



int pickSCType() { // RETURNS AN INT 1-5
	int iteratorChoice;
	while(true){
		cout << "\n Please pick the type of Sequence Container you wish to use: \n"
			" 1. array\n"
			" 2. deque\n"
			" 3. forward_list\n"
			" 4. list\n"
			" 5. vector\n";
		cout << " Enter 1-5 to choose an container type to use: ";
		cin >> iteratorChoice;
		cin.clear();
		cin.ignore(1024, '\n');
		if (!iteratorChoice || iteratorChoice > 5 || iteratorChoice < 1) {
			cout << "\nEntery must be a number between 1-5 inclusive.  Please try again.\n\n";
		}// end if
		else break;
	}// end while
	return iteratorChoice;
}// end pickSCIterType()


// USED TO POPULATE ARRAY USING A FOR LOOP AND SUBSCRIPTS
void populateArray() {
	ostream_iterator<char> output{ cout, "" };// ADD A SPACE IF YOU CHANGE DATA TYPES
	array<char, 20> charArray;// create an array to hold user data
	cout << "\n Please enter a string of 20 characters: ";
	string choice;
	getline(cin, choice);
	for ( size_t i = 0; i < size(choice); i++ ) {
		charArray[i] = choice[i];// iterate through and populate the charArray.. this does store the spaces entered
	}// end for loop
	processArray(charArray);
}// end populate array


// THIS METHOD WILL GET INPUT FROM THE USER AND PLACE IT IN AN ARRAY.
// IT WILL THEN ALLOW THE USER TO MANIPULATE THE ARRAY DATA IN AT LEAST 2 WAYS
void processArray(array<char, 20> charArray) {
	ostream_iterator<char> output{ cout, "" };// ADD A SPACE IF YOU CHANGE DATA TYPES
	int choice;
	char cont;
	bool loop = true;
	while (loop) {
		while (true) {
			cout << "\n Please choose from the options below:\n"
				" 1. Print out the contents of the array\n"
				" 2. Swap the array data for another set of array data\n"
				" 3. Fill the array with a single character\n";
			cout << " Enter your choice now (1-3) : ";
			cin >> choice;
			cin.clear();
			cin.ignore(1024, '\n');
			if (!choice || choice > 3 || choice < 1) { cout << "\nInvalid entry. Please try again.\n\n"; }
			else break;
		}// end while loop
		if (choice == 1) {
			cout << "\nHere is the data in the array: ";
			for (auto const &item : charArray) { cout << item; }
			cout << endl;
		}// end if choice 1
		else if (choice == 2) {
			cout << "\n Please enter a string of 20 characters to swap into the array: ";
			array<char, 20> charArray2;
			string choice;
			getline(cin, choice);
			for (size_t i = 0; i < size(choice); i++) { charArray2[i] = choice[i]; }// end for loop
			charArray.swap(charArray2);
			cout << "Here is the array after swapping data: ";
			copy(charArray.cbegin(), charArray.cend(), output);// copy and display the list data
		}// end if choice 2
		else if (choice == 3) {
			cout << "Enter the character you would like to fill the array with: ";
			char fillChar;
			cin >> fillChar;
			charArray.fill(fillChar);
			cout << "Here is the array after fill was used: ";
			copy(charArray.cbegin(), charArray.cend(), output);// copy and display the list data
		}// end if choice 3
		cout << "\n\n Press Y to manipulate this array data again (any other key to exit arrays): ";
		cin >> cont;
		cin.clear();
		cin.ignore(1024, '\n');
		if (toupper(cont) == 'Y') continue;
		else loop = false;
	}// end while 
}// end processArray()

// USED TO PROCESS A LIST WITH UNIQUE OPTIONS TO THE OTHER CONTAINER TYPES
void processList(list<char> charList) { 
	ostream_iterator<char> output{ cout, "" };// ADD A SPACE IF YOU CHANGE DATA TYPES
	int choice;
	char cont;
	bool loop = true;
	while (loop) {
		while (true) {
			cout << "\n Please choose from the options below:\n"
				" 1. Print out the contents of the list\n"
				" 2. Sort the list\n"
				" 3. Force the list to remove all duplate items, leaving only unique data(note: must be sorted first)\n";
			cout << " Enter your choice now (1-3) : ";
			cin >> choice;
			cin.clear();
			cin.ignore(1024, '\n');
			if (!choice || choice > 3 || choice < 1) { cout << "\nInvalid entry. Please try again.\n\n"; }
			else break;
		}// end while loop
		if (choice == 1) {
			cout << "\nHere is the data in the list: ";
			for (auto const &item : charList) { cout << item; }
			cout << endl;
		}// end if choice 1
		else if (choice == 2) {
			cout << "Here is the list after sorting: ";
			charList.sort();// sort the list
			copy(charList.cbegin(), charList.cend(), output);// copy and display the list data
		}// end if choice 2
		else if (choice == 3) {
			cout << "Show only the unique values in the list: ";
			charList.unique();
			copy(charList.cbegin(), charList.cend(), output);// copy and display the list data
		}// end if choice 3
		cout << "\n\n Press Y to manipulate this list data again (any other key to exit lists): ";
		cin >> cont;
		cin.clear();
		cin.ignore(1024, '\n');
		if (toupper(cont) == 'Y') continue;
		else loop = false;
	}// end while 
}// end processList()

// USED TO PROCESS FORWARD_LISTS USING UNIQUE OPTIONS FROM OTHER CONTAINER TYPES
void processForwardList(forward_list<char> fList) { 
	ostream_iterator<char> output{ cout, "" };
	int choice;
	char cont;
	bool loop = true;
	while(loop) {
		while(true) {
			cout << "\n Please choose from the options below:\n"
				" 1. Print out the contents of the forward_list\n"
				" 2. Remove all occurances of any element in the forward_list\n"
				" 3. Add an item to the beginning of the forward_list\n";
			cout << " Enter your choice now (1-3) : ";
			cin >> choice;
			cin.clear();
			cin.ignore(1024, '\n');
			if (!choice || choice > 3 || choice < 1) {
				cout << "\nInvalid entry. Please try again.\n\n";
			} else break;
		}// end while(true)
		if (choice == 1) {
			cout << "\nHere is the data in the deque: ";
			for (auto const &item : fList) { cout << item; }
			cout << endl;
		}// end if choice 1
		else if (choice == 2) {
			cout << "Please enter the character you wish to remove from the forward_list: ";
			char removeChar;
			cin >> removeChar;
			fList.remove(removeChar);
			cout << "Here is the forward_list after removing all occurances of your selected value: ";
			copy(fList.cbegin(), fList.cend(), output);// copy and display the deque data
		}// end if choice 2
		else if (choice == 3) {
			cout << "Please enter a character to add to the beginning of the deque: ";
			char tempChar;
			cin >> tempChar;
			fList.push_front(tempChar);
			cout << "Here is the deque after adding a new top item: ";
			copy(fList.cbegin(), fList.cend(), output);// copy and display the deque data
		}// end if choice 3
		cout << "\n\n Press Y to manipulate this forward_list data again (any other key to exit forward_list): ";
		cin >> cont;
		cin.clear();
		cin.ignore(1024, '\n');
		if (toupper(cont) == 'Y') continue;
		else loop = false;
	}// end while(loop)
}// end processForwardList()

// USED TO PROCESS DEQUE WITH UNIQUE OPTIONS FROM THE OTHER CONTAINER TYPES
void processDeque(deque<char> charDeque) {
	ostream_iterator<char> output{ cout, "" };// ADD A SPACE IF YOU CHANGE DATA TYPES
	int choice;
	char cont;
	bool loop = true;
	while (loop) {
		while (true) {
			cout << "\n Please choose from the options below:\n"
				" 1. Print out the contents of the deque\n"
				" 2. Remove the beginning item from the deque\n"
				" 3. Add an item to the end of the deque\n";
			cout << " Enter your choice now (1-3) : ";
			cin >> choice;
			cin.clear();
			cin.ignore(1024, '\n');
			if (!choice || choice > 3 || choice < 1) {
				cout << "\nInvalid entry. Please try again.\n\n";
			}
			else break;
		}// end while loop
		if (choice == 1) {
			cout << "\nHere is the data in the deque: ";
			for (auto const &item : charDeque) { cout << item; }
			cout << endl;
		}// end if choice 1
		else if (choice == 2) {
			cout << "Here is the deque after removing the top item: ";
			charDeque.pop_front();// remove the first element
			copy(charDeque.cbegin(), charDeque.cend(), output);// copy and display the deque data
		}// end if choice 2
		else if (choice == 3) {
			cout << "Please enter a character to add to the end of the deque: ";
			char tempChar;
			cin >> tempChar;
			charDeque.push_back(tempChar);
			cout << "Here is the deque after adding a new item to the end: ";
			copy(charDeque.cbegin(), charDeque.cend(), output);// copy and display the deque data
		}// end if choice 3
		cout << "\n\n Press Y to manipulate this deque data again (any other key to exit deque): ";
		cin >> cont;
		cin.clear();
		cin.ignore(1024, '\n');
		if (toupper(cont) == 'Y') continue;
		else loop = false;
	}// end while 
}// end processDeque()

// USED TO PROCESS VECTORS WITH UNIQUE OPTIONS FROM THE OTHER CONTAINER TYPES
void processVector(vector<char> stringVector) {
	int choice;
	char cont;
	bool loop = true;
	while(loop){
		while (true) {
			cout << "\n Please choose from the options below:\n"
				" 1. Print out the contents of the vector\n"
				" 2. Print out the contents of the vector in reverse order\n"
				" 3. Clear the contents of the vector\n";// there are better ones to choose from
			cout << " Enter your choice now (1-3) : ";
			cin >> choice;
			cin.clear();
			cin.ignore(1024, '\n');
			if (!choice || choice > 3 || choice < 1) {
				cout << "\nInvalid entry. Please try again.\n\n";
			}
			else break;
		}// end while loop
		if (choice == 1) {
			cout << "\nHere is the data in the vector: ";
			for (auto const &item : stringVector) { cout << item; }
			cout << endl;
		}// end if choice 1
		else if (choice == 2) {
			cout << "Here is the reversed data in the vector: ";
			for (auto reverseIter = stringVector.crbegin(); reverseIter != stringVector.crend(); ++reverseIter) {
				cout << *reverseIter;
			}
		}// end if choice 2
		else if (choice == 3) {
			cout << "After clearing the vector, here are the contents of the vector(hint: it's empty): ";
			stringVector.clear();
			for (auto const &item : stringVector) { cout << item; }
			cout << "\n(This prints on a new line after the vector contents are printed)\n";
		}// end if choice 3
		cout << "\n\n Press Y to manipulate this vector data again (any other key to exit vectors): ";
		cin >> cont;
		cin.clear();
		cin.ignore(1024, '\n');
		if (toupper(cont) == 'Y') continue;
		else loop = false;
	}// end while 
}// end processVector

//***THESE SHOULD EACH HAVE THEIR OWN CLASS WITH POPULATION AND MANIPULATION METHODS FOR THEIR CONTAINER TYPE*******

int pickOACType() {// ORDERED ASSOCIATIVE CONTAINERS ITERATOR PICKER
	int iteratorChoice;
	while (true) {
		cout << "\n Please pick the type of Ordered Associatave Container you wish to use: \n"
			" 1. set\n"
			" 2. multiset\n"
			" 3. map\n"
			" 4. multimap\n";
		cout << " Enter 1-4 to choose an container type to use: ";
		cin >> iteratorChoice;
		cin.clear();
		cin.ignore(1024, '\n');
		if (!iteratorChoice || iteratorChoice > 4 || iteratorChoice < 1) {
			cout << "\nEntery must be a number between 1-4 inclusive.  Please try again.\n\n";
		}// end if
		else break;
	}// end while
	return iteratorChoice;
}

int pickUACType() {// UNORDERED ASSOCIATIVE CONTAINERS ITERATOR PICKER
	int iteratorChoice;
	while (true) {
		cout << "\n Please pick the type of Unordered Associative Container you wish to use: \n"
			" 1. unordered set\n"
			" 2. unordered multiset\n"
			" 3. unordered map\n"
			" 4. unordered multimap\n";
		cout << " Enter 1-4 to choose an container type to use: ";
		cin >> iteratorChoice;
		cin.clear();
		cin.ignore(1024, '\n');
		if (!iteratorChoice || iteratorChoice > 4 || iteratorChoice < 1) {
			cout << "\nEntery must be a number between 1-4 inclusive.  Please try again.\n\n";
		}// end if
		else break;
	}// end while
	return iteratorChoice;
}

int pickContainerAdapterType() {
	int iteratorChoice;
	while (true) {
		cout << "\n Please pick the type of Container Adapter you wish to use: \n"
			" 1. stack\n"
			" 2. queue\n"
			" 3. priorty_queue\n";
		cout << " Enter 1-3 to choose an container type to use: ";
		cin >> iteratorChoice;
		cin.clear();
		cin.ignore(1024, '\n');
		if (!iteratorChoice || iteratorChoice > 4 || iteratorChoice < 1) {
			cout << "\nEntry must be a number between 1-3 inclusive.  Please try again.\n\n";
		}// end if
		else break;
	}// end while
	return iteratorChoice;
}

void processSet(set<int> inSet) {
	int choice;
	char cont;
	bool loop = true;
	while (loop) {
		while (true) {
			cout << "\n Please choose from the options below:\n"
				" 1. Print out the contents of the set\n"
				" 2. Insert a new integer in the set\n"
				" 3. Erase an element from the set\n";// there are better ones to choose from
			cout << " Enter your choice now (1-3) : ";
			cin >> choice;
			cin.clear();
			cin.ignore(1024, '\n');
			if (!choice || choice > 3 || choice < 1) {
				cout << "\nInvalid entry. Please try again.\n\n";
			}
			else break;
		}// end while loop
		if (choice == 1) {
			cout << "\nHere is the data in the set: ";
			for (auto const &item : inSet) { cout << item << " "; }
			cout << endl;
		}// end if choice 1
		else if (choice == 2) {
			cout << "Enter the integer you want to add to the set(cannot be a duplicate): ";
			int addInt;
			cin >> addInt;
			inSet.insert(addInt);
			cout << "Here is the set after inserting: ";
			for (auto const &item : inSet) { cout << item << " "; }
		}// end if choice 2
		else if (choice == 3) {
			cout << "Enter the integer you want to erase from the set: ";
			int removeInt;
			cin >> removeInt;
			inSet.erase(removeInt);
			cout << "Here is the set after erasing the noted integer: ";
			for (auto const &item : inSet) { cout << item << " "; }
		}// end if choice 3
		cout << "\n\n Press Y to manipulate this set data again (any other key to exit sets): ";
		cin >> cont;
		cin.clear();
		cin.ignore(1024, '\n');
		if (toupper(cont) == 'Y') continue;
		else loop = false;
	}// end while 
}// end processSet()

void processMultiset(multiset<int> inMultiset) {
	int choice;
	char cont;
	bool loop = true;
	while (loop) {
		while (true) {
			cout << "\n Please choose from the options below:\n"
				" 1. Print out the contents of the multiset\n"
				" 2. Insert a new integer in the multiset(may be a duplicate)\n"
				" 3. Count the number of occurances of an int in the multiset\n";// there are better ones to choose from
			cout << " Enter your choice now (1-3) : ";
			cin >> choice;
			cin.clear();
			cin.ignore(1024, '\n');
			if (!choice || choice > 3 || choice < 1) {
				cout << "\nInvalid entry. Please try again.\n\n";
			}
			else break;
		}// end while loop
		if (choice == 1) {
			cout << "\nHere is the data in the multiset: ";
			for (auto const &item : inMultiset) { cout << item << " "; }
			cout << endl;
		}// end if choice 1
		else if (choice == 2) {
			cout << "Enter the integer you want to add to the set(can be a duplicate): ";
			int addInt;
			cin >> addInt;
			inMultiset.insert(addInt);
			cout << "Here is the multiset after inserting: ";
			for (auto const &item : inMultiset) { cout << item << " "; }
		}// end if choice 2
		else if (choice == 3) {
			cout << "Enter the integer you want to count in the multiset: ";
			int countInt;
			cin >> countInt;
			cout << "Here is the number of times that " << countInt 
				<< " was found in the multiset: " << inMultiset.count(countInt);
		}// end if choice 3
		cout << "\n\n Press Y to manipulate this multiset data again (any other key to exit multiset): ";
		cin >> cont;
		cin.clear();
		cin.ignore(1024, '\n');
		if (toupper(cont) == 'Y') continue;
		else loop = false;
	}// end while
}// end processMultiset()

void processMap(map<int, double> map) {
	int choice;
	char cont;
	bool loop = true;
	while (loop) {
		while (true) {
			cout << "\n Please choose from the options below:\n"
				" 1. Print out the contents of the map\n"
				" 2. Find a pair in the map based on a key value\n"
				" 3. Use at() to change the value stored for any key\n";// there are better ones to choose from
			cout << " Enter your choice now (1-3) : ";
			cin >> choice;
			cin.clear();
			cin.ignore(1024, '\n');
			if (!choice || choice > 3 || choice < 1) {
				cout << "\nInvalid entry. Please try again.\n\n";
			}
			else break;
		}// end while loop
		if (choice == 1) {
			cout << "\n Here is the data in the map:\n";
			cout << "\n Key\tValue\n";
			for (auto pair : map) { cout << " " << pair.first << "\t" << pair.second << endl; }
		}// end if choice 1
		else if (choice == 2) {
			cout << " Enter the key value to the pair you wish to find in the map: ";
			int findKey;
			cin >> findKey;
			map.find(findKey);
			cout << "\n Here are all pairs found with the key value " << findKey << endl;
			cout << "\n Key\tValue\n";
			cout << " " << map.find(findKey)->first << "\t" << map.find(findKey)->second << endl;
		}// end if choice 2
		else if (choice == 3) {
			cout << "\n Enter the key to the data you wish to change: ";
			int key;
			cin >> key;
			cout << " Now enter the new data: ";
			double newValue;
			cin >> newValue;
			map.at(key) = newValue;
			cout << "\n Here is the updated data in the map:\n";
			cout << "\n Key\tValue\n";
			for (auto pair : map) { cout << " " << pair.first << "\t" << pair.second << endl; }
		}// end if choice 3
		cout << "\n\n Press Y to manipulate this map data again (any other key to exit map): ";
		cin >> cont;
		cin.clear();
		cin.ignore(1024, '\n');
		if (toupper(cont) == 'Y') continue;
		else loop = false;
	}// end while
}// end processMap()

void processMultimap(multimap<int, double> mMap) {
	int choice;
	char cont;
	bool loop = true;
	while (loop) {
		while (true) {
			cout << "\n Please choose from the options below:\n"
				" 1. Print out the contents of the multimap\n"
				" 2. Find all values in the multimap matching a key value using equal_range\n"
				" 3. Find the size of the multimap container\n";
			cout << " Enter your choice now (1-3) : ";
			cin >> choice;
			cin.clear();
			cin.ignore(1024, '\n');
			if (!choice || choice > 3 || choice < 1) { cout << "\nInvalid entry. Please try again.\n\n"; }
			else break;
		}// end while loop
		if (choice == 1) {
			cout << "\n Here is the data in the multimap:\n";
			cout << "\n Key\tValue\n";
			for (auto pair : mMap) { cout << " " << pair.first << "\t" << pair.second << endl; }
		}// end if choice 1
		else if (choice == 2) {
			cout << "\n Enter the key value to the pair(s) you wish to find in the multimap: ";
			int findKey;
			cin >> findKey;
			auto range = mMap.equal_range(findKey);
			cout << "\n Here are all pairs found with the key value in the multimap" << findKey << endl;
			cout << "\n Key\tValue\n";
			for (auto i = range.first; i != range.second; ++i) {
			cout << " " << i->first << "\t" << i->second << endl;
			}
		}// end if choice 2
		else if (choice == 3) {
			cout << "\n The multimap size is: " << mMap.size() << endl;
		}// end if choice 3
		cout << "\n\n Press Y to manipulate this multimap data again (any other key to exit multimap): ";
		cin >> cont;
		cin.clear();
		cin.ignore(1024, '\n');
		if (toupper(cont) == 'Y') continue;
		else loop = false;
	}// end while
}// end processMultimap()

//*******************************************************************************************//
void processUSet(unordered_set<int> inUSet) {
	int choice;
	char cont;
	bool loop = true;
	while (loop) {
		while (true) {
			cout << "\n Please choose from the options below:\n"
				" 1. Print out the contents of the unordered set\n"
				" 2. Swap the unordered sets data with another unordered sets data\n"
				" 3. Clear the data from the unordered set\n";
			cout << " Enter your choice now (1-3) : ";
			cin >> choice;
			cin.clear();
			cin.ignore(1024, '\n');
			if (!choice || choice > 3 || choice < 1) {
				cout << "\nInvalid entry. Please try again.\n\n";
			}
			else break;
		}// end while loop
		if (choice == 1) {
			cout << "\n\n Here is the data in the unordered set: ";
			for (auto const &item : inUSet) { cout << item << " "; }
			cout << endl;
		}// end if choice 1
		else if (choice == 2) {
			unordered_set<int> newUSet;
			populateOAC(newUSet);
			inUSet.swap(newUSet);
			cout << " Here is the first unordered set after the swap: ";
			for (auto const &item : inUSet) { cout << item << " "; }
		}// end if choice 2
		else if (choice == 3) {
			inUSet.clear();
			cout << " Here is the unordered set after clearing it: ";
			for (auto const &item : inUSet) { cout << item << " "; }
			cout << "\n(this prints on a new line after the cleared unordered set is printed)";
		}// end if choice 3
		cout << "\n\n Press Y to manipulate this unordered set data again (any other key to exit): ";
		cin >> cont;
		cin.clear();
		cin.ignore(1024, '\n');
		if (toupper(cont) == 'Y') continue;
		else loop = false;
	}// end while 
}// end processSet()

void processUMultiset(unordered_multiset<int> inMultiset) {
	int choice;
	char cont;
	bool loop = true;
	while (loop) {
		while (true) {
			cout << "\n Please choose from the options below:\n"
				" 1. Print out the contents of the unordered multiset\n"
				" 2. Find a value based on a user entered search in the unordered multiset\n"
				" 3. Count the number of occurances of an int in the unordered multiset\n";// there are better ones to choose from
			cout << " Enter your choice now (1-3) : ";
			cin >> choice;
			cin.clear();
			cin.ignore(1024, '\n');
			if (!choice || choice > 3 || choice < 1) {
				cout << "\nInvalid entry. Please try again.\n\n";
			}
			else break;
		}// end while loop
		if (choice == 1) {
			cout << "\nHere is the data in the unordered multiset: ";
			for (auto const &item : inMultiset) { cout << item << " "; }
			cout << endl;
		}// end if choice 1
		else if (choice == 2) {
			cout << "\n Enter the key you wish to search for in the unordered multiset: ";
			int searchKey;
			cin >> searchKey;
			inMultiset.find(searchKey);			
			auto range = inMultiset.equal_range(searchKey);
			cout << "\n Here all items found matching the search value in the unordered multiset:\n";
			while(range.first != range.second) {
				cout << " " << *range.first++ << " " << endl;
			}
		}// end if choice 2
		else if (choice == 3) {
			cout << "Enter the integer you want to count in the unordered multiset: ";
			int countInt;
			cin >> countInt;
			cout << "Here is the number of times that " << countInt
				<< " was found in the unordered multiset: " << inMultiset.count(countInt);
		}// end if choice 3
		cout << "\n\n Press Y to manipulate this unordered multiset data again (any other key to exit): ";
		cin >> cont;
		cin.clear();
		cin.ignore(1024, '\n');
		if (toupper(cont) == 'Y') continue;
		else loop = false;
	}// end while
}// end processMultiset()

void processUMap(unordered_map<int, double> uMap) {
	int choice;
	char cont;
	bool loop = true;
	while (loop) {
		while (true) {
			cout << "\n Please choose from the options below:\n"
				" 1. Print out the contents of the unordered map\n"
				" 2. Find the first element in the unordered map container\n"
				" 3. Use at() to change the value stored for any key\n";// there are better ones to choose from
			cout << " Enter your choice now (1-3) : ";
			cin >> choice;
			cin.clear();
			cin.ignore(1024, '\n');
			if (!choice || choice > 3 || choice < 1) {
				cout << "\nInvalid entry. Please try again.\n\n";
			}
			else break;
		}// end while loop
		if (choice == 1) {
			cout << "\n Here is the data in the unordered map:\n";
			cout << "\n Key\tValue\n";
			for (auto pair : uMap) { cout << " " << pair.first << "\t" << pair.second << endl; }
		}// end if choice 1
		else if (choice == 2) {
			uMap.begin();
			cout << "\n Here is the first element pair in the unordered map:\n ";
			cout << "\n Key\tValue\n";
			//for (auto it = uMap.begin(); it != uMap.end(); ++it) {
				cout << " " << uMap.begin()->first << "\t" << uMap.begin()->second << endl;
			//}
		}// end if choice 2
		else if (choice == 3) {
			cout << "\n Enter the key to the data you wish to change: ";
			int key;
			cin >> key;
			cout << " Now enter the new data: ";
			double newValue;
			cin >> newValue;
			uMap.at(key) = newValue;
			cout << "\n Here is the updated data in the  unordered map:\n";
			cout << "\n Key\tValue\n";
			for (auto pair : uMap) { cout << " " << pair.first << "\t" << pair.second << endl; }
		}// end if choice 3
		cout << "\n\n Press Y to manipulate this unordered map data again (any other key to exit unordered map): ";
		cin >> cont;
		cin.clear();
		cin.ignore(1024, '\n');
		if (toupper(cont) == 'Y') continue;
		else loop = false;
	}// end while
}// end processMap()

void processUMultimap(unordered_multimap<int, double> mMap) {
	int choice;
	char cont;
	bool loop = true;
	while (loop) {
		while (true) {
			cout << "\n Please choose from the options below:\n"
				" 1. Print out the contents of the unordered multimap\n"
				" 2. Insert a new key/value pair into the unorderd multimap\n"
				" 3. Erase key/value pairs in the unordered multimap using a search key\n";
			cout << " Enter your choice now (1-3) : ";
			cin >> choice;
			cin.clear();
			cin.ignore(1024, '\n');
			if (!choice || choice > 3 || choice < 1) { cout << "\nInvalid entry. Please try again.\n\n"; }
			else break;
		}// end while loop
		if (choice == 1) {
			cout << "\n Here is the data in the unordered multimap:\n";
			cout << "\n Key\tValue\n";
			for (auto pair : mMap) { cout << " " << pair.first << "\t" << pair.second << endl; }
		}// end if choice 1
		else if (choice == 2) {
			cout << "\n Enter int and a double, seperated by a space, to add to the unordered multimap: ";
			int newInt;
			double newDouble;
			cin >> newInt >> newDouble;
			pair<int, double> newPair(newInt, newDouble);
			mMap.insert(newPair);
			cout << "\n Here is the updated unordered multimap:\n";
			cout << "\n Key\tValue\n";
			for (auto pair : mMap) { cout << " " << pair.first << "\t" << pair.second << endl; }
		}// end if choice 2
		else if (choice == 3) {
			cout << "\n Enter the key for the pair(s) you wish to erase from the unordered multimap: ";
			int key;
			cin >> key;
			mMap.erase(key);
			cout << "\n Here is the updated unordered multimap:\n";
			cout << "\n Key\tValue\n";
			for (auto pair : mMap) { cout << " " << pair.first << "\t" << pair.second << endl; }
		}// end if choice 3
		cout << "\n\n Press Y to manipulate this unordered multimap data again (any other key to exit): ";
		cin >> cont;
		cin.clear();
		cin.ignore(1024, '\n');
		if (toupper(cont) == 'Y') continue;
		else loop = false;
	}// end while
}// end processMultimap()

void processStack(stack<int, vector<int>> myStack) {
	int choice;
	char cont;
	bool loop = true;
	while (loop) {
		while (true) {
			cout << "\n Please choose from the options below:\n"
				" 1. Print out the contents of the stack\n"
				" 2. Access the top element in the stack\n"
				" 3. Remove the top element in the stack\n";
			cout << " Enter your choice now (1-3) : ";
			cin >> choice;
			cin.clear();
			cin.ignore(1024, '\n');
			if (!choice || choice > 3 || choice < 1) { cout << "\nInvalid entry. Please try again.\n\n"; }
			else break;
		}// end while loop
		if (choice == 1) {
			cout << "\n Here is the data in the stack:\n";
			stack<int, vector<int>> printS;
			printS = myStack;
			printStack(printS);
		}// end if choice 1
		else if (choice == 2) {
			cout << "\n Here is the top element in the stack: " << myStack.top() << endl;
		}// end if choice 2
		else if (choice == 3) {
			cout << "\n The top element " << myStack.top() << " has been removed: ";
			myStack.pop();
		}// end if choice 3
		cout << "\n\n Press Y to manipulate this stack data again (any other key to exit): ";
		cin >> cont;
		cin.clear();
		cin.ignore(1024, '\n');
		if (toupper(cont) == 'Y') continue;
		else loop = false;
	}
}

void processQueue(queue<int> myQueue) {
	int choice;
	char cont;
	bool loop = true;
	while (loop) {
		while (true) {
			cout << "\n Please choose from the options below:\n"
				" 1. Print out the contents of the queue\n"
				" 2. See if the queue is empty\n"
				" 3. Swap the contents of this queue with another queue\n";
			cout << " Enter your choice now (1-3) : ";
			cin >> choice;
			cin.clear();
			cin.ignore(1024, '\n');
			if (!choice || choice > 3 || choice < 1) { cout << "\nInvalid entry. Please try again.\n\n"; }
			else break;
		}// end while loop
		if (choice == 1) {
			cout << "\n Here is the data in the queue:\n";
			queue<int> printQ;
			printQ = myQueue;
			printQueue(printQ);
		}// end if choice 1
		else if (choice == 2) {
			string empty;
			if (myQueue.empty() == 0) empty = "No";
			else if (myQueue.empty() == 1) empty = "Yes";
			cout << "\n Is the queue empty? " << empty << endl;
		}// end if choice 2
		else if (choice == 3) {
			queue<int> q;
			populateContainerAdapters(q);
			myQueue.swap(q);
			cout << "\n Here is queue data after the swap:\n";
			queue<int> printQ;
			printQ = myQueue;
			printQueue(printQ);
		}// end if choice 3
		cout << "\n\n Press Y to manipulate this queue data again (any other key to exit): ";
		cin >> cont;
		cin.clear();
		cin.ignore(1024, '\n');
		if (toupper(cont) == 'Y') continue;
		else loop = false;
	}
}

void processPriorityQueue(priority_queue<int> myPQueue) {
	int choice;
	char cont;
	bool loop = true;
	while (loop) {
		while (true) {
			cout << "\n Please choose from the options below:\n"
				" 1. Print out the contents of the priority queue\n"
				" 2. Push another integer into the priority queue\n"
				" 3. Get the current size of the priority queue\n";
			cout << " Enter your choice now (1-3) : ";
			cin >> choice;
			cin.clear();
			cin.ignore(1024, '\n');
			if (!choice || choice > 3 || choice < 1) { cout << "\nInvalid entry. Please try again.\n\n"; }
			else break;
		}// end while loop
		if (choice == 1) {
			cout << "\n Here is the data in the priority queue:\n";
			priority_queue<int> printPQ;
			printPQ = myPQueue;
			printPriorityQueue(printPQ);
		}// end if choice 1
		else if (choice == 2) {
			cout << " Enter the integer you wish to add to the priority queue: ";
			int newInt;
			cin >> newInt;
			myPQueue.push(newInt);
			cout << "\n Here is the updated priority queue data: ";
			priority_queue<int> printPQ;
			printPQ = myPQueue;
			printPriorityQueue(printPQ);
		}// end if choice 2
		else if (choice == 3) {	
			cout << "\n The current size of the priority queue is: " << myPQueue.size();
		}// end if choice 3
		cout << "\n\n Press Y to manipulate this priority queue data again (any other key to exit): ";
		cin >> cont;
		cin.clear();
		cin.ignore(1024, '\n');
		if (toupper(cont) == 'Y') continue;
		else loop = false;
	}
}


void printStack(stack<int, vector<int>> stack) {
	while (!stack.empty()) {
		cout << stack.top() << " ";
		stack.pop();
	}
	cout << endl;
}


void printQueue(queue<int> q) {
	while (!q.empty()) {
		cout << " " << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

void printPriorityQueue(priority_queue<int> q) {
	while (!q.empty()) {
		cout << q.top() << " ";
		q.pop();
	}
	cout << endl;
}