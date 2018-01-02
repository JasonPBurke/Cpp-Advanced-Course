// Program01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<array>
//#include<iterator>

using namespace std;

// PUT YOUR FIVE FUNCTION PROTOTYPES HERE!!!!!!!!!!!
void calculateDiscount(double, double, double*); // DONE
int determineLarger(int*, int*); // DONE
bool compareArrays(string[], string[], int);// DONE
void sortArrays(array<string, 10>*, string *arrayBuiltIn, int); // DONE
void demoPtrTechniques(int**, const int*&, int*, const int* const);// DONE

int main()
{
	// CODE USING FUNCTION ONE
	cout << "PART 1:" << endl;
	cout << "Enter the price of an item, then the percent discount for that" << endl
		 << "item, and I will calculate the new discounted total." << endl << endl;
	double discPrice = 0;
	cout << "Please enter the list price for the item in question: ";
	double listPrice = 0;
	cin >> listPrice;
	cout << endl << "Now enter the discount percentage for that item: ";
	double discountPercentage = 0;
	cin >> discountPercentage;
	calculateDiscount(listPrice, discountPercentage, &discPrice);
	cout << "Discounted Price is : $" << discPrice << endl << endl;

	// CODE USING FUNCTON TWO
	cout << "PART 2:" << endl;
	cout << "Enter two integers and I will tell you which is larger." << endl;
	int intOne{ 0 };
	int intTwo{ 0 };
	cout << endl << "Enter the first integer: ";
	cin >> intOne;
	cout << "Enter the second integer: ";
	cin >> intTwo;
	int largerInt = determineLarger(&intOne, &intTwo);
	if (largerInt == NULL) {
		cout << "The values " << intOne << " and " << intTwo << " are the same." << endl << endl;
	}
	else {
		cout << endl << "Comparing " << intOne << " and " << intTwo << ", "
			 << "The larger integer is " << largerInt << "." << endl << endl;
	}
	
	// CODE USING FUNCTION THREE
	cout << "PART 3:" << endl;
	cout << "Please enter two strings of five characters or \"words\" " << endl
		 << "(they can be strings of any characters seperated by spaces)"
		 << endl << "and I will tell you if they are the same." << endl << endl;	

	const int arraySize = 5;
	string arrayOne[arraySize];
	string arrayTwo[arraySize];

	cout << "Enter the first string of five characters or words seperated by spaces: ";
	for (size_t i{ 0 }; i < arraySize; ++i) {
		cin >> arrayOne[i];
	}
	cin.clear();
	cin.ignore(1024, '\n');
	cout << "Enter the second string of five characters or words seperated by spaces: ";
	for (size_t j{ 0 }; j < arraySize; ++j) {
		cin >> arrayTwo[j];
	}
	bool isEqual = compareArrays(arrayOne, arrayTwo, arraySize);
	string yesNoEqual = "";
	if (isEqual == false) yesNoEqual = " not";
	cout << endl << "The two strings entered were" << yesNoEqual << " the same." << endl << endl;
	
	
	// CODE USING FUNCTION FOUR
	cout << "PART 4:" << endl;

	// Class Template array object of strings
	const size_t sortArraySize{10};// size of the array
								   
	array<string, sortArraySize> topTenAlive{ "Jon", "Samwell", "Tyrion", "Davos", "Theon",
										     "Sansa", "Arya", "Bran", "Daenerys", "Jamie" };
	cout << "~~~~~~~~~~~In Main Before Sort~~~~~~~~~~~~" << endl;
	cout << "Contents of Class Template array before sort:" << endl;
	for (int i = 0; i < sortArraySize; ++i) {
		cout << topTenAlive[i];
		if (i != sortArraySize - 1) {
			cout << ", ";
		}
	}
	// built-in array of strings
	string topTenDead[sortArraySize]{"Stannis", "Joffery", "Eddard", "Robb", "Catelyn",
									"Tommen", "Cold Hands", "Aemon", "Khal Drogo", "Hodor"};

	cout << endl << endl << "Contents of the built-in array of strings before the sort: " << endl;
	for (int i = 0; i < sortArraySize; ++i) {
		cout << topTenDead[i];
		if (i != sortArraySize-1) {
			cout <<  ", ";
		}	
	}	
	// Call the sortArrays() function
	sortArrays(&topTenAlive, topTenDead, sortArraySize);

	cout << endl << endl << "~~~~~~~~~~~In Main After Sort~~~~~~~~~~~~";
	cout << endl << "Contents of Class Template array after sort:" << endl;
	for (int i = 0; i < sortArraySize; ++i) {
		cout << topTenAlive[i];
		if (i != sortArraySize - 1) {
			cout << ", ";
		}
	}
	cout << endl << endl << "Contents of the built-in array of strings after the sort: " << endl;
	for (int i = 0; i < sortArraySize; ++i) {
		cout << topTenDead[i];
		if (i != sortArraySize - 1) {
			cout << ", ";
		}
	}
	
	// CODE USING FUNCTION FIVE
	//nonConstant pointer to nonConstant data
	int nonConstData{ 5 }; // nonConstant data
	int *nonConstPtr1 = &nonConstData;
	//	NonConst ptr to const data
	const int constData{ 6 }; // ...do I need the const here????
	const int *nonConstPtr2 = &constData;
	// Const ptr to nonConst data
	int conPtr2NonConData = 7;
	int* const constPtr1 = &conPtr2NonConData;
	// Const ptr to const data
	const int conPtr2ConData = 8;
	const int* const constPtr2 = &conPtr2ConData;// defining a const ptr to a const int

	cout << endl << endl;
	cout << "PART 5:" << endl;
	cout << "~~~~~~~~~~~Before function call ~~~~~~~~~~~~" << endl;
	cout << endl << "Pointer One" << endl;
	cout << "Nonconstant data pointed to by nonConstPtr1: " << nonConstData << endl;
	cout << "Address that nonConstPtr1 points to: " << nonConstPtr1 << endl << endl;
	cout << endl << "Pointer Two" << endl;
	cout << "Constant data pointed to by nonConstPtr2: " << constData << endl;
	cout << "Address that nonConstPtr2 points to: " << nonConstPtr2 << endl << endl;
	cout << endl << "Pointer Three" << endl;
	cout << "Constant Pointer(constPtr1) points to this nonconstant data: " << conPtr2NonConData << endl;
	cout << "Address pointed to by Constant Pointer(constPtr1): " << &constPtr1 <<endl;
	cout << endl << "Pointer Four" << endl;
	cout << "Nonconstant data pointed to by constPtr2: " << conPtr2ConData << endl;
	cout << "Address pointed to by Constant Pointer(constPtr2): " << &constPtr2 << endl;

	// Call Function showing 4 ways to pass a pointer
	demoPtrTechniques(&nonConstPtr1, nonConstPtr2, constPtr1, constPtr2);

	cout << endl << "~~~~~~~~~~~After function call ~~~~~~~~~~~~" << endl;
	cout << endl << "Pointer One" << endl;
	cout << "Nonconstant data in main after function call: " << nonConstData << endl;
	cout << "Address nonConstPtr1 points to in main after function call: " << nonConstPtr1 << endl;
	cout << endl << "Pointer Two" << endl;
	cout << "constData in main after function call: " << constData << endl;
	cout << "Address that nonConstPtr2 points to after function call: " << nonConstPtr2 <<endl<<endl;
	cout << endl << "Pointer Three" << endl;
	cout << "Nonconstant data after function call: " << conPtr2NonConData << endl;
	cout << "Address pointed to by constant pointer(constPtr1) after function call: "<<&constPtr1<<endl;
	cout << endl << "Pointer Four" << endl;
	cout << "Const data after function call: " << conPtr2ConData << endl;
	cout << "Address that constPtr2 points to after function call: " << &constPtr2 << endl;

	
	cout << endl;
	system("PAUSE");
	//cin.get();// this should work on non-windows machines
    return 0;
}
/********************************************\
         calculateDiscount() Function
\********************************************/
void calculateDiscount(double listPr, double discountPer, double* discPrice) {
	discountPer = discountPer / 100;
	*discPrice = listPr - (listPr * discountPer);
}
/********************************************\
          determineLarger() Function
\********************************************/
int determineLarger(int* intOne, int* intTwo) {
	if (*intOne > *intTwo) {
		return *intOne;
	}
	else if (*intOne == *intTwo) {
		return NULL;
	}
	else {
		return *intTwo;
	}
}

