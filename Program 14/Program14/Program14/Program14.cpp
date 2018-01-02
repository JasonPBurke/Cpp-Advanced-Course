// Program14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string>
#include<iostream>
#include<sstream>
#include<fstream>
#include<iomanip>

using namespace std;

void setStringValues(string& string1, string& string2, string& string3) {
	cout << "\n\n(DEMO ONE: ASSIGN VALUES TO STRINGS)\n";
	cout << " To begin, I will have you enter 2 seperate strings labeled string1 and string2.\n"
		<< " String1 will equal your entry up to any whitespace found.  It uses 'cin >> string1'.\n"
		<< " Please enter string1 now: ";
	cin >> string1;
	cin.clear();
	cin.ignore(1024, '\n');
	cout << "\n String2 will equal your entire entry prior to the enter/return key being pressed.\n"
		<< " It uses 'getline(cin, string2)' to assign value to string2.\n"
		<< " Please enter string2 now: ";
	getline(cin, string2);
	cout << "\n String3 will use 'string3.assign(string1)' to assign value to string3 using the\n"
		<< " data we previously assigned to string1.  The assign function does not effect string1's\n"
		<< " data, but essentially copies it to string3.\n\n";
	string3.assign(string1);
}

void changeStringData(string& string1, string& string2, string& string3) {
	cout << "***Would you like to change the string data before proceding?(Y/N): ";
	char recreateStrings;
	cin >> recreateStrings;
	cin.clear();
	cin.ignore(1024, '\n');
	if (toupper(recreateStrings) == 'Y') setStringValues(string1, string2, string3);
}

void concatenateStrings(string& string1, string& string2, string& string3, string& string4) {
	cout << "\n\n(DEMO TWO: CONCATENATE STRINGS)\n";
	cout << " Next we will demonstrate two ways to perform string concatenation using\n"
		<< " the three strings we created in the previous step.  We will be creating a new string\n"
		<< " to assign the concatenated string values to.  It will be called string4.\n\n";
	cout << " String1 data: " << string1 << "\n String2 data: " << string2
		<< "\n String3 data: " << string3 << "\n String4 data: " << string4 << endl;
	cout << "\n Our first concatenation will use 'string4 = string2 + string1'.  this will assign\n"
		<< " string4 the values of string2 followed by the values of string1.\n";
	string4 = string2 + string1;
	cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << " Here is string4 after the first concatenation demonstration: " << string4;
	cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "\n Our second concatenation demonstration will use 'string4.append(string3)' to\n"
		<< " concatenate the data from string3 to the current data in string4.  This function\n"
		<< " concatenates the string3 data to the end of string4(thus the append..).\n";
	string4.append(string3);
	cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << " Here is string4 after the second concatenation demonstration: " << string4 << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
}

void compareStrings(string& string1, string& string2) {
	int string1Index, string2Index, numCharsToCompare, result;
	cout << "\n\n(DEMO THREE: COMPARE PORTIONS OF TWO STRINGS)\n";
	cout << " Next we will demonstrate the ability to compare sections of two strings\n"
		<< " against each other to see if they are equal.  We will be using string1 and string2.\n";
	cout << "\nString1 Data: " << string1 << endl;
	cout << "String2 Data: " << string2 << endl;
	cout << " Enter the starting index for string1's section you wish to compare: ";
	cin >> string1Index;
	cout << "\n Enter the starting index for string2's section you wish to compare: ";
	cin >> string2Index;
	cout << "\n Now enter the number of characters you wish to compare: ";
	cin >> numCharsToCompare;

	// compare string sections
	result = string1.compare(string1Index, numCharsToCompare, string2, string2Index, numCharsToCompare);
	if (result == 0) {
		cout << "\n String1 section '" << string1.substr(string1Index, numCharsToCompare) << "' "
			<< "is equal to string2 section '" << string2.substr(string2Index, numCharsToCompare) << "'.\n";
	}
	else {
		cout << "\n String1 section '" << string1.substr(string1Index, numCharsToCompare) << "' "
			<< "is not equal to string2 section '" << string2.substr(string2Index, numCharsToCompare) << "'.\n";
	}
}

void forwardReverseIterator(string string2) {
	string::const_iterator forwardIterator{ string2.begin() };
	string::const_reverse_iterator reverseIterator{ string2.rbegin() };

	cout << "\n\n(DEMO FOUR: DEMOSTRATE FORWARD AND REVERSE STRING ITERATORS)";
	cout << "\n The next section will demonstrate a string iterator displaying a string in forward order,\n"
		<< " and a string iterator displaying the string in reverse order.  They will be displayed together\n"
		<< " to compare and contrast.  We will be using string2 for this demonstration.\n";
	cout << "\n String2 data before using iterators: " << string2 << endl;
	cout << " String2 data using a forward iterator: ";
	while (forwardIterator != string2.end()) {
		cout << *forwardIterator;
		forwardIterator++;
	}
	//for (char c : string2) { cout << c; } or this..
	cout << "\n String2 data using a reverse iterator: ";
	while (reverseIterator != string2.rend()) {
		cout << *reverseIterator;
		reverseIterator++;
	}
	cout << endl;
}

