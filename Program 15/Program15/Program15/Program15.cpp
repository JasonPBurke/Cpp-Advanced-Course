// Program15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<iomanip>
#include<cctype>
#include<vector>
#include<string>
#include<cstring>
using namespace std;


int getUserChoice() {

	while (true) {
		cout << "Please choose from the following options:\n"
			<< " 1.) Bitwise Operations\n"
			<< " 2.) Character Handling\n"
			<< " 3.) C-String Manipulation Functions\n"
			<< " 4.) C-String Search Functions\n"
			<< " 0.) Exit\n"
			<< "Enter your choice now: ";
		vector<int> numVector{ 0,1,2,3,4 };
		int uChoice;
		cin >> uChoice;
		cin.clear();
		cin.ignore(1024, '\n');
		// if uChoice equals 0-4, then return it. else, loop
		for (auto i : numVector) { if (i == uChoice) { return uChoice; } }
		cout << "\n ***** ERROR. PLEASE TRY AGAIN. *****\n\n";		
	}// end while	

}// end getUserChoice()

void displayBits(unsigned value) {
	const unsigned SHIFT{ 8 * sizeof(unsigned) - 1 };
	const unsigned MASK{ static_cast<const unsigned>(1 << SHIFT) };

	cout << setw(10) << value << " = ";

	for (unsigned i{ 0 }; i <= SHIFT + 1; ++i) {
		cout << (value & MASK ? '1' : '0');
		value <<= 1;// shift value to the left

		if (i % 8 == 0) { cout << ' '; }// output a space every 8 bits
	}
	cout << endl;
}// end displayBits()



void bitwiseOperationsDemo() {
	while (true) {

		cout << "\nChoose from the following bitwise operations to demo:\n"
			<< "1.) Bitwise AND(&)\n"
			<< "2.) Bitwise Inclusive OR(|)\n"
			<< "3.) Bitwise Complement(~)\n"
			<< "0.) Return to previous menu\n"
			<< "Please enter your choice now: ";

		unsigned int choice, int1, int2;
		cin >> choice;
		cin.clear();
		cin.ignore(1024, '\n');
		if (choice == 0) break; // exit from function if 0
		cout << "\n To help our demo, please enter two integers seperated by a space: ";
		cin >> int1 >> int2;
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "\nint1: " << int1 << "\nint2: " << int2 << endl;
		if (choice == 1) {
			cout << "\n To demonstrate bitwise &, we will show the result of combining\n"
				<< " int1 and int2 using the bitwise AND operator.\n\n";
			cout << "int1:\n";
			displayBits(int1);
			cout << "int2:\n";
			displayBits(int2);
			cout << "after combining using bitwise &:\n";
			displayBits(int1 & int2);
		}
		else if (choice == 2) {
			cout << "\n To demonstrate bitwise |, we will show the result of combining\n"
				<< " int1 and int2 using the bitwise OR operator.\n\n";
			cout << "int1:\n";
			displayBits(int1);
			cout << "int2:\n";
			displayBits(int2);
			cout << "after combining using bitwise |:\n";
			displayBits(int1 | int2);
		}
		else if (choice == 3) {
			cout << "\n To demonstrate bitwise ~, we will display both ints with their\n"
				<< " corresponding bitwise complement.\n\n";
			cout << "int1:\n";
			displayBits(int1);
			cout << "int1's complement:\n";
			displayBits(~int1);
			cout << "int2:\n";
			displayBits(int2);
			cout << "int2's complement:\n";
			displayBits(~int2);
		}

	}// end while	
}// end bitwiseOperationsDemo()