/********************************************\
         compareArrays() Function
\********************************************/
bool compareArrays(string arrayOne[], string arrayTwo[], const int size) {
	// PG. 351 - BUILT-IN ARRAYS MUST BE COMPARED IN A LOOP, ELEMENT BY ELEMENT
	// BUILT-IN ARRAYS DO NOT KNOW THEIR OWN SIZE.
	bool isEqual = false;
	for (size_t i{ 0 }; i < size; ++i) {
		if (arrayOne[i] != arrayTwo[i]) return isEqual;	
	}
	return isEqual = true;
}
/********************************************\
             sortArrays() Function
\********************************************/
// Call sortArrays() with a built-in array of strings and a Class Template array object of strings.
// Sort both of them.
void sortArrays(array<string, 10>* CTArray, string *arrayBuiltIn, int x) {
	// Sort the Class Template Array
	sort((*CTArray).begin(), (*CTArray).end());
	sort(arrayBuiltIn, arrayBuiltIn + x);
	//sort(begin(*arrayBuiltIn), end(*arrayBuiltIn));	
}

/********************************************\
       demoPtrTechniques() Function
\********************************************/
// Pass in 4 pointers: a nonconstant ptr to nonconstant data, a nonconstant ptr to constant data,
// a constant ptr to nonconstant data, and a constant ptr to constant data.
// I am passing the first pointer in as a pointer to a pointer; the second as a refrence to a pointer.
void demoPtrTechniques(int **nonConPtr2NonConData, const int *&nonConPtr2conData,
					   int* const conPtr2nonConData, const int* const conPtr2ConData ) {
					   //using *& should let me change the address the pointer stores

	// FIRST POINTER..changing data and pointer
	**nonConPtr2NonConData = 1005;//changing the nonconstant data by nonconstant pointer to a pointer.
	static int myInt = 1000;// create a value(address) to point the pointer to
	*nonConPtr2NonConData = &myInt;// changing the nonconstant pointer to point to new data(address)

	// SECOND POINTER..can't change the data the pointer points to; can point it to new address
	//*nonConPtr2conData = 1006; // ATTEMPT TO CHANGE DATA NOT ALLOWED..
	nonConPtr2conData = &myInt;// changing the nonconstant pointer to point to new data(address)

	// THIRD POINTER..can change the data the pointer points to; can't point pointer to new address
	*conPtr2nonConData = 1007;// changing the nonconstant data by constant pointer reference
	//conPtr2nonConData = &myInt;// NOT ALLOWED..EXPRESSION MUST BE A MODIFIABLE LVALUE

	// FORTH POINTER..can't change the data the ptr points to; can't point ptr to new address
	//*conPtr2ConData = 1008; // ATTEMPT TO CHANGE DATA NOT ALLOWED...NON MODIFIABLE LVALUE FOUND
	//conPtr2ConData = &myInt;// NOT ALLOWED..EXPRESSION MUST BE A MODIFIABLE LVALUE
}