void insertionExtractionDemo(string& string1, string& string2, string& string3, string& string4) {
	cout << "(DEMO FIVE: STANDARD, FILE, AND STRING STREAM I/O)\n";
	cout << " This section will demonstrate standard I/O, file I/O and string stream I/O\n"
		<< " using insertion(<<) and extraction(>>) operators.\n";
	string yourString;
	// demonstrate standard i/o
	cout << " This line demonstrates the insertion operator used with standard output (cout << '....')\n"
		<< " To demonstrate standard input, please enter a string now: ";
	cin >> yourString;
	cout << "\n Your string " << yourString << " was captured using cin >> yourString.\n";
	// demonstrate file i/o
	cout << "\n Next we demonstrate file I/O by first outputting(saving) our five strings\n"
		<< " to a file, then inputting(reading) those strings back from that file to the screen.\n";
	cout << " Our strings are:\n\n String1: " << string1 << "\n String2: " << string2
		<< "\n String3: " << string3 << "\n String4: " << string4 << "\n YourString: " << yourString << endl;
	cout << "\n First we output our strings to a file called file_io_demo.txt";
	ofstream outFile{ "file_io_demo.txt" , ios::out};
	outFile << quoted(string1) << quoted(string2) << quoted(string3) << quoted(string4) << quoted(yourString) << endl;
	cout << "....done.\n Next we will read the strings back from file_io_demo.txt and print them to the screen\n";
	cout << " To help ensure we are reading from the file, the strings will be saved to new strings.\n";
	ifstream inFile{ "file_io_demo.txt" , ios::in};
	string firstString, secondString, thirdString, fourthString, myString;
	inFile >> quoted(firstString) >> quoted(secondString) >> quoted(thirdString) >> quoted(fourthString) >> quoted(myString);
	cout << "\n Here is the data read out of the file:\n"
		<< "\n firstString: " << firstString << "\n secondString: " << secondString << "\n thirdString: "
		<< thirdString << "\n fourthString: " << fourthString << "\n myString: " << myString << endl;
	//demonstrate string stream i/o
	cout << "\n Lastly we will demonstrate string stream input and output.\n";
	ostringstream outputString; // creating a ostringstream object
	cout << " For this demonstration we will be copying the above five strings in reverse order to a ostringstream object.\n"
		<< " We will then output the contents of the ostringstream object using 'cout << outputString.str()'.\n";
	outputString << "\n yourString: " << yourString << "\n string4: " << string4 << "\n string3: " << string3
		<< "\n string2: " << string2 << "\n string1: " << string1;
	cout << "\n The outputString contains:\n" << outputString.str() << endl;
	string input = "So Long and Thanks for All the Fish";// dummy data for istringstream object
	istringstream inputString{input}; // creating an istringstream object and instantiate it with 'input'
	cout << "\n Now we will create an istringstream object called inputString that we will seed with\n"
		<< " a dummy string that contains 'So Long and Thanks for All the Fish'.  We will extract each\n"
		<< " word and save them as new individual strings(str1-str8).\n\n";
	string str1, str2, str3, str4, str5, str6, str7, str8;
	str1 = str2 = str3 = str4 = str5 = str6 = str7 = str8 = "EMPTY";
	cout << "Str1-str8 before filling with istringstream data:\n\n";
	cout << " str1: " << str1 << "\n str2: " << str2 << "\n str3: " << str3 << "\n str4: " << str4
		<< "\n str5: " << str5 << "\n str6: " << str6 << "\n str7: " << str7 << "\n str8: " << str8 << "\n\n";
	inputString >> str1 >> str2 >> str3 >> str4 >> str5 >> str6 >> str7 >> str8;
	cout << "Str1-str8 after filling with istringstream data:\n\n";
	cout << " str1: " << str1 << "\n str2: " << str2 << "\n str3: " << str3 << "\n str4: " << str4
		<< "\n str5: " << str5 << "\n str6: " << str6 << "\n str7: " << str7 << "\n str8: " << str8 << "\n\n";
}


int main()
{

	cout << "This program demonstrates string operations and string stream processing.\n";
	string string1, string2, string3, string4;

	setStringValues(string1, string2, string3);// set values for string1-string3
	// display the values
	cout << "++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "Here are the string names and their data:\n"
		<< " String1: " << string1 << "\n String2: " << string2 << "\n String3: " << string3 << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++\n\n";
	
	cout << " The next section will demonstrate concatenation of strings.\n";
	changeStringData(string1, string2, string3);// see if user wants to change string1-string3 values before demo2
	concatenateStrings(string1, string2, string3, string4);// concatenate strings demonstration

	cout << " The next section will allow you to compare portions of strings against each other.\n";
	changeStringData(string1, string2, string3);// see if user wants to change string1-string3 values before demo3
	compareStrings(string1, string2);

	forwardReverseIterator(string2);

	cout << "\n\n The last section will demonstrate the three common I/O streams using << and >> operators.\n";
	insertionExtractionDemo(string1, string2, string3, string4);

	system("pause");
    return 0;
}