void characterHandlingDemo() {
	cout << "\n For this demo of character handling, you will enter any character\n"
		<< " you like, and we will process it using character handling functions\n"
		<< " to see what info we can learn about it.\n";

		while (true) {
			cout << "\n Please enter any single character now:";
			char character;
			cin.get(character);// to allow capture of spaces
			//cin >> character;
			cin.clear();
			cin.ignore(1024, '\n');
			cout << " Character Info:\n"
				<< " '" << character << "'" << (isalnum(character) ? " is a" : " is not a") << " letter or a digit.\n"
				<< " '" << character << "'" << (isdigit(character) ? " is a" : " is not a") << " digit.\n"
				<< " '" << character << "'" << (isalpha(character) ? " is a" : " is not a") << " letter.\n"
				<< " '" << character << "'" << (ispunct(character) ? " is" : " is not") << " punctuation.\n"
				<< " '" << character << "'" << (isupper(character) ? " is an" : " is not an") << " upper case letter.\n"
				<< " '" << character << "'" << (islower(character) ? " is a" : " is not a") << " lower case letter.\n"
				<< " '" << character << "'" << (isspace(character) ? " is a" : " is not a") << " space character.\n"
				<< " '" << character << "'" << " in upper case is: " <<  static_cast<char>(toupper(character)) << endl
				<< " '" << character << "'" << " in lower case is: " << static_cast<char>(tolower(character)) << endl;

			cout << "\n See this demo again?(Y/N): ";
			char again;
			cin >> again;
			cin.clear();
			cin.ignore(1024, '\n');
			if (toupper(again) == 'N') break;
		}// end while		
}// end characterHandlingDemo()


void initializeArray(string str, char list[]) {
	unsigned int index;
	for (index = 0; index < str.length(); index++) {
		list[index] = str.at(index);
	}
}// end initializeArray


void cStringManipulationDemo() {
	cout << "\n For this demo of c-string manipulation, you will enter 2 strings\n"
		<< " of any length less than 101. You will first choose to perform strcpy, strcat, or strlen\n"
		<< " on the strings that you will create.\n\n";

	string str1, str2;

	while (true) {	
		char str1Array[100] = { '\0' };// making char arrays big enough to handle most inputs and allow full copy to occur
		char str2Array[100] = { '\0' };
		cout << "\nPlease choose from the following c-string manipulation functions to demo:\n"
			<< " 1.) Use strcpy to copy\n"
			<< " 2.) Use strcat to concatenate\n"
			<< " 3.) Use strlen to find string length\n"
			<< " 0.) Return to previous menu\n"
			<< "Please enter your choice now: ";
		unsigned int choice;
		cin >> choice;
		cin.clear();
		cin.ignore(1024, '\n');
		if (choice == 0) break; // exit from function if 0

		cout << "\n Please enter the first string now: ";
		getline(cin, str1);
		initializeArray(str1, str1Array);
		cout << "\n Now enter the second string: ";
		getline(cin, str2);
		initializeArray(str2, str2Array);

		if (choice == 1) {
			cout << "\n To demonstrate strcpy, we will now copy the contents of string 1 to a new string.\n";
			char str3Array[100] = { '\0' };
			strcpy_s(str3Array, str1Array);// strcpy is now depreciated
			cout << "\n The string in array 3 now matches the string in array 1:\n"
				<< " String1 Array: " << str1Array << "\n String3 Array: " << str3Array << endl;
		}// end if 1
		if (choice == 2) {
			cout << "\n To demonstrate strcat, we will now concatinate the contents of string 2\n"
				<< " to the end of string 1.\n\n";
			cout << " String 1: " << str1Array << "\n String 2: " << str2Array << endl;
			strcat_s(str1Array, str2Array);// strcat is depreciated
			cout << " String 1 after concatenating String 2 using strcat: " << str1Array << endl;
		}// end if 2
		if (choice == 3) {
			cout << "\n To demonstrate strlen, we will now output the lengths of string 1 and string 2.\n\n"
				<< " String 1: " << str1Array << "\n String 1 length: " << strlen(str1Array) << endl;
			cout << " String 2: " << str2Array << "\n String 2 length: " << strlen(str2Array) << endl;
		}
		//if (choice == 3) {
		//	cout << "\n To demonstrate strtok, we will use it to tokenize string 1 and string 2.\n"
		//		<< " We will then print out the tokenized strings.\n\n";
		//	cout << " String 1 before tokenization: " << str1Array << endl;
		//	cout << " String 1 after tokenization:";
		//	rsize_t str1Max = sizeof str1Array;
		//	const char *delim = " ";
		//	char *next_token;
		//	char* tokenPtr1{ strtok_s(str1Array, &str1Max, delim, &next_token) };// start tokenization of string
		//	while (tokenPtr1 != NULL) {//continue tok until tokenPtr = NULL
		//		cout << tokenPtr1 << " ";// print out the token
		//		tokenPtr1 = strtok_s(NULL, " ");// get next token
		//	}// end while		
		//	cout << " String 2 before tokenization: " << str2Array << endl;
		//	cout << " String 2 after tokenization:";
		//	char* tokenPtr2{ strtok_s(str2Array, " ") };// start tokenization of string
		//	while (tokenPtr2 != NULL) {//continue tok until tokenPtr = NULL
		//		cout << tokenPtr2 << " ";// print out the token
		//		tokenPtr2 = strtok_s(NULL, " ");// get next token
		//	}// end while	
		//}// end if 3

	}// end while
}// end cStringManipulationDemo()


