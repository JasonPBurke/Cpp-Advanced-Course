// Program09.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>// for getline
#include<vector>
#include<array>
#include<list>
#include<set>
#include<algorithm>
#include<iterator>
#include<numeric>
#include<random>
#include<functional>

using namespace std;

list<string> list2;// create an empty list of ints

// POPULATE VECTORS AND LISTS
template<typename T> T populateSeqCont(T& tContainer) {// can add &
	string pushMe;
	for (size_t i = 0; i < 10; i++) {
		cin >> pushMe;
		tContainer.push_back(pushMe);
	}
	cin.clear();
	cin.ignore(1024, '\n');
	return tContainer; // return the populated container
}// end processSC

template<typename T> T populateMultiset(T& tContainer) {// can add &
	int pushMe;
	vector<int> v;
	for (size_t i = 0; i < 10; i++) {
		cin >> pushMe;
		v.push_back(pushMe);
	}
	tContainer.insert(v.begin(), v.end());
	cin.clear();
	cin.ignore(1024, '\n');
	return tContainer; // return the populated container
}// end processSC

bool continueWithGroup() {
	cout << "\n\n Do you wish to use this group of algorithms again? (Y/N): ";
	char yesNo;
	cin >> yesNo;
	if (toupper(yesNo) == 'Y') {  }
	else if (toupper(yesNo) == 'N') { return false; }
}

// FUNCTION OBJECTS
template<typename T>
class OddsFirstClass {
public:
	//sort the evens first and then the odds
	T operator()(const T& thing1, const T& thing2) {
		if (thing1 % 2 == 0 && thing2 % 2 != 0) {
			return false;	
		}
		else if (thing1 % 2 != 0 && thing2 % 2 == 0) {
			return true;
		}
		return thing1 < thing2;
	}
};

template<typename T>
class FindMinEvenClass {
public:
	// find the minimum even number in the container
	T operator()(const T& thing1, const T& thing2) {
		if (thing1 % 2 == 0 && thing2 % 2 != 0) {
			return true;
		}
		else if (thing1 % 2 != 0 && thing2 % 2 == 0) {
			return false;
		}
		else if (thing1 < thing2) return true;
		else if (thing2 < thing1) return false;
	}
};

template<typename T>
class FindMaxEvenClass {
public:
	//find max odd number
	T operator()(const T& thing1, const T& thing2) {
		if (thing1 % 2 != 0 && thing2 % 2 == 0) {
			return true;
		}
		else if (thing1 % 2 == 0 && thing2 % 2 != 0) {
			return false;
		}
		else if (thing1 < thing2) return true;
		else if (thing2 < thing1) return false;
	}
};



