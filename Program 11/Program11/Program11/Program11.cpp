// Program11.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include "Stack.h"
using namespace std;

int optionsScreen();

// create a function template to manipulate Stack<T>
template<typename T>
void manipulateStack(Stack<T>& theStack, const int& option, const string& stackName = "Stack") {

	if (option == 2) {	//pop elements from the Stack
		cout << "\n Removing the top element from " << stackName << '\n';	
		try {
			if (theStack.isEmpty()) {// throw an exception if the stack is empty
				throw exception{};
			}
			theStack.pop(); // remove top element 
		}
		catch (const exception& error) {
			cout << "\n****" << error.what() << " - Exception occured attempting to remove the top element: " << "Stack is empty. ****\n";
		}
	}// end if 2
	else if (option == 3) {// display the top element from the Stack		
		try {
			if (theStack.isEmpty()) {// throw exception w/custom message if stack is empty
				throw exception{};
			}
			cout << "\n The top element is: " << theStack.top() << endl;
		}
		catch (const exception& error) {
			cout << "\n ****" << error.what() << " - Exception occured accessing top element: " << "Stack is empty. ****\n";
		}
	}// end if 3
	else if (option == 4) {
		// clear elements from the Stack
		cout << "\n Clearing the Stack: ";
		theStack.clear();
		cout << "The stack " << (theStack.isEmpty() ? "is" : "is not") << " empty.\n";
	}// end if 4
	else if (option == 5) {
		// check if the stack is empty
		cout << "\n\n Check if stack is empty: ";
		cout << "The stack " << (theStack.isEmpty() ? "is" : "is not") << " empty.\n";
	}// end if 5

	showStack(theStack);// output the modified stack data
}// end class template manipulateStack

// call to populate the custom Stack
template<typename T> 
void populateStack(Stack<T>& myStack, const T& dType) {
	cout << "\n Input ten items of the above data type to create the stack (seperate each element with a space): ";
	T pushValue = dType;
	for (size_t i = 0; i < 10; ++i) {
		cin >> pushValue;
		myStack.push(pushValue);// fill() or push() 
	}
	cin.clear();
	cin.ignore(1024, '\n');

	showStack(myStack);
}// end populateStack

// call to show the contents of the stack regardless of stack data type
template<typename T> 
void showStack(Stack<T>& myStack) {
	Stack<T> tempStack = myStack;
	cout << "\n The starting stack: ";
	while (!tempStack.isEmpty()) {
		cout << tempStack.top() << ' ';
		tempStack.pop(); // remove top element 
	}
}// end showStack template



int main() {

	cout << " This program demonstrates custom class and function templates.\n";
	while (true) {
		Stack<string> stringStack;// change name to stringStack etc..
		Stack<double> doubleStack;
		Stack<int> intStack;
		// CALL STACK TYPE OPTION HERE
		cout << "\n Please choose the type of data to store in the Stack:\n 1) Integer\n 2) Double\n 3) String\n"
			<< " Enter your type choice now (0 to exit app): ";
		int typeChoice;
		cin >> typeChoice;
		const string myString = "String";
		const double myDouble = 0.0;
		if (typeChoice == 0) break; // end program
		if (typeChoice == 1) {
			cout << "\nData Type: Integer";
			populateStack(intStack, 0);// PASSING IN A DUMMY VALUE TO SUPPLY THE TYPE INFO??
		}
		else if (typeChoice == 2) { 
			cout << "\nData Type: Double";
			populateStack(doubleStack, myDouble); // ...THINK I HAVE TO THOUGH...
		}
		else if (typeChoice == 3) { 
			cout << "\nData Type: String";
			populateStack(stringStack, myString);
		}

		while (true) {
			int optionChoice = optionsScreen();// display options screen

			if (optionChoice == 0) { break; }// break to outer while loop
			
			if (optionChoice == 1) { // PUSH
				cout << "\n Enter the value you wish to push to the stack: ";
				if (typeChoice == 1) {
					int pushVal;
					cin >> pushVal;
					intStack.push(pushVal);// CALLING PUSH TEMPLATE FUNCTION FROM MAIN
					showStack(intStack);
				}
				else if (typeChoice == 2) {
					double pushVal;
					cin >> pushVal;
					doubleStack.push(pushVal);// CALLING PUSH TEMPLATE FUNCTION FROM MAIN
					showStack(doubleStack);
				}
				else if (typeChoice == 3) {
					string pushVal;
					cin >> pushVal;
					stringStack.push(pushVal);// CALLING PUSH TEMPLATE FUNCTION FROM MAIN
					showStack(stringStack);
				}
			}// end if PUSH
		
			else if (optionChoice == 2) { // POP			
				if (typeChoice == 1) manipulateStack(intStack, optionChoice, "intStack"); // end tC 1			
				else if (typeChoice == 2) manipulateStack(doubleStack, optionChoice, "doubleStack");
				else if (typeChoice == 3) {
					manipulateStack(stringStack, optionChoice, "stringStack");
				}
			}// end if pop
		
			else if (optionChoice == 3) { // TOP
				if (typeChoice == 1) manipulateStack(intStack, optionChoice, "intStack");
				else if (typeChoice == 2) manipulateStack(doubleStack, optionChoice, "doubleStack");
				else if (typeChoice == 3) manipulateStack(stringStack, optionChoice, "stringStack");
			}// end if top

			else if (optionChoice == 4) { // CLEAR
				if (typeChoice == 1) manipulateStack(intStack, optionChoice, "intStack");
				else if (typeChoice == 2) manipulateStack(doubleStack, optionChoice, "doubleStack");
				else if (typeChoice == 3) manipulateStack(stringStack, optionChoice, "stringStack");
			}//end if clear

			else if (optionChoice == 5) { // EMPTY
				if (typeChoice == 1) manipulateStack(intStack, optionChoice, "intStack");
				else if (typeChoice == 2) manipulateStack(doubleStack, optionChoice, "doubleStack");
				else if (typeChoice == 3) manipulateStack(stringStack, optionChoice, "stringStack");
			}// end if empty

		}// end inner while loop
	}// end outer while loop
    return 0;
}// end main()

int optionsScreen() {
		cout << "\n\n Please choose from one of the following options:\n"
			<< " 1) push() - add an element to the top of the stack\n"
			<< " 2) pop() - returns and removes the element from the top of the stack\n"
			<< " 3) top() - returns(but does not remove) element from the top of the stack\n"
			<< " 4) clear() - removes all elements from the stack\n"
			<< " 5) empty() - checks if the stack is empty or not\n";
		cout << " Enter your choice now (0 to enter new data type): ";
		int userChoice;
		cin >> userChoice;
		return userChoice;
}