void cStringSearchFunctionDemo() {
	cout << "\n For this demo of c-string search functions, you will enter 2 strings\n"
		<< " of any length less than 101. You will first choose to perform strchr,\n"
		<< " strpbrk, or strstr on the strings that you will create.\n\n";

	while (true) {
		cout << "\nPlease choose from the following c-string search functions to demo:\n"
			<< " 1.) Demonstrate strchr\n"
			<< " 2.) Demonstrate strpbrk\n"
			<< " 3.) Demonstrate strstr\n"
			<< " 0.) Return to previous menu\n"
			<< "Please enter your choice now: ";
		unsigned int choice;
		cin >> choice;
		cin.clear();
		cin.ignore(1024, '\n');
		if (choice == 0) break; // exit from function if 0

		const char* charStr1;
		const char* charStr2;
		string str1, str2;

		cout << "\n Please enter string 1 now: ";
		getline(cin, str1);
		charStr1 = str1.c_str();// save string 1 to const char* so we can use strchr
		char character;

		if (choice == 1) {
			cout << "\n Enter the character you wish to search for in string 1: ";			
			cin >> character;
			cin.clear();
			cin.ignore(1024, '\n');
		}		

		if (choice == 1) {
			cout << "\nStrchr will search our string looking for the search character entered.\n\n";
			
			if (strchr(charStr1, character) != NULL) {
				cout << " '" << character << "' was found in \"" << charStr1 << "\"\n";
			}
			else {
				cout << " '" << character << "' was not found in \"" << charStr1 << "\"\n";
			}
		}// end if 1
		if (choice == 2) {
			cout << "\n Now enter the second string: ";
			getline(cin, str2);
			charStr2 = str2.c_str();// save string 2 to const char* so we can use strchr
			cout << " Strpbrk will search string 1 for the first instance\n"
				<< " of any character found in string 2.\n\n";
			cout << " String 1: " << charStr1 << "\n String 2: " << charStr2 << endl << endl;

			if (strpbrk(charStr1, charStr2) != nullptr) {
				cout << " Of the characters in '" << charStr2 << "', '" << *strpbrk(charStr1, charStr2)
					<< "' is the first character to appear in '" << charStr1 << "'\n";
			}
			else {
				cout << " No characters in '" << charStr2 << "' were found in '" << charStr1 << "'\n";
			}
			
		}// end if 2
		if (choice == 3) {
			cout << "\n Now enter the second string: ";
			getline(cin, str2);
			charStr2 = str2.c_str();// save string 2 to const char* so we can use strchr
			cout << "Strstr will search string 1 to see if it contains all of string 2.\n\n";
			cout << " String 1: " << charStr1 << "\n String 2: " << charStr2 << endl << endl;
			if (strstr(charStr1, charStr2) != 0) {
				cout << " String 2 was found in string 1.\n";
				cout << " The remainder of string 1 beginning with the first occurance of string 2 is: "
					<< strstr(charStr1, charStr2) << endl;
			}
			else {
				cout << " '" << charStr2 << "' was not found in '" << charStr1 << "'.\n";
			}
		}// end if 3

	}// end while


}// end cStringSearchFunctionDemo()

void processUserChoice(int option) {// option is guaranteed to be int 1-4

	if (option == 1) { bitwiseOperationsDemo(); }
	else if (option == 2) { characterHandlingDemo(); }
	else if (option == 3) { cStringManipulationDemo(); }
	else if (option == 4) { cStringSearchFunctionDemo(); }
}// end processUserChoice()


int main()
{

	cout << "\n This program will demonstrate bitwise operations, character-handling,\n"
		<< " and C-String functions.\n\n";

	while (true) {

		cout << " You will be presented with 4 categories of operation sets to choose from.\n"
			<< " They will allow you to perform bitwise operations, character handling,\n"
			<< " c-string manipulation functions, and c-string search functions.\n\n";

		int choice = getUserChoice();
		if (choice == 0) break;// exit while loop/program if choice equals zero
		
		processUserChoice(choice);
		

	}// end while


    return 0;
}