int main() {

	cout << "This program demonstrates many of the algorithms found in the c++ standard library\n\n";
	int usrChoice;

	while(true){
		while (true) {
			cout << "\n Here is a list containing different groups of sequence algorithms\n"
				<< " 1) Modifying Sequence Algorithms\n"
				<< " 2) Non-Modifying Sequence Algorithms\n"
				<< " 3) Sorting and Related Algorithms\n"
				<< " 4) Numerical Algorithms\n"
				<< " 5) Function Objects\n";
			cout << "Please enter the number of the algorithm group you wish to use (1-5 or 0 to exit): ";
		
			cin >> usrChoice;
			cin.clear();
			cin.ignore(1024, '\n');
			if (usrChoice < 0 || usrChoice > 5) {
				cout << "\nEntry must be a number between 0-5 inclusive.  Please try again.\n\n";
			}// end if
			else break;
		}// end userChoice while loop

		if (usrChoice == 0) break;
		if (usrChoice == 1) {// array; use remove, remove_if, replace_if, and fill algorithms 

			//********this block fills an array to use with this set of modifying algorithms************//
			cout << "\n For this algorithm set, we will use an array of integers\n";
			cout << " Please enter ten itegers, seperated by spaces, to populate the array: ";
			array<int, 10> myArray;// create an empty array of ints
			for (size_t i = 0; i < 10; i++) { cin >> myArray[i]; }// FILL THE ARRAY FROM USER DATA
			cin.clear();// clear/ignore incase user entered more than ten ints
			cin.ignore(1024, '\n');
			//*****************************************************************************************//
			auto newEnd = myArray.end();
			while (true) {	
				ostream_iterator<int> output{ cout, " " };//put array in an os_iterator to output easily for all options				
				cout << "\n Array data: ";
				copy(myArray.begin(), newEnd, output);
				int choice;
				while (true) {
					cout << "\n\n This group of modifying algorithms contains the following:\n"
						<< " 1) Remove Algorithm\n"
						<< " 2) Remove_if Algorithm\n"
						<< " 3) Replace_if Algorithm\n"
						<< " 4) Fill Algorithm\n"
						<< " Please enter the number of the algorithm you would like to use: ";
					cin >> choice;
					cin.clear();
					cin.ignore(1024, '\n');
					if (choice < 1 || choice > 4) {
						cout << "\nEntry must be a number between 1-4 inclusive.  Please try again.\n\n";
					}// end if
					else break;
				}
				if (choice == 1) {
					cout << "\nREMOVE:\n Please enter the integer you wish to remove from the array: ";
					int removeMe;
					cin >> removeMe;
					newEnd = remove(myArray.begin(), newEnd, removeMe);
					cout << "\n Here is the updated array: ";
					copy(myArray.begin(), newEnd, output);// output array using copy/os_iter
				}// end inner if choice alg 1
				else if (choice == 2) {
					cout << "\nREMOVE_IF:\n This algorithm's implementation will remove all integers\n"
						 << " in the array that are larger than a specified number.\n"
						 << "\n Please enter a number, and I will remove all integers larger than it from the array: ";
					int removeIf;
					cin >> removeIf;
					newEnd = remove_if(myArray.begin(), newEnd, [removeIf](auto x) { return x > removeIf; });
					cout << "\n Here is the updated array: ";
					copy(myArray.begin(), newEnd, output);
				}// end inner if choice alg 2
				else if (choice == 3) {
					cout << "\nREPLACE_IF:\n This algorithm's inmplementation will repalce all integers\n"
						 << " less than the user specified number, with a user chosen integer,\n"
						 << " Please enter the replacement integer: ";
					int replacementInt, pivotInt;
					cin >> replacementInt;
					cout << " Now enter a number, and I will replace all integers in the array that are less than\n"
						<< " your number, with the replacement integer previously entered: ";
					cin >> pivotInt;
					replace_if(myArray.begin(), newEnd, 
						[pivotInt, replacementInt](auto x) { return x < pivotInt; }, replacementInt);
					cout << "\n Here is the updated array: ";
					copy(myArray.begin(), newEnd, output);
				}// end inner if choice alg 3
				else if (choice == 4) {
					cout << "\n Please enter an integer and I will fill the array with it: ";
					int fillInt;
					cin >> fillInt;
					fill(myArray.begin(), newEnd, fillInt);
					cout << "\n Here is the updated array: ";
					copy(myArray.begin(), newEnd, output);
				}// end inner if choice alg 4
		
				bool again = continueWithGroup();// see if user wants to continue with the same data/alg group
				if (again == false) break;
			}// end inner while
		}// end outer if choice group 1
		else if(usrChoice == 2) {// list; use equal, mismatch, lexiconagraphical_compare, and for_each algorithms

			cout << "\n For this non-modifying algorithm set, we will use a list of strings\n";
			cout << " Please enter ten strings of characters, seperated by spaces, to populate the list:\n :";
			list<string> myList;// create an empty list of ints
			populateSeqCont(myList);// call template to fill vector

			while (true) {
				cout << "\n List data: ";
				for (auto const &item : myList) { cout << item << " "; }
				int choice;
				while (true) {
					cout << "\n\n This group contains the following non-modifying algorithms:\n"
						<< " 1) Equal Algorithm\n"
						<< " 2) Mismatch Algorithm\n"
						<< " 3) Lexiconagraphical_Compare Algorithm\n"
						<< " 4) For_Each Algorithm\n"
						<< " Please enter the number of the algorithm that you would like to use: ";
					cin >> choice;
					cin.clear();
					cin.ignore(1024, '\n');
					if (choice < 1 || choice > 4) { cout << "\nEntry must be 1-4 inclusive.  Please try again.\n\n"; }
					else break;
				}
				if (choice == 1) {
					//*****************************CREATE AND POPULATE NEW LIST*********************************//
					cout << "\nEQUAL:\n The equal algorithm will tell us if our two lists are the same.\n"
						 << "\n To use the equal algorithm, we will first need to populate a second list.\n"
						 << " Please enter ten strings of characters, seperated by spaces, to populate the second list : ";
					list<string> list2;// create an empty list of ints
					populateSeqCont(list2);
					//******************************************************************************************//
					bool result = equal(myList.begin(), myList.end(), list2.begin(), list2.end());
					cout << "\n List 1" << (result ? " is " : " is not ") << "equal to list 2.";
				}// end if choice non-mod alg1
				if (choice == 2) {
					cout << "\nMISMATCH:\n If our two lists are not the same, the mismatch algorithm\n"
						 << " will tell us where the FIRST mismatched elements are located.  As such,\n"
						 << " we will need to fill another list.  Enter 10 strings of chars, as before, now:\n :";
					//*****************************CREATE AND POPULATE NEW LIST*********************************//
					list<string> list2;// create an empty list of ints
					populateSeqCont(list2);
					//******************************************************************************************//
					auto location = mismatch(myList.begin(), myList.end(), list2.begin(), list2.end());
					if (location.first == myList.end()) {
						cout << "\n There is no mismatch between list 1 and list 2.\n";
					}
					else {
						cout << "\n There is a mismatch between list 1 and list 2. \n"
							//<< (location.first - myList.begin()) << "\n where list 1 contains "// NOT WORKING
							<< " List 1 found '" << *location.first
							<< "' where list 2 contains '" << *location.second << "'\n";
					}
				}// end if choice non-mod alg2
				if (choice == 3) {
					cout << "\nLEXICOGRAPHICAL_COMPARE:\n If there is a mismatch in the two lists, this algorithm\n"
						 << " will compare the first set of mismatched values and return true if the value from\n"
						 << " the first list was less than the mismatched value found in the second list.\n";
					cout << " Again, we will need a second list to make the comparison.\n"
						 << " Enter 10 strings of characters, seperated by spaces, to fill the second list:\n: ";
					//*****************************CREATE AND POPULATE NEW LIST*********************************//
					list<string> list2;// create an empty list of ints
					populateSeqCont(list2);
					bool result = lexicographical_compare(myList.begin(), myList.end(), list2.begin(), list2.end());
					cout << " List 1" << (result ? " is less than " : " is greater than or equal to ") << "list 2.";
				}// end if choice non-mod alg3
				if (choice == 4) {
					cout << "\nFOR_EACH:\n We will use this algorithm to output the first character from \n"
						<< " each string in our list.";
					int total;
					cout << "\n\n Here is the first letter from each string stored in the list: ";
					for_each(myList.cbegin(), myList.cend(), [&total](auto x) { cout << x[0] << " "; });	                                                            
					
				}// end if choice non-mod alg4

				bool again = continueWithGroup();// see if user wants to continue with the same data/alg group
				if (again == false) break;
			}// end inner while
		}// end outer if choice group 2
		else if (usrChoice == 3) {// vector; use find, find_if, sort, all_of, any_of, and none_of algorithms
			cout << "\n For this sorting and related algorithm group, we will use a vector of doubles.\n"
				 << " Please enter ten doubles, seperated by spaces, now: ";
			vector<double> myVector;
			double pushMe;
			for (size_t i = 0; i < 10; i++) {
				cin >> pushMe;
				myVector.push_back(pushMe);
			}
			cin.clear();
			cin.ignore(1024, '\n');

			while (true) {
				ostream_iterator<double> output{ cout, " " };
				auto isGreaterThanFive{ [](auto x) { return x > 5.0; } };
				cout << "\n\n Vector data: ";
				for (auto const &item : myVector) { cout << item << " "; }
				int choice;
				while (true) {
					cout << "\n\n This group contains the following sorting and related algorithms:\n"
						<< " 1) Sort Algorithm\n"
						<< " 2) Find Algorithm\n"
						<< " 3) Find_If Algorithm\n"
						<< " 4) All_Of Algorithm\n"
						<< " 5) Any_Of Algorithm\n"
						<< " 6) None_Of Algorithm\n"
						<< " Please enter the number of the algorithm you would like to use: ";			
					cin >> choice;
					cin.clear();
					cin.ignore(1024, '\n');
					if (choice < 1 || choice > 6) { cout << "\nEntry must be 1-6 inclusive.  Please try again.\n\n"; }
					else break;
				}// end while

				if (choice == 1) { 					
					cout << "\nSORT:\n The sort algorithm will sort the vector of doubles in acending order.\n";
					cout << "\n The vector before sort: ";
					copy(myVector.begin(), myVector.end(), output);
					sort(myVector.begin(), myVector.end());
					cout << "\n The vector after sort: ";
					copy(myVector.begin(), myVector.end(), output);		
				}// end choice sort
				else if (choice == 2) {
					cout << "\nFIND:\n The find algorithm will find if a double you search for is in the vector.\n";
					cout << " Enter the double to search for now: ";
					double searchDouble;
					cin >> searchDouble;
					auto location = find(myVector.begin(), myVector.end(), searchDouble);
					if (location != myVector.end()) {
						cout << "\n Success!  Found " << searchDouble << " at position " << (location - myVector.begin());
					}
					else cout << " " << searchDouble << " not found in the vector.\n";
				}// end choice find
				else if (choice == 3) {
					cout << "\nFIND_IF:\n For our implementation, the find_if algorithm will find the first\n"
						<< " number in the list that is larger than 5.0.\n";
					auto location = find_if(myVector.begin(), myVector.end(), isGreaterThanFive);
					if (location != myVector.end()) {
						cout << "\n The first value in the vector greater than 5.0 is " << *location
							 << " found at location " << (location - myVector.begin());
					}
					else cout << "\n No vales greater than 5.0 were found in the vector.\n";
				}// end choice find_if
				else if (choice == 4) {
					cout << "\nALL_OF:\n The all_of algorithm will determine if ALL of\n"
						 << " the doubles in the vector are greater than 5.0.\n";
					if (all_of(myVector.begin(), myVector.end(), isGreaterThanFive)) {
						cout << "\n (true) All elements in the vector are greater than 5.0.\n";
					} 
					else cout << "\n (false) Some of the elements in the vector are less than 5.0.\n";
				}// end choice all_of
				else if (choice == 5) {
					cout << " \nANY_OF:\n The any_of algorithm will determine if ANY of\n"
						<< " the doubles in the vector are greater than 5.0.\n";
					if (any_of(myVector.begin(), myVector.end(), isGreaterThanFive)) {
						cout << "\n (true) Some of the elements in the vector are greater than 5.0.\n";
					}
					else cout << "\n (false) None of the elements in the vector are greater than 5.0.\n";
				}// end choice any_of
				else if (choice == 6) {
					cout << " \nNONE_OF:\n The none_of algorithm will determine if NONE of\n"
						<< " the doubles in the vector are greater than 5.0.\n";
					if (none_of(myVector.begin(), myVector.end(), isGreaterThanFive)) {
						cout << "\n (true) None of the elements in the vector are greater than 5.0.\n";
					}
					else cout << "\n (false) Some of the elements in the vector are greater than 5.0.\n";
				}

				bool again = continueWithGroup();// see if user wants to continue with the same data/alg group
				if (again == false) break;
			}// end while loop
		}// end if choice group 3
		else if (usrChoice == 4) {// array; use shuffle and count algorithms
			cout << "\n For this numerical algorithm group, we will use an array of ints.\n"
				<< " Please enter ten integers, seperated by spaces, now: ";
			array<int, 10> myArray;
			int addMe;
			for (size_t i = 0; i < 10; i++) {
				cin >> addMe;
				myArray[i] = addMe;
			}
			cin.clear();
			cin.ignore(1024, '\n');

			while (true) {
				ostream_iterator<int> output{ cout, " " };
				auto isGreaterThanFive{ [](auto x) { return x > 5.0; } };
				cout << "\n\n Vector data: ";
				for (auto const &item : myArray) { cout << item << " "; }
				int choice;
				while (true) {
					cout << "\n\n This group contains the following numerical algorithms:\n"
						<< " 1) Shuffle Algorithm\n"
						<< " 2) Count Algorithm\n"
						<< " Please enter the number of the algorithm you would like to use: ";
					cin >> choice;
					cin.clear();
					cin.ignore(1024, '\n');
					if (choice < 1 || choice > 6) { cout << "\nEntry must be 1-6 inclusive.  Please try again.\n\n"; }
					else break;
				}// end while
				if(choice == 1){
					cout << "\nSHUFFLE:\n The shuffle algorithm will randomly reorder the elements in the array.\n";
					// create a randon-number engine and use it to help shuffle myArray's elements
					default_random_engine randomEngine{ random_device{}() };
					shuffle(myArray.begin(), myArray.end(), randomEngine);// randomly order the array elements
					cout << "\n Here is the array after shuffle was used: ";
					copy(myArray.begin(), myArray.end(), output);// output shuffled array
					cin.clear();
					cin.ignore(1024, '\n');
				}
				else if(choice == 2){
					cout << "\nCOUNT:\n The count algorithm will count up the"
						<< " times a specified number is found in the array.\n";
					int findMe;
					cout << "\n Enter an integer to use to demonstrate the count algorithm on the array: ";
					cin >> findMe;
					auto result = count(myArray.begin(), myArray.end(), findMe);
					cout << "\n The number of elements matching " << findMe << " is: " << result;
				}
				cin.clear();
				cin.ignore(1024, '\n');

				bool again = continueWithGroup();// see if user wants to continue with the same data/alg group
				if (again == false) break;
			}// end while
		}// end if choice group 4
		else if (usrChoice == 5) {//vector 4 types of function objects
			cout << "\n For this function objects group, we will use a vector of integers.\n"
				<< " Please enter ten integers, seperated by spaces, now: ";
			vector<int> myVector;
			//populateMultiset(myMultiset);
			int pushMe;
			for (size_t i = 0; i < 10; i++) {
				cin >> pushMe;
				myVector.push_back(pushMe);
			}
			cin.clear();
			cin.ignore(1024, '\n');
			while(true) {
				ostream_iterator<int> output{ cout, " " };
				cout << "\n Vector data: ";
				copy(myVector.begin(), myVector.end(), output);
				cout << endl;
				int choice;
				while (true) {
					cout << "\n\n This group provides the following Function Objects:\n"
						<< " 1) Transform using Plus Function Object\n"
						<< " 2) Sort algorithm using EvensFirstClass Function Object\n"
						<< " 3) Min_Element algorithm using FindMinEvenClass Function Object\n"
						<< " 4) Max_Element algorithm using FindMaxEvensClass Function Object\n"
						<< " Please enter the number of the function object you would like to use: ";
					cin >> choice;
					cin.clear();
					cin.ignore(1024, '\n');
					if (choice < 1 || choice > 4) { cout << "\nEntry must be 1-4 inclusive.  Please try again.\n\n"; }
					else break;
				}// end while

				if (choice == 1) {
					cout << "\nPLUS FUNCTION OBJECT:\n The transform algorithm using the plus function object\n"
						 << " will add together each matched element of 2 vectors.\n";
					cout << " We will need to populate an additional vector for this process.\n"
						<< " Enter 10 integers, seperated by spaces, to fill the 2nd vector now: ";
					vector<int> mySecondVector;
					int pushMe;
					for (size_t i = 0; i < 10; i++) {
						cin >> pushMe;
						mySecondVector.push_back(pushMe);
					}
					cin.clear();
					cin.ignore(1024, '\n');
					vector<int> transformedVector;
					transformedVector.resize(myVector.size());
					cout << "\n First  Vector data: ";
					copy(myVector.begin(), myVector.end(), output);
					cout << "\n Second Vector data: ";
					copy(mySecondVector.begin(), mySecondVector.end(), output);
					cout << endl << endl;
					transform(myVector.begin(), myVector.end(), mySecondVector.begin(), transformedVector.begin() ,plus<int>());
					cout << " Here is the vector transformed using the PLUS function object: ";
					copy(transformedVector.begin(), transformedVector.end(), output);
					cout << endl;
				}
				if (choice == 2) {//sort}//sort by odd, then by value
					cout << "\nODDSFIRSTCLASS FUNCTION OBJECT:\n The sort algorithm using the function object OddsFirstClass will sort\n"
						 << " the odd elements to the front of the vector and the evens to the back.\n";
					sort(myVector.begin(), myVector.end(), OddsFirstClass<int>{});
					cout << "\n Here is the odds-first sorted vector: ";
					copy(myVector.begin(), myVector.end(), output);
				}
				if (choice == 3) {//min_element// minimum even
					cout << "\nFINDMINEVENCLASS FUNCTION OBJECT:\n The min_element algorithm will be used with the function object\n"
						<< " called FindMinEvenClass that will return the minimum even element in the vector.\n";
					cout << "\n The minimum even element in the vector is: "
						<< *(min_element(myVector.begin(), myVector.end(), FindMinEvenClass<int>{}));
				}
				if (choice == 4) {//max_element// maximum even
					cout << "\nFINDMAXEVENSCLASS FUNCTION OBJECT:\n The max_element algorithm will be used with the function object\n"
						<< " called FindMaxEvensClass that will return the maximum even element in the vector.\n";
					cout << "\n The maximum even element in the vector is: "
						<< *(max_element(myVector.begin(), myVector.end(), FindMaxEvenClass<int>{}));
				}

				bool again = continueWithGroup();// see if user wants to continue with the same data/alg group
				if (again == false) break;
			}// end while
		}// end if function object grouup
	}// end outer while
    return 0;
}// end main


