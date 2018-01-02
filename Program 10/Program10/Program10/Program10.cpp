// Program10.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<iostream>
#include<new>
#include "DivideByZeroException.h"
using namespace std;


//Prototypes
void divByZero();
void rethrowExceptions();
void stackUnwinding();
void newBad_alloc();
void newSet_new_handler();
double quotient(double, double);
void f2();
void f3();
void f4();
void f5();
void customHandler();

int main() {
	cout << "This program is intended to demonstrate exception handling\n\n";
	while (true) {
		cout << " Please choose one of the following exception handling demonstrations: \n"
			<< " 1) Division by Zero\n"
			<< " 2) Rethrowing Exceptions\n"
			<< " 3) Stack Unwinding\n"
			<< " 4) Using the 'new' operator to throw a bad_alloc exception type\n"
			<< " 5) Using the 'new' operator to demonstrate set_new_handler\n"
			<< " Enter your choice now (0 to exit): ";
		int userChoice;
		cin >> userChoice;
		cin.clear();
		cin.ignore(1024, '\n');
		if (userChoice == 0) break;
		if (userChoice == 1) divByZero();
		else if (userChoice == 2) {
			cout << "\n This option will demonstrate rethrowing exceptions.  The function\n"
				 << " asks the user to enter anything into the keyboard, and will throw an\n"
				 << " exception if anything other than the integer 13 was entered.  The user\n"
				 << " will recieve messages at each level of the throw/rethrow process.\n\n";
			cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
			cout << " Press Enter after each step is displayed to move to the next step\n\n";			
			try {
				cout << "Main is now invoking the function rethrowExceptions.\n";
				cin.ignore();
				rethrowExceptions();
			}
			catch(const exception&) {
				cout << "The non-13 exception was thrown from the function and "
					 << "is now being handled in a catch statement in main.\n";
				cin.ignore();
			}
		}// end if 2
		else if (userChoice == 3) { 
			cout << "\n This demonstration will will call functions five times from other functions,\n"
				<< " with the last function throwing an exception.  The exception will fall,\n"
				<< " or unwind, through the called functions back to main, where it will be caught and handled.\n\n";
			try {
				stackUnwinding();
				cout << "No error detected, try demonstration again.\n\n";
			}
			catch (const runtime_error&) {
				cout << " The exception that was nested five functions deep, is now caught/handled in main.\n\n";
			}		
		}// end if 3
		else if (userChoice == 4) newBad_alloc();
		else if (userChoice == 5) newSet_new_handler();
	}// end while loop
    return 0;
}// end main


void newSet_new_handler() {
	cout << "\n This is a demonstration of handling 'new' failures using the set_new_handler function.\n"
		<< " Again, we will be attempting to create a number of pointers to doubles.  You will enter a number\n"
		<< " that will be added to 50,000,000 except when you enter the number 13.\n"
		<< " Entering any number except 13 will cause a memory allocation error to occur.\n"
		<< " This failure will be handled using our set_new_handler function.\n\n";

	set_new_handler(customHandler);// specifies that customHandler should be called on mem allocation failure
	double *ptr[50];
	int powerInt;
	cout << " Enter a number now to calculate the size of each double: ";
	cin >> powerInt;
	cin.clear();
	cin.ignore(1024, '\n');
	if (powerInt != 13) powerInt = powerInt + 50'000'000;// cause number to be large enough to bad_alloc
	try {
		for (size_t i = 0; i < 5; ++i) {
			ptr[i] = new double[powerInt] {};
		}//end for loop
		cout << "\nAll 'new' doubles created successfully.\n\n";
	}
	catch (const bad_alloc& memAllocErr) {
		//cout << "In the catch now: \n\n";
	}
}// end newSet_new_handler()

void customHandler() {
	cerr << "\ncustomHandler was called due to memory allocation failure.\n\n";
	set_new_handler(nullptr);
}// end customHandler()

void newBad_alloc() {
	cout << "\n This is a demonstration of using 'new' to throw a bad_alloc exception on failure.\n"
		 << " We will be attempting to create a number of pointers to doubles.  You will enter a number\n"
		 << " that will be added to 50,000,000 except when you enter the number 13.\n"
		 << " Entering any number except 13 will cause a bad_alloc error to occur.\n\n";

	double *ptr[50];
	int powerInt;
	cout << " Enter a number now to calculate the size of each double: ";
	cin >> powerInt;
	cin.clear();
	cin.ignore(1024, '\n');
	try {
		if (powerInt != 13) powerInt = powerInt + 50'000'000;// cause number to be large enough to bad_alloc
		for (size_t i = 0; i < 50; ++i) {
			ptr[i] = new double[powerInt]{};
		}//end for loop
		cout << "\nAll 'new' doubles created successfully.\n\n";
	}
	catch (bad_alloc& memAllocException) {
		cerr << "\nException occurred: " << memAllocException.what() << endl << endl;
	}
}// end newBad_alloc()

void stackUnwinding() {
	cout << " In stackUnwinding function. Calling function 2\n";
	f2();
}
void f2() { 
	cout << " In function 2.  Calling function 3\n";
	f3();
}
void f3() {
	cout << " In function 3.  Calling function 4\n";
	f4();
}
void f4() {
	cout << " In function 4.  Calling function 5\n";
	f5();
}
void f5() {
	cout << " In function 5.\n\n  Enter Y to cause a runtime_error to occur: ";
	char uIn;
	cin >> uIn;
	cout << endl;
	cin.clear();
	cin.ignore(1024, '\n');
	if (toupper(uIn) == 'Y') throw runtime_error{ " Runtime Error Thrown in function 5." };
}

void rethrowExceptions() {
	try {
		cout << "Now the function we are in (rethrowExceptions) will throw an\n"
			 << "exception if you enter anything other than the number 13.\n";
		cout << "\nEnter anything other than the number 13 to cause an exception to be thrown: ";
		int thirteen;
		cin >> thirteen;
		cin.clear();
		cin.ignore(1024, '\n');
		if (thirteen != 13) throw exception{}; // generate an exception
		cout << "\nYou must have entered thirteen!  Here's your number: " << thirteen << endl << endl;
	}
	catch (const exception&) {
		cout << "\nNon-13 exception caught in the rethrowExceptions function.  "
			 << "The function rethrowExceptions'\n catch statement now calls 'throw' "
			 << "to rethrow the non-13 exception back to main(the caller).\n";
		cin.ignore();
		throw;
	}
}// end rethrowExceptions()

void divByZero() {
		cout << "\n Enter two numbers to divide the first one by the second.\n"
			<< "(enter 0 as the second number to view divide_by_zero error message): ";
		double num1, num2;
		cin >> num1 >> num2;
		cin.clear();
		cin.ignore(1024, '\n');
		try {
			double result = quotient(num1, num2);
			// the following should onl print if the divide is not by zero
			cout << "\n " << num1 << " divided by " << num2 << " equals " << result << endl << endl;
		}
		catch(const DivideByZeroException& divideByZeroException){
			cout << "\nException occured: " << divideByZeroException.what() << endl << endl;
		}
}// end divByZero()

double quotient(double num, double denom) {//used to check for a divide by 0 error before it is actually calculated
	if (denom == 0) throw DivideByZeroException{};// throw the error
	return static_cast<double>(num) / denom;// retrun the result of the division if no error thrown
}// end quotient()